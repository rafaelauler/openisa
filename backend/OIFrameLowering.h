//===-- OIFrameLowering.h - Define frame lowering for OI --*- C++ -*-===//
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

#include "OI.h"
#include "OISubtarget.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {
  class OISubtarget;

class OIFrameLowering : public TargetFrameLowering {
public:
  explicit OIFrameLowering(const OISubtarget &/*sti*/)
    : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, 8, 0) {
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF) const;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const;

  bool hasFP(const MachineFunction &MF) const { return false; }
};

} // End llvm namespace

#endif
