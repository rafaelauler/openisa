//===-- Oi16InstrInfo.cpp - Oi16 Instruction Information --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Oi16 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "Oi16InstrInfo.h"
#include "InstPrinter/OiInstPrinter.h"
#include "OiMachineFunction.h"
#include "OiTargetMachine.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/RegisterScavenging.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

static cl::opt<bool> NeverUseSaveRestore(
  "oi16-never-use-save-restore",
  cl::init(false),
  cl::desc("For testing ability to adjust stack pointer "
           "without save/restore instruction"),
  cl::Hidden);


Oi16InstrInfo::Oi16InstrInfo(OiTargetMachine &tm)
  : OiInstrInfo(tm, Oi::BimmX16),
    RI(*tm.getSubtargetImpl(), *this) {}

const OiRegisterInfo &Oi16InstrInfo::getRegisterInfo() const {
  return RI;
}

/// isLoadFromStackSlot - If the specified machine instruction is a direct
/// load from a stack slot, return the virtual or physical register number of
/// the destination along with the FrameIndex of the loaded stack slot.  If
/// not, return 0.  This predicate must return 0 if the instruction has
/// any side effects other than loading from the stack slot.
unsigned Oi16InstrInfo::
isLoadFromStackSlot(const MachineInstr *MI, int &FrameIndex) const
{
  return 0;
}

/// isStoreToStackSlot - If the specified machine instruction is a direct
/// store to a stack slot, return the virtual or physical register number of
/// the source reg along with the FrameIndex of the loaded stack slot.  If
/// not, return 0.  This predicate must return 0 if the instruction has
/// any side effects other than storing to the stack slot.
unsigned Oi16InstrInfo::
isStoreToStackSlot(const MachineInstr *MI, int &FrameIndex) const
{
  return 0;
}

void Oi16InstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                                  MachineBasicBlock::iterator I, DebugLoc DL,
                                  unsigned DestReg, unsigned SrcReg,
                                  bool KillSrc) const {
  unsigned Opc = 0;

  if (Oi::CPU16RegsRegClass.contains(DestReg) &&
      Oi::CPURegsRegClass.contains(SrcReg))
    Opc = Oi::MoveR3216;
  else if (Oi::CPURegsRegClass.contains(DestReg) &&
           Oi::CPU16RegsRegClass.contains(SrcReg))
    Opc = Oi::Move32R16;
  else if ((SrcReg == Oi::HI) &&
           (Oi::CPU16RegsRegClass.contains(DestReg)))
    Opc = Oi::Mfhi16, SrcReg = 0;

  else if ((SrcReg == Oi::LO) &&
           (Oi::CPU16RegsRegClass.contains(DestReg)))
    Opc = Oi::Mflo16, SrcReg = 0;


  assert(Opc && "Cannot copy registers");

  MachineInstrBuilder MIB = BuildMI(MBB, I, DL, get(Opc));

  if (DestReg)
    MIB.addReg(DestReg, RegState::Define);

  if (SrcReg)
    MIB.addReg(SrcReg, getKillRegState(KillSrc));
}

void Oi16InstrInfo::
storeRegToStack(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                unsigned SrcReg, bool isKill, int FI,
                const TargetRegisterClass *RC, const TargetRegisterInfo *TRI,
                int64_t Offset) const {
  DebugLoc DL;
  if (I != MBB.end()) DL = I->getDebugLoc();
  MachineMemOperand *MMO = GetMemOperand(MBB, FI, MachineMemOperand::MOStore);
  unsigned Opc = 0;
  if (Oi::CPU16RegsRegClass.hasSubClassEq(RC))
    Opc = Oi::SwRxSpImmX16;
  assert(Opc && "Register class not handled!");
  BuildMI(MBB, I, DL, get(Opc)).addReg(SrcReg, getKillRegState(isKill))
    .addFrameIndex(FI).addImm(Offset).addMemOperand(MMO);
}

void Oi16InstrInfo::
loadRegFromStack(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                 unsigned DestReg, int FI, const TargetRegisterClass *RC,
                 const TargetRegisterInfo *TRI, int64_t Offset) const {
  DebugLoc DL;
  if (I != MBB.end()) DL = I->getDebugLoc();
  MachineMemOperand *MMO = GetMemOperand(MBB, FI, MachineMemOperand::MOLoad);
  unsigned Opc = 0;

  if (Oi::CPU16RegsRegClass.hasSubClassEq(RC))
    Opc = Oi::LwRxSpImmX16;
  assert(Opc && "Register class not handled!");
  BuildMI(MBB, I, DL, get(Opc), DestReg).addFrameIndex(FI).addImm(Offset)
    .addMemOperand(MMO);
}

