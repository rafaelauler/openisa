//===---- OiOs16.h for Oi Option -Os16                         --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an optimization phase for the OI target.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/OiMCTargetDesc.h"
#include "OiTargetMachine.h"
#include "llvm/Pass.h"
#include "llvm/Target/TargetMachine.h"



#ifndef OIOS16_H
#define OIOS16_H

using namespace llvm;

namespace llvm {

class OiOs16 : public ModulePass {

public:
  static char ID;

  OiOs16() : ModulePass(ID) {

  }

  virtual const char *getPassName() const {
    return "OI Os16 Optimization";
  }

  virtual bool runOnModule(Module &M);

};

ModulePass *createOiOs16(OiTargetMachine &TM);

}

#endif
