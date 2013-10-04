//===-- OISelectionDAGInfo.cpp - OI SelectionDAG Info ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the OISelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "oi-selectiondag-info"
#include "OITargetMachine.h"
using namespace llvm;

OISelectionDAGInfo::OISelectionDAGInfo(const OITargetMachine &TM)
  : TargetSelectionDAGInfo(TM) {
}

OISelectionDAGInfo::~OISelectionDAGInfo() {
}
