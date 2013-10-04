//===-- Oi16InstrInfo.h - Oi16 Instruction Information ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Oi16 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef OI16INSTRUCTIONINFO_H
#define OI16INSTRUCTIONINFO_H

#include "Oi16RegisterInfo.h"
#include "OiInstrInfo.h"

namespace llvm {

class Oi16InstrInfo : public OiInstrInfo {
  const Oi16RegisterInfo RI;

public:
  explicit Oi16InstrInfo(OiTargetMachine &TM);

  virtual const OiRegisterInfo &getRegisterInfo() const;

  /// isLoadFromStackSlot - If the specified machine instruction is a direct
  /// load from a stack slot, return the virtual or physical register number of
  /// the destination along with the FrameIndex of the loaded stack slot.  If
  /// not, return 0.  This predicate must return 0 if the instruction has
  /// any side effects other than loading from the stack slot.
  virtual unsigned isLoadFromStackSlot(const MachineInstr *MI,
                                       int &FrameIndex) const;

  /// isStoreToStackSlot - If the specified machine instruction is a direct
  /// store to a stack slot, return the virtual or physical register number of
  /// the source reg along with the FrameIndex of the loaded stack slot.  If
  /// not, return 0.  This predicate must return 0 if the instruction has
  /// any side effects other than storing to the stack slot.
  virtual unsigned isStoreToStackSlot(const MachineInstr *MI,
                                      int &FrameIndex) const;

  virtual void copyPhysReg(MachineBasicBlock &MBB,
                           MachineBasicBlock::iterator MI, DebugLoc DL,
                           unsigned DestReg, unsigned SrcReg,
                           bool KillSrc) const;

  virtual void storeRegToStackSlot(MachineBasicBlock &MBB,
                                   MachineBasicBlock::iterator MBBI,
                                   unsigned SrcReg, bool isKill, int FrameIndex,
                                   const TargetRegisterClass *RC,
                                   const TargetRegisterInfo *TRI) const;

  virtual void loadRegFromStackSlot(MachineBasicBlock &MBB,
                                    MachineBasicBlock::iterator MBBI,
                                    unsigned DestReg, int FrameIndex,
                                    const TargetRegisterClass *RC,
                                    const TargetRegisterInfo *TRI) const;

  virtual bool expandPostRAPseudo(MachineBasicBlock::iterator MI) const;

  virtual unsigned GetOppositeBranchOpc(unsigned Opc) const;

  // Adjust SP by FrameSize bytes. Save RA, S0, S1
  void makeFrame(unsigned SP, int64_t FrameSize, MachineBasicBlock &MBB,
                      MachineBasicBlock::iterator I) const;

  // Adjust SP by FrameSize bytes. Restore RA, S0, S1
  void restoreFrame(unsigned SP, int64_t FrameSize, MachineBasicBlock &MBB,
                      MachineBasicBlock::iterator I) const;


  /// Adjust SP by Amount bytes.
  void adjustStackPtr(unsigned SP, int64_t Amount, MachineBasicBlock &MBB,
                      MachineBasicBlock::iterator I) const;

  /// Emit a series of instructions to load an immediate. If NewImm is a
  /// non-NULL parameter, the last instruction is not emitted, but instead
  /// its immediate operand is returned in NewImm.
  unsigned loadImmediate(int64_t Imm, MachineBasicBlock &MBB,
                         MachineBasicBlock::iterator II, DebugLoc DL,
                         unsigned *NewImm) const;

private:
  virtual unsigned GetAnalyzableBrOpc(unsigned Opc) const;

  void ExpandRetRA16(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                   unsigned Opc) const;

  // Adjust SP by Amount bytes where bytes can be up to 32bit number.
  void adjustStackPtrBig(unsigned SP, int64_t Amount, MachineBasicBlock &MBB,
                         MachineBasicBlock::iterator I,
                         unsigned Reg1, unsigned Reg2) const;

  // Adjust SP by Amount bytes where bytes can be up to 32bit number.
  void adjustStackPtrBigUnrestricted(unsigned SP, int64_t Amount,
                                     MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const;


};

}

#endif
