//=== OiInstTranslate.h - Convert Oi MCInst to LLVM IR -*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class translates a Oi MCInst to LLVM IR using static binary translation
// techniques.
//
//===----------------------------------------------------------------------===//

#ifndef OIINSTTRANSLATE_H
#define OIINSTTRANSLATE_H
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/Object/ObjectFile.h"
#include "InstPrinter/OiInstPrinter.h"
#include "llvm/ADT/OwningPtr.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"

namespace llvm {

namespace object{
class ObjectFile;
}

using namespace object;

class OiInstTranslate : public MCInstPrinter {
public:
  OiInstTranslate(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                  const MCRegisterInfo &MRI, const ObjectFile *obj)
    : MCInstPrinter(MAI, MII, MRI),
      TheModule(new Module("outputtest", getGlobalContext())),
      Builder(getGlobalContext()), Obj(obj), Regs(SmallVector<Value*,32>(32)),
      FirstFunction(true), CurAddr(0), CurSection(0) 
  {
    BuildShadowImage();
    BuildRegisterFile();
  }

  // Autogenerated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  virtual void printRegName(raw_ostream &OS, unsigned RegNo) const;
  virtual void printInst(const MCInst *MI, raw_ostream &O, StringRef Annot);
  void printCPURegs(const MCInst *MI, unsigned OpNo, raw_ostream &O);

  bool printAliasInstr(const MCInst *MI, raw_ostream &OS);
  Module* takeModule();
  void StartFunction(Twine &N);
  void FinishFunction();
  void UpdateCurAddr(uint64_t val) {
    CurAddr = val;
  }
  void SetCurSection(section_iterator *i) {
    CurSection = i;
  }

private:
  OwningPtr<Module> TheModule;
  IRBuilder<> Builder;
  const ObjectFile *Obj;
  OwningArrayPtr<uint8_t> ShadowImage;
  uint64_t ShadowSize;
  SmallVector<Value*, 32> Regs;
  Value* ShadowImageValue;
  bool FirstFunction;
  uint64_t CurAddr;
  section_iterator* CurSection;

  bool HandleAluSrcOperand(const MCOperand &o, Value *&V);
  bool HandleAluDstOperand(const MCOperand &o, Value *&V);
  bool HandleMemExpr(const MCExpr &exp, Value *&V, bool IsLoad);
  bool HandleMemOperand(const MCOperand &o, const MCOperand &o2, Value *&V,
                        bool IsLoad);
  bool HandleLUiOperand(const MCOperand &o, Value *&V, bool IsLoad);
  bool HandleCallTarget(const MCOperand &o, Value *&V);
  bool HandleSyscallWrite(Value *&V);
  bool HandleLocalCall(StringRef Name, Value *&V);
  Value *AccessShadowMemory32(Value *Idx, bool IsLoad);
  bool CheckRelocation(relocation_iterator &Rel, StringRef &Name);
  bool ResolveRelocation(uint64_t &Res, uint64_t *Type = 0);
  void InsertStartupCode();

  void printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  void printUnsignedImm(const MCInst *MI, int opNum, raw_ostream &O);
  void printMemOperand(const MCInst *MI, int opNum, raw_ostream &O);
  void printMemOperandEA(const MCInst *MI, int opNum, raw_ostream &O);
  void printFCCOperand(const MCInst *MI, int opNum, raw_ostream &O);
  void BuildShadowImage();
  void BuildRegisterFile();
};
} // end namespace llvm

#endif
