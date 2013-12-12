//=== SyscallsIface.h - ---------------------------------------- -*- C++ -*-==//
//
// Generate code to call host syscalls or libc functions during static
// binary translation.
//
//===----------------------------------------------------------------------===//
#ifndef SYSCALLSIFACE_H
#define SYSCALLSIFACE_H

#include "OiIREmitter.h"
#include "llvm/IR/Value.h"

namespace llvm {

class SyscallsIface {
 public:  
  SyscallsIface(OiIREmitter &ir) : IREmitter(ir), TheModule(ir.TheModule),
    Builder(ir.Builder), ReadMap(ir.ReadMap), WriteMap(ir.WriteMap) {
  }

  bool HandleSyscallWrite(Value *&V, Value **First = 0);
  bool HandleLibcAtoi(Value *&V, Value **First = 0);
  bool HandleLibcMalloc(Value *&V, Value **First = 0);
  bool HandleLibcCalloc(Value *&V, Value **First = 0);
  bool HandleLibcFree(Value *&V, Value **First = 0);
  bool HandleLibcExit(Value *&V, Value **First = 0);
  bool HandleLibcPuts(Value *&V, Value **First = 0);
  bool HandleLibcMemset(Value *&V, Value **First = 0);
  bool HandleLibcFwrite(Value *&V, Value **First = 0);
  bool HandleLibcFprintf(Value *&V, Value **First = 0);
  bool HandleLibcPrintf(Value *&V, Value **First = 0);
  bool HandleLibcScanf(Value *&V, Value **First = 0);
  bool HandleLibcAtan(Value *&V, Value **First = 0);
  bool HandleLibcCos(Value *&V, Value **First = 0);
  bool HandleLibcAcos(Value *&V, Value **First = 0);
  bool HandleLibcSqrt(Value *&V, Value **First = 0);
  bool HandleLibcPow(Value *&V, Value **First = 0);

 private:
  OiIREmitter &IREmitter;
  OwningPtr<Module> &TheModule;
  IRBuilder<> &Builder;
  DenseMap<int32_t, bool> &ReadMap, &WriteMap;
};

}

#endif
