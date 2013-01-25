//===-- OISubtarget.cpp - OI Subtarget Information ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the OI specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "OISubtarget.h"
#include "OI.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "OIGenSubtargetInfo.inc"

using namespace llvm;

void OISubtarget::anchor() { }

OISubtarget::OISubtarget(const std::string &TT, const std::string &CPU,
                               const std::string &FS,  bool is64Bit) :
  OIGenSubtargetInfo(TT, CPU, FS),
  IsV9(false),
  V8DeprecatedInsts(false),
  IsVIS(false),
  Is64Bit(is64Bit) {
}
