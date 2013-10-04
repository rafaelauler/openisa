//===---- OiModuleISelDAGToDAG.h -  Change Subtarget             --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines a pass used to change the subtarget for the
// Oi Instruction selector.
//
//===----------------------------------------------------------------------===//

#ifndef OIMODULEISELDAGTODAG_H
#define OIMODULEISELDAGTODAG_H

#include "Oi.h"
#include "OiSubtarget.h"
#include "OiTargetMachine.h"
#include "llvm/CodeGen/SelectionDAGISel.h"


//===----------------------------------------------------------------------===//
// Instruction Selector Implementation
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// OiModuleDAGToDAGISel - OI specific code to select OI machine
// instructions for SelectionDAG operations.
//===----------------------------------------------------------------------===//
namespace llvm {

class OiModuleDAGToDAGISel : public MachineFunctionPass {
public:

  static char ID;

  explicit OiModuleDAGToDAGISel(OiTargetMachine &TM_)
    : MachineFunctionPass(ID),
      TM(TM_), Subtarget(TM.getSubtarget<OiSubtarget>()) {}

  // Pass Name
  virtual const char *getPassName() const {
    return "OI DAG->DAG Pattern Instruction Selection";
  }

  virtual bool runOnMachineFunction(MachineFunction &MF);

  virtual SDNode *Select(SDNode *N) {
    llvm_unreachable("unexpected");
  }

protected:
  /// Keep a pointer to the OiSubtarget around so that we can make the right
  /// decision when generating code for different targets.
  const TargetMachine &TM;
  const OiSubtarget &Subtarget;
};

/// createOiISelDag - This pass converts a legalized DAG into a
/// OI-specific DAG, ready for instruction scheduling.
FunctionPass *createOiModuleISelDag(OiTargetMachine &TM);
}

#endif
