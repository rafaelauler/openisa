//===-- OiMCTargetDesc.h - Oi Target Descriptions -----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Oi specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef OIMCTARGETDESC_H
#define OIMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

namespace llvm {
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class StringRef;
class Target;
class raw_ostream;

extern Target TheOiTarget;
  //extern Target TheOielTarget;
  //extern Target TheOi64Target;
  //extern Target TheOi64elTarget;

MCCodeEmitter *createOiMCCodeEmitterEB(const MCInstrInfo &MCII,
                                         const MCRegisterInfo &MRI,
                                         const MCSubtargetInfo &STI,
                                         MCContext &Ctx);
MCCodeEmitter *createOiMCCodeEmitterEL(const MCInstrInfo &MCII,
                                         const MCRegisterInfo &MRI,
                                         const MCSubtargetInfo &STI,
                                         MCContext &Ctx);

MCAsmBackend *createOiAsmBackendEB32(const Target &T, StringRef TT,
                                       StringRef CPU);
MCAsmBackend *createOiAsmBackendEL32(const Target &T, StringRef TT,
                                       StringRef CPU);
MCAsmBackend *createOiAsmBackendEB64(const Target &T, StringRef TT,
                                       StringRef CPU);
MCAsmBackend *createOiAsmBackendEL64(const Target &T, StringRef TT,
                                       StringRef CPU);

MCObjectWriter *createOiELFObjectWriter(raw_ostream &OS,
                                          uint8_t OSABI,
                                          bool IsLittleEndian,
                                          bool Is64Bit);
} // End llvm namespace

// Defines symbolic names for Oi registers.  This defines a mapping from
// register name to register number.
#define GET_REGINFO_ENUM
#include "OiGenRegisterInfo.inc"

// Defines symbolic names for the Oi instructions.
#define GET_INSTRINFO_ENUM
#include "OiGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "OiGenSubtargetInfo.inc"

#endif
