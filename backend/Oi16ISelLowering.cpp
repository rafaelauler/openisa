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
#define DEBUG_TYPE "oi-lower"
#include "Oi16ISelLowering.h"
#include "OiRegisterInfo.h"
#include "MCTargetDesc/OiBaseInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Target/TargetInstrInfo.h"
#include <set>

using namespace llvm;

static cl::opt<bool>
Oi16HardFloat("oi16-hard-float", cl::NotHidden,
                cl::desc("OI: oi16 hard float enable."),
                cl::init(false));

static cl::opt<bool> DontExpandCondPseudos16(
  "oi16-dont-expand-cond-pseudo",
  cl::init(false),
  cl::desc("Dont expand conditional move related "
           "pseudos for Oi 16"),
  cl::Hidden);

namespace {
  std::set<const char*, OiTargetLowering::LTStr> NoHelperNeeded;
}

Oi16TargetLowering::Oi16TargetLowering(OiTargetMachine &TM)
  : OiTargetLowering(TM) {
  //
  // set up as if oi32 and then revert so we can test the mechanism
  // for switching
  addRegisterClass(MVT::i32, &Oi::CPURegsRegClass);
  addRegisterClass(MVT::f32, &Oi::FGR32RegClass);
  computeRegisterProperties();
  clearRegisterClasses();

  // Set up the register classes
  addRegisterClass(MVT::i32, &Oi::CPU16RegsRegClass);

  if (Oi16HardFloat)
    setOi16HardFloatLibCalls();

  setOperationAction(ISD::ATOMIC_FENCE,       MVT::Other, Expand);
  setOperationAction(ISD::ATOMIC_CMP_SWAP,    MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_SWAP,        MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_ADD,    MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_SUB,    MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_AND,    MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_OR,     MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_XOR,    MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_NAND,   MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_MIN,    MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_MAX,    MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_UMIN,   MVT::i32,   Expand);
  setOperationAction(ISD::ATOMIC_LOAD_UMAX,   MVT::i32,   Expand);

  computeRegisterProperties();
}

const OiTargetLowering *
llvm::createOi16TargetLowering(OiTargetMachine &TM) {
  return new Oi16TargetLowering(TM);
}

bool
Oi16TargetLowering::allowsUnalignedMemoryAccesses(EVT VT, bool *Fast) const {
  return false;
}

