//===-- OiRegisterInfo.cpp - OI Register Information -== --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the OI implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "oi-reg-info"

#include "OiRegisterInfo.h"
#include "Oi.h"
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
#include "llvm/IR/Type.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetInstrInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#define GET_REGINFO_TARGET_DESC
#include "OiGenRegisterInfo.inc"

using namespace llvm;

OiRegisterInfo::OiRegisterInfo(const OiSubtarget &ST)
  : OiGenRegisterInfo(Oi::RA), Subtarget(ST) {}

unsigned OiRegisterInfo::getPICCallReg() { return Oi::T9; }


unsigned
OiRegisterInfo::getRegPressureLimit(const TargetRegisterClass *RC,
                                      MachineFunction &MF) const {
  switch (RC->getID()) {
  default:
    return 0;
  case Oi::CPURegsRegClassID:
  case Oi::CPU64RegsRegClassID:
  case Oi::DSPRegsRegClassID: {
    const TargetFrameLowering *TFI = MF.getTarget().getFrameLowering();
    return 28 - TFI->hasFP(MF);
  }
  case Oi::FGR32RegClassID:
    return 32;
  case Oi::AFGR64RegClassID:
    return 16;
  case Oi::FGR64RegClassID:
    return 32;
  }
}

//===----------------------------------------------------------------------===//
// Callee Saved Registers methods
//===----------------------------------------------------------------------===//

/// Oi Callee Saved Registers
const uint16_t* OiRegisterInfo::
getCalleeSavedRegs(const MachineFunction *MF) const {
  if (Subtarget.isSingleFloat())
    return CSR_SingleFloatOnly_SaveList;
  else if (!Subtarget.hasOi64())
    return CSR_O32_SaveList;
  else if (Subtarget.isABI_N32())
    return CSR_N32_SaveList;

  assert(Subtarget.isABI_N64());
  return CSR_N64_SaveList;
}

const uint32_t*
OiRegisterInfo::getCallPreservedMask(CallingConv::ID) const {
  if (Subtarget.isSingleFloat())
    return CSR_SingleFloatOnly_RegMask;
  else if (!Subtarget.hasOi64())
    return CSR_O32_RegMask;
  else if (Subtarget.isABI_N32())
    return CSR_N32_RegMask;

  assert(Subtarget.isABI_N64());
  return CSR_N64_RegMask;
}

BitVector OiRegisterInfo::
getReservedRegs(const MachineFunction &MF) const {
  static const uint16_t ReservedCPURegs[] = {
    Oi::ZERO, Oi::K0, Oi::K1, Oi::SP
  };

  static const uint16_t ReservedCPU64Regs[] = {
    Oi::ZERO_64, Oi::K0_64, Oi::K1_64, Oi::SP_64
  };

  BitVector Reserved(getNumRegs());
  typedef TargetRegisterClass::const_iterator RegIter;

  for (unsigned I = 0; I < array_lengthof(ReservedCPURegs); ++I)
    Reserved.set(ReservedCPURegs[I]);

  for (unsigned I = 0; I < array_lengthof(ReservedCPU64Regs); ++I)
    Reserved.set(ReservedCPU64Regs[I]);

  if (Subtarget.hasOi64()) {
    // Reserve all registers in AFGR64.
    for (RegIter Reg = Oi::AFGR64RegClass.begin(),
         EReg = Oi::AFGR64RegClass.end(); Reg != EReg; ++Reg)
      Reserved.set(*Reg);
  } else {
    // Reserve all registers in FGR64.
    for (RegIter Reg = Oi::FGR64RegClass.begin(),
         EReg = Oi::FGR64RegClass.end(); Reg != EReg; ++Reg)
      Reserved.set(*Reg);
  }
  // Reserve FP if this function should have a dedicated frame pointer register.
  if (MF.getTarget().getFrameLowering()->hasFP(MF)) {
    if (Subtarget.inOi16Mode())
      Reserved.set(Oi::S0);
    else {
      Reserved.set(Oi::FP);
      Reserved.set(Oi::FP_64);
    }
  }

  // Reserve hardware registers.
  Reserved.set(Oi::HWR29);
  Reserved.set(Oi::HWR29_64);

  // Reserve DSP control register.
  Reserved.set(Oi::DSPPos);
  Reserved.set(Oi::DSPSCount);
  Reserved.set(Oi::DSPCarry);
  Reserved.set(Oi::DSPEFI);
  Reserved.set(Oi::DSPOutFlag);

  // Reserve RA if in oi16 mode.
  if (Subtarget.inOi16Mode()) {
    Reserved.set(Oi::RA);
    Reserved.set(Oi::RA_64);
  }

  // Reserve GP if small section is used.
  if (Subtarget.useSmallSection()) {
    Reserved.set(Oi::GP);
    Reserved.set(Oi::GP_64);
  }

  return Reserved;
}

bool
OiRegisterInfo::requiresRegisterScavenging(const MachineFunction &MF) const {
  return true;
}

bool
OiRegisterInfo::trackLivenessAfterRegAlloc(const MachineFunction &MF) const {
  return true;
}

// FrameIndex represent objects inside a abstract stack.
// We must replace FrameIndex with an stack/frame pointer
// direct reference.
void OiRegisterInfo::
eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                    unsigned FIOperandNum, RegScavenger *RS) const {
  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();

  DEBUG(errs() << "\nFunction : " << MF.getName() << "\n";
        errs() << "<--------->\n" << MI);

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  uint64_t stackSize = MF.getFrameInfo()->getStackSize();
  int64_t spOffset = MF.getFrameInfo()->getObjectOffset(FrameIndex);

  DEBUG(errs() << "FrameIndex : " << FrameIndex << "\n"
               << "spOffset   : " << spOffset << "\n"
               << "stackSize  : " << stackSize << "\n");

  eliminateFI(MI, FIOperandNum, FrameIndex, stackSize, spOffset);
}

unsigned OiRegisterInfo::
getFrameRegister(const MachineFunction &MF) const {
  const TargetFrameLowering *TFI = MF.getTarget().getFrameLowering();
  bool IsN64 = Subtarget.isABI_N64();

  if (Subtarget.inOi16Mode())
    return TFI->hasFP(MF) ? Oi::S0 : Oi::SP;
  else
    return TFI->hasFP(MF) ? (IsN64 ? Oi::FP_64 : Oi::FP) :
                            (IsN64 ? Oi::SP_64 : Oi::SP);

}

unsigned OiRegisterInfo::
getEHExceptionRegister() const {
  llvm_unreachable("What is the exception register");
}

unsigned OiRegisterInfo::
getEHHandlerRegister() const {
  llvm_unreachable("What is the exception handler register");
}
