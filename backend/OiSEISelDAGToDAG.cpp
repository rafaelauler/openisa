//===-- OiSEISelDAGToDAG.cpp - A Dag to Dag Inst Selector for OiSE ----===//
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

#define DEBUG_TYPE "oi-isel"
#include "OiSEISelDAGToDAG.h"
#include "Oi.h"
#include "MCTargetDesc/OiBaseInfo.h"
#include "OiAnalyzeImmediate.h"
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

bool OiSEDAGToDAGISel::runOnMachineFunction(MachineFunction &MF) {
  if (Subtarget.inOi16Mode())
    return false;
  return OiDAGToDAGISel::runOnMachineFunction(MF);
}

void OiSEDAGToDAGISel::addDSPCtrlRegOperands(bool IsDef, MachineInstr &MI,
                                               MachineFunction &MF) {
  MachineInstrBuilder MIB(MF, &MI);
  unsigned Mask = MI.getOperand(1).getImm();
  unsigned Flag = IsDef ? RegState::ImplicitDefine : RegState::Implicit;

  if (Mask & 1)
    MIB.addReg(Oi::DSPPos, Flag);

  if (Mask & 2)
    MIB.addReg(Oi::DSPSCount, Flag);

  if (Mask & 4)
    MIB.addReg(Oi::DSPCarry, Flag);

  if (Mask & 8)
    MIB.addReg(Oi::DSPOutFlag, Flag);

  if (Mask & 16)
    MIB.addReg(Oi::DSPCCond, Flag);

  if (Mask & 32)
    MIB.addReg(Oi::DSPEFI, Flag);
}

bool OiSEDAGToDAGISel::replaceUsesWithZeroReg(MachineRegisterInfo *MRI,
                                                const MachineInstr& MI) {
  unsigned DstReg = 0, ZeroReg = 0;

  // Check if MI is "addiu $dst, $zero, 0" or "daddiu $dst, $zero, 0".
  if ((MI.getOpcode() == Oi::ADDiu) &&
      (MI.getOperand(1).getReg() == Oi::ZERO) &&
      (MI.getOperand(2).getImm() == 0)) {
    DstReg = MI.getOperand(0).getReg();
    ZeroReg = Oi::ZERO;
  } else if ((MI.getOpcode() == Oi::DADDiu) &&
             (MI.getOperand(1).getReg() == Oi::ZERO_64) &&
             (MI.getOperand(2).getImm() == 0)) {
    DstReg = MI.getOperand(0).getReg();
    ZeroReg = Oi::ZERO_64;
  }

  if (!DstReg)
    return false;

  // Replace uses with ZeroReg.
  for (MachineRegisterInfo::use_iterator U = MRI->use_begin(DstReg),
       E = MRI->use_end(); U != E;) {
    MachineOperand &MO = U.getOperand();
    unsigned OpNo = U.getOperandNo();
    MachineInstr *MI = MO.getParent();
    ++U;

    // Do not replace if it is a phi's operand or is tied to def operand.
    if (MI->isPHI() || MI->isRegTiedToDefOperand(OpNo) || MI->isPseudo())
      continue;

    MO.setReg(ZeroReg);
  }

  return true;
}