MachineBasicBlock *
Oi16TargetLowering::EmitInstrWithCustomInserter(MachineInstr *MI,
                                                  MachineBasicBlock *BB) const {
  switch (MI->getOpcode()) {
  default:
    return OiTargetLowering::EmitInstrWithCustomInserter(MI, BB);
  case Oi::SelBeqZ:
    return emitSel16(Oi::BeqzRxImm16, MI, BB);
  case Oi::SelBneZ:
    return emitSel16(Oi::BnezRxImm16, MI, BB);
  case Oi::SelTBteqZCmpi:
    return emitSeliT16(Oi::BteqzX16, Oi::CmpiRxImmX16, MI, BB);
  case Oi::SelTBteqZSlti:
    return emitSeliT16(Oi::BteqzX16, Oi::SltiRxImmX16, MI, BB);
  case Oi::SelTBteqZSltiu:
    return emitSeliT16(Oi::BteqzX16, Oi::SltiuRxImmX16, MI, BB);
  case Oi::SelTBtneZCmpi:
    return emitSeliT16(Oi::BtnezX16, Oi::CmpiRxImmX16, MI, BB);
  case Oi::SelTBtneZSlti:
    return emitSeliT16(Oi::BtnezX16, Oi::SltiRxImmX16, MI, BB);
  case Oi::SelTBtneZSltiu:
    return emitSeliT16(Oi::BtnezX16, Oi::SltiuRxImmX16, MI, BB);
  case Oi::SelTBteqZCmp:
    return emitSelT16(Oi::BteqzX16, Oi::CmpRxRy16, MI, BB);
  case Oi::SelTBteqZSlt:
    return emitSelT16(Oi::BteqzX16, Oi::SltRxRy16, MI, BB);
  case Oi::SelTBteqZSltu:
    return emitSelT16(Oi::BteqzX16, Oi::SltuRxRy16, MI, BB);
  case Oi::SelTBtneZCmp:
    return emitSelT16(Oi::BtnezX16, Oi::CmpRxRy16, MI, BB);
  case Oi::SelTBtneZSlt:
    return emitSelT16(Oi::BtnezX16, Oi::SltRxRy16, MI, BB);
  case Oi::SelTBtneZSltu:
    return emitSelT16(Oi::BtnezX16, Oi::SltuRxRy16, MI, BB);
  case Oi::BteqzT8CmpX16:
    return emitFEXT_T8I816_ins(Oi::BteqzX16, Oi::CmpRxRy16, MI, BB);
  case Oi::BteqzT8SltX16:
    return emitFEXT_T8I816_ins(Oi::BteqzX16, Oi::SltRxRy16, MI, BB);
  case Oi::BteqzT8SltuX16:
    // TBD: figure out a way to get this or remove the instruction
    // altogether.
    return emitFEXT_T8I816_ins(Oi::BteqzX16, Oi::SltuRxRy16, MI, BB);
  case Oi::BtnezT8CmpX16:
    return emitFEXT_T8I816_ins(Oi::BtnezX16, Oi::CmpRxRy16, MI, BB);
  case Oi::BtnezT8SltX16:
    return emitFEXT_T8I816_ins(Oi::BtnezX16, Oi::SltRxRy16, MI, BB);
  case Oi::BtnezT8SltuX16:
    // TBD: figure out a way to get this or remove the instruction
    // altogether.
    return emitFEXT_T8I816_ins(Oi::BtnezX16, Oi::SltuRxRy16, MI, BB);
  case Oi::BteqzT8CmpiX16: return emitFEXT_T8I8I16_ins(
    Oi::BteqzX16, Oi::CmpiRxImm16, Oi::CmpiRxImmX16, MI, BB);
  case Oi::BteqzT8SltiX16: return emitFEXT_T8I8I16_ins(
    Oi::BteqzX16, Oi::SltiRxImm16, Oi::SltiRxImmX16, MI, BB);
  case Oi::BteqzT8SltiuX16: return emitFEXT_T8I8I16_ins(
    Oi::BteqzX16, Oi::SltiuRxImm16, Oi::SltiuRxImmX16, MI, BB);
  case Oi::BtnezT8CmpiX16: return emitFEXT_T8I8I16_ins(
    Oi::BtnezX16, Oi::CmpiRxImm16, Oi::CmpiRxImmX16, MI, BB);
  case Oi::BtnezT8SltiX16: return emitFEXT_T8I8I16_ins(
    Oi::BtnezX16, Oi::SltiRxImm16, Oi::SltiRxImmX16, MI, BB);
  case Oi::BtnezT8SltiuX16: return emitFEXT_T8I8I16_ins(
    Oi::BtnezX16, Oi::SltiuRxImm16, Oi::SltiuRxImmX16, MI, BB);
    break;
  case Oi::SltCCRxRy16:
    return emitFEXT_CCRX16_ins(Oi::SltRxRy16, MI, BB);
    break;
  case Oi::SltiCCRxImmX16:
    return emitFEXT_CCRXI16_ins
      (Oi::SltiRxImm16, Oi::SltiRxImmX16, MI, BB);
  case Oi::SltiuCCRxImmX16:
    return emitFEXT_CCRXI16_ins
      (Oi::SltiuRxImm16, Oi::SltiuRxImmX16, MI, BB);
  case Oi::SltuCCRxRy16:
    return emitFEXT_CCRX16_ins
      (Oi::SltuRxRy16, MI, BB);
  }
}

