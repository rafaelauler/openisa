//===-- OiSEISelDAGToDAG.h - A Dag to Dag Inst Selector for OiSE -----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Subclass of OiDAGToDAGISel specialized for oi32/64.
//
//===----------------------------------------------------------------------===//

#ifndef OISEISELDAGTODAG_H
#define OISEISELDAGTODAG_H

#include "OiISelDAGToDAG.h"

namespace llvm {

class OiSEDAGToDAGISel : public OiDAGToDAGISel {

public:
  explicit OiSEDAGToDAGISel(OiTargetMachine &TM) : OiDAGToDAGISel(TM) {}

private:

  virtual bool runOnMachineFunction(MachineFunction &MF);

  void addDSPCtrlRegOperands(bool IsDef, MachineInstr &MI,
                             MachineFunction &MF);

  bool replaceUsesWithZeroReg(MachineRegisterInfo *MRI, const MachineInstr&);

  std::pair<SDNode*, SDNode*> selectMULT(SDNode *N, unsigned Opc, DebugLoc dl,
                                         EVT Ty, bool HasLo, bool HasHi);

  SDNode *selectAddESubE(unsigned MOp, SDValue InFlag, SDValue CmpLHS,
                         DebugLoc DL, SDNode *Node) const;

  virtual bool selectAddrRegImm(SDValue Addr, SDValue &Base,
                                SDValue &Offset) const;

  virtual bool selectAddrDefault(SDValue Addr, SDValue &Base,
                                 SDValue &Offset) const;

  virtual bool selectIntAddr(SDValue Addr, SDValue &Base,
                             SDValue &Offset) const;

  virtual std::pair<bool, SDNode*> selectNode(SDNode *Node);

  virtual void processFunctionAfterISel(MachineFunction &MF);

  // Insert instructions to initialize the global base register in the
  // first MBB of the function.
  void initGlobalBaseReg(MachineFunction &MF);
};

FunctionPass *createOiSEISelDag(OiTargetMachine &TM);

}

#endif
