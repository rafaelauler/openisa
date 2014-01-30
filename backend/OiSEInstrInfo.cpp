//===-- OiSEInstrInfo.cpp - Oi32/64 Instruction Information -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Oi32/64 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "OiSEInstrInfo.h"
#include "InstPrinter/OiInstPrinter.h"
#include "OiMachineFunction.h"
#include "OiTargetMachine.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

OiSEInstrInfo::OiSEInstrInfo(OiTargetMachine &tm)
  : OiInstrInfo(tm,
                  tm.getRelocationModel() == Reloc::PIC_ ? Oi::B : Oi::J),
    RI(*tm.getSubtargetImpl(), *this),
    IsN64(tm.getSubtarget<OiSubtarget>().isABI_N64()) {}

const OiRegisterInfo &OiSEInstrInfo::getRegisterInfo() const {
  return RI;
}

/// isLoadFromStackSlot - If the specified machine instruction is a direct
/// load from a stack slot, return the virtual or physical register number of
/// the destination along with the FrameIndex of the loaded stack slot.  If
/// not, return 0.  This predicate must return 0 if the instruction has
/// any side effects other than loading from the stack slot.
unsigned OiSEInstrInfo::
isLoadFromStackSlot(const MachineInstr *MI, int &FrameIndex) const
{
  unsigned Opc = MI->getOpcode();

  if ((Opc == Oi::LW)    || (Opc == Oi::LW_P8)  || (Opc == Oi::LD) ||
      (Opc == Oi::LD_P8) || (Opc == Oi::LWC1)   || (Opc == Oi::LWC1_P8) ||
      (Opc == Oi::LDC1)  || (Opc == Oi::LDC164) ||
      (Opc == Oi::LDC164_P8) || (Opc == Oi::SPILLLW)) {
    if ((MI->getOperand(1).isFI()) && // is a stack slot
        (MI->getOperand(2).isImm()) &&  // the imm is zero
        (isZeroImm(MI->getOperand(2)))) {
      FrameIndex = MI->getOperand(1).getIndex();
      return MI->getOperand(0).getReg();
    }
  }

  return 0;
}

/// isStoreToStackSlot - If the specified machine instruction is a direct
/// store to a stack slot, return the virtual or physical register number of
/// the source reg along with the FrameIndex of the loaded stack slot.  If
/// not, return 0.  This predicate must return 0 if the instruction has
/// any side effects other than storing to the stack slot.
unsigned OiSEInstrInfo::
isStoreToStackSlot(const MachineInstr *MI, int &FrameIndex) const
{
  unsigned Opc = MI->getOpcode();

  if ((Opc == Oi::SW)    || (Opc == Oi::SW_P8)  || (Opc == Oi::SD) ||
      (Opc == Oi::SD_P8) || (Opc == Oi::SWC1)   || (Opc == Oi::SWC1_P8) ||
      (Opc == Oi::SDC1)  || (Opc == Oi::SDC164) ||
      (Opc == Oi::SDC164_P8) || (Opc == Oi::SPILLSW)) {
    if ((MI->getOperand(1).isFI()) && // is a stack slot
        (MI->getOperand(2).isImm()) &&  // the imm is zero
        (isZeroImm(MI->getOperand(2)))) {
      FrameIndex = MI->getOperand(1).getIndex();
      return MI->getOperand(0).getReg();
    }
  }
  return 0;
}

void OiSEInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                                  MachineBasicBlock::iterator I, DebugLoc DL,
                                  unsigned DestReg, unsigned SrcReg,
                                  bool KillSrc) const {
  unsigned Opc = 0, ZeroReg = 0;

  if (Oi::CPURegsRegClass.contains(DestReg)) { // Copy to CPU Reg.
    if (Oi::CPURegsRegClass.contains(SrcReg))
      Opc = Oi::OR, ZeroReg = Oi::ZERO;
    else if (Oi::CCRRegClass.contains(SrcReg))
      Opc = Oi::CFC1;
    else if (Oi::FGR32RegClass.contains(SrcReg))
      Opc = Oi::MFC1;
    else if (Oi::HIRegsRegClass.contains(SrcReg))
      Opc = Oi::MFHI, SrcReg = 0;
    else if (Oi::LORegsRegClass.contains(SrcReg))
      Opc = Oi::MFLO, SrcReg = 0;
    else if (Oi::HIRegsDSPRegClass.contains(SrcReg))
      Opc = Oi::MFHI_DSP;
    else if (Oi::LORegsDSPRegClass.contains(SrcReg))
      Opc = Oi::MFLO_DSP;
    else if (Oi::DSPCCRegClass.contains(SrcReg)) {
      BuildMI(MBB, I, DL, get(Oi::RDDSP), DestReg).addImm(1 << 4)
        .addReg(SrcReg, RegState::Implicit | getKillRegState(KillSrc));
      return;
    }
  }
  else if (Oi::CPURegsRegClass.contains(SrcReg)) { // Copy from CPU Reg.
    if (Oi::CCRRegClass.contains(DestReg))
      Opc = Oi::CTC1;
    else if (Oi::FGR32RegClass.contains(DestReg))
      Opc = Oi::MTC1;
    else if (Oi::HIRegsRegClass.contains(DestReg))
      Opc = Oi::MTHI, DestReg = 0;
    else if (Oi::LORegsRegClass.contains(DestReg))
      Opc = Oi::MTLO, DestReg = 0;
    else if (Oi::HIRegsDSPRegClass.contains(DestReg))
      Opc = Oi::MTHI_DSP;
    else if (Oi::LORegsDSPRegClass.contains(DestReg))
      Opc = Oi::MTLO_DSP;
    else if (Oi::DSPCCRegClass.contains(DestReg)) {
      BuildMI(MBB, I, DL, get(Oi::WRDSP))
        .addReg(SrcReg, getKillRegState(KillSrc)).addImm(1 << 4)
        .addReg(DestReg, RegState::ImplicitDefine);
      return;
    }
  }
  else if (Oi::FGR32RegClass.contains(DestReg, SrcReg))
    Opc = Oi::FMOV_S;
  else if (Oi::AFGR64RegClass.contains(DestReg, SrcReg))
    Opc = Oi::FMOV_D32;
  else if (Oi::FGR64RegClass.contains(DestReg, SrcReg))
    Opc = Oi::FMOV_D64;
  else if (Oi::CCRRegClass.contains(DestReg, SrcReg))
    Opc = Oi::MOVCCRToCCR;
  else if (Oi::CPU64RegsRegClass.contains(DestReg)) { // Copy to CPU64 Reg.
    if (Oi::CPU64RegsRegClass.contains(SrcReg))
      Opc = Oi::OR64, ZeroReg = Oi::ZERO_64;
    else if (Oi::HIRegs64RegClass.contains(SrcReg))
      Opc = Oi::MFHI64, SrcReg = 0;
    else if (Oi::LORegs64RegClass.contains(SrcReg))
      Opc = Oi::MFLO64, SrcReg = 0;
    else if (Oi::FGR64RegClass.contains(SrcReg))
      Opc = Oi::DMFC1;
  }
  else if (Oi::CPU64RegsRegClass.contains(SrcReg)) { // Copy from CPU64 Reg.
    if (Oi::HIRegs64RegClass.contains(DestReg))
      Opc = Oi::MTHI64, DestReg = 0;
    else if (Oi::LORegs64RegClass.contains(DestReg))
      Opc = Oi::MTLO64, DestReg = 0;
    else if (Oi::FGR64RegClass.contains(DestReg))
      Opc = Oi::DMTC1;
  }

  assert(Opc && "Cannot copy registers");

  MachineInstrBuilder MIB = BuildMI(MBB, I, DL, get(Opc));

  if (DestReg)
    MIB.addReg(DestReg, RegState::Define);

  if (SrcReg)
    MIB.addReg(SrcReg, getKillRegState(KillSrc));

  if (ZeroReg)
    MIB.addReg(ZeroReg);
}

