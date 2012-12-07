//===-- OITargetMachine.cpp - Define TargetMachine for OI -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//

#include "OITargetMachine.h"
#include "OI.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

extern "C" void LLVMInitializeOITarget() {
  // Register the target.
  RegisterTargetMachine<OIV8TargetMachine> X(TheOITarget);
  RegisterTargetMachine<OIV9TargetMachine> Y(TheOIV9Target);
}

/// OITargetMachine ctor - Create an ILP32 architecture model
///
OITargetMachine::OITargetMachine(const Target &T, StringRef TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       Reloc::Model RM, CodeModel::Model CM,
                                       CodeGenOpt::Level OL,
                                       bool is64bit)
  : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL),
    Subtarget(TT, CPU, FS, is64bit),
    DL(Subtarget.getDataLayout()),
    InstrInfo(Subtarget),
    TLInfo(*this), TSInfo(*this),
    FrameLowering(Subtarget), STTI(&TLInfo), VTTI(&TLInfo) {
}

namespace {
/// OI Code Generator Pass Configuration Options.
class OIPassConfig : public TargetPassConfig {
public:
  OIPassConfig(OITargetMachine *TM, PassManagerBase &PM)
    : TargetPassConfig(TM, PM) {}

  OITargetMachine &getOITargetMachine() const {
    return getTM<OITargetMachine>();
  }

  virtual bool addInstSelector();
  virtual bool addPreEmitPass();
};
} // namespace

TargetPassConfig *OITargetMachine::createPassConfig(PassManagerBase &PM) {
  return new OIPassConfig(this, PM);
}

bool OIPassConfig::addInstSelector() {
  addPass(createOIISelDag(getOITargetMachine()));
  return false;
}

/// addPreEmitPass - This pass may be implemented by targets that want to run
/// passes immediately before machine code is emitted.  This should return
/// true if -print-machineinstrs should print out the code after the passes.
bool OIPassConfig::addPreEmitPass(){
  addPass(createOIFPMoverPass(getOITargetMachine()));
  addPass(createOIDelaySlotFillerPass(getOITargetMachine()));
  return true;
}

void OIV8TargetMachine::anchor() { }

OIV8TargetMachine::OIV8TargetMachine(const Target &T,
                                           StringRef TT, StringRef CPU,
                                           StringRef FS,
                                           const TargetOptions &Options,
                                           Reloc::Model RM,
                                           CodeModel::Model CM,
                                           CodeGenOpt::Level OL)
  : OITargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, false) {
}

void OIV9TargetMachine::anchor() { }

OIV9TargetMachine::OIV9TargetMachine(const Target &T,
                                           StringRef TT,  StringRef CPU,
                                           StringRef FS,
                                           const TargetOptions &Options,
                                           Reloc::Model RM,
                                           CodeModel::Model CM,
                                           CodeGenOpt::Level OL)
  : OITargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, true) {
}
