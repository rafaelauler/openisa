//===-- OiAsmPrinter.cpp - Oi LLVM Assembly Printer -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to GAS-format OI assembly language.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "oi-asm-printer"
#include "InstPrinter/OiInstPrinter.h"
#include "MCTargetDesc/OiBaseInfo.h"
#include "MCTargetDesc/OiELFStreamer.h"
#include "Oi.h"
#include "OiAsmPrinter.h"
#include "OiInstrInfo.h"
#include "OiMCInstLower.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Twine.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/Instructions.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ELF.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/Mangler.h"
#include "llvm/Target/TargetLoweringObjectFile.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

bool OiAsmPrinter::runOnMachineFunction(MachineFunction &MF) {
  // Initialize TargetLoweringObjectFile.
  if (Subtarget->allowMixed16_32())
    const_cast<TargetLoweringObjectFile&>(getObjFileLowering())
      .Initialize(OutContext, TM);
  OiFI = MF.getInfo<OiFunctionInfo>();
  size_t n = MF.getFunction()->arg_size();
  OutStreamer.EmitRawText("\t.numargs\t" + Twine(n));
  AsmPrinter::runOnMachineFunction(MF);
  return true;
}

bool OiAsmPrinter::lowerOperand(const MachineOperand &MO, MCOperand &MCOp) {
  MCOp = MCInstLowering.LowerOperand(MO);
  return MCOp.isValid();
}

#include "OiGenMCPseudoLowering.inc"

void OiAsmPrinter::EmitInstruction(const MachineInstr *MI) {
  if (MI->isDebugValue()) {
    SmallString<128> Str;
    raw_svector_ostream OS(Str);

    PrintDebugValueComment(MI, OS);
    return;
  }

  MachineBasicBlock::const_instr_iterator I = MI;
  MachineBasicBlock::const_instr_iterator E = MI->getParent()->instr_end();

  do {
    // Do any auto-generated pseudo lowerings.
    if (emitPseudoExpansionLowering(OutStreamer, &*I))
      continue;

    // The inOi16Mode() test is not permanent.
    // Some instructions are marked as pseudo right now which
    // would make the test fail for the wrong reason but
    // that will be fixed soon. We need this here because we are
    // removing another test for this situation downstream in the
    // callchain.
    //
    if (I->isPseudo() && !Subtarget->inOi16Mode())
      llvm_unreachable("Pseudo opcode found in EmitInstruction()");

    MCInst TmpInst0;
    MCInstLowering.Lower(I, TmpInst0);
    OutStreamer.EmitInstruction(TmpInst0);
  } while ((++I != E) && I->isInsideBundle()); // Delay slot check
}

//===----------------------------------------------------------------------===//
//
//  Oi Asm Directives
//
//  -- Frame directive "frame Stackpointer, Stacksize, RARegister"
//  Describe the stack frame.
//
//  -- Mask directives "(f)mask  bitmask, offset"
//  Tells the assembler which registers are saved and where.
//  bitmask - contain a little endian bitset indicating which registers are
//            saved on function prologue (e.g. with a 0x80000000 mask, the
//            assembler knows the register 31 (RA) is saved at prologue.
//  offset  - the position before stack pointer subtraction indicating where
//            the first saved register on prologue is located. (e.g. with a
//
//  Consider the following function prologue:
//
//    .frame  $fp,48,$ra
//    .mask   0xc0000000,-8
//       addiu $sp, $sp, -48
//       sw $ra, 40($sp)
//       sw $fp, 36($sp)
//
//    With a 0xc0000000 mask, the assembler knows the register 31 (RA) and
//    30 (FP) are saved at prologue. As the save order on prologue is from
//    left to right, RA is saved first. A -8 offset means that after the
//    stack pointer subtration, the first register in the mask (RA) will be
//    saved at address 48-8=40.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Mask directives
//===----------------------------------------------------------------------===//

