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
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/Object/ELF.h"
#include "llvm-objdump.h"
using namespace llvm;

static bool error(error_code ec) {
  if (!ec) return false;

  outs() << "error reading file: " << ec.message() << ".\n";
  outs().flush();
  return true;
}

static uint64_t GetELFOffset(section_iterator &i) {
  DataRefImpl Sec = i->getRawDataRefImpl();
  const object::Elf_Shdr_Impl<object::ELFType<support::little, 2, false> > *sec =
    reinterpret_cast<const object::Elf_Shdr_Impl<object::ELFType<support::little, 2, false> > *>(Sec.p);
  return sec->sh_offset;
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
    if (SectionAddr == 0) 
      SectionAddr = GetELFOffset(i);
    uint64_t SectSize;
    if (error(i->getSize(SectSize))) break;
    if (SectSize + SectionAddr > ShadowSize)
      ShadowSize = SectSize + SectionAddr;
  }

  //Allocate some space for the stack
  //ShadowSize += 10 << 20;
  ShadowSize += StackSize;
  ShadowImage.reset(new uint8_t[ShadowSize]);
 
  for (section_iterator i = Obj->begin_sections(),
                        e = Obj->end_sections();
                        i != e; i.increment(ec)) {
    uint64_t SectionAddr;
    if (error(i->getAddress(SectionAddr))) break;
    uint64_t SectSize;
    if (error(i->getSize(SectSize))) break;

    uint64_t Offset = 0;
    if (SectionAddr == 0) 
      Offset = GetELFOffset(i);
    
    StringRef Bytes;
    if (error(i->getContents(Bytes))) break;
    StringRefMemoryObject memoryObject(Bytes);
    memoryObject.readBytes(SectionAddr, SectSize, 
                           &ShadowImage[0] + SectionAddr + Offset, 0); 
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
  case Oi::D0_64:
    return Oi::F0;
  case Oi::D1_64:
    return Oi::F1;
  case Oi::D2_64:
    return Oi::F2;
  case Oi::D3_64:
    return Oi::F3;
  case Oi::D4_64:
    return Oi::F4;
  case Oi::D5_64:
    return Oi::F5;
  case Oi::D6_64:
    return Oi::F6;
  case Oi::D7_64:
    return Oi::F7;
  case Oi::D8_64:
    return Oi::F8;
  case Oi::D9_64:
    return Oi::F9;
  case Oi::D10_64:
    return Oi::F10;
  case Oi::D11_64:
    return Oi::F11;
  case Oi::D12_64:
    return Oi::F12;
  case Oi::D13_64:
    return Oi::F13;
  case Oi::D14_64:
    return Oi::F14;
  case Oi::D15_64:
    return Oi::F15;
    //    return regnum - 1;
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
    // Floating point registers
  case Oi::D0:
  case Oi::F0:
    return 34;
  case Oi::F1:
    return 35;
  case Oi::D1:
  case Oi::F2:
    return 36;
  case Oi::F3:
    return 37;
  case Oi::D2:
  case Oi::F4:
    return 38;
  case Oi::F5:
    return 39;
  case Oi::D3:
  case Oi::F6:
    return 40;
  case Oi::F7:
    return 41;
  case Oi::D4:
  case Oi::F8:
    return 42;
  case Oi::F9:
    return 43;
  case Oi::D5:
  case Oi::F10:
    return 44;
  case Oi::F11:
    return 45;
  case Oi::D6:
  case Oi::F12:
    return 46;
  case Oi::F13:
    return 47;
  case Oi::D7:
  case Oi::F14:
    return 48;
  case Oi::F15:
    return 49;
  case Oi::D8:
  case Oi::F16:
    return 50;
  case Oi::F17:
    return 51;
  case Oi::D9:
  case Oi::F18:
    return 52;
  case Oi::F19:
    return 53;
  case Oi::D10:
  case Oi::F20:
    return 54;
  case Oi::F21:
    return 55;
  case Oi::D11:
  case Oi::F22:
    return 56;
  case Oi::F23:
    return 57;
  case Oi::D12:
  case Oi::F24:
    return 58;
  case Oi::F25:
    return 59;
  case Oi::D13:
  case Oi::F26:
    return 60;
  case Oi::F27:
    return 61;
  case Oi::D14:
  case Oi::F28:
    return 62;
  case Oi::F29:
    return 63;
  case Oi::D15:
  case Oi::F30:
    return 64;
  case Oi::F31:
    return 65;

  }
  llvm_unreachable("Invalid register");
  return -1;
}


void OiInstTranslate::BuildRegisterFile() {
  Type *ty = Type::getInt32Ty(getGlobalContext());
  // 32 base regs  0-31
  // LO 32
  // HI 33
  // 32 fp regs 34-65
  // FPCondCode 66
  for (int I = 0; I < 67; ++I) {
    Constant *ci = ConstantInt::get(ty, 0U);
    GlobalVariable *gv = new GlobalVariable(*TheModule, ty, false, 
                                            GlobalValue::ExternalLinkage,
                                            ci, "reg");
    Regs[I] = gv;
  }
}

void OiInstTranslate::InsertStartupCode() {
  // Initialize the stack
  Value *size = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                  ShadowSize);
  Builder.CreateStore(size, Regs[ConvToDirective(Oi::SP)]);
}

