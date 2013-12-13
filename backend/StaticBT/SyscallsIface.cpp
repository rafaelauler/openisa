//=== SyscallsIface.cpp - -------------------------------------- -*- C++ -*-==//
//
// Generate code to call host syscalls or libc functions during static
// binary translation.
//
//===----------------------------------------------------------------------===//
#include "SyscallsIface.h"
#include "OiInstrInfo.h"
#include "SBTUtils.h"

using namespace llvm;

bool SyscallsIface::HandleLibcAtoi(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("atoi", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  Value *addrbuf = IREmitter.AccessShadowMemory(f, false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), IREmitter.Regs[ConvToDirective
                                                                (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

bool SyscallsIface::HandleLibcMalloc(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("malloc", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  params.push_back(f);
  Value *mal = Builder.CreateCall(fun, params);
  Value *ptr = Builder.CreatePtrToInt(IREmitter.ShadowImageValue,
                                      Type::getInt32Ty(getGlobalContext()));
  Value *fixed = Builder.CreateSub(mal, ptr);
  V = Builder.CreateStore(fixed, IREmitter.Regs[ConvToDirective
                                      (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

bool SyscallsIface::HandleLibcCalloc(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(2, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("calloc", ft);
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  SmallVector<Value*, 8> params;
  params.push_back(f);
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A1)]));
  Value *mal = Builder.CreateCall(fun, params);
  Value *ptr = Builder.CreatePtrToInt(IREmitter.ShadowImageValue,
                                      Type::getInt32Ty(getGlobalContext()));
  Value *fixed = Builder.CreateSub(mal, ptr);
  V = Builder.CreateStore(fixed, IREmitter.Regs[ConvToDirective
                                      (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  ReadMap[ConvToDirective(Oi::A1)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

bool SyscallsIface::HandleLibcFree(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getVoidTy(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("free", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  Value *addrbuf = IREmitter.AccessShadowMemory
    (f, false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  V = Builder.CreateCall(fun, params);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  return true;
}

bool SyscallsIface::HandleLibcExit(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getVoidTy(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("exit", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  params.push_back(f);
  V = Builder.CreateCall(fun, params);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  return true;
}

bool SyscallsIface::HandleGenericInt(Value *&V, StringRef Name, int numargs,
                                     int numret, bool *PtrTypes, Value **First) {
  SmallVector<Type*, 8> args(numargs, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft;
  if (numret == 0)
    ft= FunctionType::get(Type::getVoidTy(getGlobalContext()),
                          args, /*isvararg*/false);
  else if (numret == 1)
    ft= FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                          args, /*isvararg*/false);
  else
    llvm_unreachable("Unhandled return size.");
  Value *fun = TheModule->getOrInsertFunction(Name, ft);
  SmallVector<Value*, 8> params;
  assert(numargs <= 4 && "Cannot handle more than 4 arguments");
  if (numargs > 0) {
    for (int I = 0, E = numargs; I != E; ++I) {
      Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)+I]);
      if (I == 0 && First)
        *First = f;
      if (PtrTypes[I]) {
        Value *addrbuf = IREmitter.AccessShadowMemory(f, false);
        params.push_back(Builder.CreatePtrToInt
                         (addrbuf, Type::getInt32Ty(getGlobalContext())));
      } else {
        params.push_back(f);
      }
      ReadMap[ConvToDirective(Oi::A0)+I] = true;
    }
    V = Builder.CreateCall(fun, params);
  } else {
    V = Builder.CreateCall(fun, params);
    if (First)
      *First = V;
  }
  if (numret > 0) {
    if (PtrTypes[numargs]) {
      Value *ptr = Builder.CreatePtrToInt(IREmitter.ShadowImageValue,
                                          Type::getInt32Ty(getGlobalContext()));
      Value *fixed = Builder.CreateSub(V, ptr);
      V = Builder.CreateStore(fixed, IREmitter.Regs[ConvToDirective
                                                    (Oi::V0)]);
    } else {
      Builder.CreateStore(V, IREmitter.Regs[ConvToDirective(Oi::V0)]);
    }
    WriteMap[ConvToDirective(Oi::V0)] = true;
  }

  return true;
}

bool SyscallsIface::HandleLibcPuts(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("puts", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  Value *addrbuf = IREmitter.AccessShadowMemory
    (f, false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), IREmitter.Regs[ConvToDirective
                                                                (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

bool SyscallsIface::HandleLibcMemset(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(3, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("memset", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  Value *addrbuf = IREmitter.AccessShadowMemory
    (f, false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A1)]));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A2)]));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), IREmitter.Regs[ConvToDirective
                                                                (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  ReadMap[ConvToDirective(Oi::A1)] = true;
  ReadMap[ConvToDirective(Oi::A2)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

// XXX: Handling a fixed number of 4 arguments, since we cannot infer how many
// arguments the program is using with fprintf
bool SyscallsIface::HandleLibcFprintf(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(2, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("fprintf", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  params.push_back(f);
  Value *addrbuf = IREmitter.AccessShadowMemory
    (Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A1)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A2)]));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A3)]));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), IREmitter.Regs[ConvToDirective
                                                                (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  ReadMap[ConvToDirective(Oi::A1)] = true;
  ReadMap[ConvToDirective(Oi::A2)] = true;
  ReadMap[ConvToDirective(Oi::A3)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

// XXX: Handling a fixed number of 4 arguments, since we cannot infer how many
// arguments the program is using with printf
bool SyscallsIface::HandleLibcPrintf(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("printf", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  Value *addrbuf = IREmitter.AccessShadowMemory(f, false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A1)]));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A2)]));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A3)]));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), IREmitter.Regs[ConvToDirective
                                                                (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  ReadMap[ConvToDirective(Oi::A1)] = true;
  ReadMap[ConvToDirective(Oi::A2)] = true;
  ReadMap[ConvToDirective(Oi::A3)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

// XXX: Handling a fixed number of 4 arguments, since we cannot infer how many
// arguments the program is using with scanf
bool SyscallsIface::HandleLibcScanf(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("__isoc99_scanf", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  Value *addrbuf0 = IREmitter.AccessShadowMemory(f, false);
  Value *addrbuf1 = IREmitter.AccessShadowMemory
    (Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A1)]), false);
  Value *addrbuf2 = IREmitter.AccessShadowMemory
    (Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A2)]), false);
  Value *addrbuf3 = IREmitter.AccessShadowMemory
    (Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A3)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf0,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreatePtrToInt(addrbuf1,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreatePtrToInt(addrbuf2,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreatePtrToInt(addrbuf3,
                                          Type::getInt32Ty(getGlobalContext())));
  V = Builder.CreateStore(Builder.CreateCall(fun, params), IREmitter.Regs[ConvToDirective
                                                                (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  ReadMap[ConvToDirective(Oi::A1)] = true;
  ReadMap[ConvToDirective(Oi::A2)] = true;
  ReadMap[ConvToDirective(Oi::A3)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}

bool SyscallsIface::HandleLibcAtan(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getDoubleTy(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("atan", ft);
  SmallVector<Value*, 8> params;
  Value *v1 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)]);
  Value *v2 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)+1]);
  Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
  Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
  Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                (Type::getInt64Ty(getGlobalContext()), 32));
  Value *v6 = Builder.CreateOr(v5,v4);
  Value *v7 = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));

  params.push_back(v7);
  Value *call = Builder.CreateCall(fun, params);
  if (First)
    *First = GetFirstInstruction(v1, call);
  V = call;
  Value *v8 = Builder.CreateBitCast(call, Type::getInt64Ty(getGlobalContext()));
  Value *v9 = Builder.CreateLShr(v8, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Value *hi = Builder.CreateSExtOrTrunc(v9, Type::getInt32Ty(getGlobalContext()));
  Value *lo = Builder.CreateSExtOrTrunc(v8, Type::getInt32Ty(getGlobalContext()));
  Builder.CreateStore(lo, IREmitter.Regs[ConvToDirective(Oi::F0)]);
  Builder.CreateStore(hi, IREmitter.Regs[ConvToDirective(Oi::F0)+1]);

  ReadMap[ConvToDirective(Oi::F12)] = true;
  ReadMap[ConvToDirective(Oi::F12)+1] = true;
  WriteMap[ConvToDirective(Oi::F0)] = true;
  WriteMap[ConvToDirective(Oi::F0)+1] = true;
  return true;
}

