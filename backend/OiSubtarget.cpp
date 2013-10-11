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

#define DEBUG_TYPE "oi-subtarget"

#include "OiMachineFunction.h"
#include "OiSubtarget.h"
#include "OiTargetMachine.h"
#include "Oi.h"
#include "OiRegisterInfo.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "OiGenSubtargetInfo.inc"


using namespace llvm;

// FIXME: Maybe this should be on by default when Oi16 is specified
//
static cl::opt<bool> Mixed16_32(
  "oi-mixed-16-32",
  cl::init(false),
  cl::desc("Allow for a mixture of Oi16 "
           "and Oi32 code in a single source file"),
  cl::Hidden);

static cl::opt<bool> Oi_Os16(
  "oi-os16",
  cl::init(false),
  cl::desc("Compile all functions that don' use "
           "floating point as Oi 16"),
  cl::Hidden);

void OiSubtarget::anchor() { }

OiSubtarget::OiSubtarget(const std::string &TT, const std::string &CPU,
                             const std::string &FS, bool little,
                             Reloc::Model _RM, OiTargetMachine *_TM) :
  OiGenSubtargetInfo(TT, CPU, FS),
  OiArchVersion(Oi32), OiABI(UnknownABI), IsLittle(little),
  IsSingleFloat(false), IsFP64bit(false), IsGP64bit(false), HasVFPU(false),
  IsLinux(true), HasSEInReg(false), HasCondMov(false), HasSwap(false),
  HasBitCount(false), HasFPIdx(false),
  InOi16Mode(false), InMicroOiMode(false), HasDSP(false), HasDSPR2(false),
  AllowMixed16_32(Mixed16_32 | Oi_Os16), Os16(Oi_Os16),
  RM(_RM), OverrideMode(NoOverride), TM(_TM)
{
  std::string CPUName = CPU;
  if (CPUName.empty())
    CPUName = "oi32";

  // Force static relocation XXX: Disable PIC
  //RM = Reloc::Static;

  // Parse features string.
  ParseSubtargetFeatures(CPUName, FS);

  PreviousInOi16Mode = InOi16Mode;

  // Initialize scheduling itinerary for the specified CPU.
  InstrItins = getInstrItineraryForCPU(CPUName);

  // Set OiABI if it hasn't been set yet.
  if (OiABI == UnknownABI)
    //OiABI = hasOi64() ? N64 : O32;
    OiABI = O32;

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

//FIXME: This logic for reseting the subtarget along with
// the helper classes can probably be simplified but there are a lot of
// cases so we will defer rewriting this to later.
//
void OiSubtarget::resetSubtarget(MachineFunction *MF) {
  bool ChangeToOi16 = false, ChangeToNoOi16 = false;
  DEBUG(dbgs() << "resetSubtargetFeatures" << "\n");
  AttributeSet FnAttrs = MF->getFunction()->getAttributes();
  ChangeToOi16 = FnAttrs.hasAttribute(AttributeSet::FunctionIndex,
                                        "oi16");
  ChangeToNoOi16 = FnAttrs.hasAttribute(AttributeSet::FunctionIndex,
                                        "nooi16");
  assert (!(ChangeToOi16 & ChangeToNoOi16) &&
          "oi16 and nooi16 specified on the same function");
  if (ChangeToOi16) {
    if (PreviousInOi16Mode)
      return;
    OverrideMode = Oi16Override;
    PreviousInOi16Mode = true;
    TM->setHelperClassesOi16();
    return;
  } else if (ChangeToNoOi16) {
    if (!PreviousInOi16Mode)
      return;
    OverrideMode = NoOi16Override;
    PreviousInOi16Mode = false;
    TM->setHelperClassesOiSE();
    return;
  } else {
    if (OverrideMode == NoOverride)
      return;
    OverrideMode = NoOverride;
    DEBUG(dbgs() << "back to default" << "\n");
    if (inOi16Mode() && !PreviousInOi16Mode) {
      TM->setHelperClassesOi16();
      PreviousInOi16Mode = true;
    } else if (!inOi16Mode() && PreviousInOi16Mode) {
      TM->setHelperClassesOiSE();
      PreviousInOi16Mode = false;
    }
    return;
  }
}

