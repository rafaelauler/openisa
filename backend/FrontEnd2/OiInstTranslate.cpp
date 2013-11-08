//===-- OiInstTranslate.cpp - Convert Oi MCInst to LLVM IR ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class translates an Oi MCInst to LLVM IR using static binary translation
// techniques.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "asm-printer"
#include "OiInstTranslate.h"
#include "OiInstrInfo.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm-objdump.h"
using namespace llvm;

static bool error(error_code ec) {
  if (!ec) return false;

  outs() << "error reading file: " << ec.message() << ".\n";
  outs().flush();
  return true;
}


void OiInstTranslate::BuildShadowImage() {
  ShadowSize = 0;

  error_code ec;
  for (section_iterator i = Obj->begin_sections(),
                        e = Obj->end_sections();
                        i != e; i.increment(ec)) {
    if (error(ec)) break;

    uint64_t SectionAddr;
    if (error(i->getAddress(SectionAddr))) break;
    uint64_t SectSize;
    if (error(i->getSize(SectSize))) break;
    if (SectSize + SectionAddr > ShadowSize)
      ShadowSize = SectSize + SectionAddr;
  }
  ShadowImage.reset(new uint8_t[ShadowSize]);
 
  for (section_iterator i = Obj->begin_sections(),
                        e = Obj->end_sections();
                        i != e; i.increment(ec)) {
    uint64_t SectionAddr;
    if (error(i->getAddress(SectionAddr))) break;
    uint64_t SectSize;
    if (error(i->getSize(SectSize))) break;
    if (SectSize + SectionAddr > ShadowSize)
      ShadowSize = SectSize + SectionAddr;
    StringRef Bytes;
    if (error(i->getContents(Bytes))) break;
    StringRefMemoryObject memoryObject(Bytes);
    memoryObject.readBytes(SectionAddr, SectSize, 
                           &ShadowImage[0] + SectionAddr, 0); 
  }

  ConstantDataArray *c = 
    dyn_cast<ConstantDataArray>(ConstantDataArray::get(getGlobalContext(),
      ArrayRef<uint8_t>(reinterpret_cast<const unsigned char *>(&ShadowImage[0]), 
                        ShadowSize)));

  GlobalVariable *gv = new GlobalVariable(*TheModule, c->getType(), false, 
                                          GlobalValue::ExternalLinkage,
                                          c, "ShadowMemory");  
  ShadowImageValue = gv;
}

static unsigned conv32(unsigned regnum) {
  switch(regnum) {
  case Oi::AT_64:
    return Oi::AT;
  case Oi::FP_64:
    return Oi::FP;
  case Oi::SP_64:
    return Oi::SP;
  case Oi::RA_64:
    return Oi::RA;
  case Oi::ZERO_64:
    return Oi::ZERO;
  case Oi::GP_64:
    return Oi::GP;
  case Oi::A0_64:
    return Oi::A0;
  case Oi::A1_64:
    return Oi::A1;
  case Oi::A2_64:
    return Oi::A2;
  case Oi::A3_64:
    return Oi::A3;
  case Oi::V0_64:
    return Oi::V0;
  case Oi::V1_64:
    return Oi::V1;
  case Oi::S0_64:
    return Oi::S0;
  case Oi::S1_64:
    return Oi::S1;
  case Oi::S2_64:
    return Oi::S2;
  case Oi::S3_64:
    return Oi::S3;
  case Oi::S4_64:
    return Oi::S4;
  case Oi::S5_64:
    return Oi::S5;
  case Oi::S6_64:
    return Oi::S6;
  case Oi::S7_64:
    return Oi::S7;
  case Oi::K0_64:
    return Oi::K0;
  case Oi::K1_64:
    return Oi::K1;
  case Oi::T0_64:
    return Oi::T0;
  case Oi::T1_64:
    return Oi::T1;
  case Oi::T2_64:
    return Oi::T2;
  case Oi::T3_64:
    return Oi::T3;
  case Oi::T4_64:
    return Oi::T4;
  case Oi::T5_64:
    return Oi::T5;
  case Oi::T6_64:
    return Oi::T6;
  case Oi::T7_64:
    return Oi::T7;
  case Oi::T8_64:
    return Oi::T8;
  case Oi::T9_64:
    return Oi::T9; 
  }
  return regnum;
}

