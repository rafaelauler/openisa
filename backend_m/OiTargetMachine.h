//===-- OiTargetMachine.h - Define TargetMachine for Oi -----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Oi specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef OITARGETMACHINE_H
#define OITARGETMACHINE_H

#include "OiFrameLowering.h"
#include "OiISelLowering.h"
#include "OiInstrInfo.h"
#include "OiJITInfo.h"
#include "OiSelectionDAGInfo.h"
#include "OiSubtarget.h"
#include "llvm/ADT/OwningPtr.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class formatted_raw_ostream;
class OiRegisterInfo;

class OiTargetMachine : public LLVMTargetMachine {
  OiSubtarget       Subtarget;
  const DataLayout    DL; // Calculates type size & alignment
  OwningPtr<const OiInstrInfo> InstrInfo;
  OwningPtr<const OiFrameLowering> FrameLowering;
  OiTargetLowering  TLInfo;
  OiSelectionDAGInfo TSInfo;
  OiJITInfo JITInfo;

public:
  OiTargetMachine(const Target &T, StringRef TT,
                    StringRef CPU, StringRef FS, const TargetOptions &Options,
                    Reloc::Model RM, CodeModel::Model CM,
                    CodeGenOpt::Level OL,
                    bool isLittle);

  virtual ~OiTargetMachine() {}

  virtual const OiInstrInfo *getInstrInfo() const
  { return InstrInfo.get(); }
  virtual const TargetFrameLowering *getFrameLowering() const
  { return FrameLowering.get(); }
  virtual const OiSubtarget *getSubtargetImpl() const
  { return &Subtarget; }
  virtual const DataLayout *getDataLayout()    const
  { return &DL;}
  virtual OiJITInfo *getJITInfo()
  { return &JITInfo; }

  virtual const OiRegisterInfo *getRegisterInfo()  const {
    return &InstrInfo->getRegisterInfo();
  }

  virtual const OiTargetLowering *getTargetLowering() const {
    return &TLInfo;
  }

  virtual const OiSelectionDAGInfo* getSelectionDAGInfo() const {
    return &TSInfo;
  }

  // Pass Pipeline Configuration
  virtual TargetPassConfig *createPassConfig(PassManagerBase &PM);
  virtual bool addCodeEmitter(PassManagerBase &PM, JITCodeEmitter &JCE);
};

/// OiebTargetMachine - Oi32/64 big endian target machine.
///
class OiebTargetMachine : public OiTargetMachine {
  virtual void anchor();
public:
  OiebTargetMachine(const Target &T, StringRef TT,
                      StringRef CPU, StringRef FS, const TargetOptions &Options,
                      Reloc::Model RM, CodeModel::Model CM,
                      CodeGenOpt::Level OL);
};

/// OielTargetMachine - Oi32/64 little endian target machine.
///
class OielTargetMachine : public OiTargetMachine {
  virtual void anchor();
public:
  OielTargetMachine(const Target &T, StringRef TT,
                      StringRef CPU, StringRef FS, const TargetOptions &Options,
                      Reloc::Model RM, CodeModel::Model CM,
                      CodeGenOpt::Level OL);
};

} // End llvm namespace

#endif
