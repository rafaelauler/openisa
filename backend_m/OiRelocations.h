//===-- OiRelocations.h - Oi Code Relocations ---------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the Oi target-specific relocation types
// (for relocation-model=static).
//
//===----------------------------------------------------------------------===//

#ifndef OIRELOCATIONS_H_
#define OIRELOCATIONS_H_

#include "llvm/CodeGen/MachineRelocation.h"

namespace llvm {
  namespace Oi{
    enum RelocationType {
      // reloc_oi_pc16 - pc relative relocation for branches. The lower 18
      // bits of the difference between the branch target and the branch
      // instruction, shifted right by 2.
      reloc_oi_pc16 = 1,

      // reloc_oi_hi - upper 16 bits of the address (modified by +1 if the
      // lower 16 bits of the address is negative).
      reloc_oi_hi = 2,

      // reloc_oi_lo - lower 16 bits of the address.
      reloc_oi_lo = 3,

      // reloc_oi_26 - lower 28 bits of the address, shifted right by 2.
      reloc_oi_26 = 4
    };
  }
}

#endif /* OIRELOCATIONS_H_ */
