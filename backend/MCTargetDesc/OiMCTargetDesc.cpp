//===-- OiMCTargetDesc.cpp - Oi Target Descriptions -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Oi specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/OiELFStreamer.h"
#include "OiMCTargetDesc.h"
#include "InstPrinter/OiInstPrinter.h"
#include "OiMCAsmInfo.h"
#include "llvm/MC/MCCodeGenInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MachineLocation.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "OiGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "OiGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "OiGenRegisterInfo.inc"

using namespace llvm;

static std::string ParseOiTriple(StringRef TT, StringRef CPU) {
  std::string OiArchFeature;
  size_t DashPosition = 0;
  StringRef TheTriple;

  // Let's see if there is a dash, like oi-unknown-linux.
  DashPosition = TT.find('-');

  if (DashPosition == StringRef::npos) {
    // No dash, we check the string size.
    TheTriple = TT.substr(0);
  } else {
    // We are only interested in substring before dash.
    TheTriple = TT.substr(0,DashPosition);
  }

  if (TheTriple == "oi" || TheTriple == "oiel"
      || TheTriple == "mips" || TheTriple == "mipsel") {
    if (CPU.empty() || CPU == "oi32") {
      OiArchFeature = "+oi32";
    } else if (CPU == "oi32r2") {
      OiArchFeature = "+oi32r2";
    }
  } else {
      if (CPU.empty() || CPU == "oi64") {
        OiArchFeature = "+oi64";
      } else if (CPU == "oi64r2") {
        OiArchFeature = "+oi64r2";
      }
  }
  return OiArchFeature;
}

static MCInstrInfo *createOiMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitOiMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createOiMCRegisterInfo(StringRef TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitOiMCRegisterInfo(X, Oi::RA);
  return X;
}

static MCSubtargetInfo *createOiMCSubtargetInfo(StringRef TT, StringRef CPU,
                                                  StringRef FS) {
  std::string ArchFS = ParseOiTriple(TT,CPU);
  if (!FS.empty()) {
    if (!ArchFS.empty())
      ArchFS = ArchFS + "," + FS.str();
    else
      ArchFS = FS;
  }
  MCSubtargetInfo *X = new MCSubtargetInfo();
  InitOiMCSubtargetInfo(X, TT, CPU, ArchFS);
  return X;
}

static MCAsmInfo *createOiMCAsmInfo(const Target &T, StringRef TT) {
  MCAsmInfo *MAI = new OiMCAsmInfo(T, TT);

  MachineLocation Dst(MachineLocation::VirtualFP);
  MachineLocation Src(Oi::SP, 0);
  MAI->addInitialFrameState(0, Dst, Src);

  return MAI;
}

static MCCodeGenInfo *createOiMCCodeGenInfo(StringRef TT, Reloc::Model RM,
                                              CodeModel::Model CM,
                                              CodeGenOpt::Level OL) {
  MCCodeGenInfo *X = new MCCodeGenInfo();
  if (CM == CodeModel::JITDefault)
    RM = Reloc::Static;
  else if (RM == Reloc::Default)
    RM = Reloc::PIC_;
  X->InitMCCodeGenInfo(RM, CM, OL);
  return X;
}

static MCInstPrinter *createOiMCInstPrinter(const Target &T,
                                              unsigned SyntaxVariant,
                                              const MCAsmInfo &MAI,
                                              const MCInstrInfo &MII,
                                              const MCRegisterInfo &MRI,
                                              const MCSubtargetInfo &STI) {
  return new OiInstPrinter(MAI, MII, MRI);
}

static MCStreamer *createMCStreamer(const Target &T, StringRef TT,
                                    MCContext &Ctx, MCAsmBackend &MAB,
                                    raw_ostream &_OS,
                                    MCCodeEmitter *_Emitter,
                                    bool RelaxAll,
                                    bool NoExecStack) {
  Triple TheTriple(TT);

  return createOiELFStreamer(Ctx, MAB, _OS, _Emitter, RelaxAll, NoExecStack);
}