void OiSEDAGToDAGISel::initGlobalBaseReg(MachineFunction &MF) {
  OiFunctionInfo *OiFI = MF.getInfo<OiFunctionInfo>();

  if (!OiFI->globalBaseRegSet())
    return;

  MachineBasicBlock &MBB = MF.front();
  MachineBasicBlock::iterator I = MBB.begin();
  MachineRegisterInfo &RegInfo = MF.getRegInfo();
  const TargetInstrInfo &TII = *MF.getTarget().getInstrInfo();
  DebugLoc DL = I != MBB.end() ? I->getDebugLoc() : DebugLoc();
  unsigned V0, V1, GlobalBaseReg = OiFI->getGlobalBaseReg();
  const TargetRegisterClass *RC;

  if (Subtarget.isABI_N64())
    RC = (const TargetRegisterClass*)&Oi::CPU64RegsRegClass;
  else
    RC = (const TargetRegisterClass*)&Oi::CPURegsRegClass;

  V0 = RegInfo.createVirtualRegister(RC);
  V1 = RegInfo.createVirtualRegister(RC);

  if (Subtarget.isABI_N64()) {
    MF.getRegInfo().addLiveIn(Oi::T9_64);
    MBB.addLiveIn(Oi::T9_64);

    // lui $v0, %hi(%neg(%gp_rel(fname)))
    // daddu $v1, $v0, $t9
    // daddiu $globalbasereg, $v1, %lo(%neg(%gp_rel(fname)))
    const GlobalValue *FName = MF.getFunction();
    BuildMI(MBB, I, DL, TII.get(Oi::LUi64), V0)
      .addGlobalAddress(FName, 0, OiII::MO_GPOFF_HI);
    BuildMI(MBB, I, DL, TII.get(Oi::DADDu), V1).addReg(V0)
      .addReg(Oi::T9_64);
    BuildMI(MBB, I, DL, TII.get(Oi::DADDiu), GlobalBaseReg).addReg(V1)
      .addGlobalAddress(FName, 0, OiII::MO_GPOFF_LO);
    return;
  }

  if (MF.getTarget().getRelocationModel() == Reloc::Static) {
    // Set global register to __gnu_local_gp.
    //
    // lui   $v0, %hi(__gnu_local_gp)
    // addiu $globalbasereg, $v0, %lo(__gnu_local_gp)
    BuildMI(MBB, I, DL, TII.get(Oi::LUi), V0)
      .addExternalSymbol("__gnu_local_gp", OiII::MO_ABS_HI);
    BuildMI(MBB, I, DL, TII.get(Oi::ADDiu), GlobalBaseReg).addReg(V0)
      .addExternalSymbol("__gnu_local_gp", OiII::MO_ABS_LO);
    return;
  }

  MF.getRegInfo().addLiveIn(Oi::T9);
  MBB.addLiveIn(Oi::T9);

  if (Subtarget.isABI_N32()) {
    // lui $v0, %hi(%neg(%gp_rel(fname)))
    // addu $v1, $v0, $t9
    // addiu $globalbasereg, $v1, %lo(%neg(%gp_rel(fname)))
    const GlobalValue *FName = MF.getFunction();
    BuildMI(MBB, I, DL, TII.get(Oi::LUi), V0)
      .addGlobalAddress(FName, 0, OiII::MO_GPOFF_HI);
    BuildMI(MBB, I, DL, TII.get(Oi::ADDu), V1).addReg(V0).addReg(Oi::T9);
    BuildMI(MBB, I, DL, TII.get(Oi::ADDiu), GlobalBaseReg).addReg(V1)
      .addGlobalAddress(FName, 0, OiII::MO_GPOFF_LO);
    return;
  }

  assert(Subtarget.isABI_O32());

  // For O32 ABI, the following instruction sequence is emitted to initialize
  // the global base register:
  //
  //  0. lui   $2, %hi(_gp_disp)
  //  1. addiu $2, $2, %lo(_gp_disp)
  //  2. addu  $globalbasereg, $2, $t9
  //
  // We emit only the last instruction here.
  //
  // GNU linker requires that the first two instructions appear at the beginning
  // of a function and no instructions be inserted before or between them.
  // The two instructions are emitted during lowering to MC layer in order to
  // avoid any reordering.
  //
  // Register $2 (Oi::V0) is added to the list of live-in registers to ensure
  // the value instruction 1 (addiu) defines is valid when instruction 2 (addu)
  // reads it.
  MF.getRegInfo().addLiveIn(Oi::V0);
  MBB.addLiveIn(Oi::V0);
  BuildMI(MBB, I, DL, TII.get(Oi::ADDu), GlobalBaseReg)
    .addReg(Oi::V0).addReg(Oi::T9);
}

void OiSEDAGToDAGISel::processFunctionAfterISel(MachineFunction &MF) {
  initGlobalBaseReg(MF);

  MachineRegisterInfo *MRI = &MF.getRegInfo();

  for (MachineFunction::iterator MFI = MF.begin(), MFE = MF.end(); MFI != MFE;
       ++MFI)
    for (MachineBasicBlock::iterator I = MFI->begin(); I != MFI->end(); ++I) {
      if (I->getOpcode() == Oi::RDDSP)
        addDSPCtrlRegOperands(false, *I, MF);
      else if (I->getOpcode() == Oi::WRDSP)
        addDSPCtrlRegOperands(true, *I, MF);
      else
        replaceUsesWithZeroReg(MRI, *I);
    }
}

SDNode *OiSEDAGToDAGISel::selectAddESubE(unsigned MOp, SDValue InFlag,
                                           SDValue CmpLHS, DebugLoc DL,
                                           SDNode *Node) const {
  unsigned Opc = InFlag.getOpcode(); (void)Opc;

  assert(((Opc == ISD::ADDC || Opc == ISD::ADDE) ||
          (Opc == ISD::SUBC || Opc == ISD::SUBE)) &&
         "(ADD|SUB)E flag operand must come from (ADD|SUB)C/E insn");

  SDValue Ops[] = { CmpLHS, InFlag.getOperand(1) };
  SDValue LHS = Node->getOperand(0), RHS = Node->getOperand(1);
  EVT VT = LHS.getValueType();

  SDNode *Carry = CurDAG->getMachineNode(Oi::SLTu, DL, VT, Ops);
  SDNode *AddCarry = CurDAG->getMachineNode(Oi::ADDu, DL, VT,
                                            SDValue(Carry, 0), RHS);
  return CurDAG->SelectNodeTo(Node, MOp, VT, MVT::Glue, LHS,
                              SDValue(AddCarry, 0));
}