bool Oi16InstrInfo::expandPostRAPseudo(MachineBasicBlock::iterator MI) const {
  MachineBasicBlock &MBB = *MI->getParent();
  switch(MI->getDesc().getOpcode()) {
  default:
    return false;
  case Oi::RetRA16:
    ExpandRetRA16(MBB, MI, Oi::JrcRa16);
    break;
  }

  MBB.erase(MI);
  return true;
}

/// GetOppositeBranchOpc - Return the inverse of the specified
/// opcode, e.g. turning BEQ to BNE.
unsigned Oi16InstrInfo::GetOppositeBranchOpc(unsigned Opc) const {
  switch (Opc) {
  default:  llvm_unreachable("Illegal opcode!");
  case Oi::BeqzRxImmX16: return Oi::BnezRxImmX16;
  case Oi::BnezRxImmX16: return Oi::BeqzRxImmX16;
  case Oi::BteqzT8CmpX16: return Oi::BtnezT8CmpX16;
  case Oi::BteqzT8SltX16: return Oi::BtnezT8SltX16;
  case Oi::BteqzT8SltiX16: return Oi::BtnezT8SltiX16;
  case Oi::BtnezX16: return Oi::BteqzX16;
  case Oi::BtnezT8CmpiX16: return Oi::BteqzT8CmpiX16;
  case Oi::BtnezT8SltuX16: return Oi::BteqzT8SltuX16;
  case Oi::BtnezT8SltiuX16: return Oi::BteqzT8SltiuX16;
  case Oi::BteqzX16: return Oi::BtnezX16;
  case Oi::BteqzT8CmpiX16: return Oi::BtnezT8CmpiX16;
  case Oi::BteqzT8SltuX16: return Oi::BtnezT8SltuX16;
  case Oi::BteqzT8SltiuX16: return Oi::BtnezT8SltiuX16;
  case Oi::BtnezT8CmpX16: return Oi::BteqzT8CmpX16;
  case Oi::BtnezT8SltX16: return Oi::BteqzT8SltX16;
  case Oi::BtnezT8SltiX16: return Oi::BteqzT8SltiX16;
  }
  assert(false && "Implement this function.");
  return 0;
}

// Adjust SP by FrameSize bytes. Save RA, S0, S1
void Oi16InstrInfo::makeFrame(unsigned SP, int64_t FrameSize,
                    MachineBasicBlock &MBB,
                    MachineBasicBlock::iterator I) const {
  DebugLoc DL = I != MBB.end() ? I->getDebugLoc() : DebugLoc();
  if (!NeverUseSaveRestore) {
    if (isUInt<11>(FrameSize))
      BuildMI(MBB, I, DL, get(Oi::SaveRaF16)).addImm(FrameSize);
    else {
      int Base = 2040; // should create template function like isUInt that
                       // returns largest possible n bit unsigned integer
      int64_t Remainder = FrameSize - Base;
      BuildMI(MBB, I, DL, get(Oi::SaveRaF16)). addImm(Base);
      if (isInt<16>(-Remainder))
        BuildAddiuSpImm(MBB, I, -Remainder);
      else
        adjustStackPtrBig(SP, -Remainder, MBB, I, Oi::V0, Oi::V1);
    }

  }
  else {
    //
    // sw ra, -4[sp]
    // sw s1, -8[sp]
    // sw s0, -12[sp]

    MachineInstrBuilder MIB1 = BuildMI(MBB, I, DL, get(Oi::SwRxSpImmX16),
                                       Oi::RA);
    MIB1.addReg(Oi::SP);
    MIB1.addImm(-4);
    MachineInstrBuilder MIB2 = BuildMI(MBB, I, DL, get(Oi::SwRxSpImmX16),
                                       Oi::S1);
    MIB2.addReg(Oi::SP);
    MIB2.addImm(-8);
    MachineInstrBuilder MIB3 = BuildMI(MBB, I, DL, get(Oi::SwRxSpImmX16),
                                       Oi::S0);
    MIB3.addReg(Oi::SP);
    MIB3.addImm(-12);
    adjustStackPtrBig(SP, -FrameSize, MBB, I, Oi::V0, Oi::V1);
  }
}