extern "C" void LLVMInitializeOiTargetMC() {
  // Register the MC asm info.
  RegisterMCAsmInfoFn X(TheOiTarget, createOiMCAsmInfo);
  RegisterMCAsmInfoFn Y(TheOielTarget, createOiMCAsmInfo);
  RegisterMCAsmInfoFn A(TheOi64Target, createOiMCAsmInfo);
  RegisterMCAsmInfoFn B(TheOi64elTarget, createOiMCAsmInfo);

  // Register the MC codegen info.
  TargetRegistry::RegisterMCCodeGenInfo(TheOiTarget,
                                        createOiMCCodeGenInfo);
  TargetRegistry::RegisterMCCodeGenInfo(TheOielTarget,
                                        createOiMCCodeGenInfo);
  TargetRegistry::RegisterMCCodeGenInfo(TheOi64Target,
                                        createOiMCCodeGenInfo);
  TargetRegistry::RegisterMCCodeGenInfo(TheOi64elTarget,
                                        createOiMCCodeGenInfo);

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheOiTarget, createOiMCInstrInfo);
  TargetRegistry::RegisterMCInstrInfo(TheOielTarget, createOiMCInstrInfo);
  TargetRegistry::RegisterMCInstrInfo(TheOi64Target, createOiMCInstrInfo);
  TargetRegistry::RegisterMCInstrInfo(TheOi64elTarget,
                                      createOiMCInstrInfo);

  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheOiTarget, createOiMCRegisterInfo);
  TargetRegistry::RegisterMCRegInfo(TheOielTarget, createOiMCRegisterInfo);
  TargetRegistry::RegisterMCRegInfo(TheOi64Target, createOiMCRegisterInfo);
  TargetRegistry::RegisterMCRegInfo(TheOi64elTarget,
                                    createOiMCRegisterInfo);

  // Register the MC Code Emitter
  TargetRegistry::RegisterMCCodeEmitter(TheOiTarget,
                                        createOiMCCodeEmitterEB);
  TargetRegistry::RegisterMCCodeEmitter(TheOielTarget,
                                        createOiMCCodeEmitterEL);
  TargetRegistry::RegisterMCCodeEmitter(TheOi64Target,
                                        createOiMCCodeEmitterEB);
  TargetRegistry::RegisterMCCodeEmitter(TheOi64elTarget,
                                        createOiMCCodeEmitterEL);

  // Register the object streamer.
  TargetRegistry::RegisterMCObjectStreamer(TheOiTarget, createMCStreamer);
  TargetRegistry::RegisterMCObjectStreamer(TheOielTarget, createMCStreamer);
  TargetRegistry::RegisterMCObjectStreamer(TheOi64Target, createMCStreamer);
  TargetRegistry::RegisterMCObjectStreamer(TheOi64elTarget,
                                           createMCStreamer);

  // Register the asm backend.
  TargetRegistry::RegisterMCAsmBackend(TheOiTarget,
                                       createOiAsmBackendEB32);
  TargetRegistry::RegisterMCAsmBackend(TheOielTarget,
                                       createOiAsmBackendEL32);
  TargetRegistry::RegisterMCAsmBackend(TheOi64Target,
                                       createOiAsmBackendEB64);
  TargetRegistry::RegisterMCAsmBackend(TheOi64elTarget,
                                       createOiAsmBackendEL64);

  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheOiTarget,
                                          createOiMCSubtargetInfo);
  TargetRegistry::RegisterMCSubtargetInfo(TheOielTarget,
                                          createOiMCSubtargetInfo);
  TargetRegistry::RegisterMCSubtargetInfo(TheOi64Target,
                                          createOiMCSubtargetInfo);
  TargetRegistry::RegisterMCSubtargetInfo(TheOi64elTarget,
                                          createOiMCSubtargetInfo);

  // Register the MCInstPrinter.
  TargetRegistry::RegisterMCInstPrinter(TheOiTarget,
                                        createOiMCInstPrinter);
  TargetRegistry::RegisterMCInstPrinter(TheOielTarget,
                                        createOiMCInstPrinter);
  TargetRegistry::RegisterMCInstPrinter(TheOi64Target,
                                        createOiMCInstPrinter);
  TargetRegistry::RegisterMCInstPrinter(TheOi64elTarget,
                                        createOiMCInstPrinter);
}