// Create a bitmask with all callee saved registers for CPU or Floating Point
// registers. For CPU registers consider RA, GP and FP for saving if necessary.
void OiAsmPrinter::printSavedRegsBitmask(raw_ostream &O) {
  // CPU and FPU Saved Registers Bitmasks
  unsigned CPUBitmask = 0, FPUBitmask = 0;
  int CPUTopSavedRegOff, FPUTopSavedRegOff;

  // Set the CPU and FPU Bitmasks
  const MachineFrameInfo *MFI = MF->getFrameInfo();
  const std::vector<CalleeSavedInfo> &CSI = MFI->getCalleeSavedInfo();
  // size of stack area to which FP callee-saved regs are saved.
  unsigned CPURegSize = Oi::CPURegsRegClass.getSize();
  unsigned FGR32RegSize = Oi::FGR32RegClass.getSize();
  unsigned AFGR64RegSize = Oi::AFGR64RegClass.getSize();
  bool HasAFGR64Reg = false;
  unsigned CSFPRegsSize = 0;
  unsigned i, e = CSI.size();

  // Set FPU Bitmask.
  for (i = 0; i != e; ++i) {
    unsigned Reg = CSI[i].getReg();
    if (Oi::CPURegsRegClass.contains(Reg))
      break;

    unsigned RegNum = TM.getRegisterInfo()->getEncodingValue(Reg);
    if (Oi::AFGR64RegClass.contains(Reg)) {
      FPUBitmask |= (3 << RegNum);
      CSFPRegsSize += AFGR64RegSize;
      HasAFGR64Reg = true;
      continue;
    }

    FPUBitmask |= (1 << RegNum);
    CSFPRegsSize += FGR32RegSize;
  }

  // Set CPU Bitmask.
  for (; i != e; ++i) {
    unsigned Reg = CSI[i].getReg();
    unsigned RegNum = TM.getRegisterInfo()->getEncodingValue(Reg);
    CPUBitmask |= (1 << RegNum);
  }

  // FP Regs are saved right below where the virtual frame pointer points to.
  FPUTopSavedRegOff = FPUBitmask ?
    (HasAFGR64Reg ? -AFGR64RegSize : -FGR32RegSize) : 0;

  // CPU Regs are saved below FP Regs.
  CPUTopSavedRegOff = CPUBitmask ? -CSFPRegsSize - CPURegSize : 0;

  // Print CPUBitmask
  O << "\t.mask \t"; printHex32(CPUBitmask, O);
  O << ',' << CPUTopSavedRegOff << '\n';

  // Print FPUBitmask
  O << "\t.fmask\t"; printHex32(FPUBitmask, O);
  O << "," << FPUTopSavedRegOff << '\n';
}

// Print a 32 bit hex number with all numbers.
void OiAsmPrinter::printHex32(unsigned Value, raw_ostream &O) {
  O << "0x";
  for (int i = 7; i >= 0; i--)
    O.write_hex((Value & (0xF << (i*4))) >> (i*4));
}

//===----------------------------------------------------------------------===//
// Frame and Set directives
//===----------------------------------------------------------------------===//

/// Frame Directive
void OiAsmPrinter::emitFrameDirective() {
  const TargetRegisterInfo &RI = *TM.getRegisterInfo();

  unsigned stackReg  = RI.getFrameRegister(*MF);
  unsigned returnReg = RI.getRARegister();
  unsigned stackSize = MF->getFrameInfo()->getStackSize();

  if (OutStreamer.hasRawTextSupport())
    OutStreamer.EmitRawText("\t.frame\t$" +
           StringRef(OiInstPrinter::getRegisterName(stackReg)).lower() +
           "," + Twine(stackSize) + ",$" +
           StringRef(OiInstPrinter::getRegisterName(returnReg)).lower());
}

