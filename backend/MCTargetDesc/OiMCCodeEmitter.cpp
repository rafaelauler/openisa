//===-- OiMCCodeEmitter.cpp - Convert Oi Code to Machine Code ---------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the OiMCCodeEmitter class.
//
//===----------------------------------------------------------------------===//
//
#define DEBUG_TYPE "mccodeemitter"
#include "MCTargetDesc/OiBaseInfo.h"
#include "MCTargetDesc/OiDirectObjLower.h"
#include "MCTargetDesc/OiFixupKinds.h"
#include "MCTargetDesc/OiMCTargetDesc.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/raw_ostream.h"

#define GET_INSTRMAP_INFO
#include "OiGenInstrInfo.inc"

using namespace llvm;

namespace {
class OiMCCodeEmitter : public MCCodeEmitter {
  OiMCCodeEmitter(const OiMCCodeEmitter &) LLVM_DELETED_FUNCTION;
  void operator=(const OiMCCodeEmitter &) LLVM_DELETED_FUNCTION;
  const MCInstrInfo &MCII;
  MCContext &Ctx;
  const MCSubtargetInfo &STI;
  bool IsLittleEndian;

public:
  OiMCCodeEmitter(const MCInstrInfo &mcii, MCContext &Ctx_,
                    const MCSubtargetInfo &sti, bool IsLittle) :
    MCII(mcii), Ctx(Ctx_), STI (sti), IsLittleEndian(IsLittle) {}

  ~OiMCCodeEmitter() {}

  void EmitByte(unsigned char C, raw_ostream &OS) const {
    OS << (char)C;
  }

  void EmitInstruction(uint64_t Val, unsigned Size, raw_ostream &OS) const {
    // Output the instruction encoding in little endian byte order.
    for (unsigned i = 0; i < Size; ++i) {
      unsigned Shift = IsLittleEndian ? i * 8 : (Size - 1 - i) * 8;
      EmitByte((Val >> Shift) & 0xff, OS);
    }
  }

  void EncodeInstruction(const MCInst &MI, raw_ostream &OS,
                         SmallVectorImpl<MCFixup> &Fixups) const;

  // getBinaryCodeForInstr - TableGen'erated function for getting the
  // binary encoding for an instruction.
  uint64_t getBinaryCodeForInstr(const MCInst &MI,
                                 SmallVectorImpl<MCFixup> &Fixups) const;

  // getBranchJumpOpValue - Return binary encoding of the jump
  // target operand. If the machine operand requires relocation,
  // record the relocation and return zero.
   unsigned getJumpTargetOpValue(const MCInst &MI, unsigned OpNo,
                                 SmallVectorImpl<MCFixup> &Fixups) const;

   // getBranchTargetOpValue - Return binary encoding of the branch
   // target operand. If the machine operand requires relocation,
   // record the relocation and return zero.
  unsigned getBranchTargetOpValue(const MCInst &MI, unsigned OpNo,
                                  SmallVectorImpl<MCFixup> &Fixups) const;

   // getMachineOpValue - Return binary encoding of operand. If the machin
   // operand requires relocation, record the relocation and return zero.
  unsigned getMachineOpValue(const MCInst &MI,const MCOperand &MO,
                             SmallVectorImpl<MCFixup> &Fixups) const;

  unsigned getMemEncoding(const MCInst &MI, unsigned OpNo,
                          SmallVectorImpl<MCFixup> &Fixups) const;
  unsigned getSizeExtEncoding(const MCInst &MI, unsigned OpNo,
                              SmallVectorImpl<MCFixup> &Fixups) const;
  unsigned getSizeInsEncoding(const MCInst &MI, unsigned OpNo,
                              SmallVectorImpl<MCFixup> &Fixups) const;

  unsigned
  getExprOpValue(const MCExpr *Expr,SmallVectorImpl<MCFixup> &Fixups) const;

}; // class OiMCCodeEmitter
}  // namespace

MCCodeEmitter *llvm::createOiMCCodeEmitterEB(const MCInstrInfo &MCII,
                                               const MCRegisterInfo &MRI,
                                               const MCSubtargetInfo &STI,
                                               MCContext &Ctx)
{
  return new OiMCCodeEmitter(MCII, Ctx, STI, false);
}

MCCodeEmitter *llvm::createOiMCCodeEmitterEL(const MCInstrInfo &MCII,
                                               const MCRegisterInfo &MRI,
                                               const MCSubtargetInfo &STI,
                                               MCContext &Ctx)
{
  return new OiMCCodeEmitter(MCII, Ctx, STI, true);
}

