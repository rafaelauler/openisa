/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Assembly Matcher Source Fragment                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_ASSEMBLER_HEADER
#undef GET_ASSEMBLER_HEADER
  // This should be included into the middle of the declaration of
  // your subclasses implementation of MCTargetAsmParser.
  unsigned ComputeAvailableFeatures(uint64_t FeatureBits) const;
  void convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                       const SmallVectorImpl<MCParsedAsmOperand*> &Operands);
  void convertToMapAndConstraints(unsigned Kind,
                           const SmallVectorImpl<MCParsedAsmOperand*> &Operands);
  bool mnemonicIsValid(StringRef Mnemonic);
  unsigned MatchInstructionImpl(
                           const SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                                MCInst &Inst,
                                unsigned &ErrorInfo, bool matchingInlineAsm,
                                unsigned VariantID = 0);

  enum OperandMatchResultTy {
    MatchOperand_Success,    // operand matched successfully
    MatchOperand_NoMatch,    // operand did not match
    MatchOperand_ParseFail   // operand matched but had errors
  };
  OperandMatchResultTy MatchOperandParserImpl(
    SmallVectorImpl<MCParsedAsmOperand*> &Operands,
    StringRef Mnemonic);
  OperandMatchResultTy tryCustomParseOperand(
    SmallVectorImpl<MCParsedAsmOperand*> &Operands,
    unsigned MCK);

#endif // GET_ASSEMBLER_HEADER_INFO


#ifdef GET_OPERAND_DIAGNOSTIC_TYPES
#undef GET_OPERAND_DIAGNOSTIC_TYPES

#endif // GET_OPERAND_DIAGNOSTIC_TYPES


#ifdef GET_REGISTER_MATCHER
#undef GET_REGISTER_MATCHER

// Flags for subtarget features that participate in instruction matching.
enum SubtargetFeatureFlag {
  Feature_HasSEInReg = (1 << 9),
  Feature_HasBitCount = (1 << 0),
  Feature_HasSwap = (1 << 11),
  Feature_HasCondMov = (1 << 1),
  Feature_HasFPIdx = (1 << 4),
  Feature_HasOi32 = (1 << 5),
  Feature_HasOi32r2 = (1 << 6),
  Feature_HasOi64 = (1 << 7),
  Feature_NotOi64 = (1 << 20),
  Feature_HasOi64r2 = (1 << 8),
  Feature_IsN64 = (1 << 14),
  Feature_NotN64 = (1 << 19),
  Feature_InOi16Mode = (1 << 12),
  Feature_RelocStatic = (1 << 22),
  Feature_RelocPIC = (1 << 21),
  Feature_NoNaNsFPMath = (1 << 17),
  Feature_HasStdEnc = (1 << 10),
  Feature_IsFP64bit = (1 << 13),
  Feature_NotFP64bit = (1 << 18),
  Feature_IsSingleFloat = (1 << 16),
  Feature_IsNotSingleFloat = (1 << 15),
  Feature_HasDSP = (1 << 2),
  Feature_HasDSPR2 = (1 << 3),
  Feature_None = 0
};

#endif // GET_REGISTER_MATCHER


#ifdef GET_SUBTARGET_FEATURE_NAME
#undef GET_SUBTARGET_FEATURE_NAME

// User-level names for subtarget features that participate in
// instruction matching.
static const char *getSubtargetFeatureName(unsigned Val) {
  switch(Val) {
  case Feature_HasSEInReg: return "";
  case Feature_HasBitCount: return "";
  case Feature_HasSwap: return "";
  case Feature_HasCondMov: return "";
  case Feature_HasFPIdx: return "";
  case Feature_HasOi32: return "";
  case Feature_HasOi32r2: return "";
  case Feature_HasOi64: return "";
  case Feature_NotOi64: return "";
  case Feature_HasOi64r2: return "";
  case Feature_IsN64: return "";
  case Feature_NotN64: return "";
  case Feature_InOi16Mode: return "";
  case Feature_RelocStatic: return "";
  case Feature_RelocPIC: return "";
  case Feature_NoNaNsFPMath: return "";
  case Feature_HasStdEnc: return "";
  case Feature_IsFP64bit: return "";
  case Feature_NotFP64bit: return "";
  case Feature_IsSingleFloat: return "";
  case Feature_IsNotSingleFloat: return "";
  case Feature_HasDSP: return "";
  case Feature_HasDSPR2: return "";
  default: return "(unknown)";
  }
}

#endif // GET_SUBTARGET_FEATURE_NAME


#ifdef GET_MATCHER_IMPLEMENTATION
#undef GET_MATCHER_IMPLEMENTATION

