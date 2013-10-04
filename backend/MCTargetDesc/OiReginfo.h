//=== OiReginfo.h - OiReginfo -----------------------------------------===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENCE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef OIREGINFO_H
#define OIREGINFO_H

namespace llvm {
  class MCStreamer;
  class TargetLoweringObjectFile;
  class OiSubtarget;

  class OiReginfo {
    void anchor();
  public:
    OiReginfo() {}

    void emitOiReginfoSectionCG(MCStreamer &OS,
        const TargetLoweringObjectFile &TLOF,
        const OiSubtarget &MST) const;
  };

} // namespace llvm

#endif

