//===-- OI.td - Describe the OI Target Machine -------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces which we are implementing
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// OI Subtarget features.
//
 
def FeatureV9
  : SubtargetFeature<"v9", "IsV9", "true",
                     "Enable OI-V9 instructions">;
def FeatureV8Deprecated
  : SubtargetFeature<"deprecated-v8", "V8DeprecatedInsts", "true",
                     "Enable deprecated V8 instructions in V9 mode">;
def FeatureVIS
  : SubtargetFeature<"vis", "IsVIS", "true",
                     "Enable UltraOI Visual Instruction Set extensions">;

//===----------------------------------------------------------------------===//
// Register File, Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "OIRegisterInfo.td"
include "OICallingConv.td"
include "OIInstrInfo.td"

def OIInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// OI processors supported.
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic",         []>;
def : Proc<"oiv9",              [FeatureV9]>;
def : Proc<"ultraoi",      [FeatureV9, FeatureV8Deprecated]>;
def : Proc<"ultraoi3-vis", [FeatureV9, FeatureV8Deprecated, FeatureVIS]>;


//===----------------------------------------------------------------------===//
// Declare the target which we are implementing
//===----------------------------------------------------------------------===//

def OI : Target {
  // Pull in Instruction Info:
  let InstructionSet = OIInstrInfo;
}