/// Emit Set directives.
const char *OiAsmPrinter::getCurrentABIString() const {
  switch (Subtarget->getTargetABI()) {
  case OiSubtarget::O32:  return "abi32";
  case OiSubtarget::N32:  return "abiN32";
  case OiSubtarget::N64:  return "abi64";
  case OiSubtarget::EABI: return "eabi32"; // TODO: handle eabi64
  default: llvm_unreachable("Unknown Oi ABI");
  }
}

void OiAsmPrinter::EmitFunctionEntryLabel() {
  if (OutStreamer.hasRawTextSupport()) {
    if (Subtarget->inOi16Mode())
      OutStreamer.EmitRawText(StringRef("\t.set\toi16"));
    else
      OutStreamer.EmitRawText(StringRef("\t.set\tnooi16"));
    // leave out until FSF available gas has microoi changes
    // OutStreamer.EmitRawText(StringRef("\t.set\tnomicrooi"));
    OutStreamer.EmitRawText("\t.ent\t" + Twine(CurrentFnSym->getName()));
  }

  if (Subtarget->inMicroOiMode())
    if (OiELFStreamer *MES = dyn_cast<OiELFStreamer>(&OutStreamer))
      MES->emitOiSTOCG(*Subtarget, CurrentFnSym,
      (unsigned)ELF::STO_MIPS_MICROMIPS);
  OutStreamer.EmitLabel(CurrentFnSym);
}

/// EmitFunctionBodyStart - Targets can override this to emit stuff before
/// the first basic block in the function.
void OiAsmPrinter::EmitFunctionBodyStart() {
  MCInstLowering.Initialize(Mang, &MF->getContext());

  bool IsNakedFunction =
    MF->getFunction()->
      getAttributes().hasAttribute(AttributeSet::FunctionIndex,
                                   Attribute::Naked);
  if (!IsNakedFunction)
    emitFrameDirective();

  if (OutStreamer.hasRawTextSupport()) {
    SmallString<128> Str;
    raw_svector_ostream OS(Str);
    if (!IsNakedFunction)
      printSavedRegsBitmask(OS);
    OutStreamer.EmitRawText(OS.str());
    if (!Subtarget->inOi16Mode()) {
      OutStreamer.EmitRawText(StringRef("\t.set\tnoreorder"));
      OutStreamer.EmitRawText(StringRef("\t.set\tnomacro"));
      OutStreamer.EmitRawText(StringRef("\t.set\tnoat"));
    }
  }
}

/// EmitFunctionBodyEnd - Targets can override this to emit stuff after
/// the last basic block in the function.
void OiAsmPrinter::EmitFunctionBodyEnd() {
  // There are instruction for this macros, but they must
  // always be at the function end, and we can't emit and
  // break with BB logic.
  if (OutStreamer.hasRawTextSupport()) {
    if (!Subtarget->inOi16Mode()) {
      OutStreamer.EmitRawText(StringRef("\t.set\tat"));
      OutStreamer.EmitRawText(StringRef("\t.set\tmacro"));
      OutStreamer.EmitRawText(StringRef("\t.set\treorder"));
    }
    OutStreamer.EmitRawText("\t.end\t" + Twine(CurrentFnSym->getName()));
  }
}

