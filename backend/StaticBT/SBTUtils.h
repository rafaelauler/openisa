//=== SBTUtils.h - General utilities --------------------*- C++ -*-==//
// 
// Convenience functions to convert register numbers when reading
// an OpenISA binary and converting it to IR.
//
//===------------------------------------------------------------===//
#ifndef SBTUTILS_H
#define SBTUTILS_H
#include "llvm/Support/system_error.h"
#include "llvm/Object/ObjectFile.h"

namespace llvm {

using namespace object;

unsigned conv32(unsigned regnum);
unsigned ConvFromDirective(unsigned regnum);
unsigned ConvToDirective(unsigned regnum);
bool error(error_code ec);
uint64_t GetELFOffset(section_iterator &i);

}
#endif
