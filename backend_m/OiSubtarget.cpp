//===-- OiSubtarget.cpp - Oi Subtarget Information --------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Oi specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "OiSubtarget.h"
#include "Oi.h"
#include "OiRegisterInfo.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "OiGenSubtargetInfo.inc"

using namespace llvm;

void OiSubtarget::anchor() { }

OiSubtarget::OiSubtarget(const std::string &TT, const std::string &CPU,
                             const std::string &FS, bool little,
                             Reloc::Model RM) :
  OiGenSubtargetInfo(TT, CPU, FS),
  OiArchVersion(Oi32), OiABI(UnknownABI), IsLittle(little),
  IsSingleFloat(false), IsFP64bit(false), IsGP64bit(false), HasVFPU(false),
  IsLinux(true), HasSEInReg(false), HasCondMov(false), HasSwap(false),
  HasBitCount(false), HasFPIdx(false),
  InOi16Mode(false), HasDSP(false), HasDSPR2(false), IsAndroid(false)
{
  std::string CPUName = CPU;
  if (CPUName.empty())
    CPUName = "oi32";

  // Parse features string.
  ParseSubtargetFeatures(CPUName, FS);

  // Initialize scheduling itinerary for the specified CPU.
  InstrItins = getInstrItineraryForCPU(CPUName);

  // Set OiABI if it hasn't been set yet.
  if (OiABI == UnknownABI)
    OiABI = hasOi64() ? N64 : O32;

  // Check if Architecture and ABI are compatible.
  assert(((!hasOi64() && (isABI_O32() || isABI_EABI())) ||
          (hasOi64() && (isABI_N32() || isABI_N64()))) &&
         "Invalid  Arch & ABI pair.");

  // Is the target system Linux ?
  if (TT.find("linux") == std::string::npos)
    IsLinux = false;

  // Set UseSmallSection.
  UseSmallSection = !IsLinux && (RM == Reloc::Static);
}

bool
OiSubtarget::enablePostRAScheduler(CodeGenOpt::Level OptLevel,
                                    TargetSubtargetInfo::AntiDepBreakMode &Mode,
                                     RegClassVector &CriticalPathRCs) const {
  Mode = TargetSubtargetInfo::ANTIDEP_NONE;
  CriticalPathRCs.clear();
  CriticalPathRCs.push_back(hasOi64() ?
                            &Oi::CPU64RegsRegClass : &Oi::CPURegsRegClass);
  return OptLevel >= CodeGenOpt::Aggressive;
}
