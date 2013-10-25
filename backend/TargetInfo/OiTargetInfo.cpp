//===-- OiTargetInfo.cpp - Oi Target Implementation -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "Oi.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::TheOiTarget, llvm::TheOielTarget;
Target llvm::TheOi64Target, llvm::TheOi64elTarget;

extern "C" void LLVMInitializeOiTargetInfo() {
  RegisterTarget<Triple::UnknownArch,
        /*HasJIT=*/true> X(TheOiTarget, "oi", "Oi");

  RegisterTarget<Triple::UnknownArch,
        /*HasJIT=*/true> Y(TheOielTarget, "oiel", "Oiel");

  RegisterTarget<Triple::UnknownArch,
        /*HasJIT=*/false> A(TheOi64Target, "oi64", "Oi64 [experimental]");

  RegisterTarget<Triple::UnknownArch,
        /*HasJIT=*/false> B(TheOi64elTarget,
                            "oi64el", "Oi64el [experimental]");
}
  

extern "C" void LLVMInitializeOiTarget();
extern "C" void LLVMInitializeOiTargetMC();
extern "C" void LLVMInitializeOiAsmPrinter();
extern "C" void LLVMInitializeOiAsmParser();
extern "C" void LLVMInitializeOiDisassembler();

namespace {
  class InitializeOI {
  public:
    InitializeOI() {
      LLVMInitializeOiTargetInfo();
      LLVMInitializeOiTarget();
      LLVMInitializeOiTargetMC();
      LLVMInitializeOiAsmPrinter();
      LLVMInitializeOiAsmParser();
      LLVMInitializeOiDisassembler();
    }
  };

} // End of anonymous namespace

InitializeOI X;

