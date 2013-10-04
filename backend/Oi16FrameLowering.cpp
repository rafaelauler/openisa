//===-- Oi16FrameLowering.cpp - Oi16 Frame Information ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Oi16 implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#include "Oi16FrameLowering.h"
#include "MCTargetDesc/OiBaseInfo.h"
#include "Oi16InstrInfo.h"
#include "OiInstrInfo.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

void Oi16FrameLowering::emitPrologue(MachineFunction &MF) const {
  MachineBasicBlock &MBB = MF.front();
  MachineFrameInfo *MFI = MF.getFrameInfo();
  const Oi16InstrInfo &TII =
    *static_cast<const Oi16InstrInfo*>(MF.getTarget().getInstrInfo());
  MachineBasicBlock::iterator MBBI = MBB.begin();
  DebugLoc dl = MBBI != MBB.end() ? MBBI->getDebugLoc() : DebugLoc();
  uint64_t StackSize = MFI->getStackSize();

  // No need to allocate space on the stack.
  if (StackSize == 0 && !MFI->adjustsStack()) return;

  MachineModuleInfo &MMI = MF.getMMI();
  std::vector<MachineMove> &Moves = MMI.getFrameMoves();
  MachineLocation DstML, SrcML;

  // Adjust stack.
  TII.makeFrame(Oi::SP, StackSize, MBB, MBBI);

  // emit ".cfi_def_cfa_offset StackSize"
  MCSymbol *AdjustSPLabel = MMI.getContext().CreateTempSymbol();
  BuildMI(MBB, MBBI, dl,
          TII.get(TargetOpcode::PROLOG_LABEL)).addSym(AdjustSPLabel);
  DstML = MachineLocation(MachineLocation::VirtualFP);
  SrcML = MachineLocation(MachineLocation::VirtualFP, -StackSize);
  Moves.push_back(MachineMove(AdjustSPLabel, DstML, SrcML));

  MCSymbol *CSLabel = MMI.getContext().CreateTempSymbol();
  BuildMI(MBB, MBBI, dl,
          TII.get(TargetOpcode::PROLOG_LABEL)).addSym(CSLabel);
  DstML = MachineLocation(MachineLocation::VirtualFP, -8);
  SrcML = MachineLocation(Oi::S1);
  Moves.push_back(MachineMove(CSLabel, DstML, SrcML));

  DstML = MachineLocation(MachineLocation::VirtualFP, -12);
  SrcML = MachineLocation(Oi::S0);
  Moves.push_back(MachineMove(CSLabel, DstML, SrcML));

  DstML = MachineLocation(MachineLocation::VirtualFP, -4);
  SrcML = MachineLocation(Oi::RA);
  Moves.push_back(MachineMove(CSLabel, DstML, SrcML));

  if (hasFP(MF))
    BuildMI(MBB, MBBI, dl, TII.get(Oi::MoveR3216), Oi::S0)
      .addReg(Oi::SP);

}

void Oi16FrameLowering::emitEpilogue(MachineFunction &MF,
                                 MachineBasicBlock &MBB) const {
  MachineBasicBlock::iterator MBBI = MBB.getLastNonDebugInstr();
  MachineFrameInfo *MFI = MF.getFrameInfo();
  const Oi16InstrInfo &TII =
    *static_cast<const Oi16InstrInfo*>(MF.getTarget().getInstrInfo());
  DebugLoc dl = MBBI->getDebugLoc();
  uint64_t StackSize = MFI->getStackSize();

  if (!StackSize)
    return;

  if (hasFP(MF))
    BuildMI(MBB, MBBI, dl, TII.get(Oi::Move32R16), Oi::SP)
      .addReg(Oi::S0);

  // Adjust stack.
  // assumes stacksize multiple of 8
  TII.restoreFrame(Oi::SP, StackSize, MBB, MBBI);
}

bool Oi16FrameLowering::
spillCalleeSavedRegisters(MachineBasicBlock &MBB,
                          MachineBasicBlock::iterator MI,
                          const std::vector<CalleeSavedInfo> &CSI,
                          const TargetRegisterInfo *TRI) const {
  MachineFunction *MF = MBB.getParent();
  MachineBasicBlock *EntryBlock = MF->begin();

  //
  // Registers RA, S0,S1 are the callee saved registers and they
  // will be saved with the "save" instruction
  // during emitPrologue
  //
  for (unsigned i = 0, e = CSI.size(); i != e; ++i) {
    // Add the callee-saved register as live-in. Do not add if the register is
    // RA and return address is taken, because it has already been added in
    // method OiTargetLowering::LowerRETURNADDR.
    // It's killed at the spill, unless the register is RA and return address
    // is taken.
    unsigned Reg = CSI[i].getReg();
    bool IsRAAndRetAddrIsTaken = (Reg == Oi::RA)
      && MF->getFrameInfo()->isReturnAddressTaken();
    if (!IsRAAndRetAddrIsTaken)
      EntryBlock->addLiveIn(Reg);
  }

  return true;
}

bool Oi16FrameLowering::restoreCalleeSavedRegisters(MachineBasicBlock &MBB,
                                          MachineBasicBlock::iterator MI,
                                       const std::vector<CalleeSavedInfo> &CSI,
                                       const TargetRegisterInfo *TRI) const {
  //
  // Registers RA,S0,S1 are the callee saved registers and they will be restored
  // with the restore instruction during emitEpilogue.
  // We need to override this virtual function, otherwise llvm will try and
  // restore the registers on it's on from the stack.
  //

  return true;
}

// Eliminate ADJCALLSTACKDOWN, ADJCALLSTACKUP pseudo instructions
void Oi16FrameLowering::
eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                              MachineBasicBlock::iterator I) const {
  if (!hasReservedCallFrame(MF)) {
    int64_t Amount = I->getOperand(0).getImm();

    if (I->getOpcode() == Oi::ADJCALLSTACKDOWN)
      Amount = -Amount;

    const Oi16InstrInfo &TII =
      *static_cast<const Oi16InstrInfo*>(MF.getTarget().getInstrInfo());

    TII.adjustStackPtr(Oi::SP, Amount, MBB, I);
  }

  MBB.erase(I);
}

bool
Oi16FrameLowering::hasReservedCallFrame(const MachineFunction &MF) const {
  const MachineFrameInfo *MFI = MF.getFrameInfo();
  // Reserve call frame if the size of the maximum call frame fits into 15-bit
  // immediate field and there are no variable sized objects on the stack.
  return isInt<15>(MFI->getMaxCallFrameSize()) && !MFI->hasVarSizedObjects();
}

void Oi16FrameLowering::
processFunctionBeforeCalleeSavedScan(MachineFunction &MF,
                                     RegScavenger *RS) const {
  MF.getRegInfo().setPhysRegUsed(Oi::RA);
  MF.getRegInfo().setPhysRegUsed(Oi::S0);
  MF.getRegInfo().setPhysRegUsed(Oi::S1);
}

const OiFrameLowering *
llvm::createOi16FrameLowering(const OiSubtarget &ST) {
  return new Oi16FrameLowering(ST);
}
