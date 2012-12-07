//===-- OISelectionDAGInfo.h - OI SelectionDAG Info -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the OI subclass for TargetSelectionDAGInfo.
//
//===----------------------------------------------------------------------===//

#ifndef OISELECTIONDAGINFO_H
#define OISELECTIONDAGINFO_H

#include "llvm/Target/TargetSelectionDAGInfo.h"

namespace llvm {

class OITargetMachine;

class OISelectionDAGInfo : public TargetSelectionDAGInfo {
public:
  explicit OISelectionDAGInfo(const OITargetMachine &TM);
  ~OISelectionDAGInfo();
};

}

#endif