bool SyscallsIface::HandleLibcCos(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getDoubleTy(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("cos", ft);
  SmallVector<Value*, 8> params;
  Value *v1 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)]);
  Value *v2 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)+1]);
  if (First)
    *First = v1;
  Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
  Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
  Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                (Type::getInt64Ty(getGlobalContext()), 32));
  Value *v6 = Builder.CreateOr(v5,v4);
  Value *v7 = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));

  params.push_back(v7);
  Value *call = Builder.CreateCall(fun, params);
  V = call;
  Value *v8 = Builder.CreateBitCast(call, Type::getInt64Ty(getGlobalContext()));
  Value *v9 = Builder.CreateLShr(v8, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Value *hi = Builder.CreateSExtOrTrunc(v9, Type::getInt32Ty(getGlobalContext()));
  Value *lo = Builder.CreateSExtOrTrunc(v8, Type::getInt32Ty(getGlobalContext()));
  Builder.CreateStore(lo, IREmitter.Regs[ConvToDirective(Oi::F0)]);
  Builder.CreateStore(hi, IREmitter.Regs[ConvToDirective(Oi::F0)+1]);

  ReadMap[ConvToDirective(Oi::F12)] = true;
  ReadMap[ConvToDirective(Oi::F12)+1] = true;
  WriteMap[ConvToDirective(Oi::F0)] = true;
  WriteMap[ConvToDirective(Oi::F0)+1] = true;
  return true;
}

