//===-- OiFixupKinds.h - Oi Specific Fixup Entries ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_OI_OIFIXUPKINDS_H
#define LLVM_OI_OIFIXUPKINDS_H

#include "llvm/MC/MCFixup.h"

namespace llvm {
namespace Oi {
  // Although most of the current fixup types reflect a unique relocation
  // one can have multiple fixup types for a given relocation and thus need
  // to be uniquely named.
  //
  // This table *must* be in the save order of
  // MCFixupKindInfo Infos[Oi::NumTargetFixupKinds]
  // in OiAsmBackend.cpp.
  //
  enum Fixups {
    // Branch fixups resulting in R_OI_16.
    fixup_Oi_16 = FirstTargetFixupKind,

    // Pure 32 bit data fixup resulting in - R_OI_32.
    fixup_Oi_32,

    // Full 32 bit data relative data fixup resulting in - R_OI_REL32.
    fixup_Oi_REL32,

    // Jump 26 bit fixup resulting in - R_OI_26.
    fixup_Oi_26,

    // Pure upper 16 bit fixup resulting in - R_OI_HI16.
    fixup_Oi_HI16,

    // Pure lower 16 bit fixup resulting in - R_OI_LO16.
    fixup_Oi_LO16,

    // 16 bit fixup for GP offest resulting in - R_OI_GPREL16.
    fixup_Oi_GPREL16,

    // 16 bit literal fixup resulting in - R_OI_LITERAL.
    fixup_Oi_LITERAL,

    // Global symbol fixup resulting in - R_OI_GOT16.
    fixup_Oi_GOT_Global,

    // Local symbol fixup resulting in - R_OI_GOT16.
    fixup_Oi_GOT_Local,

    // PC relative branch fixup resulting in - R_OI_PC16.
    fixup_Oi_PC16,

    // resulting in - R_OI_CALL16.
    fixup_Oi_CALL16,

    // resulting in - R_OI_GPREL32.
    fixup_Oi_GPREL32,

    // resulting in - R_OI_SHIFT5.
    fixup_Oi_SHIFT5,

    // resulting in - R_OI_SHIFT6.
    fixup_Oi_SHIFT6,

    // Pure 64 bit data fixup resulting in - R_OI_64.
    fixup_Oi_64,

    // resulting in - R_OI_TLS_GD.
    fixup_Oi_TLSGD,

    // resulting in - R_OI_TLS_GOTTPREL.
    fixup_Oi_GOTTPREL,

    // resulting in - R_OI_TLS_TPREL_HI16.
    fixup_Oi_TPREL_HI,

    // resulting in - R_OI_TLS_TPREL_LO16.
    fixup_Oi_TPREL_LO,

    // resulting in - R_OI_TLS_LDM.
    fixup_Oi_TLSLDM,

    // resulting in - R_OI_TLS_DTPREL_HI16.
    fixup_Oi_DTPREL_HI,

    // resulting in - R_OI_TLS_DTPREL_LO16.
    fixup_Oi_DTPREL_LO,

    // PC relative branch fixup resulting in - R_OI_PC16
    fixup_Oi_Branch_PCRel,

    // resulting in - R_OI_GPREL16/R_OI_SUB/R_OI_HI16
    fixup_Oi_GPOFF_HI,

    // resulting in - R_OI_GPREL16/R_OI_SUB/R_OI_LO16
    fixup_Oi_GPOFF_LO,

    // resulting in - R_OI_PAGE
    fixup_Oi_GOT_PAGE,

    // resulting in - R_OI_GOT_OFST
    fixup_Oi_GOT_OFST,

    // resulting in - R_OI_GOT_DISP
    fixup_Oi_GOT_DISP,

    // resulting in - R_OI_GOT_HIGHER
    fixup_Oi_HIGHER,

    // resulting in - R_OI_HIGHEST
    fixup_Oi_HIGHEST,

    // resulting in - R_OI_GOT_HI16
    fixup_Oi_GOT_HI16,

    // resulting in - R_OI_GOT_LO16
    fixup_Oi_GOT_LO16,

    // resulting in - R_OI_CALL_HI16
    fixup_Oi_CALL_HI16,

    // resulting in - R_OI_CALL_LO16
    fixup_Oi_CALL_LO16,

    // Marker
    LastTargetFixupKind,
    NumTargetFixupKinds = LastTargetFixupKind - FirstTargetFixupKind
  };
} // namespace Oi
} // namespace llvm


#endif // LLVM_OI_OIFIXUPKINDS_H