BasicBlock* OiInstTranslate::CreateBB(uint64_t Addr, Function *F) {
  if (Addr == 0)
    Addr = CurAddr;
  Twine T("bb");
  T = T.concat(Twine::utohexstr(Addr));
  std::string Idx = T.str();

  if (BBMap[Idx] == 0) {
    if (F == 0)
      F = Builder.GetInsertBlock()->getParent();
    BBMap[Idx] = BasicBlock::Create(getGlobalContext(), Idx, F);
  }
  return BBMap[Idx];
}

void OiInstTranslate::UpdateInsertPoint() {
  Twine T("bb");
  T = T.concat(Twine::utohexstr(CurAddr));
  std::string Idx = T.str();

  if (BBMap[Idx] != 0) {
    if (Builder.GetInsertBlock() != BBMap[Idx]) {
      // First check if we need to add a fall-through terminator to the
      // current basic block
      BasicBlock *BB = Builder.GetInsertBlock();
      if (BB != 0) {
        if (BB->getTerminator() == 0) {
          Builder.CreateBr(BBMap[Idx]);
        }
      }
      CurBlockAddr = CurAddr;
      Builder.SetInsertPoint(BBMap[Idx]);
    }
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
    CreateBB(0, F);
    UpdateInsertPoint();
    InsertStartupCode();
  } else {
    F = reinterpret_cast<Function *>(TheModule->getOrInsertFunction(N.str(), FT));
    CreateBB(0, F);
    UpdateInsertPoint();
  }
}

void OiInstTranslate::FinishFunction() {
  //Builder.CreateRetVoid();
}

Module* OiInstTranslate::takeModule() {
  return TheModule.take();
}

static Value* GetFirstInstruction(Value *o0, Value *o1) {
  if (isa<Instruction>(o0))
    return o0;
  return o1;
}

static Value* GetFirstInstruction(Value *o0, Value *o1, Value *o2) {
  if (isa<Instruction>(o0))
    return o0;
  if (isa<Instruction>(o1))
    return o1;
  return o2;
}

static Value* GetFirstInstruction(Value *o0, Value *o1, Value *o2, Value *o3) {
  if (isa<Instruction>(o0))
    return o0;
  if (isa<Instruction>(o1))
    return o1;
  if (isa<Instruction>(o2))
    return o2;
  return o3;
}

bool OiInstTranslate::HandleAluSrcOperand(const MCOperand &o, Value *&V) {
  if (o.isReg()) {
    unsigned reg = conv32(o.getReg());
    if (ConvToDirective(reg) == 0) {
      V = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0);
      return true;
    }
    V = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
    return true;
  } else if (o.isImm()) {
    uint64_t myimm = o.getImm();
    uint64_t reltype = 0;
    if (ResolveRelocation(myimm, &reltype)) {
      if (reltype == ELF::R_MIPS_LO16) {
        Value *V0 = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                     myimm + o.getImm());
        Value *V1 = Builder.CreateAnd(V0, ConstantInt::get
                                      (Type::getInt32Ty(getGlobalContext()), 
                                       0xFFFF));
        V = V1;
        return true;
      }
    }
    V = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                         myimm);
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

bool OiInstTranslate::HandleDoubleSrcOperand(const MCOperand &o, Value *&V, Value **First) {
  if (o.isReg()) {
    unsigned reg = conv32(o.getReg());
    Value *v1 = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
    Value *v2 = Builder.CreateLoad(Regs[ConvToDirective(reg)+1]);
    // Assume little endian for doubles
    Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
    Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
    Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                   (Type::getInt64Ty(getGlobalContext()), 32));
    Value *v6 = Builder.CreateOr(v5,v4);
    V = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));
    if (First != 0)
      *First = v1;
    return true;
  } 
  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleDoubleDstOperand(const MCOperand &o, Value *&V1, Value *&V2) {
  if (o.isReg()) {
    unsigned reg = conv32(o.getReg());
    // Assume little endian doubles
    V2 = Regs[ConvToDirective(reg)];
    V1 = Regs[ConvToDirective(reg)+1];
    return true;
  }
  llvm_unreachable("Invalid dst operand");
}