namespace {
enum OperatorConversionKind {
  CVT_Done,
  CVT_Reg,
  CVT_Tied,
  CVT_95_Reg,
  CVT_95_addCPURegsAsmOperands,
  CVT_95_addImmOperands,
  CVT_95_addCPU64RegsAsmOperands,
  CVT_regRA,
  CVT_95_addCCRAsmOperands,
  CVT_imm_0,
  CVT_95_addMemOperands,
  CVT_regZERO_64,
  CVT_regZERO,
  CVT_95_addHWRegsAsmOperands,
  CVT_95_addHW64RegsAsmOperands,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__Reg1_1__Reg1_2,
  Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2,
  Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2,
  Convert__Reg1_1__Reg1_2__Reg1_3,
  Convert__Reg1_0__Imm1_1,
  Convert__Reg1_0__Tie0__Imm1_1,
  Convert__Imm1_1,
  Convert__Reg1_0__Reg1_1__Imm1_2,
  Convert__Reg1_0__Imm1_2,
  Convert__Reg1_0__Reg1_1__Reg1_2,
  Convert__Reg1_0__Tie0__Reg1_1,
  Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2,
  Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2,
  Convert__Reg1_0__Reg1_1__Imm1_2__Tie0,
  Convert__Imm1_0,
  Convert__regRA__Imm1_0,
  Convert__CPURegsAsm1_0__Imm1_1,
  Convert__Reg1_0__Reg1_1,
  Convert__Reg1_3__Reg1_4__Imm1_1,
  Convert__Reg1_2__Reg1_3,
  Convert__Reg1_0__CCRAsm1_1,
  Convert__CPURegsAsm1_0__CPURegsAsm1_1,
  Convert__Reg1_2__Reg1_3__Reg1_4,
  Convert__CCRAsm1_1__Reg1_0,
  Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1,
  Convert__CPU64RegsAsm1_1__CPU64RegsAsm1_2,
  Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3,
  Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3__Tie0,
  Convert__CPURegsAsm1_1__CPURegsAsm1_2,
  Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__imm_0,
  Convert__CPU64RegsAsm1_1__imm_0__CPU64RegsAsm1_0,
  Convert__CPU64RegsAsm1_1__Imm1_2__CPU64RegsAsm1_0,
  Convert__Reg1_1__Reg1_0,
  Convert__CPU64RegsAsm1_0__CPURegsAsm1_2__CPU64RegsAsm1_1,
  Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2__Imm1_3,
  Convert__Reg1_1__Reg1_2__Imm1_3,
  Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2__Imm1_3__Tie0,
  Convert__Reg1_0,
  Convert_NoOperands,
  Convert__CPURegsAsm1_0__Mem2_1,
  Convert__Reg1_0__Mem2_1,
  Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3,
  Convert__Reg1_0__Reg1_3__Reg1_1,
  Convert__Reg1_0__Mem2_1__Tie0,
  Convert__CPU64RegsAsm1_0__Mem2_1,
  Convert__Reg1_0__Reg1_3__Imm1_1,
  Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4,
  Convert__CPURegsAsm1_0__CPURegsAsm1_1__imm_0,
  Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__regZERO_64,
  Convert__CPURegsAsm1_0__CPURegsAsm1_1__regZERO,
  Convert__Reg1_0__Reg1_1__Tie0,
  Convert__Reg1_1__Reg1_2__Tie0,
  Convert__Reg1_0__Reg1_1__Reg1_2__Tie0,
  Convert__Reg1_1__Reg1_2__Reg1_3__Tie0,
  Convert__CPURegsAsm1_1__imm_0__CPURegsAsm1_0,
  Convert__CPURegsAsm1_1__Imm1_2__CPURegsAsm1_0,
  Convert__CPURegsAsm1_0__regZERO__CPURegsAsm1_1,
  Convert__Reg1_2__Reg1_3__Imm1_4__Tie0,
  Convert__Reg1_0__HWRegsAsm1_1,
  Convert__Reg1_0__HW64RegsAsm1_1,
  Convert__Reg1_1__Imm1_2,
  Convert__CPURegsAsm1_0__CPURegsAsm1_2__CPURegsAsm1_1,
  Convert__CPURegsAsm1_0__Tie0__Mem2_1,
  Convert__CPU64RegsAsm1_0__Tie0__Mem2_1,
  Convert__CPURegsAsm1_0__Reg1_1__Reg1_2,
  Convert__CPURegsAsm1_0__Reg1_1__Imm1_2,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][11] = {
  // Convert__Reg1_1__Reg1_2
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 2, CVT_95_addCPURegsAsmOperands, 3, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__Imm1_1
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Tie0__Imm1_1
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Imm1_1
  { CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Imm1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Imm1_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPU64RegsAsmOperands, 2, CVT_95_addCPU64RegsAsmOperands, 3, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPU64RegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Imm1_2__Tie0
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__Imm1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__regRA__Imm1_0
  { CVT_regRA, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__CPURegsAsm1_0__Imm1_1
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Imm1_1
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_3
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__CCRAsm1_1
  { CVT_95_Reg, 1, CVT_95_addCCRAsmOperands, 2, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_1
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_Done },
  // Convert__CCRAsm1_1__Reg1_0
  { CVT_95_addCCRAsmOperands, 2, CVT_95_Reg, 1, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPU64RegsAsmOperands, 2, CVT_Done },
  // Convert__CPU64RegsAsm1_1__CPU64RegsAsm1_2
  { CVT_95_addCPU64RegsAsmOperands, 2, CVT_95_addCPU64RegsAsmOperands, 3, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPU64RegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3__Tie0
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPU64RegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Tied, 0, CVT_Done },
  // Convert__CPURegsAsm1_1__CPURegsAsm1_2
  { CVT_95_addCPURegsAsmOperands, 2, CVT_95_addCPURegsAsmOperands, 3, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__imm_0
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPU64RegsAsmOperands, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__CPU64RegsAsm1_1__imm_0__CPU64RegsAsm1_0
  { CVT_95_addCPU64RegsAsmOperands, 2, CVT_imm_0, 0, CVT_95_addCPU64RegsAsmOperands, 1, CVT_Done },
  // Convert__CPU64RegsAsm1_1__Imm1_2__CPU64RegsAsm1_0
  { CVT_95_addCPU64RegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addCPU64RegsAsmOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_0
  { CVT_95_Reg, 2, CVT_95_Reg, 1, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPURegsAsm1_2__CPU64RegsAsm1_1
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 3, CVT_95_addCPU64RegsAsmOperands, 2, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2__Imm1_3
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm1_3
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2__Imm1_3__Tie0
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_0
  { CVT_95_Reg, 1, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__CPURegsAsm1_0__Mem2_1
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__Reg1_0__Mem2_1
  { CVT_95_Reg, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_3__Reg1_1
  { CVT_95_Reg, 1, CVT_95_Reg, 4, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_0__Mem2_1__Tie0
  { CVT_95_Reg, 1, CVT_95_addMemOperands, 2, CVT_Tied, 0, CVT_Done },
  // Convert__CPU64RegsAsm1_0__Mem2_1
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_3__Imm1_1
  { CVT_95_Reg, 1, CVT_95_Reg, 4, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_1__imm_0
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__regZERO_64
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_95_addCPU64RegsAsmOperands, 2, CVT_regZERO_64, 0, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_1__regZERO
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 2, CVT_regZERO, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Tie0
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Tie0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__Tie0
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__Tie0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Tied, 0, CVT_Done },
  // Convert__CPURegsAsm1_1__imm_0__CPURegsAsm1_0
  { CVT_95_addCPURegsAsmOperands, 2, CVT_imm_0, 0, CVT_95_addCPURegsAsmOperands, 1, CVT_Done },
  // Convert__CPURegsAsm1_1__Imm1_2__CPURegsAsm1_0
  { CVT_95_addCPURegsAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addCPURegsAsmOperands, 1, CVT_Done },
  // Convert__CPURegsAsm1_0__regZERO__CPURegsAsm1_1
  { CVT_95_addCPURegsAsmOperands, 1, CVT_regZERO, 0, CVT_95_addCPURegsAsmOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm1_4__Tie0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_0__HWRegsAsm1_1
  { CVT_95_Reg, 1, CVT_95_addHWRegsAsmOperands, 2, CVT_Done },
  // Convert__Reg1_0__HW64RegsAsm1_1
  { CVT_95_Reg, 1, CVT_95_addHW64RegsAsmOperands, 2, CVT_Done },
  // Convert__Reg1_1__Imm1_2
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__CPURegsAsm1_0__CPURegsAsm1_2__CPURegsAsm1_1
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_addCPURegsAsmOperands, 3, CVT_95_addCPURegsAsmOperands, 2, CVT_Done },
  // Convert__CPURegsAsm1_0__Tie0__Mem2_1
  { CVT_95_addCPURegsAsmOperands, 1, CVT_Tied, 0, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__CPU64RegsAsm1_0__Tie0__Mem2_1
  { CVT_95_addCPU64RegsAsmOperands, 1, CVT_Tied, 0, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__CPURegsAsm1_0__Reg1_1__Reg1_2
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__CPURegsAsm1_0__Reg1_1__Imm1_2
  { CVT_95_addCPURegsAsmOperands, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
};

void OiAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const SmallVectorImpl<MCParsedAsmOperand*> &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_Reg:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_95_addCPURegsAsmOperands:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addCPURegsAsmOperands(Inst, 1);
      break;
    case CVT_95_addImmOperands:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addImmOperands(Inst, 1);
      break;
    case CVT_95_addCPU64RegsAsmOperands:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addCPU64RegsAsmOperands(Inst, 1);
      break;
    case CVT_regRA:
      Inst.addOperand(MCOperand::CreateReg(Oi::RA));
      break;
    case CVT_95_addCCRAsmOperands:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addCCRAsmOperands(Inst, 1);
      break;
    case CVT_imm_0:
      Inst.addOperand(MCOperand::CreateImm(0));
      break;
    case CVT_95_addMemOperands:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addMemOperands(Inst, 2);
      break;
    case CVT_regZERO_64:
      Inst.addOperand(MCOperand::CreateReg(Oi::ZERO_64));
      break;
    case CVT_regZERO:
      Inst.addOperand(MCOperand::CreateReg(Oi::ZERO));
      break;
    case CVT_95_addHWRegsAsmOperands:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addHWRegsAsmOperands(Inst, 1);
      break;
    case CVT_95_addHW64RegsAsmOperands:
      static_cast<OiOperand*>(Operands[*(p + 1)])->addHW64RegsAsmOperands(Inst, 1);
      break;
    }
  }
}

void OiAsmParser::
convertToMapAndConstraints(unsigned Kind,
                           const SmallVectorImpl<MCParsedAsmOperand*> &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  unsigned NumMCOperands = 0;
  const uint8_t *Converter = ConversionTable[Kind];
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      ++NumMCOperands;
      break;
    case CVT_Tied:
      ++NumMCOperands;
      break;
    case CVT_95_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      NumMCOperands += 1;
      break;
    case CVT_95_addCPURegsAsmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addCPU64RegsAsmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regRA:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addCCRAsmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addMemOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_regZERO_64:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regZERO:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addHWRegsAsmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addHW64RegsAsmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    }
  }
}

namespace {

/// MatchClassKind - The kinds of classes which participate in
/// instruction matching.
enum MatchClassKind {
  InvalidMatchClass = 0,
  MCK__40_, // '('
  MCK__41_, // ')'
  MCK__41__59_, // ');'
  MCK__DOT_, // '.'
  MCK__DOT_d, // '.d'
  MCK__DOT_eq, // '.eq'
  MCK__DOT_h, // '.h'
  MCK__DOT_l, // '.l'
  MCK__DOT_le, // '.le'
  MCK__DOT_lt, // '.lt'
  MCK__DOT_ph, // '.ph'
  MCK__DOT_phl, // '.phl'
  MCK__DOT_phr, // '.phr'
  MCK__DOT_qb, // '.qb'
  MCK__DOT_qbl, // '.qbl'
  MCK__DOT_qbla, // '.qbla'
  MCK__DOT_qbr, // '.qbr'
  MCK__DOT_qbra, // '.qbra'
  MCK__DOT_s, // '.s'
  MCK__DOT_w, // '.w'
  MCK_ZERO, // register class 'ZERO'
  MCK_CPU16Regs, // register class 'CPU16Regs'
  MCK_CPUSPReg, // register class 'CPUSPReg,SP'
  MCK_CPURAReg, // register class 'CPURAReg,RA'
  MCK_CPURegs, // register class 'CPURegs,DSPRegs'
  MCK_Reg6, // derived register class
  MCK_Reg7, // derived register class
  MCK_Reg8, // derived register class
  MCK_CPU64Regs, // register class 'CPU64Regs'
  MCK_FGR32, // register class 'FGR32'
  MCK_AFGR64, // register class 'AFGR64'
  MCK_FGR64, // register class 'FGR64'
  MCK_HILO, // register class 'HILO'
  MCK_HILO64, // register class 'HILO64'
  MCK_FCC0, // register class 'FCC0'
  MCK_CCR, // register class 'CCR'
  MCK_PC, // register class 'PC'
  MCK_HWRegs, // register class 'HWRegs'
  MCK_HWRegs64, // register class 'HWRegs64'
  MCK_Reg19, // derived register class
  MCK_ACRegs, // register class 'ACRegs'
  MCK_CCRAsm, // user defined class 'CCRAsmOperand'
  MCK_CPU64RegsAsm, // user defined class 'CPU64RegsAsmOperand'
  MCK_CPURegsAsm, // user defined class 'CPURegsAsmOperand'
  MCK_HW64RegsAsm, // user defined class 'HW64RegsAsmOperand'
  MCK_HWRegsAsm, // user defined class 'HWRegsAsmOperand'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_Mem, // user defined class 'OiMemAsmOperand'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 3 strings to match.
    switch (Name[0]) {
    default: break;
    case '(':	 // 1 string to match.
      return MCK__40_;	 // "("
    case ')':	 // 1 string to match.
      return MCK__41_;	 // ")"
    case '.':	 // 1 string to match.
      return MCK__DOT_;	 // "."
    }
    break;
  case 2:	 // 6 strings to match.
    switch (Name[0]) {
    default: break;
    case ')':	 // 1 string to match.
      if (Name[1] != ';')
        break;
      return MCK__41__59_;	 // ");"
    case '.':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        return MCK__DOT_d;	 // ".d"
      case 'h':	 // 1 string to match.
        return MCK__DOT_h;	 // ".h"
      case 'l':	 // 1 string to match.
        return MCK__DOT_l;	 // ".l"
      case 's':	 // 1 string to match.
        return MCK__DOT_s;	 // ".s"
      case 'w':	 // 1 string to match.
        return MCK__DOT_w;	 // ".w"
      }
      break;
    }
    break;
  case 3:	 // 5 strings to match.
    if (Name[0] != '.')
      break;
    switch (Name[1]) {
    default: break;
    case 'e':	 // 1 string to match.
      if (Name[2] != 'q')
        break;
      return MCK__DOT_eq;	 // ".eq"
    case 'l':	 // 2 strings to match.
      switch (Name[2]) {
      default: break;
      case 'e':	 // 1 string to match.
        return MCK__DOT_le;	 // ".le"
      case 't':	 // 1 string to match.
        return MCK__DOT_lt;	 // ".lt"
      }
      break;
    case 'p':	 // 1 string to match.
      if (Name[2] != 'h')
        break;
      return MCK__DOT_ph;	 // ".ph"
    case 'q':	 // 1 string to match.
      if (Name[2] != 'b')
        break;
      return MCK__DOT_qb;	 // ".qb"
    }
    break;
  case 4:	 // 4 strings to match.
    if (Name[0] != '.')
      break;
    switch (Name[1]) {
    default: break;
    case 'p':	 // 2 strings to match.
      if (Name[2] != 'h')
        break;
      switch (Name[3]) {
      default: break;
      case 'l':	 // 1 string to match.
        return MCK__DOT_phl;	 // ".phl"
      case 'r':	 // 1 string to match.
        return MCK__DOT_phr;	 // ".phr"
      }
      break;
    case 'q':	 // 2 strings to match.
      if (Name[2] != 'b')
        break;
      switch (Name[3]) {
      default: break;
      case 'l':	 // 1 string to match.
        return MCK__DOT_qbl;	 // ".qbl"
      case 'r':	 // 1 string to match.
        return MCK__DOT_qbr;	 // ".qbr"
      }
      break;
    }
    break;
  case 5:	 // 2 strings to match.
    if (memcmp(Name.data()+0, ".qb", 3))
      break;
    switch (Name[3]) {
    default: break;
    case 'l':	 // 1 string to match.
      if (Name[4] != 'a')
        break;
      return MCK__DOT_qbla;	 // ".qbla"
    case 'r':	 // 1 string to match.
      if (Name[4] != 'a')
        break;
      return MCK__DOT_qbra;	 // ".qbra"
    }
    break;
  }
  return InvalidMatchClass;
}

/// isSubclass - Compute whether \p A is a subclass of \p B.
static bool isSubclass(MatchClassKind A, MatchClassKind B) {
  if (A == B)
    return true;

  switch (A) {
  default:
    return false;

  case MCK_ZERO:
    return B == MCK_CPURegs;

  case MCK_CPU16Regs:
    return B == MCK_CPURegs;

  case MCK_CPUSPReg:
    return B == MCK_CPURegs;

  case MCK_CPURAReg:
    return B == MCK_CPURegs;

  case MCK_Reg6:
    return B == MCK_CPU64Regs;

  case MCK_Reg7:
    return B == MCK_CPU64Regs;

  case MCK_Reg8:
    return B == MCK_CPU64Regs;

  case MCK_FCC0:
    return B == MCK_CCR;

  case MCK_Reg19:
    return B == MCK_ACRegs;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand *GOp, MatchClassKind Kind) {
  OiOperand &Operand = *(OiOperand*)GOp;
  if (Kind == InvalidMatchClass)
    return MCTargetAsmParser::Match_InvalidOperand;

  if (Operand.isToken())
    return isSubclass(matchTokenString(Operand.getToken()), Kind) ?
             MCTargetAsmParser::Match_Success :
             MCTargetAsmParser::Match_InvalidOperand;

  // 'CCRAsm' class
  if (Kind == MCK_CCRAsm) {
    if (Operand.isCCRAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CPU64RegsAsm' class
  if (Kind == MCK_CPU64RegsAsm) {
    if (Operand.isCPU64RegsAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CPURegsAsm' class
  if (Kind == MCK_CPURegsAsm) {
    if (Operand.isCPURegsAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'HW64RegsAsm' class
  if (Kind == MCK_HW64RegsAsm) {
    if (Operand.isHW64RegsAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'HWRegsAsm' class
  if (Kind == MCK_HWRegsAsm) {
    if (Operand.isHWRegsAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm' class
  if (Kind == MCK_Imm) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Mem' class
  if (Kind == MCK_Mem) {
    if (Operand.isMem())
      return MCTargetAsmParser::Match_Success;
  }

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case Oi::ZERO: OpKind = MCK_ZERO; break;
    case Oi::AT: OpKind = MCK_CPURegs; break;
    case Oi::V0: OpKind = MCK_CPU16Regs; break;
    case Oi::V1: OpKind = MCK_CPU16Regs; break;
    case Oi::A0: OpKind = MCK_CPU16Regs; break;
    case Oi::A1: OpKind = MCK_CPU16Regs; break;
    case Oi::A2: OpKind = MCK_CPU16Regs; break;
    case Oi::A3: OpKind = MCK_CPU16Regs; break;
    case Oi::T0: OpKind = MCK_CPURegs; break;
    case Oi::T1: OpKind = MCK_CPURegs; break;
    case Oi::T2: OpKind = MCK_CPURegs; break;
    case Oi::T3: OpKind = MCK_CPURegs; break;
    case Oi::T4: OpKind = MCK_CPURegs; break;
    case Oi::T5: OpKind = MCK_CPURegs; break;
    case Oi::T6: OpKind = MCK_CPURegs; break;
    case Oi::T7: OpKind = MCK_CPURegs; break;
    case Oi::S0: OpKind = MCK_CPU16Regs; break;
    case Oi::S1: OpKind = MCK_CPU16Regs; break;
    case Oi::S2: OpKind = MCK_CPURegs; break;
    case Oi::S3: OpKind = MCK_CPURegs; break;
    case Oi::S4: OpKind = MCK_CPURegs; break;
    case Oi::S5: OpKind = MCK_CPURegs; break;
    case Oi::S6: OpKind = MCK_CPURegs; break;
    case Oi::S7: OpKind = MCK_CPURegs; break;
    case Oi::T8: OpKind = MCK_CPURegs; break;
    case Oi::T9: OpKind = MCK_CPURegs; break;
    case Oi::K0: OpKind = MCK_CPURegs; break;
    case Oi::K1: OpKind = MCK_CPURegs; break;
    case Oi::GP: OpKind = MCK_CPURegs; break;
    case Oi::SP: OpKind = MCK_CPUSPReg; break;
    case Oi::FP: OpKind = MCK_CPURegs; break;
    case Oi::RA: OpKind = MCK_CPURAReg; break;
    case Oi::ZERO_64: OpKind = MCK_CPU64Regs; break;
    case Oi::AT_64: OpKind = MCK_CPU64Regs; break;
    case Oi::V0_64: OpKind = MCK_Reg6; break;
    case Oi::V1_64: OpKind = MCK_Reg6; break;
    case Oi::A0_64: OpKind = MCK_Reg6; break;
    case Oi::A1_64: OpKind = MCK_Reg6; break;
    case Oi::A2_64: OpKind = MCK_Reg6; break;
    case Oi::A3_64: OpKind = MCK_Reg6; break;
    case Oi::T0_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T1_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T2_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T3_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T4_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T5_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T6_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T7_64: OpKind = MCK_CPU64Regs; break;
    case Oi::S0_64: OpKind = MCK_Reg6; break;
    case Oi::S1_64: OpKind = MCK_Reg6; break;
    case Oi::S2_64: OpKind = MCK_CPU64Regs; break;
    case Oi::S3_64: OpKind = MCK_CPU64Regs; break;
    case Oi::S4_64: OpKind = MCK_CPU64Regs; break;
    case Oi::S5_64: OpKind = MCK_CPU64Regs; break;
    case Oi::S6_64: OpKind = MCK_CPU64Regs; break;
    case Oi::S7_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T8_64: OpKind = MCK_CPU64Regs; break;
    case Oi::T9_64: OpKind = MCK_CPU64Regs; break;
    case Oi::K0_64: OpKind = MCK_CPU64Regs; break;
    case Oi::K1_64: OpKind = MCK_CPU64Regs; break;
    case Oi::GP_64: OpKind = MCK_CPU64Regs; break;
    case Oi::SP_64: OpKind = MCK_Reg7; break;
    case Oi::FP_64: OpKind = MCK_CPU64Regs; break;
    case Oi::RA_64: OpKind = MCK_Reg8; break;
    case Oi::F0: OpKind = MCK_FGR32; break;
    case Oi::F1: OpKind = MCK_FGR32; break;
    case Oi::F2: OpKind = MCK_FGR32; break;
    case Oi::F3: OpKind = MCK_FGR32; break;
    case Oi::F4: OpKind = MCK_FGR32; break;
    case Oi::F5: OpKind = MCK_FGR32; break;
    case Oi::F6: OpKind = MCK_FGR32; break;
    case Oi::F7: OpKind = MCK_FGR32; break;
    case Oi::F8: OpKind = MCK_FGR32; break;
    case Oi::F9: OpKind = MCK_FGR32; break;
    case Oi::F10: OpKind = MCK_FGR32; break;
    case Oi::F11: OpKind = MCK_FGR32; break;
    case Oi::F12: OpKind = MCK_FGR32; break;
    case Oi::F13: OpKind = MCK_FGR32; break;
    case Oi::F14: OpKind = MCK_FGR32; break;
    case Oi::F15: OpKind = MCK_FGR32; break;
    case Oi::F16: OpKind = MCK_FGR32; break;
    case Oi::F17: OpKind = MCK_FGR32; break;
    case Oi::F18: OpKind = MCK_FGR32; break;
    case Oi::F19: OpKind = MCK_FGR32; break;
    case Oi::F20: OpKind = MCK_FGR32; break;
    case Oi::F21: OpKind = MCK_FGR32; break;
    case Oi::F22: OpKind = MCK_FGR32; break;
    case Oi::F23: OpKind = MCK_FGR32; break;
    case Oi::F24: OpKind = MCK_FGR32; break;
    case Oi::F25: OpKind = MCK_FGR32; break;
    case Oi::F26: OpKind = MCK_FGR32; break;
    case Oi::F27: OpKind = MCK_FGR32; break;
    case Oi::F28: OpKind = MCK_FGR32; break;
    case Oi::F29: OpKind = MCK_FGR32; break;
    case Oi::F30: OpKind = MCK_FGR32; break;
    case Oi::F31: OpKind = MCK_FGR32; break;
    case Oi::D0: OpKind = MCK_AFGR64; break;
    case Oi::D1: OpKind = MCK_AFGR64; break;
    case Oi::D2: OpKind = MCK_AFGR64; break;
    case Oi::D3: OpKind = MCK_AFGR64; break;
    case Oi::D4: OpKind = MCK_AFGR64; break;
    case Oi::D5: OpKind = MCK_AFGR64; break;
    case Oi::D6: OpKind = MCK_AFGR64; break;
    case Oi::D7: OpKind = MCK_AFGR64; break;
    case Oi::D8: OpKind = MCK_AFGR64; break;
    case Oi::D9: OpKind = MCK_AFGR64; break;
    case Oi::D10: OpKind = MCK_AFGR64; break;
    case Oi::D11: OpKind = MCK_AFGR64; break;
    case Oi::D12: OpKind = MCK_AFGR64; break;
    case Oi::D13: OpKind = MCK_AFGR64; break;
    case Oi::D14: OpKind = MCK_AFGR64; break;
    case Oi::D15: OpKind = MCK_AFGR64; break;
    case Oi::D0_64: OpKind = MCK_FGR64; break;
    case Oi::D1_64: OpKind = MCK_FGR64; break;
    case Oi::D2_64: OpKind = MCK_FGR64; break;
    case Oi::D3_64: OpKind = MCK_FGR64; break;
    case Oi::D4_64: OpKind = MCK_FGR64; break;
    case Oi::D5_64: OpKind = MCK_FGR64; break;
    case Oi::D6_64: OpKind = MCK_FGR64; break;
    case Oi::D7_64: OpKind = MCK_FGR64; break;
    case Oi::D8_64: OpKind = MCK_FGR64; break;
    case Oi::D9_64: OpKind = MCK_FGR64; break;
    case Oi::D10_64: OpKind = MCK_FGR64; break;
    case Oi::D11_64: OpKind = MCK_FGR64; break;
    case Oi::D12_64: OpKind = MCK_FGR64; break;
    case Oi::D13_64: OpKind = MCK_FGR64; break;
    case Oi::D14_64: OpKind = MCK_FGR64; break;
    case Oi::D15_64: OpKind = MCK_FGR64; break;
    case Oi::D16_64: OpKind = MCK_FGR64; break;
    case Oi::D17_64: OpKind = MCK_FGR64; break;
    case Oi::D18_64: OpKind = MCK_FGR64; break;
    case Oi::D19_64: OpKind = MCK_FGR64; break;
    case Oi::D20_64: OpKind = MCK_FGR64; break;
    case Oi::D21_64: OpKind = MCK_FGR64; break;
    case Oi::D22_64: OpKind = MCK_FGR64; break;
    case Oi::D23_64: OpKind = MCK_FGR64; break;
    case Oi::D24_64: OpKind = MCK_FGR64; break;
    case Oi::D25_64: OpKind = MCK_FGR64; break;
    case Oi::D26_64: OpKind = MCK_FGR64; break;
    case Oi::D27_64: OpKind = MCK_FGR64; break;
    case Oi::D28_64: OpKind = MCK_FGR64; break;
    case Oi::D29_64: OpKind = MCK_FGR64; break;
    case Oi::D30_64: OpKind = MCK_FGR64; break;
    case Oi::D31_64: OpKind = MCK_FGR64; break;
    case Oi::HI: OpKind = MCK_HILO; break;
    case Oi::LO: OpKind = MCK_HILO; break;
    case Oi::HI64: OpKind = MCK_HILO64; break;
    case Oi::LO64: OpKind = MCK_HILO64; break;
    case Oi::FCR31: OpKind = MCK_CCR; break;
    case Oi::FCC0: OpKind = MCK_FCC0; break;
    case Oi::PC: OpKind = MCK_PC; break;
    case Oi::HWR29: OpKind = MCK_HWRegs; break;
    case Oi::HWR29_64: OpKind = MCK_HWRegs64; break;
    case Oi::AC0: OpKind = MCK_Reg19; break;
    case Oi::AC1: OpKind = MCK_ACRegs; break;
    case Oi::AC2: OpKind = MCK_ACRegs; break;
    case Oi::AC3: OpKind = MCK_ACRegs; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

unsigned OiAsmParser::
ComputeAvailableFeatures(uint64_t FB) const {
  unsigned Features = 0;
  if (((FB & Oi::FeatureSEInReg) != 0))
    Features |= Feature_HasSEInReg;
  if (((FB & Oi::FeatureBitCount) != 0))
    Features |= Feature_HasBitCount;
  if (((FB & Oi::FeatureSwap) != 0))
    Features |= Feature_HasSwap;
  if (((FB & Oi::FeatureCondMov) != 0))
    Features |= Feature_HasCondMov;
  if (((FB & Oi::FeatureFPIdx) != 0))
    Features |= Feature_HasFPIdx;
  if (((FB & Oi::FeatureOi32) != 0))
    Features |= Feature_HasOi32;
  if (((FB & Oi::FeatureOi32r2) != 0))
    Features |= Feature_HasOi32r2;
  if (((FB & Oi::FeatureOi64) != 0))
    Features |= Feature_HasOi64;
  if (((FB & Oi::FeatureOi64) == 0))
    Features |= Feature_NotOi64;
  if (((FB & Oi::FeatureOi64r2) != 0))
    Features |= Feature_HasOi64r2;
  if (((FB & Oi::FeatureN64) != 0))
    Features |= Feature_IsN64;
  if (((FB & Oi::FeatureN64) == 0))
    Features |= Feature_NotN64;
  if (((FB & Oi::FeatureOi16) != 0))
    Features |= Feature_InOi16Mode;
  if (((FB & Oi::FeatureOi32) != 0))
    Features |= Feature_RelocStatic;
  if (((FB & Oi::FeatureOi32) != 0))
    Features |= Feature_RelocPIC;
  if (((FB & Oi::FeatureOi32) != 0))
    Features |= Feature_NoNaNsFPMath;
  if (((FB & Oi::FeatureOi16) == 0))
    Features |= Feature_HasStdEnc;
  if (((FB & Oi::FeatureFP64Bit) != 0))
    Features |= Feature_IsFP64bit;
  if (((FB & Oi::FeatureFP64Bit) == 0))
    Features |= Feature_NotFP64bit;
  if (((FB & Oi::FeatureSingleFloat) != 0))
    Features |= Feature_IsSingleFloat;
  if (((FB & Oi::FeatureSingleFloat) == 0))
    Features |= Feature_IsNotSingleFloat;
  if (((FB & Oi::FeatureDSP) != 0))
    Features |= Feature_HasDSP;
  if (((FB & Oi::FeatureDSPR2) != 0))
    Features |= Feature_HasDSPR2;
  return Features;
}

static const char *const MnemonicTable =
    "\003abs\006absq_s\003add\004addi\005addiu\004addq\006addq_s\005addqh\007"
    "addqh_r\005addsc\004addu\006addu_s\005adduh\007adduh_r\005addwc\003and\004"
    "andi\006append\001b\003bal\006balign\004bc1f\004bc1t\003beq\004beqz\004"
    "bgez\006bgezal\004bgtz\006bitrev\004blez\004bltz\006bltzal\003bne\004bn"
    "ez\010bposge32\005bteqz\005btnez\001c\004ceil\004cfc1\003clo\003clz\003"
    "cmp\006cmpgdu\005cmpgu\004cmpu\004ctc1\003cvt\004dadd\005daddi\006daddi"
    "u\005daddu\004dclo\004dclz\004ddiv\005ddivu\004dext\005dextm\005dextu\004"
    "dins\005dinsm\005dinsu\003div\004divu\005dmfc0\005dmfc1\005dmfc2\005dmt"
    "c0\005dmtc1\005dmtc2\005dmult\006dmultu\003dpa\006dpaq_s\007dpaq_sa\007"
    "dpaqx_s\010dpaqx_sa\004dpau\004dpax\003dps\006dpsq_s\007dpsq_sa\007dpsq"
    "x_s\010dpsqx_sa\004dpsu\004dpsx\005drotr\006drotrv\004dsbh\004dshd\004d"
    "sll\006dsll32\005dsllv\004dsra\006dsra32\005dsrav\004dsrl\006dsrl32\005"
    "dsrlv\005dsubu\003ext\004extp\006extpdp\007extpdpv\005extpv\004extr\006"
    "extr_r\007extr_rs\006extr_s\005extrv\007extrv_r\010extrv_rs\007extrv_s\005"
    "floor\003ins\004insv\001j\003jal\004jalr\005jalrc\002jr\003jrc\002la\002"
    "lb\003lbu\004lbux\002ld\004ldc1\003ldl\003ldr\005ldxc1\002lh\003lhu\003"
    "lhx\002li\002ll\003lld\003lui\005luxc1\002lw\004lwc1\003lwl\003lwr\003l"
    "wu\003lwx\005lwxc1\004madd\005maddu\005maq_s\006maq_sa\004mfc0\004mfc1\004"
    "mfc2\004mfhi\004mflo\006modsub\003mov\004move\004movf\004movn\004movt\004"
    "movz\004msub\005msubu\004mtc0\004mtc1\004mtc2\004mthi\006mthlip\004mtlo"
    "\003mul\005mul_s\007muleq_s\007muleu_s\007mulq_rs\006mulq_s\005mulsa\010"
    "mulsaq_s\004mult\005multu\003neg\004negu\005nmadd\005nmsub\003nop\003no"
    "r\003not\002or\003ori\006packrl\004pick\006preceq\007precequ\006preceu\005"
    "precr\tprecr_sra\013precr_sra_r\006precrq\tprecrq_rs\tprecrqu_s\007prep"
    "end\005raddu\005rddsp\005rdhwr\004repl\005replv\004rotr\005rotrv\005rou"
    "nd\002sb\002sc\003scd\002sd\004sdc1\003sdl\003sdr\005sdxc1\003seb\003se"
    "h\002sh\005shilo\006shilov\004shll\006shll_s\005shllv\007shllv_s\004shr"
    "a\006shra_r\005shrav\007shrav_r\004shrl\005shrlv\003sll\004sllv\003slt\004"
    "slti\005sltiu\004sltu\004sqrt\003sra\004srav\003srl\004srlv\003sub\004s"
    "ubq\006subq_s\005subqh\007subqh_r\004subu\006subu_s\005subuh\007subuh_r"
    "\005suxc1\002sw\004swc1\003swl\003swr\005swxc1\004sync\005trunc\005wrds"
    "p\004wsbh\003xor\004xori";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint32_t RequiredFeatures;
    uint8_t Classes[5];
    uint8_t AsmVariantID;

    StringRef getMnemonic() const {
      return StringRef(MnemonicTable + Mnemonic + 1,
                       MnemonicTable[Mnemonic]);
    }
  };

  // Predicate for searching for an opcode.
  struct LessOpcode {
    bool operator()(const MatchEntry &LHS, StringRef RHS) {
      return LHS.getMnemonic() < RHS;
    }
    bool operator()(StringRef LHS, const MatchEntry &RHS) {
      return LHS < RHS.getMnemonic();
    }
    bool operator()(const MatchEntry &LHS, const MatchEntry &RHS) {
      return LHS.getMnemonic() < RHS.getMnemonic();
    }
  };
} // end anonymous namespace.

static const MatchEntry MatchTable[512] = {
  { 0 /* abs */, Oi::FABS_D32, Convert__Reg1_1__Reg1_2, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 0 /* abs */, Oi::FABS_D64, Convert__Reg1_1__Reg1_2, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 0 /* abs */, Oi::FABS_S, Convert__Reg1_1__Reg1_2, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 4 /* absq_s */, Oi::ABSQ_S_PH, Convert__Reg1_1__Reg1_2, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs }, 0},
  { 4 /* absq_s */, Oi::ABSQ_S_QB, Convert__Reg1_1__Reg1_2, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs }, 0},
  { 4 /* absq_s */, Oi::ABSQ_S_W, Convert__Reg1_1__Reg1_2, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs }, 0},
  { 11 /* add */, Oi::ADD, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 11 /* add */, Oi::ADDi, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 11 /* add */, Oi::FADD_D32, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 11 /* add */, Oi::FADD_D64, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_FGR64 }, 0},
  { 11 /* add */, Oi::FADD_S, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 15 /* addi */, Oi::ADDi, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 20 /* addiu */, Oi::AddiuRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_Imm }, 0},
  { 20 /* addiu */, Oi::AddiuRxRxImmX16, Convert__Reg1_0__Tie0__Imm1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_Imm }, 0},
  { 20 /* addiu */, Oi::AddiuSpImmX16, Convert__Imm1_1, Feature_InOi16Mode, { MCK_CPUSPReg, MCK_Imm }, 0},
  { 20 /* addiu */, Oi::AddiuRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm }, 0},
  { 20 /* addiu */, Oi::AddiuRxPcImmX16, Convert__Reg1_0__Imm1_2, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_PC, MCK_Imm }, 0},
  { 20 /* addiu */, Oi::ADDiu, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 26 /* addq */, Oi::ADDQ_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 31 /* addq_s */, Oi::ADDQ_S_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 31 /* addq_s */, Oi::ADDQ_S_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 38 /* addqh */, Oi::ADDQH_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 38 /* addqh */, Oi::ADDQH_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 44 /* addqh_r */, Oi::ADDQH_R_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 44 /* addqh_r */, Oi::ADDQH_R_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 52 /* addsc */, Oi::ADDSC, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 58 /* addu */, Oi::AdduRxRyRz16, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 58 /* addu */, Oi::ADDu, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 58 /* addu */, Oi::ADDiu, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 58 /* addu */, Oi::ADDU_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 58 /* addu */, Oi::ADDU_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 63 /* addu_s */, Oi::ADDU_S_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 63 /* addu_s */, Oi::ADDU_S_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 70 /* adduh */, Oi::ADDUH_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 76 /* adduh_r */, Oi::ADDUH_R_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 84 /* addwc */, Oi::ADDWC, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 90 /* and */, Oi::AndRxRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 90 /* and */, Oi::AND64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 90 /* and */, Oi::DANDi, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasOi64, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 90 /* and */, Oi::AND, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 90 /* and */, Oi::ANDi, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 94 /* andi */, Oi::DANDi, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 94 /* andi */, Oi::ANDi, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 99 /* append */, Oi::APPEND, Convert__Reg1_0__Reg1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 106 /* b */, Oi::B, Convert__Imm1_0, Feature_RelocPIC|Feature_HasStdEnc, { MCK_Imm }, 0},
  { 106 /* b */, Oi::BimmX16, Convert__Imm1_0, Feature_InOi16Mode, { MCK_Imm }, 0},
  { 108 /* bal */, Oi::BAL_BR, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, 0},
  { 108 /* bal */, Oi::BGEZAL, Convert__regRA__Imm1_0, 0, { MCK_Imm }, 0},
  { 112 /* balign */, Oi::BALIGN, Convert__Reg1_0__Reg1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 119 /* bc1f */, Oi::BC1F, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, 0},
  { 124 /* bc1t */, Oi::BC1T, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, 0},
  { 129 /* beq */, Oi::BEQ, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 129 /* beq */, Oi::BEQ64, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs, MCK_Imm }, 0},
  { 133 /* beqz */, Oi::BeqzRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_Imm }, 0},
  { 138 /* bgez */, Oi::BGEZ, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_Imm }, 0},
  { 138 /* bgez */, Oi::BGEZ64, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Imm }, 0},
  { 143 /* bgezal */, Oi::BGEZAL, Convert__CPURegsAsm1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_Imm }, 0},
  { 150 /* bgtz */, Oi::BGTZ, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_Imm }, 0},
  { 150 /* bgtz */, Oi::BGTZ64, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Imm }, 0},
  { 155 /* bitrev */, Oi::BITREV, Convert__Reg1_0__Reg1_1, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs }, 0},
  { 162 /* blez */, Oi::BLEZ, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_Imm }, 0},
  { 162 /* blez */, Oi::BLEZ64, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Imm }, 0},
  { 167 /* bltz */, Oi::BLTZ, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_Imm }, 0},
  { 167 /* bltz */, Oi::BLTZ64, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Imm }, 0},
  { 172 /* bltzal */, Oi::BLTZAL, Convert__CPURegsAsm1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_Imm }, 0},
  { 179 /* bne */, Oi::BNE, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 179 /* bne */, Oi::BNE64, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs, MCK_Imm }, 0},
  { 183 /* bnez */, Oi::BnezRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_Imm }, 0},
  { 188 /* bposge32 */, Oi::BPOSGE32, Convert__Imm1_0, Feature_HasDSP, { MCK_Imm }, 0},
  { 197 /* bteqz */, Oi::BteqzX16, Convert__Imm1_0, Feature_InOi16Mode, { MCK_Imm }, 0},
  { 203 /* btnez */, Oi::BtnezX16, Convert__Imm1_0, Feature_InOi16Mode, { MCK_Imm }, 0},
  { 209 /* c */, Oi::FCMP_D32, Convert__Reg1_3__Reg1_4__Imm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_, MCK_Imm, MCK__DOT_d, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 209 /* c */, Oi::FCMP_D64, Convert__Reg1_3__Reg1_4__Imm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_, MCK_Imm, MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 209 /* c */, Oi::FCMP_S32, Convert__Reg1_3__Reg1_4__Imm1_1, Feature_HasStdEnc, { MCK__DOT_, MCK_Imm, MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 211 /* ceil */, Oi::CEIL_L_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 211 /* ceil */, Oi::CEIL_L_S, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_s, MCK_FGR64, MCK_FGR32 }, 0},
  { 211 /* ceil */, Oi::CEIL_W_D32, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_AFGR64 }, 0},
  { 211 /* ceil */, Oi::CEIL_W_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_FGR64 }, 0},
  { 211 /* ceil */, Oi::CEIL_W_S, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 216 /* cfc1 */, Oi::CFC1, Convert__Reg1_0__CCRAsm1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_CCRAsm }, 0},
  { 221 /* clo */, Oi::CLO, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 225 /* clz */, Oi::CLZ, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 229 /* cmp */, Oi::CMP_EQ_PH, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_eq, MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs }, 0},
  { 229 /* cmp */, Oi::CMP_LE_PH, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_le, MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs }, 0},
  { 229 /* cmp */, Oi::CMP_LT_PH, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_lt, MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs }, 0},
  { 233 /* cmpgdu */, Oi::CMPGDU_EQ_QB, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_eq, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 233 /* cmpgdu */, Oi::CMPGDU_LE_QB, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_le, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 233 /* cmpgdu */, Oi::CMPGDU_LT_QB, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_lt, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 240 /* cmpgu */, Oi::CMPGU_EQ_QB, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_eq, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 240 /* cmpgu */, Oi::CMPGU_LE_QB, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_le, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 240 /* cmpgu */, Oi::CMPGU_LT_QB, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_lt, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 246 /* cmpu */, Oi::CMPU_EQ_QB, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_eq, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs }, 0},
  { 246 /* cmpu */, Oi::CMPU_LE_QB, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_le, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs }, 0},
  { 246 /* cmpu */, Oi::CMPU_LT_QB, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_lt, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs }, 0},
  { 251 /* ctc1 */, Oi::CTC1, Convert__CCRAsm1_1__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs, MCK_CCRAsm }, 0},
  { 256 /* cvt */, Oi::CVT_D64_L, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK__DOT_l, MCK_FGR64, MCK_FGR64 }, 0},
  { 256 /* cvt */, Oi::CVT_D32_S, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK__DOT_s, MCK_AFGR64, MCK_FGR32 }, 0},
  { 256 /* cvt */, Oi::CVT_D64_S, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK__DOT_s, MCK_FGR64, MCK_FGR32 }, 0},
  { 256 /* cvt */, Oi::CVT_D32_W, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK__DOT_w, MCK_AFGR64, MCK_FGR32 }, 0},
  { 256 /* cvt */, Oi::CVT_D64_W, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK__DOT_w, MCK_FGR64, MCK_FGR32 }, 0},
  { 256 /* cvt */, Oi::CVT_L_D64, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 256 /* cvt */, Oi::CVT_L_S, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_s, MCK_FGR64, MCK_FGR32 }, 0},
  { 256 /* cvt */, Oi::CVT_S_D32, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_s, MCK__DOT_d, MCK_FGR32, MCK_AFGR64 }, 0},
  { 256 /* cvt */, Oi::CVT_S_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_s, MCK__DOT_d, MCK_FGR32, MCK_FGR64 }, 0},
  { 256 /* cvt */, Oi::CVT_S_L, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_s, MCK__DOT_l, MCK_FGR32, MCK_FGR64 }, 0},
  { 256 /* cvt */, Oi::CVT_S_W, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_s, MCK__DOT_w, MCK_FGR32, MCK_FGR32 }, 0},
  { 256 /* cvt */, Oi::CVT_W_D32, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_AFGR64 }, 0},
  { 256 /* cvt */, Oi::CVT_W_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_FGR64 }, 0},
  { 256 /* cvt */, Oi::CVT_W_S, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 260 /* dadd */, Oi::DADD, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 260 /* dadd */, Oi::DADDi, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, 0, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 265 /* daddi */, Oi::DADDi, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 271 /* daddiu */, Oi::DADDiu, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 278 /* daddu */, Oi::DADDu, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 278 /* daddu */, Oi::DADDiu, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, 0, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 284 /* dclo */, Oi::DCLO, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 289 /* dclz */, Oi::DCLZ, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 294 /* ddiv */, Oi::DSDIV, Convert__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 299 /* ddivu */, Oi::DUDIV, Convert__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 305 /* dext */, Oi::DEXT, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 310 /* dextm */, Oi::DEXTM, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 316 /* dextu */, Oi::DEXTU, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 322 /* dins */, Oi::DINS, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 327 /* dinsm */, Oi::DINSM, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 333 /* dinsu */, Oi::DINSU, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 339 /* div */, Oi::DivRxRy16, Convert__Reg1_1__Reg1_2, Feature_InOi16Mode, { MCK_ZERO, MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 339 /* div */, Oi::SDIV, Convert__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 339 /* div */, Oi::FDIV_D32, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 339 /* div */, Oi::FDIV_D64, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_FGR64 }, 0},
  { 339 /* div */, Oi::FDIV_S, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 343 /* divu */, Oi::DivuRxRy16, Convert__Reg1_1__Reg1_2, Feature_InOi16Mode, { MCK_ZERO, MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 343 /* divu */, Oi::UDIV, Convert__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 348 /* dmfc0 */, Oi::DMFC0_3OP64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__imm_0, 0, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 348 /* dmfc0 */, Oi::DMFC0_3OP64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 354 /* dmfc1 */, Oi::DMFC1, Convert__Reg1_0__Reg1_1, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_FGR64 }, 0},
  { 360 /* dmfc2 */, Oi::DMFC2_3OP64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__imm_0, 0, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 360 /* dmfc2 */, Oi::DMFC2_3OP64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 366 /* dmtc0 */, Oi::DMTC0_3OP64, Convert__CPU64RegsAsm1_1__imm_0__CPU64RegsAsm1_0, 0, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 366 /* dmtc0 */, Oi::DMTC0_3OP64, Convert__CPU64RegsAsm1_1__Imm1_2__CPU64RegsAsm1_0, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 372 /* dmtc1 */, Oi::DMTC1, Convert__Reg1_1__Reg1_0, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_FGR64 }, 0},
  { 378 /* dmtc2 */, Oi::DMTC2_3OP64, Convert__CPU64RegsAsm1_1__imm_0__CPU64RegsAsm1_0, 0, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 378 /* dmtc2 */, Oi::DMTC2_3OP64, Convert__CPU64RegsAsm1_1__Imm1_2__CPU64RegsAsm1_0, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 384 /* dmult */, Oi::DMULT, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 390 /* dmultu */, Oi::DMULTu, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 397 /* dpa */, Oi::DPA_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 401 /* dpaq_s */, Oi::DPAQ_S_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 408 /* dpaq_sa */, Oi::DPAQ_SA_L_W, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_l, MCK__DOT_w, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 416 /* dpaqx_s */, Oi::DPAQX_S_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 424 /* dpaqx_sa */, Oi::DPAQX_SA_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 433 /* dpau */, Oi::DPAU_H_QBL, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_h, MCK__DOT_qbl, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 433 /* dpau */, Oi::DPAU_H_QBR, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_h, MCK__DOT_qbr, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 438 /* dpax */, Oi::DPAX_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 443 /* dps */, Oi::DPS_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 447 /* dpsq_s */, Oi::DPSQ_S_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 454 /* dpsq_sa */, Oi::DPSQ_SA_L_W, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_l, MCK__DOT_w, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 462 /* dpsqx_s */, Oi::DPSQX_S_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 470 /* dpsqx_sa */, Oi::DPSQX_SA_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 479 /* dpsu */, Oi::DPSU_H_QBL, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_h, MCK__DOT_qbl, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 479 /* dpsu */, Oi::DPSU_H_QBR, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_h, MCK__DOT_qbr, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 484 /* dpsx */, Oi::DPSX_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 489 /* drotr */, Oi::DROTR, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasOi64r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 495 /* drotrv */, Oi::DROTRV, Convert__CPU64RegsAsm1_0__CPURegsAsm1_2__CPU64RegsAsm1_1, Feature_HasOi64r2|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPURegsAsm }, 0},
  { 502 /* dsbh */, Oi::DSBH, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1, Feature_HasSwap|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 507 /* dshd */, Oi::DSHD, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1, Feature_HasSwap|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 512 /* dsll */, Oi::DSLL, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 517 /* dsll32 */, Oi::DSLL32, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 524 /* dsllv */, Oi::DSLLV, Convert__CPU64RegsAsm1_0__CPURegsAsm1_2__CPU64RegsAsm1_1, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPURegsAsm }, 0},
  { 530 /* dsra */, Oi::DSRA, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 535 /* dsra32 */, Oi::DSRA32, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 542 /* dsrav */, Oi::DSRAV, Convert__CPU64RegsAsm1_0__CPURegsAsm1_2__CPU64RegsAsm1_1, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPURegsAsm }, 0},
  { 548 /* dsrl */, Oi::DSRL, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 553 /* dsrl32 */, Oi::DSRL32, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 560 /* dsrlv */, Oi::DSRLV, Convert__CPU64RegsAsm1_0__CPURegsAsm1_2__CPU64RegsAsm1_1, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPURegsAsm }, 0},
  { 566 /* dsubu */, Oi::DSUBu, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 572 /* ext */, Oi::EXT, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2__Imm1_3, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 576 /* extp */, Oi::EXTP, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_HasDSP, { MCK_CPURegs, MCK_ACRegs, MCK_Imm }, 0},
  { 581 /* extpdp */, Oi::EXTPDP, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_HasDSP, { MCK_CPURegs, MCK_ACRegs, MCK_Imm }, 0},
  { 588 /* extpdpv */, Oi::EXTPDPV, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_CPURegs, MCK_ACRegs, MCK_CPURegs }, 0},
  { 596 /* extpv */, Oi::EXTPV, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_CPURegs, MCK_ACRegs, MCK_CPURegs }, 0},
  { 602 /* extr */, Oi::EXTR_W, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_ACRegs, MCK_Imm }, 0},
  { 607 /* extr_r */, Oi::EXTR_R_W, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_ACRegs, MCK_Imm }, 0},
  { 614 /* extr_rs */, Oi::EXTR_RS_W, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_ACRegs, MCK_Imm }, 0},
  { 622 /* extr_s */, Oi::EXTR_S_H, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_h, MCK_CPURegs, MCK_ACRegs, MCK_Imm }, 0},
  { 629 /* extrv */, Oi::EXTRV_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_ACRegs, MCK_CPURegs }, 0},
  { 635 /* extrv_r */, Oi::EXTRV_R_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_ACRegs, MCK_CPURegs }, 0},
  { 643 /* extrv_rs */, Oi::EXTRV_RS_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_ACRegs, MCK_CPURegs }, 0},
  { 652 /* extrv_s */, Oi::EXTRV_S_H, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_h, MCK_CPURegs, MCK_ACRegs, MCK_CPURegs }, 0},
  { 660 /* floor */, Oi::FLOOR_L_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 660 /* floor */, Oi::FLOOR_L_S, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_s, MCK_FGR64, MCK_FGR32 }, 0},
  { 660 /* floor */, Oi::FLOOR_W_D32, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_AFGR64 }, 0},
  { 660 /* floor */, Oi::FLOOR_W_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_FGR64 }, 0},
  { 660 /* floor */, Oi::FLOOR_W_S, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 666 /* ins */, Oi::INS, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm, MCK_Imm }, 0},
  { 670 /* insv */, Oi::INSV, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs }, 0},
  { 675 /* j */, Oi::JR, Convert__Reg1_0, Feature_NotOi64, { MCK_CPURegs }, 0},
  { 675 /* j */, Oi::JR64, Convert__Reg1_0, Feature_HasOi64, { MCK_CPU64Regs }, 0},
  { 675 /* j */, Oi::J, Convert__Imm1_0, Feature_RelocStatic|Feature_HasStdEnc, { MCK_Imm }, 0},
  { 677 /* jal */, Oi::JAL, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, 0},
  { 681 /* jalr */, Oi::JALR, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs }, 0},
  { 681 /* jalr */, Oi::JALR64, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPU64Regs }, 0},
  { 686 /* jalrc */, Oi::JumpLinkReg16, Convert__Reg1_0, Feature_InOi16Mode, { MCK_CPU16Regs }, 0},
  { 692 /* jr */, Oi::JrRa16, Convert_NoOperands, Feature_InOi16Mode, { MCK_CPURAReg }, 0},
  { 692 /* jr */, Oi::JR, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs }, 0},
  { 692 /* jr */, Oi::JR64, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPU64Regs }, 0},
  { 695 /* jrc */, Oi::JrcRx16, Convert__Reg1_0, Feature_InOi16Mode, { MCK_CPU16Regs }, 0},
  { 695 /* jrc */, Oi::JrcRa16, Convert_NoOperands, Feature_InOi16Mode, { MCK_CPURAReg }, 0},
  { 699 /* la */, Oi::LoadAddr32Imm, Convert__CPURegsAsm1_0__Imm1_1, 0, { MCK_CPURegsAsm, MCK_Imm }, 0},
  { 699 /* la */, Oi::LoadAddr32Reg, Convert__CPURegsAsm1_0__Mem2_1, 0, { MCK_CPURegsAsm, MCK_Mem }, 0},
  { 702 /* lb */, Oi::LB, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 702 /* lb */, Oi::LB64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 702 /* lb */, Oi::LbRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 705 /* lbu */, Oi::LBu, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 705 /* lbu */, Oi::LBu64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 705 /* lbu */, Oi::LbuRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 709 /* lbux */, Oi::LBUX, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 714 /* ld */, Oi::LD, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 717 /* ldc1 */, Oi::LDC1, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_NotOi64|Feature_HasStdEnc, { MCK_AFGR64, MCK_Mem }, 0},
  { 717 /* ldc1 */, Oi::LDC164, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasOi64|Feature_HasStdEnc, { MCK_FGR64, MCK_Mem }, 0},
  { 722 /* ldl */, Oi::LDL, Convert__Reg1_0__Mem2_1__Tie0, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 726 /* ldr */, Oi::LDR, Convert__Reg1_0__Mem2_1__Tie0, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 730 /* ldxc1 */, Oi::LDXC1, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasOi32r2|Feature_NotOi64|Feature_HasStdEnc, { MCK_AFGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 730 /* ldxc1 */, Oi::LDXC164, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasOi64|Feature_NotN64|Feature_HasStdEnc, { MCK_FGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 736 /* lh */, Oi::LH, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 736 /* lh */, Oi::LH64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 736 /* lh */, Oi::LhRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 739 /* lhu */, Oi::LHu, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 739 /* lhu */, Oi::LHu64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 739 /* lhu */, Oi::LhuRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 743 /* lhx */, Oi::LHX, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 747 /* li */, Oi::LiRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_Imm }, 0},
  { 747 /* li */, Oi::LoadImm32Reg, Convert__CPURegsAsm1_0__Imm1_1, 0, { MCK_CPURegsAsm, MCK_Imm }, 0},
  { 750 /* ll */, Oi::LL, Convert__CPURegsAsm1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_Mem }, 0},
  { 750 /* ll */, Oi::LL_P8, Convert__CPURegsAsm1_0__Mem2_1, Feature_IsN64|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_Mem }, 0},
  { 753 /* lld */, Oi::LLD, Convert__CPU64RegsAsm1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_Mem }, 0},
  { 757 /* lui */, Oi::LUi, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_Imm }, 0},
  { 757 /* lui */, Oi::LUi64, Convert__Reg1_0__Imm1_1, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Imm }, 0},
  { 761 /* luxc1 */, Oi::LUXC1, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_NotOi64|Feature_HasStdEnc, { MCK_AFGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 761 /* luxc1 */, Oi::LUXC164, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasOi64|Feature_HasStdEnc, { MCK_FGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 767 /* lw */, Oi::LW, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 767 /* lw */, Oi::LW64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 767 /* lw */, Oi::LwRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 767 /* lw */, Oi::LwRxSpImmX16, Convert__Reg1_0__Reg1_3__Imm1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__40_, MCK_CPUSPReg, MCK__41__59_ }, 0},
  { 770 /* lwc1 */, Oi::LWC1, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_FGR32, MCK_Mem }, 0},
  { 770 /* lwc1 */, Oi::LWC1_P8, Convert__Reg1_0__Mem2_1, Feature_IsN64|Feature_HasStdEnc, { MCK_FGR32, MCK_Mem }, 0},
  { 775 /* lwl */, Oi::LWL, Convert__Reg1_0__Mem2_1__Tie0, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 775 /* lwl */, Oi::LWL64, Convert__Reg1_0__Mem2_1__Tie0, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 779 /* lwr */, Oi::LWR, Convert__Reg1_0__Mem2_1__Tie0, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 779 /* lwr */, Oi::LWR64, Convert__Reg1_0__Mem2_1__Tie0, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 783 /* lwu */, Oi::LWu64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 787 /* lwx */, Oi::LWX, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 791 /* lwxc1 */, Oi::LWXC1, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasFPIdx|Feature_HasStdEnc, { MCK_FGR32, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 797 /* madd */, Oi::MADD, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 797 /* madd */, Oi::MADD_DSP, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 797 /* madd */, Oi::MADD_D32, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 797 /* madd */, Oi::MADD_S, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 802 /* maddu */, Oi::MADDU, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 802 /* maddu */, Oi::MADDU_DSP, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 808 /* maq_s */, Oi::MAQ_S_W_PHL, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phl, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 808 /* maq_s */, Oi::MAQ_S_W_PHR, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phr, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 814 /* maq_sa */, Oi::MAQ_SA_W_PHL, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phl, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 814 /* maq_sa */, Oi::MAQ_SA_W_PHR, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phr, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 821 /* mfc0 */, Oi::MFC0_3OP, Convert__CPURegsAsm1_0__CPURegsAsm1_1__imm_0, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 821 /* mfc0 */, Oi::MFC0_3OP, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 826 /* mfc1 */, Oi::MFC1, Convert__Reg1_0__Reg1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_FGR32 }, 0},
  { 831 /* mfc2 */, Oi::MFC2_3OP, Convert__CPURegsAsm1_0__CPURegsAsm1_1__imm_0, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 831 /* mfc2 */, Oi::MFC2_3OP, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 836 /* mfhi */, Oi::Mfhi16, Convert__Reg1_0, Feature_InOi16Mode, { MCK_CPU16Regs }, 0},
  { 836 /* mfhi */, Oi::MFHI, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs }, 0},
  { 836 /* mfhi */, Oi::MFHI64, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPU64Regs }, 0},
  { 841 /* mflo */, Oi::Mflo16, Convert__Reg1_0, Feature_InOi16Mode, { MCK_CPU16Regs }, 0},
  { 841 /* mflo */, Oi::MFLO, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs }, 0},
  { 841 /* mflo */, Oi::MFLO64, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPU64Regs }, 0},
  { 846 /* modsub */, Oi::MODSUB, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 853 /* mov */, Oi::FMOV_D32, Convert__Reg1_1__Reg1_2, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 853 /* mov */, Oi::FMOV_D64, Convert__Reg1_1__Reg1_2, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 853 /* mov */, Oi::FMOV_S, Convert__Reg1_1__Reg1_2, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 857 /* move */, Oi::MoveR3216, Convert__Reg1_0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPURegs }, 0},
  { 857 /* move */, Oi::Move32R16, Convert__Reg1_0__Reg1_1, Feature_InOi16Mode, { MCK_CPURegs, MCK_CPU16Regs }, 0},
  { 857 /* move */, Oi::DADDu, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__regZERO_64, Feature_HasOi64, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 857 /* move */, Oi::ADDu, Convert__CPURegsAsm1_0__CPURegsAsm1_1__regZERO, Feature_NotOi64, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 862 /* movf */, Oi::MOVF_I, Convert__Reg1_0__Reg1_1__Tie0, Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs, MCK_FCC0 }, 0},
  { 862 /* movf */, Oi::MOVF_I64, Convert__Reg1_0__Reg1_1__Tie0, Feature_HasOi64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs, MCK_FCC0 }, 0},
  { 862 /* movf */, Oi::MOVF_D32, Convert__Reg1_1__Reg1_2__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_FCC0 }, 0},
  { 862 /* movf */, Oi::MOVF_D64, Convert__Reg1_1__Reg1_2__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_FCC0 }, 0},
  { 862 /* movf */, Oi::MOVF_S, Convert__Reg1_1__Reg1_2__Tie0, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FCC0 }, 0},
  { 867 /* movn */, Oi::MOVN_I_I, Convert__Reg1_0__Reg1_1__Reg1_2__Tie0, Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 867 /* movn */, Oi::MOVN_I_I64, Convert__Reg1_0__Reg1_1__Reg1_2__Tie0, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs, MCK_CPURegs }, 0},
  { 867 /* movn */, Oi::MOVN_I_D32, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_CPURegs }, 0},
  { 867 /* movn */, Oi::MOVN_I_D64, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_CPURegs }, 0},
  { 867 /* movn */, Oi::MOVN_I_S, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_CPURegs }, 0},
  { 867 /* movn */, Oi::MOVN_I64_S, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_HasOi64|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_CPU64Regs }, 0},
  { 872 /* movt */, Oi::MOVT_I, Convert__Reg1_0__Reg1_1__Tie0, Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs, MCK_FCC0 }, 0},
  { 872 /* movt */, Oi::MOVT_I64, Convert__Reg1_0__Reg1_1__Tie0, Feature_HasOi64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs, MCK_FCC0 }, 0},
  { 872 /* movt */, Oi::MOVT_D32, Convert__Reg1_1__Reg1_2__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_FCC0 }, 0},
  { 872 /* movt */, Oi::MOVT_D64, Convert__Reg1_1__Reg1_2__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_FCC0 }, 0},
  { 872 /* movt */, Oi::MOVT_S, Convert__Reg1_1__Reg1_2__Tie0, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FCC0 }, 0},
  { 877 /* movz */, Oi::MOVZ_I_I, Convert__Reg1_0__Reg1_1__Reg1_2__Tie0, Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 877 /* movz */, Oi::MOVZ_I_I64, Convert__Reg1_0__Reg1_1__Reg1_2__Tie0, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs, MCK_CPURegs }, 0},
  { 877 /* movz */, Oi::MOVZ_I_D32, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_CPURegs }, 0},
  { 877 /* movz */, Oi::MOVZ_I_D64, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_CPURegs }, 0},
  { 877 /* movz */, Oi::MOVZ_I_S, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_CPURegs }, 0},
  { 877 /* movz */, Oi::MOVZ_I64_S, Convert__Reg1_1__Reg1_2__Reg1_3__Tie0, Feature_HasOi64|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_CPU64Regs }, 0},
  { 882 /* msub */, Oi::MSUB, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 882 /* msub */, Oi::MSUB_DSP, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 882 /* msub */, Oi::MSUB_D32, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 882 /* msub */, Oi::MSUB_S, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 887 /* msubu */, Oi::MSUBU, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 887 /* msubu */, Oi::MSUBU_DSP, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 893 /* mtc0 */, Oi::MTC0_3OP, Convert__CPURegsAsm1_1__imm_0__CPURegsAsm1_0, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 893 /* mtc0 */, Oi::MTC0_3OP, Convert__CPURegsAsm1_1__Imm1_2__CPURegsAsm1_0, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 898 /* mtc1 */, Oi::MTC1, Convert__Reg1_1__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs, MCK_FGR32 }, 0},
  { 903 /* mtc2 */, Oi::MTC2_3OP, Convert__CPURegsAsm1_1__imm_0__CPURegsAsm1_0, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 903 /* mtc2 */, Oi::MTC2_3OP, Convert__CPURegsAsm1_1__Imm1_2__CPURegsAsm1_0, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 908 /* mthi */, Oi::MTHI, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs }, 0},
  { 908 /* mthi */, Oi::MTHI64, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPU64Regs }, 0},
  { 913 /* mthlip */, Oi::MTHLIP, Convert__Reg1_1__Reg1_0, Feature_HasDSP, { MCK_CPURegs, MCK_ACRegs }, 0},
  { 920 /* mtlo */, Oi::MTLO, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPURegs }, 0},
  { 920 /* mtlo */, Oi::MTLO64, Convert__Reg1_0, Feature_HasStdEnc, { MCK_CPU64Regs }, 0},
  { 925 /* mul */, Oi::MUL, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 925 /* mul */, Oi::FMUL_D32, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 925 /* mul */, Oi::FMUL_D64, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_FGR64 }, 0},
  { 925 /* mul */, Oi::MUL_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 925 /* mul */, Oi::FMUL_S, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 929 /* mul_s */, Oi::MUL_S_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 935 /* muleq_s */, Oi::MULEQ_S_W_PHL, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phl, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 935 /* muleq_s */, Oi::MULEQ_S_W_PHR, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phr, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 943 /* muleu_s */, Oi::MULEU_S_PH_QBL, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbl, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 943 /* muleu_s */, Oi::MULEU_S_PH_QBR, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbr, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 951 /* mulq_rs */, Oi::MULQ_RS_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 951 /* mulq_rs */, Oi::MULQ_RS_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 959 /* mulq_s */, Oi::MULQ_S_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 959 /* mulq_s */, Oi::MULQ_S_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 966 /* mulsa */, Oi::MULSA_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 972 /* mulsaq_s */, Oi::MULSAQ_S_W_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_ph, MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 981 /* mult */, Oi::MULT, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 981 /* mult */, Oi::MULT_DSP, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 986 /* multu */, Oi::MULTu, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 986 /* multu */, Oi::MULTU_DSP, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasDSP, { MCK_ACRegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 992 /* neg */, Oi::NegRxRy16, Convert__Reg1_0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 992 /* neg */, Oi::SUB, Convert__CPURegsAsm1_0__regZERO__CPURegsAsm1_1, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 992 /* neg */, Oi::FNEG_D32, Convert__Reg1_1__Reg1_2, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 992 /* neg */, Oi::FNEG_D64, Convert__Reg1_1__Reg1_2, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 992 /* neg */, Oi::FNEG_S, Convert__Reg1_1__Reg1_2, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 996 /* negu */, Oi::SUBu, Convert__CPURegsAsm1_0__regZERO__CPURegsAsm1_1, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1001 /* nmadd */, Oi::NMADD_D32, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_NotFP64bit|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 1001 /* nmadd */, Oi::NMADD_S, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 1007 /* nmsub */, Oi::NMSUB_D32, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_NotFP64bit|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 1007 /* nmsub */, Oi::NMSUB_S, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4, Feature_HasOi32r2|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 1013 /* nop */, Oi::NOP, Convert_NoOperands, Feature_HasStdEnc, {  }, 0},
  { 1017 /* nor */, Oi::NOR64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 1017 /* nor */, Oi::NOR, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1021 /* not */, Oi::NotRxRy16, Convert__Reg1_0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1021 /* not */, Oi::NOR64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__regZERO_64, Feature_HasOi64, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 1021 /* not */, Oi::NOR, Convert__CPURegsAsm1_0__CPURegsAsm1_1__regZERO, 0, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1025 /* or */, Oi::OrRxRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1025 /* or */, Oi::OR64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 1025 /* or */, Oi::OR, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1028 /* ori */, Oi::ORi64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 1028 /* ori */, Oi::ORi, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 1032 /* packrl */, Oi::PACKRL_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1039 /* pick */, Oi::PICK_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1039 /* pick */, Oi::PICK_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1044 /* preceq */, Oi::PRECEQ_W_PHL, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phl, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1044 /* preceq */, Oi::PRECEQ_W_PHR, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_phr, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1051 /* precequ */, Oi::PRECEQU_PH_QBL, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbl, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1051 /* precequ */, Oi::PRECEQU_PH_QBLA, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbla, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1051 /* precequ */, Oi::PRECEQU_PH_QBR, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbr, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1051 /* precequ */, Oi::PRECEQU_PH_QBRA, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbra, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1059 /* preceu */, Oi::PRECEU_PH_QBL, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbl, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1059 /* preceu */, Oi::PRECEU_PH_QBLA, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbla, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1059 /* preceu */, Oi::PRECEU_PH_QBR, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbr, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1059 /* preceu */, Oi::PRECEU_PH_QBRA, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_qbra, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1066 /* precr */, Oi::PRECR_QB_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSPR2, { MCK__DOT_qb, MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1072 /* precr_sra */, Oi::PRECR_SRA_PH_W, Convert__Reg1_2__Reg1_3__Imm1_4__Tie0, Feature_HasDSPR2, { MCK__DOT_ph, MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1082 /* precr_sra_r */, Oi::PRECR_SRA_R_PH_W, Convert__Reg1_2__Reg1_3__Imm1_4__Tie0, Feature_HasDSPR2, { MCK__DOT_ph, MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1094 /* precrq */, Oi::PRECRQ_PH_W, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1094 /* precrq */, Oi::PRECRQ_QB_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_qb, MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1101 /* precrq_rs */, Oi::PRECRQ_RS_PH_W, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_ph, MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1111 /* precrqu_s */, Oi::PRECRQU_S_QB_PH, Convert__Reg1_2__Reg1_3__Reg1_4, Feature_HasDSP, { MCK__DOT_qb, MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1121 /* prepend */, Oi::PREPEND, Convert__Reg1_0__Reg1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1129 /* raddu */, Oi::RADDU_W_QB, Convert__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1135 /* rddsp */, Oi::RDDSP, Convert__Reg1_0__Imm1_1, Feature_HasDSP, { MCK_CPURegs, MCK_Imm }, 0},
  { 1141 /* rdhwr */, Oi::RDHWR, Convert__Reg1_0__HWRegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegs, MCK_HWRegsAsm }, 0},
  { 1141 /* rdhwr */, Oi::RDHWR64, Convert__Reg1_0__HW64RegsAsm1_1, Feature_HasStdEnc, { MCK_CPU64Regs, MCK_HW64RegsAsm }, 0},
  { 1147 /* repl */, Oi::REPL_PH, Convert__Reg1_1__Imm1_2, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_Imm }, 0},
  { 1147 /* repl */, Oi::REPL_QB, Convert__Reg1_1__Imm1_2, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_Imm }, 0},
  { 1152 /* replv */, Oi::REPLV_PH, Convert__Reg1_1__Reg1_2, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1152 /* replv */, Oi::REPLV_QB, Convert__Reg1_1__Reg1_2, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1158 /* rotr */, Oi::ROTR, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 1163 /* rotrv */, Oi::ROTRV, Convert__CPURegsAsm1_0__CPURegsAsm1_2__CPURegsAsm1_1, Feature_HasOi32r2|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1169 /* round */, Oi::ROUND_L_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 1169 /* round */, Oi::ROUND_L_S, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_s, MCK_FGR64, MCK_FGR32 }, 0},
  { 1169 /* round */, Oi::ROUND_W_D32, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_AFGR64 }, 0},
  { 1169 /* round */, Oi::ROUND_W_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_FGR64 }, 0},
  { 1169 /* round */, Oi::ROUND_W_S, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 1175 /* sb */, Oi::SB, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 1175 /* sb */, Oi::SB64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1175 /* sb */, Oi::SbRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 1178 /* sc */, Oi::SC, Convert__CPURegsAsm1_0__Tie0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_Mem }, 0},
  { 1178 /* sc */, Oi::SC_P8, Convert__CPURegsAsm1_0__Tie0__Mem2_1, Feature_IsN64|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_Mem }, 0},
  { 1181 /* scd */, Oi::SCD, Convert__CPU64RegsAsm1_0__Tie0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_Mem }, 0},
  { 1185 /* sd */, Oi::SD, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1188 /* sdc1 */, Oi::SDC1, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_NotOi64|Feature_HasStdEnc, { MCK_AFGR64, MCK_Mem }, 0},
  { 1188 /* sdc1 */, Oi::SDC164, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasOi64|Feature_HasStdEnc, { MCK_FGR64, MCK_Mem }, 0},
  { 1193 /* sdl */, Oi::SDL, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1197 /* sdr */, Oi::SDR, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1201 /* sdxc1 */, Oi::SDXC1, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasOi32r2|Feature_NotOi64|Feature_HasStdEnc, { MCK_AFGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 1201 /* sdxc1 */, Oi::SDXC164, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasOi64|Feature_NotN64|Feature_HasStdEnc, { MCK_FGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 1207 /* seb */, Oi::SEB, Convert__Reg1_0__Reg1_1, Feature_HasSEInReg|Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs }, 0},
  { 1207 /* seb */, Oi::SEB64, Convert__Reg1_0__Reg1_1, Feature_HasSEInReg|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs }, 0},
  { 1211 /* seh */, Oi::SEH, Convert__Reg1_0__Reg1_1, Feature_HasSEInReg|Feature_HasStdEnc, { MCK_CPURegs, MCK_CPURegs }, 0},
  { 1211 /* seh */, Oi::SEH64, Convert__Reg1_0__Reg1_1, Feature_HasSEInReg|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_CPU64Regs }, 0},
  { 1215 /* sh */, Oi::SH, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 1215 /* sh */, Oi::SH64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1215 /* sh */, Oi::ShRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 1218 /* shilo */, Oi::SHILO, Convert__Reg1_0__Imm1_1, Feature_HasDSP, { MCK_ACRegs, MCK_Imm }, 0},
  { 1224 /* shilov */, Oi::SHILOV, Convert__Reg1_0__Reg1_1, Feature_HasDSP, { MCK_ACRegs, MCK_CPURegs }, 0},
  { 1231 /* shll */, Oi::SHLL_PH, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1231 /* shll */, Oi::SHLL_QB, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1236 /* shll_s */, Oi::SHLL_S_PH, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1236 /* shll_s */, Oi::SHLL_S_W, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1243 /* shllv */, Oi::SHLLV_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1243 /* shllv */, Oi::SHLLV_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1249 /* shllv_s */, Oi::SHLLV_S_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1249 /* shllv_s */, Oi::SHLLV_S_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1257 /* shra */, Oi::SHRA_PH, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1257 /* shra */, Oi::SHRA_QB, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1262 /* shra_r */, Oi::SHRA_R_PH, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1262 /* shra_r */, Oi::SHRA_R_QB, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1262 /* shra_r */, Oi::SHRA_R_W, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1269 /* shrav */, Oi::SHRAV_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1269 /* shrav */, Oi::SHRAV_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1275 /* shrav_r */, Oi::SHRAV_R_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1275 /* shrav_r */, Oi::SHRAV_R_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1275 /* shrav_r */, Oi::SHRAV_R_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1283 /* shrl */, Oi::SHRL_PH, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1283 /* shrl */, Oi::SHRL_QB, Convert__Reg1_1__Reg1_2__Imm1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_Imm }, 0},
  { 1288 /* shrlv */, Oi::SHRLV_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1288 /* shrlv */, Oi::SHRLV_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1294 /* sll */, Oi::SllX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm }, 0},
  { 1294 /* sll */, Oi::SLL, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 1298 /* sllv */, Oi::SllvRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1298 /* sllv */, Oi::SLLV, Convert__CPURegsAsm1_0__CPURegsAsm1_2__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1303 /* slt */, Oi::SltRxRy16, Convert__Reg1_0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1303 /* slt */, Oi::SLT, Convert__CPURegsAsm1_0__Reg1_1__Reg1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1303 /* slt */, Oi::SLTi, Convert__CPURegsAsm1_0__Reg1_1__Imm1_2, 0, { MCK_CPURegsAsm, MCK_CPURegs, MCK_Imm }, 0},
  { 1303 /* slt */, Oi::SLT64, Convert__CPURegsAsm1_0__Reg1_1__Reg1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPU64Regs, MCK_CPU64Regs }, 0},
  { 1303 /* slt */, Oi::SLTi64, Convert__CPURegsAsm1_0__Reg1_1__Imm1_2, Feature_HasOi64, { MCK_CPURegsAsm, MCK_CPU64Regs, MCK_Imm }, 0},
  { 1307 /* slti */, Oi::SLTi, Convert__CPURegsAsm1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegs, MCK_Imm }, 0},
  { 1307 /* slti */, Oi::SLTi64, Convert__CPURegsAsm1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPU64Regs, MCK_Imm }, 0},
  { 1312 /* sltiu */, Oi::SLTiu, Convert__CPURegsAsm1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegs, MCK_Imm }, 0},
  { 1312 /* sltiu */, Oi::SLTiu64, Convert__CPURegsAsm1_0__Reg1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPU64Regs, MCK_Imm }, 0},
  { 1318 /* sltu */, Oi::SLTu, Convert__CPURegsAsm1_0__Reg1_1__Reg1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1318 /* sltu */, Oi::SLTu64, Convert__CPURegsAsm1_0__Reg1_1__Reg1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPU64Regs, MCK_CPU64Regs }, 0},
  { 1323 /* sqrt */, Oi::FSQRT_D32, Convert__Reg1_1__Reg1_2, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 1323 /* sqrt */, Oi::FSQRT_D64, Convert__Reg1_1__Reg1_2, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 1323 /* sqrt */, Oi::FSQRT_S, Convert__Reg1_1__Reg1_2, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 1328 /* sra */, Oi::SraX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm }, 0},
  { 1328 /* sra */, Oi::SRA, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 1332 /* srav */, Oi::SravRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1332 /* srav */, Oi::SRAV, Convert__CPURegsAsm1_0__CPURegsAsm1_2__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1337 /* srl */, Oi::SrlX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm }, 0},
  { 1337 /* srl */, Oi::SRL, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 1341 /* srlv */, Oi::SrlvRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1341 /* srlv */, Oi::SRLV, Convert__CPURegsAsm1_0__CPURegsAsm1_2__CPURegsAsm1_1, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1346 /* sub */, Oi::SUB, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1346 /* sub */, Oi::FSUB_D32, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_AFGR64, MCK_AFGR64, MCK_AFGR64 }, 0},
  { 1346 /* sub */, Oi::FSUB_D64, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_d, MCK_FGR64, MCK_FGR64, MCK_FGR64 }, 0},
  { 1346 /* sub */, Oi::FSUB_S, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_s, MCK_FGR32, MCK_FGR32, MCK_FGR32 }, 0},
  { 1350 /* subq */, Oi::SUBQ_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1355 /* subq_s */, Oi::SUBQ_S_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1355 /* subq_s */, Oi::SUBQ_S_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1362 /* subqh */, Oi::SUBQH_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1362 /* subqh */, Oi::SUBQH_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1368 /* subqh_r */, Oi::SUBQH_R_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1368 /* subqh_r */, Oi::SUBQH_R_W, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_w, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1376 /* subu */, Oi::SubuRxRyRz16, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1376 /* subu */, Oi::SUBu, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1376 /* subu */, Oi::SUBU_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1376 /* subu */, Oi::SUBU_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1381 /* subu_s */, Oi::SUBU_S_PH, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_ph, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1381 /* subu_s */, Oi::SUBU_S_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSP, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1388 /* subuh */, Oi::SUBUH_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1394 /* subuh_r */, Oi::SUBUH_R_QB, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasDSPR2, { MCK__DOT_qb, MCK_CPURegs, MCK_CPURegs, MCK_CPURegs }, 0},
  { 1402 /* suxc1 */, Oi::SUXC1, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_NotOi64|Feature_HasStdEnc, { MCK_AFGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 1402 /* suxc1 */, Oi::SUXC164, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasOi64|Feature_HasStdEnc, { MCK_FGR64, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 1408 /* sw */, Oi::SW, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 1408 /* sw */, Oi::SW64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1408 /* sw */, Oi::SwRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16Regs }, 0},
  { 1408 /* sw */, Oi::SwRxSpImmX16, Convert__Reg1_0__Reg1_3__Imm1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__40_, MCK_CPUSPReg, MCK__41__59_ }, 0},
  { 1411 /* swc1 */, Oi::SWC1, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_FGR32, MCK_Mem }, 0},
  { 1411 /* swc1 */, Oi::SWC1_P8, Convert__Reg1_0__Mem2_1, Feature_IsN64|Feature_HasStdEnc, { MCK_FGR32, MCK_Mem }, 0},
  { 1416 /* swl */, Oi::SWL, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 1416 /* swl */, Oi::SWL64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1420 /* swr */, Oi::SWR, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPURegs, MCK_Mem }, 0},
  { 1420 /* swr */, Oi::SWR64, Convert__Reg1_0__Mem2_1, Feature_NotN64|Feature_HasStdEnc, { MCK_CPU64Regs, MCK_Mem }, 0},
  { 1424 /* swxc1 */, Oi::SWXC1, Convert__Reg1_0__Reg1_3__Reg1_1, Feature_HasFPIdx|Feature_HasStdEnc, { MCK_FGR32, MCK_CPURegs, MCK__40_, MCK_CPURegs, MCK__41_ }, 0},
  { 1430 /* sync */, Oi::SYNC, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, 0},
  { 1435 /* trunc */, Oi::TRUNC_L_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_d, MCK_FGR64, MCK_FGR64 }, 0},
  { 1435 /* trunc */, Oi::TRUNC_L_S, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_l, MCK__DOT_s, MCK_FGR64, MCK_FGR32 }, 0},
  { 1435 /* trunc */, Oi::TRUNC_W_D32, Convert__Reg1_2__Reg1_3, Feature_NotFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_AFGR64 }, 0},
  { 1435 /* trunc */, Oi::TRUNC_W_D64, Convert__Reg1_2__Reg1_3, Feature_IsFP64bit|Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_d, MCK_FGR32, MCK_FGR64 }, 0},
  { 1435 /* trunc */, Oi::TRUNC_W_S, Convert__Reg1_2__Reg1_3, Feature_HasStdEnc, { MCK__DOT_w, MCK__DOT_s, MCK_FGR32, MCK_FGR32 }, 0},
  { 1441 /* wrdsp */, Oi::WRDSP, Convert__Reg1_0__Imm1_1, Feature_HasDSP, { MCK_CPURegs, MCK_Imm }, 0},
  { 1447 /* wsbh */, Oi::WSBH, Convert__CPURegsAsm1_0__CPURegsAsm1_1, Feature_HasSwap|Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1452 /* xor */, Oi::XorRxRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InOi16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, 0},
  { 1452 /* xor */, Oi::XOR64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__CPU64RegsAsm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_CPU64RegsAsm }, 0},
  { 1452 /* xor */, Oi::XORi64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasOi64, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 1452 /* xor */, Oi::XOR, Convert__CPURegsAsm1_0__CPURegsAsm1_1__CPURegsAsm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_CPURegsAsm }, 0},
  { 1452 /* xor */, Oi::XORi, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_NotOi64, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
  { 1456 /* xori */, Oi::XORi64, Convert__CPU64RegsAsm1_0__CPU64RegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPU64RegsAsm, MCK_CPU64RegsAsm, MCK_Imm }, 0},
  { 1456 /* xori */, Oi::XORi, Convert__CPURegsAsm1_0__CPURegsAsm1_1__Imm1_2, Feature_HasStdEnc, { MCK_CPURegsAsm, MCK_CPURegsAsm, MCK_Imm }, 0},
};

