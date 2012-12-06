//===-- OIBackendTargetInfo.cpp - CppBackend Target Implementation -------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "OITargetMachine.h"
#include "llvm/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

namespace llvm {
  Target OIBackendTarget;
}

static unsigned OIBackend_TripleMatchQuality(const std::string &TT) {
  // This class always works, but shouldn't be the default in most cases.
  return 1;
}

extern "C" void LLVMInitializeOIBackendTargetInfo() { 
  TargetRegistry::RegisterTarget(OIBackendTarget, "cpp",    
                                  "OpenISA backend",
                                  &OIBackend_TripleMatchQuality);
}

extern "C" void LLVMInitializeOIBackendTargetMC() {}
