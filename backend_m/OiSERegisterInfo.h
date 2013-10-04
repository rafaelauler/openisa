//===-- OiSERegisterInfo.h - Oi32/64 Register Information ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Oi32/64 implementation of the TargetRegisterInfo
// class.
//
//===----------------------------------------------------------------------===//

#ifndef OISEREGISTERINFO_H
#define OISEREGISTERINFO_H

#include "OiRegisterInfo.h"

namespace llvm {
class OiSEInstrInfo;

class OiSERegisterInfo : public OiRegisterInfo {
  const OiSEInstrInfo &TII;

public:
  OiSERegisterInfo(const OiSubtarget &Subtarget,
                     const OiSEInstrInfo &TII);

  bool requiresRegisterScavenging(const MachineFunction &MF) const;

  bool requiresFrameIndexScavenging(const MachineFunction &MF) const;

  void eliminateCallFramePseudoInstr(MachineFunction &MF,
                                     MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const;

private:
  virtual void eliminateFI(MachineBasicBlock::iterator II, unsigned OpNo,
                           int FrameIndex, uint64_t StackSize,
                           int64_t SPOffset) const;
};

} // end namespace llvm

#endif
