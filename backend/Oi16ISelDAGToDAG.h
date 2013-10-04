//===---- Oi16ISelDAGToDAG.h - A Dag to Dag Inst Selector for Oi ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Subclass of OiDAGToDAGISel specialized for oi16.
//
//===----------------------------------------------------------------------===//

#ifndef OI16ISELDAGTODAG_H
#define OI16ISELDAGTODAG_H

#include "OiISelDAGToDAG.h"

namespace llvm {

class Oi16DAGToDAGISel : public OiDAGToDAGISel {
public:
  explicit Oi16DAGToDAGISel(OiTargetMachine &TM) : OiDAGToDAGISel(TM) {}

private:
  std::pair<SDNode*, SDNode*> selectMULT(SDNode *N, unsigned Opc, DebugLoc DL,
                                         EVT Ty, bool HasLo, bool HasHi);

  SDValue getOi16SPAliasReg();

  virtual bool runOnMachineFunction(MachineFunction &MF);

  void getOi16SPRefReg(SDNode *Parent, SDValue &AliasReg);

  virtual bool selectAddr16(SDNode *Parent, SDValue N, SDValue &Base,
                            SDValue &Offset, SDValue &Alias);

  virtual std::pair<bool, SDNode*> selectNode(SDNode *Node);

  virtual void processFunctionAfterISel(MachineFunction &MF);

  // Insert instructions to initialize the global base register in the
  // first MBB of the function.
  void initGlobalBaseReg(MachineFunction &MF);

  void initOi16SPAliasReg(MachineFunction &MF);
};

FunctionPass *createOi16ISelDag(OiTargetMachine &TM);

}

#endif
