//===-- Oi16ISelLowering.h - Oi16 DAG Lowering Interface ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Subclass of OiTargetLowering specialized for oi16.
//
//===----------------------------------------------------------------------===//

#ifndef Oi16ISELLOWERING_H
#define Oi16ISELLOWERING_H

#include "OiISelLowering.h"

namespace llvm {
  class Oi16TargetLowering : public OiTargetLowering  {
  public:
    explicit Oi16TargetLowering(OiTargetMachine &TM);

    virtual bool allowsUnalignedMemoryAccesses(EVT VT, bool *Fast) const;

    virtual MachineBasicBlock *
    EmitInstrWithCustomInserter(MachineInstr *MI, MachineBasicBlock *MBB) const;

  private:
    virtual bool
    isEligibleForTailCallOptimization(const OiCC &OiCCInfo,
                                      unsigned NextStackOffset,
                                      const OiFunctionInfo& FI) const;

    void setOi16LibcallName(RTLIB::Libcall, const char *Name);

    void setOi16HardFloatLibCalls();

    unsigned int
      getOi16HelperFunctionStubNumber(ArgListTy &Args) const;

    const char *getOi16HelperFunction
      (Type* RetTy, ArgListTy &Args, bool &needHelper) const;

    virtual void
    getOpndList(SmallVectorImpl<SDValue> &Ops,
                std::deque< std::pair<unsigned, SDValue> > &RegsToPass,
                bool IsPICCall, bool GlobalOrExternal, bool InternalLinkage,
                CallLoweringInfo &CLI, SDValue Callee, SDValue Chain) const;

    MachineBasicBlock *emitSel16(unsigned Opc, MachineInstr *MI,
                                 MachineBasicBlock *BB) const;

    MachineBasicBlock *emitSeliT16(unsigned Opc1, unsigned Opc2,
                                   MachineInstr *MI,
                                   MachineBasicBlock *BB) const;

    MachineBasicBlock *emitSelT16(unsigned Opc1, unsigned Opc2,
                                  MachineInstr *MI,
                                  MachineBasicBlock *BB) const;

    MachineBasicBlock *emitFEXT_T8I816_ins(unsigned BtOpc, unsigned CmpOpc,
                                           MachineInstr *MI,
                                           MachineBasicBlock *BB) const;

    MachineBasicBlock *emitFEXT_T8I8I16_ins(
      unsigned BtOpc, unsigned CmpiOpc, unsigned CmpiXOpc,
      MachineInstr *MI,  MachineBasicBlock *BB) const;

    MachineBasicBlock *emitFEXT_CCRX16_ins(
      unsigned SltOpc,
      MachineInstr *MI,  MachineBasicBlock *BB) const;

    MachineBasicBlock *emitFEXT_CCRXI16_ins(
      unsigned SltiOpc, unsigned SltiXOpc,
      MachineInstr *MI,  MachineBasicBlock *BB )const;
  };
}

#endif // Oi16ISELLOWERING_H
