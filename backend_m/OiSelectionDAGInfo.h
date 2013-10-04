//===-- OiSelectionDAGInfo.h - Oi SelectionDAG Info ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the Oi subclass for TargetSelectionDAGInfo.
//
//===----------------------------------------------------------------------===//

#ifndef OISELECTIONDAGINFO_H
#define OISELECTIONDAGINFO_H

#include "llvm/Target/TargetSelectionDAGInfo.h"

namespace llvm {

class OiTargetMachine;

class OiSelectionDAGInfo : public TargetSelectionDAGInfo {
public:
  explicit OiSelectionDAGInfo(const OiTargetMachine &TM);
  ~OiSelectionDAGInfo();
};

}

#endif
