//===-- OiSEISelLowering.h - OiSE DAG Lowering Interface ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Subclass of OiTargetLowering specialized for oi32/64.
//
//===----------------------------------------------------------------------===//

#ifndef OiSEISELLOWERING_H
#define OiSEISELLOWERING_H

#include "OiISelLowering.h"
#include "OiRegisterInfo.h"

namespace llvm {
  class OiSETargetLowering : public OiTargetLowering  {
  public:
    explicit OiSETargetLowering(OiTargetMachine &TM);

    virtual bool allowsUnalignedMemoryAccesses(EVT VT, bool *Fast) const;

    virtual SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const;

    virtual SDValue PerformDAGCombine(SDNode *N, DAGCombinerInfo &DCI) const;

    virtual MachineBasicBlock *
    EmitInstrWithCustomInserter(MachineInstr *MI, MachineBasicBlock *MBB) const;

    virtual bool isShuffleMaskLegal(const SmallVectorImpl<int> &Mask,
                                    EVT VT) const {
      return false;
    }

    virtual const TargetRegisterClass *getRepRegClassFor(MVT VT) const {
      if (VT == MVT::Untyped)
        return Subtarget->hasDSP() ? &Oi::ACRegsDSPRegClass :
                                     &Oi::ACRegsRegClass;

      return TargetLowering::getRepRegClassFor(VT);
    }

  private:
    virtual bool
    isEligibleForTailCallOptimization(const OiCC &OiCCInfo,
                                      unsigned NextStackOffset,
                                      const OiFunctionInfo& FI) const;

    virtual void
    getOpndList(SmallVectorImpl<SDValue> &Ops,
                std::deque< std::pair<unsigned, SDValue> > &RegsToPass,
                bool IsPICCall, bool GlobalOrExternal, bool InternalLinkage,
                CallLoweringInfo &CLI, SDValue Callee, SDValue Chain,
                unsigned nargs) const;

    SDValue lowerMulDiv(SDValue Op, unsigned NewOpc, bool HasLo, bool HasHi,
                        SelectionDAG &DAG) const;

    SDValue lowerINTRINSIC_WO_CHAIN(SDValue Op, SelectionDAG &DAG) const;
    SDValue lowerINTRINSIC_W_CHAIN(SDValue Op, SelectionDAG &DAG) const;

    MachineBasicBlock *emitBPOSGE32(MachineInstr *MI,
                                    MachineBasicBlock *BB) const;
  };
}

#endif // OiSEISELLOWERING_H
