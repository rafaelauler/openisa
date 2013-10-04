//===-- Oi16RegisterInfo.cpp - OI16 Register Information -== ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the OI16 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "Oi16RegisterInfo.h"
#include "Oi.h"
#include "Oi16InstrInfo.h"
#include "OiAnalyzeImmediate.h"
#include "OiInstrInfo.h"
#include "OiMachineFunction.h"
#include "OiSubtarget.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/ValueTypes.h"
#include "llvm/DebugInfo.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetInstrInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

Oi16RegisterInfo::Oi16RegisterInfo(const OiSubtarget &ST,
    const Oi16InstrInfo &I)
  : OiRegisterInfo(ST), TII(I) {}

bool Oi16RegisterInfo::requiresRegisterScavenging
  (const MachineFunction &MF) const {
  return true;
}
bool Oi16RegisterInfo::requiresFrameIndexScavenging
  (const MachineFunction &MF) const {
  return true;
}

bool Oi16RegisterInfo::useFPForScavengingIndex
  (const MachineFunction &MF) const {
  return false;
}

bool Oi16RegisterInfo::saveScavengerRegister
  (MachineBasicBlock &MBB,
   MachineBasicBlock::iterator I,
   MachineBasicBlock::iterator &UseMI,
   const TargetRegisterClass *RC,
   unsigned Reg) const {
  DebugLoc DL;
  TII.copyPhysReg(MBB, I, DL, Oi::T0, Reg, true);
  TII.copyPhysReg(MBB, UseMI, DL, Reg, Oi::T0, true);
  return true;
}

// This function eliminate ADJCALLSTACKDOWN,
// ADJCALLSTACKUP pseudo instructions
void Oi16RegisterInfo::
eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                              MachineBasicBlock::iterator I) const {
  const TargetFrameLowering *TFI = MF.getTarget().getFrameLowering();

  if (!TFI->hasReservedCallFrame(MF)) {
    int64_t Amount = I->getOperand(0).getImm();

    if (I->getOpcode() == Oi::ADJCALLSTACKDOWN)
      Amount = -Amount;

    const Oi16InstrInfo *II = static_cast<const Oi16InstrInfo*>(&TII);

    II->adjustStackPtr(Oi::SP, Amount, MBB, I);
  }

  MBB.erase(I);
}

void Oi16RegisterInfo::eliminateFI(MachineBasicBlock::iterator II,
                                     unsigned OpNo, int FrameIndex,
                                     uint64_t StackSize,
                                     int64_t SPOffset) const {
  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  MachineFrameInfo *MFI = MF.getFrameInfo();

  const std::vector<CalleeSavedInfo> &CSI = MFI->getCalleeSavedInfo();
  int MinCSFI = 0;
  int MaxCSFI = -1;

  if (CSI.size()) {
    MinCSFI = CSI[0].getFrameIdx();
    MaxCSFI = CSI[CSI.size() - 1].getFrameIdx();
  }

  // The following stack frame objects are always
  // referenced relative to $sp:
  //  1. Outgoing arguments.
  //  2. Pointer to dynamically allocated stack space.
  //  3. Locations for callee-saved registers.
  // Everything else is referenced relative to whatever register
  // getFrameRegister() returns.
  unsigned FrameReg;

  if (FrameIndex >= MinCSFI && FrameIndex <= MaxCSFI)
    FrameReg = Oi::SP;
  else {
    const TargetFrameLowering *TFI = MF.getTarget().getFrameLowering();
    if (TFI->hasFP(MF)) {
      FrameReg = Oi::S0;
    }
    else {
      if ((MI.getNumOperands()> OpNo+2) && MI.getOperand(OpNo+2).isReg())
        FrameReg = MI.getOperand(OpNo+2).getReg();
      else
        FrameReg = Oi::SP;
    }
  }
  // Calculate final offset.
  // - There is no need to change the offset if the frame object
  //   is one of the
  //   following: an outgoing argument, pointer to a dynamically allocated
  //   stack space or a $gp restore location,
  // - If the frame object is any of the following,
  //   its offset must be adjusted
  //   by adding the size of the stack:
  //   incoming argument, callee-saved register location or local variable.
  int64_t Offset;
  Offset = SPOffset + (int64_t)StackSize;
  Offset += MI.getOperand(OpNo + 1).getImm();


  DEBUG(errs() << "Offset     : " << Offset << "\n" << "<--------->\n");

  if (!MI.isDebugValue() && ( ((FrameReg != Oi::SP) && !isInt<16>(Offset)) ||
      ((FrameReg == Oi::SP) && !isInt<15>(Offset)) )) {
    llvm_unreachable("frame offset does not fit in instruction");
  }
  MI.getOperand(OpNo).ChangeToRegister(FrameReg, false);
  MI.getOperand(OpNo + 1).ChangeToImmediate(Offset);


}
