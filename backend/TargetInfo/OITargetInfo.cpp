//===-- OITargetInfo.cpp - OI Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "OI.h"
#include "llvm/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::TheOITarget;
Target llvm::TheOIV9Target;

static unsigned OIBackend_TripleMatchQuality(const std::string &TT) {
  // This class always works, but shouldn't be the default in most cases.
  return 1;
}

extern "C" void LLVMInitializeOITargetInfo() { 
  // RegisterTarget<Triple::oi> X(TheOITarget, "oi", "OI");
  // RegisterTarget<Triple::oiv9> Y(TheOIV9Target, "oiv9", "OI V9");
  TargetRegistry::RegisterTarget(TheOITarget, "oi", "OpenISA backend",
                                 &OIBackend_TripleMatchQuality);
  TargetRegistry::RegisterTarget(TheOIV9Target, "oiv9", "OpenISA v9 backend",
                                 &OIBackend_TripleMatchQuality);
}

extern "C" void LLVMInitializeOITarget();
extern "C" void LLVMInitializeOIAsmPrinter();
extern "C" void LLVMInitializeOITargetMC();

namespace {
  class InitializeOI {
  public:
    InitializeOI() {
      LLVMInitializeOITargetInfo();
      LLVMInitializeOITarget();
      LLVMInitializeOIAsmPrinter();
      LLVMInitializeOITargetMC();
    }
  };

} // End of anonymous namespace

InitializeOI X;
