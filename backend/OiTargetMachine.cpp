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
#include "OiModuleISelDAGToDAG.h"
#include "OiOs16.h"
#include "OiSEFrameLowering.h"
#include "OiSEInstrInfo.h"
#include "OiSEISelLowering.h"
#include "OiSEISelDAGToDAG.h"
#include "Oi16FrameLowering.h"
#include "Oi16InstrInfo.h"
#include "Oi16ISelDAGToDAG.h"
#include "Oi16ISelLowering.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/PassManager.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;



extern "C" void LLVMInitializeOiTarget() {
  // Register the target.
  RegisterTargetMachine<OiebTargetMachine> X(TheOiTarget);
  //RegisterTargetMachine<OielTargetMachine> Y(TheOielTarget);
  //RegisterTargetMachine<OiebTargetMachine> A(TheOi64Target);
  //RegisterTargetMachine<OielTargetMachine> B(TheOi64elTarget);
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
    Subtarget(TT, CPU, FS, isLittle, RM, this),
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
    TLInfo(OiTargetLowering::create(*this)),
    TSInfo(*this), JITInfo() {
}


void OiTargetMachine::setHelperClassesOi16() {
  InstrInfoSE.swap(InstrInfo);
  FrameLoweringSE.swap(FrameLowering);
  TLInfoSE.swap(TLInfo);
  if (!InstrInfo16) {
    InstrInfo.reset(OiInstrInfo::create(*this));
    FrameLowering.reset(OiFrameLowering::create(*this, Subtarget));
    TLInfo.reset(OiTargetLowering::create(*this));
  } else {
    InstrInfo16.swap(InstrInfo);
    FrameLowering16.swap(FrameLowering);
    TLInfo16.swap(TLInfo);
  }
  assert(TLInfo && "null target lowering 16");
  assert(InstrInfo && "null instr info 16");
  assert(FrameLowering && "null frame lowering 16");
}

void OiTargetMachine::setHelperClassesOiSE() {
  InstrInfo16.swap(InstrInfo);
  FrameLowering16.swap(FrameLowering);
  TLInfo16.swap(TLInfo);
  if (!InstrInfoSE) {
    InstrInfo.reset(OiInstrInfo::create(*this));
    FrameLowering.reset(OiFrameLowering::create(*this, Subtarget));
    TLInfo.reset(OiTargetLowering::create(*this));
  } else {
    InstrInfoSE.swap(InstrInfo);
    FrameLoweringSE.swap(FrameLowering);
    TLInfoSE.swap(TLInfo);
  }
  assert(TLInfo && "null target lowering in SE");
  assert(InstrInfo && "null instr info SE");
  assert(FrameLowering && "null frame lowering SE");
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

  virtual void addIRPasses();
  virtual bool addInstSelector();
  virtual bool addPreEmitPass();
};
} // namespace

TargetPassConfig *OiTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new OiPassConfig(this, PM);
}

void OiPassConfig::addIRPasses() {
  TargetPassConfig::addIRPasses();
  if (getOiSubtarget().os16())
    addPass(createOiOs16(getOiTargetMachine()));
}
// Install an instruction selector pass using
// the ISelDag to gen Oi code.
bool OiPassConfig::addInstSelector() {
  if (getOiSubtarget().allowMixed16_32()) {
    addPass(createOiModuleISelDag(getOiTargetMachine()));
    addPass(createOi16ISelDag(getOiTargetMachine()));
    addPass(createOiSEISelDag(getOiTargetMachine()));
  } else {
    addPass(createOiISelDag(getOiTargetMachine()));
  }
  return false;
}

void OiTargetMachine::addAnalysisPasses(PassManagerBase &PM) {
  if (Subtarget.allowMixed16_32()) {
    DEBUG(errs() << "No ");
    //FIXME: The Basic Target Transform Info
    // pass needs to become a function pass instead of
    // being an immutable pass and then this method as it exists now
    // would be unnecessary.
    PM.add(createNoTargetTransformInfoPass());
  } else
    LLVMTargetMachine::addAnalysisPasses(PM);
  DEBUG(errs() << "Target Transform Info Pass Added\n");
}

// Implemented by targets that want to run passes immediately before
// machine code is emitted. return true if -print-machineinstrs should
// print out the code after the passes.
bool OiPassConfig::addPreEmitPass() {
  OiTargetMachine &TM = getOiTargetMachine();
  const OiSubtarget &Subtarget = TM.getSubtarget<OiSubtarget>();
  addPass(createOiDelaySlotFillerPass(TM));

  if (Subtarget.hasStandardEncoding() ||
      Subtarget.allowMixed16_32())
    addPass(createOiLongBranchPass(TM));
  if (Subtarget.inOi16Mode() ||
      Subtarget.allowMixed16_32())
    addPass(createOiConstantIslandPass(TM));

  return true;
}

bool OiTargetMachine::addCodeEmitter(PassManagerBase &PM,
                                       JITCodeEmitter &JCE) {
  // Machine code emitter pass for Oi.
  PM.add(createOiJITCodeEmitterPass(*this, JCE));
  return false;
}