bool OiInstTranslate::HandleDoubleMemOperand(const MCOperand &o, const MCOperand &o2,
                                             Value *&V1, Value *&V2, Value **First,
                                             bool IsLoad) {
  if (o.isReg() && o2.isImm()) {
    uint64_t myimm = o2.getImm();
    uint64_t reltype = 0;
    Value *idx, *addr, *base;
    if (ResolveRelocation(myimm, &reltype)) {
      if (reltype == ELF::R_MIPS_LO16) {
        Value *V0 = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                     myimm + o2.getImm());
        Value *V1 = Builder.CreateAnd(V0, ConstantInt::get
                                      (Type::getInt32Ty(getGlobalContext()), 
                                       0xFFFF));
        idx = V1;
        //Assume little endian doubles
        unsigned reg = conv32(o.getReg());
        base = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
        addr = Builder.CreateAdd(base, idx);
        if (First != 0) {
          *First = GetFirstInstruction(V1, base, addr);
        }
      } else {
        llvm_unreachable("Don't know how to handle this relocation");
      }      
    } else {
      idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                             myimm);
      //Assume little endian doubles
      unsigned reg = conv32(o.getReg());
      base = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
      addr = Builder.CreateAdd(base, idx);
      if (First != 0)
        *First = GetFirstInstruction(base, addr);
    }
    V2 = AccessShadowMemory32(addr, IsLoad);
    Value *idx2 = Builder.CreateAdd(idx, ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 4U));
    Value *addr2 = Builder.CreateAdd(base, idx2);
    V1 = AccessShadowMemory32(addr2, IsLoad);
    if (First != 0) {
      *First = GetFirstInstruction(*First, V2);
    }
    return true;
  } 

  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleSaveDouble(Value *In, Value *&Out1, Value *&Out2) {
  Value *v1 = Builder.CreateBitCast(In, Type::getInt64Ty(getGlobalContext()));
  Value *v2 = Builder.CreateLShr(v1, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Out1 = Builder.CreateSExtOrTrunc(v2, Type::getInt32Ty(getGlobalContext()));
  Out2 = Builder.CreateSExtOrTrunc(v1, Type::getInt32Ty(getGlobalContext()));
  return true;
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
  Idxs.push_back(ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U));
  Idxs.push_back(Idx);
  Value *gep = Builder.CreateGEP(ShadowImageValue, Idxs);
  Value *ptr = Builder.CreateBitCast(gep, Type::getInt32PtrTy(getGlobalContext()));
  if (IsLoad)
    return Builder.CreateLoad(ptr);
  return ptr;
}

bool OiInstTranslate::HandleLUiOperand(const MCOperand &o, Value *&V, Value **First,
                                       bool IsLoad) {
  if (o.isImm()) {
    uint64_t addr = o.getImm();

    if (ResolveRelocation(addr)) {
      addr += o.getImm();
      Value *idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), addr);    
      Value *V1 = Builder.CreateLShr(idx, ConstantInt::get
                                     (Type::getInt32Ty(getGlobalContext()), 16));
      *First = V1;
      Value *V2 = Builder.CreateShl(V1, ConstantInt::get
                                    (Type::getInt32Ty(getGlobalContext()), 16));
      if (!isa<Instruction>(*First)) {
        *First = V2;
      }
      V = V2;
    } else {
      Value *idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), addr);    
      Value *V2 = Builder.CreateShl(idx, ConstantInt::get
                                    (Type::getInt32Ty(getGlobalContext()), 16));
      *First = V2;
      V = V2;
    }
    return true;
  }
  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleMemOperand(const MCOperand &o, const MCOperand &o2,
                                       Value *&V, Value **First, bool IsLoad) {
  if (o.isReg() && o2.isImm()) {
    uint64_t myimm = o2.getImm();
    uint64_t reltype = 0;
    Value *idx, *addr;
    if (ResolveRelocation(myimm, &reltype)) {
      if (reltype == ELF::R_MIPS_LO16) {
        Value *V0 = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                     myimm + o2.getImm());
        Value *V1 = Builder.CreateAnd(V0, ConstantInt::get
                                      (Type::getInt32Ty(getGlobalContext()), 
                                       0xFFFF));
        *First = V1;
        idx = V1;
        unsigned reg = conv32(o.getReg());
        Value *base = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
        if (!isa<Instruction>(*First)) {
          *First = base;
        }
        addr = Builder.CreateAdd(base, idx);
        if (!isa<Instruction>(*First)) {
          *First = addr;
        }
      } else {
        llvm_unreachable("Don't know how to handle this relocation");
      }      
    } else {
      idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                             myimm);
      unsigned reg = conv32(o.getReg());
      Value *base = Builder.CreateLoad(Regs[ConvToDirective(reg)]);
      addr = Builder.CreateAdd(base, idx);
      *First = base;
    }
    V = AccessShadowMemory32(addr, IsLoad);
    return true;
  } 

  //  } else if (o.isExpr()) {
  //  int64_t val;
  //  if(o.getExpr()->EvaluateAsAbsolute(val)) { 
  //    Value *idx = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), val);
  //    V = AccessShadowMemory32(idx, IsLoad);
  //  } else {
  //    return HandleMemExpr(*o.getExpr(), V, IsLoad);
  //  }
  //  return true;
  //}
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

bool OiInstTranslate::ResolveRelocation(uint64_t &Res, uint64_t *Type) {
  relocation_iterator Rel = (*CurSection)->end_relocations();
  error_code ec;
  StringRef Name;
  if (!CheckRelocation(Rel, Name))
    return false;
  for (section_iterator i = Obj->begin_sections(),
         e = Obj->end_sections();
       i != e; i.increment(ec)) {
    if (error(ec)) break;
    StringRef SecName;
    if (error(i->getName(SecName))) break;
    if (SecName != Name)
      continue;
    
    uint64_t SectionAddr;
    if (error(i->getAddress(SectionAddr))) break;

    // Relocatable file
    if (SectionAddr == 0) {
      SectionAddr = GetELFOffset(i);
    }

    Res = SectionAddr;
    if (Type) {
      if (error(Rel->getType(*Type)))
        llvm_unreachable("Error getting relocation type");
    }
    return true;
  }

  for (symbol_iterator si = Obj->begin_symbols(),
         se = Obj->end_symbols();
       si != se; si.increment(ec)) {
    StringRef SName;
    if (error(si->getName(SName))) break;
    if (Name != SName)
      continue;

    uint64_t Address;
    if (error(si->getAddress(Address))) break;
    if (Address == UnknownAddressOrSize) continue;
    //        Address -= SectionAddr;
    Res = Address;

    section_iterator seci = Obj->end_sections();
    // Check if it is relative to a section
    if ((!error(si->getSection(seci)))
        && seci != Obj->end_sections()) {
      uint64_t SectionAddr;
      if (error(seci->getAddress(SectionAddr))) 
        llvm_unreachable("Error getting section address");

      // Relocatable file
      if (SectionAddr == 0) {
        SectionAddr = GetELFOffset(seci);
      }
      Res += SectionAddr;
    }

    if (Type) {
      if (error(Rel->getType(*Type)))
        llvm_unreachable("Error getting relocation type");
    }
    return true;
  }

  return false;
}

