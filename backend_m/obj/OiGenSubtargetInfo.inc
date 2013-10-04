/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Subtarget Enumeration Source Fragment                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_SUBTARGETINFO_ENUM
#undef GET_SUBTARGETINFO_ENUM
namespace llvm {
namespace Oi {
enum {
  FeatureAndroid =  1ULL << 0,
  FeatureBitCount =  1ULL << 1,
  FeatureCondMov =  1ULL << 2,
  FeatureDSP =  1ULL << 3,
  FeatureDSPR2 =  1ULL << 4,
  FeatureEABI =  1ULL << 5,
  FeatureFP64Bit =  1ULL << 6,
  FeatureFPIdx =  1ULL << 7,
  FeatureGP64Bit =  1ULL << 8,
  FeatureN32 =  1ULL << 9,
  FeatureN64 =  1ULL << 10,
  FeatureO32 =  1ULL << 11,
  FeatureOi16 =  1ULL << 12,
  FeatureOi32 =  1ULL << 13,
  FeatureOi32r2 =  1ULL << 14,
  FeatureOi64 =  1ULL << 15,
  FeatureOi64r2 =  1ULL << 16,
  FeatureSEInReg =  1ULL << 17,
  FeatureSingleFloat =  1ULL << 18,
  FeatureSwap =  1ULL << 19,
  FeatureVFPU =  1ULL << 20
};
}
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV OiFeatureKV[] = {
  { "FPIdx", "Enable 'FP indexed load/store' instructions.", Oi::FeatureFPIdx, 0ULL },
  { "android", "Target is android", Oi::FeatureAndroid, 0ULL },
  { "bitcount", "Enable 'count leading bits' instructions.", Oi::FeatureBitCount, 0ULL },
  { "condmov", "Enable 'conditional move' instructions.", Oi::FeatureCondMov, 0ULL },
  { "dsp", "Oi DSP ASE", Oi::FeatureDSP, 0ULL },
  { "dspr2", "Oi DSP-R2 ASE", Oi::FeatureDSPR2, Oi::FeatureDSP },
  { "eabi", "Enable eabi ABI", Oi::FeatureEABI, 0ULL },
  { "fp64", "Support 64-bit FP registers.", Oi::FeatureFP64Bit, 0ULL },
  { "gp64", "General Purpose Registers are 64-bit wide.", Oi::FeatureGP64Bit, 0ULL },
  { "n32", "Enable n32 ABI", Oi::FeatureN32, 0ULL },
  { "n64", "Enable n64 ABI", Oi::FeatureN64, 0ULL },
  { "o32", "Enable o32 ABI", Oi::FeatureO32, 0ULL },
  { "oi16", "Oi16 mode", Oi::FeatureOi16, 0ULL },
  { "oi32", "Oi32 ISA Support", Oi::FeatureOi32, Oi::FeatureCondMov | Oi::FeatureBitCount },
  { "oi32r2", "Oi32r2 ISA Support", Oi::FeatureOi32r2, Oi::FeatureOi32 | Oi::FeatureSEInReg | Oi::FeatureSwap | Oi::FeatureFPIdx },
  { "oi64", "Oi64 ISA Support", Oi::FeatureOi64, Oi::FeatureGP64Bit | Oi::FeatureFP64Bit | Oi::FeatureOi32 | Oi::FeatureFPIdx },
  { "oi64r2", "Oi64r2 ISA Support", Oi::FeatureOi64r2, Oi::FeatureOi64 | Oi::FeatureOi32r2 },
  { "seinreg", "Enable 'signext in register' instructions.", Oi::FeatureSEInReg, 0ULL },
  { "single-float", "Only supports single precision float", Oi::FeatureSingleFloat, 0ULL },
  { "swap", "Enable 'byte/half swap' instructions.", Oi::FeatureSwap, 0ULL },
  { "vfpu", "Enable vector FPU instructions.", Oi::FeatureVFPU, 0ULL }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV OiSubTypeKV[] = {
  { "oi16", "Select the oi16 processor", Oi::FeatureOi16, 0ULL },
  { "oi32", "Select the oi32 processor", Oi::FeatureOi32, 0ULL },
  { "oi32r2", "Select the oi32r2 processor", Oi::FeatureOi32r2, 0ULL },
  { "oi64", "Select the oi64 processor", Oi::FeatureOi64, 0ULL },
  { "oi64r2", "Select the oi64r2 processor", Oi::FeatureOi64r2, 0ULL }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// Functional units for "OiGenericItineraries"
namespace OiGenericItinerariesFU {
  const unsigned ALU = 1 << 0;
  const unsigned IMULDIV = 1 << 1;
}

extern const llvm::InstrStage OiStages[] = {
  { 0, 0, 0, llvm::InstrStage::Required }, // No itinerary
  { 1, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 1
  { 4, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 2
  { 3, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 3
  { 36, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 4
  { 23, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 5
  { 2, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 6
  { 8, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 7
  { 7, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 8
  { 12, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 9
  { 54, OiGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 10
  { 1, OiGenericItinerariesFU::IMULDIV, -1, (llvm::InstrStage::ReservationKinds)0 }, // 11
  { 38, OiGenericItinerariesFU::IMULDIV, -1, (llvm::InstrStage::ReservationKinds)0 }, // 12
  { 17, OiGenericItinerariesFU::IMULDIV, -1, (llvm::InstrStage::ReservationKinds)0 }, // 13
  { 0, 0, 0, llvm::InstrStage::Required } // End stages
};
extern const unsigned OiOperandCycles[] = {
  0, // No itinerary
  0 // End operand cycles
};
extern const unsigned OiForwardingPaths[] = {
 0, // No itinerary
 0 // End bypass tables
};

static const llvm::InstrItinerary *NoItineraries = 0;

static const llvm::InstrItinerary OiGenericItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoItinerary
  { 1, 1, 2, 0, 0 }, // 1 IIAlu
  { 1, 1, 2, 0, 0 }, // 2 IIBranch
  { 1, 2, 3, 0, 0 }, // 3 IIFadd
  { 1, 3, 4, 0, 0 }, // 4 IIFcmp
  { 1, 1, 2, 0, 0 }, // 5 IIFcvt
  { 1, 4, 5, 0, 0 }, // 6 IIFdivDouble
  { 1, 5, 6, 0, 0 }, // 7 IIFdivSingle
  { 1, 6, 7, 0, 0 }, // 8 IIFmove
  { 1, 7, 8, 0, 0 }, // 9 IIFmulDouble
  { 1, 8, 9, 0, 0 }, // 10 IIFmulSingle
  { 1, 9, 10, 0, 0 }, // 11 IIFsqrtDouble
  { 1, 10, 11, 0, 0 }, // 12 IIFsqrtSingle
  { 1, 11, 12, 0, 0 }, // 13 IIHiLo
  { 1, 12, 13, 0, 0 }, // 14 IIIdiv
  { 1, 13, 14, 0, 0 }, // 15 IIImul
  { 1, 3, 4, 0, 0 }, // 16 IILoad
  { 0, 0, 0, 0, 0 }, // 17 IIPseudo
  { 1, 1, 2, 0, 0 }, // 18 IIStore
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry OiWriteProcResTable[] = {
  { 0,  0}, // Invalid
}; // OiWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry OiWriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // OiWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry OiReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // OiReadAdvanceTable

static const llvm::MCSchedModel NoSchedModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMinLatency,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultILPWindow,
  MCSchedModel::DefaultMispredictPenalty,
  0, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  NoItineraries);

static const llvm::MCSchedModel OiGenericItinerariesModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMinLatency,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultILPWindow,
  MCSchedModel::DefaultMispredictPenalty,
  1, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  OiGenericItineraries);

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV OiProcSchedKV[] = {
  { "oi16", (const void *)&OiGenericItinerariesModel },
  { "oi32", (const void *)&OiGenericItinerariesModel },
  { "oi32r2", (const void *)&OiGenericItinerariesModel },
  { "oi64", (const void *)&OiGenericItinerariesModel },
  { "oi64r2", (const void *)&OiGenericItinerariesModel }
};
#undef DBGFIELD
static inline void InitOiMCSubtargetInfo(MCSubtargetInfo *II, StringRef TT, StringRef CPU, StringRef FS) {
  II->InitMCSubtargetInfo(TT, CPU, FS, OiFeatureKV, OiSubTypeKV, 
                      OiProcSchedKV, OiWriteProcResTable, OiWriteLatencyTable, OiReadAdvanceTable, 
                      OiStages, OiOperandCycles, OiForwardingPaths, 21, 5);
}

} // End llvm namespace 
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::OiSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  uint64_t Bits = getFeatureBits();
  if ((Bits & Oi::FeatureAndroid) != 0) IsAndroid = true;
  if ((Bits & Oi::FeatureBitCount) != 0) HasBitCount = true;
  if ((Bits & Oi::FeatureCondMov) != 0) HasCondMov = true;
  if ((Bits & Oi::FeatureDSP) != 0) HasDSP = true;
  if ((Bits & Oi::FeatureDSPR2) != 0) HasDSPR2 = true;
  if ((Bits & Oi::FeatureEABI) != 0 && OiABI < EABI) OiABI = EABI;
  if ((Bits & Oi::FeatureFP64Bit) != 0) IsFP64bit = true;
  if ((Bits & Oi::FeatureFPIdx) != 0) HasFPIdx = true;
  if ((Bits & Oi::FeatureGP64Bit) != 0) IsGP64bit = true;
  if ((Bits & Oi::FeatureN32) != 0 && OiABI < N32) OiABI = N32;
  if ((Bits & Oi::FeatureN64) != 0 && OiABI < N64) OiABI = N64;
  if ((Bits & Oi::FeatureO32) != 0 && OiABI < O32) OiABI = O32;
  if ((Bits & Oi::FeatureOi16) != 0) InOi16Mode = true;
  if ((Bits & Oi::FeatureOi32) != 0 && OiArchVersion < Oi32) OiArchVersion = Oi32;
  if ((Bits & Oi::FeatureOi32r2) != 0 && OiArchVersion < Oi32r2) OiArchVersion = Oi32r2;
  if ((Bits & Oi::FeatureOi64) != 0 && OiArchVersion < Oi64) OiArchVersion = Oi64;
  if ((Bits & Oi::FeatureOi64r2) != 0 && OiArchVersion < Oi64r2) OiArchVersion = Oi64r2;
  if ((Bits & Oi::FeatureSEInReg) != 0) HasSEInReg = true;
  if ((Bits & Oi::FeatureSingleFloat) != 0) IsSingleFloat = true;
  if ((Bits & Oi::FeatureSwap) != 0) HasSwap = true;
  if ((Bits & Oi::FeatureVFPU) != 0) HasVFPU = true;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct OiGenSubtargetInfo : public TargetSubtargetInfo {
  explicit OiGenSubtargetInfo(StringRef TT, StringRef CPU, StringRef FS);
public:
  unsigned resolveSchedClass(unsigned SchedClass, const MachineInstr *DefMI, const TargetSchedModel *SchedModel) const;
  DFAPacketizer *createDFAPacketizer(const InstrItineraryData *IID) const;
};
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_HEADER


#ifdef GET_SUBTARGETINFO_CTOR
#undef GET_SUBTARGETINFO_CTOR
#include "llvm/CodeGen/TargetSchedule.h"
namespace llvm {
extern const llvm::SubtargetFeatureKV OiFeatureKV[];
extern const llvm::SubtargetFeatureKV OiSubTypeKV[];
extern const llvm::SubtargetInfoKV OiProcSchedKV[];
extern const llvm::MCWriteProcResEntry OiWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry OiWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry OiReadAdvanceTable[];
extern const llvm::InstrStage OiStages[];
extern const unsigned OiOperandCycles[];
extern const unsigned OiForwardingPaths[];
OiGenSubtargetInfo::OiGenSubtargetInfo(StringRef TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo() {
  InitMCSubtargetInfo(TT, CPU, FS, OiFeatureKV, OiSubTypeKV, 
                      OiProcSchedKV, OiWriteProcResTable, OiWriteLatencyTable, OiReadAdvanceTable, 
                      OiStages, OiOperandCycles, OiForwardingPaths, 21, 5);
}

unsigned OiGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // OiGenSubtargetInfo::resolveSchedClass
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_CTOR