void OiSEInstrInfo::
storeRegToStack(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                unsigned SrcReg, bool isKill, int FI,
                const TargetRegisterClass *RC, const TargetRegisterInfo *TRI,
                int64_t Offset) const {
  DebugLoc DL;
  if (I != MBB.end()) DL = I->getDebugLoc();
  MachineMemOperand *MMO = GetMemOperand(MBB, FI, MachineMemOperand::MOStore);

  unsigned Opc = 0;

  if (Oi::CPURegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SW_P8 : Oi::SPILLSW;
  else if (Oi::CPU64RegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SD_P8 : Oi::SD;
  else if (Oi::ACRegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::STORE_AC64_P8 : Oi::STORE_AC64;
  else if (Oi::ACRegsDSPRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::STORE_AC_DSP_P8 : Oi::STORE_AC_DSP;
  else if (Oi::ACRegs128RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::STORE_AC128_P8 : Oi::STORE_AC128;
  else if (Oi::DSPCCRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::STORE_CCOND_DSP_P8 : Oi::STORE_CCOND_DSP;
  else if (Oi::FGR32RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SWC1_P8 : Oi::SWC1;
  else if (Oi::AFGR64RegClass.hasSubClassEq(RC))
    Opc = Oi::SDC1;
  else if (Oi::FGR64RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SDC164_P8 : Oi::SDC164;

  assert(Opc && "Register class not handled!");
  BuildMI(MBB, I, DL, get(Opc)).addReg(SrcReg, getKillRegState(isKill))
    .addFrameIndex(FI).addImm(Offset).addMemOperand(MMO);
}

void OiSEInstrInfo::
loadRegFromStack(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                 unsigned DestReg, int FI, const TargetRegisterClass *RC,
                 const TargetRegisterInfo *TRI, int64_t Offset) const {
  DebugLoc DL;
  if (I != MBB.end()) DL = I->getDebugLoc();
  MachineMemOperand *MMO = GetMemOperand(MBB, FI, MachineMemOperand::MOLoad);
  unsigned Opc = 0;

  if (Oi::CPURegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LW_P8 : Oi::SPILLLW;
  else if (Oi::CPU64RegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LD_P8 : Oi::LD;
  else if (Oi::ACRegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LOAD_AC64_P8 : Oi::LOAD_AC64;
  else if (Oi::ACRegsDSPRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LOAD_AC_DSP_P8 : Oi::LOAD_AC_DSP;
  else if (Oi::ACRegs128RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LOAD_AC128_P8 : Oi::LOAD_AC128;
  else if (Oi::DSPCCRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LOAD_CCOND_DSP_P8 : Oi::LOAD_CCOND_DSP;
  else if (Oi::FGR32RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LWC1_P8 : Oi::LWC1;
  else if (Oi::AFGR64RegClass.hasSubClassEq(RC))
    Opc = Oi::LDC1;
  else if (Oi::FGR64RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LDC164_P8 : Oi::LDC164;

  assert(Opc && "Register class not handled!");
  BuildMI(MBB, I, DL, get(Opc), DestReg).addFrameIndex(FI).addImm(Offset)
    .addMemOperand(MMO);
}

bool OiSEInstrInfo::expandPostRAPseudo(MachineBasicBlock::iterator MI) const {
  MachineBasicBlock &MBB = *MI->getParent();

  switch(MI->getDesc().getOpcode()) {
  default:
    return false;
  case Oi::RetRA:
    ExpandRetRA(MBB, MI, Oi::RET);
    break;
  case Oi::BuildPairF64:
    ExpandBuildPairF64(MBB, MI);
    break;
  case Oi::ExtractElementF64:
    ExpandExtractElementF64(MBB, MI);
    break;
  case Oi::OIeh_return32:
  case Oi::OIeh_return64:
    ExpandEhReturn(MBB, MI);
    break;
  }

  MBB.erase(MI);
  return true;
}

/// GetOppositeBranchOpc - Return the inverse of the specified
/// opcode, e.g. turning BEQ to BNE.
unsigned OiSEInstrInfo::GetOppositeBranchOpc(unsigned Opc) const {
  switch (Opc) {
  default:           llvm_unreachable("Illegal opcode!");
  case Oi::BEQ:    return Oi::BNE;
  case Oi::BNE:    return Oi::BEQ;
  case Oi::BGTZ:   return Oi::BLEZ;
  case Oi::BGEZ:   return Oi::BLTZ;
  case Oi::BLTZ:   return Oi::BGEZ;
  case Oi::BLEZ:   return Oi::BGTZ;
  case Oi::BEQ64:  return Oi::BNE64;
  case Oi::BNE64:  return Oi::BEQ64;
  case Oi::BGTZ64: return Oi::BLEZ64;
  case Oi::BGEZ64: return Oi::BLTZ64;
  case Oi::BLTZ64: return Oi::BGEZ64;
  case Oi::BLEZ64: return Oi::BGTZ64;
  case Oi::BC1T:   return Oi::BC1F;
  case Oi::BC1F:   return Oi::BC1T;
  }
}

/// Adjust SP by Amount bytes.
void OiSEInstrInfo::adjustStackPtr(unsigned SP, int64_t Amount,
                                     MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const {
  const OiSubtarget &STI = TM.getSubtarget<OiSubtarget>();
  DebugLoc DL = I != MBB.end() ? I->getDebugLoc() : DebugLoc();
  unsigned ADDu = STI.isABI_N64() ? Oi::DADDu : Oi::ADDu;
  unsigned ADDiu = STI.isABI_N64() ? Oi::DADDiu : Oi::ADDiu;

  if (isInt<32>(Amount))// addi sp, sp, amount
    BuildMI(MBB, I, DL, get(ADDiu), SP).addReg(SP).addImm(Amount);
  else { // Expand immediate that doesn't fit in 16-bit.
    unsigned Reg = loadImmediate(Amount, MBB, I, DL, 0);
    BuildMI(MBB, I, DL, get(ADDu), SP).addReg(SP).addReg(Reg, RegState::Kill);
  }
}

/// This function generates the sequence of instructions needed to get the
/// result of adding register REG and immediate IMM.
unsigned
OiSEInstrInfo::loadImmediate(int64_t Imm, MachineBasicBlock &MBB,
                               MachineBasicBlock::iterator II, DebugLoc DL,
                               unsigned *NewImm) const {
  OiAnalyzeImmediate AnalyzeImm;
  const OiSubtarget &STI = TM.getSubtarget<OiSubtarget>();
  MachineRegisterInfo &RegInfo = MBB.getParent()->getRegInfo();
  unsigned Size = STI.isABI_N64() ? 64 : 32;
  unsigned LUi = STI.isABI_N64() ? Oi::LUi64 : Oi::LUi;
  unsigned ZEROReg = STI.isABI_N64() ? Oi::ZERO_64 : Oi::ZERO;
  const TargetRegisterClass *RC = STI.isABI_N64() ?
    &Oi::CPU64RegsRegClass : &Oi::CPURegsRegClass;
  bool LastInstrIsADDiu = NewImm;

  const OiAnalyzeImmediate::InstSeq &Seq =
    AnalyzeImm.Analyze(Imm, Size, LastInstrIsADDiu);
  OiAnalyzeImmediate::InstSeq::const_iterator Inst = Seq.begin();

  assert(Seq.size());

  // The first instruction can be a LUi, which is different from other
  // instructions (ADDiu, ORI and SLL) in that it does not have a register
  // operand.
  unsigned Reg = RegInfo.createVirtualRegister(RC);

  if (LastInstrIsADDiu && Seq.size() == 1) {
    BuildMI(MBB, II, DL, get(Inst->Opc), Reg).addReg(ZEROReg)
      .addImm(SignExtend64<16>(Inst->ImmOpnd));
    *NewImm = 0;
    return Reg;
  }

  if (Inst->Opc == LUi)
    BuildMI(MBB, II, DL, get(LUi), Reg).addImm(SignExtend64<16>(Inst->ImmOpnd));
  else
    BuildMI(MBB, II, DL, get(Inst->Opc), Reg).addReg(ZEROReg)
      .addImm(SignExtend64<16>(Inst->ImmOpnd));

  // Build the remaining instructions in Seq.
  for (++Inst; Inst != Seq.end() - LastInstrIsADDiu; ++Inst)
    BuildMI(MBB, II, DL, get(Inst->Opc), Reg).addReg(Reg, RegState::Kill)
      .addImm(SignExtend64<16>(Inst->ImmOpnd));

  if (LastInstrIsADDiu)
    *NewImm = Inst->ImmOpnd;

  return Reg;
}

unsigned OiSEInstrInfo::GetAnalyzableBrOpc(unsigned Opc) const {
  return (Opc == Oi::BEQ    || Opc == Oi::BNE    || Opc == Oi::BGTZ   ||
          Opc == Oi::BGEZ   || Opc == Oi::BLTZ   || Opc == Oi::BLEZ   ||
          Opc == Oi::BEQ64  || Opc == Oi::BNE64  || Opc == Oi::BGTZ64 ||
          Opc == Oi::BGEZ64 || Opc == Oi::BLTZ64 || Opc == Oi::BLEZ64 ||
          Opc == Oi::BC1T   || Opc == Oi::BC1F   || Opc == Oi::B      ||
          Opc == Oi::J) ?
         Opc : 0;
}

void OiSEInstrInfo::ExpandRetRA(MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator I,
                                unsigned Opc) const {
  BuildMI(MBB, I, I->getDebugLoc(), get(Opc)).addReg(Oi::RA);
}

void OiSEInstrInfo::ExpandExtractElementF64(MachineBasicBlock &MBB,
                                          MachineBasicBlock::iterator I) const {
  unsigned DstReg = I->getOperand(0).getReg();
  unsigned SrcReg = I->getOperand(1).getReg();
  unsigned N = I->getOperand(2).getImm();
  const MCInstrDesc& Mfc1Tdd = get(Oi::MFC1);
  DebugLoc dl = I->getDebugLoc();

  assert(N < 2 && "Invalid immediate");
  unsigned SubIdx = N ? Oi::sub_fpodd : Oi::sub_fpeven;
  unsigned SubReg = getRegisterInfo().getSubReg(SrcReg, SubIdx);

  BuildMI(MBB, I, dl, Mfc1Tdd, DstReg).addReg(SubReg);
}

void OiSEInstrInfo::ExpandBuildPairF64(MachineBasicBlock &MBB,
                                       MachineBasicBlock::iterator I) const {
  unsigned DstReg = I->getOperand(0).getReg();
  unsigned LoReg = I->getOperand(1).getReg(), HiReg = I->getOperand(2).getReg();
  const MCInstrDesc& Mtc1Tdd = get(Oi::MTC1);
  DebugLoc dl = I->getDebugLoc();
  const TargetRegisterInfo &TRI = getRegisterInfo();

  // mtc1 Lo, $fp
  // mtc1 Hi, $fp + 1
  BuildMI(MBB, I, dl, Mtc1Tdd, TRI.getSubReg(DstReg, Oi::sub_fpeven))
    .addReg(LoReg);
  BuildMI(MBB, I, dl, Mtc1Tdd, TRI.getSubReg(DstReg, Oi::sub_fpodd))
    .addReg(HiReg);
}

void OiSEInstrInfo::ExpandEhReturn(MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const {
  // This pseudo instruction is generated as part of the lowering of
  // ISD::EH_RETURN. We convert it to a stack increment by OffsetReg, and
  // indirect jump to TargetReg
  const OiSubtarget &STI = TM.getSubtarget<OiSubtarget>();
  unsigned ADDU = STI.isABI_N64() ? Oi::DADDu : Oi::ADDu;
  unsigned OR = STI.isABI_N64() ? Oi::OR64 : Oi::OR;
  unsigned JR = STI.isABI_N64() ? Oi::JR64 : Oi::JR;
  unsigned SP = STI.isABI_N64() ? Oi::SP_64 : Oi::SP;
  unsigned RA = STI.isABI_N64() ? Oi::RA_64 : Oi::RA;
  unsigned T9 = STI.isABI_N64() ? Oi::T9_64 : Oi::T9;
  unsigned ZERO = STI.isABI_N64() ? Oi::ZERO_64 : Oi::ZERO;
  unsigned OffsetReg = I->getOperand(0).getReg();
  unsigned TargetReg = I->getOperand(1).getReg();

  // or   $ra, $v0, $zero
  // addu $sp, $sp, $v1
  // jr   $ra
  if (TM.getRelocationModel() == Reloc::PIC_)
    BuildMI(MBB, I, I->getDebugLoc(), TM.getInstrInfo()->get(OR), T9)
        .addReg(TargetReg).addReg(ZERO);
  BuildMI(MBB, I, I->getDebugLoc(), TM.getInstrInfo()->get(OR), RA)
      .addReg(TargetReg).addReg(ZERO);
  BuildMI(MBB, I, I->getDebugLoc(), TM.getInstrInfo()->get(ADDU), SP)
      .addReg(SP).addReg(OffsetReg);
  BuildMI(MBB, I, I->getDebugLoc(), TM.getInstrInfo()->get(JR)).addReg(RA);
}

const OiInstrInfo *llvm::createOiSEInstrInfo(OiTargetMachine &TM) {
  return new OiSEInstrInfo(TM);
}