bool OiInstTranslate::CheckRelocation(relocation_iterator &Rel, StringRef &Name) {
  error_code ec;
  uint64_t offset = GetELFOffset(*CurSection);
  for (relocation_iterator ri = (*CurSection)->begin_relocations(),
         re = (*CurSection)->end_relocations();
       ri != re; ri.increment(ec)) {
    if (error(ec)) break;
    uint64_t addr;
    if (error(ri->getOffset(addr))) break;
    if (offset + addr != CurAddr)
      continue;

    Rel = ri;
    SymbolRef symb;
    if (!error(ri->getSymbol(symb))) {
      if (!error(symb.getName(Name))) {
        return true;
      }
    }
  }

  return false;
}

bool OiInstTranslate::HandleCallTarget(const MCOperand &o, Value *&V) {
  if (o.isImm()) {
    Twine T("a");
    if (o.getImm() != 0U) {
      T = T.concat(Twine::utohexstr(o.getImm()));
      return HandleLocalCall(StringRef(T.str()), V);
    } else { // Need to handle the relocation to find the correct jump address
      relocation_iterator ri = (*CurSection)->end_relocations();
      StringRef val;
      if (CheckRelocation(ri, val)) {
        if (val == "write") 
          return HandleSyscallWrite(V);        
        if (val == "atoi")
          return HandleLibcAtoi(V);
        if (val == "malloc")
          return HandleLibcMalloc(V);
        if (val == "free")
          return HandleLibcFree(V);
        if (val == "printf")
          return HandleLibcPrintf(V);
        if (val == "__isoc99_scanf")
          return HandleLibcScanf(V);
      }
      uint64_t targetaddr;
      if (ResolveRelocation(targetaddr)) {
        T = T.concat(Twine::utohexstr(targetaddr));
        return HandleLocalCall(StringRef(T.str()), V);
      }
      llvm_unreachable("Unrecognized function call");
    }
    llvm_unreachable("Unrecognized function call");
    return false;
  }
  return false;
}

bool OiInstTranslate::HandleFCmpOperand(const MCOperand &o, Value *o0, Value *o1, Value *&V) {
  if (o.isImm()) {
    uint64_t cond = o.getImm();
    Value *cmp = 0;
    switch (cond) {
    case 0: // OI_FCOND_F  false
      cmp = ConstantInt::get(Type::getInt1Ty(getGlobalContext()), 0);
      break;
    case 1: // OI_FCOND_UN unordered - true if either nans
      cmp = Builder.CreateFCmpUNO(o0, o1);
      break;
    case 2: // OI_FCOND_OEQ equal
      cmp = Builder.CreateFCmpOEQ(o0, o1);
      break;
    case 3: // OI_FCOND_UEQ unordered or equal
      cmp = Builder.CreateFCmpUEQ(o0, o1);
      break;
    case 4: // OI_FCOND_OLT
      cmp = Builder.CreateFCmpOLT(o0, o1);
      break;
    case 5: // OI_FCOND_ULT
      cmp = Builder.CreateFCmpULT(o0, o1);
      break;
    case 6: // OI_FCOND_OLE
      cmp = Builder.CreateFCmpOLE(o0, o1);
      break;
    case 7: // OI_FCOND_ULE
      cmp = Builder.CreateFCmpULE(o0, o1);
      break;
    case 8: // OI_FCOND_SF
      // Exception not implemented
      llvm_unreachable("Unimplemented FCmp Operand");
      cmp = ConstantInt::get(Type::getInt1Ty(getGlobalContext()), 0);
      break;
    case 9: // OI_FCOND_NGLE - compare not greater or less than equal double 
            // (w/ except.)
      cmp = Builder.CreateFCmpOLE(o0, o1);
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 10: // OI_FCOND_SEQ
      cmp = Builder.CreateFCmpOEQ(o0, o1);
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 11: // OI_FCOND_NGL
      cmp = Builder.CreateFCmpULE(o0, o1);
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 12: // OI_FCOND_LT
      cmp = Builder.CreateFCmpULE(o0, o1);
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 13: // OI_FCOND_NGE
      cmp = Builder.CreateFCmpULE(o0, o1);
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 14: // OI_FCOND_LE
      cmp = Builder.CreateFCmpULE(o0, o1);
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 15: // OI_FCOND_NGT
      cmp = Builder.CreateFCmpULE(o0, o1);
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    }    
    V = cmp;
    return true;
  }
  llvm_unreachable("Unrecognized FCmp Operand");
  return false;
}

