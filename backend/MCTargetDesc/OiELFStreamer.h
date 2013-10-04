//=== OiELFStreamer.h - OiELFStreamer ------------------------------===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENCE.TXT for details.
//
//===-------------------------------------------------------------------===//
#ifndef OIELFSTREAMER_H_
#define OIELFSTREAMER_H_

#include "llvm/MC/MCELFStreamer.h"

namespace llvm {
class OiAsmPrinter;
class OiSubtarget;
class MCSymbol;

class OiELFStreamer : public MCELFStreamer {
public:
  OiELFStreamer(MCContext &Context, MCAsmBackend &TAB,
                  raw_ostream &OS, MCCodeEmitter *Emitter,
                  bool RelaxAll, bool NoExecStack)
    : MCELFStreamer(SK_MipsELFStreamer, Context, TAB, OS, Emitter) {
  }

  ~OiELFStreamer() {}
  void emitELFHeaderFlagsCG(const OiSubtarget &Subtarget);
  void emitOiSTOCG(const OiSubtarget &Subtarget,
                     MCSymbol *Sym,
                     unsigned Val);

  static bool classof(const MCStreamer *S) {
    return S->getKind() == SK_MipsELFStreamer;
  }
};

  MCELFStreamer* createOiELFStreamer(MCContext &Context, MCAsmBackend &TAB,
                                       raw_ostream &OS, MCCodeEmitter *Emitter,
                                       bool RelaxAll, bool NoExecStack);
}

#endif /* OIELFSTREAMER_H_ */