bool Oi16TargetLowering::
isEligibleForTailCallOptimization(const OiCC &OiCCInfo,
                                  unsigned NextStackOffset,
                                  const OiFunctionInfo& FI) const {
  // No tail call optimization for oi16.
  return false;
}

void Oi16TargetLowering::setOi16LibcallName
  (RTLIB::Libcall L, const char *Name) {
  setLibcallName(L, Name);
  NoHelperNeeded.insert(Name);
}

void Oi16TargetLowering::setOi16HardFloatLibCalls() {
  setOi16LibcallName(RTLIB::ADD_F32, "__oi16_addsf3");
  setOi16LibcallName(RTLIB::ADD_F64, "__oi16_adddf3");
  setOi16LibcallName(RTLIB::SUB_F32, "__oi16_subsf3");
  setOi16LibcallName(RTLIB::SUB_F64, "__oi16_subdf3");
  setOi16LibcallName(RTLIB::MUL_F32, "__oi16_mulsf3");
  setOi16LibcallName(RTLIB::MUL_F64, "__oi16_muldf3");
  setOi16LibcallName(RTLIB::DIV_F32, "__oi16_divsf3");
  setOi16LibcallName(RTLIB::DIV_F64, "__oi16_divdf3");
  setOi16LibcallName(RTLIB::FPEXT_F32_F64, "__oi16_extendsfdf2");
  setOi16LibcallName(RTLIB::FPROUND_F64_F32, "__oi16_truncdfsf2");
  setOi16LibcallName(RTLIB::FPTOSINT_F32_I32, "__oi16_fix_truncsfsi");
  setOi16LibcallName(RTLIB::FPTOSINT_F64_I32, "__oi16_fix_truncdfsi");
  setOi16LibcallName(RTLIB::SINTTOFP_I32_F32, "__oi16_floatsisf");
  setOi16LibcallName(RTLIB::SINTTOFP_I32_F64, "__oi16_floatsidf");
  setOi16LibcallName(RTLIB::UINTTOFP_I32_F32, "__oi16_floatunsisf");
  setOi16LibcallName(RTLIB::UINTTOFP_I32_F64, "__oi16_floatunsidf");
  setOi16LibcallName(RTLIB::OEQ_F32, "__oi16_eqsf2");
  setOi16LibcallName(RTLIB::OEQ_F64, "__oi16_eqdf2");
  setOi16LibcallName(RTLIB::UNE_F32, "__oi16_nesf2");
  setOi16LibcallName(RTLIB::UNE_F64, "__oi16_nedf2");
  setOi16LibcallName(RTLIB::OGE_F32, "__oi16_gesf2");
  setOi16LibcallName(RTLIB::OGE_F64, "__oi16_gedf2");
  setOi16LibcallName(RTLIB::OLT_F32, "__oi16_ltsf2");
  setOi16LibcallName(RTLIB::OLT_F64, "__oi16_ltdf2");
  setOi16LibcallName(RTLIB::OLE_F32, "__oi16_lesf2");
  setOi16LibcallName(RTLIB::OLE_F64, "__oi16_ledf2");
  setOi16LibcallName(RTLIB::OGT_F32, "__oi16_gtsf2");
  setOi16LibcallName(RTLIB::OGT_F64, "__oi16_gtdf2");
  setOi16LibcallName(RTLIB::UO_F32, "__oi16_unordsf2");
  setOi16LibcallName(RTLIB::UO_F64, "__oi16_unorddf2");
  setOi16LibcallName(RTLIB::O_F32, "__oi16_unordsf2");
  setOi16LibcallName(RTLIB::O_F64, "__oi16_unorddf2");
}


