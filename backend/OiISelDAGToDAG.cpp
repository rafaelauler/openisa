//===-- OiISelDAGToDAG.cpp - A Dag to Dag Inst Selector for Oi --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the OI target.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "oi-isel"
#include "OiISelDAGToDAG.h"
#include "Oi16ISelDAGToDAG.h"
#include "OiSEISelDAGToDAG.h"
#include "Oi.h"
#include "MCTargetDesc/OiBaseInfo.h"
#include "OiMachineFunction.h"
#include "OiRegisterInfo.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAGNodes.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/CFG.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
using namespace llvm;

//===----------------------------------------------------------------------===//
// Instruction Selector Implementation
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// OiDAGToDAGISel - OI specific code to select OI machine
// instructions for SelectionDAG operations.
//===----------------------------------------------------------------------===//

bool OiDAGToDAGISel::runOnMachineFunction(MachineFunction &MF) {
  bool Ret = SelectionDAGISel::runOnMachineFunction(MF);

  processFunctionAfterISel(MF);

  return Ret;
}

/// getGlobalBaseReg - Output the instructions required to put the
/// GOT address into a register.
SDNode *OiDAGToDAGISel::getGlobalBaseReg() {
  unsigned GlobalBaseReg = MF->getInfo<OiFunctionInfo>()->getGlobalBaseReg();
  return CurDAG->getRegister(GlobalBaseReg, TLI.getPointerTy()).getNode();
}

/// ComplexPattern used on OiInstrInfo
/// Used on Oi Load/Store instructions
bool OiDAGToDAGISel::selectAddrRegImm(SDValue Addr, SDValue &Base,
                                        SDValue &Offset) const {
  llvm_unreachable("Unimplemented function.");
  return false;
}

bool OiDAGToDAGISel::selectAddrDefault(SDValue Addr, SDValue &Base,
                                         SDValue &Offset) const {
  llvm_unreachable("Unimplemented function.");
  return false;
}

bool OiDAGToDAGISel::selectIntAddr(SDValue Addr, SDValue &Base,
                                     SDValue &Offset) const {
  llvm_unreachable("Unimplemented function.");
  return false;
}

bool OiDAGToDAGISel::selectAddr16(SDNode *Parent, SDValue N, SDValue &Base,
                                    SDValue &Offset, SDValue &Alias) {
  llvm_unreachable("Unimplemented function.");
  return false;
}

/// Select instructions not customized! Used for
/// expanded, promoted and normal instructions
SDNode* OiDAGToDAGISel::Select(SDNode *Node) {
  unsigned Opcode = Node->getOpcode();

  // Dump information about the Node being selected
  DEBUG(errs() << "Selecting: "; Node->dump(CurDAG); errs() << "\n");

  // If we have a custom node, we already have selected!
  if (Node->isMachineOpcode()) {
    DEBUG(errs() << "== "; Node->dump(CurDAG); errs() << "\n");
    return NULL;
  }

  // See if subclasses can handle this node.
  std::pair<bool, SDNode*> Ret = selectNode(Node);

  if (Ret.first)
    return Ret.second;

  switch(Opcode) {
  default: break;

  // Get target GOT address.
  case ISD::GLOBAL_OFFSET_TABLE:
    return getGlobalBaseReg();

#ifndef NDEBUG
  case ISD::LOAD:
  case ISD::STORE:
    assert(cast<MemSDNode>(Node)->getMemoryVT().getSizeInBits() / 8 <=
           cast<MemSDNode>(Node)->getAlignment() &&
           "Unexpected unaligned loads/stores.");
    break;
#endif
  }

  // Select the default instruction
  SDNode *ResNode = SelectCode(Node);

  DEBUG(errs() << "=> ");
  if (ResNode == NULL || ResNode == Node)
    DEBUG(Node->dump(CurDAG));
  else
    DEBUG(ResNode->dump(CurDAG));
  DEBUG(errs() << "\n");
  return ResNode;
}

bool OiDAGToDAGISel::
SelectInlineAsmMemoryOperand(const SDValue &Op, char ConstraintCode,
                             std::vector<SDValue> &OutOps) {
  assert(ConstraintCode == 'm' && "unexpected asm memory constraint");
  OutOps.push_back(Op);
  return false;
}

/// createOiISelDag - This pass converts a legalized DAG into a
/// OI-specific DAG, ready for instruction scheduling.
FunctionPass *llvm::createOiISelDag(OiTargetMachine &TM) {
  if (TM.getSubtargetImpl()->inOi16Mode())
    return llvm::createOi16ISelDag(TM);

  return llvm::createOiSEISelDag(TM);
}