/// isBlockOnlyReachableByFallthough - Return true if the basic block has
/// exactly one predecessor and the control transfer mechanism between
/// the predecessor and this block is a fall-through.
bool OiAsmPrinter::isBlockOnlyReachableByFallthrough(const MachineBasicBlock*
                                                       MBB) const {
  // The predecessor has to be immediately before this block.
  const MachineBasicBlock *Pred = *MBB->pred_begin();

  // If the predecessor is a switch statement, assume a jump table
  // implementation, so it is not a fall through.
  if (const BasicBlock *bb = Pred->getBasicBlock())
    if (isa<SwitchInst>(bb->getTerminator()))
      return false;

  // If this is a landing pad, it isn't a fall through.  If it has no preds,
  // then nothing falls through to it.
  if (MBB->isLandingPad() || MBB->pred_empty())
    return false;

  // If there isn't exactly one predecessor, it can't be a fall through.
  MachineBasicBlock::const_pred_iterator PI = MBB->pred_begin(), PI2 = PI;
  ++PI2;

  if (PI2 != MBB->pred_end())
    return false;

  // The predecessor has to be immediately before this block.
  if (!Pred->isLayoutSuccessor(MBB))
    return false;

  // If the block is completely empty, then it definitely does fall through.
  if (Pred->empty())
    return true;

  // Otherwise, check the last instruction.
  // Check if the last terminator is an unconditional branch.
  MachineBasicBlock::const_iterator I = Pred->end();
  while (I != Pred->begin() && !(--I)->isTerminator()) ;

  return !I->isBarrier();
}

// Print out an operand for an inline asm expression.
bool OiAsmPrinter::PrintAsmOperand(const MachineInstr *MI, unsigned OpNum,
                                     unsigned AsmVariant,const char *ExtraCode,
                                     raw_ostream &O) {
  // Does this asm operand have a single letter operand modifier?
  if (ExtraCode && ExtraCode[0]) {
    if (ExtraCode[1] != 0) return true; // Unknown modifier.

    const MachineOperand &MO = MI->getOperand(OpNum);
    switch (ExtraCode[0]) {
    default:
      // See if this is a generic print operand
      return AsmPrinter::PrintAsmOperand(MI,OpNum,AsmVariant,ExtraCode,O);
    case 'X': // hex const int
      if ((MO.getType()) != MachineOperand::MO_Immediate)
        return true;
      O << "0x" << StringRef(utohexstr(MO.getImm())).lower();
      return false;
    case 'x': // hex const int (low 16 bits)
      if ((MO.getType()) != MachineOperand::MO_Immediate)
        return true;
      O << "0x" << StringRef(utohexstr(MO.getImm() & 0xffff)).lower();
      return false;
    case 'd': // decimal const int
      if ((MO.getType()) != MachineOperand::MO_Immediate)
        return true;
      O << MO.getImm();
      return false;
    case 'm': // decimal const int minus 1
      if ((MO.getType()) != MachineOperand::MO_Immediate)
        return true;
      O << MO.getImm() - 1;
      return false;
    case 'z': {
      // $0 if zero, regular printing otherwise
      if (MO.getType() != MachineOperand::MO_Immediate)
        return true;
      int64_t Val = MO.getImm();
      if (Val)
        O << Val;
      else
        O << "$0";
      return false;
    }
    case 'D': // Second part of a double word register operand
    case 'L': // Low order register of a double word register operand
    case 'M': // High order register of a double word register operand
    {
      if (OpNum == 0)
        return true;
      const MachineOperand &FlagsOP = MI->getOperand(OpNum - 1);
      if (!FlagsOP.isImm())
        return true;
      unsigned Flags = FlagsOP.getImm();
      unsigned NumVals = InlineAsm::getNumOperandRegisters(Flags);
      // Number of registers represented by this operand. We are looking
      // for 2 for 32 bit mode and 1 for 64 bit mode.
      if (NumVals != 2) {
        if (Subtarget->isGP64bit() && NumVals == 1 && MO.isReg()) {
          unsigned Reg = MO.getReg();
          O << '$' << OiInstPrinter::getRegisterName(Reg);
          return false;
        }
        return true;
      }

      unsigned RegOp = OpNum;
      if (!Subtarget->isGP64bit()){
        // Endianess reverses which register holds the high or low value
        // between M and L.
        switch(ExtraCode[0]) {
        case 'M':
          RegOp = (Subtarget->isLittle()) ? OpNum + 1 : OpNum;
          break;
        case 'L':
          RegOp = (Subtarget->isLittle()) ? OpNum : OpNum + 1;
          break;
        case 'D': // Always the second part
          RegOp = OpNum + 1;
        }
        if (RegOp >= MI->getNumOperands())
          return true;
        const MachineOperand &MO = MI->getOperand(RegOp);
        if (!MO.isReg())
          return true;
        unsigned Reg = MO.getReg();
        O << '$' << OiInstPrinter::getRegisterName(Reg);
        return false;
      }
    }
    }
  }

  printOperand(MI, OpNum, O);
  return false;
}