//
// The Oi16 hard float is a crazy quilt inherited from gcc. I have a much
// cleaner way to do all of this but it will have to wait until the traditional
// gcc mechanism is completed.
//
// For Pic, in order for Oi16 code to call Oi32 code which according the abi
// have either arguments or returned values placed in floating point registers,
// we use a set of helper functions. (This includes functions which return type
//  complex which on Oi are returned in a pair of floating point registers).
//
// This is an encoding that we inherited from gcc.
// In Oi traditional O32, N32 ABI, floating point numbers are passed in
// floating point argument registers 1,2 only when the first and optionally
// the second arguments are float (sf) or double (df).
// For Oi16 we are only concerned with the situations where floating point
// arguments are being passed in floating point registers by the ABI, because
// Oi16 mode code cannot execute floating point instructions to load those
// values and hence helper functions are needed.
// The possibilities are (), (sf), (sf, sf), (sf, df), (df), (df, sf), (df, df)
// the helper function suffixs for these are:
//                        0,  1,    5,        9,         2,   6,        10
// this suffix can then be calculated as follows:
// for a given argument Arg:
//     Arg1x, Arg2x = 1 :  Arg is sf
//                    2 :  Arg is df
//                    0:   Arg is neither sf or df
// So this stub is the string for number Arg1x + Arg2x*4.
// However not all numbers between 0 and 10 are possible, we check anyway and
// assert if the impossible exists.
//

unsigned int Oi16TargetLowering::getOi16HelperFunctionStubNumber
  (ArgListTy &Args) const {
  unsigned int resultNum = 0;
  if (Args.size() >= 1) {
    Type *t = Args[0].Ty;
    if (t->isFloatTy()) {
      resultNum = 1;
    }
    else if (t->isDoubleTy()) {
      resultNum = 2;
    }
  }
  if (resultNum) {
    if (Args.size() >=2) {
      Type *t = Args[1].Ty;
      if (t->isFloatTy()) {
        resultNum += 4;
      }
      else if (t->isDoubleTy()) {
        resultNum += 8;
      }
    }
  }
  return resultNum;
}

//
// prefixs are attached to stub numbers depending on the return type .
// return type: float  sf_
//              double df_
//              single complex sc_
//              double complext dc_
//              others  NO PREFIX
//
//
// The full name of a helper function is__oi16_call_stub +
//    return type dependent prefix + stub number
//
//
// This is something that probably should be in a different source file and
// perhaps done differently but my main purpose is to not waste runtime
// on something that we can enumerate in the source. Another possibility is
// to have a python script to generate these mapping tables. This will do
// for now. There are a whole series of helper function mapping arrays, one
// for each return type class as outlined above. There there are 11 possible
//  entries. Ones with 0 are ones which should never be selected
//
// All the arrays are similar except for ones which return neither
// sf, df, sc, dc, in which only care about ones which have sf or df as a
// first parameter.
//
#define P_ "__oi16_call_stub_"
#define MAX_STUB_NUMBER 10
#define T1 P "1", P "2", 0, 0, P "5", P "6", 0, 0, P "9", P "10"
#define T P "0" , T1
#define P P_
static char const * vOi16Helper[MAX_STUB_NUMBER+1] =
  {0, T1 };
#undef P
#define P P_ "sf_"
static char const * sfOi16Helper[MAX_STUB_NUMBER+1] =
  { T };
#undef P
#define P P_ "df_"
static char const * dfOi16Helper[MAX_STUB_NUMBER+1] =
  { T };
#undef P
#define P P_ "sc_"
static char const * scOi16Helper[MAX_STUB_NUMBER+1] =
  { T };
#undef P
#define P P_ "dc_"
static char const * dcOi16Helper[MAX_STUB_NUMBER+1] =
  { T };
#undef P
#undef P_