static unsigned ConvFromDirective(unsigned regnum) {
  switch(regnum) {
  case 0:
    return Oi::ZERO;
  case 1:
    return Oi::AT;
  case 4:
    return Oi::A0;
  case 5:
    return Oi::A1;
  case 6:
    return Oi::A2;
  case 7:
    return Oi::A3;
  case 2:
    return Oi::V0;
  case 3:
    return Oi::V1;
  case 16:
    return Oi::S0;
  case 17:
    return Oi::S1;
  case 18:
    return Oi::S2;
  case 19:
    return Oi::S3;
  case 20:
    return Oi::S4;
  case 21:
    return Oi::S5;
  case 22:
    return Oi::S6;
  case 23:
    return Oi::S7;
  case 26:
    return Oi::K0;
  case 27:
    return Oi::K1;
  case 29:
    return Oi::SP;
  case 30:
    return Oi::FP;
  case 28:
    return Oi::GP;
  case 31:
    return Oi::RA;
  case 8:
    return Oi::T0;
  case 9:
    return Oi::T1;
  case 10:
    return Oi::T2;
  case 11:
    return Oi::T3;
  case 12:
    return Oi::T4;
  case 13:
    return Oi::T5;
  case 14:
    return Oi::T6;
  case 15:
    return Oi::T7;
  case 24:
    return Oi::T8;
  case 25:
    return Oi::T9;
  }
  return -1;
}

static unsigned ConvToDirective(unsigned regnum) {
  switch(regnum) {
  case Oi::ZERO:
    return 0;
  case Oi::AT:
    return 1;
  case Oi::A0:
    return 4;
  case Oi::A1:
    return 5;
  case Oi::A2:
    return 6;
  case Oi::A3:
    return 7;
  case Oi::V0:
    return 2;
  case Oi::V1:
    return 3;
  case Oi::S0:
    return 16;
  case Oi::S1:
    return 17;
  case Oi::S2:
    return 18;
  case Oi::S3:
    return 19;
  case Oi::S4:
    return 20;
  case Oi::S5:
    return 21;
  case Oi::S6:
    return 22;
  case Oi::S7:
    return 23;
  case Oi::K0:
    return 26;
  case Oi::K1:
    return 27;
  case Oi::SP:
    return 29;
  case Oi::FP:
    return 30;
  case Oi::GP:
    return 28;
  case Oi::RA:
    return 31;
  case Oi::T0:
    return 8;
  case Oi::T1:
    return 9;
  case Oi::T2:
    return 10;
  case Oi::T3:
    return 11;
  case Oi::T4:
    return 12;
  case Oi::T5:
    return 13;
  case Oi::T6:
    return 14;
  case Oi::T7:
    return 15;
  case Oi::T8:
    return 24;
  case Oi::T9:
    return 25;
  }
  return -1;
}


void OiInstTranslate::BuildRegisterFile() {
  ConstantDataArray *c = 
    dyn_cast<ConstantDataArray>(ConstantDataArray::get(getGlobalContext(),
      ArrayRef<uint8_t>(reinterpret_cast<const unsigned char *>(&ShadowImage[0]), 
                        ShadowSize)));
  Type *ty = Type::getInt32Ty(getGlobalContext());
  for (int I = 0; I < 32; ++I) {
    Constant *ci = ConstantInt::get(ty, 0U);
    GlobalVariable *gv = new GlobalVariable(*TheModule, ty, false, 
                                            GlobalValue::ExternalLinkage,
                                            ci, "reg1");
    Regs[I] = gv;
  }
}

void OiInstTranslate::StartFunction(Twine &N) {
  // Create a function with no parameters
  FunctionType *FT = FunctionType::get(Type::getVoidTy(getGlobalContext()),
                                       false);
  Function *F = 0;
  if (FirstFunction) {
     F = Function::Create(FT, Function::ExternalLinkage,
                          "main", &*TheModule);
     FirstFunction = false;
  } else {
     F = Function::Create(FT, Function::ExternalLinkage,
                          N, &*TheModule);
  }

  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", F);
  Builder.SetInsertPoint(BB);
}

void OiInstTranslate::FinishFunction() {
  Builder.CreateRetVoid();
}

Module* OiInstTranslate::takeModule() {
  return TheModule.take();
}

