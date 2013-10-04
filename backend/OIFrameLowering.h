//===-- OiFrameLowering.h - Define frame lowering for Oi ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//

#ifndef OI_FRAMEINFO_H
#define OI_FRAMEINFO_H

#include "Oi.h"
#include "OiSubtarget.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {
  class OiSubtarget;

class OiFrameLowering : public TargetFrameLowering {
protected:
  const OiSubtarget &STI;

public:
  explicit OiFrameLowering(const OiSubtarget &sti, unsigned Alignment)
    : TargetFrameLowering(StackGrowsDown, Alignment, 0, Alignment), STI(sti) {}

  static const OiFrameLowering *create(OiTargetMachine &TM,
                                         const OiSubtarget &ST);

  bool hasFP(const MachineFunction &MF) const;

protected:
  uint64_t estimateStackSize(const MachineFunction &MF) const;
};

/// Create OiFrameLowering objects.
const OiFrameLowering *createOi16FrameLowering(const OiSubtarget &ST);
const OiFrameLowering *createOiSEFrameLowering(const OiSubtarget &ST);

} // End llvm namespace

#endif