const char* Oi16TargetLowering::
  getOi16HelperFunction
    (Type* RetTy, ArgListTy &Args, bool &needHelper) const {
  const unsigned int stubNum = getOi16HelperFunctionStubNumber(Args);
#ifndef NDEBUG
  const unsigned int maxStubNum = 10;
  assert(stubNum <= maxStubNum);
  const bool validStubNum[maxStubNum+1] =
    {true, true, true, false, false, true, true, false, false, true, true};
  assert(validStubNum[stubNum]);
#endif
  const char *result;
  if (RetTy->isFloatTy()) {
    result = sfOi16Helper[stubNum];
  }
  else if (RetTy ->isDoubleTy()) {
    result = dfOi16Helper[stubNum];
  }
  else if (RetTy->isStructTy()) {
    // check if it's complex
    if (RetTy->getNumContainedTypes() == 2) {
      if ((RetTy->getContainedType(0)->isFloatTy()) &&
          (RetTy->getContainedType(1)->isFloatTy())) {
        result = scOi16Helper[stubNum];
      }
      else if ((RetTy->getContainedType(0)->isDoubleTy()) &&
               (RetTy->getContainedType(1)->isDoubleTy())) {
        result = dcOi16Helper[stubNum];
      }
      else {
        llvm_unreachable("Uncovered condition");
      }
    }
    else {
      llvm_unreachable("Uncovered condition");
    }
  }
  else {
    if (stubNum == 0) {
      needHelper = false;
      return "";
    }
    result = vOi16Helper[stubNum];
  }
  needHelper = true;
  return result;
}

void Oi16TargetLowering::
getOpndList(SmallVectorImpl<SDValue> &Ops,
            std::deque< std::pair<unsigned, SDValue> > &RegsToPass,
            bool IsPICCall, bool GlobalOrExternal, bool InternalLinkage,
            CallLoweringInfo &CLI, SDValue Callee, SDValue Chain) const {
  SelectionDAG &DAG = CLI.DAG;
  const char* Oi16HelperFunction = 0;
  bool NeedOi16Helper = false;

  if (getTargetMachine().Options.UseSoftFloat && Oi16HardFloat) {
    //
    // currently we don't have symbols tagged with the oi16 or oi32
    // qualifier so we will assume that we don't know what kind it is.
    // and generate the helper
    //
    bool LookupHelper = true;
    if (ExternalSymbolSDNode *S = dyn_cast<ExternalSymbolSDNode>(CLI.Callee)) {
      if (NoHelperNeeded.find(S->getSymbol()) != NoHelperNeeded.end()) {
        LookupHelper = false;
      }
    }
    if (LookupHelper) Oi16HelperFunction =
      getOi16HelperFunction(CLI.RetTy, CLI.Args, NeedOi16Helper);

  }

  SDValue JumpTarget = Callee;

  // T9 should contain the address of the callee function if
  // -reloction-model=pic or it is an indirect call.
  if (IsPICCall || !GlobalOrExternal) {
    unsigned V0Reg = Oi::V0;
    if (NeedOi16Helper) {
      RegsToPass.push_front(std::make_pair(V0Reg, Callee));
      JumpTarget = DAG.getExternalSymbol(Oi16HelperFunction, getPointerTy());
      JumpTarget = getAddrGlobal(JumpTarget, DAG, OiII::MO_GOT);
    } else
      RegsToPass.push_front(std::make_pair((unsigned)Oi::T9, Callee));
  }

  Ops.push_back(JumpTarget);

  OiTargetLowering::getOpndList(Ops, RegsToPass, IsPICCall, GlobalOrExternal,
                                  InternalLinkage, CLI, Callee, Chain);
}

