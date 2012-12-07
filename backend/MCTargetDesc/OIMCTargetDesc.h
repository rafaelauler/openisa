//===-- OIMCTargetDesc.h - OI Target Descriptions ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides OI specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef OIMCTARGETDESC_H
#define OIMCTARGETDESC_H

namespace llvm {
class Target;

extern Target TheOITarget;
extern Target TheOIV9Target;

} // End llvm namespace

// Defines symbolic names for OI registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "OIGenRegisterInfo.inc"

// Defines symbolic names for the OI instructions.
//
#define GET_INSTRINFO_ENUM
#include "OIGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "OIGenSubtargetInfo.inc"

#endif
