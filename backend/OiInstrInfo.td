//===- OiInstrInfo.td - Target Description for Oi Target -*- tablegen -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Oi implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//


//===----------------------------------------------------------------------===//
// Oi profiles and nodes
//===----------------------------------------------------------------------===//

def SDT_OiJmpLink      : SDTypeProfile<0, 1, [SDTCisVT<0, iPTR>]>;
def SDT_OiCMov         : SDTypeProfile<1, 4, [SDTCisSameAs<0, 1>,
                                                SDTCisSameAs<1, 2>,
                                                SDTCisSameAs<3, 4>,
                                                SDTCisInt<4>]>;
def SDT_OiCallSeqStart : SDCallSeqStart<[SDTCisVT<0, i32>]>;
def SDT_OiCallSeqEnd   : SDCallSeqEnd<[SDTCisVT<0, i32>, SDTCisVT<1, i32>]>;
def SDT_ExtractLOHI : SDTypeProfile<1, 2, [SDTCisInt<0>, SDTCisVT<1, untyped>,
                                           SDTCisVT<2, i32>]>;
def SDT_InsertLOHI : SDTypeProfile<1, 2, [SDTCisVT<0, untyped>,
                                          SDTCisVT<1, i32>, SDTCisSameAs<1, 2>]>;
def SDT_OiMultDiv : SDTypeProfile<1, 2, [SDTCisVT<0, untyped>, SDTCisInt<1>,
                                    SDTCisSameAs<1, 2>]>;
def SDT_OiMAddMSub : SDTypeProfile<1, 3,
                                     [SDTCisVT<0, untyped>, SDTCisSameAs<0, 3>,
                                      SDTCisVT<1, i32>, SDTCisSameAs<1, 2>]>;
def SDT_OiDivRem16 : SDTypeProfile<0, 2, [SDTCisInt<0>, SDTCisSameAs<0, 1>]>;

def SDT_OiThreadPointer : SDTypeProfile<1, 0, [SDTCisPtrTy<0>]>;

def SDT_Sync             : SDTypeProfile<0, 1, [SDTCisVT<0, i32>]>;

def SDT_Ext : SDTypeProfile<1, 3, [SDTCisInt<0>, SDTCisSameAs<0, 1>,
                                   SDTCisVT<2, i32>, SDTCisSameAs<2, 3>]>;
def SDT_Ins : SDTypeProfile<1, 4, [SDTCisInt<0>, SDTCisSameAs<0, 1>,
                                   SDTCisVT<2, i32>, SDTCisSameAs<2, 3>,
                                   SDTCisSameAs<0, 4>]>;

def SDTOiLoadLR  : SDTypeProfile<1, 2,
                                   [SDTCisInt<0>, SDTCisPtrTy<1>,
                                    SDTCisSameAs<0, 2>]>;

// Call
def OiJmpLink : SDNode<"OiISD::JmpLink",SDT_OiJmpLink,
                         [SDNPHasChain, SDNPOutGlue, SDNPOptInGlue,
                          SDNPVariadic]>;

