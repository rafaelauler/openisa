//===-- OITargetMachine.h - Define TargetMachine for OI ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the OI specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef OITARGETMACHINE_H
#define OITARGETMACHINE_H

#include "OIFrameLowering.h"
#include "OIISelLowering.h"
#include "OIInstrInfo.h"
#include "OISelectionDAGInfo.h"
#include "OISubtarget.h"
#include "llvm/DataLayout.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetTransformImpl.h"

namespace llvm {

class OITargetMachine : public LLVMTargetMachine {
  OISubtarget Subtarget;
  const DataLayout DL;       // Calculates type size & alignment
  OIInstrInfo InstrInfo;
  OITargetLowering TLInfo;
  OISelectionDAGInfo TSInfo;
  OIFrameLowering FrameLowering;
  ScalarTargetTransformImpl STTI;
  VectorTargetTransformImpl VTTI;
public:
  OITargetMachine(const Target &T, StringRef TT,
                     StringRef CPU, StringRef FS, const TargetOptions &Options,
                     Reloc::Model RM, CodeModel::Model CM,
                     CodeGenOpt::Level OL, bool is64bit);

  virtual const OIInstrInfo *getInstrInfo() const { return &InstrInfo; }
  virtual const TargetFrameLowering  *getFrameLowering() const {
    return &FrameLowering;
  }
  virtual const OISubtarget   *getSubtargetImpl() const{ return &Subtarget; }
  virtual const OIRegisterInfo *getRegisterInfo() const {
    return &InstrInfo.getRegisterInfo();
  }
  virtual const OITargetLowering* getTargetLowering() const {
    return &TLInfo;
  }
  virtual const OISelectionDAGInfo* getSelectionDAGInfo() const {
    return &TSInfo;
  }
  virtual const ScalarTargetTransformInfo *getScalarTargetTransformInfo()const {
    return &STTI;
  }
  virtual const VectorTargetTransformInfo *getVectorTargetTransformInfo()const {
    return &VTTI;
  }
  virtual const DataLayout       *getDataLayout() const { return &DL; }

  // Pass Pipeline Configuration
  virtual TargetPassConfig *createPassConfig(PassManagerBase &PM);
};

/// OIV8TargetMachine - OI 32-bit target machine
///
class OIV8TargetMachine : public OITargetMachine {
  virtual void anchor();
public:
  OIV8TargetMachine(const Target &T, StringRef TT,
                       StringRef CPU, StringRef FS,
                       const TargetOptions &Options,
                       Reloc::Model RM, CodeModel::Model CM,
                       CodeGenOpt::Level OL);
};

/// OIV9TargetMachine - OI 64-bit target machine
///
class OIV9TargetMachine : public OITargetMachine {
  virtual void anchor();
public:
  OIV9TargetMachine(const Target &T, StringRef TT,
                       StringRef CPU, StringRef FS,
                       const TargetOptions &Options,
                       Reloc::Model RM, CodeModel::Model CM,
                       CodeGenOpt::Level OL);
};

} // end namespace llvm

#endif
