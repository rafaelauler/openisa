//===----------------------------------------------------------------------===//
// Instruction Selector Subtarget Control
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// This file defines a pass used to change the subtarget for the
// Oi Instruction selector.
//
//===----------------------------------------------------------------------===//

#include "OiISelDAGToDAG.h"
#include "OiModuleISelDAGToDAG.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {

bool OiModuleDAGToDAGISel::runOnMachineFunction(MachineFunction &MF) {
  DEBUG(errs() << "In OiModuleDAGToDAGISel::runMachineFunction\n");
  const_cast<OiSubtarget&>(Subtarget).resetSubtarget(&MF);
  return false;
}

char OiModuleDAGToDAGISel::ID = 0;

}


llvm::FunctionPass *llvm::createOiModuleISelDag(OiTargetMachine &TM) {
  return new OiModuleDAGToDAGISel(TM);
}


