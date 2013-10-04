//===-- OIMCTargetDesc.cpp - OI Target Descriptions -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides OI specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "OIMCTargetDesc.h"
#include "OIMCAsmInfo.h"
#include "llvm/MC/MCCodeGenInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "OIGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "OIGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "OIGenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createOIMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitOIMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createOIMCRegisterInfo(StringRef TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitOIMCRegisterInfo(X, SP::I7);
  return X;
}

static MCSubtargetInfo *createOIMCSubtargetInfo(StringRef TT, StringRef CPU,
                                                   StringRef FS) {
  MCSubtargetInfo *X = new MCSubtargetInfo();
  InitOIMCSubtargetInfo(X, TT, CPU, FS);
  return X;
}

static MCCodeGenInfo *createOIMCCodeGenInfo(StringRef TT, Reloc::Model RM,
                                               CodeModel::Model CM,
                                               CodeGenOpt::Level OL) {
  MCCodeGenInfo *X = new MCCodeGenInfo();
  X->InitMCCodeGenInfo(RM, CM, OL);
  return X;
}

extern "C" void LLVMInitializeOITargetMC() {
  // Register the MC asm info.
  RegisterMCAsmInfo<OIELFMCAsmInfo> X(TheOITarget);
  RegisterMCAsmInfo<OIELFMCAsmInfo> Y(TheOIV9Target);

  // Register the MC codegen info.
  TargetRegistry::RegisterMCCodeGenInfo(TheOITarget,
                                       createOIMCCodeGenInfo);
  TargetRegistry::RegisterMCCodeGenInfo(TheOIV9Target,
                                       createOIMCCodeGenInfo);

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheOITarget, createOIMCInstrInfo);

  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheOITarget, createOIMCRegisterInfo);

  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheOITarget,
                                          createOIMCSubtargetInfo);
}
