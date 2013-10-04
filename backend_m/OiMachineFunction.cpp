//===-- OiMachineFunctionInfo.cpp - Private data used for Oi ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "OiMachineFunction.h"
#include "MCTargetDesc/OiBaseInfo.h"
#include "OiInstrInfo.h"
#include "OiSubtarget.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

static cl::opt<bool>
FixGlobalBaseReg("oi-fix-global-base-reg", cl::Hidden, cl::init(true),
                 cl::desc("Always use $gp as the global base register."));

bool OiFunctionInfo::globalBaseRegSet() const {
  return GlobalBaseReg;
}

unsigned OiFunctionInfo::getGlobalBaseReg() {
  // Return if it has already been initialized.
  if (GlobalBaseReg)
    return GlobalBaseReg;

  const OiSubtarget &ST = MF.getTarget().getSubtarget<OiSubtarget>();

  const TargetRegisterClass *RC;
  if (ST.inOi16Mode())
    RC=(const TargetRegisterClass*)&Oi::CPU16RegsRegClass;
  else
    RC = ST.isABI_N64() ?
      (const TargetRegisterClass*)&Oi::CPU64RegsRegClass :
      (const TargetRegisterClass*)&Oi::CPURegsRegClass;
  return GlobalBaseReg = MF.getRegInfo().createVirtualRegister(RC);
}

bool OiFunctionInfo::oi16SPAliasRegSet() const {
  return Oi16SPAliasReg;
}
unsigned OiFunctionInfo::getOi16SPAliasReg() {
  // Return if it has already been initialized.
  if (Oi16SPAliasReg)
    return Oi16SPAliasReg;

  const TargetRegisterClass *RC;
  RC=(const TargetRegisterClass*)&Oi::CPU16RegsRegClass;
  return Oi16SPAliasReg = MF.getRegInfo().createVirtualRegister(RC);
}

void OiFunctionInfo::anchor() { }