/// EncodeInstruction - Emit the instruction.
/// Size the instruction (currently only 4 bytes
void OiMCCodeEmitter::
EncodeInstruction(const MCInst &MI, raw_ostream &OS,
                  SmallVectorImpl<MCFixup> &Fixups) const
{

  // Non-pseudo instructions that get changed for direct object
  // only based on operand values.
  // If this list of instructions get much longer we will move
  // the check to a function call. Until then, this is more efficient.
  MCInst TmpInst = MI;
  switch (MI.getOpcode()) {
  // If shift amount is >= 32 it the inst needs to be lowered further
  case Oi::DSLL:
  case Oi::DSRL:
  case Oi::DSRA:
    Oi::LowerLargeShift(TmpInst);
    break;
    // Double extract instruction is chosen by pos and size operands
  case Oi::DEXT:
  case Oi::DINS:
    Oi::LowerDextDins(TmpInst);
  }

  uint64_t Binary = getBinaryCodeForInstr(TmpInst, Fixups);

  // Check for unimplemented opcodes.
  // Unfortunately in OI both NOP and SLL will come in with Binary == 0
  // so we have to special check for them.
  unsigned Opcode = TmpInst.getOpcode();
  if ((Opcode != Oi::NOP) && (Opcode != Oi::SLL) && !Binary)
    llvm_unreachable("unimplemented opcode in EncodeInstruction()");

  if (STI.getFeatureBits() & Oi::FeatureMicroOi) {
    int NewOpcode = Oi::Std2MicroOi (Opcode, Oi::Arch_microoi);
    if (NewOpcode != -1) {
      Opcode = NewOpcode;
      TmpInst.setOpcode (NewOpcode);
      Binary = getBinaryCodeForInstr(TmpInst, Fixups);
    }
  }

  const MCInstrDesc &Desc = MCII.get(TmpInst.getOpcode());

  // Get byte count of instruction
  unsigned Size = Desc.getSize();
  if (!Size)
    llvm_unreachable("Desc.getSize() returns 0");

  EmitInstruction(Binary, Size, OS);
}

/// getBranchTargetOpValue - Return binary encoding of the branch
/// target operand. If the machine operand requires relocation,
/// record the relocation and return zero.
unsigned OiMCCodeEmitter::
getBranchTargetOpValue(const MCInst &MI, unsigned OpNo,
                       SmallVectorImpl<MCFixup> &Fixups) const {

  const MCOperand &MO = MI.getOperand(OpNo);

  // If the destination is an immediate, divide by 4.
  if (MO.isImm()) return MO.getImm() >> 2;

  assert(MO.isExpr() &&
         "getBranchTargetOpValue expects only expressions or immediates");

  const MCExpr *Expr = MO.getExpr();
  Fixups.push_back(MCFixup::Create(0, Expr,
                                   MCFixupKind(Oi::fixup_Oi_PC16)));
  return 0;
}

/// getJumpTargetOpValue - Return binary encoding of the jump
/// target operand. If the machine operand requires relocation,
/// record the relocation and return zero.
unsigned OiMCCodeEmitter::
getJumpTargetOpValue(const MCInst &MI, unsigned OpNo,
                     SmallVectorImpl<MCFixup> &Fixups) const {

  const MCOperand &MO = MI.getOperand(OpNo);
  // If the destination is an immediate, divide by 4.
  if (MO.isImm()) return MO.getImm()>>2;

  assert(MO.isExpr() &&
         "getJumpTargetOpValue expects only expressions or an immediate");

  const MCExpr *Expr = MO.getExpr();
  Fixups.push_back(MCFixup::Create(0, Expr,
                                   MCFixupKind(Oi::fixup_Oi_26)));
  return 0;
}

