/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Subtarget Enumeration Source Fragment                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_SUBTARGETINFO_ENUM
#undef GET_SUBTARGETINFO_ENUM
namespace llvm {
namespace OI {
enum {
  FeatureV8Deprecated =  1ULL << 0,
  FeatureV9 =  1ULL << 1,
  FeatureVIS =  1ULL << 2
};
}
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV OIFeatureKV[] = {
  { "deprecated-v8", "Enable deprecated V8 instructions in V9 mode", OI::FeatureV8Deprecated, 0ULL },
  { "v9", "Enable OI-V9 instructions", OI::FeatureV9, 0ULL },
  { "vis", "Enable UltraOI Visual Instruction Set extensions", OI::FeatureVIS, 0ULL }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV OISubTypeKV[] = {
  { "generic", "Select the generic processor", 0ULL, 0ULL },
  { "oiv9", "Select the oiv9 processor", OI::FeatureV9, 0ULL },
  { "ultraoi", "Select the ultraoi processor", OI::FeatureV9 | OI::FeatureV8Deprecated, 0ULL },
  { "ultraoi3-vis", "Select the ultraoi3-vis processor", OI::FeatureV9 | OI::FeatureV8Deprecated | OI::FeatureVIS, 0ULL }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry OIWriteProcResTable[] = {
  { 0,  0}, // Invalid
}; // OIWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry OIWriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // OIWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry OIReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // OIReadAdvanceTable

static const llvm::MCSchedModel NoSchedModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMinLatency,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultILPWindow,
  MCSchedModel::DefaultMispredictPenalty,
  0, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  0); // No Itinerary

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV OIProcSchedKV[] = {
  { "generic", (const void *)&NoSchedModel },
  { "oiv9", (const void *)&NoSchedModel },
  { "ultraoi", (const void *)&NoSchedModel },
  { "ultraoi3-vis", (const void *)&NoSchedModel }
};
#undef DBGFIELD
static inline void InitOIMCSubtargetInfo(MCSubtargetInfo *II, StringRef TT, StringRef CPU, StringRef FS) {
  II->InitMCSubtargetInfo(TT, CPU, FS, OIFeatureKV, OISubTypeKV, 
                      OIProcSchedKV, OIWriteProcResTable, OIWriteLatencyTable, OIReadAdvanceTable, 0, 0, 0, 3, 4);
}

} // End llvm namespace 
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::OISubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  uint64_t Bits = getFeatureBits();
  if ((Bits & OI::FeatureV8Deprecated) != 0) V8DeprecatedInsts = true;
  if ((Bits & OI::FeatureV9) != 0) IsV9 = true;
  if ((Bits & OI::FeatureVIS) != 0) IsVIS = true;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct OIGenSubtargetInfo : public TargetSubtargetInfo {
  explicit OIGenSubtargetInfo(StringRef TT, StringRef CPU, StringRef FS);
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
extern const llvm::SubtargetFeatureKV OIFeatureKV[];
extern const llvm::SubtargetFeatureKV OISubTypeKV[];
extern const llvm::SubtargetInfoKV OIProcSchedKV[];
extern const llvm::MCWriteProcResEntry OIWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry OIWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry OIReadAdvanceTable[];
OIGenSubtargetInfo::OIGenSubtargetInfo(StringRef TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo() {
  InitMCSubtargetInfo(TT, CPU, FS, OIFeatureKV, OISubTypeKV, 
                      OIProcSchedKV, OIWriteProcResTable, OIWriteLatencyTable, OIReadAdvanceTable, 
                      0, 0, 0, 3, 4);
}

unsigned OIGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // OIGenSubtargetInfo::resolveSchedClass
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_CTOR

