//===-- Oi.td - Describe the Oi Target Machine ---------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the Oi target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Register File, Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "OiRegisterInfo.td"
include "OiSchedule.td"
include "OiInstrInfo.td"
include "OiCallingConv.td"

def OiInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// Oi Subtarget features                                                    //
//===----------------------------------------------------------------------===//

def FeatureGP64Bit     : SubtargetFeature<"gp64", "IsGP64bit", "true",
                                "General Purpose Registers are 64-bit wide.">;
def FeatureFP64Bit     : SubtargetFeature<"fp64", "IsFP64bit", "true",
                                "Support 64-bit FP registers.">;
def FeatureSingleFloat : SubtargetFeature<"single-float", "IsSingleFloat",
                                "true", "Only supports single precision float">;
def FeatureO32         : SubtargetFeature<"o32", "OiABI", "O32",
                                "Enable o32 ABI">;
def FeatureN32         : SubtargetFeature<"n32", "OiABI", "N32",
                                "Enable n32 ABI">;
def FeatureN64         : SubtargetFeature<"n64", "OiABI", "N64",
                                "Enable n64 ABI">;
def FeatureEABI        : SubtargetFeature<"eabi", "OiABI", "EABI",
                                "Enable eabi ABI">;
def FeatureVFPU        : SubtargetFeature<"vfpu", "HasVFPU",
                                "true", "Enable vector FPU instructions.">;
def FeatureSEInReg     : SubtargetFeature<"seinreg", "HasSEInReg", "true",
                                "Enable 'signext in register' instructions.">;
def FeatureCondMov     : SubtargetFeature<"condmov", "HasCondMov", "true",
                                "Enable 'conditional move' instructions.">;
def FeatureSwap        : SubtargetFeature<"swap", "HasSwap", "true",
                                "Enable 'byte/half swap' instructions.">;
def FeatureBitCount    : SubtargetFeature<"bitcount", "HasBitCount", "true",
                                "Enable 'count leading bits' instructions.">;
def FeatureFPIdx       : SubtargetFeature<"FPIdx", "HasFPIdx", "true",
                                "Enable 'FP indexed load/store' instructions.">;
def FeatureOi32      : SubtargetFeature<"oi32", "OiArchVersion", "Oi32",
                                "Oi32 ISA Support",
                                [FeatureCondMov, FeatureBitCount]>;
def FeatureOi32r2    : SubtargetFeature<"oi32r2", "OiArchVersion",
                                "Oi32r2", "Oi32r2 ISA Support",
                                [FeatureOi32, FeatureSEInReg, FeatureSwap,
                                 FeatureFPIdx]>;
def FeatureOi64      : SubtargetFeature<"oi64", "OiArchVersion",
                                "Oi64", "Oi64 ISA Support",
                                [FeatureGP64Bit, FeatureFP64Bit,
                                 FeatureOi32, FeatureFPIdx]>;
def FeatureOi64r2    : SubtargetFeature<"oi64r2", "OiArchVersion",
                                "Oi64r2", "Oi64r2 ISA Support",
                                [FeatureOi64, FeatureOi32r2]>;

def FeatureOi16  : SubtargetFeature<"oi16", "InOi16Mode", "true",
                                      "Oi16 mode">;

def FeatureDSP : SubtargetFeature<"dsp", "HasDSP", "true", "Oi DSP ASE">;
def FeatureDSPR2 : SubtargetFeature<"dspr2", "HasDSPR2", "true",
                                    "Oi DSP-R2 ASE", [FeatureDSP]>;

def FeatureMicroOi  : SubtargetFeature<"microoi", "InMicroOiMode", "true",
                                         "microOi mode">;

//===----------------------------------------------------------------------===//
// Oi processors supported.
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, OiGenericItineraries, Features>;

def : Proc<"oi32", [FeatureOi32]>;
def : Proc<"oi32r2", [FeatureOi32r2]>;
def : Proc<"oi64", [FeatureOi64]>;
def : Proc<"oi64r2", [FeatureOi64r2]>;
def : Proc<"oi16", [FeatureOi16]>;

def OiAsmWriter : AsmWriter {
  string AsmWriterClassName  = "InstPrinter";
  bit isMCAsmWriter = 1;
}

def OiAsmParser : AsmParser {
  let ShouldEmitMatchRegisterName = 0;
}

def OiAsmParserVariant : AsmParserVariant {
  int Variant = 0;

  // Recognize hard coded registers.
  string RegisterPrefix = "$";
}

def Oi : Target {
  let InstructionSet = OiInstrInfo;
  let AssemblyParsers = [OiAsmParser];
  let AssemblyWriters = [OiAsmWriter];
  let AssemblyParserVariants = [OiAsmParserVariant];
}
