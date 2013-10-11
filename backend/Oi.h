//===-- Oi.h - Top-level interface for Oi representation ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM Oi back-end.
//
//===----------------------------------------------------------------------===//

#ifndef TARGET_OI_H
#define TARGET_OI_H

#include "MCTargetDesc/OiMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class OiTargetMachine;
  class FunctionPass;

  FunctionPass *createOiISelDag(OiTargetMachine &TM);
  FunctionPass *createOiDelaySlotFillerPass(OiTargetMachine &TM);
  FunctionPass *createOiLongBranchPass(OiTargetMachine &TM);
  FunctionPass *createOiJITCodeEmitterPass(OiTargetMachine &TM,
                                             JITCodeEmitter &JCE);
  FunctionPass *createOiConstantIslandPass(OiTargetMachine &tm);

} // end namespace llvm;

#endif
