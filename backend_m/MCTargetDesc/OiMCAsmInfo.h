//===-- OiMCAsmInfo.h - Oi Asm Info ------------------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the OiMCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef OITARGETASMINFO_H
#define OITARGETASMINFO_H

#include "llvm/MC/MCAsmInfo.h"

namespace llvm {
  class StringRef;
  class Target;

  class OiMCAsmInfo : public MCAsmInfo {
    virtual void anchor();
  public:
    explicit OiMCAsmInfo(const Target &T, StringRef TT);
  };

} // namespace llvm

#endif