bool SyscallsIface::HandleLibcAcos(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getDoubleTy(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("acos", ft);
  SmallVector<Value*, 8> params;
  Value *v1 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)]);
  Value *v2 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)+1]);
  if (First)
    *First = v1;
  Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
  Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
  Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                (Type::getInt64Ty(getGlobalContext()), 32));
  Value *v6 = Builder.CreateOr(v5,v4);
  Value *v7 = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));

  params.push_back(v7);
  Value *call = Builder.CreateCall(fun, params);
  V = call;
  Value *v8 = Builder.CreateBitCast(call, Type::getInt64Ty(getGlobalContext()));
  Value *v9 = Builder.CreateLShr(v8, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Value *hi = Builder.CreateSExtOrTrunc(v9, Type::getInt32Ty(getGlobalContext()));
  Value *lo = Builder.CreateSExtOrTrunc(v8, Type::getInt32Ty(getGlobalContext()));
  Builder.CreateStore(lo, IREmitter.Regs[ConvToDirective(Oi::F0)]);
  Builder.CreateStore(hi, IREmitter.Regs[ConvToDirective(Oi::F0)+1]);

  ReadMap[ConvToDirective(Oi::F12)] = true;
  ReadMap[ConvToDirective(Oi::F12)+1] = true;
  WriteMap[ConvToDirective(Oi::F0)] = true;
  WriteMap[ConvToDirective(Oi::F0)+1] = true;
  return true;
}

bool SyscallsIface::HandleLibcSqrt(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getDoubleTy(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("sqrt", ft);
  SmallVector<Value*, 8> params;
  Value *v1 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)]);
  Value *v2 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)+1]);
  if (First)
    *First = v1;
  Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
  Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
  Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                (Type::getInt64Ty(getGlobalContext()), 32));
  Value *v6 = Builder.CreateOr(v5,v4);
  Value *v7 = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));

  params.push_back(v7);
  Value *call = Builder.CreateCall(fun, params);
  V = call;
  Value *v8 = Builder.CreateBitCast(call, Type::getInt64Ty(getGlobalContext()));
  Value *v9 = Builder.CreateLShr(v8, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Value *hi = Builder.CreateSExtOrTrunc(v9, Type::getInt32Ty(getGlobalContext()));
  Value *lo = Builder.CreateSExtOrTrunc(v8, Type::getInt32Ty(getGlobalContext()));
  Builder.CreateStore(lo, IREmitter.Regs[ConvToDirective(Oi::F0)]);
  Builder.CreateStore(hi, IREmitter.Regs[ConvToDirective(Oi::F0)+1]);

  ReadMap[ConvToDirective(Oi::F12)] = true;
  ReadMap[ConvToDirective(Oi::F12)+1] = true;
  WriteMap[ConvToDirective(Oi::F0)] = true;
  WriteMap[ConvToDirective(Oi::F0)+1] = true;
  return true;
}

bool SyscallsIface::HandleLibcExp(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getDoubleTy(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("exp", ft);
  SmallVector<Value*, 8> params;
  Value *v1 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)]);
  Value *v2 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)+1]);
  if (First)
    *First = v1;
  Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
  Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
  Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                (Type::getInt64Ty(getGlobalContext()), 32));
  Value *v6 = Builder.CreateOr(v5,v4);
  Value *v7 = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));

  params.push_back(v7);
  Value *call = Builder.CreateCall(fun, params);
  V = call;
  Value *v8 = Builder.CreateBitCast(call, Type::getInt64Ty(getGlobalContext()));
  Value *v9 = Builder.CreateLShr(v8, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Value *hi = Builder.CreateSExtOrTrunc(v9, Type::getInt32Ty(getGlobalContext()));
  Value *lo = Builder.CreateSExtOrTrunc(v8, Type::getInt32Ty(getGlobalContext()));
  Builder.CreateStore(lo, IREmitter.Regs[ConvToDirective(Oi::F0)]);
  Builder.CreateStore(hi, IREmitter.Regs[ConvToDirective(Oi::F0)+1]);

  ReadMap[ConvToDirective(Oi::F12)] = true;
  ReadMap[ConvToDirective(Oi::F12)+1] = true;
  WriteMap[ConvToDirective(Oi::F0)] = true;
  WriteMap[ConvToDirective(Oi::F0)+1] = true;
  return true;
}