bool OiInstTranslate::HandleAluSrcOperand(const MCOperand &o, Value *&V) {
  if (o.isReg()) {
    unsigned reg = conv32(o.getReg());
    V = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
    return true;
  } else if (o.isImm()) {
    V = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                         o.getImm());
    return true;
  } else if (o.isFPImm()) {
    V = ConstantFP::get(getGlobalContext(), APFloat(o.getFPImm()));
    return true;
  } else if (o.isExpr()) {
    int64_t val;
    if(o.getExpr()->EvaluateAsAbsolute(val)) {
      V = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), val);
    } else {
      llvm_unreachable("Invalid src operand");
    }
    return true;
  }
  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleMemExpr(const MCExpr &exp, Value *&V, bool IsLoad) {
  if (const MCConstantExpr *ce = dyn_cast<const MCConstantExpr>(&exp)) {
    Value *idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                  ce->getValue());
    V = AccessShadowMemory32(idx, IsLoad);
    return true;
  } else if (const MCSymbolRefExpr *se = dyn_cast<const MCSymbolRefExpr>(&exp)){
    V = TheModule->getOrInsertGlobal(se->getSymbol().getName(),
                                     Type::getInt32Ty(getGlobalContext()));
    if (se->getKind() == MCSymbolRefExpr::VK_Mips_ABS_HI) {
      Value *V0 = Builder.CreateCast(Instruction::PtrToInt, V,
                                     Type::getInt32Ty(getGlobalContext()));
      Value *V1 = Builder.CreateLShr(V0, ConstantInt::get
                                     (Type::getInt32Ty(getGlobalContext()), 16));
      Value *V2 = Builder.CreateShl(V1, ConstantInt::get
                                    (Type::getInt32Ty(getGlobalContext()), 16));
      V = V2;      
    } else if (se->getKind() == MCSymbolRefExpr::VK_Mips_ABS_LO) {
      Value *V0 = Builder.CreateCast(Instruction::PtrToInt, V,
                                     Type::getInt32Ty(getGlobalContext()));
      Value *V1 = Builder.CreateAnd(V0, ConstantInt::get
                                    (Type::getInt32Ty(getGlobalContext()), 
                                     0xFFFF));
      V = V1;
    } else if (se->getKind() != MCSymbolRefExpr::VK_None) {
      llvm_unreachable("Unhandled SymbolRef Kind");
    }
    return true;
    //    GlobalVariable(TheModule,
    //               Type::getInt32Ty(getGlobalContext()),
    //               false,
    //              GlobalValue::LinkageTypes::ExternalLinkage,
    //              Constant::getNullValue(Type::getInt32Ty(getGlobalContext())),
    //             se->getSymbol().getName(),
    //             0, GlobalVariable::NotThreadLocal, 0, true);
  }
  llvm_unreachable("Invalid Load Expr");
}

Value *OiInstTranslate::AccessShadowMemory32(Value *Idx, bool IsLoad) {
  SmallVector<Value*,4> Idxs;
  Idxs.push_back(Idx);
  Value *gep = Builder.CreateGEP(ShadowImageValue, Idxs);
  Value *ptr = Builder.CreateBitCast(gep, Type::getInt32PtrTy(getGlobalContext()));
  if (IsLoad)
    return Builder.CreateLoad(ptr);
  return ptr;
}

bool OiInstTranslate::HandleMemOperand(const MCOperand &o, Value *&V, bool IsLoad) {
  if (o.isReg()) {
    unsigned reg = conv32(o.getReg());
    Value *idx = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
    V = AccessShadowMemory32(idx, IsLoad);
    return true;
  } else if (o.isImm()) {
    Value *idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                  o.getImm());
    V = AccessShadowMemory32(idx, IsLoad);
    return true;
  } else if (o.isFPImm()) {
    llvm_unreachable("Invalid load src operand");
    return false;
  } else if (o.isExpr()) {
    int64_t val;
    if(o.getExpr()->EvaluateAsAbsolute(val)) { 
      Value *idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), val);
      V = AccessShadowMemory32(idx, IsLoad);
    } else {
      return HandleMemExpr(*o.getExpr(), V, IsLoad);
    }
    return true;
  }
  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleAluDstOperand(const MCOperand &o, Value *&V) {
  if (o.isReg()) {
    unsigned reg = conv32(o.getReg());
    V = Regs[ConvToDirective(reg)];
    return true;
  }
  llvm_unreachable("Invalid Dst operand");
  return false;
}

bool OiInstTranslate::HandleCallTarget(const MCOperand &o, Value *&V) {
  if (o.isImm()) {
    Twine T("a");
    T.concat(Twine::utohexstr(o.getImm()));
    Function *f = TheModule->getFunction(T.str());
    assert(f && "Invalid function call");
    V = f;
    return true;
  }
  return false;
}