/// ComplexPattern used on OiInstrInfo
/// Used on Oi Load/Store instructions
bool OiSEDAGToDAGISel::selectAddrRegImm(SDValue Addr, SDValue &Base,
                                          SDValue &Offset) const {
  EVT ValTy = Addr.getValueType();

  // if Address is FI, get the TargetFrameIndex.
  if (FrameIndexSDNode *FIN = dyn_cast<FrameIndexSDNode>(Addr)) {
    Base   = CurDAG->getTargetFrameIndex(FIN->getIndex(), ValTy);
    Offset = CurDAG->getTargetConstant(0, ValTy);
    return true;
  }

  // on PIC code Load GA
  if (Addr.getOpcode() == OiISD::Wrapper) {
    Base   = Addr.getOperand(0);
    Offset = Addr.getOperand(1);
    return true;
  }

  if (TM.getRelocationModel() != Reloc::PIC_) {
    if ((Addr.getOpcode() == ISD::TargetExternalSymbol ||
        Addr.getOpcode() == ISD::TargetGlobalAddress))
      return false;
  }

  // Addresses of the form FI+const or FI|const
  if (CurDAG->isBaseWithConstantOffset(Addr)) {
    ConstantSDNode *CN = dyn_cast<ConstantSDNode>(Addr.getOperand(1));
    if (isInt<32>(CN->getSExtValue())) {

      // If the first operand is a FI, get the TargetFI Node
      if (FrameIndexSDNode *FIN = dyn_cast<FrameIndexSDNode>
                                  (Addr.getOperand(0)))
        Base = CurDAG->getTargetFrameIndex(FIN->getIndex(), ValTy);
      else
        Base = Addr.getOperand(0);

      Offset = CurDAG->getTargetConstant(CN->getZExtValue(), ValTy);
      return true;
    }
  }

  // Operand is a result from an ADD.
  if (Addr.getOpcode() == ISD::ADD) {
    // When loading from constant pools, load the lower address part in
    // the instruction itself. Example, instead of:
    //  lui $2, %hi($CPI1_0)
    //  addiu $2, $2, %lo($CPI1_0)
    //  lwc1 $f0, 0($2)
    // Generate:
    //  lui $2, %hi($CPI1_0)
    //  lwc1 $f0, %lo($CPI1_0)($2)
    if (Addr.getOperand(1).getOpcode() == OiISD::Lo ||
        Addr.getOperand(1).getOpcode() == OiISD::GPRel) {
      SDValue Opnd0 = Addr.getOperand(1).getOperand(0);
      if (isa<ConstantPoolSDNode>(Opnd0) || isa<GlobalAddressSDNode>(Opnd0) ||
          isa<JumpTableSDNode>(Opnd0)) {
        // Stupid modification below screws ConstantPool loading logic! Reverted
        // Blame: commit "Adapting backend to use 32-bit immediates" 
        //Base = CurDAG->getRegister(Oi::ZERO, ValTy);
        Base = Addr.getOperand(0);
        Offset = Opnd0;
        return true;
      }
    }
  }

  return false;
}

bool OiSEDAGToDAGISel::selectAddrDefault(SDValue Addr, SDValue &Base,
                                           SDValue &Offset) const {
  Base = Addr;
  Offset = CurDAG->getTargetConstant(0, Addr.getValueType());
  return true;
}

bool OiSEDAGToDAGISel::selectIntAddr(SDValue Addr, SDValue &Base,
                                       SDValue &Offset) const {
  return selectAddrRegImm(Addr, Base, Offset) ||
    selectAddrDefault(Addr, Base, Offset);
}

