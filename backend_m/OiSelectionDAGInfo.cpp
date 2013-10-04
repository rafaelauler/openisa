//===-- OiSelectionDAGInfo.cpp - Oi SelectionDAG Info -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the OiSelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "oi-selectiondag-info"
#include "OiTargetMachine.h"
using namespace llvm;

OiSelectionDAGInfo::OiSelectionDAGInfo(const OiTargetMachine &TM)
  : TargetSelectionDAGInfo(TM) {
}

OiSelectionDAGInfo::~OiSelectionDAGInfo() {
}