void OiInstTranslate::printInstruction(const MCInst *MI, raw_ostream &O) {
  switch (MI->getOpcode()) {
  case Oi::ADDiu:
  case Oi::ADDi:
  case Oi::ADD:
    Value *o0, *o1, *o2;
    if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
        HandleAluSrcOperand(MI->getOperand(2), o2) &&
        HandleAluDstOperand(MI->getOperand(0), o0)) {      
      Value *v = Builder.CreateAdd(o1, o2);
      Builder.CreateStore(v, o0);
    }
    break;
  case Oi::LUi:
  case Oi::LUi64: {
    Value *dst, *src;
    if (HandleAluDstOperand(MI->getOperand(0),dst) &&
        HandleMemOperand(MI->getOperand(1), src, true)) {
      Builder.CreateStore(src, dst);
    }
    break;
  }
  case Oi::LW:
  case Oi::LW64: {
    Value *dst, *src;
    if (HandleAluDstOperand(MI->getOperand(0),dst) &&
        HandleMemOperand(MI->getOperand(1), src, true)) {
      Builder.CreateStore(Builder.CreateLoad(src), dst);
    }
    break;
  }
  case Oi::SW:
  case Oi::SW64: {
    Value *dst, *src;
    if (HandleAluSrcOperand(MI->getOperand(0),src) &&
        HandleMemOperand(MI->getOperand(1), dst, false)) {
      Builder.CreateStore(src, dst);
    }
    break;
  }
  case Oi::JALR64:
  case Oi::JALR: {
    llvm_unreachable("Can't handle indirect jumps yet.");
    break;
  }
  case Oi::JAL: {
    Value *dst;
    if(HandleCallTarget(MI->getOperand(0), dst)) {
      Builder.CreateCall(dst);
    }
    break;
  }
  case Oi::JR64:
  case Oi::JR: {
    if (MI->getOperand(0).getReg() == Oi::RA
        || MI->getOperand(0).getReg() == Oi::RA_64) {
      Builder.CreateRetVoid();
    } else {
      llvm_unreachable("Can't handle indirect jumps yet.");
    }
    break;
  }
  default: O << "huahua"; return;
  }
  return;
}

const char *OiInstTranslate::getRegisterName(unsigned RegNo) {
  return 0;
}

bool OiInstTranslate::printAliasInstr(const MCInst *MI, raw_ostream &OS) {
  switch (MI->getOpcode()) {
  default: return false;
  }
  return true;
}


void OiInstTranslate::printRegName(raw_ostream &OS, unsigned RegNo) const {
  OS << '$' << StringRef(getRegisterName(RegNo)).lower();
}

void OiInstTranslate::printInst(const MCInst *MI, raw_ostream &O,
                                StringRef Annot) {
  switch (MI->getOpcode()) {
  default:
    break;
  case Oi::RDHWR:
  case Oi::RDHWR64:
    O << "\t.set\tpush\n";
    O << "\t.set\toi32r2\n";
  }

  // Try to print any aliases first.
  if (!printAliasInstr(MI, O))
    printInstruction(MI, O);
  printAnnotation(O, Annot);

  switch (MI->getOpcode()) {
  default:
    break;
  case Oi::RDHWR:
  case Oi::RDHWR64:
    O << "\n\t.set\tpop";
  }
}

