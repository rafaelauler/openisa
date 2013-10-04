//===-- Oi16RegisterInfo.h - Oi16 Register Information ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Oi16 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef OI16REGISTERINFO_H
#define OI16REGISTERINFO_H

#include "OiRegisterInfo.h"

namespace llvm {
class Oi16InstrInfo;

class Oi16RegisterInfo : public OiRegisterInfo {
  const Oi16InstrInfo &TII;
public:
  Oi16RegisterInfo(const OiSubtarget &Subtarget,
                     const Oi16InstrInfo &TII);

  bool requiresRegisterScavenging(const MachineFunction &MF) const;

  bool requiresFrameIndexScavenging(const MachineFunction &MF) const;

  bool useFPForScavengingIndex(const MachineFunction &MF) const;

  bool saveScavengerRegister(MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I,
                                     MachineBasicBlock::iterator &UseMI,
                                     const TargetRegisterClass *RC,
                                     unsigned Reg) const;

  virtual const TargetRegisterClass *intRegClass(unsigned Size) const;

private:
  virtual void eliminateFI(MachineBasicBlock::iterator II, unsigned OpNo,
                           int FrameIndex, uint64_t StackSize,
                           int64_t SPOffset) const;
};

} // end namespace llvm

#endif
