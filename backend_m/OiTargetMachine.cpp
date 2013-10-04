//===-- OiTargetMachine.cpp - Define TargetMachine for Oi -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Implements the info about Oi target spec.
//
//===----------------------------------------------------------------------===//

#include "OiTargetMachine.h"
#include "Oi.h"
#include "OiFrameLowering.h"
#include "OiInstrInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

extern "C" void LLVMInitializeOiTarget() {
  // Register the target.
  RegisterTargetMachine<OiebTargetMachine> X(TheOiTarget);
  RegisterTargetMachine<OielTargetMachine> Y(TheOielTarget);
  RegisterTargetMachine<OiebTargetMachine> A(TheOi64Target);
  RegisterTargetMachine<OielTargetMachine> B(TheOi64elTarget);
}

// DataLayout --> Big-endian, 32-bit pointer/ABI/alignment
// The stack is always 8 byte aligned
// On function prologue, the stack is created by decrementing
// its pointer. Once decremented, all references are done with positive
// offset from the stack/frame pointer, using StackGrowsUp enables
// an easier handling.
// Using CodeModel::Large enables different CALL behavior.
OiTargetMachine::
OiTargetMachine(const Target &T, StringRef TT,
                  StringRef CPU, StringRef FS, const TargetOptions &Options,
                  Reloc::Model RM, CodeModel::Model CM,
                  CodeGenOpt::Level OL,
                  bool isLittle)
  : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL),
    Subtarget(TT, CPU, FS, isLittle, RM),
    DL(isLittle ?
               (Subtarget.isABI_N64() ?
                "e-p:64:64:64-i8:8:32-i16:16:32-i64:64:64-f128:128:128-"
                "n32:64-S128" :
                "e-p:32:32:32-i8:8:32-i16:16:32-i64:64:64-n32-S64") :
               (Subtarget.isABI_N64() ?
                "E-p:64:64:64-i8:8:32-i16:16:32-i64:64:64-f128:128:128-"
                "n32:64-S128" :
                "E-p:32:32:32-i8:8:32-i16:16:32-i64:64:64-n32-S64")),
    InstrInfo(OiInstrInfo::create(*this)),
    FrameLowering(OiFrameLowering::create(*this, Subtarget)),
    TLInfo(*this), TSInfo(*this), JITInfo() {
}

void OiebTargetMachine::anchor() { }

OiebTargetMachine::
OiebTargetMachine(const Target &T, StringRef TT,
                    StringRef CPU, StringRef FS, const TargetOptions &Options,
                    Reloc::Model RM, CodeModel::Model CM,
                    CodeGenOpt::Level OL)
  : OiTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, false) {}

void OielTargetMachine::anchor() { }

OielTargetMachine::
OielTargetMachine(const Target &T, StringRef TT,
                    StringRef CPU, StringRef FS, const TargetOptions &Options,
                    Reloc::Model RM, CodeModel::Model CM,
                    CodeGenOpt::Level OL)
  : OiTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, true) {}

namespace {
/// Oi Code Generator Pass Configuration Options.
class OiPassConfig : public TargetPassConfig {
public:
  OiPassConfig(OiTargetMachine *TM, PassManagerBase &PM)
    : TargetPassConfig(TM, PM) {}

  OiTargetMachine &getOiTargetMachine() const {
    return getTM<OiTargetMachine>();
  }

  const OiSubtarget &getOiSubtarget() const {
    return *getOiTargetMachine().getSubtargetImpl();
  }

  virtual bool addInstSelector();
  virtual bool addPreEmitPass();
};
} // namespace

TargetPassConfig *OiTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new OiPassConfig(this, PM);
}

// Install an instruction selector pass using
// the ISelDag to gen Oi code.
bool OiPassConfig::addInstSelector() {
  addPass(createOiISelDag(getOiTargetMachine()));
  return false;
}

// Implemented by targets that want to run passes immediately before
// machine code is emitted. return true if -print-machineinstrs should
// print out the code after the passes.
bool OiPassConfig::addPreEmitPass() {
  OiTargetMachine &TM = getOiTargetMachine();
  addPass(createOiDelaySlotFillerPass(TM));

  // NOTE: long branch has not been implemented for oi16.
  if (TM.getSubtarget<OiSubtarget>().hasStandardEncoding())
    addPass(createOiLongBranchPass(TM));

  return true;
}

bool OiTargetMachine::addCodeEmitter(PassManagerBase &PM,
                                       JITCodeEmitter &JCE) {
  // Machine code emitter pass for Oi.
  PM.add(createOiJITCodeEmitterPass(*this, JCE));
  return false;
}