bool OiAsmPrinter::PrintAsmMemoryOperand(const MachineInstr *MI,
                                           unsigned OpNum, unsigned AsmVariant,
                                           const char *ExtraCode,
                                           raw_ostream &O) {
  int Offset = 0;
  // Currently we are expecting either no ExtraCode or 'D'
  if (ExtraCode) {
    if (ExtraCode[0] == 'D')
      Offset = 4;
    else
      return true; // Unknown modifier.
  }

  const MachineOperand &MO = MI->getOperand(OpNum);
  assert(MO.isReg() && "unexpected inline asm memory operand");
  O << Offset << "($" << OiInstPrinter::getRegisterName(MO.getReg()) << ")";

  return false;
}

void OiAsmPrinter::printOperand(const MachineInstr *MI, int opNum,
                                  raw_ostream &O) {
  const MachineOperand &MO = MI->getOperand(opNum);
  bool closeP = false;

  if (MO.getTargetFlags())
    closeP = true;

  switch(MO.getTargetFlags()) {
  case OiII::MO_GPREL:    O << "%gp_rel("; break;
  case OiII::MO_GOT_CALL: O << "%call16("; break;
  case OiII::MO_GOT:      O << "%got(";    break;
  case OiII::MO_ABS_HI:   O << "%hi(";     break;
  case OiII::MO_ABS_LO:   O << "%lo(";     break;
  case OiII::MO_TLSGD:    O << "%tlsgd(";  break;
  case OiII::MO_GOTTPREL: O << "%gottprel("; break;
  case OiII::MO_TPREL_HI: O << "%tprel_hi("; break;
  case OiII::MO_TPREL_LO: O << "%tprel_lo("; break;
  case OiII::MO_GPOFF_HI: O << "%hi(%neg(%gp_rel("; break;
  case OiII::MO_GPOFF_LO: O << "%lo(%neg(%gp_rel("; break;
  case OiII::MO_GOT_DISP: O << "%got_disp("; break;
  case OiII::MO_GOT_PAGE: O << "%got_page("; break;
  case OiII::MO_GOT_OFST: O << "%got_ofst("; break;
  }

  switch (MO.getType()) {
    case MachineOperand::MO_Register:
      O << '$'
        << StringRef(OiInstPrinter::getRegisterName(MO.getReg())).lower();
      break;

    case MachineOperand::MO_Immediate:
      O << MO.getImm();
      break;

    case MachineOperand::MO_MachineBasicBlock:
      O << *MO.getMBB()->getSymbol();
      return;

    case MachineOperand::MO_GlobalAddress:
      O << *Mang->getSymbol(MO.getGlobal());
      break;

    case MachineOperand::MO_BlockAddress: {
      MCSymbol *BA = GetBlockAddressSymbol(MO.getBlockAddress());
      O << BA->getName();
      break;
    }

    case MachineOperand::MO_ExternalSymbol:
      O << *GetExternalSymbolSymbol(MO.getSymbolName());
      break;

    case MachineOperand::MO_JumpTableIndex:
      O << MAI->getPrivateGlobalPrefix() << "JTI" << getFunctionNumber()
        << '_' << MO.getIndex();
      break;

    case MachineOperand::MO_ConstantPoolIndex:
      O << MAI->getPrivateGlobalPrefix() << "CPI"
        << getFunctionNumber() << "_" << MO.getIndex();
      if (MO.getOffset())
        O << "+" << MO.getOffset();
      break;

    default:
      llvm_unreachable("<unknown operand type>");
  }

  if (closeP) O << ")";
}