static void printExpr(const MCExpr *Expr, raw_ostream &OS) {
  int Offset = 0;
  const MCSymbolRefExpr *SRE;

  if (const MCBinaryExpr *BE = dyn_cast<MCBinaryExpr>(Expr)) {
    SRE = dyn_cast<MCSymbolRefExpr>(BE->getLHS());
    const MCConstantExpr *CE = dyn_cast<MCConstantExpr>(BE->getRHS());
    assert(SRE && CE && "Binary expression must be sym+const.");
    Offset = CE->getValue();
  }
  else if (!(SRE = dyn_cast<MCSymbolRefExpr>(Expr)))
    assert(false && "Unexpected MCExpr type.");

  MCSymbolRefExpr::VariantKind Kind = SRE->getKind();

  switch (Kind) {
  default:                                 llvm_unreachable("Invalid kind!");
  case MCSymbolRefExpr::VK_None:           break;
  case MCSymbolRefExpr::VK_Mips_GPREL:     OS << "%gp_rel("; break;
  case MCSymbolRefExpr::VK_Mips_GOT_CALL:  OS << "%call16("; break;
  case MCSymbolRefExpr::VK_Mips_GOT16:     OS << "%got(";    break;
  case MCSymbolRefExpr::VK_Mips_GOT:       OS << "%got(";    break;
  case MCSymbolRefExpr::VK_Mips_ABS_HI:    OS << "%hi(";     break;
  case MCSymbolRefExpr::VK_Mips_ABS_LO:    OS << "%lo(";     break;
  case MCSymbolRefExpr::VK_Mips_TLSGD:     OS << "%tlsgd(";  break;
  case MCSymbolRefExpr::VK_Mips_TLSLDM:    OS << "%tlsldm(";  break;
  case MCSymbolRefExpr::VK_Mips_DTPREL_HI: OS << "%dtprel_hi(";  break;
  case MCSymbolRefExpr::VK_Mips_DTPREL_LO: OS << "%dtprel_lo(";  break;
  case MCSymbolRefExpr::VK_Mips_GOTTPREL:  OS << "%gottprel("; break;
  case MCSymbolRefExpr::VK_Mips_TPREL_HI:  OS << "%tprel_hi("; break;
  case MCSymbolRefExpr::VK_Mips_TPREL_LO:  OS << "%tprel_lo("; break;
  case MCSymbolRefExpr::VK_Mips_GPOFF_HI:  OS << "%hi(%neg(%gp_rel("; break;
  case MCSymbolRefExpr::VK_Mips_GPOFF_LO:  OS << "%lo(%neg(%gp_rel("; break;
  case MCSymbolRefExpr::VK_Mips_GOT_DISP:  OS << "%got_disp("; break;
  case MCSymbolRefExpr::VK_Mips_GOT_PAGE:  OS << "%got_page("; break;
  case MCSymbolRefExpr::VK_Mips_GOT_OFST:  OS << "%got_ofst("; break;
  case MCSymbolRefExpr::VK_Mips_HIGHER:    OS << "%higher("; break;
  case MCSymbolRefExpr::VK_Mips_HIGHEST:   OS << "%highest("; break;
  case MCSymbolRefExpr::VK_Mips_GOT_HI16:  OS << "%got_hi("; break;
  case MCSymbolRefExpr::VK_Mips_GOT_LO16:  OS << "%got_lo("; break;
  case MCSymbolRefExpr::VK_Mips_CALL_HI16: OS << "%call_hi("; break;
  case MCSymbolRefExpr::VK_Mips_CALL_LO16: OS << "%call_lo("; break;
  }

  OS << SRE->getSymbol();

  if (Offset) {
    if (Offset > 0)
      OS << '+';
    OS << Offset;
  }

  if ((Kind == MCSymbolRefExpr::VK_Mips_GPOFF_HI) ||
      (Kind == MCSymbolRefExpr::VK_Mips_GPOFF_LO))
    OS << ")))";
  else if (Kind != MCSymbolRefExpr::VK_None)
    OS << ')';
}

void OiInstTranslate::printCPURegs(const MCInst *MI, unsigned OpNo,
                                   raw_ostream &O) {
  printRegName(O, MI->getOperand(OpNo).getReg());
}

void OiInstTranslate::printOperand(const MCInst *MI, unsigned OpNo,
                                   raw_ostream &O) {
  const MCOperand &Op = MI->getOperand(OpNo);
  if (Op.isReg()) {
    printRegName(O, Op.getReg());
    return;
  }

  if (Op.isImm()) {
    O << Op.getImm();
    return;
  }

  assert(Op.isExpr() && "unknown operand kind in printOperand");
  printExpr(Op.getExpr(), O);
}

void OiInstTranslate::printUnsignedImm(const MCInst *MI, int opNum,
                                       raw_ostream &O) {
  const MCOperand &MO = MI->getOperand(opNum);
  if (MO.isImm())
    O << (unsigned short int)MO.getImm();
  else
    printOperand(MI, opNum, O);
}

void OiInstTranslate::
printMemOperand(const MCInst *MI, int opNum, raw_ostream &O) {
  // Load/Store memory operands -- imm($reg)
  // If PIC target the target is loaded as the
  // pattern lw $25,%call16($28)
  printOperand(MI, opNum+1, O);
  O << "(";
  printOperand(MI, opNum, O);
  O << ")";
}

void OiInstTranslate::
printMemOperandEA(const MCInst *MI, int opNum, raw_ostream &O) {
  // when using stack locations for not load/store instructions
  // print the same way as all normal 3 operand instructions.
  printOperand(MI, opNum, O);
  O << ", ";
  printOperand(MI, opNum+1, O);
  return;
}

void OiInstTranslate::
printFCCOperand(const MCInst *MI, int opNum, raw_ostream &O) {
  const MCOperand& MO = MI->getOperand(opNum);
  O << OiFCCToString((Oi::CondCode)MO.getImm());
}