unsigned OiMCCodeEmitter::
getExprOpValue(const MCExpr *Expr,SmallVectorImpl<MCFixup> &Fixups) const {
  int64_t Res;

  if (Expr->EvaluateAsAbsolute(Res))
    return Res;

  MCExpr::ExprKind Kind = Expr->getKind();
  if (Kind == MCExpr::Constant) {
    return cast<MCConstantExpr>(Expr)->getValue();
  }

  if (Kind == MCExpr::Binary) {
    unsigned Res = getExprOpValue(cast<MCBinaryExpr>(Expr)->getLHS(), Fixups);
    Res += getExprOpValue(cast<MCBinaryExpr>(Expr)->getRHS(), Fixups);
    return Res;
  }
  if (Kind == MCExpr::SymbolRef) {
  Oi::Fixups FixupKind = Oi::Fixups(0);

  switch(cast<MCSymbolRefExpr>(Expr)->getKind()) {
  default: llvm_unreachable("Unknown fixup kind!");
    break;
  case MCSymbolRefExpr::VK_Mips_GPOFF_HI :
    FixupKind = Oi::fixup_Oi_GPOFF_HI;
    break;
  case MCSymbolRefExpr::VK_Mips_GPOFF_LO :
    FixupKind = Oi::fixup_Oi_GPOFF_LO;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT_PAGE :
    FixupKind = Oi::fixup_Oi_GOT_PAGE;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT_OFST :
    FixupKind = Oi::fixup_Oi_GOT_OFST;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT_DISP :
    FixupKind = Oi::fixup_Oi_GOT_DISP;
    break;
  case MCSymbolRefExpr::VK_Mips_GPREL:
    FixupKind = Oi::fixup_Oi_GPREL16;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT_CALL:
    FixupKind = Oi::fixup_Oi_CALL16;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT16:
    FixupKind = Oi::fixup_Oi_GOT_Global;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT:
    FixupKind = Oi::fixup_Oi_GOT_Local;
    break;
  case MCSymbolRefExpr::VK_Mips_ABS_HI:
    FixupKind = Oi::fixup_Oi_HI16;
    break;
  case MCSymbolRefExpr::VK_Mips_ABS_LO:
    FixupKind = Oi::fixup_Oi_LO16;
    break;
  case MCSymbolRefExpr::VK_Mips_TLSGD:
    FixupKind = Oi::fixup_Oi_TLSGD;
    break;
  case MCSymbolRefExpr::VK_Mips_TLSLDM:
    FixupKind = Oi::fixup_Oi_TLSLDM;
    break;
  case MCSymbolRefExpr::VK_Mips_DTPREL_HI:
    FixupKind = Oi::fixup_Oi_DTPREL_HI;
    break;
  case MCSymbolRefExpr::VK_Mips_DTPREL_LO:
    FixupKind = Oi::fixup_Oi_DTPREL_LO;
    break;
  case MCSymbolRefExpr::VK_Mips_GOTTPREL:
    FixupKind = Oi::fixup_Oi_GOTTPREL;
    break;
  case MCSymbolRefExpr::VK_Mips_TPREL_HI:
    FixupKind = Oi::fixup_Oi_TPREL_HI;
    break;
  case MCSymbolRefExpr::VK_Mips_TPREL_LO:
    FixupKind = Oi::fixup_Oi_TPREL_LO;
    break;
  case MCSymbolRefExpr::VK_Mips_HIGHER:
    FixupKind = Oi::fixup_Oi_HIGHER;
    break;
  case MCSymbolRefExpr::VK_Mips_HIGHEST:
    FixupKind = Oi::fixup_Oi_HIGHEST;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT_HI16:
    FixupKind = Oi::fixup_Oi_GOT_HI16;
    break;
  case MCSymbolRefExpr::VK_Mips_GOT_LO16:
    FixupKind = Oi::fixup_Oi_GOT_LO16;
    break;
  case MCSymbolRefExpr::VK_Mips_CALL_HI16:
    FixupKind = Oi::fixup_Oi_CALL_HI16;
    break;
  case MCSymbolRefExpr::VK_Mips_CALL_LO16:
    FixupKind = Oi::fixup_Oi_CALL_LO16;
    break;
  } // switch

    Fixups.push_back(MCFixup::Create(0, Expr, MCFixupKind(FixupKind)));
    return 0;
  }
  return 0;
}

/// getMachineOpValue - Return binary encoding of operand. If the machine
/// operand requires relocation, record the relocation and return zero.
unsigned OiMCCodeEmitter::
getMachineOpValue(const MCInst &MI, const MCOperand &MO,
                  SmallVectorImpl<MCFixup> &Fixups) const {
  if (MO.isReg()) {
    unsigned Reg = MO.getReg();
    unsigned RegNo = Ctx.getRegisterInfo().getEncodingValue(Reg);
    return RegNo;
  } else if (MO.isImm()) {
    return static_cast<unsigned>(MO.getImm());
  } else if (MO.isFPImm()) {
    return static_cast<unsigned>(APFloat(MO.getFPImm())
        .bitcastToAPInt().getHiBits(32).getLimitedValue());
  }
  // MO must be an Expr.
  assert(MO.isExpr());
  return getExprOpValue(MO.getExpr(),Fixups);
}

/// getMemEncoding - Return binary encoding of memory related operand.
/// If the offset operand requires relocation, record the relocation.
unsigned
OiMCCodeEmitter::getMemEncoding(const MCInst &MI, unsigned OpNo,
                                  SmallVectorImpl<MCFixup> &Fixups) const {
  // Base register is encoded in bits 20-16, offset is encoded in bits 15-0.
  assert(MI.getOperand(OpNo).isReg());
  unsigned RegBits = getMachineOpValue(MI, MI.getOperand(OpNo),Fixups) << 16;
  unsigned OffBits = getMachineOpValue(MI, MI.getOperand(OpNo+1), Fixups);

  return (OffBits & 0xFFFF) | RegBits;
}

unsigned
OiMCCodeEmitter::getSizeExtEncoding(const MCInst &MI, unsigned OpNo,
                                      SmallVectorImpl<MCFixup> &Fixups) const {
  assert(MI.getOperand(OpNo).isImm());
  unsigned SizeEncoding = getMachineOpValue(MI, MI.getOperand(OpNo), Fixups);
  return SizeEncoding - 1;
}

// FIXME: should be called getMSBEncoding
//
unsigned
OiMCCodeEmitter::getSizeInsEncoding(const MCInst &MI, unsigned OpNo,
                                      SmallVectorImpl<MCFixup> &Fixups) const {
  assert(MI.getOperand(OpNo-1).isImm());
  assert(MI.getOperand(OpNo).isImm());
  unsigned Position = getMachineOpValue(MI, MI.getOperand(OpNo-1), Fixups);
  unsigned Size = getMachineOpValue(MI, MI.getOperand(OpNo), Fixups);

  return Position + Size - 1;
}

#include "OiGenMCCodeEmitter.inc"