bool OiAsmParser::
mnemonicIsValid(StringRef Mnemonic) {
  // Search the table.
  std::pair<const MatchEntry*, const MatchEntry*> MnemonicRange =
    std::equal_range(MatchTable, MatchTable+512, Mnemonic, LessOpcode());
  return MnemonicRange.first != MnemonicRange.second;
}

unsigned OiAsmParser::
MatchInstructionImpl(const SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                     MCInst &Inst,
unsigned &ErrorInfo, bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 6) {
    ErrorInfo = 6;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic = ((OiOperand*)Operands[0])->getToken();

  // Some state to try to produce better error messages.
  bool HadMatchOtherThanFeatures = false;
  bool HadMatchOtherThanPredicate = false;
  unsigned RetCode = Match_InvalidOperand;
  unsigned MissingFeatures = ~0U;
  // Set ErrorInfo to the operand that mismatches if it is
  // wrong for all instances of the instruction.
  ErrorInfo = ~0U;
  // Search the table.
  std::pair<const MatchEntry*, const MatchEntry*> MnemonicRange =
    std::equal_range(MatchTable, MatchTable+512, Mnemonic, LessOpcode());

  // Return a more specific error code if no mnemonics match.
  if (MnemonicRange.first == MnemonicRange.second)
    return Match_MnemonicFail;

  for (const MatchEntry *it = MnemonicRange.first, *ie = MnemonicRange.second;
       it != ie; ++it) {
    // equal_range guarantees that instruction mnemonic matches.
    assert(Mnemonic == it->getMnemonic());
    if (VariantID != it->AsmVariantID) continue;
    bool OperandsValid = true;
    for (unsigned i = 0; i != 5; ++i) {
      if (i + 1 >= Operands.size()) {
        OperandsValid = (it->Classes[i] == InvalidMatchClass);
        if (!OperandsValid) ErrorInfo = i + 1;
        break;
      }
      unsigned Diag = validateOperandClass(Operands[i+1],
                                           (MatchClassKind)it->Classes[i]);
      if (Diag == Match_Success)
        continue;
      // If the generic handler indicates an invalid operand
      // failure, check for a special case.
      if (Diag == Match_InvalidOperand) {
        Diag = validateTargetOperandClass(Operands[i+1],
                                           (MatchClassKind)it->Classes[i]);
        if (Diag == Match_Success)
          continue;
      }
      // If this operand is broken for all of the instances of this
      // mnemonic, keep track of it so we can report loc info.
      // If we already had a match that only failed due to a
      // target predicate, that diagnostic is preferred.
      if (!HadMatchOtherThanPredicate &&
          (it == MnemonicRange.first || ErrorInfo <= i+1)) {
        ErrorInfo = i+1;
        // InvalidOperand is the default. Prefer specificity.
        if (Diag != Match_InvalidOperand)
          RetCode = Diag;
      }
      // Otherwise, just reject this instance of the mnemonic.
      OperandsValid = false;
      break;
    }

    if (!OperandsValid) continue;
    if ((AvailableFeatures & it->RequiredFeatures) != it->RequiredFeatures) {
      HadMatchOtherThanFeatures = true;
      unsigned NewMissingFeatures = it->RequiredFeatures & ~AvailableFeatures;
      if (CountPopulation_32(NewMissingFeatures) <=
          CountPopulation_32(MissingFeatures))
        MissingFeatures = NewMissingFeatures;
      continue;
    }

    if (matchingInlineAsm) {
      Inst.setOpcode(it->Opcode);
      convertToMapAndConstraints(it->ConvertFn, Operands);
      return Match_Success;
    }

    // We have selected a definite instruction, convert the parsed
    // operands into the appropriate MCInst.
    convertToMCInst(it->ConvertFn, Inst, it->Opcode, Operands);

    // We have a potential match. Check the target predicate to
    // handle any context sensitive constraints.
    unsigned MatchResult;
    if ((MatchResult = checkTargetMatchPredicate(Inst)) != Match_Success) {
      Inst.clear();
      RetCode = MatchResult;
      HadMatchOtherThanPredicate = true;
      continue;
    }

    return Match_Success;
  }

  // Okay, we had no match.  Try to return a useful error code.
  if (HadMatchOtherThanPredicate || !HadMatchOtherThanFeatures)
    return RetCode;

  // Missing feature matches return which features were missing
  ErrorInfo = MissingFeatures;
  return Match_MissingFeature;
}