// Tail call
def OiTailCall : SDNode<"OiISD::TailCall", SDT_OiJmpLink,
                          [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

// Hi and Lo nodes are used to handle global addresses. Used on
// OiISelLowering to lower stuff like GlobalAddress, ExternalSymbol
// static model. (nothing to do with Oi Registers Hi and Lo)
def OiHi    : SDNode<"OiISD::Hi", SDTIntUnaryOp>;
def OiLo    : SDNode<"OiISD::Lo", SDTIntUnaryOp>;
def OiGPRel : SDNode<"OiISD::GPRel", SDTIntUnaryOp>;

// TlsGd node is used to handle General Dynamic TLS
def OiTlsGd : SDNode<"OiISD::TlsGd", SDTIntUnaryOp>;

// TprelHi and TprelLo nodes are used to handle Local Exec TLS
def OiTprelHi    : SDNode<"OiISD::TprelHi", SDTIntUnaryOp>;
def OiTprelLo    : SDNode<"OiISD::TprelLo", SDTIntUnaryOp>;

// Thread pointer
def OiThreadPointer: SDNode<"OiISD::ThreadPointer", SDT_OiThreadPointer>;

// Return
def OiRet : SDNode<"OiISD::Ret", SDTNone,
                     [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

// These are target-independent nodes, but have target-specific formats.
def callseq_start : SDNode<"ISD::CALLSEQ_START", SDT_OiCallSeqStart,
                           [SDNPHasChain, SDNPSideEffect, SDNPOutGlue]>;
def callseq_end   : SDNode<"ISD::CALLSEQ_END", SDT_OiCallSeqEnd,
                           [SDNPHasChain, SDNPSideEffect,
                            SDNPOptInGlue, SDNPOutGlue]>;

// Node used to extract integer from LO/HI register.
def ExtractLOHI : SDNode<"OiISD::ExtractLOHI", SDT_ExtractLOHI>;

// Node used to insert 32-bit integers to LOHI register pair.
def InsertLOHI : SDNode<"OiISD::InsertLOHI", SDT_InsertLOHI>;

// Mult nodes.
def OiMult  : SDNode<"OiISD::Mult", SDT_OiMultDiv>;
def OiMultu : SDNode<"OiISD::Multu", SDT_OiMultDiv>;

// MAdd*/MSub* nodes
def OiMAdd  : SDNode<"OiISD::MAdd", SDT_OiMAddMSub>;
def OiMAddu : SDNode<"OiISD::MAddu", SDT_OiMAddMSub>;
def OiMSub  : SDNode<"OiISD::MSub", SDT_OiMAddMSub>;
def OiMSubu : SDNode<"OiISD::MSubu", SDT_OiMAddMSub>;

// DivRem(u) nodes
def OiDivRem    : SDNode<"OiISD::DivRem", SDT_OiMultDiv>;
def OiDivRemU   : SDNode<"OiISD::DivRemU", SDT_OiMultDiv>;
def OiDivRem16  : SDNode<"OiISD::DivRem16", SDT_OiDivRem16, [SDNPOutGlue]>;
def OiDivRemU16 : SDNode<"OiISD::DivRemU16", SDT_OiDivRem16,
                           [SDNPOutGlue]>;

// Target constant nodes that are not part of any isel patterns and remain
// unchanged can cause instructions with illegal operands to be emitted.
// Wrapper node patterns give the instruction selector a chance to replace
// target constant nodes that would otherwise remain unchanged with ADDiu
// nodes. Without these wrapper node patterns, the following conditional move
// instrucion is emitted when function cmov2 in test/CodeGen/Oi/cmov.ll is
// compiled:
//  movn  %got(d)($gp), %got(c)($gp), $4
// This instruction is illegal since movn can take only register operands.

def OiWrapper    : SDNode<"OiISD::Wrapper", SDTIntBinOp>;

def OiSync : SDNode<"OiISD::Sync", SDT_Sync, [SDNPHasChain,SDNPSideEffect]>;

def OiExt :  SDNode<"OiISD::Ext", SDT_Ext>;
def OiIns :  SDNode<"OiISD::Ins", SDT_Ins>;

def OiLWL : SDNode<"OiISD::LWL", SDTOiLoadLR,
                     [SDNPHasChain, SDNPMayLoad, SDNPMemOperand]>;
def OiLWR : SDNode<"OiISD::LWR", SDTOiLoadLR,
                     [SDNPHasChain, SDNPMayLoad, SDNPMemOperand]>;
def OiSWL : SDNode<"OiISD::SWL", SDTStore,
                     [SDNPHasChain, SDNPMayStore, SDNPMemOperand]>;
def OiSWR : SDNode<"OiISD::SWR", SDTStore,
                     [SDNPHasChain, SDNPMayStore, SDNPMemOperand]>;
def OiLDL : SDNode<"OiISD::LDL", SDTOiLoadLR,
                     [SDNPHasChain, SDNPMayLoad, SDNPMemOperand]>;
def OiLDR : SDNode<"OiISD::LDR", SDTOiLoadLR,
                     [SDNPHasChain, SDNPMayLoad, SDNPMemOperand]>;
def OiSDL : SDNode<"OiISD::SDL", SDTStore,
                     [SDNPHasChain, SDNPMayStore, SDNPMemOperand]>;
def OiSDR : SDNode<"OiISD::SDR", SDTStore,
                     [SDNPHasChain, SDNPMayStore, SDNPMemOperand]>;

//===----------------------------------------------------------------------===//
// Oi Instruction Predicate Definitions.
//===----------------------------------------------------------------------===//
def HasSEInReg  :     Predicate<"Subtarget.hasSEInReg()">,
                      AssemblerPredicate<"FeatureSEInReg">;
def HasBitCount :     Predicate<"Subtarget.hasBitCount()">,
                      AssemblerPredicate<"FeatureBitCount">;
def HasSwap     :     Predicate<"Subtarget.hasSwap()">,
                      AssemblerPredicate<"FeatureSwap">;
def HasCondMov  :     Predicate<"Subtarget.hasCondMov()">,
                      AssemblerPredicate<"FeatureCondMov">;
def HasFPIdx    :     Predicate<"Subtarget.hasFPIdx()">,
                      AssemblerPredicate<"FeatureFPIdx">;
def HasOi32    :    Predicate<"Subtarget.hasOi32()">,
                      AssemblerPredicate<"FeatureOi32">;
def HasOi32r2  :    Predicate<"Subtarget.hasOi32r2()">,
                      AssemblerPredicate<"FeatureOi32r2">;
def HasOi64    :    Predicate<"Subtarget.hasOi64()">,
                      AssemblerPredicate<"FeatureOi64">;
def NotOi64    :    Predicate<"!Subtarget.hasOi64()">,
                      AssemblerPredicate<"!FeatureOi64">;
def HasOi64r2  :    Predicate<"Subtarget.hasOi64r2()">,
                      AssemblerPredicate<"FeatureOi64r2">;
def IsN64       :     Predicate<"Subtarget.isABI_N64()">,
                      AssemblerPredicate<"FeatureN64">;
def NotN64      :     Predicate<"!Subtarget.isABI_N64()">,
                      AssemblerPredicate<"!FeatureN64">;
def InOi16Mode :    Predicate<"Subtarget.inOi16Mode()">,
                      AssemblerPredicate<"FeatureOi16">;
def RelocStatic :     Predicate<"TM.getRelocationModel() == Reloc::Static">,
                      AssemblerPredicate<"FeatureOi32">;
def RelocPIC    :     Predicate<"TM.getRelocationModel() == Reloc::PIC_">,
                      AssemblerPredicate<"FeatureOi32">;
def NoNaNsFPMath :    Predicate<"TM.Options.NoNaNsFPMath">,
                      AssemblerPredicate<"FeatureOi32">;
def HasStdEnc :       Predicate<"Subtarget.hasStandardEncoding()">,
                      AssemblerPredicate<"!FeatureOi16">;
def NotDSP :          Predicate<"!Subtarget.hasDSP()">;

class OiPat<dag pattern, dag result> : Pat<pattern, result> {
  let Predicates = [HasStdEnc];
}

class IsCommutable {
  bit isCommutable = 1;
}

class IsBranch {
  bit isBranch = 1;
}

class IsReturn {
  bit isReturn = 1;
}

class IsCall {
  bit isCall = 1;
}

class IsTailCall {
  bit isCall = 1;
  bit isTerminator = 1;
  bit isReturn = 1;
  bit isBarrier = 1;
  bit hasExtraSrcRegAllocReq = 1;
  bit isCodeGenOnly = 1;
}

class IsAsCheapAsAMove {
  bit isAsCheapAsAMove = 1;
}

class NeverHasSideEffects {
  bit neverHasSideEffects = 1;
}

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "OiInstrFormats.td"

//===----------------------------------------------------------------------===//
// Oi Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

// Instruction operand types
def jmptarget   : Operand<OtherVT> {
  let EncoderMethod = "getJumpTargetOpValue";
}
def brtarget    : Operand<OtherVT> {
  let EncoderMethod = "getBranchTargetOpValue";
  let OperandType = "OPERAND_PCREL";
  let DecoderMethod = "DecodeBranchTarget";
}
def calltarget  : Operand<iPTR> {
  let EncoderMethod = "getJumpTargetOpValue";
}
def calltarget64: Operand<i64>;
def simm16      : Operand<i32> {
  let DecoderMethod= "DecodeSimm16";
}

def simm32      : Operand<i32> {
}

def simm20      : Operand<i32> {
}

def simm16_64   : Operand<i64>;
def shamt       : Operand<i32>;

// Unsigned Operand
def uimm16      : Operand<i32> {
  let PrintMethod = "printUnsignedImm";
}

def uimm32      : Operand<i32> {
}


def OiMemAsmOperand : AsmOperandClass {
  let Name = "Mem";
  let ParserMethod = "parseMemOperand";
}

// Address operand
def mem : Operand<i32> {
  let PrintMethod = "printMemOperand";
  let MIOperandInfo = (ops CPURegs, simm32);
  let EncoderMethod = "getMemEncoding";
  let ParserMatchClass = OiMemAsmOperand;
  let OperandType = "OPERAND_MEMORY";
}

def mem64 : Operand<i64> {
  let PrintMethod = "printMemOperand";
  let MIOperandInfo = (ops CPU64Regs, simm16_64);
  let EncoderMethod = "getMemEncoding";
  let ParserMatchClass = OiMemAsmOperand;
  let OperandType = "OPERAND_MEMORY";
}

def mem_ea : Operand<i32> {
  let PrintMethod = "printMemOperandEA";
  let MIOperandInfo = (ops CPURegs, simm32);
  let EncoderMethod = "getMemEncoding";
  let OperandType = "OPERAND_MEMORY";
}

def mem_ea_64 : Operand<i64> {
  let PrintMethod = "printMemOperandEA";
  let MIOperandInfo = (ops CPU64Regs, simm16_64);
  let EncoderMethod = "getMemEncoding";
  let OperandType = "OPERAND_MEMORY";
}

// size operand of ext instruction
def size_ext : Operand<i32> {
  let EncoderMethod = "getSizeExtEncoding";
  let DecoderMethod = "DecodeExtSize";
}

// size operand of ins instruction
def size_ins : Operand<i32> {
  let EncoderMethod = "getSizeInsEncoding";
  let DecoderMethod = "DecodeInsSize";
}

// Transformation Function - get the lower 16 bits.
def LO16 : SDNodeXForm<imm, [{
  return getImm(N, N->getZExtValue() & 0xFFFF);
}]>;

// Transformation Function - get the higher 16 bits.
def HI16 : SDNodeXForm<imm, [{
  return getImm(N, (N->getZExtValue() >> 16) & 0xFFFF);
}]>;

// Plus 1.
def Plus1 : SDNodeXForm<imm, [{ return getImm(N, N->getSExtValue() + 1); }]>;

// Node immediate fits as 16-bit sign extended on target immediate.
// e.g. addi, andi
def immSExt8  : PatLeaf<(imm), [{ return isInt<8>(N->getSExtValue()); }]>;

// Node immediate fits as 16-bit sign extended on target immediate.
// e.g. addi, andi
def immSExt16  : PatLeaf<(imm), [{ return isInt<16>(N->getSExtValue()); }]>;

def immSExt32  : PatLeaf<(imm), [{ return isInt<32>(N->getSExtValue()); }]>;


// Node immediate fits as 15-bit sign extended on target immediate.
// e.g. addi, andi
def immSExt15  : PatLeaf<(imm), [{ return isInt<15>(N->getSExtValue()); }]>;

// Node immediate fits as 16-bit zero extended on target immediate.
// The LO16 param means that only the lower 16 bits of the node
// immediate are caught.
// e.g. addiu, sltiu
def immZExt16  : PatLeaf<(imm), [{
  if (N->getValueType(0) == MVT::i32)
    return (uint32_t)N->getZExtValue() == (unsigned short)N->getZExtValue();
  else
    return (uint64_t)N->getZExtValue() == (unsigned short)N->getZExtValue();
}], LO16>;

def immZExt32  : PatLeaf<(imm), [{
  if (N->getValueType(0) == MVT::i32)
    return (uint32_t)N->getZExtValue() == (unsigned)N->getZExtValue();
  else
    return (uint64_t)N->getZExtValue() == (unsigned)N->getZExtValue();
}]>;

// Immediate can be loaded with LUi (32-bit int with lower 16-bit cleared).
def immLow16Zero : PatLeaf<(imm), [{
  int64_t Val = N->getSExtValue();
  return isInt<32>(Val) && !(Val & 0xffff);
}]>;

// shamt field must fit in 5 bits.
def immZExt5 : ImmLeaf<i32, [{return Imm == (Imm & 0x1f);}]>;

// True if (N + 1) fits in 16-bit field.
def immSExt16Plus1 : PatLeaf<(imm), [{
  return isInt<17>(N->getSExtValue()) && isInt<16>(N->getSExtValue() + 1);
}]>;

// Oi Address Mode! SDNode frameindex could possibily be a match
// since load and store instructions from stack used it.
def addr :
  ComplexPattern<iPTR, 2, "selectIntAddr", [frameindex]>;

def addrRegImm :
  ComplexPattern<iPTR, 2, "selectAddrRegImm", [frameindex]>;

def addrDefault :
  ComplexPattern<iPTR, 2, "selectAddrDefault", [frameindex]>;

//===----------------------------------------------------------------------===//
// Instructions specific format
//===----------------------------------------------------------------------===//

// Arithmetic and logical instructions with 3 register operands.
class ArithLogicR<string opstr, RegisterOperand RO, bit isComm = 0,
                  InstrItinClass Itin = NoItinerary,
                  SDPatternOperator OpNode = null_frag>:
  InstSE<(outs RO:$rd), (ins RO:$rs, RO:$rt),
         !strconcat(opstr, "\t$rd, $rs, $rt"),
         [(set RO:$rd, (OpNode RO:$rs, RO:$rt))], Itin, FrmR, opstr> {
  let isCommutable = isComm;
  let isReMaterializable = 1;
}

// Arithmetic and logical instructions with 2 register operands.
class ArithLogicI<string opstr, Operand Od, RegisterOperand RO,
                  SDPatternOperator imm_type = null_frag,
                  SDPatternOperator OpNode = null_frag> :
  InstSE<(outs RO:$rt), (ins RO:$rs, Od:$imm32),
         !strconcat(opstr, "\t$rt, $rs, $imm32"),
         [(set RO:$rt, (OpNode RO:$rs, imm_type:$imm32))],
         IIAlu, FrmI, opstr> {
  let isReMaterializable = 1;
}

// Arithmetic Multiply ADD/SUB
class MArithR<string opstr, bit isComm = 0> :
  InstSE<(outs), (ins CPURegsOpnd:$rs, CPURegsOpnd:$rt),
         !strconcat(opstr, "\t$rs, $rt"), [], IIImul, FrmR> {
  let Defs = [HI, LO];
  let Uses = [HI, LO];
  let isCommutable = isComm;
}

//  Logical
class LogicNOR<string opstr, RegisterOperand RC>:
  InstSE<(outs RC:$rd), (ins RC:$rs, RC:$rt),
         !strconcat(opstr, "\t$rd, $rs, $rt"),
         [(set RC:$rd, (not (or RC:$rs, RC:$rt)))], IIAlu, FrmR, opstr> {
  let isCommutable = 1;
}

// Shifts
class shift_rotate_imm<string opstr, Operand ImmOpnd,
                       RegisterOperand RC, SDPatternOperator OpNode = null_frag,
                       SDPatternOperator PF = null_frag> :
  InstSE<(outs RC:$rd), (ins RC:$rt, ImmOpnd:$shamt),
         !strconcat(opstr, "\t$rd, $rt, $shamt"),
         [(set RC:$rd, (OpNode RC:$rt, PF:$shamt))], IIAlu, FrmR, opstr>;

class shift_rotate_reg<string opstr, RegisterOperand RC,
                       SDPatternOperator OpNode = null_frag>:
  InstSE<(outs RC:$rd), (ins CPURegsOpnd:$rs, RC:$rt),
         !strconcat(opstr, "\t$rd, $rt, $rs"),
         [(set RC:$rd, (OpNode RC:$rt, CPURegsOpnd:$rs))], IIAlu, FrmR, opstr>;

// Load Upper Imediate
class LoadUpper<string opstr, RegisterClass RC, Operand Imm>:
  InstSE<(outs RC:$rt), (ins Imm:$imm16), !strconcat(opstr, "\t$rt, $imm16"),
         [], IIAlu, FrmI>, IsAsCheapAsAMove {
  let neverHasSideEffects = 1;
  let isReMaterializable = 1;
}

class FMem<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern,
          InstrItinClass itin>: FFI<op, outs, ins, asmstr, pattern> {
  bits<39> addr;
  let Inst{57-51} = addr{38-32};
  let Inst{31-0}  = addr{31-0};
  let DecoderMethod = "DecodeMem";
}

// Memory Load/Store
class Load<string opstr, SDPatternOperator OpNode, RegisterClass RC,
           Operand MemOpnd, ComplexPattern Addr, string ofsuffix> :
  InstSE<(outs RC:$rt), (ins MemOpnd:$addr), !strconcat(opstr, "\t$rt, $addr"),
         [(set RC:$rt, (OpNode Addr:$addr))], NoItinerary, FrmI,
         !strconcat(opstr, ofsuffix)> {
  let DecoderMethod = "DecodeMem";
  let canFoldAsLoad = 1;
  let mayLoad = 1;
}

class Store<string opstr, SDPatternOperator OpNode, RegisterClass RC,
            Operand MemOpnd, ComplexPattern Addr, string ofsuffix> :
  InstSE<(outs), (ins RC:$rt, MemOpnd:$addr), !strconcat(opstr, "\t$rt, $addr"),
         [(OpNode RC:$rt, Addr:$addr)], NoItinerary, FrmI,
         !strconcat(opstr, ofsuffix)> {
  let DecoderMethod = "DecodeMem";
  let mayStore = 1;
}

multiclass LoadM<string opstr, RegisterClass RC,
                 SDPatternOperator OpNode = null_frag,
                 ComplexPattern Addr = addr> {
  def NAME : Load<opstr, OpNode, RC, mem, Addr, "">,
             Requires<[NotN64, HasStdEnc]>;
  def _P8  : Load<opstr, OpNode, RC, mem64, Addr, "_p8">,
             Requires<[IsN64, HasStdEnc]> {
    let DecoderNamespace = "Oi64";
    let isCodeGenOnly = 1;
  }
}

multiclass StoreM<string opstr, RegisterClass RC,
                  SDPatternOperator OpNode = null_frag,
                  ComplexPattern Addr = addr> {
  def NAME : Store<opstr, OpNode, RC, mem, Addr, "">,
             Requires<[NotN64, HasStdEnc]>;
  def _P8  : Store<opstr, OpNode, RC, mem64, Addr, "_p8">,
             Requires<[IsN64, HasStdEnc]> {
    let DecoderNamespace = "Oi64";
    let isCodeGenOnly = 1;
  }
}

// Load/Store Left/Right
let canFoldAsLoad = 1 in
class LoadLeftRight<string opstr, SDNode OpNode, RegisterClass RC,
                    Operand MemOpnd> :
  InstSE<(outs RC:$rt), (ins MemOpnd:$addr, RC:$src),
         !strconcat(opstr, "\t$rt, $addr"),
         [(set RC:$rt, (OpNode addr:$addr, RC:$src))], NoItinerary, FrmI> {
  let DecoderMethod = "DecodeMem";
  string Constraints = "$src = $rt";
}

class StoreLeftRight<string opstr, SDNode OpNode, RegisterClass RC,
                     Operand MemOpnd>:
  InstSE<(outs), (ins RC:$rt, MemOpnd:$addr), !strconcat(opstr, "\t$rt, $addr"),
         [(OpNode RC:$rt, addr:$addr)], NoItinerary, FrmI> {
  let DecoderMethod = "DecodeMem";
}

multiclass LoadLeftRightM<string opstr, SDNode OpNode, RegisterClass RC> {
  def NAME : LoadLeftRight<opstr, OpNode, RC, mem>,
             Requires<[NotN64, HasStdEnc]>;
  def _P8  : LoadLeftRight<opstr, OpNode, RC, mem64>,
             Requires<[IsN64, HasStdEnc]> {
    let DecoderNamespace = "Oi64";
    let isCodeGenOnly = 1;
  }
}

multiclass StoreLeftRightM<string opstr, SDNode OpNode, RegisterClass RC> {
  def NAME : StoreLeftRight<opstr, OpNode, RC, mem>,
             Requires<[NotN64, HasStdEnc]>;
  def _P8  : StoreLeftRight<opstr, OpNode, RC, mem64>,
             Requires<[IsN64, HasStdEnc]> {
    let DecoderNamespace = "Oi64";
    let isCodeGenOnly = 1;
  }
}

// Conditional Branch
class CBranch<string opstr, PatFrag cond_op, RegisterClass RC> :
  InstSE<(outs), (ins RC:$rs, RC:$rt, brtarget:$offset),
         !strconcat(opstr, "\t$rs, $rt, $offset"),
         [(brcond (i32 (cond_op RC:$rs, RC:$rt)), bb:$offset)], IIBranch,
         FrmI> {
  let isBranch = 1;
  let isTerminator = 1;
  let hasDelaySlot = 0;
  let Defs = [AT];
}

class CBranchZero<string opstr, PatFrag cond_op, RegisterClass RC> :
  InstSE<(outs), (ins RC:$rs, brtarget:$offset),
         !strconcat(opstr, "\t$rs, $offset"),
         [(brcond (i32 (cond_op RC:$rs, 0)), bb:$offset)], IIBranch, FrmI> {
  let isBranch = 1;
  let isTerminator = 1;
  let hasDelaySlot = 0;
  let Defs = [AT];
}

// SetCC
class SetCC_R<string opstr, PatFrag cond_op, RegisterClass RC> :
  InstSE<(outs CPURegsOpnd:$rd), (ins RC:$rs, RC:$rt),
         !strconcat(opstr, "\t$rd, $rs, $rt"),
         [(set CPURegsOpnd:$rd, (cond_op RC:$rs, RC:$rt))],
         IIAlu, FrmR, opstr>;

class SetCC_I<string opstr, PatFrag cond_op, Operand Od, PatLeaf imm_type,
              RegisterClass RC>:
  InstSE<(outs CPURegsOpnd:$rt), (ins RC:$rs, Od:$imm32),
         !strconcat(opstr, "\t$rt, $rs, $imm32"),
         [(set CPURegsOpnd:$rt, (cond_op RC:$rs, imm_type:$imm32))],
         IIAlu, FrmI, opstr>;

// Jump
class JumpFJ<DAGOperand opnd, string opstr, SDPatternOperator operator,
             SDPatternOperator targetoperator> :
  InstSE<(outs), (ins opnd:$target), !strconcat(opstr, "\t$target"),
         [(operator targetoperator:$target)], IIBranch, FrmJ> {
  let isTerminator=1;
  let isBarrier=1;
  let hasDelaySlot = 0;
  let DecoderMethod = "DecodeJumpTarget";
  let Defs = [AT];
}

// Unconditional branch
class UncondBranch<string opstr> :
  InstSE<(outs), (ins brtarget:$offset), !strconcat(opstr, "\t$offset"),
         [(br bb:$offset)], IIBranch, FrmI> {
  let isBranch = 1;
  let isTerminator = 1;
  let isBarrier = 1;
  let hasDelaySlot = 0;
  let Predicates = [RelocPIC, HasStdEnc];
  let Defs = [AT];
}

// Base class for indirect branch and return instruction classes.
let isTerminator=1, isBarrier=1, hasDelaySlot = 0 in
class JumpFR<RegisterClass RC, SDPatternOperator operator = null_frag>:
  InstSE<(outs), (ins RC:$rs), "jr\t$rs", [(operator RC:$rs)], IIBranch, FrmR>;

// Indirect branch
class IndirectBranch<RegisterClass RC>: JumpFR<RC, brind> {
  let isBranch = 1;
  let isIndirectBranch = 1;
}

// Return instruction
class RetBase<RegisterClass RC>: JumpFR<RC> {
  let isReturn = 1;
  let isCodeGenOnly = 1;
  let hasCtrlDep = 1;
  let hasExtraSrcRegAllocReq = 1;
}

// Jump and Link (Call)
let isCall=1, hasDelaySlot=0, Defs = [RA] in {
  class JumpLink<string opstr> :
    InstSE<(outs), (ins calltarget:$target), !strconcat(opstr, "\t$target"),
           [(OiJmpLink imm:$target)], IIBranch, FrmJ> {
    let DecoderMethod = "DecodeJumpTarget";
  }

  class JumpLinkRegPseudo<RegisterClass RC, Instruction JALRInst,
                          Register RetReg>:
    PseudoSE<(outs), (ins RC:$rs), [(OiJmpLink RC:$rs)], IIBranch>,
    PseudoInstExpansion<(JALRInst RetReg, RC:$rs)>;

  class JumpLinkReg<string opstr, RegisterClass RC>:
    InstSE<(outs RC:$rd), (ins RC:$rs), !strconcat(opstr, "\t$rd, $rs"),
           [], IIBranch, FrmR>;

  class BGEZAL_FT<string opstr, RegisterOperand RO> :
    InstSE<(outs), (ins RO:$rs, brtarget:$offset),
           !strconcat(opstr, "\t$rs, $offset"), [], IIBranch, FrmI>;

}

class BAL_FT :
  InstSE<(outs), (ins brtarget:$offset), "bal\t$offset", [], IIBranch, FrmI> {
  let isBranch = 1;
  let isTerminator = 1;
  let isBarrier = 1;
  let hasDelaySlot = 0;
  let Defs = [RA];
}

// Sync
let hasSideEffects = 1 in
class SYNC_FT :
  InstSE<(outs), (ins i32imm:$stype), "sync $stype", [(OiSync imm:$stype)],
         NoItinerary, FrmOther>;

// Mul, Div
class Mult<string opstr, InstrItinClass itin, RegisterOperand RO,
           list<Register> DefRegs> :
  InstSE<(outs), (ins RO:$rs, RO:$rt), !strconcat(opstr, "\t$rs, $rt"), [],
         itin, FrmR, opstr> {
  let isCommutable = 1;
  let Defs = DefRegs;
  let neverHasSideEffects = 1;
}

// Pseudo multiply/divide instruction with explicit accumulator register
// operands.
class MultDivPseudo<Instruction RealInst, RegisterClass R0, RegisterOperand R1,
                    SDPatternOperator OpNode, InstrItinClass Itin,
                    bit IsComm = 1, bit HasSideEffects = 0> :
  PseudoSE<(outs R0:$ac), (ins R1:$rs, R1:$rt),
           [(set R0:$ac, (OpNode R1:$rs, R1:$rt))], Itin>,
  PseudoInstExpansion<(RealInst R1:$rs, R1:$rt)> {
  let isCommutable = IsComm;
  let hasSideEffects = HasSideEffects;
}

// Pseudo multiply add/sub instruction with explicit accumulator register
// operands.
class MAddSubPseudo<Instruction RealInst, SDPatternOperator OpNode>
  : PseudoSE<(outs ACRegs:$ac),
             (ins CPURegsOpnd:$rs, CPURegsOpnd:$rt, ACRegs:$acin),
             [(set ACRegs:$ac,
              (OpNode CPURegsOpnd:$rs, CPURegsOpnd:$rt, ACRegs:$acin))],
             IIImul>,
    PseudoInstExpansion<(RealInst CPURegsOpnd:$rs, CPURegsOpnd:$rt)> {
  string Constraints = "$acin = $ac";
}

class Div<string opstr, InstrItinClass itin, RegisterOperand RO,
          list<Register> DefRegs> :
  InstSE<(outs), (ins RO:$rs, RO:$rt), !strconcat(opstr, "\t$rs, $rt"),
         [], itin, FrmR> {
  let Defs = DefRegs;
}

// Move from Hi/Lo
class MoveFromLOHI<string opstr, RegisterClass RC, list<Register> UseRegs>:
  InstSE<(outs RC:$rd), (ins), !strconcat(opstr, "\t$rd"), [], IIHiLo, FrmR> {
  let Uses = UseRegs;
  let neverHasSideEffects = 1;
}

class MoveToLOHI<string opstr, RegisterClass RC, list<Register> DefRegs>:
  InstSE<(outs), (ins RC:$rs), !strconcat(opstr, "\t$rs"), [], IIHiLo, FrmR> {
  let Defs = DefRegs;
  let neverHasSideEffects = 1;
}

class EffectiveAddress<string opstr, RegisterClass RC, Operand Mem> :
  InstSE<(outs RC:$rt), (ins Mem:$addr), !strconcat(opstr, "\t$rt, $addr"),
         [(set RC:$rt, addr:$addr)], NoItinerary, FrmI> {
  let isCodeGenOnly = 1;
  let DecoderMethod = "DecodeMem";
}

// Count Leading Ones/Zeros in Word
class CountLeading0<string opstr, RegisterOperand RO>:
  InstSE<(outs RO:$rd), (ins RO:$rs), !strconcat(opstr, "\t$rd, $rs"),
         [(set RO:$rd, (ctlz RO:$rs))], IIAlu, FrmR>,
  Requires<[HasBitCount, HasStdEnc]>;

class CountLeading1<string opstr, RegisterOperand RO>:
  InstSE<(outs RO:$rd), (ins RO:$rs), !strconcat(opstr, "\t$rd, $rs"),
         [(set RO:$rd, (ctlz (not RO:$rs)))], IIAlu, FrmR>,
  Requires<[HasBitCount, HasStdEnc]>;


// Sign Extend in Register.
class SignExtInReg<string opstr, ValueType vt, RegisterClass RC> :
  InstSE<(outs RC:$rd), (ins RC:$rt), !strconcat(opstr, "\t$rd, $rt"),
         [(set RC:$rd, (sext_inreg RC:$rt, vt))], NoItinerary, FrmR> {
  let Predicates = [HasSEInReg, HasStdEnc];
}

// Subword Swap
class SubwordSwap<string opstr, RegisterOperand RO>:
  InstSE<(outs RO:$rd), (ins RO:$rt), !strconcat(opstr, "\t$rd, $rt"), [],
         NoItinerary, FrmR> {
  let Predicates = [HasSwap, HasStdEnc];
  let neverHasSideEffects = 1;
}

// Read Hardware
class ReadHardware<RegisterClass CPURegClass, RegisterOperand RO> :
  InstSE<(outs CPURegClass:$rt), (ins RO:$rd), "rdhwr\t$rt, $rd", [],
         IIAlu, FrmR>;

// Ext and Ins
class ExtBase<string opstr, RegisterOperand RO>:
  InstSE<(outs RO:$rt), (ins RO:$rs, uimm32:$pos, size_ext:$size),
         !strconcat(opstr, " $rt, $rs, $pos, $size"),
         [(set RO:$rt, (OiExt RO:$rs, imm:$pos, imm:$size))], NoItinerary,
         FrmR> {
  let Predicates = [HasOi32r2, HasStdEnc];
}

class InsBase<string opstr, RegisterOperand RO>:
  InstSE<(outs RO:$rt), (ins RO:$rs, uimm32:$pos, size_ins:$size, RO:$src),
         !strconcat(opstr, " $rt, $rs, $pos, $size"),
         [(set RO:$rt, (OiIns RO:$rs, imm:$pos, imm:$size, RO:$src))],
         NoItinerary, FrmR> {
  let Predicates = [HasOi32r2, HasStdEnc];
  let Constraints = "$src = $rt";
}

// Atomic instructions with 2 source operands (ATOMIC_SWAP & ATOMIC_LOAD_*).
class Atomic2Ops<PatFrag Op, RegisterClass DRC, RegisterClass PRC> :
  PseudoSE<(outs DRC:$dst), (ins PRC:$ptr, DRC:$incr),
           [(set DRC:$dst, (Op PRC:$ptr, DRC:$incr))]>;

multiclass Atomic2Ops32<PatFrag Op> {
  def NAME : Atomic2Ops<Op, CPURegs, CPURegs>, Requires<[NotN64, HasStdEnc]>;
  def _P8  : Atomic2Ops<Op, CPURegs, CPU64Regs>,
             Requires<[IsN64, HasStdEnc]> {
    let DecoderNamespace = "Oi64";
  }
}

// Atomic Compare & Swap.
class AtomicCmpSwap<PatFrag Op, RegisterClass DRC, RegisterClass PRC> :
  PseudoSE<(outs DRC:$dst), (ins PRC:$ptr, DRC:$cmp, DRC:$swap),
           [(set DRC:$dst, (Op PRC:$ptr, DRC:$cmp, DRC:$swap))]>;

multiclass AtomicCmpSwap32<PatFrag Op>  {
  def NAME : AtomicCmpSwap<Op, CPURegs, CPURegs>,
             Requires<[NotN64, HasStdEnc]>;
  def _P8  : AtomicCmpSwap<Op, CPURegs, CPU64Regs>,
             Requires<[IsN64, HasStdEnc]> {
    let DecoderNamespace = "Oi64";
  }
}

class LLBase<string opstr, RegisterOperand RO, Operand Mem> :
  InstSE<(outs RO:$rt), (ins Mem:$addr), !strconcat(opstr, "\t$rt, $addr"),
         [], NoItinerary, FrmI> {
  let DecoderMethod = "DecodeMem";
  let mayLoad = 1;
}

class SCBase<string opstr, RegisterOperand RO, Operand Mem> :
  InstSE<(outs RO:$dst), (ins RO:$rt, Mem:$addr),
         !strconcat(opstr, "\t$rt, $addr"), [], NoItinerary, FrmI> {
  let DecoderMethod = "DecodeMem";
  let mayStore = 1;
  let Constraints = "$rt = $dst";
}

class MFC3OP<dag outs, dag ins, string asmstr> :
  InstSE<outs, ins, asmstr, [], NoItinerary, FrmFR>;

//===----------------------------------------------------------------------===//
// Pseudo instructions
//===----------------------------------------------------------------------===//

// Return RA.
let isReturn=1, isTerminator=1, hasDelaySlot=0, isBarrier=1, hasCtrlDep=1 in
def RetRA : PseudoSE<(outs), (ins), [(OiRet)]>;

let Defs = [SP], Uses = [SP], hasSideEffects = 1 in {
def ADJCALLSTACKDOWN : OiPseudo<(outs), (ins i32imm:$amt),
                                  [(callseq_start timm:$amt)]>;
def ADJCALLSTACKUP   : OiPseudo<(outs), (ins i32imm:$amt1, i32imm:$amt2),
                                  [(callseq_end timm:$amt1, timm:$amt2)]>;
}

let usesCustomInserter = 1 in {
  defm ATOMIC_LOAD_ADD_I8   : Atomic2Ops32<atomic_load_add_8>;
  defm ATOMIC_LOAD_ADD_I16  : Atomic2Ops32<atomic_load_add_16>;
  defm ATOMIC_LOAD_ADD_I32  : Atomic2Ops32<atomic_load_add_32>;
  defm ATOMIC_LOAD_SUB_I8   : Atomic2Ops32<atomic_load_sub_8>;
  defm ATOMIC_LOAD_SUB_I16  : Atomic2Ops32<atomic_load_sub_16>;
  defm ATOMIC_LOAD_SUB_I32  : Atomic2Ops32<atomic_load_sub_32>;
  defm ATOMIC_LOAD_AND_I8   : Atomic2Ops32<atomic_load_and_8>;
  defm ATOMIC_LOAD_AND_I16  : Atomic2Ops32<atomic_load_and_16>;
  defm ATOMIC_LOAD_AND_I32  : Atomic2Ops32<atomic_load_and_32>;
  defm ATOMIC_LOAD_OR_I8    : Atomic2Ops32<atomic_load_or_8>;
  defm ATOMIC_LOAD_OR_I16   : Atomic2Ops32<atomic_load_or_16>;
  defm ATOMIC_LOAD_OR_I32   : Atomic2Ops32<atomic_load_or_32>;
  defm ATOMIC_LOAD_XOR_I8   : Atomic2Ops32<atomic_load_xor_8>;
  defm ATOMIC_LOAD_XOR_I16  : Atomic2Ops32<atomic_load_xor_16>;
  defm ATOMIC_LOAD_XOR_I32  : Atomic2Ops32<atomic_load_xor_32>;
  defm ATOMIC_LOAD_NAND_I8  : Atomic2Ops32<atomic_load_nand_8>;
  defm ATOMIC_LOAD_NAND_I16 : Atomic2Ops32<atomic_load_nand_16>;
  defm ATOMIC_LOAD_NAND_I32 : Atomic2Ops32<atomic_load_nand_32>;

  defm ATOMIC_SWAP_I8       : Atomic2Ops32<atomic_swap_8>;
  defm ATOMIC_SWAP_I16      : Atomic2Ops32<atomic_swap_16>;
  defm ATOMIC_SWAP_I32      : Atomic2Ops32<atomic_swap_32>;

  defm ATOMIC_CMP_SWAP_I8   : AtomicCmpSwap32<atomic_cmp_swap_8>;
  defm ATOMIC_CMP_SWAP_I16  : AtomicCmpSwap32<atomic_cmp_swap_16>;
  defm ATOMIC_CMP_SWAP_I32  : AtomicCmpSwap32<atomic_cmp_swap_32>;
}

/// Pseudo instructions for loading and storing accumulator registers.
let isPseudo = 1 in {
  defm LOAD_AC64  : LoadM<"load_ac64", ACRegs>;
  defm STORE_AC64 : StoreM<"store_ac64", ACRegs>;
}

//===----------------------------------------------------------------------===//
// Instruction definition
//===----------------------------------------------------------------------===//
//===----------------------------------------------------------------------===//
// OiI Instructions
//===----------------------------------------------------------------------===//

/// Arithmetic Instructions (ALU Immediate)
def ADDiu : MMRel, ArithLogicI<"addiu", simm32, CPURegsOpnd, immSExt32, add>,
            ADDI_FM<0x9>, IsAsCheapAsAMove;
def ADDi  : MMRel, ArithLogicI<"addi", simm32, CPURegsOpnd>, ADDI_FM<0x8>;
def SLTi  : MMRel, SetCC_I<"slti", setlt, simm32, immSExt32, CPURegs>,
            SLTI_FM<0xa>;
def SLTiu : MMRel, SetCC_I<"sltiu", setult, simm32, immSExt32, CPURegs>,
            SLTI_FM<0xb>;
def ANDi  : MMRel, ArithLogicI<"andi", uimm32, CPURegsOpnd, immZExt32, and>,
            ADDI_FM<0xc>;
def ORi   : MMRel, ArithLogicI<"ori", uimm32, CPURegsOpnd, immZExt32, or>,
            ADDI_FM<0xd>;
def XORi  : MMRel, ArithLogicI<"xori", uimm32, CPURegsOpnd, immZExt32, xor>,
            ADDI_FM<0xe>;
def LUi   : MMRel, LoadUpper<"lui", CPURegs, uimm32>, LUI_FM;

/// Arithmetic Instructions (3-Operand, R-Type)
def SYSCALL: InstSE<(outs ), (ins ), "syscall", [], NoItinerary, 
    FrmR, "syscall">, SYSCALL_FM;

def ADDu  : MMRel, ArithLogicR<"addu", CPURegsOpnd, 1, IIAlu, add>,
            ADD_FM<0, 0x21>;
def SUBu  : MMRel, ArithLogicR<"subu", CPURegsOpnd, 0, IIAlu, sub>,
            ADD_FM<0, 0x23>;
def MUL   : MMRel, ArithLogicR<"mul", CPURegsOpnd, 1, IIImul, mul>,
            ADD_FM<0x1c, 2>;
def ADD   : MMRel, ArithLogicR<"add", CPURegsOpnd>, ADD_FM<0, 0x20>;
def SUB   : MMRel, ArithLogicR<"sub", CPURegsOpnd>, ADD_FM<0, 0x22>;
def SLT   : MMRel, SetCC_R<"slt", setlt, CPURegs>, ADD_FM<0, 0x2a>;
def SLTu  : MMRel, SetCC_R<"sltu", setult, CPURegs>, ADD_FM<0, 0x2b>;
def AND   : MMRel, ArithLogicR<"and", CPURegsOpnd, 1, IIAlu, and>,
            ADD_FM<0, 0x24>;
def OR    : MMRel, ArithLogicR<"or", CPURegsOpnd, 1, IIAlu, or>,
            ADD_FM<0, 0x25>;
def XOR   : MMRel, ArithLogicR<"xor", CPURegsOpnd, 1, IIAlu, xor>,
            ADD_FM<0, 0x26>;
def NOR   : MMRel, LogicNOR<"nor", CPURegsOpnd>, ADD_FM<0, 0x27>;

/// Shift Instructions
def SLL  : MMRel, shift_rotate_imm<"sll", shamt, CPURegsOpnd, shl, immZExt5>,
           SRA_FM<0, 0>;
def SRL  : MMRel, shift_rotate_imm<"srl", shamt, CPURegsOpnd, srl, immZExt5>,
           SRA_FM<2, 0>;
def SRA  : MMRel, shift_rotate_imm<"sra", shamt, CPURegsOpnd, sra, immZExt5>,
           SRA_FM<3, 0>;
def SLLV : MMRel, shift_rotate_reg<"sllv", CPURegsOpnd, shl>, SRLV_FM<4, 0>;
def SRLV : MMRel, shift_rotate_reg<"srlv", CPURegsOpnd, srl>, SRLV_FM<6, 0>;
def SRAV : MMRel, shift_rotate_reg<"srav", CPURegsOpnd, sra>, SRLV_FM<7, 0>;

// Rotate Instructions
let Predicates = [HasOi32r2, HasStdEnc] in {
  def ROTR  : MMRel, shift_rotate_imm<"rotr", shamt, CPURegsOpnd, rotr,
                                      immZExt5>,
              SRA_FM<2, 1>;
  def ROTRV : MMRel, shift_rotate_reg<"rotrv", CPURegsOpnd, rotr>,
              SRLV_FM<6, 1>;
}

/// Load and Store Instructions
///  aligned
defm LB  : LoadM<"lb", CPURegs, sextloadi8>, MMRel, LW_FM<0x20>;
defm LBu : LoadM<"lbu", CPURegs, zextloadi8, addrDefault>, MMRel, LW_FM<0x24>;
defm LH  : LoadM<"lh", CPURegs, sextloadi16, addrDefault>, MMRel, LW_FM<0x21>;
defm LHu : LoadM<"lhu", CPURegs, zextloadi16>, MMRel, LW_FM<0x25>;
defm LW  : LoadM<"lw", CPURegs, load, addrDefault>, MMRel, LW_FM<0x23>;
defm SB  : StoreM<"sb", CPURegs, truncstorei8>, MMRel, LW_FM<0x28>;
defm SH  : StoreM<"sh", CPURegs, truncstorei16>, MMRel, LW_FM<0x29>;
defm SW  : StoreM<"sw", CPURegs, store>, MMRel, LW_FM<0x2b>;

/// Oi NEW: Spill load/store
def SPILLLW : InstSE<(outs CPURegs:$rt), (ins mem:$addr), "spilllw\t$rt, $addr",
    [], NoItinerary, FrmI, "spilllw">, MMRel, LW_FM<0x37> {
  let DecoderMethod = "DecodeMem";
  let canFoldAsLoad = 1;
  let mayLoad = 1;
}

def SPILLSW : InstSE<(outs), (ins CPURegs:$rt, mem:$addr), "spillsw\t$rt, $addr",
    [], NoItinerary, FrmI, "spillsw">, MMRel, LW_FM<0x36> {
  let DecoderMethod = "DecodeMem";
  let mayStore = 1;
}

/// load/store left/right
defm LWL : LoadLeftRightM<"lwl", OiLWL, CPURegs>, LW_FM<0x22>;
defm LWR : LoadLeftRightM<"lwr", OiLWR, CPURegs>, LW_FM<0x26>;
defm SWL : StoreLeftRightM<"swl", OiSWL, CPURegs>, LW_FM<0x2a>;
defm SWR : StoreLeftRightM<"swr", OiSWR, CPURegs>, LW_FM<0x2e>;

def SYNC : SYNC_FT, SYNC_FM;

/// Load-linked, Store-conditional
let Predicates = [NotN64, HasStdEnc] in {
  def LL : LLBase<"ll", CPURegsOpnd, mem>, LW_FM<0x30>;
  def SC : SCBase<"sc", CPURegsOpnd, mem>, LW_FM<0x38>;
}

let Predicates = [IsN64, HasStdEnc], DecoderNamespace = "Oi64" in {
  def LL_P8 : LLBase<"ll", CPURegsOpnd, mem64>, LW_FM<0x30>;
  def SC_P8 : SCBase<"sc", CPURegsOpnd, mem64>, LW_FM<0x38>;
}

/// Jump and Branch Instructions
def J       : JumpFJ<jmptarget, "j", br, bb>, FJ<2>,
              Requires<[RelocStatic, HasStdEnc]>, IsBranch;
def JR      : IndirectBranch<CPURegs>, MTLO_FM<8>;
def B       : UncondBranch<"b">, B_FM;
def BEQ     : CBranch<"beq", seteq, CPURegs>, BEQ_FM<4>;
def BNE     : CBranch<"bne", setne, CPURegs>, BEQ_FM<5>;
def BGEZ    : CBranchZero<"bgez", setge, CPURegs>, BGEZ_FM<1, 1>;
def BGTZ    : CBranchZero<"bgtz", setgt, CPURegs>, BGEZ_FM<7, 0>;
def BLEZ    : CBranchZero<"blez", setle, CPURegs>, BGEZ_FM<6, 0>;
def BLTZ    : CBranchZero<"bltz", setlt, CPURegs>, BGEZ_FM<1, 0>;

def BAL_BR: BAL_FT, BAL_FM;

def JAL  : JumpLink<"jal">, FJ<3>;
def JALR : JumpLinkReg<"jalr", CPURegs>, JALR_FM;
def JALRPseudo : JumpLinkRegPseudo<CPURegs, JALR, RA>;
def BGEZAL : BGEZAL_FT<"bgezal", CPURegsOpnd>, BGEZAL_FM<0x11>;
def BLTZAL : BGEZAL_FT<"bltzal", CPURegsOpnd>, BGEZAL_FM<0x10>;
def TAILCALL : JumpFJ<calltarget, "j", OiTailCall, imm>, FJ<2>, IsTailCall;
def TAILCALL_R : JumpFR<CPURegs, OiTailCall>, MTLO_FM<8>, IsTailCall;

def RET : RetBase<CPURegs>, MTLO_FM<8>;

// Exception handling related node and instructions.
// The conversion sequence is:
// ISD::EH_RETURN -> OiISD::EH_RETURN ->
// OIeh_return -> (stack change + indirect branch)
//
// OIeh_return takes the place of regular return instruction
// but takes two arguments (V1, V0) which are used for storing
// the offset and return address respectively.
def SDT_OiEHRET : SDTypeProfile<0, 2, [SDTCisInt<0>, SDTCisPtrTy<1>]>;

def OIehret : SDNode<"OiISD::EH_RETURN", SDT_OiEHRET,
                      [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

let Uses = [V0, V1], isTerminator = 1, isReturn = 1, isBarrier = 1 in {
  def OIeh_return32 : OiPseudo<(outs), (ins CPURegs:$spoff, CPURegs:$dst),
                                [(OIehret CPURegs:$spoff, CPURegs:$dst)]>;
  def OIeh_return64 : OiPseudo<(outs), (ins CPU64Regs:$spoff,
                                                CPU64Regs:$dst),
                                [(OIehret CPU64Regs:$spoff, CPU64Regs:$dst)]>;
}

/// Multiply and Divide Instructions.
def MULT  : MMRel, Mult<"mult", IIImul, CPURegsOpnd, [HI, LO]>,
            MULT_FM<0, 0x18>;
def MULTu : MMRel, Mult<"multu", IIImul, CPURegsOpnd, [HI, LO]>,
            MULT_FM<0, 0x19>;
def PseudoMULT  : MultDivPseudo<MULT, ACRegs, CPURegsOpnd, OiMult, IIImul>;
def PseudoMULTu : MultDivPseudo<MULTu, ACRegs, CPURegsOpnd, OiMultu, IIImul>;
def SDIV  : Div<"div", IIIdiv, CPURegsOpnd, [HI, LO]>, MULT_FM<0, 0x1a>;
def UDIV  : Div<"divu", IIIdiv, CPURegsOpnd, [HI, LO]>, MULT_FM<0, 0x1b>;
def PseudoSDIV : MultDivPseudo<SDIV, ACRegs, CPURegsOpnd, OiDivRem, IIIdiv, 0>;
def PseudoUDIV : MultDivPseudo<UDIV, ACRegs, CPURegsOpnd, OiDivRemU, IIIdiv,
                               0>;

def MTHI : MoveToLOHI<"mthi", CPURegs, [HI]>, MTLO_FM<0x11>;
def MTLO : MoveToLOHI<"mtlo", CPURegs, [LO]>, MTLO_FM<0x13>;
def MFHI : MoveFromLOHI<"mfhi", CPURegs, [HI]>, MFLO_FM<0x10>;
def MFLO : MoveFromLOHI<"mflo", CPURegs, [LO]>, MFLO_FM<0x12>;

/// Sign Ext In Register Instructions.
def SEB : SignExtInReg<"seb", i8, CPURegs>, SEB_FM<0x10, 0x20>;
def SEH : SignExtInReg<"seh", i16, CPURegs>, SEB_FM<0x18, 0x20>;

/// Count Leading
def CLZ : CountLeading0<"clz", CPURegsOpnd>, CLO_FM<0x20>;
def CLO : CountLeading1<"clo", CPURegsOpnd>, CLO_FM<0x21>;

/// Word Swap Bytes Within Halfwords
def WSBH : SubwordSwap<"wsbh", CPURegsOpnd>, SEB_FM<2, 0x20>;

/// No operation.
def NOP : PseudoSE<(outs), (ins), []>, PseudoInstExpansion<(SLL ZERO, ZERO, 0)>;
//def NOP : OiInstNOP<(outs), (ins), "nop", []>;

// FrameIndexes are legalized when they are operands from load/store
// instructions. The same not happens for stack address copies, so an
// add op with mem ComplexPattern is used and the stack address copy
// can be matched. It's similar to Sparc LEA_ADDRi
def LEA_ADDiu : EffectiveAddress<"addiu", CPURegs, mem_ea>, LW_FM<9>;

// MADD*/MSUB*
def MADD  : MArithR<"madd", 1>, MULT_FM<0x1c, 0>;
def MADDU : MArithR<"maddu", 1>, MULT_FM<0x1c, 1>;
def MSUB  : MArithR<"msub">, MULT_FM<0x1c, 4>;
def MSUBU : MArithR<"msubu">, MULT_FM<0x1c, 5>;
def PseudoMADD  : MAddSubPseudo<MADD, OiMAdd>;
def PseudoMADDU : MAddSubPseudo<MADDU, OiMAddu>;
def PseudoMSUB  : MAddSubPseudo<MSUB, OiMSub>;
def PseudoMSUBU : MAddSubPseudo<MSUBU, OiMSubu>;

def RDHWR : ReadHardware<CPURegs, HWRegsOpnd>, RDHWR_FM;

def EXT : ExtBase<"ext", CPURegsOpnd>, EXT_FM<0>;
def INS : InsBase<"ins", CPURegsOpnd>, EXT_FM<4>;

/// Move Control Registers From/To CPU Registers
def MFC0_3OP : MFC3OP<(outs CPURegsOpnd:$rt),
                      (ins CPURegsOpnd:$rd, uimm32:$sel),
                      "mfc0\t$rt, $rd, $sel">, MFC3OP_FM<0x10, 0>;

def MTC0_3OP : MFC3OP<(outs CPURegsOpnd:$rd, uimm32:$sel),
                      (ins CPURegsOpnd:$rt),
                      "mtc0\t$rt, $rd, $sel">, MFC3OP_FM<0x10, 4>;

def MFC2_3OP : MFC3OP<(outs CPURegsOpnd:$rt),
                      (ins CPURegsOpnd:$rd, uimm32:$sel),
                      "mfc2\t$rt, $rd, $sel">, MFC3OP_FM<0x12, 0>;

def MTC2_3OP : MFC3OP<(outs CPURegsOpnd:$rd, uimm32:$sel),
                      (ins CPURegsOpnd:$rt),
                      "mtc2\t$rt, $rd, $sel">, MFC3OP_FM<0x12, 4>;

//===----------------------------------------------------------------------===//
// Instruction aliases
//===----------------------------------------------------------------------===//
//def : InstAlias<"move $dst, $src",
//                (ADDu CPURegsOpnd:$dst, CPURegsOpnd:$src,ZERO), 1>;
  //    Requires<[NotOi64]>;
//def : InstAlias<"move $dst, $src",
 //               (OR CPURegsOpnd:$dst, CPURegsOpnd:$src,ZERO), 1>;
//      Requires<[NotOi64]>;
def : InstAlias<"bal $offset", (BGEZAL RA, brtarget:$offset), 1>;
def : InstAlias<"addu $rs, $rt, $imm",
                (ADDiu CPURegsOpnd:$rs, CPURegsOpnd:$rt, simm32:$imm), 0>;
def : InstAlias<"add $rs, $rt, $imm",
                (ADDi CPURegsOpnd:$rs, CPURegsOpnd:$rt, simm32:$imm), 0>;
def : InstAlias<"and $rs, $rt, $imm",
                (ANDi CPURegsOpnd:$rs, CPURegsOpnd:$rt, simm32:$imm), 0>;
def : InstAlias<"j $rs", (JR CPURegs:$rs), 0>,
      Requires<[NotOi64]>;
def : InstAlias<"jalr $rs", (JALR RA, CPURegs:$rs)>, Requires<[NotOi64]>;
def : InstAlias<"jal $rs", (JALR RA, CPURegs:$rs), 0>, Requires<[NotOi64]>;
def : InstAlias<"jal $rd,$rs", (JALR CPURegs:$rd, CPURegs:$rs), 0>,
      Requires<[NotOi64]>; 
def : InstAlias<"not $rt, $rs",
                (NOR CPURegsOpnd:$rt, CPURegsOpnd:$rs, ZERO), 1>;
def : InstAlias<"neg $rt, $rs",
                (SUB CPURegsOpnd:$rt, ZERO, CPURegsOpnd:$rs), 1>;
def : InstAlias<"negu $rt, $rs",
                (SUBu CPURegsOpnd:$rt, ZERO, CPURegsOpnd:$rs), 1>;
def : InstAlias<"slt $rs, $rt, $imm",
                (SLTi CPURegsOpnd:$rs, CPURegs:$rt, simm32:$imm), 0>;
def : InstAlias<"xor $rs, $rt, $imm",
                (XORi CPURegsOpnd:$rs, CPURegsOpnd:$rt, uimm32:$imm), 1>,
      Requires<[NotOi64]>;
def : InstAlias<"or $rs, $rt, $imm",
                (ORi CPURegsOpnd:$rs, CPURegsOpnd:$rt, uimm32:$imm), 1>,
                 Requires<[NotOi64]>;
def : InstAlias<"nop", (SLL ZERO, ZERO, 0), 1>;
def : InstAlias<"mfc0 $rt, $rd",
                (MFC0_3OP CPURegsOpnd:$rt, CPURegsOpnd:$rd, 0), 0>;
def : InstAlias<"mtc0 $rt, $rd",
                (MTC0_3OP CPURegsOpnd:$rd, 0, CPURegsOpnd:$rt), 0>;
def : InstAlias<"mfc2 $rt, $rd",
                (MFC2_3OP CPURegsOpnd:$rt, CPURegsOpnd:$rd, 0), 0>;
def : InstAlias<"mtc2 $rt, $rd",
                (MTC2_3OP CPURegsOpnd:$rd, 0, CPURegsOpnd:$rt), 0>;

//===----------------------------------------------------------------------===//
// Assembler Pseudo Instructions
//===----------------------------------------------------------------------===//

class LoadImm32< string instr_asm, Operand Od, RegisterOperand RO> :
  OiAsmPseudoInst<(outs RO:$rt), (ins Od:$imm32),
                     !strconcat(instr_asm, "\t$rt, $imm32")> ;
def LoadImm32Reg : LoadImm32<"li", shamt,CPURegsOpnd>;

class LoadAddress<string instr_asm, Operand MemOpnd, RegisterOperand RO> :
  OiAsmPseudoInst<(outs RO:$rt), (ins MemOpnd:$addr),
                     !strconcat(instr_asm, "\t$rt, $addr")> ;
def LoadAddr32Reg : LoadAddress<"la", mem, CPURegsOpnd>;

class LoadAddressImm<string instr_asm, Operand Od, RegisterOperand RO> :
  OiAsmPseudoInst<(outs RO:$rt), (ins Od:$imm32),
                     !strconcat(instr_asm, "\t$rt, $imm32")> ;
def LoadAddr32Imm : LoadAddressImm<"la", shamt,CPURegsOpnd>;



//===----------------------------------------------------------------------===//
//  Arbitrary patterns that map to one or more instructions
//===----------------------------------------------------------------------===//

// Load/store pattern templates.
class LoadRegImmPat<Instruction LoadInst, ValueType ValTy, PatFrag Node> :
  OiPat<(ValTy (Node addrRegImm:$a)), (LoadInst addrRegImm:$a)>;

class StoreRegImmPat<Instruction StoreInst, ValueType ValTy> :
  OiPat<(store ValTy:$v, addrRegImm:$a), (StoreInst ValTy:$v, addrRegImm:$a)>;

// Small immediates
def : OiPat<(i32 immSExt32:$in),
              (ADDiu ZERO, imm:$in)>;
def : OiPat<(i32 immZExt32:$in),
              (ORi ZERO, imm:$in)>;
def : OiPat<(i32 immLow16Zero:$in),
              (LUi (HI16 imm:$in))>;

// Arbitrary immediates
//def : OiPat<(i32 imm:$imm),
//          (ORi (LUi (HI16 imm:$imm)), (LO16 imm:$imm))>;

// Carry OiPatterns
def : OiPat<(subc CPURegs:$lhs, CPURegs:$rhs),
              (SUBu CPURegs:$lhs, CPURegs:$rhs)>;
let Predicates = [HasStdEnc, NotDSP] in {
  def : OiPat<(addc CPURegs:$lhs, CPURegs:$rhs),
                (ADDu CPURegs:$lhs, CPURegs:$rhs)>;
  def : OiPat<(addc  CPURegs:$src, immSExt32:$imm),
                (ADDiu CPURegs:$src, imm:$imm)>;
}

// Call
def : OiPat<(OiJmpLink (i32 tglobaladdr:$dst)),
              (JAL tglobaladdr:$dst)>;
def : OiPat<(OiJmpLink (i32 texternalsym:$dst)),
              (JAL texternalsym:$dst)>;
def : OiPat<(OiJmpLink CPURegs:$dst),
              (JALR CPURegs:$dst)>;

// Tail call
def : OiPat<(OiTailCall (iPTR tglobaladdr:$dst)),
              (TAILCALL tglobaladdr:$dst)>;
def : OiPat<(OiTailCall (iPTR texternalsym:$dst)),
              (TAILCALL texternalsym:$dst)>;
// hi/lo relocs
def : OiPat<(OiHi tglobaladdr:$in), (LUi tglobaladdr:$in)>;
def : OiPat<(OiHi tblockaddress:$in), (LUi tblockaddress:$in)>;
def : OiPat<(OiHi tjumptable:$in), (LUi tjumptable:$in)>;
def : OiPat<(OiHi tconstpool:$in), (LUi tconstpool:$in)>;
def : OiPat<(OiHi tglobaltlsaddr:$in), (LUi tglobaltlsaddr:$in)>;
def : OiPat<(OiHi texternalsym:$in), (LUi texternalsym:$in)>;

def : OiPat<(OiHi CPURegs:$in), (ADDu ZERO, CPURegs:$in)>;


def : OiPat<(OiLo tglobaladdr:$in), (ADDiu ZERO, tglobaladdr:$in)>;
def : OiPat<(OiLo tblockaddress:$in), (ADDiu ZERO, tblockaddress:$in)>;
def : OiPat<(OiLo tjumptable:$in), (ADDiu ZERO, tjumptable:$in)>;
def : OiPat<(OiLo tconstpool:$in), (ADDiu ZERO, tconstpool:$in)>;
def : OiPat<(OiLo tglobaltlsaddr:$in), (ADDiu ZERO, tglobaltlsaddr:$in)>;
def : OiPat<(OiLo texternalsym:$in), (ADDiu ZERO, texternalsym:$in)>;

def : OiPat<(add CPURegs:$hi, (OiLo tglobaladdr:$lo)),
              (ADDiu CPURegs:$hi, tglobaladdr:$lo)>;
def : OiPat<(add CPURegs:$hi, (OiLo tblockaddress:$lo)),
              (ADDiu CPURegs:$hi, tblockaddress:$lo)>;
def : OiPat<(add CPURegs:$hi, (OiLo tjumptable:$lo)),
              (ADDiu CPURegs:$hi, tjumptable:$lo)>;
def : OiPat<(add CPURegs:$hi, (OiLo tconstpool:$lo)),
              (ADDiu CPURegs:$hi, tconstpool:$lo)>;
def : OiPat<(add CPURegs:$hi, (OiLo tglobaltlsaddr:$lo)),
              (ADDiu CPURegs:$hi, tglobaltlsaddr:$lo)>;

// gp_rel relocs
def : OiPat<(add CPURegs:$gp, (OiGPRel tglobaladdr:$in)),
              (ADDiu CPURegs:$gp, tglobaladdr:$in)>;
def : OiPat<(add CPURegs:$gp, (OiGPRel tconstpool:$in)),
              (ADDiu CPURegs:$gp, tconstpool:$in)>;

// wrapper_pic
class WrapperPat<SDNode node, Instruction ADDiuOp, RegisterClass RC>:
      OiPat<(OiWrapper RC:$gp, node:$in),
              (ADDiuOp RC:$gp, node:$in)>;

def : WrapperPat<tglobaladdr, ADDiu, CPURegs>;
def : WrapperPat<tconstpool, ADDiu, CPURegs>;
def : WrapperPat<texternalsym, ADDiu, CPURegs>;
def : WrapperPat<tblockaddress, ADDiu, CPURegs>;
def : WrapperPat<tjumptable, ADDiu, CPURegs>;
def : WrapperPat<tglobaltlsaddr, ADDiu, CPURegs>;

// Oi does not have "not", so we expand our way
def : OiPat<(not CPURegs:$in),
              (NOR CPURegsOpnd:$in, ZERO)>;

// extended loads
let Predicates = [NotN64, HasStdEnc] in {
  def : OiPat<(i32 (extloadi1  addr:$src)), (LBu addr:$src)>;
  def : OiPat<(i32 (extloadi8  addr:$src)), (LBu addr:$src)>;
  def : OiPat<(i32 (extloadi16 addr:$src)), (LHu addr:$src)>;
}
let Predicates = [IsN64, HasStdEnc] in {
  def : OiPat<(i32 (extloadi1  addr:$src)), (LBu_P8 addr:$src)>;
  def : OiPat<(i32 (extloadi8  addr:$src)), (LBu_P8 addr:$src)>;
  def : OiPat<(i32 (extloadi16 addr:$src)), (LHu_P8 addr:$src)>;
}

// peepholes
let Predicates = [NotN64, HasStdEnc] in {
  def : OiPat<(store (i32 0), addr:$dst), (SW ZERO, addr:$dst)>;
}
let Predicates = [IsN64, HasStdEnc] in {
  def : OiPat<(store (i32 0), addr:$dst), (SW_P8 ZERO, addr:$dst)>;
}

// brcond patterns
multiclass BrcondPats<RegisterClass RC, Instruction BEQOp, Instruction BNEOp,
                      Instruction SLTOp, Instruction SLTuOp, Instruction SLTiOp,
                      Instruction SLTiuOp, Register ZEROReg> {
def : OiPat<(brcond (i32 (setne RC:$lhs, 0)), bb:$dst),
              (BNEOp RC:$lhs, ZEROReg, bb:$dst)>;
def : OiPat<(brcond (i32 (seteq RC:$lhs, 0)), bb:$dst),
              (BEQOp RC:$lhs, ZEROReg, bb:$dst)>;

def : OiPat<(brcond (i32 (setge RC:$lhs, RC:$rhs)), bb:$dst),
              (BEQ (SLTOp RC:$lhs, RC:$rhs), ZERO, bb:$dst)>;
def : OiPat<(brcond (i32 (setuge RC:$lhs, RC:$rhs)), bb:$dst),
              (BEQ (SLTuOp RC:$lhs, RC:$rhs), ZERO, bb:$dst)>;
def : OiPat<(brcond (i32 (setge RC:$lhs, immSExt16:$rhs)), bb:$dst),
              (BEQ (SLTiOp RC:$lhs, immSExt16:$rhs), ZERO, bb:$dst)>;
def : OiPat<(brcond (i32 (setuge RC:$lhs, immSExt16:$rhs)), bb:$dst),
              (BEQ (SLTiuOp RC:$lhs, immSExt16:$rhs), ZERO, bb:$dst)>;

def : OiPat<(brcond (i32 (setle RC:$lhs, RC:$rhs)), bb:$dst),
              (BEQ (SLTOp RC:$rhs, RC:$lhs), ZERO, bb:$dst)>;
def : OiPat<(brcond (i32 (setule RC:$lhs, RC:$rhs)), bb:$dst),
              (BEQ (SLTuOp RC:$rhs, RC:$lhs), ZERO, bb:$dst)>;

def : OiPat<(brcond RC:$cond, bb:$dst),
              (BNEOp RC:$cond, ZEROReg, bb:$dst)>;
}

defm : BrcondPats<CPURegs, BEQ, BNE, SLT, SLTu, SLTi, SLTiu, ZERO>;

// setcc patterns
multiclass SeteqPats<RegisterClass RC, Instruction SLTiuOp, Instruction XOROp,
                     Instruction SLTuOp, Register ZEROReg> {
  def : OiPat<(seteq RC:$lhs, RC:$rhs),
                (SLTiuOp (XOROp RC:$lhs, RC:$rhs), 1)>;
  def : OiPat<(setne RC:$lhs, RC:$rhs),
                (SLTuOp ZEROReg, (XOROp RC:$lhs, RC:$rhs))>;
}

multiclass SetlePats<RegisterClass RC, Instruction SLTOp, Instruction SLTuOp> {
  def : OiPat<(setle RC:$lhs, RC:$rhs),
                (XORi (SLTOp RC:$rhs, RC:$lhs), 1)>;
  def : OiPat<(setule RC:$lhs, RC:$rhs),
                (XORi (SLTuOp RC:$rhs, RC:$lhs), 1)>;
}

multiclass SetgtPats<RegisterClass RC, Instruction SLTOp, Instruction SLTuOp> {
  def : OiPat<(setgt RC:$lhs, RC:$rhs),
                (SLTOp RC:$rhs, RC:$lhs)>;
  def : OiPat<(setugt RC:$lhs, RC:$rhs),
                (SLTuOp RC:$rhs, RC:$lhs)>;
}

multiclass SetgePats<RegisterClass RC, Instruction SLTOp, Instruction SLTuOp> {
  def : OiPat<(setge RC:$lhs, RC:$rhs),
                (XORi (SLTOp RC:$lhs, RC:$rhs), 1)>;
  def : OiPat<(setuge RC:$lhs, RC:$rhs),
                (XORi (SLTuOp RC:$lhs, RC:$rhs), 1)>;
}

multiclass SetgeImmPats<RegisterClass RC, Instruction SLTiOp,
                        Instruction SLTiuOp> {
  def : OiPat<(setge RC:$lhs, immSExt32:$rhs),
                (XORi (SLTiOp RC:$lhs, immSExt32:$rhs), 1)>;
  def : OiPat<(setuge RC:$lhs, immSExt32:$rhs),
                (XORi (SLTiuOp RC:$lhs, immSExt32:$rhs), 1)>;
}

defm : SeteqPats<CPURegs, SLTiu, XOR, SLTu, ZERO>;
defm : SetlePats<CPURegs, SLT, SLTu>;
defm : SetgtPats<CPURegs, SLT, SLTu>;
defm : SetgePats<CPURegs, SLT, SLTu>;
defm : SetgeImmPats<CPURegs, SLTi, SLTiu>;

// bswap pattern
def : OiPat<(bswap CPURegs:$rt), (ROTR (WSBH CPURegs:$rt), 16)>;

// mflo/hi patterns.
def : OiPat<(i32 (ExtractLOHI ACRegs:$ac, imm:$lohi_idx)),
              (EXTRACT_SUBREG ACRegs:$ac, imm:$lohi_idx)>;

// Load halfword/word patterns.
let AddedComplexity = 40 in {
  let Predicates = [NotN64, HasStdEnc] in {
    def : LoadRegImmPat<LBu, i32, zextloadi8>;
    def : LoadRegImmPat<LH, i32, sextloadi16>;
    def : LoadRegImmPat<LW, i32, load>;
  }
  let Predicates = [IsN64, HasStdEnc] in {
    def : LoadRegImmPat<LBu_P8, i32, zextloadi8>;
    def : LoadRegImmPat<LH_P8, i32, sextloadi16>;
    def : LoadRegImmPat<LW_P8, i32, load>;
  }
}

//===----------------------------------------------------------------------===//
// Floating Point Support
//===----------------------------------------------------------------------===//

include "OiInstrFPU.td"
include "Oi64InstrInfo.td"
include "OiCondMov.td"

//
// Oi16

include "Oi16InstrFormats.td"
include "Oi16InstrInfo.td"

// DSP
include "OiDSPInstrFormats.td"
include "OiDSPInstrInfo.td"

// Microoi
include "MicroOiInstrFormats.td"
include "MicroOiInstrInfo.td"