MachineBasicBlock *Oi16TargetLowering::
emitSel16(unsigned Opc, MachineInstr *MI, MachineBasicBlock *BB) const {
  if (DontExpandCondPseudos16)
    return BB;
  const TargetInstrInfo *TII = getTargetMachine().getInstrInfo();
  DebugLoc DL = MI->getDebugLoc();
  // To "insert" a SELECT_CC instruction, we actually have to insert the
  // diamond control-flow pattern.  The incoming instruction knows the
  // destination vreg to set, the condition code register to branch on, the
  // true/false values to select between, and a branch opcode to use.
  const BasicBlock *LLVM_BB = BB->getBasicBlock();
  MachineFunction::iterator It = BB;
  ++It;

  //  thisMBB:
  //  ...
  //   TrueVal = ...
  //   setcc r1, r2, r3
  //   bNE   r1, r0, copy1MBB
  //   fallthrough --> copy0MBB
  MachineBasicBlock *thisMBB  = BB;
  MachineFunction *F = BB->getParent();
  MachineBasicBlock *copy0MBB = F->CreateMachineBasicBlock(LLVM_BB);
  MachineBasicBlock *sinkMBB  = F->CreateMachineBasicBlock(LLVM_BB);
  F->insert(It, copy0MBB);
  F->insert(It, sinkMBB);

  // Transfer the remainder of BB and its successor edges to sinkMBB.
  sinkMBB->splice(sinkMBB->begin(), BB,
                  llvm::next(MachineBasicBlock::iterator(MI)),
                  BB->end());
  sinkMBB->transferSuccessorsAndUpdatePHIs(BB);

  // Next, add the true and fallthrough blocks as its successors.
  BB->addSuccessor(copy0MBB);
  BB->addSuccessor(sinkMBB);

  BuildMI(BB, DL, TII->get(Opc)).addReg(MI->getOperand(3).getReg())
    .addMBB(sinkMBB);

  //  copy0MBB:
  //   %FalseValue = ...
  //   # fallthrough to sinkMBB
  BB = copy0MBB;

  // Update machine-CFG edges
  BB->addSuccessor(sinkMBB);

  //  sinkMBB:
  //   %Result = phi [ %TrueValue, thisMBB ], [ %FalseValue, copy0MBB ]
  //  ...
  BB = sinkMBB;

  BuildMI(*BB, BB->begin(), DL,
          TII->get(Oi::PHI), MI->getOperand(0).getReg())
    .addReg(MI->getOperand(1).getReg()).addMBB(thisMBB)
    .addReg(MI->getOperand(2).getReg()).addMBB(copy0MBB);

  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;
}

MachineBasicBlock *Oi16TargetLowering::emitSelT16
  (unsigned Opc1, unsigned Opc2,
   MachineInstr *MI, MachineBasicBlock *BB) const {
  if (DontExpandCondPseudos16)
    return BB;
  const TargetInstrInfo *TII = getTargetMachine().getInstrInfo();
  DebugLoc DL = MI->getDebugLoc();
  // To "insert" a SELECT_CC instruction, we actually have to insert the
  // diamond control-flow pattern.  The incoming instruction knows the
  // destination vreg to set, the condition code register to branch on, the
  // true/false values to select between, and a branch opcode to use.
  const BasicBlock *LLVM_BB = BB->getBasicBlock();
  MachineFunction::iterator It = BB;
  ++It;

  //  thisMBB:
  //  ...
  //   TrueVal = ...
  //   setcc r1, r2, r3
  //   bNE   r1, r0, copy1MBB
  //   fallthrough --> copy0MBB
  MachineBasicBlock *thisMBB  = BB;
  MachineFunction *F = BB->getParent();
  MachineBasicBlock *copy0MBB = F->CreateMachineBasicBlock(LLVM_BB);
  MachineBasicBlock *sinkMBB  = F->CreateMachineBasicBlock(LLVM_BB);
  F->insert(It, copy0MBB);
  F->insert(It, sinkMBB);

  // Transfer the remainder of BB and its successor edges to sinkMBB.
  sinkMBB->splice(sinkMBB->begin(), BB,
                  llvm::next(MachineBasicBlock::iterator(MI)),
                  BB->end());
  sinkMBB->transferSuccessorsAndUpdatePHIs(BB);

  // Next, add the true and fallthrough blocks as its successors.
  BB->addSuccessor(copy0MBB);
  BB->addSuccessor(sinkMBB);

  BuildMI(BB, DL, TII->get(Opc2)).addReg(MI->getOperand(3).getReg())
    .addReg(MI->getOperand(4).getReg());
  BuildMI(BB, DL, TII->get(Opc1)).addMBB(sinkMBB);

  //  copy0MBB:
  //   %FalseValue = ...
  //   # fallthrough to sinkMBB
  BB = copy0MBB;

  // Update machine-CFG edges
  BB->addSuccessor(sinkMBB);

  //  sinkMBB:
  //   %Result = phi [ %TrueValue, thisMBB ], [ %FalseValue, copy0MBB ]
  //  ...
  BB = sinkMBB;

  BuildMI(*BB, BB->begin(), DL,
          TII->get(Oi::PHI), MI->getOperand(0).getReg())
    .addReg(MI->getOperand(1).getReg()).addMBB(thisMBB)
    .addReg(MI->getOperand(2).getReg()).addMBB(copy0MBB);

  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;

}