void OiAsmPrinter::printUnsignedImm(const MachineInstr *MI, int opNum,
                                      raw_ostream &O) {
  const MachineOperand &MO = MI->getOperand(opNum);
  if (MO.isImm())
    O << (unsigned short int)MO.getImm();
  else
    printOperand(MI, opNum, O);
}

void OiAsmPrinter::
printMemOperand(const MachineInstr *MI, int opNum, raw_ostream &O) {
  // Load/Store memory operands -- imm($reg)
  // If PIC target the target is loaded as the
  // pattern lw $25,%call16($28)
  printOperand(MI, opNum+1, O);
  O << "(";
  printOperand(MI, opNum, O);
  O << ")";
}

void OiAsmPrinter::
printMemOperandEA(const MachineInstr *MI, int opNum, raw_ostream &O) {
  // when using stack locations for not load/store instructions
  // print the same way as all normal 3 operand instructions.
  printOperand(MI, opNum, O);
  O << ", ";
  printOperand(MI, opNum+1, O);
  return;
}

void OiAsmPrinter::
printFCCOperand(const MachineInstr *MI, int opNum, raw_ostream &O,
                const char *Modifier) {
  const MachineOperand &MO = MI->getOperand(opNum);
  O << Oi::OiFCCToString((Oi::CondCode)MO.getImm());
}

void OiAsmPrinter::EmitStartOfAsmFile(Module &M) {
  // FIXME: Use SwitchSection.

  // Tell the assembler which ABI we are using
  if (OutStreamer.hasRawTextSupport())
    OutStreamer.EmitRawText("\t.section .mdebug." +
                            Twine(getCurrentABIString()));

  // TODO: handle O64 ABI
  if (OutStreamer.hasRawTextSupport()) {
    if (Subtarget->isABI_EABI()) {
      if (Subtarget->isGP32bit())
        OutStreamer.EmitRawText(StringRef("\t.section .gcc_compiled_long32"));
      else
        OutStreamer.EmitRawText(StringRef("\t.section .gcc_compiled_long64"));
    }
  }

  // return to previous section
  if (OutStreamer.hasRawTextSupport())
    OutStreamer.EmitRawText(StringRef("\t.previous"));

}

void OiAsmPrinter::EmitEndOfAsmFile(Module &M) {

  if (OutStreamer.hasRawTextSupport()) return;

  // Emit Oi ELF register info
  Subtarget->getMReginfo().emitOiReginfoSectionCG(
             OutStreamer, getObjFileLowering(), *Subtarget);
  if (OiELFStreamer *MES = dyn_cast<OiELFStreamer>(&OutStreamer))
    MES->emitELFHeaderFlagsCG(*Subtarget);
}

MachineLocation
OiAsmPrinter::getDebugValueLocation(const MachineInstr *MI) const {
  // Handles frame addresses emitted in OiInstrInfo::emitFrameIndexDebugValue.
  assert(MI->getNumOperands() == 4 && "Invalid no. of machine operands!");
  assert(MI->getOperand(0).isReg() && MI->getOperand(1).isImm() &&
         "Unexpected MachineOperand types");
  return MachineLocation(MI->getOperand(0).getReg(),
                         MI->getOperand(1).getImm());
}

void OiAsmPrinter::PrintDebugValueComment(const MachineInstr *MI,
                                           raw_ostream &OS) {
  // TODO: implement
}

// Force static initialization.
extern "C" void LLVMInitializeOiAsmPrinter() {
  RegisterAsmPrinter<OiAsmPrinter> X(TheOiTarget);
  //  RegisterAsmPrinter<OiAsmPrinter> Y(TheOielTarget);
  //  RegisterAsmPrinter<OiAsmPrinter> A(TheOi64Target);
  //  RegisterAsmPrinter<OiAsmPrinter> B(TheOi64elTarget);
}
