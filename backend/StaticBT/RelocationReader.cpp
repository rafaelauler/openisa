#include "RelocationReader.h"
#include "SBTUtils.h"
#include "llvm/Object/ELF.h"
#include "llvm/IR/Value.h"

using namespace llvm;

bool RelocationReader::ResolveRelocation(uint64_t &Res, uint64_t *Type) {
  relocation_iterator Rel = (*CurSection)->end_relocations();
  error_code ec;
  StringRef Name;
  if (!CheckRelocation(Rel, Name))
    return false;
  for (section_iterator i = Obj->begin_sections(),
         e = Obj->end_sections();
       i != e; i.increment(ec)) {
    if (error(ec)) break;
    StringRef SecName;
    if (error(i->getName(SecName))) break;
    if (SecName != Name)
      continue;
    
    uint64_t SectionAddr;
    if (error(i->getAddress(SectionAddr))) break;

    // Relocatable file
    if (SectionAddr == 0) {
      SectionAddr = GetELFOffset(i);
    }

    Res = SectionAddr;
    if (Type) {
      if (error(Rel->getType(*Type)))
        llvm_unreachable("Error getting relocation type");
    }
    return true;
  }

  for (symbol_iterator si = Obj->begin_symbols(),
         se = Obj->end_symbols();
       si != se; si.increment(ec)) {
    StringRef SName;
    if (error(si->getName(SName))) break;
    if (Name != SName)
      continue;

    uint64_t Address;
    if (error(si->getAddress(Address))) break;
    if (Address == UnknownAddressOrSize) continue;
    //        Address -= SectionAddr;
    Res = Address;

    section_iterator seci = Obj->end_sections();
    // Check if it is relative to a section
    if ((!error(si->getSection(seci)))
        && seci != Obj->end_sections()) {
      uint64_t SectionAddr;
      if (error(seci->getAddress(SectionAddr))) 
        llvm_unreachable("Error getting section address");

      // Relocatable file
      if (SectionAddr == 0) {
        SectionAddr = GetELFOffset(seci);
      }
      Res += SectionAddr;
    }

    if (Type) {
      if (error(Rel->getType(*Type)))
        llvm_unreachable("Error getting relocation type");
    }
    return true;
  }

  return false;
}

bool RelocationReader::CheckRelocation(relocation_iterator &Rel, StringRef &Name) {
  error_code ec;
  uint64_t offset = GetELFOffset(*CurSection);
  for (relocation_iterator ri = (*CurSection)->begin_relocations(),
         re = (*CurSection)->end_relocations();
       ri != re; ri.increment(ec)) {
    if (error(ec)) break;
    uint64_t addr;
    if (error(ri->getOffset(addr))) break;
    if (offset + addr != CurAddr)
      continue;

    Rel = ri;
    SymbolRef symb;
    if (!error(ri->getSymbol(symb))) {
      if (!error(symb.getName(Name))) {
        return true;
      }
    }
  }

  return false;
}