bool OiInstTranslate::HandleBranchTarget(const MCOperand &o, BasicBlock *&Target,
                                         bool IsRelative) {
  if (o.isImm()) {
    Twine T("a");
    if (o.getImm() != 0U) {
      uint64_t tgtaddr;
      if (IsRelative)
        tgtaddr = (CurAddr + o.getImm()) & 0xFFFFFFFFULL;
      else
        tgtaddr = o.getImm();
      uint64_t rel = 0;
      if (ResolveRelocation(rel)) {
        tgtaddr += rel;
      }
      assert (tgtaddr != CurAddr);
      if (tgtaddr < CurAddr)
        return HandleBackEdge(tgtaddr, Target);
      Target = CreateBB(tgtaddr);
      return true;
    } else { // Need to handle the relocation to find the correct jump address
      uint64_t targetaddr;
      if (ResolveRelocation(targetaddr)) {
        Target = CreateBB(targetaddr);
        return true;
      }
    }
  }
  llvm_unreachable("Unrecognized branch target");
}

bool OiInstTranslate::HandleBackEdge(uint64_t Addr, BasicBlock *&Target) {
  Twine T("bb");
  T = T.concat(Twine::utohexstr(Addr));
  std::string Idx = T.str();

  if (BBMap[Idx] != 0) {
    Target = BBMap[Idx];
    return true;
  }

  Instruction *TgtIns = InsMap[Addr];
  while (TgtIns == 0 && Addr < CurAddr) {
    Addr += 4;
    TgtIns = InsMap[Addr];
  }
    
  assert(TgtIns && "Backedge out of range");
  assert(TgtIns->getParent()->getParent() 
         == Builder.GetInsertBlock()->getParent() && "Backedge out of range");

  Twine T2("bb");
  T2 = T2.concat(Twine::utohexstr(Addr));
  Idx = T2.str();
  if (BBMap[Idx] != 0) {
    Target = BBMap[Idx];
    return true;
  }
  BasicBlock *BB = TgtIns->getParent();
  BasicBlock::iterator I, E;
  for (I = BB->begin(), E = BB->end(); I != E; ++I) {
    if (&*I == TgtIns)
      break;
  }
  assert (I != E);
  if (BB->getTerminator()) {
    Target = BB->splitBasicBlock(I, Idx);    
    BBMap[Idx] = Target;
    return true;
  }

  //Insert dummy terminator
  assert(Builder.GetInsertBlock() == BB && CurBlockAddr < Addr);
  Instruction *dummy = dyn_cast<Instruction>(Builder.CreateRetVoid());
  assert(dummy);
  Target = BB->splitBasicBlock(I, Idx);    
  BBMap[Idx] = Target;
  CurBlockAddr = Addr;
  dummy->eraseFromParent();
  Builder.SetInsertPoint(Target, Target->end());
  
  return true;
}

bool OiInstTranslate::HandleLocalCall(StringRef Name, Value *&V) {
  FunctionType *ft = FunctionType::get(Type::getVoidTy(getGlobalContext()),
                                       /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction(Name, ft);
  V = Builder.CreateCall(fun);
  return true;
}

bool OiInstTranslate::HandleLibcAtoi(Value *&V) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("atoi", ft);
  SmallVector<Value*, 8> params;
  Value *addrbuf = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A0)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), Regs[ConvToDirective
                                                                (Oi::V0)]);
  return true;
}

bool OiInstTranslate::HandleLibcMalloc(Value *&V) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("malloc", ft);
  SmallVector<Value*, 8> params;
  params.push_back(Builder.CreateLoad(Regs[ConvToDirective(Oi::A0)]));
  Value *mal = Builder.CreateCall(fun, params);
  Value *ptr = Builder.CreatePtrToInt(ShadowImageValue, Type::getInt32Ty(getGlobalContext()));
  Value *fixed = Builder.CreateSub(mal, ptr);
  V = Builder.CreateStore(fixed, Regs[ConvToDirective
                                                                (Oi::V0)]);
  return true;
}

bool OiInstTranslate::HandleLibcFree(Value *&V) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getVoidTy(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("free", ft);
  SmallVector<Value*, 8> params;
  Value *addrbuf = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A0)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  V = Builder.CreateCall(fun, params);
  return true;
}

// XXX: Handling a fixed number of 4 arguments, since we cannot infer how many
// arguments the program is using with printf
bool OiInstTranslate::HandleLibcPrintf(Value *&V) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("printf", ft);
  SmallVector<Value*, 8> params;
  Value *addrbuf = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A0)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreateLoad(Regs[ConvToDirective(Oi::A1)]));
  params.push_back(Builder.CreateLoad(Regs[ConvToDirective(Oi::A2)]));
  params.push_back(Builder.CreateLoad(Regs[ConvToDirective(Oi::A3)]));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), Regs[ConvToDirective
                                                                (Oi::V0)]);
  return true;
}