std::pair<bool, SDNode*> OiSEDAGToDAGISel::selectNode(SDNode *Node) {
  unsigned Opcode = Node->getOpcode();
  DebugLoc DL = Node->getDebugLoc();

  ///
  // Instruction Selection not handled by the auto-generated
  // tablegen selection should be handled here.
  ///
  SDNode *Result;

  switch(Opcode) {
  default: break;

  case ISD::SUBE: {
    SDValue InFlag = Node->getOperand(2);
    Result = selectAddESubE(Oi::SUBu, InFlag, InFlag.getOperand(0), DL, Node);
    return std::make_pair(true, Result);
  }

  case ISD::ADDE: {
    if (Subtarget.hasDSP()) // Select DSP instructions, ADDSC and ADDWC.
      break;
    SDValue InFlag = Node->getOperand(2);
    Result = selectAddESubE(Oi::ADDu, InFlag, InFlag.getValue(0), DL, Node);
    return std::make_pair(true, Result);
  }

  case ISD::ConstantFP: {
    ConstantFPSDNode *CN = dyn_cast<ConstantFPSDNode>(Node);
    if (Node->getValueType(0) == MVT::f64 && CN->isExactlyValue(+0.0)) {
      if (Subtarget.hasOi64()) {
        SDValue Zero = CurDAG->getCopyFromReg(CurDAG->getEntryNode(), DL,
                                              Oi::ZERO_64, MVT::i64);
        Result = CurDAG->getMachineNode(Oi::DMTC1, DL, MVT::f64, Zero);
      } else {
        SDValue Zero = CurDAG->getCopyFromReg(CurDAG->getEntryNode(), DL,
                                              Oi::ZERO, MVT::i32);
        Result = CurDAG->getMachineNode(Oi::BuildPairF64, DL, MVT::f64, Zero,
                                        Zero);
      }

      return std::make_pair(true, Result);
    }
    break;
  }

  case ISD::Constant: {
    const ConstantSDNode *CN = dyn_cast<ConstantSDNode>(Node);
    unsigned Size = CN->getValueSizeInBits(0);

    if (Size == 32)
      break;

    OiAnalyzeImmediate AnalyzeImm;
    int64_t Imm = CN->getSExtValue();

    const OiAnalyzeImmediate::InstSeq &Seq =
      AnalyzeImm.Analyze(Imm, Size, false);

    OiAnalyzeImmediate::InstSeq::const_iterator Inst = Seq.begin();
    DebugLoc DL = CN->getDebugLoc();
    SDNode *RegOpnd;
    SDValue ImmOpnd = CurDAG->getTargetConstant(SignExtend64<16>(Inst->ImmOpnd),
                                                MVT::i64);

    // The first instruction can be a LUi which is different from other
    // instructions (ADDiu, ORI and SLL) in that it does not have a register
    // operand.
    if (Inst->Opc == Oi::LUi64)
      RegOpnd = CurDAG->getMachineNode(Inst->Opc, DL, MVT::i64, ImmOpnd);
    else
      RegOpnd =
        CurDAG->getMachineNode(Inst->Opc, DL, MVT::i64,
                               CurDAG->getRegister(Oi::ZERO_64, MVT::i64),
                               ImmOpnd);

    // The remaining instructions in the sequence are handled here.
    for (++Inst; Inst != Seq.end(); ++Inst) {
      ImmOpnd = CurDAG->getTargetConstant(SignExtend64<16>(Inst->ImmOpnd),
                                          MVT::i64);
      RegOpnd = CurDAG->getMachineNode(Inst->Opc, DL, MVT::i64,
                                       SDValue(RegOpnd, 0), ImmOpnd);
    }

    return std::make_pair(true, RegOpnd);
  }

  case OiISD::ThreadPointer: {
    EVT PtrVT = TLI.getPointerTy();
    unsigned RdhwrOpc, SrcReg, DestReg;

    if (PtrVT == MVT::i32) {
      RdhwrOpc = Oi::RDHWR;
      SrcReg = Oi::HWR29;
      DestReg = Oi::V1;
    } else {
      RdhwrOpc = Oi::RDHWR64;
      SrcReg = Oi::HWR29_64;
      DestReg = Oi::V1_64;
    }

    SDNode *Rdhwr =
      CurDAG->getMachineNode(RdhwrOpc, Node->getDebugLoc(),
                             Node->getValueType(0),
                             CurDAG->getRegister(SrcReg, PtrVT));
    SDValue Chain = CurDAG->getCopyToReg(CurDAG->getEntryNode(), DL, DestReg,
                                         SDValue(Rdhwr, 0));
    SDValue ResNode = CurDAG->getCopyFromReg(Chain, DL, DestReg, PtrVT);
    ReplaceUses(SDValue(Node, 0), ResNode);
    return std::make_pair(true, ResNode.getNode());
  }

  case OiISD::InsertLOHI: {
    unsigned RCID = Subtarget.hasDSP() ? Oi::ACRegsDSPRegClassID :
                                         Oi::ACRegsRegClassID;
    SDValue RegClass = CurDAG->getTargetConstant(RCID, MVT::i32);
    SDValue LoIdx = CurDAG->getTargetConstant(Oi::sub_lo, MVT::i32);
    SDValue HiIdx = CurDAG->getTargetConstant(Oi::sub_hi, MVT::i32);
    const SDValue Ops[] = { RegClass, Node->getOperand(0), LoIdx,
                            Node->getOperand(1), HiIdx };
    SDNode *Res = CurDAG->getMachineNode(TargetOpcode::REG_SEQUENCE, DL,
                                         MVT::Untyped, Ops);
    return std::make_pair(true, Res);
  }
  }

  return std::make_pair(false, (SDNode*)NULL);
}

FunctionPass *llvm::createOiSEISelDag(OiTargetMachine &TM) {
  return new OiSEDAGToDAGISel(TM);
}
