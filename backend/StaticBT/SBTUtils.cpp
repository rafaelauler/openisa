//=== SBTUtils.cpp - General utilities ------------------*- C++ -*-==//
// 
// Convenience functions to convert register numbers when reading
// an OpenISA binary and converting it to IR.
//
//===------------------------------------------------------------===//

#include "SBTUtils.h"
#include "OiInstrInfo.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Object/ELF.h"

namespace llvm {

bool error(error_code ec) {
  if (!ec) return false;

  outs() << "error reading file: " << ec.message() << ".\n";
  outs().flush();
  return true;
}

unsigned conv32(unsigned regnum) {
  switch(regnum) {
  case Oi::AT_64:
    return Oi::AT;
  case Oi::FP_64:
    return Oi::FP;
  case Oi::SP_64:
    return Oi::SP;
  case Oi::RA_64:
    return Oi::RA;
  case Oi::ZERO_64:
    return Oi::ZERO;
  case Oi::GP_64:
    return Oi::GP;
  case Oi::A0_64:
    return Oi::A0;
  case Oi::A1_64:
    return Oi::A1;
  case Oi::A2_64:
    return Oi::A2;
  case Oi::A3_64:
    return Oi::A3;
  case Oi::V0_64:
    return Oi::V0;
  case Oi::V1_64:
    return Oi::V1;
  case Oi::S0_64:
    return Oi::S0;
  case Oi::S1_64:
    return Oi::S1;
  case Oi::S2_64:
    return Oi::S2;
  case Oi::S3_64:
    return Oi::S3;
  case Oi::S4_64:
    return Oi::S4;
  case Oi::S5_64:
    return Oi::S5;
  case Oi::S6_64:
    return Oi::S6;
  case Oi::S7_64:
    return Oi::S7;
  case Oi::K0_64:
    return Oi::K0;
  case Oi::K1_64:
    return Oi::K1;
  case Oi::T0_64:
    return Oi::T0;
  case Oi::T1_64:
    return Oi::T1;
  case Oi::T2_64:
    return Oi::T2;
  case Oi::T3_64:
    return Oi::T3;
  case Oi::T4_64:
    return Oi::T4;
  case Oi::T5_64:
    return Oi::T5;
  case Oi::T6_64:
    return Oi::T6;
  case Oi::T7_64:
    return Oi::T7;
  case Oi::T8_64:
    return Oi::T8;
  case Oi::T9_64:
    return Oi::T9; 
  case Oi::D0_64:
    return Oi::F0;
  case Oi::D1_64:
    return Oi::F1;
  case Oi::D2_64:
    return Oi::F2;
  case Oi::D3_64:
    return Oi::F3;
  case Oi::D4_64:
    return Oi::F4;
  case Oi::D5_64:
    return Oi::F5;
  case Oi::D6_64:
    return Oi::F6;
  case Oi::D7_64:
    return Oi::F7;
  case Oi::D8_64:
    return Oi::F8;
  case Oi::D9_64:
    return Oi::F9;
  case Oi::D10_64:
    return Oi::F10;
  case Oi::D11_64:
    return Oi::F11;
  case Oi::D12_64:
    return Oi::F12;
  case Oi::D13_64:
    return Oi::F13;
  case Oi::D14_64:
    return Oi::F14;
  case Oi::D15_64:
    return Oi::F15;
  case Oi::D16_64:
    return Oi::F16;
  case Oi::D17_64:
    return Oi::F17;
  case Oi::D18_64:
    return Oi::F18;
  case Oi::D19_64:
    return Oi::F19;
  case Oi::D20_64:
    return Oi::F20;
  case Oi::D21_64:
    return Oi::F21;
  case Oi::D22_64:
    return Oi::F22;
  case Oi::D23_64:
    return Oi::F23;
  case Oi::D24_64:
    return Oi::F24;
  case Oi::D25_64:
    return Oi::F25;
  case Oi::D26_64:
    return Oi::F26;
  case Oi::D27_64:
    return Oi::F27;
  case Oi::D28_64:
    return Oi::F28;
  case Oi::D29_64:
    return Oi::F29;
  case Oi::D30_64:
    return Oi::F30;
  case Oi::D31_64:
    return Oi::F31;

    //    return regnum - 1;
  }
  return regnum;
}

unsigned ConvFromDirective(unsigned regnum) {
  switch(regnum) {
  case 0:
    return Oi::ZERO;
  case 1:
    return Oi::AT;
  case 4:
    return Oi::A0;
  case 5:
    return Oi::A1;
  case 6:
    return Oi::A2;
  case 7:
    return Oi::A3;
  case 2:
    return Oi::V0;
  case 3:
    return Oi::V1;
  case 16:
    return Oi::S0;
  case 17:
    return Oi::S1;
  case 18:
    return Oi::S2;
  case 19:
    return Oi::S3;
  case 20:
    return Oi::S4;
  case 21:
    return Oi::S5;
  case 22:
    return Oi::S6;
  case 23:
    return Oi::S7;
  case 26:
    return Oi::K0;
  case 27:
    return Oi::K1;
  case 29:
    return Oi::SP;
  case 30:
    return Oi::FP;
  case 28:
    return Oi::GP;
  case 31:
    return Oi::RA;
  case 8:
    return Oi::T0;
  case 9:
    return Oi::T1;
  case 10:
    return Oi::T2;
  case 11:
    return Oi::T3;
  case 12:
    return Oi::T4;
  case 13:
    return Oi::T5;
  case 14:
    return Oi::T6;
  case 15:
    return Oi::T7;
  case 24:
    return Oi::T8;
  case 25:
    return Oi::T9;
  }
  return -1;
}

unsigned ConvToDirective(unsigned regnum) {
  switch(regnum) {
  case Oi::ZERO:
    return 0;
  case Oi::AT:
    return 1;
  case Oi::A0:
    return 4;
  case Oi::A1:
    return 5;
  case Oi::A2:
    return 6;
  case Oi::A3:
    return 7;
  case Oi::V0:
    return 2;
  case Oi::V1:
    return 3;
  case Oi::S0:
    return 16;
  case Oi::S1:
    return 17;
  case Oi::S2:
    return 18;
  case Oi::S3:
    return 19;
  case Oi::S4:
    return 20;
  case Oi::S5:
    return 21;
  case Oi::S6:
    return 22;
  case Oi::S7:
    return 23;
  case Oi::K0:
    return 26;
  case Oi::K1:
    return 27;
  case Oi::SP:
    return 29;
  case Oi::FP:
    return 30;
  case Oi::GP:
    return 28;
  case Oi::RA:
    return 31;
  case Oi::T0:
    return 8;
  case Oi::T1:
    return 9;
  case Oi::T2:
    return 10;
  case Oi::T3:
    return 11;
  case Oi::T4:
    return 12;
  case Oi::T5:
    return 13;
  case Oi::T6:
    return 14;
  case Oi::T7:
    return 15;
  case Oi::T8:
    return 24;
  case Oi::T9:
    return 25;
    // Floating point registers
  case Oi::D0:
  case Oi::F0:
    return 34;
  case Oi::F1:
    return 35;
  case Oi::D1:
  case Oi::F2:
    return 36;
  case Oi::F3:
    return 37;
  case Oi::D2:
  case Oi::F4:
    return 38;
  case Oi::F5:
    return 39;
  case Oi::D3:
  case Oi::F6:
    return 40;
  case Oi::F7:
    return 41;
  case Oi::D4:
  case Oi::F8:
    return 42;
  case Oi::F9:
    return 43;
  case Oi::D5:
  case Oi::F10:
    return 44;
  case Oi::F11:
    return 45;
  case Oi::D6:
  case Oi::F12:
    return 46;
  case Oi::F13:
    return 47;
  case Oi::D7:
  case Oi::F14:
    return 48;
  case Oi::F15:
    return 49;
  case Oi::D8:
  case Oi::F16:
    return 50;
  case Oi::F17:
    return 51;
  case Oi::D9:
  case Oi::F18:
    return 52;
  case Oi::F19:
    return 53;
  case Oi::D10:
  case Oi::F20:
    return 54;
  case Oi::F21:
    return 55;
  case Oi::D11:
  case Oi::F22:
    return 56;
  case Oi::F23:
    return 57;
  case Oi::D12:
  case Oi::F24:
    return 58;
  case Oi::F25:
    return 59;
  case Oi::D13:
  case Oi::F26:
    return 60;
  case Oi::F27:
    return 61;
  case Oi::D14:
  case Oi::F28:
    return 62;
  case Oi::F29:
    return 63;
  case Oi::D15:
  case Oi::F30:
    return 64;
  case Oi::F31:
    return 65;

  }
  llvm_unreachable("Invalid register");
  return -1;
}

uint64_t GetELFOffset(section_iterator &i) {
  DataRefImpl Sec = i->getRawDataRefImpl();
  const object::Elf_Shdr_Impl<object::ELFType<support::little, 2, false> > *sec =
    reinterpret_cast<const object::Elf_Shdr_Impl<object::ELFType<support::little, 2, false> > *>(Sec.p);
  return sec->sh_offset;
}


std::vector<std::pair<uint64_t, StringRef> > GetSymbolsList(const ObjectFile *Obj, section_iterator &i) {
  uint64_t SectionAddr;
  if (error(i->getAddress(SectionAddr))) llvm_unreachable("");

  error_code ec;
  // Make a list of all the symbols in this section.
  std::vector<std::pair<uint64_t, StringRef> > Symbols;
  for (symbol_iterator si = Obj->begin_symbols(),
         se = Obj->end_symbols();
       si != se; si.increment(ec)) {
    bool contains;
    if (!error(i->containsSymbol(*si, contains)) && contains) {
      uint64_t Address;
      if (error(si->getAddress(Address))) break;
      if (Address == UnknownAddressOrSize) continue;
      Address -= SectionAddr;

      StringRef Name;
      if (error(si->getName(Name))) break;
      Symbols.push_back(std::make_pair(Address, Name));
    }
  }

  // Sort the symbols by address, just in case they didn't come in that way.
  array_pod_sort(Symbols.begin(), Symbols.end());
  return Symbols;
}

}
