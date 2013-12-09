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
#include "StringRefMemoryObject.h"
#include "SBTUtils.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/Object/ELF.h"
using namespace llvm;

static cl::opt<bool>
DebugIR("debug-ir", cl::desc("Print the generated IR for each function, prior to optimizations"));

void OiInstTranslate::StartFunction(Twine &N) {
  IREmitter.StartFunction(N);
}

void OiInstTranslate::FinishFunction() {
  if (!OneRegion) {
    IREmitter.CleanRegs();
    IREmitter.FixBBTerminators();
    if (DebugIR) 
      IREmitter.Builder.GetInsertBlock()->getParent()->dump();
  }
  //Builder.CreateRetVoid();
}

void OiInstTranslate::FinishModule() {
  if (OneRegion) {
    IREmitter.CleanRegs();
    IREmitter.FixBBTerminators();
    IREmitter.BuildReturnTablesOneRegion();
    if (DebugIR) 
      IREmitter.Builder.GetInsertBlock()->getParent()->dump();
  }
}

Module* OiInstTranslate::takeModule() {
  return IREmitter.TheModule.take();
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
    unsigned reg = ConvToDirective(conv32(o.getReg()));
    if (reg == 0) {
      V = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0);
      return true;
    }
    V = Builder.CreateLoad(IREmitter.Regs[reg]);
    ReadMap[reg] = true;
    return true;
  } else if (o.isImm()) {
    uint64_t myimm = o.getImm();
    uint64_t reltype = 0;
    if (RelocReader.ResolveRelocation(myimm, &reltype)) {
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
  }
  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleDoubleSrcOperand(const MCOperand &o, Value *&V, Value **First) {
  if (o.isReg()) {
    unsigned reg = ConvToDirective(conv32(o.getReg()));
    Value *v1 = Builder.CreateLoad(IREmitter.Regs[reg]);
    Value *v2 = Builder.CreateLoad(IREmitter.Regs[reg+1]);
    // Assume little endian for doubles
    Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
    Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
    Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                   (Type::getInt64Ty(getGlobalContext()), 32));
    Value *v6 = Builder.CreateOr(v5,v4);
    V = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));
    if (First != 0)
      *First = v1;
    ReadMap[reg] = true;
    ReadMap[reg+1] = true;
    return true;
  } 
  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleDoubleDstOperand(const MCOperand &o, Value *&V1, Value *&V2) {
  if (o.isReg()) {
    unsigned reg = ConvToDirective(conv32(o.getReg()));
    // Assume little endian doubles
    V2 = IREmitter.Regs[reg];
    V1 = IREmitter.Regs[reg+1];
    WriteMap[reg] = true;
    WriteMap[reg+1] = true;
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
    if (RelocReader.ResolveRelocation(myimm, &reltype)) {
      if (reltype == ELF::R_MIPS_LO16) {
        Value *V0 = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                     myimm + o2.getImm());
        Value *V1 = Builder.CreateAnd(V0, ConstantInt::get
                                      (Type::getInt32Ty(getGlobalContext()), 
                                       0xFFFF));
        idx = V1;
        //Assume little endian doubles
        unsigned reg = ConvToDirective(conv32(o.getReg()));
        base = Builder.CreateLoad(IREmitter.Regs[reg]);
        ReadMap[reg] = true;
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
      unsigned reg = ConvToDirective(conv32(o.getReg()));
      base = Builder.CreateLoad(IREmitter.Regs[reg]);
      ReadMap[reg] = true;
      addr = Builder.CreateAdd(base, idx);
      if (First != 0)
        *First = GetFirstInstruction(base, addr);
    }
    V2 = IREmitter.AccessShadowMemory(addr, IsLoad);
    Value *idx2 = Builder.CreateAdd(idx, ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 4U));
    Value *addr2 = Builder.CreateAdd(base, idx2);
    V1 = IREmitter.AccessShadowMemory(addr2, IsLoad);
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
    V = IREmitter.AccessShadowMemory(idx, IsLoad);
    return true;
  } else if (const MCSymbolRefExpr *se = dyn_cast<const MCSymbolRefExpr>(&exp)){
    V = IREmitter.TheModule->getOrInsertGlobal(se->getSymbol().getName(),
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
    //    GlobalVariable(IREmitter.TheModule,
    //               Type::getInt32Ty(getGlobalContext()),
    //               false,
    //              GlobalValue::LinkageTypes::ExternalLinkage,
    //              Constant::getNullValue(Type::getInt32Ty(getGlobalContext())),
    //             se->getSymbol().getName(),
    //             0, GlobalVariable::NotThreadLocal, 0, true);
  }
  llvm_unreachable("Invalid Load Expr");
}