bool SyscallsIface::HandleLibcAtof(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(1, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("atof", ft);
  SmallVector<Value*, 8> params;

  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  Value *addrbuf = IREmitter.AccessShadowMemory(f, false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));

  Value *call = Builder.CreateCall(fun, params);
  V = call;
  Value *v8 = Builder.CreateBitCast(call, Type::getInt64Ty(getGlobalContext()));
  Value *v9 = Builder.CreateLShr(v8, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Value *hi = Builder.CreateSExtOrTrunc(v9, Type::getInt32Ty(getGlobalContext()));
  Value *lo = Builder.CreateSExtOrTrunc(v8, Type::getInt32Ty(getGlobalContext()));
  Builder.CreateStore(lo, IREmitter.Regs[ConvToDirective(Oi::F0)]);
  Builder.CreateStore(hi, IREmitter.Regs[ConvToDirective(Oi::F0)+1]);

  ReadMap[ConvToDirective(Oi::A0)] = true;
  WriteMap[ConvToDirective(Oi::F0)] = true;
  WriteMap[ConvToDirective(Oi::F0)+1] = true;
  return true;
}


bool SyscallsIface::HandleLibcPow(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(2, Type::getDoubleTy(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       args, /*isvararg*/true);
  Value *fun = TheModule->getOrInsertFunction("pow", ft);
  SmallVector<Value*, 8> params;
  Value *v1 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)]);
  Value *v2 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F12)+1]);
  if (First)
    *First = v1;
  Value *v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
  Value *v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
  Value *v5 = Builder.CreateShl(v3, ConstantInt::get
                                (Type::getInt64Ty(getGlobalContext()), 32));
  Value *v6 = Builder.CreateOr(v5,v4);
  Value *v7 = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));

  params.push_back(v7);
  v1 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F14)]);
  v2 = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::F14)+1]);
  v3 = Builder.CreateZExtOrTrunc(v2, Type::getInt64Ty(getGlobalContext()));
  v4 = Builder.CreateZExtOrTrunc(v1, Type::getInt64Ty(getGlobalContext()));
  v5 = Builder.CreateShl(v3, ConstantInt::get
                                (Type::getInt64Ty(getGlobalContext()), 32));
  v6 = Builder.CreateOr(v5,v4);
  v7 = Builder.CreateBitCast(v6, Type::getDoubleTy(getGlobalContext()));

  params.push_back(v7);

  Value *call = Builder.CreateCall(fun, params);
  V = call;
  Value *v8 = Builder.CreateBitCast(call, Type::getInt64Ty(getGlobalContext()));
  Value *v9 = Builder.CreateLShr(v8, ConstantInt::get
                                 (Type::getInt64Ty(getGlobalContext()), 32));
  // Assume little endian for doubles
  Value *hi = Builder.CreateSExtOrTrunc(v9, Type::getInt32Ty(getGlobalContext()));
  Value *lo = Builder.CreateSExtOrTrunc(v8, Type::getInt32Ty(getGlobalContext()));
  Builder.CreateStore(lo, IREmitter.Regs[ConvToDirective(Oi::F0)]);
  Builder.CreateStore(hi, IREmitter.Regs[ConvToDirective(Oi::F0)+1]);

  ReadMap[ConvToDirective(Oi::F12)] = true;
  ReadMap[ConvToDirective(Oi::F12)+1] = true;
  ReadMap[ConvToDirective(Oi::F14)] = true;
  ReadMap[ConvToDirective(Oi::F14)+1] = true;
  WriteMap[ConvToDirective(Oi::F0)] = true;
  WriteMap[ConvToDirective(Oi::F0)+1] = true;
  return true;
}

bool SyscallsIface::HandleSyscallWrite(Value *&V, Value **First) {
  SmallVector<Type*, 8> args(3, Type::getInt32Ty(getGlobalContext()));
  FunctionType *ft = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
                                       args, /*isvararg*/false);
  Value *fun = TheModule->getOrInsertFunction("write", ft);
  SmallVector<Value*, 8> params;
  Value *f = Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A0)]);
  if (First)
    *First = f;
  params.push_back(f);
  Value *addrbuf = IREmitter.AccessShadowMemory
    (Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A1)]), false);
  params.push_back(Builder.CreatePtrToInt(addrbuf,
                                          Type::getInt32Ty(getGlobalContext())));
  params.push_back(Builder.CreateLoad(IREmitter.Regs[ConvToDirective(Oi::A2)]));

  V = Builder.CreateStore(Builder.CreateCall(fun, params), IREmitter.Regs[ConvToDirective
                                                                (Oi::V0)]);
  ReadMap[ConvToDirective(Oi::A0)] = true;
  ReadMap[ConvToDirective(Oi::A1)] = true;
  ReadMap[ConvToDirective(Oi::A2)] = true;
  WriteMap[ConvToDirective(Oi::V0)] = true;
  return true;
}