// XXX: Handling a fixed number of 4 arguments, since we cannot infer how many
// arguments the program is using with scanf
bool OiInstTranslate::HandleLibcScanf(Value *&V) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("__isoc99_scanf", ft);
  SmallVector<Value*, 8> params;
  Value *addrbuf0 = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A0)]), false);
  Value *addrbuf1 = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A1)]), false);
  Value *addrbuf2 = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A2)]), false);
  Value *addrbuf3 = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A3)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf0,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreatePtrToInt(addrbuf1,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreatePtrToInt(addrbuf2,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreatePtrToInt(addrbuf3,
                                          Type::getInt32Ty(getGlobalContext())));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), Regs[ConvToDirective
                                                                (Oi::V0)]);
  return true;
}

bool OiInstTranslate::HandleSyscallWrite(Value *&V) {
  SmallVector<Type*, 8> args(3, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("write", ft);
  SmallVector<Value*, 8> params;
  params.push_back(Builder.CreateLoad(Regs[ConvToDirective(Oi::A0)]));
  Value *addrbuf = AccessShadowMemory32
    (Builder.CreateLoad(Regs[ConvToDirective(Oi::A1)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreateLoad(Regs[ConvToDirective(Oi::A2)]));

  V = Builder.CreateStore(Builder.CreateCall(fun, params), Regs[ConvToDirective
                                                                (Oi::V0)]);

  return true;
}

void OiInstTranslate::printInstruction(const MCInst *MI, raw_ostream &O) {
#ifndef NDEBUG
  raw_ostream &DebugOut = dbgs();
#else
  raw_ostream &DebugOut = nulls();
#endif

  switch (MI->getOpcode()) {
  case Oi::ADDiu:
  case Oi::ADDi:
  case Oi::ADDu:
  case Oi::ADD:
    DebugOut << "Handling ADDiu, ADDi, ADDu, ADD\n";
    Value *o0, *o1, *o2;
    if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
        HandleAluSrcOperand(MI->getOperand(2), o2) &&
        HandleAluDstOperand(MI->getOperand(0), o0)) {
      Value *v = Builder.CreateAdd(o1, o2);
      Value *v2 = Builder.CreateStore(v, o0);
      Value *first = GetFirstInstruction(o1, o2, v, v2);
      assert(isa<Instruction>(first) && "Need to rework map logic");
      InsMap[CurAddr] = dyn_cast<Instruction>(first);
      v2->dump();
    }
    break;
  case Oi::SUBu:
  case Oi::SUB:
    {
      DebugOut << "Handling SUBu, SUB\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateSub(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::MUL:
    {
      DebugOut << "Handling MUL\n";
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateMul(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::MULT:
    {
      DebugOut << "Handling MULT\n";
      if (HandleAluSrcOperand(MI->getOperand(0), o0) &&
          HandleAluSrcOperand(MI->getOperand(1), o1)) {      
        Value *o0se = Builder.CreateSExtOrTrunc(o0, Type::getInt64Ty(getGlobalContext()));
        Value *o1se = Builder.CreateSExtOrTrunc(o1, Type::getInt64Ty(getGlobalContext()));
        Value *v = Builder.CreateMul(o0se, o1se);
        Value *V1 = Builder.CreateLShr(v, ConstantInt::get
                                       (Type::getInt64Ty(getGlobalContext()), 32));
        Value *V2 = Builder.CreateSExtOrTrunc(V1, Type::getInt32Ty(getGlobalContext()));
        Value *V3 = Builder.CreateSExtOrTrunc(v, Type::getInt32Ty(getGlobalContext()));
        Value *v4 = Builder.CreateStore(V2, Regs[33]);
        Value *v5 = Builder.CreateStore(V3, Regs[32]);
        assert(isa<Instruction>(o0) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(o0);
        o0se->dump();
      }
      break;
    }
  case Oi::MFHI:
    {
      DebugOut << "Handling MFHI\n";
      if (HandleAluDstOperand(MI->getOperand(0), o0)) {
        Value *v = Builder.CreateLoad(Regs[33]);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o0, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::MFLO:
    {
      DebugOut << "Handling MFLO\n";
      if (HandleAluDstOperand(MI->getOperand(0), o0)) {
        Value *v = Builder.CreateLoad(Regs[32]);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o0, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::LDC1:
    {
      DebugOut << "Handling LDC1\n";
      Value *dst1, *dst2, *src1, *src2, *first;
      if (HandleDoubleDstOperand(MI->getOperand(0),dst1,dst2) &&
          HandleDoubleMemOperand(MI->getOperand(1), MI->getOperand(2), src1, src2, &first, true)) {
        Value *v = Builder.CreateStore(src1, dst1);
        Value *v2 = Builder.CreateStore(src2, dst2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v->dump();
      }
      break;
    }
  case Oi::SDC1:
    {
      DebugOut << "Handling SDC1\n";
      Value *dst_hi, *dst_lo, *src, *first;
      if (HandleDoubleSrcOperand(MI->getOperand(0), src, &first) &&
          HandleDoubleMemOperand(MI->getOperand(1), MI->getOperand(2), dst_hi, dst_lo, 0, false)) {
        Value *hi, *lo;
        HandleSaveDouble(src, hi, lo);
        Builder.CreateStore(hi, dst_hi);
        Builder.CreateStore(lo, dst_lo);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        src->dump();
      }
      break;
    }
  case Oi::FCMP_D32:
    {
      DebugOut << "Handling FCMP_D32\n";
      uint32_t cond;
      Value *o0, *o1, *first;
      if (HandleDoubleSrcOperand(MI->getOperand(0), o0, &first) &&
          HandleDoubleSrcOperand(MI->getOperand(1), o1)) {
        Value *cmp;
        if (HandleFCmpOperand(MI->getOperand(2), o0, o1, cmp)) {
          Value *one = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 1U);
          Value *zero = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U);
          Value *select = Builder.CreateSelect(cmp, one, zero);
          Builder.CreateStore(select, Regs[66]);
          assert(isa<Instruction>(first) && "Need to rework map logic");
          InsMap[CurAddr] = dyn_cast<Instruction>(first);
          select->dump();
        }
      }
      break;
    }
  case Oi::FADD_D32:
    {
      DebugOut << "Handling FADD\n";
      Value *o01, *o02, *o1, *o2, *first;
      if (HandleDoubleSrcOperand(MI->getOperand(1), o1, &first) &&       
          HandleDoubleSrcOperand(MI->getOperand(2), o2) &&       
          HandleDoubleDstOperand(MI->getOperand(0), o01, o02)) {      
        Value *high, *low;
        Value *V = Builder.CreateFAdd(o1, o2);
        HandleSaveDouble(V, high, low);
        Builder.CreateStore(high, o01);
        Builder.CreateStore(low, o02);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        o1->dump();
      }      
      break;
    }
  case Oi::FMUL_D32:
    {
      DebugOut << "Handling FMUL\n";
      Value *o01, *o02, *o1, *o2, *first;
      if (HandleDoubleSrcOperand(MI->getOperand(1), o1, &first) &&       
          HandleDoubleSrcOperand(MI->getOperand(2), o2) &&       
          HandleDoubleDstOperand(MI->getOperand(0), o01, o02)) {      
        Value *high, *low;
        Value *V = Builder.CreateFMul(o1, o2);
        HandleSaveDouble(V, high, low);
        Builder.CreateStore(high, o01);
        Builder.CreateStore(low, o02);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        o1->dump();
      }      
      break;
    }
  case Oi::FDIV_D32:
    {
      DebugOut << "Handling FDIV\n";
      Value *o01, *o02, *o1, *o2, *first;
      if (HandleDoubleSrcOperand(MI->getOperand(1), o1, &first) &&       
          HandleDoubleSrcOperand(MI->getOperand(2), o2) &&       
          HandleDoubleDstOperand(MI->getOperand(0), o01, o02)) {      
        Value *high, *low;
        Value *V = Builder.CreateFDiv(o1, o2);
        HandleSaveDouble(V, high, low);
        Builder.CreateStore(high, o01);
        Builder.CreateStore(low, o02);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        o1->dump();
      }      
      break;
    }
  case Oi::CVT_D32_W:
    {
      DebugOut << "Handling CVT.D.W\n";
      Value *o01, *o02, *o1;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&       
          HandleDoubleDstOperand(MI->getOperand(0), o01,o02)) {      
        Value *high, *low;
        Value *v1 = Builder.CreateSIToFP(o1, Type::getDoubleTy(getGlobalContext()));
        HandleSaveDouble(v1, high, low);
        Value *v2 = Builder.CreateStore(high, o01);
        Value *v3 = Builder.CreateStore(low, o02);
        Value *first = GetFirstInstruction(o1, v1);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v1->dump();
      }      
      break;
    }
  case Oi::MFC1:
  case Oi::MTC1:
    {
      DebugOut << "Handling MFC1, MTC1\n";
      Value *o0, *o1;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&       
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateStore(o1, o0);
        Value *first = GetFirstInstruction(o1, v);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v->dump();
      }
      break;
    }
  case Oi::BC1T:
  case Oi::BC1F:
    {
      DebugOut << "Handling BC1F, BC1T\n";
      BasicBlock *True = 0;
      if (HandleBranchTarget(MI->getOperand(0), True)) {
        Value *cmp;
        if (MI->getOpcode() == Oi::BC1T) {
          cmp = Builder.CreateSExtOrTrunc(Builder.CreateLoad(Regs[66]),
                                    Type::getInt1Ty(getGlobalContext()));
        } else {
          cmp = Builder.CreateICmpEQ(Builder.CreateLoad(Regs[66]),
                             ConstantInt::get(Type::getInt32Ty
                                              (getGlobalContext()), 0U));
        }
        Value *v = Builder.CreateCondBr(cmp, True, CreateBB(CurAddr+4));
        assert(isa<Instruction>(cmp) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(cmp);
        v->dump();
      }
      break;
    }
  case Oi::J:
    {
      DebugOut << "Handling J\n";
      Value *o1;
      BasicBlock *Target = 0;
      if (HandleBranchTarget(MI->getOperand(0), Target, false)) {
        Value *v = Builder.CreateBr(Target);
        InsMap[CurAddr] = dyn_cast<Instruction>(v);
        CreateBB(CurAddr+4);
        v->dump();
      }
      break;
    }
  case Oi::SRA:
    {
      DebugOut << "Handling SRA\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateAShr(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::SRL:
    {
      DebugOut << "Handling SRL\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateLShr(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::SLL:
    {
      DebugOut << "Handling SLL\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateShl(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::ORi:
  case Oi::OR:
    {
      DebugOut << "Handling ORi, OR\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateOr(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::SLTiu:
  case Oi::SLTu:
  case Oi::SLTi:
  case Oi::SLT:
    {
      DebugOut << "Handling SLT\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      

        Function *F = Builder.GetInsertBlock()->getParent();
        BasicBlock *BB1 = BasicBlock::Create(getGlobalContext(), "", F);
        BasicBlock *BB2 = BasicBlock::Create(getGlobalContext(), "", F);
        BasicBlock *FT = CreateBB(CurAddr+4);

        Value *cmp = 0;
        if (MI->getOpcode() == Oi::SLTiu ||
            MI->getOpcode() == Oi::SLTu)
          cmp = Builder.CreateICmpULT(o1, o2);
        else
          cmp = Builder.CreateICmpSLT(o1, o2);
        Builder.CreateCondBr(cmp, BB1, BB2);
        
        Value *one = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 1U);
        Value *zero = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U);

        Builder.SetInsertPoint(BB1);
        Builder.CreateStore(one, o0);
        Builder.CreateBr(FT);
        Builder.SetInsertPoint(BB2);
        Builder.CreateStore(zero, o0);
        Builder.CreateBr(FT);
        Builder.SetInsertPoint(FT);
        CurBlockAddr = CurAddr+4;

        assert(isa<Instruction>(cmp) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(cmp);
        cmp->dump();
      }      
      break;
    }
  case Oi::BEQ:
    {
      DebugOut << "Handling BEQ\n";
      Value *o1, *o2;
      BasicBlock *True = 0;
      if (HandleAluSrcOperand(MI->getOperand(0), o1) &&
          HandleAluSrcOperand(MI->getOperand(1), o2) &&
          HandleBranchTarget(MI->getOperand(2), True)) {
        Value *cmp = Builder.CreateICmpEQ(o1, o2);
        Value *v = Builder.CreateCondBr(cmp, True, CreateBB(CurAddr+4));
        Value *first = GetFirstInstruction(o1, o2, cmp, v);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v->dump();
      }
      break;
    }
  case Oi::BNE:
    {
      DebugOut << "Handling BNE\n";
      Value *o1, *o2;
      BasicBlock *True = 0;
      if (HandleAluSrcOperand(MI->getOperand(0), o1) &&
          HandleAluSrcOperand(MI->getOperand(1), o2) &&
          HandleBranchTarget(MI->getOperand(2), True)) {
        Value *cmp = Builder.CreateICmpNE(o1, o2);
        Value *v = Builder.CreateCondBr(cmp, True, CreateBB(CurAddr+4));
        Value *first = GetFirstInstruction(o1, o2, cmp, v);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        InsMap[CurAddr] = dyn_cast<Instruction>(first);
        v->dump();
      }
      break;
    }
  case Oi::LUi:
  case Oi::LUi64: {
    DebugOut << "Handling LUi\n";
    Value *dst, *src, *first;
    if (HandleAluDstOperand(MI->getOperand(0),dst) &&
        HandleLUiOperand(MI->getOperand(1), src, &first, true)) {
      Value *v = Builder.CreateStore(src, dst);
      if (!isa<Instruction>(first))
        first = v;
      assert(isa<Instruction>(first) && "Need to rework map logic");
      InsMap[CurAddr] = dyn_cast<Instruction>(first);
      v->dump();
    }
    break;
  }
  case Oi::LW:
  case Oi::LW64: {
    DebugOut << "Handling LW\n";
    Value *dst, *src, *first;
    if (HandleAluDstOperand(MI->getOperand(0),dst) &&
        HandleMemOperand(MI->getOperand(1), MI->getOperand(2), src, &first, true)) {
      Value *v = Builder.CreateStore(src, dst);
      assert(isa<Instruction>(first) && "Need to rework map logic");
      InsMap[CurAddr] = dyn_cast<Instruction>(first);
      v->dump();
    }
    break;
  }
  case Oi::SW:
  case Oi::SW64: {
    DebugOut << "Handling SW\n";
    Value *dst, *src, *first;
    if (HandleAluSrcOperand(MI->getOperand(0),src) &&
        HandleMemOperand(MI->getOperand(1), MI->getOperand(2), dst, &first, false)) {
      Value *v = Builder.CreateStore(src, dst);
      assert(isa<Instruction>(first) && "Need to rework map logic");
      InsMap[CurAddr] = dyn_cast<Instruction>(first);
      v->dump();
    }
    break;
  }
  case Oi::JALR64:
  case Oi::JALR: {
    llvm_unreachable("Can't handle indirect jumps yet.");
    break;
  }
  case Oi::JAL: {
    DebugOut << "Handling JAL\n";
    Value *call;
    if(HandleCallTarget(MI->getOperand(0), call)) {
      InsMap[CurAddr] = dyn_cast<Instruction>(call);
      call->dump();
    }
    break;
  }
  case Oi::JR64:
  case Oi::JR: {
    DebugOut << "Handling JR\n";
    if (MI->getOperand(0).getReg() == Oi::RA
        || MI->getOperand(0).getReg() == Oi::RA_64) {
      Value *v = Builder.CreateRetVoid();
      InsMap[CurAddr] = dyn_cast<Instruction>(v);
      v->dump();
    } else {
      llvm_unreachable("Can't handle indirect jumps yet.");
    }
    break;
  }
  case Oi::NOP:
    DebugOut << "Handling NOP\n";
    break;
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