// Adjust SP by FrameSize bytes. Restore RA, S0, S1
void Oi16InstrInfo::restoreFrame(unsigned SP, int64_t FrameSize,
                                   MachineBasicBlock &MBB,
                                   MachineBasicBlock::iterator I) const {
  DebugLoc DL = I != MBB.end() ? I->getDebugLoc() : DebugLoc();
  if (!NeverUseSaveRestore) {
    if (isUInt<11>(FrameSize))
      BuildMI(MBB, I, DL, get(Oi::RestoreRaF16)).addImm(FrameSize);
    else {
      int Base = 2040; // should create template function like isUInt that
                       // returns largest possible n bit unsigned integer
      int64_t Remainder = FrameSize - Base;
      if (isInt<16>(Remainder))
        BuildAddiuSpImm(MBB, I, Remainder);
      else
        adjustStackPtrBig(SP, Remainder, MBB, I, Oi::A0, Oi::A1);
      BuildMI(MBB, I, DL, get(Oi::RestoreRaF16)). addImm(Base);
    }
  }
  else {
    adjustStackPtrBig(SP, FrameSize, MBB, I, Oi::A0, Oi::A1);
    // lw ra, -4[sp]
    // lw s1, -8[sp]
    // lw s0, -12[sp]
    MachineInstrBuilder MIB1 = BuildMI(MBB, I, DL, get(Oi::LwRxSpImmX16),
                                       Oi::A0);
    MIB1.addReg(Oi::SP);
    MIB1.addImm(-4);
    MachineInstrBuilder MIB0 = BuildMI(MBB, I, DL, get(Oi::Move32R16),
                                       Oi::RA);
     MIB0.addReg(Oi::A0);
    MachineInstrBuilder MIB2 = BuildMI(MBB, I, DL, get(Oi::LwRxSpImmX16),
                                       Oi::S1);
    MIB2.addReg(Oi::SP);
    MIB2.addImm(-8);
    MachineInstrBuilder MIB3 = BuildMI(MBB, I, DL, get(Oi::LwRxSpImmX16),
                                       Oi::S0);
    MIB3.addReg(Oi::SP);
    MIB3.addImm(-12);
  }

}

// Adjust SP by Amount bytes where bytes can be up to 32bit number.
// This can only be called at times that we know that there is at least one free
// register.
// This is clearly safe at prologue and epilogue.
//
void Oi16InstrInfo::adjustStackPtrBig(unsigned SP, int64_t Amount,
                                        MachineBasicBlock &MBB,
                                        MachineBasicBlock::iterator I,
                                        unsigned Reg1, unsigned Reg2) const {
  DebugLoc DL = I != MBB.end() ? I->getDebugLoc() : DebugLoc();
//  MachineRegisterInfo &RegInfo = MBB.getParent()->getRegInfo();
//  unsigned Reg1 = RegInfo.createVirtualRegister(&Oi::CPU16RegsRegClass);
//  unsigned Reg2 = RegInfo.createVirtualRegister(&Oi::CPU16RegsRegClass);
  //
  // li reg1, constant
  // move reg2, sp
  // add reg1, reg1, reg2
  // move sp, reg1
  //
  //
  MachineInstrBuilder MIB1 = BuildMI(MBB, I, DL, get(Oi::LwConstant32), Reg1);
  MIB1.addImm(Amount);
  MachineInstrBuilder MIB2 = BuildMI(MBB, I, DL, get(Oi::MoveR3216), Reg2);
  MIB2.addReg(Oi::SP, RegState::Kill);
  MachineInstrBuilder MIB3 = BuildMI(MBB, I, DL, get(Oi::AdduRxRyRz16), Reg1);
  MIB3.addReg(Reg1);
  MIB3.addReg(Reg2, RegState::Kill);
  MachineInstrBuilder MIB4 = BuildMI(MBB, I, DL, get(Oi::Move32R16),
                                                     Oi::SP);
  MIB4.addReg(Reg1, RegState::Kill);
}

void Oi16InstrInfo::adjustStackPtrBigUnrestricted(unsigned SP, int64_t Amount,
                    MachineBasicBlock &MBB,
                    MachineBasicBlock::iterator I) const {
   assert(false && "adjust stack pointer amount exceeded");
}

