#ifndef MC2IRSTREAMER_H_
#define MC2IRSTREAMER_H_


#include "llvm/ADT/SmallString.h"


namespace llvm{

class MCStreamer;
class MCContext;
class formatted_raw_ostream;
class MCInstPrinter;
class MCAsmBackend;
class MCCodeEmitter;
class Module;

MCStreamer *createMC2IRStreamer(MCContext &Ctx, formatted_raw_ostream &OS,
                                 bool isVerboseAsm,
                                 bool useLoc, bool useCFI,
                                 bool useDwarfDirectory,
                                 MCInstPrinter *InstPrint,
                                 MCCodeEmitter *CE,
                                 MCAsmBackend *TAB,
               
    bool ShowInst);


// Functions used by AsmParser to communicate OI-specific info
 void setMC2IRNumArgs(MCStreamer *s, size_t NumArgs);
 void setMC2IRFrameSize(MCStreamer *s, size_t FrameSize, int FrameRegNo,
                        int ReturnRegNo);
 Module* takeCurrentModule(MCStreamer *s);

}

#endif
