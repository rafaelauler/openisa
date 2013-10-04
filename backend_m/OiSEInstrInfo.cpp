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
      (Opc == Oi::LDC164_P8)) {
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
      (Opc == Oi::SDC164_P8)) {
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
    else if (SrcReg == Oi::HI)
      Opc = Oi::MFHI, SrcReg = 0;
    else if (SrcReg == Oi::LO)
      Opc = Oi::MFLO, SrcReg = 0;
  }
  else if (Oi::CPURegsRegClass.contains(SrcReg)) { // Copy from CPU Reg.
    if (Oi::CCRRegClass.contains(DestReg))
      Opc = Oi::CTC1;
    else if (Oi::FGR32RegClass.contains(DestReg))
      Opc = Oi::MTC1;
    else if (DestReg == Oi::HI)
      Opc = Oi::MTHI, DestReg = 0;
    else if (DestReg == Oi::LO)
      Opc = Oi::MTLO, DestReg = 0;
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
    else if (SrcReg == Oi::HI64)
      Opc = Oi::MFHI64, SrcReg = 0;
    else if (SrcReg == Oi::LO64)
      Opc = Oi::MFLO64, SrcReg = 0;
    else if (Oi::FGR64RegClass.contains(SrcReg))
      Opc = Oi::DMFC1;
  }
  else if (Oi::CPU64RegsRegClass.contains(SrcReg)) { // Copy from CPU64 Reg.
    if (DestReg == Oi::HI64)
      Opc = Oi::MTHI64, DestReg = 0;
    else if (DestReg == Oi::LO64)
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
storeRegToStackSlot(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                    unsigned SrcReg, bool isKill, int FI,
                    const TargetRegisterClass *RC,
                    const TargetRegisterInfo *TRI) const {
  DebugLoc DL;
  if (I != MBB.end()) DL = I->getDebugLoc();
  MachineMemOperand *MMO = GetMemOperand(MBB, FI, MachineMemOperand::MOStore);

  unsigned Opc = 0;

  if (Oi::CPURegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SW_P8 : Oi::SW;
  else if (Oi::CPU64RegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SD_P8 : Oi::SD;
  else if (Oi::FGR32RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SWC1_P8 : Oi::SWC1;
  else if (Oi::AFGR64RegClass.hasSubClassEq(RC))
    Opc = Oi::SDC1;
  else if (Oi::FGR64RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::SDC164_P8 : Oi::SDC164;

  assert(Opc && "Register class not handled!");
  BuildMI(MBB, I, DL, get(Opc)).addReg(SrcReg, getKillRegState(isKill))
    .addFrameIndex(FI).addImm(0).addMemOperand(MMO);
}

void OiSEInstrInfo::
loadRegFromStackSlot(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                     unsigned DestReg, int FI,
                     const TargetRegisterClass *RC,
                     const TargetRegisterInfo *TRI) const
{
  DebugLoc DL;
  if (I != MBB.end()) DL = I->getDebugLoc();
  MachineMemOperand *MMO = GetMemOperand(MBB, FI, MachineMemOperand::MOLoad);
  unsigned Opc = 0;

  if (Oi::CPURegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LW_P8 : Oi::LW;
  else if (Oi::CPU64RegsRegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LD_P8 : Oi::LD;
  else if (Oi::FGR32RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LWC1_P8 : Oi::LWC1;
  else if (Oi::AFGR64RegClass.hasSubClassEq(RC))
    Opc = Oi::LDC1;
  else if (Oi::FGR64RegClass.hasSubClassEq(RC))
    Opc = IsN64 ? Oi::LDC164_P8 : Oi::LDC164;

  assert(Opc && "Register class not handled!");
  BuildMI(MBB, I, DL, get(Opc), DestReg).addFrameIndex(FI).addImm(0)
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

  if (isInt<16>(Amount))// addi sp, sp, amount
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

  assert(Seq.size() && (!LastInstrIsADDiu || (Seq.size() > 1)));

  // The first instruction can be a LUi, which is different from other
  // instructions (ADDiu, ORI and SLL) in that it does not have a register
  // operand.
  unsigned Reg = RegInfo.createVirtualRegister(RC);

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

const OiInstrInfo *llvm::createOiSEInstrInfo(OiTargetMachine &TM) {
  return new OiSEInstrInfo(TM);
}