/// Adjust SP by Amount bytes.
void Oi16InstrInfo::adjustStackPtr(unsigned SP, int64_t Amount,
                                     MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const {
  if (isInt<16>(Amount))  // need to change to addiu sp, ....and isInt<16>
    BuildAddiuSpImm(MBB, I, Amount);
  else
    adjustStackPtrBigUnrestricted(SP, Amount, MBB, I);
}

/// This function generates the sequence of instructions needed to get the
/// result of adding register REG and immediate IMM.
unsigned
Oi16InstrInfo::loadImmediate(unsigned FrameReg,
                               int64_t Imm, MachineBasicBlock &MBB,
                               MachineBasicBlock::iterator II, DebugLoc DL,
                               unsigned &NewImm) const {
  //
  // given original instruction is:
  // Instr rx, T[offset] where offset is too big.
  //
  // lo = offset & 0xFFFF
  // hi = ((offset >> 16) + (lo >> 15)) & 0xFFFF;
  //
  // let T = temporary register
  // li T, hi
  // shl T, 16
  // add T, Rx, T
  //
  RegScavenger rs;
  int32_t lo = Imm & 0xFFFF;
  int32_t hi = ((Imm >> 16) + (lo >> 15)) & 0xFFFF;
  NewImm = lo;
  unsigned Reg =0;
  unsigned SpReg = 0;
  rs.enterBasicBlock(&MBB);
  rs.forward(II);
  //
  // we use T0 for the first register, if we need to save something away.
  // we use T1 for the second register, if we need to save something away.
  //
  unsigned FirstRegSaved =0, SecondRegSaved=0;
  unsigned FirstRegSavedTo = 0, SecondRegSavedTo = 0;

  Reg = rs.FindUnusedReg(&Oi::CPU16RegsRegClass);
  if (Reg == 0) {
    FirstRegSaved = Reg = Oi::V0;
    FirstRegSavedTo = Oi::T0;
    copyPhysReg(MBB, II, DL, FirstRegSavedTo, FirstRegSaved, true);
  }
  else
    rs.setUsed(Reg);
  BuildMI(MBB, II, DL, get(Oi::LiRxImmX16), Reg).addImm(hi);
  BuildMI(MBB, II, DL, get(Oi::SllX16), Reg).addReg(Reg).
    addImm(16);
  if (FrameReg == Oi::SP) {
    SpReg = rs.FindUnusedReg(&Oi::CPU16RegsRegClass);
    if (SpReg == 0) {
      if (Reg != Oi::V1) {
        SecondRegSaved = SpReg = Oi::V1;
        SecondRegSavedTo = Oi::T1;
      }
      else {
        SecondRegSaved = SpReg = Oi::V0;
        SecondRegSavedTo = Oi::T0;
      }
      copyPhysReg(MBB, II, DL, SecondRegSavedTo, SecondRegSaved, true);
    }
    else
      rs.setUsed(SpReg);

    copyPhysReg(MBB, II, DL, SpReg, Oi::SP, false);
    BuildMI(MBB, II, DL, get(Oi::  AdduRxRyRz16), Reg).addReg(SpReg)
      .addReg(Reg);
  }
  else
    BuildMI(MBB, II, DL, get(Oi::  AdduRxRyRz16), Reg).addReg(FrameReg)
      .addReg(Reg, RegState::Kill);
  if (FirstRegSaved || SecondRegSaved) {
    II = llvm::next(II);
    if (FirstRegSaved)
      copyPhysReg(MBB, II, DL, FirstRegSaved, FirstRegSavedTo, true);
    if (SecondRegSaved)
      copyPhysReg(MBB, II, DL, SecondRegSaved, SecondRegSavedTo, true);
  }
  return Reg;
}

unsigned Oi16InstrInfo::GetAnalyzableBrOpc(unsigned Opc) const {
  return (Opc == Oi::BeqzRxImmX16   || Opc == Oi::BimmX16  ||
          Opc == Oi::BnezRxImmX16   || Opc == Oi::BteqzX16 ||
          Opc == Oi::BteqzT8CmpX16  || Opc == Oi::BteqzT8CmpiX16 ||
          Opc == Oi::BteqzT8SltX16  || Opc == Oi::BteqzT8SltuX16  ||
          Opc == Oi::BteqzT8SltiX16 || Opc == Oi::BteqzT8SltiuX16 ||
          Opc == Oi::BtnezX16       || Opc == Oi::BtnezT8CmpX16 ||
          Opc == Oi::BtnezT8CmpiX16 || Opc == Oi::BtnezT8SltX16 ||
          Opc == Oi::BtnezT8SltuX16 || Opc == Oi::BtnezT8SltiX16 ||
          Opc == Oi::BtnezT8SltiuX16 ) ? Opc : 0;
}

void Oi16InstrInfo::ExpandRetRA16(MachineBasicBlock &MBB,
                                  MachineBasicBlock::iterator I,
                                  unsigned Opc) const {
  BuildMI(MBB, I, I->getDebugLoc(), get(Opc));
}


const MCInstrDesc &Oi16InstrInfo::AddiuSpImm(int64_t Imm) const {
  if (validSpImm8(Imm))
    return get(Oi::AddiuSpImm16);
  else
    return get(Oi::AddiuSpImmX16);
}

void Oi16InstrInfo::BuildAddiuSpImm
  (MachineBasicBlock &MBB, MachineBasicBlock::iterator I, int64_t Imm) const {
  DebugLoc DL = I != MBB.end() ? I->getDebugLoc() : DebugLoc();
  BuildMI(MBB, I, DL, AddiuSpImm(Imm)).addImm(Imm);
}

const OiInstrInfo *llvm::createOi16InstrInfo(OiTargetMachine &TM) {
  return new Oi16InstrInfo(TM);
}