MachineBasicBlock *Oi16TargetLowering::emitSeliT16
  (unsigned Opc1, unsigned Opc2,
   MachineInstr *MI, MachineBasicBlock *BB) const {
  if (DontExpandCondPseudos16)
    return BB;
  const TargetInstrInfo *TII = getTargetMachine().getInstrInfo();
  DebugLoc DL = MI->getDebugLoc();
  // To "insert" a SELECT_CC instruction, we actually have to insert the
  // diamond control-flow pattern.  The incoming instruction knows the
  // destination vreg to set, the condition code register to branch on, the
  // true/false values to select between, and a branch opcode to use.
  const BasicBlock *LLVM_BB = BB->getBasicBlock();
  MachineFunction::iterator It = BB;
  ++It;

  //  thisMBB:
  //  ...
  //   TrueVal = ...
  //   setcc r1, r2, r3
  //   bNE   r1, r0, copy1MBB
  //   fallthrough --> copy0MBB
  MachineBasicBlock *thisMBB  = BB;
  MachineFunction *F = BB->getParent();
  MachineBasicBlock *copy0MBB = F->CreateMachineBasicBlock(LLVM_BB);
  MachineBasicBlock *sinkMBB  = F->CreateMachineBasicBlock(LLVM_BB);
  F->insert(It, copy0MBB);
  F->insert(It, sinkMBB);

  // Transfer the remainder of BB and its successor edges to sinkMBB.
  sinkMBB->splice(sinkMBB->begin(), BB,
                  llvm::next(MachineBasicBlock::iterator(MI)),
                  BB->end());
  sinkMBB->transferSuccessorsAndUpdatePHIs(BB);

  // Next, add the true and fallthrough blocks as its successors.
  BB->addSuccessor(copy0MBB);
  BB->addSuccessor(sinkMBB);

  BuildMI(BB, DL, TII->get(Opc2)).addReg(MI->getOperand(3).getReg())
    .addImm(MI->getOperand(4).getImm());
  BuildMI(BB, DL, TII->get(Opc1)).addMBB(sinkMBB);

  //  copy0MBB:
  //   %FalseValue = ...
  //   # fallthrough to sinkMBB
  BB = copy0MBB;

  // Update machine-CFG edges
  BB->addSuccessor(sinkMBB);

  //  sinkMBB:
  //   %Result = phi [ %TrueValue, thisMBB ], [ %FalseValue, copy0MBB ]
  //  ...
  BB = sinkMBB;

  BuildMI(*BB, BB->begin(), DL,
          TII->get(Oi::PHI), MI->getOperand(0).getReg())
    .addReg(MI->getOperand(1).getReg()).addMBB(thisMBB)
    .addReg(MI->getOperand(2).getReg()).addMBB(copy0MBB);

  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;

}

