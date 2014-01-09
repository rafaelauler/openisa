//=== OiIREmitter.h - ------------------------------------------ -*- C++ -*-==//
//
// This class helps building LLVM I.R. that represents a piece of statically
// translated OpenISA code.
//
//===----------------------------------------------------------------------===//
#ifndef OIIREMITTER_H
#define OIIREMITTER_H

#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/ADT/OwningPtr.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include <vector>

namespace llvm {

extern cl::opt<bool> NoLocals;
extern cl::opt<bool> OneRegion;

namespace object{
class ObjectFile;
}

using namespace object;

class OiIREmitter {
public:
  typedef DenseMap<uint32_t, std::vector<uint32_t> > FunctionCallMapTy;
  typedef DenseMap<uint32_t, uint32_t> FunctionRetMapTy;
  typedef SmallPtrSet<uint32_t, 64> IndirectCallMapTy;

  OiIREmitter(const ObjectFile *obj, uint64_t Stacksz): 
    Obj(obj), TheModule(new Module("outputtest", getGlobalContext())),
    Builder(getGlobalContext()), Regs(SmallVector<Value*,67>(67)),
    GlobalRegs(SmallVector<Value*,67>(67)),
    DblRegs(SmallVector<Value*,16>(16)),
    DblGlobalRegs(SmallVector<Value*,16>(16)),
    FirstFunction(true), CurAddr(0),
    CurSection(0), BBMap(), InsMap(), ReadMap(), WriteMap(), DblReadMap(),
    DblWriteMap(), FunctionCallMap(),
    FunctionRetMap(), IndirectCallMap(), CurFunAddr(0), CurBlockAddr(0),
    StackSize(Stacksz), IndirectDestinations(), IndirectDestinationsAddrs()
  {
    BuildShadowImage();
    BuildRegisterFile();
  }
  const ObjectFile *Obj;
  OwningPtr<Module> TheModule;
  IRBuilder<> Builder;
  OwningArrayPtr<uint8_t> ShadowImage;
  SmallVector<Value*, 67> Regs, GlobalRegs;
  SmallVector<Value*, 16> DblRegs, DblGlobalRegs;
  bool FirstFunction;
  uint64_t CurAddr;
  section_iterator* CurSection;
  StringMap<BasicBlock*> BBMap;
  DenseMap<int64_t, Instruction*> InsMap;
  DenseMap<int32_t, bool> ReadMap, WriteMap, DblReadMap, DblWriteMap;;
  FunctionCallMapTy FunctionCallMap; // Used only in one-region mode
  FunctionRetMapTy FunctionRetMap; // Used only in one-region mode
  IndirectCallMapTy IndirectCallMap;
  uint64_t CurFunAddr;
  uint64_t CurBlockAddr;
  uint64_t StackSize;
  uint64_t ShadowSize;
  Value* ShadowImageValue;
  Value* IndirectJumpTableValue;
  std::vector<BasicBlock*> IndirectDestinations;
  std::vector<uint32_t> IndirectDestinationsAddrs;
  

  bool ProcessIndirectJumps();
  void BuildShadowImage();
  void BuildRegisterFile();
  void BuildLocalRegisterFile();
  bool HandleBackEdge(uint64_t Addr, BasicBlock *&Target);
  bool HandleIndirectCallOneRegion(Value *src, Value **First = 0);
  bool HandleLocalCallOneRegion(uint64_t Addr, Value *&V, Value **First = 0);
  std::vector<uint32_t> GetCallSitesFor(uint32_t FuncAddr);
  bool BuildReturnTablesOneRegion();
  bool HandleLocalCall(uint64_t Addr, Value *&V, Value **First = 0);
  Value *AccessShadowMemory(Value *Idx, bool IsLoad, int width = 32, bool isFloat = false);
  Value *AccessJumpTable(Value *Idx, Value **First = 0);
  void InsertStartupCode(Function *F);
  BasicBlock* CreateBB(uint64_t Addr = 0, Function *F = 0);
  void UpdateInsertPoint();
  void CleanRegs();
  void StartFunction(Twine &N);
  void HandleFunctionEntryPoint(Value **First = 0);
  void HandleFunctionExitPoint(Value **First = 0);
  void FixBBTerminators();
  void UpdateCurAddr(uint64_t val) {
    CurAddr = val;
    UpdateInsertPoint();
  }
  void SetCurSection(section_iterator *i) {
    CurSection = i;
  }
private:
  bool FindTextOffset(uint64_t &SectionAddr);
};

}

#endif