bool OiInstTranslate::HandleLUiOperand(const MCOperand &o, Value *&V, Value **First,
                                       bool IsLoad) {
  if (o.isImm()) {
    uint64_t addr = o.getImm();

    if (RelocReader.ResolveRelocation(addr)) {
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
                                       Value *&V, Value **First, bool IsLoad,
                                       int width) {
  if (o.isReg() && o2.isImm()) {
    uint64_t myimm = o2.getImm();
    uint64_t reltype = 0;
    Value *idx, *addr;
    if (RelocReader.ResolveRelocation(myimm, &reltype)) {
      if (reltype == ELF::R_MIPS_LO16) {
        Value *V0 = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                     myimm + o2.getImm());
        Value *V1 = Builder.CreateAnd(V0, ConstantInt::get
                                      (Type::getInt32Ty(getGlobalContext()), 
                                       0xFFFF));
        *First = V1;
        idx = V1;
        unsigned reg = ConvToDirective(conv32(o.getReg()));
        Value *base = Builder.CreateLoad(IREmitter.Regs[reg]);
        ReadMap[reg] = true;
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
      unsigned reg = ConvToDirective(conv32(o.getReg()));
      Value *base = Builder.CreateLoad(IREmitter.Regs[reg]);
      ReadMap[reg] = true;
      addr = Builder.CreateAdd(base, idx);
      *First = base;
    }
    V = IREmitter.AccessShadowMemory(addr, IsLoad, width);
    return true;
  } 
  llvm_unreachable("Invalid Src operand");
}

bool OiInstTranslate::HandleAluDstOperand(const MCOperand &o, Value *&V) {
  if (o.isReg()) {
    unsigned reg = ConvToDirective(conv32(o.getReg()));
    V = IREmitter.Regs[reg];
    WriteMap[reg] = true;
    return true;
  }
  llvm_unreachable("Invalid Dst operand");
  return false;
}

bool OiInstTranslate::HandleCallTarget(const MCOperand &o, Value *&V, Value **First) {
  if (o.isImm()) {
    if (o.getImm() != 0U) {
      return IREmitter.HandleLocalCall(o.getImm(), V, First);
    } else { // Need to handle the relocation to find the correct jump address
      relocation_iterator ri = (*IREmitter.CurSection)->end_relocations();
      StringRef val;
      if (RelocReader.CheckRelocation(ri, val)) {
        if (val == "write") 
          return Syscalls.HandleSyscallWrite(V, First);        
        if (val == "atoi")
          return Syscalls.HandleLibcAtoi(V, First);
        if (val == "malloc")
          return Syscalls.HandleLibcMalloc(V, First);
        if (val == "calloc")
          return Syscalls.HandleLibcCalloc(V, First);
        if (val == "free")
          return Syscalls.HandleLibcFree(V, First);
        if (val == "exit")
          return Syscalls.HandleLibcExit(V, First);
        if (val == "puts")
          return Syscalls.HandleLibcPuts(V, First);
        if (val == "memset")
          return Syscalls.HandleLibcMemset(V, First);
        if (val == "fwrite")
          return Syscalls.HandleLibcFwrite(V, First);
        if (val == "printf")
          return Syscalls.HandleLibcPrintf(V, First);
        if (val == "fprintf")
          return Syscalls.HandleLibcFprintf(V, First);
        if (val == "__isoc99_scanf")
          return Syscalls.HandleLibcScanf(V);
      }
      uint64_t targetaddr;
      if (RelocReader.ResolveRelocation(targetaddr))
        return IREmitter.HandleLocalCall(targetaddr, V, First);
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
        tgtaddr = (IREmitter.CurAddr + o.getImm()) & 0xFFFFFFFFULL;
      else
        tgtaddr = o.getImm();
      uint64_t rel = 0;
      if (RelocReader.ResolveRelocation(rel)) {
        tgtaddr += rel;
      }
      assert (tgtaddr != IREmitter.CurAddr);
      if (tgtaddr < IREmitter.CurAddr)
        return IREmitter.HandleBackEdge(tgtaddr, Target);
      Target = IREmitter.CreateBB(tgtaddr);
      return true;
    } else { // Need to handle the relocation to find the correct jump address
      uint64_t targetaddr;
      if (RelocReader.ResolveRelocation(targetaddr)) {
        Target = IREmitter.CreateBB(targetaddr);
        return true;
      }
    }
  }
  llvm_unreachable("Unrecognized branch target");
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
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        Value *v4 = Builder.CreateStore(V2, IREmitter.Regs[33]);
        Value *v5 = Builder.CreateStore(V3, IREmitter.Regs[32]);
        WriteMap[33] = true;
        WriteMap[32] = true;
        assert(isa<Instruction>(o0) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(o0);
        o0se->dump();
      }
      break;
    }
  case Oi::MFHI:
    {
      DebugOut << "Handling MFHI\n";
      if (HandleAluDstOperand(MI->getOperand(0), o0)) {
        Value *v = Builder.CreateLoad(IREmitter.Regs[33]);
        ReadMap[33] = true;
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o0, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::MFLO:
    {
      DebugOut << "Handling MFLO\n";
      if (HandleAluDstOperand(MI->getOperand(0), o0)) {
        Value *v = Builder.CreateLoad(IREmitter.Regs[32]);
        ReadMap[33] = true;
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o0, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
          WriteMap[66] = true;
          Builder.CreateStore(select, IREmitter.Regs[66]);
          assert(isa<Instruction>(first) && "Need to rework map logic");
          IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
          ReadMap[66] = true;
          cmp = Builder.CreateSExtOrTrunc(Builder.CreateLoad(IREmitter.Regs[66]),
                                    Type::getInt1Ty(getGlobalContext()));
        } else {
          ReadMap[66] = true;
          cmp = Builder.CreateICmpEQ(Builder.CreateLoad(IREmitter.Regs[66]),
                             ConstantInt::get(Type::getInt32Ty
                                              (getGlobalContext()), 0U));
        }
        Value *v = Builder.CreateCondBr(cmp, True, 
                                        IREmitter.CreateBB(IREmitter.CurAddr+4));
        assert(isa<Instruction>(cmp) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(cmp);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(v);
        IREmitter.CreateBB(IREmitter.CurAddr+4);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::MOVN_I_I:
  case Oi::MOVZ_I_I:
    {
      DebugOut << "Handling MOVN, MOVZ\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {        
        Value *zero = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U);
        Value *cmp;
        if (MI->getOpcode() == Oi::MOVN_I_I) {
          cmp = Builder.CreateICmpNE(o2, zero);
        } else {
          cmp = Builder.CreateICmpEQ(o2, zero);
        }
        Value *loaddst = Builder.CreateLoad(o0);
        Value *select = Builder.CreateSelect(cmp, o1, loaddst, "movz_n");
        Builder.CreateStore(select, o0);
        Value *first = GetFirstInstruction(o1, o2, cmp, loaddst);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
        select->dump();
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
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::NOR:
    {
      DebugOut << "Handling NORi, NOR\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateOr(o1, o2);
        Value *v2 = Builder.CreateNot(v);
        Value *v3 = Builder.CreateStore(v2, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::ANDi:
  case Oi::AND:
    {
      DebugOut << "Handling ANDi, AND\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateAnd(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
        v2->dump();
      }
      break;
    }
  case Oi::XORi:
  case Oi::XOR:
    {
      DebugOut << "Handling XORi, XOR\n";
      Value *o0, *o1, *o2;
      if (HandleAluSrcOperand(MI->getOperand(1), o1) &&
          HandleAluSrcOperand(MI->getOperand(2), o2) &&
          HandleAluDstOperand(MI->getOperand(0), o0)) {      
        Value *v = Builder.CreateXor(o1, o2);
        Value *v2 = Builder.CreateStore(v, o0);
        Value *first = GetFirstInstruction(o1, o2, v, v2);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
        BasicBlock *FT = IREmitter.CreateBB(IREmitter.CurAddr+4);

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
        IREmitter.CurBlockAddr = IREmitter.CurAddr+4;

        assert(isa<Instruction>(cmp) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(cmp);
        cmp->dump();
      }      
      break;
    }
  case Oi::BEQ:
  case Oi::BNE:
  case Oi::BLTZ:
  case Oi::BGTZ:
    {
      DebugOut << "Handling BEQ, BNE, BLTZ\n";
      Value *o1, *o2;
      BasicBlock *True = 0;
      if (HandleAluSrcOperand(MI->getOperand(0), o1)) {
        Value *cmp;
        if (MI->getOpcode() == Oi::BEQ) {
          HandleAluSrcOperand(MI->getOperand(1), o2);
          HandleBranchTarget(MI->getOperand(2), True);
          cmp = Builder.CreateICmpEQ(o1, o2);
        } else if (MI->getOpcode() == Oi::BNE) {
          HandleAluSrcOperand(MI->getOperand(1), o2);
          HandleBranchTarget(MI->getOperand(2), True);
          cmp = Builder.CreateICmpNE(o1, o2);
        } else if (MI->getOpcode() == Oi::BLTZ) {
          o2 = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U);
          HandleBranchTarget(MI->getOperand(1), True);
          cmp = Builder.CreateICmpSLT(o1, o2);
        } else { /*  Oi::BGTZ  */
          o2 = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U);
          HandleBranchTarget(MI->getOperand(1), True);
          cmp = Builder.CreateICmpSGT(o1, o2);
        }
        Value *v = Builder.CreateCondBr(cmp, True, 
                                        IREmitter.CreateBB(IREmitter.CurAddr+4));
        Value *first = GetFirstInstruction(o1, o2, cmp, v);
        assert(isa<Instruction>(first) && "Need to rework map logic");
        IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
      v->dump();
    }
    break;
  }
  case Oi::LB:
  case Oi::LBu: {
    DebugOut << "Handling LB\n";
    Value *dst, *src, *first;
    if (HandleAluDstOperand(MI->getOperand(0),dst) &&
        HandleMemOperand(MI->getOperand(1), MI->getOperand(2), src, &first, true, 8)) {
      Value *ext;
      if (MI->getOpcode() == Oi::LB) 
        ext = Builder.CreateSExt(src, Type::getInt32Ty(getGlobalContext()));
      else
        ext = Builder.CreateZExt(src, Type::getInt32Ty(getGlobalContext()));
      Value *v = Builder.CreateStore(ext, dst);
      assert(isa<Instruction>(first) && "Need to rework map logic");
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
      first = GetFirstInstruction(src, first);
      assert(isa<Instruction>(first) && "Need to rework map logic");
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
      v->dump();
    }
    break;
  }
  case Oi::SB: {
    DebugOut << "Handling SB\n";
    Value *dst, *src, *first;
    if (HandleAluSrcOperand(MI->getOperand(0),src) &&
        HandleMemOperand(MI->getOperand(1), MI->getOperand(2), dst, &first, false, 8)) {
      Value *tr = Builder.CreateTrunc(src, Type::getInt8Ty(getGlobalContext()));
      Value *v = Builder.CreateStore(tr, dst);
      first = GetFirstInstruction(src, tr, first);
      assert(isa<Instruction>(first) && "Need to rework map logic");
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
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
    Value *call, *first;
    if(HandleCallTarget(MI->getOperand(0), call, &first)) {
      assert(isa<Instruction>(first) && "Need to rework map logic");
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
      call->dump();
    }
    break;
  }
  case Oi::JR64:
  case Oi::JR: {
    DebugOut << "Handling JR\n";
    Value *first = 0;
    if (!NoLocals && !OneRegion)
      IREmitter.HandleFunctionExitPoint(&first);
    if (MI->getOperand(0).getReg() == Oi::RA
        || MI->getOperand(0).getReg() == Oi::RA_64) {
      Value *v = Builder.CreateRetVoid();
      if (!first)
        first = v;
      assert(isa<Instruction>(first) && "Need to rework map logic");      
      IREmitter.InsMap[IREmitter.CurAddr] = dyn_cast<Instruction>(first);
      IREmitter.FunctionRetMap[IREmitter.CurAddr] = IREmitter.CurFunAddr;
      v->dump();
    } else {
      llvm_unreachable("Can't handle indirect jumps yet.");
    }
    break;
  }
  case Oi::NOP:
    DebugOut << "Handling NOP\n";
    break;
  default: 
    llvm_unreachable("Unimplemented instruction!");
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
