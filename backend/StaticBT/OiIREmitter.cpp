//=== OiIREmitter.cpp - ---------------------------------------- -*- C++ -*-==//
//
// This class helps building LLVM I.R. that represents a piece of statically
// translated OpenISA code.
//
//===----------------------------------------------------------------------===//

#include "OiInstrInfo.h"
#include "OiIREmitter.h"
#include "StringRefMemoryObject.h"
#include "SBTUtils.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/Object/ELF.h"
#include "llvm/Support/system_error.h"
using namespace llvm;

namespace llvm {

cl::opt<bool>
NoLocals("nolocals", cl::desc("Do not use locals, always use global variables"));

cl::opt<bool>
OneRegion("oneregion", cl::desc("Consider the whole program to be one big function"));

}

bool OiIREmitter::FindTextOffset(uint64_t &SectionAddr) {
  error_code ec;
  // Find through all sections relocations against the .text section
  for (section_iterator i = Obj->begin_sections(),
         e = Obj->end_sections();
       i != e; i.increment(ec)) {
    if (error(ec)) return false;
    StringRef Name;
    if (error(i->getName(Name))) return false;
    if (Name != ".text")
      continue;

    if (error(i->getAddress(SectionAddr))) return false;
    
    //Relocatable file
    if (SectionAddr == 0)
      SectionAddr = GetELFOffset(i);
    
    return true;
  }
  return false;
}

bool OiIREmitter::ProcessIndirectJumps() {
  uint64_t FinalAddr = 0xFFFFFFFFUL;
  error_code ec;
  std::vector<Constant*> IndirectJumpTable;
  uint64_t TextOffset;
  if (!FindTextOffset(TextOffset)) return false;

  // Find through all sections relocations against the .text section
  for (section_iterator i = Obj->begin_sections(),
         e = Obj->end_sections();
       i != e; i.increment(ec)) {
    if (error(ec)) break;
    uint64_t SectionAddr;
    if (error(i->getAddress(SectionAddr))) break;

    // Relocatable file
    if (SectionAddr == 0) {
      SectionAddr = GetELFOffset(i);
    }

    for (relocation_iterator ri = i->begin_relocations(),
           re = i->end_relocations();
         ri != re; ri.increment(ec)) {
      if (error(ec)) break;
      uint64_t Type;
      if (error(ri->getType(Type)))
        llvm_unreachable("Error getting relocation type");
      if (Type != ELF::R_MIPS_32)
        continue;
      SymbolRef symb;
      StringRef Name;
      if (error(ri->getSymbol(symb))) {
        continue;
      }
      if (error(symb.getName(Name))) {
        continue;
      }
      if (Name != ".text")
        continue;

      uint64_t offset;
      if (error(ri->getOffset(offset))) break;
      offset += SectionAddr;
      outs() << "REL at " << (offset) << " Found ";
      outs() << "Contents:" << (*(int*)(&ShadowImage[offset]));
      uint64_t TargetAddr = *(int*)(&ShadowImage[offset]);
      TargetAddr += TextOffset;
      outs() << " TargetAddr = " << TargetAddr << "\n";
      BasicBlock *BB = CreateBB(TargetAddr);
      IndirectJumpTable.push_back(BlockAddress::get(BB));
      IndirectDestinations.push_back(BB);
      int JumpTableIndex = IndirectJumpTable.size() - 1;
      //      IndirectJumpTable[JumpTableIndex]->dump();
      *(int*)(&ShadowImage[offset]) = JumpTableIndex;
    }
  }
  uint64_t TableSize = IndirectJumpTable.size();

  if (TableSize == 0) {
    IndirectJumpTableValue = 0;
    return true;
  }    

  ConstantArray *c = 
    dyn_cast<ConstantArray>(ConstantArray::get(ArrayType::get(Type::getInt8PtrTy(getGlobalContext()), TableSize),
                                               ArrayRef<Constant *>(&IndirectJumpTable[0], TableSize)));

  GlobalVariable *gv = new GlobalVariable(*TheModule, c->getType(), false, 
                                          GlobalValue::ExternalLinkage,
                                          c, "IndirectJumpTable");  

  IndirectJumpTableValue = gv; 

  return true;
}

void OiIREmitter::BuildShadowImage() {
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
    StringRef SecName;
    if (error(i->getName(SecName))) break;    

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

void OiIREmitter::BuildRegisterFile() {
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
    GlobalRegs[I] = gv;
  }
}

void OiIREmitter::BuildLocalRegisterFile() {
  Type *ty = Type::getInt32Ty(getGlobalContext());
  // 32 base regs  0-31
  // LO 32
  // HI 33
  // 32 fp regs 34-65
  // FPCondCode 66
  if (NoLocals) {
    for (int I = 0; I < 67; ++I) {
      Regs[I] = GlobalRegs[I];
    }    
  } else {
    for (int I = 0; I < 67; ++I) {
      AllocaInst *inst = Builder.CreateAlloca(ty, 0, "lreg");
      Regs[I] = inst;
      Builder.CreateStore(Builder.CreateLoad(GlobalRegs[I]), inst);
      WriteMap[I] = false;
      ReadMap[I] = false;
    }
  }
}