MachineBasicBlock
  *Oi16TargetLowering::emitFEXT_T8I816_ins(unsigned BtOpc, unsigned CmpOpc,
                                             MachineInstr *MI,
                                             MachineBasicBlock *BB) const {
  if (DontExpandCondPseudos16)
    return BB;
  const TargetInstrInfo *TII = getTargetMachine().getInstrInfo();
  unsigned regX = MI->getOperand(0).getReg();
  unsigned regY = MI->getOperand(1).getReg();
  MachineBasicBlock *target = MI->getOperand(2).getMBB();
  BuildMI(*BB, MI, MI->getDebugLoc(), TII->get(CmpOpc)).addReg(regX)
    .addReg(regY);
  BuildMI(*BB, MI, MI->getDebugLoc(), TII->get(BtOpc)).addMBB(target);
  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;
}

MachineBasicBlock *Oi16TargetLowering::emitFEXT_T8I8I16_ins(
  unsigned BtOpc, unsigned CmpiOpc, unsigned CmpiXOpc,
  MachineInstr *MI,  MachineBasicBlock *BB) const {
  if (DontExpandCondPseudos16)
    return BB;
  const TargetInstrInfo *TII = getTargetMachine().getInstrInfo();
  unsigned regX = MI->getOperand(0).getReg();
  int64_t imm = MI->getOperand(1).getImm();
  MachineBasicBlock *target = MI->getOperand(2).getMBB();
  unsigned CmpOpc;
  if (isUInt<8>(imm))
    CmpOpc = CmpiOpc;
  else if (isUInt<16>(imm))
    CmpOpc = CmpiXOpc;
  else
    llvm_unreachable("immediate field not usable");
  BuildMI(*BB, MI, MI->getDebugLoc(), TII->get(CmpOpc)).addReg(regX)
    .addImm(imm);
  BuildMI(*BB, MI, MI->getDebugLoc(), TII->get(BtOpc)).addMBB(target);
  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;
}

static unsigned Oi16WhichOp8uOr16simm
  (unsigned shortOp, unsigned longOp, int64_t Imm) {
  if (isUInt<8>(Imm))
    return shortOp;
  else if (isInt<16>(Imm))
    return longOp;
  else
    llvm_unreachable("immediate field not usable");
}

MachineBasicBlock *Oi16TargetLowering::emitFEXT_CCRX16_ins(
  unsigned SltOpc,
  MachineInstr *MI,  MachineBasicBlock *BB) const {
  if (DontExpandCondPseudos16)
    return BB;
  const TargetInstrInfo *TII = getTargetMachine().getInstrInfo();
  unsigned CC = MI->getOperand(0).getReg();
  unsigned regX = MI->getOperand(1).getReg();
  unsigned regY = MI->getOperand(2).getReg();
  BuildMI(*BB, MI, MI->getDebugLoc(),
		  TII->get(SltOpc)).addReg(regX).addReg(regY);
  BuildMI(*BB, MI, MI->getDebugLoc(),
          TII->get(Oi::MoveR3216), CC).addReg(Oi::T8);
  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;
}

MachineBasicBlock *Oi16TargetLowering::emitFEXT_CCRXI16_ins(
  unsigned SltiOpc, unsigned SltiXOpc,
  MachineInstr *MI,  MachineBasicBlock *BB )const {
  if (DontExpandCondPseudos16)
    return BB;
  const TargetInstrInfo *TII = getTargetMachine().getInstrInfo();
  unsigned CC = MI->getOperand(0).getReg();
  unsigned regX = MI->getOperand(1).getReg();
  int64_t Imm = MI->getOperand(2).getImm();
  unsigned SltOpc = Oi16WhichOp8uOr16simm(SltiOpc, SltiXOpc, Imm);
  BuildMI(*BB, MI, MI->getDebugLoc(),
          TII->get(SltOpc)).addReg(regX).addImm(Imm);
  BuildMI(*BB, MI, MI->getDebugLoc(),
          TII->get(Oi::MoveR3216), CC).addReg(Oi::T8);
  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;

}