namespace {
  struct OperandMatchEntry {
    uint32_t RequiredFeatures;
    uint16_t Mnemonic;
    uint8_t Class;
    uint8_t OperandMask;

    StringRef getMnemonic() const {
      return StringRef(MnemonicTable + Mnemonic + 1,
                       MnemonicTable[Mnemonic]);
    }
  };

  // Predicate for searching for an opcode.
  struct LessOpcodeOperand {
    bool operator()(const OperandMatchEntry &LHS, StringRef RHS) {
      return LHS.getMnemonic()  < RHS;
    }
    bool operator()(StringRef LHS, const OperandMatchEntry &RHS) {
      return LHS < RHS.getMnemonic();
    }
    bool operator()(const OperandMatchEntry &LHS, const OperandMatchEntry &RHS) {
      return LHS.getMnemonic() < RHS.getMnemonic();
    }
  };
} // end anonymous namespace.

static const OperandMatchEntry OperandMatchTable[177] = {
  /* Operand List Mask, Mnemonic, Operand Class, Features */
  { Feature_HasStdEnc, 11 /* add */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { 0, 11 /* add */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 15 /* addi */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 20 /* addiu */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 58 /* addu */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { 0, 58 /* addu */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 90 /* and */, MCK_CPU64RegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasOi64, 90 /* and */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 90 /* and */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { 0, 90 /* and */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 94 /* andi */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 94 /* andi */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 143 /* bgezal */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 172 /* bltzal */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 216 /* cfc1 */, MCK_CCRAsm, 2 /* 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 221 /* clo */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 225 /* clz */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 251 /* ctc1 */, MCK_CCRAsm, 2 /* 1 */ },
  { Feature_HasStdEnc, 260 /* dadd */, MCK_CPU64RegsAsm, 7 /* 0, 1, 2 */ },
  { 0, 260 /* dadd */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 265 /* daddi */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 271 /* daddiu */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 278 /* daddu */, MCK_CPU64RegsAsm, 7 /* 0, 1, 2 */ },
  { 0, 278 /* daddu */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 284 /* dclo */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 289 /* dclz */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 294 /* ddiv */, MCK_CPU64RegsAsm, 6 /* 1, 2 */ },
  { Feature_HasStdEnc, 299 /* ddivu */, MCK_CPU64RegsAsm, 6 /* 1, 2 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 305 /* dext */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 310 /* dextm */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 316 /* dextu */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 322 /* dins */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 327 /* dinsm */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 333 /* dinsu */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 339 /* div */, MCK_CPURegsAsm, 6 /* 1, 2 */ },
  { Feature_HasStdEnc, 343 /* divu */, MCK_CPURegsAsm, 6 /* 1, 2 */ },
  { 0, 348 /* dmfc0 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 348 /* dmfc0 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { 0, 360 /* dmfc2 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 360 /* dmfc2 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { 0, 366 /* dmtc0 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 366 /* dmtc0 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { 0, 378 /* dmtc2 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 378 /* dmtc2 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 384 /* dmult */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 390 /* dmultu */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi64r2|Feature_HasStdEnc, 489 /* drotr */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi64r2|Feature_HasStdEnc, 495 /* drotrv */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi64r2|Feature_HasStdEnc, 495 /* drotrv */, MCK_CPURegsAsm, 4 /* 2 */ },
  { Feature_HasSwap|Feature_HasStdEnc, 502 /* dsbh */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasSwap|Feature_HasStdEnc, 507 /* dshd */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 512 /* dsll */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 517 /* dsll32 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 524 /* dsllv */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 524 /* dsllv */, MCK_CPURegsAsm, 4 /* 2 */ },
  { Feature_HasStdEnc, 530 /* dsra */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 535 /* dsra32 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 542 /* dsrav */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 542 /* dsrav */, MCK_CPURegsAsm, 4 /* 2 */ },
  { Feature_HasStdEnc, 548 /* dsrl */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 553 /* dsrl32 */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 560 /* dsrlv */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 560 /* dsrlv */, MCK_CPURegsAsm, 4 /* 2 */ },
  { Feature_HasStdEnc, 566 /* dsubu */, MCK_CPU64RegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 572 /* ext */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 666 /* ins */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { 0, 699 /* la */, MCK_CPURegsAsm, 1 /* 0 */ },
  { 0, 699 /* la */, MCK_CPURegsAsm, 1 /* 0 */ },
  { 0, 699 /* la */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 702 /* lb */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 702 /* lb */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 705 /* lbu */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 705 /* lbu */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 714 /* ld */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_NotOi64|Feature_HasStdEnc, 717 /* ldc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasOi64|Feature_HasStdEnc, 717 /* ldc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 722 /* ldl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 726 /* ldr */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 736 /* lh */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 736 /* lh */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 739 /* lhu */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 739 /* lhu */, MCK_Mem, 2 /* 1 */ },
  { 0, 747 /* li */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_NotN64|Feature_HasStdEnc, 750 /* ll */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_NotN64|Feature_HasStdEnc, 750 /* ll */, MCK_Mem, 2 /* 1 */ },
  { Feature_IsN64|Feature_HasStdEnc, 750 /* ll */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_IsN64|Feature_HasStdEnc, 750 /* ll */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 753 /* lld */, MCK_CPU64RegsAsm, 1 /* 0 */ },
  { Feature_NotN64|Feature_HasStdEnc, 753 /* lld */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 767 /* lw */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 767 /* lw */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 770 /* lwc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_IsN64|Feature_HasStdEnc, 770 /* lwc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 775 /* lwl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 775 /* lwl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 779 /* lwr */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 779 /* lwr */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 783 /* lwu */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 797 /* madd */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 802 /* maddu */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { 0, 821 /* mfc0 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 821 /* mfc0 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { 0, 831 /* mfc2 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 831 /* mfc2 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi64, 857 /* move */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_NotOi64, 857 /* move */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 882 /* msub */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 887 /* msubu */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { 0, 893 /* mtc0 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 893 /* mtc0 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { 0, 903 /* mtc2 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 903 /* mtc2 */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 925 /* mul */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 981 /* mult */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 986 /* multu */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { 0, 992 /* neg */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { 0, 996 /* negu */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1017 /* nor */, MCK_CPU64RegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 1017 /* nor */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasOi64, 1021 /* not */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { 0, 1021 /* not */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1025 /* or */, MCK_CPU64RegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 1025 /* or */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 1028 /* ori */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1028 /* ori */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1141 /* rdhwr */, MCK_HWRegsAsm, 2 /* 1 */ },
  { Feature_HasStdEnc, 1141 /* rdhwr */, MCK_HW64RegsAsm, 2 /* 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 1158 /* rotr */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasOi32r2|Feature_HasStdEnc, 1163 /* rotrv */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1175 /* sb */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1175 /* sb */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1178 /* sc */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1178 /* sc */, MCK_Mem, 2 /* 1 */ },
  { Feature_IsN64|Feature_HasStdEnc, 1178 /* sc */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_IsN64|Feature_HasStdEnc, 1178 /* sc */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1181 /* scd */, MCK_CPU64RegsAsm, 1 /* 0 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1181 /* scd */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1185 /* sd */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_NotOi64|Feature_HasStdEnc, 1188 /* sdc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasOi64|Feature_HasStdEnc, 1188 /* sdc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1193 /* sdl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1197 /* sdr */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1215 /* sh */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1215 /* sh */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 1294 /* sll */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1298 /* sllv */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 1303 /* slt */, MCK_CPURegsAsm, 1 /* 0 */ },
  { 0, 1303 /* slt */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1303 /* slt */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasOi64, 1303 /* slt */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1307 /* slti */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1307 /* slti */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1312 /* sltiu */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1312 /* sltiu */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1318 /* sltu */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1318 /* sltu */, MCK_CPURegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 1328 /* sra */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1332 /* srav */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 1337 /* srl */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1341 /* srlv */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 1346 /* sub */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 1376 /* subu */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1408 /* sw */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1408 /* sw */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1411 /* swc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_IsN64|Feature_HasStdEnc, 1411 /* swc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1416 /* swl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1416 /* swl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1420 /* swr */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotN64|Feature_HasStdEnc, 1420 /* swr */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasSwap|Feature_HasStdEnc, 1447 /* wsbh */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1452 /* xor */, MCK_CPU64RegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasOi64, 1452 /* xor */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1452 /* xor */, MCK_CPURegsAsm, 7 /* 0, 1, 2 */ },
  { Feature_NotOi64, 1452 /* xor */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1456 /* xori */, MCK_CPU64RegsAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1456 /* xori */, MCK_CPURegsAsm, 3 /* 0, 1 */ },
};

OiAsmParser::OperandMatchResultTy OiAsmParser::
tryCustomParseOperand(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                      unsigned MCK) {

  switch(MCK) {
  case MCK_CCRAsm:
    return parseCCRRegs(Operands);
  case MCK_CPU64RegsAsm:
    return parseCPU64Regs(Operands);
  case MCK_CPURegsAsm:
    return parseCPURegs(Operands);
  case MCK_HW64RegsAsm:
    return parseHW64Regs(Operands);
  case MCK_HWRegsAsm:
    return parseHWRegs(Operands);
  case MCK_Mem:
    return parseMemOperand(Operands);
  default:
    return MatchOperand_NoMatch;
  }
  return MatchOperand_NoMatch;
}

OiAsmParser::OperandMatchResultTy OiAsmParser::
MatchOperandParserImpl(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                       StringRef Mnemonic) {
  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the next operand index.
  unsigned NextOpNum = Operands.size()-1;
  // Search the table.
  std::pair<const OperandMatchEntry*, const OperandMatchEntry*> MnemonicRange =
    std::equal_range(OperandMatchTable, OperandMatchTable+177, Mnemonic,
                     LessOpcodeOperand());

  if (MnemonicRange.first == MnemonicRange.second)
    return MatchOperand_NoMatch;

  for (const OperandMatchEntry *it = MnemonicRange.first,
       *ie = MnemonicRange.second; it != ie; ++it) {
    // equal_range guarantees that instruction mnemonic matches.
    assert(Mnemonic == it->getMnemonic());

    // check if the available features match
    if ((AvailableFeatures & it->RequiredFeatures) != it->RequiredFeatures) {
      continue;
    }

    // check if the operand in question has a custom parser.
    if (!(it->OperandMask & (1 << NextOpNum)))
      continue;

    // call custom parse method to handle the operand
    OperandMatchResultTy Result = tryCustomParseOperand(Operands, it->Class);
    if (Result != MatchOperand_NoMatch)
      return Result;
  }

  // Okay, we had no match.
  return MatchOperand_NoMatch;
}

#endif // GET_MATCHER_IMPLEMENTATION