void OiIREmitter::StartFunction(Twine &N) {
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
    BuildLocalRegisterFile();
    InsertStartupCode();
    CurFunAddr = CurAddr+4;
    if (!ProcessIndirectJumps())
      llvm_unreachable("ProcessIndirectJumps failed.");

  } else {
    CurFunAddr = CurAddr+4;
    if (!OneRegion) {
      F = reinterpret_cast<Function *>(TheModule->getOrInsertFunction(N.str(),
                                                                      FT));
      CreateBB(0, F);
      UpdateInsertPoint();
      BuildLocalRegisterFile();
    } else {
      CreateBB(CurAddr+4);
    }
  }
}

void OiIREmitter::InsertStartupCode() {
  // Initialize the stack
  Value *size = ConstantInt::get(Type::getInt32Ty(getGlobalContext()),
                                  ShadowSize);
  Builder.CreateStore(size, Regs[ConvToDirective(Oi::SP)]);
}

BasicBlock* OiIREmitter::CreateBB(uint64_t Addr, Function *F) {
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

void OiIREmitter::UpdateInsertPoint() {
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

void OiIREmitter::HandleFunctionEntryPoint(Value **First) {
  bool WroteFirst = false;
  if (NoLocals)
    return;
  for (int I = 0; I < 67; ++I) {
    Value *st = Builder.CreateStore(Builder.CreateLoad(GlobalRegs[I]), Regs[I]);
    if (!WroteFirst) {
      WroteFirst = true;
      if (First)
        *First = st; 
    }
  }
}

void OiIREmitter::HandleFunctionExitPoint(Value **First) {
  bool WroteFirst = false;
  if (NoLocals)
    return;
  for (int I = 0; I < 67; ++I) {
    Value *st = Builder.CreateStore(Builder.CreateLoad(Regs[I]), GlobalRegs[I]);
    if (!WroteFirst) {
      WroteFirst = true;
      if (First)
        *First = st; 
    }    
  }
}

void OiIREmitter::FixBBTerminators() {
  Function *F = Builder.GetInsertBlock()->getParent();

  for (Function::iterator I = F->begin(), E = F->end(); I != E; ++I) {
    if (!I->getTerminator()) {
      Builder.SetInsertPoint(&*I);
      Instruction *Inst = &I->back();
      if (isa<CallInst>(Inst)) {
        CallInst *CInst = dyn_cast<CallInst>(Inst);
        if (CInst->getCalledFunction()->getName() == "exit")
          Builder.CreateRetVoid();
      }
    }
  }
}

// Note: CleanRegs() leaves a few remaining "Load GlobalRegXX" after the
// cleanup, but a simple SSA dead code elimination should handle them.
void OiIREmitter::CleanRegs() {
  for (int I = 0; I < 67; ++I) {
    if (!(WriteMap[I] || ReadMap[I])) {
      Instruction *inst = dyn_cast<Instruction>(Regs[I]);
      if (inst) {
        while (!inst->use_empty()) {
          Instruction* UI = inst->use_back();
          // These are assigning a value to the local copy of the reg, bu since
          // we don't use it, we can delete the assignment.
          if (isa<StoreInst>(UI)) {
            UI->eraseFromParent();
            continue;
          }
          assert (isa<LoadInst>(UI));
          // Here we should have a false usage of the value. It is loading only
          // in checkpoints (exit points) to save it back to the global copy.
          // Since we do not really use it, we should delete the load and the
          // store insruction that is using it.
          assert (UI->hasOneUse());
          Instruction* StUI = dyn_cast<Instruction>(UI->use_back());
          assert (isa<StoreInst>(StUI));
          StUI->eraseFromParent();
          UI->eraseFromParent();
        }
        inst->eraseFromParent();
      }
    }
  }
}

bool OiIREmitter::BuildReturnTablesOneRegion() {
  for (DenseMap<int32_t, int32_t>::iterator I = FunctionRetMap.begin(), 
         E = FunctionRetMap.end(); I != E; ++I) {
    uint32_t retaddr = I->first;
    uint32_t funcaddr = I->second;

    Instruction* tgtins = InsMap[retaddr];
    assert(tgtins && "Invalid return address");
    
    Builder.SetInsertPoint(tgtins->getParent(), tgtins);
    
    SmallVector<uint32_t, 4> CallSites = GetCallSitesFor(funcaddr);
    if (CallSites.empty())
      continue;

    Value *ra = Builder.CreateLoad(Regs[ConvToDirective(Oi::RA)], "RetTableInput");
    ReadMap[ConvToDirective(Oi::RA)] = true;
    Instruction *dummy = Builder.CreateUnreachable();
    Builder.SetInsertPoint(tgtins->getParent(), dummy);

    // Delete the original ret instruction
    tgtins->eraseFromParent();

    for (SmallVector<uint32_t, 4>::iterator J = CallSites.begin(), EJ = CallSites.end();
         J != EJ; ++J) {
      Value *site = ConstantInt::get(Type::getInt32Ty(getGlobalContext()), *J);
      Value *cmp = Builder.CreateICmpEQ(site, ra);

      Twine T2("bb");
      T2 = T2.concat(Twine::utohexstr(*J));
      std::string Idx = T2.str();
      //  printf("\n%08X\n\n%s\n", *J,  Idx.c_str());
      assert (BBMap[Idx] != 0 && "Invalid return target address");
      Value *TrueV = BBMap[Idx];
      assert(isa<BasicBlock>(TrueV) && "Values stored into BBMap must be BasicBlocks");
      BasicBlock *True = dyn_cast<BasicBlock>(TrueV);
      Function *F = True->getParent();
      BasicBlock *FallThrough = BasicBlock::Create(getGlobalContext(), "", F);      

      Builder.CreateCondBr(cmp, True, FallThrough);
      Builder.SetInsertPoint(FallThrough);
    }
    Builder.CreateUnreachable();
    dummy->eraseFromParent();
  }
}

SmallVector<uint32_t, 4> OiIREmitter::GetCallSitesFor(uint32_t FuncAddr) {
  SmallVector<uint32_t, 4> Res;
  for (DenseMap<int32_t, int32_t>::iterator I = FunctionCallMap.begin(),
         E = FunctionCallMap.end(); I != E; ++I) {
    uint32_t retaddr = I->first + 4;
    uint32_t funcaddr = I->second;

    if (funcaddr != FuncAddr)
      continue;

    Res.push_back(retaddr);
  }
  return Res;
}

bool OiIREmitter::HandleBackEdge(uint64_t Addr, BasicBlock *&Target) {
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

bool OiIREmitter::HandleLocalCallOneRegion(uint64_t Addr, Value *&V,
                                               Value **First) {
  BasicBlock *Target;
  FunctionCallMap[CurAddr] = Addr;
  if (Addr < CurAddr)
    HandleBackEdge(Addr, Target);
  else
    Target = CreateBB(Addr);
  Value *first = Builder.CreateStore
    (ConstantInt::get(Type::getInt32Ty(getGlobalContext()), CurAddr+4),
                               Regs[ConvToDirective(Oi::RA)]);
  V = Builder.CreateBr(Target);
  //  printf("\nHandleLocalCallOneregion.CurAddr: %08LX\n", CurAddr+4);
  CreateBB(CurAddr+4);
  if (First)
    *First = first;
  return true;
}

bool OiIREmitter::HandleLocalCall(uint64_t Addr, Value *&V, Value **First) {
  if (OneRegion)
    return HandleLocalCallOneRegion(Addr, V, First);
  Twine T("a");
  T = T.concat(Twine::utohexstr(Addr));
  StringRef Name(T.str());
  HandleFunctionExitPoint(First);
  FunctionType *ft = FunctionType::get(Type::getVoidTy(getGlobalContext()),
                                       /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction(Name, ft);
  V = Builder.CreateCall(fun);
  if (First && NoLocals)
    *First = V;
  HandleFunctionEntryPoint();
  return true;
}

Value *OiIREmitter::AccessShadowMemory(Value *Idx, bool IsLoad, int width) {
  SmallVector<Value*,4> Idxs;
  Idxs.push_back(ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U));
  Idxs.push_back(Idx);
  Value *gep = Builder.CreateGEP(ShadowImageValue, Idxs);
  Type *targetType = 0;
  switch (width) {
  case 8:
    targetType = Type::getInt8PtrTy(getGlobalContext());
    break;
  case 16:
    targetType = Type::getInt16PtrTy(getGlobalContext());
    break;
  case 32:
    targetType = Type::getInt32PtrTy(getGlobalContext());
    break;
  default:
    llvm_unreachable("Invalid memory access width");
  }
  Value *ptr = Builder.CreateBitCast(gep, targetType);
  if (IsLoad)
    return Builder.CreateLoad(ptr);
  return ptr;
}

Value *OiIREmitter::AccessJumpTable(Value *Idx, Value **First) {
  SmallVector<Value*,4> Idxs;
  Idxs.push_back(ConstantInt::get(Type::getInt32Ty(getGlobalContext()), 0U));
  Idxs.push_back(Idx);
  Value *gep = Builder.CreateGEP(IndirectJumpTableValue, Idxs);
  Type *targetType = 
    Type::getInt8PtrTy(getGlobalContext());
  Value *ptr = Builder.CreateBitCast(gep, targetType);
  if (First)
    *First = gep;
  return ptr;
}

