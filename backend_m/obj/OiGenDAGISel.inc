/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the Oi target                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

// *** NOTE: This file is #included into the middle of the target
// *** instruction selector class.  These functions are really methods.

// The main instruction selector code.
SDNode *SelectCode(SDNode *N) {
  // Some target values are emitted as 2 bytes, TARGET_VAL handles
  // this.
  #define TARGET_VAL(X) X & 255, unsigned(X) >> 8
  static const unsigned char MatcherTable[] = {
/*0*/     OPC_SwitchOpcode /*119 cases */, 59|128,5/*699*/,  TARGET_VAL(ISD::STORE),// ->704
/*5*/       OPC_RecordMemRef,
/*6*/       OPC_RecordNode,   // #0 = 'st' chained node
/*7*/       OPC_Scope, 52, /*->61*/ // 2 children in Scope
/*9*/         OPC_MoveChild, 1,
/*11*/        OPC_CheckInteger, 0, 
/*13*/        OPC_CheckType, MVT::i32,
/*15*/        OPC_MoveParent,
/*16*/        OPC_RecordChild2, // #1 = $dst
/*17*/        OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*19*/        OPC_CheckPredicate, 1, // Predicate_store
/*21*/        OPC_Scope, 18, /*->41*/ // 2 children in Scope
/*23*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*25*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$dst #2 #3
/*28*/          OPC_EmitMergeInputChains1_0,
/*29*/          OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*32*/          OPC_MorphNodeTo, TARGET_VAL(Oi::SW), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 4, 2, 3, 
                // Src: (st 0:i32, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 18
                // Dst: (SW ZERO:i32, addr:i32:$dst)
/*41*/        /*Scope*/ 18, /*->60*/
/*42*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*44*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$dst #2 #3
/*47*/          OPC_EmitMergeInputChains1_0,
/*48*/          OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*51*/          OPC_MorphNodeTo, TARGET_VAL(Oi::SW_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 4, 2, 3, 
                // Src: (st 0:i32, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 18
                // Dst: (SW_P8 ZERO:i32, addr:i64:$dst)
/*60*/        0, /*End of Scope*/
/*61*/      /*Scope*/ 0|128,5/*640*/, /*->703*/
/*63*/        OPC_RecordChild1, // #1 = $r
/*64*/        OPC_Scope, 57|128,1/*185*/, /*->252*/ // 6 children in Scope
/*67*/          OPC_CheckChild1Type, MVT::i32,
/*69*/          OPC_RecordChild2, // #2 = $addr
/*70*/          OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*72*/          OPC_Scope, 42, /*->116*/ // 4 children in Scope
/*74*/            OPC_CheckPredicate, 2, // Predicate_truncstore
/*76*/            OPC_Scope, 18, /*->96*/ // 2 children in Scope
/*78*/              OPC_CheckPredicate, 3, // Predicate_truncstorei8
/*80*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*82*/              OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddr16:$addr #3 #4 #5
/*85*/              OPC_EmitMergeInputChains1_0,
/*86*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SbRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st CPU16Regs:i32:$r, addr16:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (SbRxRyOffMemX16 CPU16Regs:i32:$r, addr16:i32:$addr)
/*96*/            /*Scope*/ 18, /*->115*/
/*97*/              OPC_CheckPredicate, 4, // Predicate_truncstorei16
/*99*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*101*/             OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddr16:$addr #3 #4 #5
/*104*/             OPC_EmitMergeInputChains1_0,
/*105*/             OPC_MorphNodeTo, TARGET_VAL(Oi::ShRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st CPU16Regs:i32:$r, addr16:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                    // Dst: (ShRxRyOffMemX16 CPU16Regs:i32:$r, addr16:i32:$addr)
/*115*/           0, /*End of Scope*/
/*116*/         /*Scope*/ 18, /*->135*/
/*117*/           OPC_CheckPredicate, 1, // Predicate_store
/*119*/           OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*121*/           OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddr16:$addr #3 #4 #5
/*124*/           OPC_EmitMergeInputChains1_0,
/*125*/           OPC_MorphNodeTo, TARGET_VAL(Oi::SwRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st CPU16Regs:i32:$r, addr16:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (SwRxRyOffMemX16 CPU16Regs:i32:$r, addr16:i32:$addr)
/*135*/         /*Scope*/ 78, /*->214*/
/*136*/           OPC_CheckPredicate, 2, // Predicate_truncstore
/*138*/           OPC_Scope, 36, /*->176*/ // 2 children in Scope
/*140*/             OPC_CheckPredicate, 3, // Predicate_truncstorei8
/*142*/             OPC_Scope, 15, /*->159*/ // 2 children in Scope
/*144*/               OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*146*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*149*/               OPC_EmitMergeInputChains1_0,
/*150*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SB), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPURegs:i32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (SB CPURegs:i32:$rt, addr:i32:$addr)
/*159*/             /*Scope*/ 15, /*->175*/
/*160*/               OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*162*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*165*/               OPC_EmitMergeInputChains1_0,
/*166*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SB_P8), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPURegs:i32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (SB_P8 CPURegs:i32:$rt, addr:i64:$addr)
/*175*/             0, /*End of Scope*/
/*176*/           /*Scope*/ 36, /*->213*/
/*177*/             OPC_CheckPredicate, 4, // Predicate_truncstorei16
/*179*/             OPC_Scope, 15, /*->196*/ // 2 children in Scope
/*181*/               OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*183*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*186*/               OPC_EmitMergeInputChains1_0,
/*187*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SH), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPURegs:i32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (SH CPURegs:i32:$rt, addr:i32:$addr)
/*196*/             /*Scope*/ 15, /*->212*/
/*197*/               OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*199*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*202*/               OPC_EmitMergeInputChains1_0,
/*203*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SH_P8), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPURegs:i32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (SH_P8 CPURegs:i32:$rt, addr:i64:$addr)
/*212*/             0, /*End of Scope*/
/*213*/           0, /*End of Scope*/
/*214*/         /*Scope*/ 36, /*->251*/
/*215*/           OPC_CheckPredicate, 1, // Predicate_store
/*217*/           OPC_Scope, 15, /*->234*/ // 2 children in Scope
/*219*/             OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*221*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*224*/             OPC_EmitMergeInputChains1_0,
/*225*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SW), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st CPURegs:i32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SW CPURegs:i32:$rt, addr:i32:$addr)
/*234*/           /*Scope*/ 15, /*->250*/
/*235*/             OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*237*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*240*/             OPC_EmitMergeInputChains1_0,
/*241*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SW_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st CPURegs:i32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SW_P8 CPURegs:i32:$rt, addr:i64:$addr)
/*250*/           0, /*End of Scope*/
/*251*/         0, /*End of Scope*/
/*252*/       /*Scope*/ 92, /*->345*/
/*253*/         OPC_CheckChild1Type, MVT::f32,
/*255*/         OPC_Scope, 39, /*->296*/ // 2 children in Scope
/*257*/           OPC_RecordChild2, // #2 = $addr
/*258*/           OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*260*/           OPC_CheckPredicate, 1, // Predicate_store
/*262*/           OPC_Scope, 15, /*->279*/ // 2 children in Scope
/*264*/             OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*266*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*269*/             OPC_EmitMergeInputChains1_0,
/*270*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SWC1_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st FGR32:f32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SWC1_P8 FGR32:f32:$rt, addr:i64:$addr)
/*279*/           /*Scope*/ 15, /*->295*/
/*280*/             OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*282*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*285*/             OPC_EmitMergeInputChains1_0,
/*286*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SWC1), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st FGR32:f32:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SWC1 FGR32:f32:$rt, addr:i32:$addr)
/*295*/           0, /*End of Scope*/
/*296*/         /*Scope*/ 47, /*->344*/
/*297*/           OPC_MoveChild, 2,
/*299*/           OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*302*/           OPC_RecordChild0, // #2 = $base
/*303*/           OPC_RecordChild1, // #3 = $index
/*304*/           OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->324
/*307*/             OPC_MoveParent,
/*308*/             OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*310*/             OPC_CheckPredicate, 1, // Predicate_store
/*312*/             OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPIdx()) && (Subtarget.hasStandardEncoding())
/*314*/             OPC_EmitMergeInputChains1_0,
/*315*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SWXC1), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st FGR32:f32:$fs, (add:i32 CPURegs:i32:$base, CPURegs:i32:$index))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 7
                    // Dst: (SWXC1 FGR32:f32:$fs, CPURegs:i32:$base, CPURegs:i32:$index)
                  /*SwitchType*/ 17,  MVT::i64,// ->343
/*326*/             OPC_MoveParent,
/*327*/             OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*329*/             OPC_CheckPredicate, 1, // Predicate_store
/*331*/             OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*333*/             OPC_EmitMergeInputChains1_0,
/*334*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SWXC1_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st FGR32:f32:$fs, (add:i64 CPU64Regs:i64:$base, CPU64Regs:i64:$index))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 7
                    // Dst: (SWXC1_P8 FGR32:f32:$fs, CPU64Regs:i64:$base, CPU64Regs:i64:$index)
                  0, // EndSwitchType
/*344*/         0, /*End of Scope*/
/*345*/       /*Scope*/ 124, /*->470*/
/*346*/         OPC_CheckChild1Type, MVT::f64,
/*348*/         OPC_Scope, 55, /*->405*/ // 2 children in Scope
/*350*/           OPC_RecordChild2, // #2 = $addr
/*351*/           OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*353*/           OPC_CheckPredicate, 1, // Predicate_store
/*355*/           OPC_Scope, 15, /*->372*/ // 3 children in Scope
/*357*/             OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*359*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*362*/             OPC_EmitMergeInputChains1_0,
/*363*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SDC164_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st FGR64:f64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SDC164_P8 FGR64:f64:$rt, addr:i64:$addr)
/*372*/           /*Scope*/ 15, /*->388*/
/*373*/             OPC_CheckPatternPredicate, 4, // (!Subtarget.isABI_N64()) && (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*375*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*378*/             OPC_EmitMergeInputChains1_0,
/*379*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SDC164), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st FGR64:f64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SDC164 FGR64:f64:$rt, addr:i32:$addr)
/*388*/           /*Scope*/ 15, /*->404*/
/*389*/             OPC_CheckPatternPredicate, 5, // (!Subtarget.isABI_N64()) && (!Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*391*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*394*/             OPC_EmitMergeInputChains1_0,
/*395*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SDC1), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st AFGR64:f64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SDC1 AFGR64:f64:$rt, addr:i32:$addr)
/*404*/           0, /*End of Scope*/
/*405*/         /*Scope*/ 63, /*->469*/
/*406*/           OPC_MoveChild, 2,
/*408*/           OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*411*/           OPC_RecordChild0, // #2 = $base
/*412*/           OPC_RecordChild1, // #3 = $index
/*413*/           OPC_SwitchType /*2 cases */, 33,  MVT::i32,// ->449
/*416*/             OPC_MoveParent,
/*417*/             OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*419*/             OPC_CheckPredicate, 1, // Predicate_store
/*421*/             OPC_Scope, 12, /*->435*/ // 2 children in Scope
/*423*/               OPC_CheckPatternPredicate, 6, // (Subtarget.hasOi32r2()) && (!Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*425*/               OPC_EmitMergeInputChains1_0,
/*426*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SDXC1), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (st AFGR64:f64:$fs, (add:i32 CPURegs:i32:$base, CPURegs:i32:$index))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 7
                      // Dst: (SDXC1 AFGR64:f64:$fs, CPURegs:i32:$base, CPURegs:i32:$index)
/*435*/             /*Scope*/ 12, /*->448*/
/*436*/               OPC_CheckPatternPredicate, 7, // (Subtarget.hasOi64()) && (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*438*/               OPC_EmitMergeInputChains1_0,
/*439*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SDXC164), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (st FGR64:f64:$fs, (add:i32 CPURegs:i32:$base, CPURegs:i32:$index))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 7
                      // Dst: (SDXC164 FGR64:f64:$fs, CPURegs:i32:$base, CPURegs:i32:$index)
/*448*/             0, /*End of Scope*/
                  /*SwitchType*/ 17,  MVT::i64,// ->468
/*451*/             OPC_MoveParent,
/*452*/             OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*454*/             OPC_CheckPredicate, 1, // Predicate_store
/*456*/             OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*458*/             OPC_EmitMergeInputChains1_0,
/*459*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SDXC164_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st FGR64:f64:$fs, (add:i64 CPU64Regs:i64:$base, CPU64Regs:i64:$index))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 7
                    // Dst: (SDXC164_P8 FGR64:f64:$fs, CPU64Regs:i64:$base, CPU64Regs:i64:$index)
                  0, // EndSwitchType
/*469*/         0, /*End of Scope*/
/*470*/       /*Scope*/ 32|128,1/*160*/, /*->632*/
/*472*/         OPC_CheckChild1Type, MVT::i64,
/*474*/         OPC_RecordChild2, // #2 = $addr
/*475*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*477*/         OPC_Scope, 115, /*->594*/ // 2 children in Scope
/*479*/           OPC_CheckPredicate, 2, // Predicate_truncstore
/*481*/           OPC_Scope, 36, /*->519*/ // 3 children in Scope
/*483*/             OPC_CheckPredicate, 3, // Predicate_truncstorei8
/*485*/             OPC_Scope, 15, /*->502*/ // 2 children in Scope
/*487*/               OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*489*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*492*/               OPC_EmitMergeInputChains1_0,
/*493*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SB64), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (SB64 CPU64Regs:i64:$rt, addr:i32:$addr)
/*502*/             /*Scope*/ 15, /*->518*/
/*503*/               OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*505*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*508*/               OPC_EmitMergeInputChains1_0,
/*509*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SB64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (SB64_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*518*/             0, /*End of Scope*/
/*519*/           /*Scope*/ 36, /*->556*/
/*520*/             OPC_CheckPredicate, 4, // Predicate_truncstorei16
/*522*/             OPC_Scope, 15, /*->539*/ // 2 children in Scope
/*524*/               OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*526*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*529*/               OPC_EmitMergeInputChains1_0,
/*530*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SH64), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (SH64 CPU64Regs:i64:$rt, addr:i32:$addr)
/*539*/             /*Scope*/ 15, /*->555*/
/*540*/               OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*542*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*545*/               OPC_EmitMergeInputChains1_0,
/*546*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SH64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (SH64_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*555*/             0, /*End of Scope*/
/*556*/           /*Scope*/ 36, /*->593*/
/*557*/             OPC_CheckPredicate, 5, // Predicate_truncstorei32
/*559*/             OPC_Scope, 15, /*->576*/ // 2 children in Scope
/*561*/               OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*563*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*566*/               OPC_EmitMergeInputChains1_0,
/*567*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SW64), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 13
                      // Dst: (SW64 CPU64Regs:i64:$rt, addr:i32:$addr)
/*576*/             /*Scope*/ 15, /*->592*/
/*577*/               OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*579*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*582*/               OPC_EmitMergeInputChains1_0,
/*583*/               OPC_MorphNodeTo, TARGET_VAL(Oi::SW64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                      // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 13
                      // Dst: (SW64_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*592*/             0, /*End of Scope*/
/*593*/           0, /*End of Scope*/
/*594*/         /*Scope*/ 36, /*->631*/
/*595*/           OPC_CheckPredicate, 1, // Predicate_store
/*597*/           OPC_Scope, 15, /*->614*/ // 2 children in Scope
/*599*/             OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*601*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*604*/             OPC_EmitMergeInputChains1_0,
/*605*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SD), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SD CPU64Regs:i64:$rt, addr:i32:$addr)
/*614*/           /*Scope*/ 15, /*->630*/
/*615*/             OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*617*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*620*/             OPC_EmitMergeInputChains1_0,
/*621*/             OPC_MorphNodeTo, TARGET_VAL(Oi::SD_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st CPU64Regs:i64:$rt, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (SD_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*630*/           0, /*End of Scope*/
/*631*/         0, /*End of Scope*/
/*632*/       /*Scope*/ 34, /*->667*/
/*633*/         OPC_CheckChild1Type, MVT::v2i16,
/*635*/         OPC_RecordChild2, // #2 = $a
/*636*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*638*/         OPC_CheckPredicate, 1, // Predicate_store
/*640*/         OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*642*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$a #3 #4
/*645*/         OPC_EmitMergeInputChains1_0,
/*646*/         OPC_EmitInteger, MVT::i32, Oi::CPURegsRegClassID,
/*649*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 5,  // Results = #6
/*658*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SW), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 6, 3, 4, 
                // Src: (st DSPRegs:v2i16:$val, addr:iPTR:$a)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                // Dst: (SW (COPY_TO_REGCLASS:i32 DSPRegs:v2i16:$val, CPURegs:i32), addr:i32:$a)
/*667*/       /*Scope*/ 34, /*->702*/
/*668*/         OPC_CheckChild1Type, MVT::v4i8,
/*670*/         OPC_RecordChild2, // #2 = $a
/*671*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*673*/         OPC_CheckPredicate, 1, // Predicate_store
/*675*/         OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*677*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$a #3 #4
/*680*/         OPC_EmitMergeInputChains1_0,
/*681*/         OPC_EmitInteger, MVT::i32, Oi::CPURegsRegClassID,
/*684*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 5,  // Results = #6
/*693*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SW), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 6, 3, 4, 
                // Src: (st DSPRegs:v4i8:$val, addr:iPTR:$a)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                // Dst: (SW (COPY_TO_REGCLASS:i32 DSPRegs:v4i8:$val, CPURegs:i32), addr:i32:$a)
/*702*/       0, /*End of Scope*/
/*703*/     0, /*End of Scope*/
          /*SwitchOpcode*/ 31|128,9/*1183*/,  TARGET_VAL(ISD::LOAD),// ->1891
/*708*/     OPC_RecordMemRef,
/*709*/     OPC_RecordNode,   // #0 = 'ld' chained node
/*710*/     OPC_Scope, 115|128,7/*1011*/, /*->1724*/ // 3 children in Scope
/*713*/       OPC_RecordChild1, // #1 = $addr
/*714*/       OPC_CheckPredicate, 6, // Predicate_unindexedload
/*716*/       OPC_Scope, 22, /*->740*/ // 21 children in Scope
/*718*/         OPC_CheckPredicate, 7, // Predicate_sextload
/*720*/         OPC_CheckPredicate, 8, // Predicate_sextloadi8
/*722*/         OPC_CheckType, MVT::i32,
/*724*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*726*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddr16:$addr #2 #3 #4
/*729*/         OPC_EmitMergeInputChains1_0,
/*730*/         OPC_MorphNodeTo, TARGET_VAL(Oi::LbRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:i32 addr16:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 16
                // Dst: (LbRxRyOffMemX16:i32 addr16:i32:$addr)
/*740*/       /*Scope*/ 22, /*->763*/
/*741*/         OPC_CheckPredicate, 9, // Predicate_zextload
/*743*/         OPC_CheckPredicate, 10, // Predicate_zextloadi8
/*745*/         OPC_CheckType, MVT::i32,
/*747*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*749*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddr16:$addr #2 #3 #4
/*752*/         OPC_EmitMergeInputChains1_0,
/*753*/         OPC_MorphNodeTo, TARGET_VAL(Oi::LbuRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:i32 addr16:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 16
                // Dst: (LbuRxRyOffMemX16:i32 addr16:i32:$addr)
/*763*/       /*Scope*/ 22, /*->786*/
/*764*/         OPC_CheckPredicate, 7, // Predicate_sextload
/*766*/         OPC_CheckPredicate, 11, // Predicate_sextloadi16
/*768*/         OPC_CheckType, MVT::i32,
/*770*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*772*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddr16:$addr #2 #3 #4
/*775*/         OPC_EmitMergeInputChains1_0,
/*776*/         OPC_MorphNodeTo, TARGET_VAL(Oi::LhRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:i32 addr16:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 16
                // Dst: (LhRxRyOffMemX16:i32 addr16:i32:$addr)
/*786*/       /*Scope*/ 22, /*->809*/
/*787*/         OPC_CheckPredicate, 9, // Predicate_zextload
/*789*/         OPC_CheckPredicate, 12, // Predicate_zextloadi16
/*791*/         OPC_CheckType, MVT::i32,
/*793*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*795*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddr16:$addr #2 #3 #4
/*798*/         OPC_EmitMergeInputChains1_0,
/*799*/         OPC_MorphNodeTo, TARGET_VAL(Oi::LhuRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:i32 addr16:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 16
                // Dst: (LhuRxRyOffMemX16:i32 addr16:i32:$addr)
/*809*/       /*Scope*/ 20, /*->830*/
/*810*/         OPC_CheckPredicate, 13, // Predicate_load
/*812*/         OPC_CheckType, MVT::i32,
/*814*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*816*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddr16:$addr #2 #3 #4
/*819*/         OPC_EmitMergeInputChains1_0,
/*820*/         OPC_MorphNodeTo, TARGET_VAL(Oi::LwRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:i32 addr16:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                // Dst: (LwRxRyOffMemX16:i32 addr16:i32:$addr)
/*830*/       /*Scope*/ 44, /*->875*/
/*831*/         OPC_CheckPredicate, 14, // Predicate_extload
/*833*/         OPC_CheckType, MVT::i32,
/*835*/         OPC_Scope, 18, /*->855*/ // 2 children in Scope
/*837*/           OPC_CheckPredicate, 15, // Predicate_extloadi8
/*839*/           OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*841*/           OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddr16:$src #2 #3 #4
/*844*/           OPC_EmitMergeInputChains1_0,
/*845*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LbuRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i32 addr16:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 16
                  // Dst: (LbuRxRyOffMemX16:i32 addr16:i32:$src)
/*855*/         /*Scope*/ 18, /*->874*/
/*856*/           OPC_CheckPredicate, 16, // Predicate_extloadi16
/*858*/           OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*860*/           OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddr16:$src #2 #3 #4
/*863*/           OPC_EmitMergeInputChains1_0,
/*864*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LhuRxRyOffMemX16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i32 addr16:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 16
                  // Dst: (LhuRxRyOffMemX16:i32 addr16:i32:$src)
/*874*/         0, /*End of Scope*/
/*875*/       /*Scope*/ 40, /*->916*/
/*876*/         OPC_CheckPredicate, 7, // Predicate_sextload
/*878*/         OPC_CheckPredicate, 8, // Predicate_sextloadi8
/*880*/         OPC_CheckType, MVT::i32,
/*882*/         OPC_Scope, 15, /*->899*/ // 2 children in Scope
/*884*/           OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*886*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*889*/           OPC_EmitMergeInputChains1_0,
/*890*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                  // Dst: (LB:i32 addr:i32:$addr)
/*899*/         /*Scope*/ 15, /*->915*/
/*900*/           OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*902*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*905*/           OPC_EmitMergeInputChains1_0,
/*906*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LB_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                  // Dst: (LB_P8:i32 addr:i64:$addr)
/*915*/         0, /*End of Scope*/
/*916*/       /*Scope*/ 40, /*->957*/
/*917*/         OPC_CheckPredicate, 9, // Predicate_zextload
/*919*/         OPC_CheckPredicate, 10, // Predicate_zextloadi8
/*921*/         OPC_CheckType, MVT::i32,
/*923*/         OPC_Scope, 15, /*->940*/ // 2 children in Scope
/*925*/           OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*927*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*930*/           OPC_EmitMergeInputChains1_0,
/*931*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LBu), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                  // Dst: (LBu:i32 addr:i32:$addr)
/*940*/         /*Scope*/ 15, /*->956*/
/*941*/           OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*943*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*946*/           OPC_EmitMergeInputChains1_0,
/*947*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LBu_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                  // Dst: (LBu_P8:i32 addr:i64:$addr)
/*956*/         0, /*End of Scope*/
/*957*/       /*Scope*/ 40, /*->998*/
/*958*/         OPC_CheckPredicate, 7, // Predicate_sextload
/*960*/         OPC_CheckPredicate, 11, // Predicate_sextloadi16
/*962*/         OPC_CheckType, MVT::i32,
/*964*/         OPC_Scope, 15, /*->981*/ // 2 children in Scope
/*966*/           OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*968*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*971*/           OPC_EmitMergeInputChains1_0,
/*972*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                  // Dst: (LH:i32 addr:i32:$addr)
/*981*/         /*Scope*/ 15, /*->997*/
/*982*/           OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*984*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*987*/           OPC_EmitMergeInputChains1_0,
/*988*/           OPC_MorphNodeTo, TARGET_VAL(Oi::LH_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                  // Dst: (LH_P8:i32 addr:i64:$addr)
/*997*/         0, /*End of Scope*/
/*998*/       /*Scope*/ 40, /*->1039*/
/*999*/         OPC_CheckPredicate, 9, // Predicate_zextload
/*1001*/        OPC_CheckPredicate, 12, // Predicate_zextloadi16
/*1003*/        OPC_CheckType, MVT::i32,
/*1005*/        OPC_Scope, 15, /*->1022*/ // 2 children in Scope
/*1007*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1009*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1012*/          OPC_EmitMergeInputChains1_0,
/*1013*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LHu), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                  // Dst: (LHu:i32 addr:i32:$addr)
/*1022*/        /*Scope*/ 15, /*->1038*/
/*1023*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1025*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1028*/          OPC_EmitMergeInputChains1_0,
/*1029*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LHu_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                  // Dst: (LHu_P8:i32 addr:i64:$addr)
/*1038*/        0, /*End of Scope*/
/*1039*/      /*Scope*/ 38, /*->1078*/
/*1040*/        OPC_CheckPredicate, 13, // Predicate_load
/*1042*/        OPC_CheckType, MVT::i32,
/*1044*/        OPC_Scope, 15, /*->1061*/ // 2 children in Scope
/*1046*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1048*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1051*/          OPC_EmitMergeInputChains1_0,
/*1052*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LW), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LW:i32 addr:i32:$addr)
/*1061*/        /*Scope*/ 15, /*->1077*/
/*1062*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1064*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1067*/          OPC_EmitMergeInputChains1_0,
/*1068*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LW_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LW_P8:i32 addr:i64:$addr)
/*1077*/        0, /*End of Scope*/
/*1078*/      /*Scope*/ 114, /*->1193*/
/*1079*/        OPC_CheckPredicate, 14, // Predicate_extload
/*1081*/        OPC_CheckType, MVT::i32,
/*1083*/        OPC_Scope, 17, /*->1102*/ // 6 children in Scope
/*1085*/          OPC_CheckPredicate, 17, // Predicate_extloadi1
/*1087*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1089*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1092*/          OPC_EmitMergeInputChains1_0,
/*1093*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LBu), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LBu:i32 addr:i32:$src)
/*1102*/        /*Scope*/ 17, /*->1120*/
/*1103*/          OPC_CheckPredicate, 15, // Predicate_extloadi8
/*1105*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1107*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1110*/          OPC_EmitMergeInputChains1_0,
/*1111*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LBu), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LBu:i32 addr:i32:$src)
/*1120*/        /*Scope*/ 17, /*->1138*/
/*1121*/          OPC_CheckPredicate, 16, // Predicate_extloadi16
/*1123*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1125*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1128*/          OPC_EmitMergeInputChains1_0,
/*1129*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LHu), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LHu:i32 addr:i32:$src)
/*1138*/        /*Scope*/ 17, /*->1156*/
/*1139*/          OPC_CheckPredicate, 17, // Predicate_extloadi1
/*1141*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1143*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1146*/          OPC_EmitMergeInputChains1_0,
/*1147*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LBu_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LBu_P8:i32 addr:i64:$src)
/*1156*/        /*Scope*/ 17, /*->1174*/
/*1157*/          OPC_CheckPredicate, 15, // Predicate_extloadi8
/*1159*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1161*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1164*/          OPC_EmitMergeInputChains1_0,
/*1165*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LBu_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LBu_P8:i32 addr:i64:$src)
/*1174*/        /*Scope*/ 17, /*->1192*/
/*1175*/          OPC_CheckPredicate, 16, // Predicate_extloadi16
/*1177*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1179*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1182*/          OPC_EmitMergeInputChains1_0,
/*1183*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LHu_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LHu_P8:i32 addr:i64:$src)
/*1192*/        0, /*End of Scope*/
/*1193*/      /*Scope*/ 40, /*->1234*/
/*1194*/        OPC_CheckPredicate, 7, // Predicate_sextload
/*1196*/        OPC_CheckPredicate, 8, // Predicate_sextloadi8
/*1198*/        OPC_CheckType, MVT::i64,
/*1200*/        OPC_Scope, 15, /*->1217*/ // 2 children in Scope
/*1202*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1204*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1207*/          OPC_EmitMergeInputChains1_0,
/*1208*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LB64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                  // Dst: (LB64:i64 addr:i32:$addr)
/*1217*/        /*Scope*/ 15, /*->1233*/
/*1218*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1220*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1223*/          OPC_EmitMergeInputChains1_0,
/*1224*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LB64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                  // Dst: (LB64_P8:i64 addr:i64:$addr)
/*1233*/        0, /*End of Scope*/
/*1234*/      /*Scope*/ 40, /*->1275*/
/*1235*/        OPC_CheckPredicate, 9, // Predicate_zextload
/*1237*/        OPC_CheckPredicate, 10, // Predicate_zextloadi8
/*1239*/        OPC_CheckType, MVT::i64,
/*1241*/        OPC_Scope, 15, /*->1258*/ // 2 children in Scope
/*1243*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1245*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1248*/          OPC_EmitMergeInputChains1_0,
/*1249*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LBu64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                  // Dst: (LBu64:i64 addr:i32:$addr)
/*1258*/        /*Scope*/ 15, /*->1274*/
/*1259*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1261*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1264*/          OPC_EmitMergeInputChains1_0,
/*1265*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LBu64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                  // Dst: (LBu64_P8:i64 addr:i64:$addr)
/*1274*/        0, /*End of Scope*/
/*1275*/      /*Scope*/ 40, /*->1316*/
/*1276*/        OPC_CheckPredicate, 7, // Predicate_sextload
/*1278*/        OPC_CheckPredicate, 11, // Predicate_sextloadi16
/*1280*/        OPC_CheckType, MVT::i64,
/*1282*/        OPC_Scope, 15, /*->1299*/ // 2 children in Scope
/*1284*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1286*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1289*/          OPC_EmitMergeInputChains1_0,
/*1290*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LH64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                  // Dst: (LH64:i64 addr:i32:$addr)
/*1299*/        /*Scope*/ 15, /*->1315*/
/*1300*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1302*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1305*/          OPC_EmitMergeInputChains1_0,
/*1306*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LH64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                  // Dst: (LH64_P8:i64 addr:i64:$addr)
/*1315*/        0, /*End of Scope*/
/*1316*/      /*Scope*/ 40, /*->1357*/
/*1317*/        OPC_CheckPredicate, 9, // Predicate_zextload
/*1319*/        OPC_CheckPredicate, 12, // Predicate_zextloadi16
/*1321*/        OPC_CheckType, MVT::i64,
/*1323*/        OPC_Scope, 15, /*->1340*/ // 2 children in Scope
/*1325*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1327*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1330*/          OPC_EmitMergeInputChains1_0,
/*1331*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LHu64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                  // Dst: (LHu64:i64 addr:i32:$addr)
/*1340*/        /*Scope*/ 15, /*->1356*/
/*1341*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1343*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1346*/          OPC_EmitMergeInputChains1_0,
/*1347*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LHu64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                  // Dst: (LHu64_P8:i64 addr:i64:$addr)
/*1356*/        0, /*End of Scope*/
/*1357*/      /*Scope*/ 40, /*->1398*/
/*1358*/        OPC_CheckPredicate, 7, // Predicate_sextload
/*1360*/        OPC_CheckPredicate, 18, // Predicate_sextloadi32
/*1362*/        OPC_CheckType, MVT::i64,
/*1364*/        OPC_Scope, 15, /*->1381*/ // 2 children in Scope
/*1366*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1368*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1371*/          OPC_EmitMergeInputChains1_0,
/*1372*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LW64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi32>> - Complexity = 13
                  // Dst: (LW64:i64 addr:i32:$addr)
/*1381*/        /*Scope*/ 15, /*->1397*/
/*1382*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1384*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1387*/          OPC_EmitMergeInputChains1_0,
/*1388*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LW64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi32>> - Complexity = 13
                  // Dst: (LW64_P8:i64 addr:i64:$addr)
/*1397*/        0, /*End of Scope*/
/*1398*/      /*Scope*/ 40, /*->1439*/
/*1399*/        OPC_CheckPredicate, 9, // Predicate_zextload
/*1401*/        OPC_CheckPredicate, 19, // Predicate_zextloadi32
/*1403*/        OPC_CheckType, MVT::i64,
/*1405*/        OPC_Scope, 15, /*->1422*/ // 2 children in Scope
/*1407*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1409*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1412*/          OPC_EmitMergeInputChains1_0,
/*1413*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LWu64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi32>> - Complexity = 13
                  // Dst: (LWu64:i64 addr:i32:$addr)
/*1422*/        /*Scope*/ 15, /*->1438*/
/*1423*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1425*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1428*/          OPC_EmitMergeInputChains1_0,
/*1429*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LWu64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi32>> - Complexity = 13
                  // Dst: (LWu64_P8:i64 addr:i64:$addr)
/*1438*/        0, /*End of Scope*/
/*1439*/      /*Scope*/ 38, /*->1478*/
/*1440*/        OPC_CheckPredicate, 13, // Predicate_load
/*1442*/        OPC_CheckType, MVT::i64,
/*1444*/        OPC_Scope, 15, /*->1461*/ // 2 children in Scope
/*1446*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1448*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1451*/          OPC_EmitMergeInputChains1_0,
/*1452*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LD), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LD:i64 addr:i32:$addr)
/*1461*/        /*Scope*/ 15, /*->1477*/
/*1462*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1464*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1467*/          OPC_EmitMergeInputChains1_0,
/*1468*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LD_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LD_P8:i64 addr:i64:$addr)
/*1477*/        0, /*End of Scope*/
/*1478*/      /*Scope*/ 22|128,1/*150*/, /*->1630*/
/*1480*/        OPC_CheckPredicate, 14, // Predicate_extload
/*1482*/        OPC_CheckType, MVT::i64,
/*1484*/        OPC_Scope, 17, /*->1503*/ // 8 children in Scope
/*1486*/          OPC_CheckPredicate, 17, // Predicate_extloadi1
/*1488*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1490*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1493*/          OPC_EmitMergeInputChains1_0,
/*1494*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LB64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LB64:i64 addr:i32:$src)
/*1503*/        /*Scope*/ 17, /*->1521*/
/*1504*/          OPC_CheckPredicate, 15, // Predicate_extloadi8
/*1506*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1508*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1511*/          OPC_EmitMergeInputChains1_0,
/*1512*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LB64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LB64:i64 addr:i32:$src)
/*1521*/        /*Scope*/ 17, /*->1539*/
/*1522*/          OPC_CheckPredicate, 16, // Predicate_extloadi16
/*1524*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1526*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1529*/          OPC_EmitMergeInputChains1_0,
/*1530*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LH64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LH64:i64 addr:i32:$src)
/*1539*/        /*Scope*/ 17, /*->1557*/
/*1540*/          OPC_CheckPredicate, 20, // Predicate_extloadi32
/*1542*/          OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1544*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1547*/          OPC_EmitMergeInputChains1_0,
/*1548*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LW64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi32>> - Complexity = 13
                  // Dst: (LW64:i64 addr:i32:$src)
/*1557*/        /*Scope*/ 17, /*->1575*/
/*1558*/          OPC_CheckPredicate, 17, // Predicate_extloadi1
/*1560*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1562*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1565*/          OPC_EmitMergeInputChains1_0,
/*1566*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LB64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LB64_P8:i64 addr:i64:$src)
/*1575*/        /*Scope*/ 17, /*->1593*/
/*1576*/          OPC_CheckPredicate, 15, // Predicate_extloadi8
/*1578*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1580*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1583*/          OPC_EmitMergeInputChains1_0,
/*1584*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LB64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LB64_P8:i64 addr:i64:$src)
/*1593*/        /*Scope*/ 17, /*->1611*/
/*1594*/          OPC_CheckPredicate, 16, // Predicate_extloadi16
/*1596*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1598*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1601*/          OPC_EmitMergeInputChains1_0,
/*1602*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LH64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LH64_P8:i64 addr:i64:$src)
/*1611*/        /*Scope*/ 17, /*->1629*/
/*1612*/          OPC_CheckPredicate, 20, // Predicate_extloadi32
/*1614*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1616*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*1619*/          OPC_EmitMergeInputChains1_0,
/*1620*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LW64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi32>> - Complexity = 13
                  // Dst: (LW64_P8:i64 addr:i64:$src)
/*1629*/        0, /*End of Scope*/
/*1630*/      /*Scope*/ 92, /*->1723*/
/*1631*/        OPC_CheckPredicate, 13, // Predicate_load
/*1633*/        OPC_SwitchType /*2 cases */, 34,  MVT::f32,// ->1670
/*1636*/          OPC_Scope, 15, /*->1653*/ // 2 children in Scope
/*1638*/            OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1640*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1643*/            OPC_EmitMergeInputChains1_0,
/*1644*/            OPC_MorphNodeTo, TARGET_VAL(Oi::LWC1_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:f32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                    // Dst: (LWC1_P8:f32 addr:i64:$addr)
/*1653*/          /*Scope*/ 15, /*->1669*/
/*1654*/            OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1656*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1659*/            OPC_EmitMergeInputChains1_0,
/*1660*/            OPC_MorphNodeTo, TARGET_VAL(Oi::LWC1), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:f32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                    // Dst: (LWC1:f32 addr:i32:$addr)
/*1669*/          0, /*End of Scope*/
                /*SwitchType*/ 50,  MVT::f64,// ->1722
/*1672*/          OPC_Scope, 15, /*->1689*/ // 3 children in Scope
/*1674*/            OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1676*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1679*/            OPC_EmitMergeInputChains1_0,
/*1680*/            OPC_MorphNodeTo, TARGET_VAL(Oi::LDC164_P8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:f64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                    // Dst: (LDC164_P8:f64 addr:i64:$addr)
/*1689*/          /*Scope*/ 15, /*->1705*/
/*1690*/            OPC_CheckPatternPredicate, 4, // (!Subtarget.isABI_N64()) && (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*1692*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1695*/            OPC_EmitMergeInputChains1_0,
/*1696*/            OPC_MorphNodeTo, TARGET_VAL(Oi::LDC164), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:f64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                    // Dst: (LDC164:f64 addr:i32:$addr)
/*1705*/          /*Scope*/ 15, /*->1721*/
/*1706*/            OPC_CheckPatternPredicate, 5, // (!Subtarget.isABI_N64()) && (!Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*1708*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*1711*/            OPC_EmitMergeInputChains1_0,
/*1712*/            OPC_MorphNodeTo, TARGET_VAL(Oi::LDC1), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:f64 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                    // Dst: (LDC1:f64 addr:i32:$addr)
/*1721*/          0, /*End of Scope*/
                0, // EndSwitchType
/*1723*/      0, /*End of Scope*/
/*1724*/    /*Scope*/ 99, /*->1824*/
/*1725*/      OPC_MoveChild, 1,
/*1727*/      OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*1730*/      OPC_RecordChild0, // #1 = $base
/*1731*/      OPC_RecordChild1, // #2 = $index
/*1732*/      OPC_SwitchType /*2 cases */, 51,  MVT::i32,// ->1786
/*1735*/        OPC_MoveParent,
/*1736*/        OPC_CheckPredicate, 6, // Predicate_unindexedload
/*1738*/        OPC_CheckPredicate, 13, // Predicate_load
/*1740*/        OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->1755
/*1743*/          OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPIdx()) && (Subtarget.hasStandardEncoding())
/*1745*/          OPC_EmitMergeInputChains1_0,
/*1746*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LWXC1), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:f32 (add:i32 CPURegs:i32:$base, CPURegs:i32:$index))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 7
                  // Dst: (LWXC1:f32 CPURegs:i32:$base, CPURegs:i32:$index)
                /*SwitchType*/ 28,  MVT::f64,// ->1785
/*1757*/          OPC_Scope, 12, /*->1771*/ // 2 children in Scope
/*1759*/            OPC_CheckPatternPredicate, 6, // (Subtarget.hasOi32r2()) && (!Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*1761*/            OPC_EmitMergeInputChains1_0,
/*1762*/            OPC_MorphNodeTo, TARGET_VAL(Oi::LDXC1), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:f64 (add:i32 CPURegs:i32:$base, CPURegs:i32:$index))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 7
                    // Dst: (LDXC1:f64 CPURegs:i32:$base, CPURegs:i32:$index)
/*1771*/          /*Scope*/ 12, /*->1784*/
/*1772*/            OPC_CheckPatternPredicate, 7, // (Subtarget.hasOi64()) && (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1774*/            OPC_EmitMergeInputChains1_0,
/*1775*/            OPC_MorphNodeTo, TARGET_VAL(Oi::LDXC164), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:f64 (add:i32 CPURegs:i32:$base, CPURegs:i32:$index))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 7
                    // Dst: (LDXC164:f64 CPURegs:i32:$base, CPURegs:i32:$index)
/*1784*/          0, /*End of Scope*/
                0, // EndSwitchType
              /*SwitchType*/ 35,  MVT::i64,// ->1823
/*1788*/        OPC_MoveParent,
/*1789*/        OPC_CheckPredicate, 6, // Predicate_unindexedload
/*1791*/        OPC_CheckPredicate, 13, // Predicate_load
/*1793*/        OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->1808
/*1796*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1798*/          OPC_EmitMergeInputChains1_0,
/*1799*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LWXC1_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:f32 (add:i64 CPU64Regs:i64:$base, CPU64Regs:i64:$index))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 7
                  // Dst: (LWXC1_P8:f32 CPU64Regs:i64:$base, CPU64Regs:i64:$index)
                /*SwitchType*/ 12,  MVT::f64,// ->1822
/*1810*/          OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1812*/          OPC_EmitMergeInputChains1_0,
/*1813*/          OPC_MorphNodeTo, TARGET_VAL(Oi::LDXC164_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:f64 (add:i64 CPU64Regs:i64:$base, CPU64Regs:i64:$index))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 7
                  // Dst: (LDXC164_P8:f64 CPU64Regs:i64:$base, CPU64Regs:i64:$index)
                0, // EndSwitchType
              0, // EndSwitchType
/*1824*/    /*Scope*/ 65, /*->1890*/
/*1825*/      OPC_RecordChild1, // #1 = $a
/*1826*/      OPC_CheckPredicate, 6, // Predicate_unindexedload
/*1828*/      OPC_CheckPredicate, 13, // Predicate_load
/*1830*/      OPC_SwitchType /*2 cases */, 27,  MVT::v2i16,// ->1860
/*1833*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*1835*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$a #2 #3
/*1838*/        OPC_EmitMergeInputChains1_0,
/*1839*/        OPC_EmitNode, TARGET_VAL(Oi::LW), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3,  // Results = #4
/*1848*/        OPC_EmitInteger, MVT::i32, Oi::DSPRegsRegClassID,
/*1851*/        OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 4, 5, 
                // Src: (ld:v2i16 addr:iPTR:$a)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (COPY_TO_REGCLASS:v2i16 (LW:i32 addr:i32:$a), DSPRegs:v4i8)
              /*SwitchType*/ 27,  MVT::v4i8,// ->1889
/*1862*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*1864*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$a #2 #3
/*1867*/        OPC_EmitMergeInputChains1_0,
/*1868*/        OPC_EmitNode, TARGET_VAL(Oi::LW), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3,  // Results = #4
/*1877*/        OPC_EmitInteger, MVT::i32, Oi::DSPRegsRegClassID,
/*1880*/        OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 4, 5, 
                // Src: (ld:v4i8 addr:iPTR:$a)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (COPY_TO_REGCLASS:v4i8 (LW:i32 addr:i32:$a), DSPRegs:v4i8)
              0, // EndSwitchType
/*1890*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 82,  TARGET_VAL(OiISD::LWL),// ->1976
/*1894*/    OPC_RecordMemRef,
/*1895*/    OPC_RecordNode,   // #0 = 'OiLWL' chained node
/*1896*/    OPC_RecordChild1, // #1 = $addr
/*1897*/    OPC_RecordChild2, // #2 = $src
/*1898*/    OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->1937
/*1901*/      OPC_Scope, 16, /*->1919*/ // 2 children in Scope
/*1903*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1905*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*1908*/        OPC_EmitMergeInputChains1_0,
/*1909*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWL), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWL:i32 addr:iPTR:$addr, CPURegs:i32:$src) - Complexity = 12
                // Dst: (LWL:i32 addr:i32:$addr, CPURegs:i32:$src)
/*1919*/      /*Scope*/ 16, /*->1936*/
/*1920*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1922*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*1925*/        OPC_EmitMergeInputChains1_0,
/*1926*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWL_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWL:i32 addr:iPTR:$addr, CPURegs:i32:$src) - Complexity = 12
                // Dst: (LWL_P8:i32 addr:i64:$addr, CPURegs:i32:$src)
/*1936*/      0, /*End of Scope*/
            /*SwitchType*/ 36,  MVT::i64,// ->1975
/*1939*/      OPC_Scope, 16, /*->1957*/ // 2 children in Scope
/*1941*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1943*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*1946*/        OPC_EmitMergeInputChains1_0,
/*1947*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWL64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWL:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
                // Dst: (LWL64:i64 addr:i32:$addr, CPU64Regs:i64:$src)
/*1957*/      /*Scope*/ 16, /*->1974*/
/*1958*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1960*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*1963*/        OPC_EmitMergeInputChains1_0,
/*1964*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWL64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWL:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
                // Dst: (LWL64_P8:i64 addr:i64:$addr, CPU64Regs:i64:$src)
/*1974*/      0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 82,  TARGET_VAL(OiISD::LWR),// ->2061
/*1979*/    OPC_RecordMemRef,
/*1980*/    OPC_RecordNode,   // #0 = 'OiLWR' chained node
/*1981*/    OPC_RecordChild1, // #1 = $addr
/*1982*/    OPC_RecordChild2, // #2 = $src
/*1983*/    OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->2022
/*1986*/      OPC_Scope, 16, /*->2004*/ // 2 children in Scope
/*1988*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*1990*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*1993*/        OPC_EmitMergeInputChains1_0,
/*1994*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWR), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWR:i32 addr:iPTR:$addr, CPURegs:i32:$src) - Complexity = 12
                // Dst: (LWR:i32 addr:i32:$addr, CPURegs:i32:$src)
/*2004*/      /*Scope*/ 16, /*->2021*/
/*2005*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2007*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*2010*/        OPC_EmitMergeInputChains1_0,
/*2011*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWR_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWR:i32 addr:iPTR:$addr, CPURegs:i32:$src) - Complexity = 12
                // Dst: (LWR_P8:i32 addr:i64:$addr, CPURegs:i32:$src)
/*2021*/      0, /*End of Scope*/
            /*SwitchType*/ 36,  MVT::i64,// ->2060
/*2024*/      OPC_Scope, 16, /*->2042*/ // 2 children in Scope
/*2026*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2028*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*2031*/        OPC_EmitMergeInputChains1_0,
/*2032*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWR64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWR:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
                // Dst: (LWR64:i64 addr:i32:$addr, CPU64Regs:i64:$src)
/*2042*/      /*Scope*/ 16, /*->2059*/
/*2043*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2045*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*2048*/        OPC_EmitMergeInputChains1_0,
/*2049*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LWR64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
                // Src: (OiLWR:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
                // Dst: (LWR64_P8:i64 addr:i64:$addr, CPU64Regs:i64:$src)
/*2059*/      0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 81,  TARGET_VAL(OiISD::SWL),// ->2145
/*2064*/    OPC_RecordMemRef,
/*2065*/    OPC_RecordNode,   // #0 = 'OiSWL' chained node
/*2066*/    OPC_RecordChild1, // #1 = $rt
/*2067*/    OPC_Scope, 37, /*->2106*/ // 2 children in Scope
/*2069*/      OPC_CheckChild1Type, MVT::i32,
/*2071*/      OPC_RecordChild2, // #2 = $addr
/*2072*/      OPC_Scope, 15, /*->2089*/ // 2 children in Scope
/*2074*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2076*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2079*/        OPC_EmitMergeInputChains1_0,
/*2080*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWL), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWL CPURegs:i32:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWL CPURegs:i32:$rt, addr:i32:$addr)
/*2089*/      /*Scope*/ 15, /*->2105*/
/*2090*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2092*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2095*/        OPC_EmitMergeInputChains1_0,
/*2096*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWL_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWL CPURegs:i32:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWL_P8 CPURegs:i32:$rt, addr:i64:$addr)
/*2105*/      0, /*End of Scope*/
/*2106*/    /*Scope*/ 37, /*->2144*/
/*2107*/      OPC_CheckChild1Type, MVT::i64,
/*2109*/      OPC_RecordChild2, // #2 = $addr
/*2110*/      OPC_Scope, 15, /*->2127*/ // 2 children in Scope
/*2112*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2114*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2117*/        OPC_EmitMergeInputChains1_0,
/*2118*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWL64), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWL CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWL64 CPU64Regs:i64:$rt, addr:i32:$addr)
/*2127*/      /*Scope*/ 15, /*->2143*/
/*2128*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2130*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2133*/        OPC_EmitMergeInputChains1_0,
/*2134*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWL64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWL CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWL64_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*2143*/      0, /*End of Scope*/
/*2144*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 81,  TARGET_VAL(OiISD::SWR),// ->2229
/*2148*/    OPC_RecordMemRef,
/*2149*/    OPC_RecordNode,   // #0 = 'OiSWR' chained node
/*2150*/    OPC_RecordChild1, // #1 = $rt
/*2151*/    OPC_Scope, 37, /*->2190*/ // 2 children in Scope
/*2153*/      OPC_CheckChild1Type, MVT::i32,
/*2155*/      OPC_RecordChild2, // #2 = $addr
/*2156*/      OPC_Scope, 15, /*->2173*/ // 2 children in Scope
/*2158*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2160*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2163*/        OPC_EmitMergeInputChains1_0,
/*2164*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWR), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWR CPURegs:i32:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWR CPURegs:i32:$rt, addr:i32:$addr)
/*2173*/      /*Scope*/ 15, /*->2189*/
/*2174*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2176*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2179*/        OPC_EmitMergeInputChains1_0,
/*2180*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWR_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWR CPURegs:i32:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWR_P8 CPURegs:i32:$rt, addr:i64:$addr)
/*2189*/      0, /*End of Scope*/
/*2190*/    /*Scope*/ 37, /*->2228*/
/*2191*/      OPC_CheckChild1Type, MVT::i64,
/*2193*/      OPC_RecordChild2, // #2 = $addr
/*2194*/      OPC_Scope, 15, /*->2211*/ // 2 children in Scope
/*2196*/        OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2198*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2201*/        OPC_EmitMergeInputChains1_0,
/*2202*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWR64), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWR CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWR64 CPU64Regs:i64:$rt, addr:i32:$addr)
/*2211*/      /*Scope*/ 15, /*->2227*/
/*2212*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2214*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2217*/        OPC_EmitMergeInputChains1_0,
/*2218*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SWR64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (OiSWR CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
                // Dst: (SWR64_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*2227*/      0, /*End of Scope*/
/*2228*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 42,  TARGET_VAL(OiISD::LDL),// ->2274
/*2232*/    OPC_RecordMemRef,
/*2233*/    OPC_RecordNode,   // #0 = 'OiLDL' chained node
/*2234*/    OPC_RecordChild1, // #1 = $addr
/*2235*/    OPC_RecordChild2, // #2 = $src
/*2236*/    OPC_CheckType, MVT::i64,
/*2238*/    OPC_Scope, 16, /*->2256*/ // 2 children in Scope
/*2240*/      OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2242*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*2245*/      OPC_EmitMergeInputChains1_0,
/*2246*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LDL), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
              // Src: (OiLDL:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
              // Dst: (LDL:i64 addr:i32:$addr, CPU64Regs:i64:$src)
/*2256*/    /*Scope*/ 16, /*->2273*/
/*2257*/      OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2259*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*2262*/      OPC_EmitMergeInputChains1_0,
/*2263*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LDL_P8), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
              // Src: (OiLDL:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
              // Dst: (LDL_P8:i64 addr:i64:$addr, CPU64Regs:i64:$src)
/*2273*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 42,  TARGET_VAL(OiISD::LDR),// ->2319
/*2277*/    OPC_RecordMemRef,
/*2278*/    OPC_RecordNode,   // #0 = 'OiLDR' chained node
/*2279*/    OPC_RecordChild1, // #1 = $addr
/*2280*/    OPC_RecordChild2, // #2 = $src
/*2281*/    OPC_CheckType, MVT::i64,
/*2283*/    OPC_Scope, 16, /*->2301*/ // 2 children in Scope
/*2285*/      OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2287*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*2290*/      OPC_EmitMergeInputChains1_0,
/*2291*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LDR), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
              // Src: (OiLDR:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
              // Dst: (LDR:i64 addr:i32:$addr, CPU64Regs:i64:$src)
/*2301*/    /*Scope*/ 16, /*->2318*/
/*2302*/      OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2304*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*2307*/      OPC_EmitMergeInputChains1_0,
/*2308*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LDR_P8), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
              // Src: (OiLDR:i64 addr:iPTR:$addr, CPU64Regs:i64:$src) - Complexity = 12
              // Dst: (LDR_P8:i64 addr:i64:$addr, CPU64Regs:i64:$src)
/*2318*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 40,  TARGET_VAL(OiISD::SDL),// ->2362
/*2322*/    OPC_RecordMemRef,
/*2323*/    OPC_RecordNode,   // #0 = 'OiSDL' chained node
/*2324*/    OPC_RecordChild1, // #1 = $rt
/*2325*/    OPC_CheckChild1Type, MVT::i64,
/*2327*/    OPC_RecordChild2, // #2 = $addr
/*2328*/    OPC_Scope, 15, /*->2345*/ // 2 children in Scope
/*2330*/      OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2332*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2335*/      OPC_EmitMergeInputChains1_0,
/*2336*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SDL), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (OiSDL CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
              // Dst: (SDL CPU64Regs:i64:$rt, addr:i32:$addr)
/*2345*/    /*Scope*/ 15, /*->2361*/
/*2346*/      OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2348*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2351*/      OPC_EmitMergeInputChains1_0,
/*2352*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SDL_P8), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (OiSDL CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
              // Dst: (SDL_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*2361*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 40,  TARGET_VAL(OiISD::SDR),// ->2405
/*2365*/    OPC_RecordMemRef,
/*2366*/    OPC_RecordNode,   // #0 = 'OiSDR' chained node
/*2367*/    OPC_RecordChild1, // #1 = $rt
/*2368*/    OPC_CheckChild1Type, MVT::i64,
/*2370*/    OPC_RecordChild2, // #2 = $addr
/*2371*/    OPC_Scope, 15, /*->2388*/ // 2 children in Scope
/*2373*/      OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2375*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2378*/      OPC_EmitMergeInputChains1_0,
/*2379*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SDR), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (OiSDR CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
              // Dst: (SDR CPU64Regs:i64:$rt, addr:i32:$addr)
/*2388*/    /*Scope*/ 15, /*->2404*/
/*2389*/      OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*2391*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*2394*/      OPC_EmitMergeInputChains1_0,
/*2395*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SDR_P8), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (OiSDR CPU64Regs:i64:$rt, addr:iPTR:$addr) - Complexity = 12
              // Dst: (SDR_P8 CPU64Regs:i64:$rt, addr:i64:$addr)
/*2404*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 54,  TARGET_VAL(ISD::FrameIndex),// ->2462
/*2408*/    OPC_RecordNode,   // #0 = $addr
/*2409*/    OPC_SwitchType /*2 cases */, 33,  MVT::i32,// ->2445
/*2412*/      OPC_Scope, 15, /*->2429*/ // 2 children in Scope
/*2414*/        OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*2416*/        OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectAddr16:$addr #1 #2 #3
/*2419*/        OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRyOffMemX16), 0,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
                // Src: addr16:i32:$addr - Complexity = 12
                // Dst: (AddiuRxRyOffMemX16:i32 addr16:i32:$addr)
/*2429*/      /*Scope*/ 14, /*->2444*/
/*2430*/        OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*2432*/        OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectAddr:$addr #1 #2
/*2435*/        OPC_MorphNodeTo, TARGET_VAL(Oi::LEA_ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: addr:i32:$addr - Complexity = 9
                // Dst: (LEA_ADDiu:i32 addr:i32:$addr)
/*2444*/      0, /*End of Scope*/
            /*SwitchType*/ 14,  MVT::i64,// ->2461
/*2447*/      OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*2449*/      OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectAddr:$addr #1 #2
/*2452*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LEA_ADDiu64), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
              // Src: addr:i64:$addr - Complexity = 9
              // Dst: (LEA_ADDiu64:i64 addr:i64:$addr)
            0, // EndSwitchType
          /*SwitchOpcode*/ 37|128,8/*1061*/,  TARGET_VAL(ISD::INTRINSIC_W_CHAIN),// ->3527
/*2466*/    OPC_RecordNode,   // #0 = 'intrinsic_w_chain' chained node
/*2467*/    OPC_MoveChild, 1,
/*2469*/    OPC_Scope, 44, /*->2515*/ // 50 children in Scope
/*2471*/      OPC_CheckInteger, 124|128,8/*1148*/, 
/*2474*/      OPC_MoveParent,
/*2475*/      OPC_RecordChild2, // #1 = $rt
/*2476*/      OPC_RecordChild3, // #2 = $rs_sa
/*2477*/      OPC_Scope, 22, /*->2501*/ // 2 children in Scope
/*2479*/        OPC_MoveChild, 3,
/*2481*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2484*/        OPC_CheckPredicate, 21, // Predicate_immZExt5
/*2486*/        OPC_MoveParent,
/*2487*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2489*/        OPC_EmitMergeInputChains1_0,
/*2490*/        OPC_EmitConvertToTarget, 2,
/*2492*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLL_S_W), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                // Src: (intrinsic_w_chain:i32 1148:iPTR, CPURegs:i32:$rt, (imm:i32)<<P:Predicate_immZExt5>>:$rs_sa) - Complexity = 12
                // Dst: (SHLL_S_W:i32 CPURegs:i32:$rt, (imm:i32):$rs_sa)
/*2501*/      /*Scope*/ 12, /*->2514*/
/*2502*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2504*/        OPC_EmitMergeInputChains1_0,
/*2505*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLLV_S_W), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_w_chain:i32 1148:iPTR, CPURegs:i32:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHLLV_S_W:i32 CPURegs:i32:$rt, CPURegs:i32:$rs_sa)
/*2514*/      0, /*End of Scope*/
/*2515*/    /*Scope*/ 26, /*->2542*/
/*2516*/      OPC_CheckInteger, 117|128,8/*1141*/, 
/*2519*/      OPC_MoveParent,
/*2520*/      OPC_RecordChild2, // #1 = $mask
/*2521*/      OPC_MoveChild, 2,
/*2523*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2526*/      OPC_CheckPredicate, 22, // Predicate_immZExt10
/*2528*/      OPC_MoveParent,
/*2529*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2531*/      OPC_EmitMergeInputChains1_0,
/*2532*/      OPC_EmitConvertToTarget, 1,
/*2534*/      OPC_MorphNodeTo, TARGET_VAL(Oi::RDDSP), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (intrinsic_w_chain:i32 1141:iPTR, (imm:i32)<<P:Predicate_immZExt10>>:$mask) - Complexity = 12
              // Dst: (RDDSP:i32 (imm:i32):$mask)
/*2542*/    /*Scope*/ 18, /*->2561*/
/*2543*/      OPC_CheckInteger, 16|128,8/*1040*/, 
/*2546*/      OPC_MoveParent,
/*2547*/      OPC_RecordChild2, // #1 = $rs
/*2548*/      OPC_RecordChild3, // #2 = $rt
/*2549*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2551*/      OPC_EmitMergeInputChains1_0,
/*2552*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDQ_S_W), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1040:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (ADDQ_S_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*2561*/    /*Scope*/ 18, /*->2580*/
/*2562*/      OPC_CheckInteger, 6|128,9/*1158*/, 
/*2565*/      OPC_MoveParent,
/*2566*/      OPC_RecordChild2, // #1 = $rs
/*2567*/      OPC_RecordChild3, // #2 = $rt
/*2568*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2570*/      OPC_EmitMergeInputChains1_0,
/*2571*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBQ_S_W), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1158:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (SUBQ_S_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*2580*/    /*Scope*/ 18, /*->2599*/
/*2581*/      OPC_CheckInteger, 21|128,8/*1045*/, 
/*2584*/      OPC_MoveParent,
/*2585*/      OPC_RecordChild2, // #1 = $rs
/*2586*/      OPC_RecordChild3, // #2 = $rt
/*2587*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2589*/      OPC_EmitMergeInputChains1_0,
/*2590*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDSC), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1045:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (ADDSC:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*2599*/    /*Scope*/ 18, /*->2618*/
/*2600*/      OPC_CheckInteger, 28|128,8/*1052*/, 
/*2603*/      OPC_MoveParent,
/*2604*/      OPC_RecordChild2, // #1 = $rs
/*2605*/      OPC_RecordChild3, // #2 = $rt
/*2606*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2608*/      OPC_EmitMergeInputChains1_0,
/*2609*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDWC), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1052:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (ADDWC:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*2618*/    /*Scope*/ 16, /*->2635*/
/*2619*/      OPC_CheckInteger, 13|128,8/*1037*/, 
/*2622*/      OPC_MoveParent,
/*2623*/      OPC_RecordChild2, // #1 = $rt
/*2624*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2626*/      OPC_EmitMergeInputChains1_0,
/*2627*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ABSQ_S_W), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 1037:iPTR, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (ABSQ_S_W:i32 CPURegs:i32:$rt)
/*2635*/    /*Scope*/ 18, /*->2654*/
/*2636*/      OPC_CheckInteger, 83|128,8/*1107*/, 
/*2639*/      OPC_MoveParent,
/*2640*/      OPC_RecordChild2, // #1 = $rs
/*2641*/      OPC_RecordChild3, // #2 = $rt
/*2642*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2644*/      OPC_EmitMergeInputChains1_0,
/*2645*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULEQ_S_W_PHL), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1107:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MULEQ_S_W_PHL:i32 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*2654*/    /*Scope*/ 18, /*->2673*/
/*2655*/      OPC_CheckInteger, 84|128,8/*1108*/, 
/*2658*/      OPC_MoveParent,
/*2659*/      OPC_RecordChild2, // #1 = $rs
/*2660*/      OPC_RecordChild3, // #2 = $rt
/*2661*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2663*/      OPC_EmitMergeInputChains1_0,
/*2664*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULEQ_S_W_PHR), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1108:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MULEQ_S_W_PHR:i32 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*2673*/    /*Scope*/ 18, /*->2692*/
/*2674*/      OPC_CheckInteger, 39|128,8/*1063*/, 
/*2677*/      OPC_MoveParent,
/*2678*/      OPC_RecordChild2, // #1 = $rs
/*2679*/      OPC_RecordChild3, // #2 = $rt
/*2680*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2682*/      OPC_EmitMergeInputChains1_0,
/*2683*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPGU_EQ_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1063:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPGU_EQ_QB:i32 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*2692*/    /*Scope*/ 18, /*->2711*/
/*2693*/      OPC_CheckInteger, 41|128,8/*1065*/, 
/*2696*/      OPC_MoveParent,
/*2697*/      OPC_RecordChild2, // #1 = $rs
/*2698*/      OPC_RecordChild3, // #2 = $rt
/*2699*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2701*/      OPC_EmitMergeInputChains1_0,
/*2702*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPGU_LT_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1065:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPGU_LT_QB:i32 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*2711*/    /*Scope*/ 18, /*->2730*/
/*2712*/      OPC_CheckInteger, 40|128,8/*1064*/, 
/*2715*/      OPC_MoveParent,
/*2716*/      OPC_RecordChild2, // #1 = $rs
/*2717*/      OPC_RecordChild3, // #2 = $rt
/*2718*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2720*/      OPC_EmitMergeInputChains1_0,
/*2721*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPGU_LE_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1064:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPGU_LE_QB:i32 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*2730*/    /*Scope*/ 20, /*->2751*/
/*2731*/      OPC_CheckInteger, 70|128,8/*1094*/, 
/*2734*/      OPC_MoveParent,
/*2735*/      OPC_RecordChild2, // #1 = $base
/*2736*/      OPC_CheckChild2Type, MVT::i32,
/*2738*/      OPC_RecordChild3, // #2 = $index
/*2739*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2741*/      OPC_EmitMergeInputChains1_0,
/*2742*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LWX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1094:iPTR, CPURegs:i32:$base, CPURegs:i32:$index) - Complexity = 8
              // Dst: (LWX:i32 CPURegs:i32:$base, CPURegs:i32:$index)
/*2751*/    /*Scope*/ 20, /*->2772*/
/*2752*/      OPC_CheckInteger, 69|128,8/*1093*/, 
/*2755*/      OPC_MoveParent,
/*2756*/      OPC_RecordChild2, // #1 = $base
/*2757*/      OPC_CheckChild2Type, MVT::i32,
/*2759*/      OPC_RecordChild3, // #2 = $index
/*2760*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2762*/      OPC_EmitMergeInputChains1_0,
/*2763*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LHX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1093:iPTR, CPURegs:i32:$base, CPURegs:i32:$index) - Complexity = 8
              // Dst: (LHX:i32 CPURegs:i32:$base, CPURegs:i32:$index)
/*2772*/    /*Scope*/ 20, /*->2793*/
/*2773*/      OPC_CheckInteger, 68|128,8/*1092*/, 
/*2776*/      OPC_MoveParent,
/*2777*/      OPC_RecordChild2, // #1 = $base
/*2778*/      OPC_CheckChild2Type, MVT::i32,
/*2780*/      OPC_RecordChild3, // #2 = $index
/*2781*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2783*/      OPC_EmitMergeInputChains1_0,
/*2784*/      OPC_MorphNodeTo, TARGET_VAL(Oi::LBUX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1092:iPTR, CPURegs:i32:$base, CPURegs:i32:$index) - Complexity = 8
              // Dst: (LBUX:i32 CPURegs:i32:$base, CPURegs:i32:$index)
/*2793*/    /*Scope*/ 18, /*->2812*/
/*2794*/      OPC_CheckInteger, 67|128,8/*1091*/, 
/*2797*/      OPC_MoveParent,
/*2798*/      OPC_RecordChild2, // #1 = $src
/*2799*/      OPC_RecordChild3, // #2 = $rs
/*2800*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2802*/      OPC_EmitMergeInputChains1_0,
/*2803*/      OPC_MorphNodeTo, TARGET_VAL(Oi::INSV), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1091:iPTR, CPURegs:i32:$src, CPURegs:i32:$rs) - Complexity = 8
              // Dst: (INSV:i32 CPURegs:i32:$src, CPURegs:i32:$rs)
/*2812*/    /*Scope*/ 18, /*->2831*/
/*2813*/      OPC_CheckInteger, 36|128,8/*1060*/, 
/*2816*/      OPC_MoveParent,
/*2817*/      OPC_RecordChild2, // #1 = $rs
/*2818*/      OPC_RecordChild3, // #2 = $rt
/*2819*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*2821*/      OPC_EmitMergeInputChains1_0,
/*2822*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPGDU_EQ_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1060:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPGDU_EQ_QB:i32 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*2831*/    /*Scope*/ 18, /*->2850*/
/*2832*/      OPC_CheckInteger, 38|128,8/*1062*/, 
/*2835*/      OPC_MoveParent,
/*2836*/      OPC_RecordChild2, // #1 = $rs
/*2837*/      OPC_RecordChild3, // #2 = $rt
/*2838*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*2840*/      OPC_EmitMergeInputChains1_0,
/*2841*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPGDU_LT_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1062:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPGDU_LT_QB:i32 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*2850*/    /*Scope*/ 18, /*->2869*/
/*2851*/      OPC_CheckInteger, 37|128,8/*1061*/, 
/*2854*/      OPC_MoveParent,
/*2855*/      OPC_RecordChild2, // #1 = $rs
/*2856*/      OPC_RecordChild3, // #2 = $rt
/*2857*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*2859*/      OPC_EmitMergeInputChains1_0,
/*2860*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPGDU_LE_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1061:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPGDU_LE_QB:i32 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*2869*/    /*Scope*/ 18, /*->2888*/
/*2870*/      OPC_CheckInteger, 90|128,8/*1114*/, 
/*2873*/      OPC_MoveParent,
/*2874*/      OPC_RecordChild2, // #1 = $rs
/*2875*/      OPC_RecordChild3, // #2 = $rt
/*2876*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*2878*/      OPC_EmitMergeInputChains1_0,
/*2879*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULQ_S_W), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1114:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (MULQ_S_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*2888*/    /*Scope*/ 18, /*->2907*/
/*2889*/      OPC_CheckInteger, 88|128,8/*1112*/, 
/*2892*/      OPC_MoveParent,
/*2893*/      OPC_RecordChild2, // #1 = $rs
/*2894*/      OPC_RecordChild3, // #2 = $rt
/*2895*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*2897*/      OPC_EmitMergeInputChains1_0,
/*2898*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULQ_RS_W), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i32 1112:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (MULQ_RS_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*2907*/    /*Scope*/ 12, /*->2920*/
/*2908*/      OPC_CheckInteger, 32|128,8/*1056*/, 
/*2911*/      OPC_MoveParent,
/*2912*/      OPC_EmitMergeInputChains1_0,
/*2913*/      OPC_MorphNodeTo, TARGET_VAL(Oi::BPOSGE32_PSEUDO), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
              // Src: (intrinsic_w_chain:i32 1056:iPTR) - Complexity = 8
              // Dst: (BPOSGE32_PSEUDO:i32)
/*2920*/    /*Scope*/ 44, /*->2965*/
/*2921*/      OPC_CheckInteger, 122|128,8/*1146*/, 
/*2924*/      OPC_MoveParent,
/*2925*/      OPC_RecordChild2, // #1 = $rt
/*2926*/      OPC_RecordChild3, // #2 = $rs_sa
/*2927*/      OPC_Scope, 22, /*->2951*/ // 2 children in Scope
/*2929*/        OPC_MoveChild, 3,
/*2931*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2934*/        OPC_CheckPredicate, 23, // Predicate_immZExt3
/*2936*/        OPC_MoveParent,
/*2937*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2939*/        OPC_EmitMergeInputChains1_0,
/*2940*/        OPC_EmitConvertToTarget, 2,
/*2942*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLL_QB), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 3, 
                // Src: (intrinsic_w_chain:v4i8 1146:iPTR, DSPRegs:v4i8:$rt, (imm:i32)<<P:Predicate_immZExt3>>:$rs_sa) - Complexity = 12
                // Dst: (SHLL_QB:v4i8 DSPRegs:v4i8:$rt, (imm:i32):$rs_sa)
/*2951*/      /*Scope*/ 12, /*->2964*/
/*2952*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2954*/        OPC_EmitMergeInputChains1_0,
/*2955*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLLV_QB), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_w_chain:v4i8 1146:iPTR, DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHLLV_QB:v4i8 DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa)
/*2964*/      0, /*End of Scope*/
/*2965*/    /*Scope*/ 44, /*->3010*/
/*2966*/      OPC_CheckInteger, 121|128,8/*1145*/, 
/*2969*/      OPC_MoveParent,
/*2970*/      OPC_RecordChild2, // #1 = $rt
/*2971*/      OPC_RecordChild3, // #2 = $rs_sa
/*2972*/      OPC_Scope, 22, /*->2996*/ // 2 children in Scope
/*2974*/        OPC_MoveChild, 3,
/*2976*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2979*/        OPC_CheckPredicate, 24, // Predicate_immZExt4
/*2981*/        OPC_MoveParent,
/*2982*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2984*/        OPC_EmitMergeInputChains1_0,
/*2985*/        OPC_EmitConvertToTarget, 2,
/*2987*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLL_PH), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 3, 
                // Src: (intrinsic_w_chain:v2i16 1145:iPTR, DSPRegs:v2i16:$rt, (imm:i32)<<P:Predicate_immZExt4>>:$rs_sa) - Complexity = 12
                // Dst: (SHLL_PH:v2i16 DSPRegs:v2i16:$rt, (imm:i32):$rs_sa)
/*2996*/      /*Scope*/ 12, /*->3009*/
/*2997*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*2999*/        OPC_EmitMergeInputChains1_0,
/*3000*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLLV_PH), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_w_chain:v2i16 1145:iPTR, DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHLLV_PH:v2i16 DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa)
/*3009*/      0, /*End of Scope*/
/*3010*/    /*Scope*/ 44, /*->3055*/
/*3011*/      OPC_CheckInteger, 123|128,8/*1147*/, 
/*3014*/      OPC_MoveParent,
/*3015*/      OPC_RecordChild2, // #1 = $rt
/*3016*/      OPC_RecordChild3, // #2 = $rs_sa
/*3017*/      OPC_Scope, 22, /*->3041*/ // 2 children in Scope
/*3019*/        OPC_MoveChild, 3,
/*3021*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3024*/        OPC_CheckPredicate, 24, // Predicate_immZExt4
/*3026*/        OPC_MoveParent,
/*3027*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3029*/        OPC_EmitMergeInputChains1_0,
/*3030*/        OPC_EmitConvertToTarget, 2,
/*3032*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLL_S_PH), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 3, 
                // Src: (intrinsic_w_chain:v2i16 1147:iPTR, DSPRegs:v2i16:$rt, (imm:i32)<<P:Predicate_immZExt4>>:$rs_sa) - Complexity = 12
                // Dst: (SHLL_S_PH:v2i16 DSPRegs:v2i16:$rt, (imm:i32):$rs_sa)
/*3041*/      /*Scope*/ 12, /*->3054*/
/*3042*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3044*/        OPC_EmitMergeInputChains1_0,
/*3045*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHLLV_S_PH), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_w_chain:v2i16 1147:iPTR, DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHLLV_S_PH:v2i16 DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa)
/*3054*/      0, /*End of Scope*/
/*3055*/    /*Scope*/ 18, /*->3074*/
/*3056*/      OPC_CheckInteger, 23|128,8/*1047*/, 
/*3059*/      OPC_MoveParent,
/*3060*/      OPC_RecordChild2, // #1 = $rs
/*3061*/      OPC_RecordChild3, // #2 = $rt
/*3062*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3064*/      OPC_EmitMergeInputChains1_0,
/*3065*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDU_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v4i8 1047:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (ADDU_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*3074*/    /*Scope*/ 18, /*->3093*/
/*3075*/      OPC_CheckInteger, 25|128,8/*1049*/, 
/*3078*/      OPC_MoveParent,
/*3079*/      OPC_RecordChild2, // #1 = $rs
/*3080*/      OPC_RecordChild3, // #2 = $rt
/*3081*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3083*/      OPC_EmitMergeInputChains1_0,
/*3084*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDU_S_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v4i8 1049:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (ADDU_S_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*3093*/    /*Scope*/ 18, /*->3112*/
/*3094*/      OPC_CheckInteger, 12|128,9/*1164*/, 
/*3097*/      OPC_MoveParent,
/*3098*/      OPC_RecordChild2, // #1 = $rs
/*3099*/      OPC_RecordChild3, // #2 = $rt
/*3100*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3102*/      OPC_EmitMergeInputChains1_0,
/*3103*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBU_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v4i8 1164:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (SUBU_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*3112*/    /*Scope*/ 18, /*->3131*/
/*3113*/      OPC_CheckInteger, 14|128,9/*1166*/, 
/*3116*/      OPC_MoveParent,
/*3117*/      OPC_RecordChild2, // #1 = $rs
/*3118*/      OPC_RecordChild3, // #2 = $rt
/*3119*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3121*/      OPC_EmitMergeInputChains1_0,
/*3122*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBU_S_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v4i8 1166:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (SUBU_S_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*3131*/    /*Scope*/ 18, /*->3150*/
/*3132*/      OPC_CheckInteger, 14|128,8/*1038*/, 
/*3135*/      OPC_MoveParent,
/*3136*/      OPC_RecordChild2, // #1 = $rs
/*3137*/      OPC_RecordChild3, // #2 = $rt
/*3138*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3140*/      OPC_EmitMergeInputChains1_0,
/*3141*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDQ_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1038:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (ADDQ_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3150*/    /*Scope*/ 18, /*->3169*/
/*3151*/      OPC_CheckInteger, 15|128,8/*1039*/, 
/*3154*/      OPC_MoveParent,
/*3155*/      OPC_RecordChild2, // #1 = $rs
/*3156*/      OPC_RecordChild3, // #2 = $rt
/*3157*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3159*/      OPC_EmitMergeInputChains1_0,
/*3160*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDQ_S_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1039:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (ADDQ_S_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3169*/    /*Scope*/ 18, /*->3188*/
/*3170*/      OPC_CheckInteger, 4|128,9/*1156*/, 
/*3173*/      OPC_MoveParent,
/*3174*/      OPC_RecordChild2, // #1 = $rs
/*3175*/      OPC_RecordChild3, // #2 = $rt
/*3176*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3178*/      OPC_EmitMergeInputChains1_0,
/*3179*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBQ_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1156:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (SUBQ_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3188*/    /*Scope*/ 18, /*->3207*/
/*3189*/      OPC_CheckInteger, 5|128,9/*1157*/, 
/*3192*/      OPC_MoveParent,
/*3193*/      OPC_RecordChild2, // #1 = $rs
/*3194*/      OPC_RecordChild3, // #2 = $rt
/*3195*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3197*/      OPC_EmitMergeInputChains1_0,
/*3198*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBQ_S_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1157:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (SUBQ_S_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3207*/    /*Scope*/ 16, /*->3224*/
/*3208*/      OPC_CheckInteger, 11|128,8/*1035*/, 
/*3211*/      OPC_MoveParent,
/*3212*/      OPC_RecordChild2, // #1 = $rt
/*3213*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3215*/      OPC_EmitMergeInputChains1_0,
/*3216*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ABSQ_S_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:v2i16 1035:iPTR, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (ABSQ_S_PH:v2i16 DSPRegs:v2i16:$rt)
/*3224*/    /*Scope*/ 18, /*->3243*/
/*3225*/      OPC_CheckInteger, 113|128,8/*1137*/, 
/*3228*/      OPC_MoveParent,
/*3229*/      OPC_RecordChild2, // #1 = $rs
/*3230*/      OPC_RecordChild3, // #2 = $rt
/*3231*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3233*/      OPC_EmitMergeInputChains1_0,
/*3234*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECRQ_RS_PH_W), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1137:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (PRECRQ_RS_PH_W:v2i16 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*3243*/    /*Scope*/ 18, /*->3262*/
/*3244*/      OPC_CheckInteger, 114|128,8/*1138*/, 
/*3247*/      OPC_MoveParent,
/*3248*/      OPC_RecordChild2, // #1 = $rs
/*3249*/      OPC_RecordChild3, // #2 = $rt
/*3250*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3252*/      OPC_EmitMergeInputChains1_0,
/*3253*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECRQU_S_QB_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v4i8 1138:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (PRECRQU_S_QB_PH:v4i8 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3262*/    /*Scope*/ 18, /*->3281*/
/*3263*/      OPC_CheckInteger, 85|128,8/*1109*/, 
/*3266*/      OPC_MoveParent,
/*3267*/      OPC_RecordChild2, // #1 = $rs
/*3268*/      OPC_RecordChild3, // #2 = $rt
/*3269*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3271*/      OPC_EmitMergeInputChains1_0,
/*3272*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULEU_S_PH_QBL), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1109:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MULEU_S_PH_QBL:v2i16 DSPRegs:v4i8:$rs, DSPRegs:v2i16:$rt)
/*3281*/    /*Scope*/ 18, /*->3300*/
/*3282*/      OPC_CheckInteger, 86|128,8/*1110*/, 
/*3285*/      OPC_MoveParent,
/*3286*/      OPC_RecordChild2, // #1 = $rs
/*3287*/      OPC_RecordChild3, // #2 = $rt
/*3288*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3290*/      OPC_EmitMergeInputChains1_0,
/*3291*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULEU_S_PH_QBR), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1110:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MULEU_S_PH_QBR:v2i16 DSPRegs:v4i8:$rs, DSPRegs:v2i16:$rt)
/*3300*/    /*Scope*/ 18, /*->3319*/
/*3301*/      OPC_CheckInteger, 87|128,8/*1111*/, 
/*3304*/      OPC_MoveParent,
/*3305*/      OPC_RecordChild2, // #1 = $rs
/*3306*/      OPC_RecordChild3, // #2 = $rt
/*3307*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3309*/      OPC_EmitMergeInputChains1_0,
/*3310*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULQ_RS_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1111:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MULQ_RS_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3319*/    /*Scope*/ 18, /*->3338*/
/*3320*/      OPC_CheckInteger, 97|128,8/*1121*/, 
/*3323*/      OPC_MoveParent,
/*3324*/      OPC_RecordChild2, // #1 = $rs
/*3325*/      OPC_RecordChild3, // #2 = $rt
/*3326*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3328*/      OPC_EmitMergeInputChains1_0,
/*3329*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PICK_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v4i8 1121:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PICK_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*3338*/    /*Scope*/ 18, /*->3357*/
/*3339*/      OPC_CheckInteger, 96|128,8/*1120*/, 
/*3342*/      OPC_MoveParent,
/*3343*/      OPC_RecordChild2, // #1 = $rs
/*3344*/      OPC_RecordChild3, // #2 = $rt
/*3345*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3347*/      OPC_EmitMergeInputChains1_0,
/*3348*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PICK_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1120:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (PICK_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3357*/    /*Scope*/ 18, /*->3376*/
/*3358*/      OPC_CheckInteger, 22|128,8/*1046*/, 
/*3361*/      OPC_MoveParent,
/*3362*/      OPC_RecordChild2, // #1 = $rs
/*3363*/      OPC_RecordChild3, // #2 = $rt
/*3364*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3366*/      OPC_EmitMergeInputChains1_0,
/*3367*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDU_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1046:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (ADDU_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3376*/    /*Scope*/ 18, /*->3395*/
/*3377*/      OPC_CheckInteger, 24|128,8/*1048*/, 
/*3380*/      OPC_MoveParent,
/*3381*/      OPC_RecordChild2, // #1 = $rs
/*3382*/      OPC_RecordChild3, // #2 = $rt
/*3383*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3385*/      OPC_EmitMergeInputChains1_0,
/*3386*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDU_S_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1048:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (ADDU_S_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3395*/    /*Scope*/ 18, /*->3414*/
/*3396*/      OPC_CheckInteger, 11|128,9/*1163*/, 
/*3399*/      OPC_MoveParent,
/*3400*/      OPC_RecordChild2, // #1 = $rs
/*3401*/      OPC_RecordChild3, // #2 = $rt
/*3402*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3404*/      OPC_EmitMergeInputChains1_0,
/*3405*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBU_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1163:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (SUBU_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3414*/    /*Scope*/ 18, /*->3433*/
/*3415*/      OPC_CheckInteger, 13|128,9/*1165*/, 
/*3418*/      OPC_MoveParent,
/*3419*/      OPC_RecordChild2, // #1 = $rs
/*3420*/      OPC_RecordChild3, // #2 = $rt
/*3421*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3423*/      OPC_EmitMergeInputChains1_0,
/*3424*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBU_S_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1165:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (SUBU_S_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3433*/    /*Scope*/ 16, /*->3450*/
/*3434*/      OPC_CheckInteger, 12|128,8/*1036*/, 
/*3437*/      OPC_MoveParent,
/*3438*/      OPC_RecordChild2, // #1 = $rt
/*3439*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3441*/      OPC_EmitMergeInputChains1_0,
/*3442*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ABSQ_S_QB), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:v4i8 1036:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (ABSQ_S_QB:v4i8 DSPRegs:v4i8:$rt)
/*3450*/    /*Scope*/ 18, /*->3469*/
/*3451*/      OPC_CheckInteger, 81|128,8/*1105*/, 
/*3454*/      OPC_MoveParent,
/*3455*/      OPC_RecordChild2, // #1 = $rs
/*3456*/      OPC_RecordChild3, // #2 = $rt
/*3457*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3459*/      OPC_EmitMergeInputChains1_0,
/*3460*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MUL_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1105:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MUL_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3469*/    /*Scope*/ 18, /*->3488*/
/*3470*/      OPC_CheckInteger, 82|128,8/*1106*/, 
/*3473*/      OPC_MoveParent,
/*3474*/      OPC_RecordChild2, // #1 = $rs
/*3475*/      OPC_RecordChild3, // #2 = $rt
/*3476*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3478*/      OPC_EmitMergeInputChains1_0,
/*3479*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MUL_S_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1106:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MUL_S_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3488*/    /*Scope*/ 18, /*->3507*/
/*3489*/      OPC_CheckInteger, 89|128,8/*1113*/, 
/*3492*/      OPC_MoveParent,
/*3493*/      OPC_RecordChild2, // #1 = $rs
/*3494*/      OPC_RecordChild3, // #2 = $rt
/*3495*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3497*/      OPC_EmitMergeInputChains1_0,
/*3498*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MULQ_S_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v2i16 1113:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (MULQ_S_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3507*/    /*Scope*/ 18, /*->3526*/
/*3508*/      OPC_CheckInteger, 108|128,8/*1132*/, 
/*3511*/      OPC_MoveParent,
/*3512*/      OPC_RecordChild2, // #1 = $rs
/*3513*/      OPC_RecordChild3, // #2 = $rt
/*3514*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3516*/      OPC_EmitMergeInputChains1_0,
/*3517*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECR_QB_PH), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:v4i8 1132:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (PRECR_QB_PH:v4i8 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*3526*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 119|128,7/*1015*/,  TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->4546
/*3531*/    OPC_MoveChild, 0,
/*3533*/    OPC_Scope, 42, /*->3577*/ // 42 children in Scope
/*3535*/      OPC_CheckInteger, 1|128,9/*1153*/, 
/*3538*/      OPC_MoveParent,
/*3539*/      OPC_RecordChild1, // #0 = $rt
/*3540*/      OPC_RecordChild2, // #1 = $rs_sa
/*3541*/      OPC_Scope, 21, /*->3564*/ // 2 children in Scope
/*3543*/        OPC_MoveChild, 2,
/*3545*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3548*/        OPC_CheckPredicate, 21, // Predicate_immZExt5
/*3550*/        OPC_MoveParent,
/*3551*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3553*/        OPC_EmitConvertToTarget, 1,
/*3555*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRA_R_W), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:i32 1153:iPTR, CPURegs:i32:$rt, (imm:i32)<<P:Predicate_immZExt5>>:$rs_sa) - Complexity = 12
                // Dst: (SHRA_R_W:i32 CPURegs:i32:$rt, (imm:i32):$rs_sa)
/*3564*/      /*Scope*/ 11, /*->3576*/
/*3565*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3567*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRAV_R_W), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:i32 1153:iPTR, CPURegs:i32:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHRAV_R_W:i32 CPURegs:i32:$rt, CPURegs:i32:$rs_sa)
/*3576*/      0, /*End of Scope*/
/*3577*/    /*Scope*/ 29, /*->3607*/
/*3578*/      OPC_CheckInteger, 29|128,8/*1053*/, 
/*3581*/      OPC_MoveParent,
/*3582*/      OPC_RecordChild1, // #0 = $src
/*3583*/      OPC_RecordChild2, // #1 = $rs
/*3584*/      OPC_RecordChild3, // #2 = $sa
/*3585*/      OPC_MoveChild, 3,
/*3587*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3590*/      OPC_CheckPredicate, 21, // Predicate_immZExt5
/*3592*/      OPC_MoveParent,
/*3593*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3595*/      OPC_EmitConvertToTarget, 2,
/*3597*/      OPC_MorphNodeTo, TARGET_VAL(Oi::APPEND), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 3, 0, 
              // Src: (intrinsic_wo_chain:i32 1053:iPTR, CPURegs:i32:$src, CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immZExt5>>:$sa) - Complexity = 12
              // Dst: (APPEND:i32 CPURegs:i32:$rs, (imm:i32):$sa, CPURegs:i32:$src)
/*3607*/    /*Scope*/ 29, /*->3637*/
/*3608*/      OPC_CheckInteger, 30|128,8/*1054*/, 
/*3611*/      OPC_MoveParent,
/*3612*/      OPC_RecordChild1, // #0 = $src
/*3613*/      OPC_RecordChild2, // #1 = $rs
/*3614*/      OPC_RecordChild3, // #2 = $sa
/*3615*/      OPC_MoveChild, 3,
/*3617*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3620*/      OPC_CheckPredicate, 25, // Predicate_immZExt2
/*3622*/      OPC_MoveParent,
/*3623*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3625*/      OPC_EmitConvertToTarget, 2,
/*3627*/      OPC_MorphNodeTo, TARGET_VAL(Oi::BALIGN), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 3, 0, 
              // Src: (intrinsic_wo_chain:i32 1054:iPTR, CPURegs:i32:$src, CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immZExt2>>:$sa) - Complexity = 12
              // Dst: (BALIGN:i32 CPURegs:i32:$rs, (imm:i32):$sa, CPURegs:i32:$src)
/*3637*/    /*Scope*/ 29, /*->3667*/
/*3638*/      OPC_CheckInteger, 115|128,8/*1139*/, 
/*3641*/      OPC_MoveParent,
/*3642*/      OPC_RecordChild1, // #0 = $src
/*3643*/      OPC_RecordChild2, // #1 = $rs
/*3644*/      OPC_RecordChild3, // #2 = $sa
/*3645*/      OPC_MoveChild, 3,
/*3647*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3650*/      OPC_CheckPredicate, 21, // Predicate_immZExt5
/*3652*/      OPC_MoveParent,
/*3653*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3655*/      OPC_EmitConvertToTarget, 2,
/*3657*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PREPEND), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 3, 0, 
              // Src: (intrinsic_wo_chain:i32 1139:iPTR, CPURegs:i32:$src, CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immZExt5>>:$sa) - Complexity = 12
              // Dst: (PREPEND:i32 CPURegs:i32:$rs, (imm:i32):$sa, CPURegs:i32:$src)
/*3667*/    /*Scope*/ 17, /*->3685*/
/*3668*/      OPC_CheckInteger, 77|128,8/*1101*/, 
/*3671*/      OPC_MoveParent,
/*3672*/      OPC_RecordChild1, // #0 = $rs
/*3673*/      OPC_RecordChild2, // #1 = $rt
/*3674*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3676*/      OPC_MorphNodeTo, TARGET_VAL(Oi::MODSUB), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:i32 1101:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (MODSUB:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*3685*/    /*Scope*/ 15, /*->3701*/
/*3686*/      OPC_CheckInteger, 116|128,8/*1140*/, 
/*3689*/      OPC_MoveParent,
/*3690*/      OPC_RecordChild1, // #0 = $rs
/*3691*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3693*/      OPC_MorphNodeTo, TARGET_VAL(Oi::RADDU_W_QB), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:i32 1140:iPTR, DSPRegs:v4i8:$rs) - Complexity = 8
              // Dst: (RADDU_W_QB:i32 DSPRegs:v4i8:$rs)
/*3701*/    /*Scope*/ 15, /*->3717*/
/*3702*/      OPC_CheckInteger, 98|128,8/*1122*/, 
/*3705*/      OPC_MoveParent,
/*3706*/      OPC_RecordChild1, // #0 = $rt
/*3707*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3709*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEQ_W_PHL), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:i32 1122:iPTR, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (PRECEQ_W_PHL:i32 DSPRegs:v2i16:$rt)
/*3717*/    /*Scope*/ 15, /*->3733*/
/*3718*/      OPC_CheckInteger, 99|128,8/*1123*/, 
/*3721*/      OPC_MoveParent,
/*3722*/      OPC_RecordChild1, // #0 = $rt
/*3723*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3725*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEQ_W_PHR), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:i32 1123:iPTR, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (PRECEQ_W_PHR:i32 DSPRegs:v2i16:$rt)
/*3733*/    /*Scope*/ 15, /*->3749*/
/*3734*/      OPC_CheckInteger, 31|128,8/*1055*/, 
/*3737*/      OPC_MoveParent,
/*3738*/      OPC_RecordChild1, // #0 = $rt
/*3739*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3741*/      OPC_MorphNodeTo, TARGET_VAL(Oi::BITREV), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:i32 1055:iPTR, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (BITREV:i32 CPURegs:i32:$rt)
/*3749*/    /*Scope*/ 17, /*->3767*/
/*3750*/      OPC_CheckInteger, 20|128,8/*1044*/, 
/*3753*/      OPC_MoveParent,
/*3754*/      OPC_RecordChild1, // #0 = $rs
/*3755*/      OPC_RecordChild2, // #1 = $rt
/*3756*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3758*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDQH_W), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:i32 1044:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (ADDQH_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*3767*/    /*Scope*/ 17, /*->3785*/
/*3768*/      OPC_CheckInteger, 19|128,8/*1043*/, 
/*3771*/      OPC_MoveParent,
/*3772*/      OPC_RecordChild1, // #0 = $rs
/*3773*/      OPC_RecordChild2, // #1 = $rt
/*3774*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3776*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDQH_R_W), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:i32 1043:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (ADDQH_R_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*3785*/    /*Scope*/ 17, /*->3803*/
/*3786*/      OPC_CheckInteger, 10|128,9/*1162*/, 
/*3789*/      OPC_MoveParent,
/*3790*/      OPC_RecordChild1, // #0 = $rs
/*3791*/      OPC_RecordChild2, // #1 = $rt
/*3792*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3794*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBQH_W), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:i32 1162:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (SUBQH_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*3803*/    /*Scope*/ 17, /*->3821*/
/*3804*/      OPC_CheckInteger, 9|128,9/*1161*/, 
/*3807*/      OPC_MoveParent,
/*3808*/      OPC_RecordChild1, // #0 = $rs
/*3809*/      OPC_RecordChild2, // #1 = $rt
/*3810*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*3812*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBQH_R_W), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:i32 1161:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (SUBQH_R_W:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*3821*/    /*Scope*/ 42, /*->3864*/
/*3822*/      OPC_CheckInteger, 3|128,9/*1155*/, 
/*3825*/      OPC_MoveParent,
/*3826*/      OPC_RecordChild1, // #0 = $rt
/*3827*/      OPC_RecordChild2, // #1 = $rs_sa
/*3828*/      OPC_Scope, 21, /*->3851*/ // 2 children in Scope
/*3830*/        OPC_MoveChild, 2,
/*3832*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3835*/        OPC_CheckPredicate, 23, // Predicate_immZExt3
/*3837*/        OPC_MoveParent,
/*3838*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3840*/        OPC_EmitConvertToTarget, 1,
/*3842*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRL_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:v4i8 1155:iPTR, DSPRegs:v4i8:$rt, (imm:i32)<<P:Predicate_immZExt3>>:$rs_sa) - Complexity = 12
                // Dst: (SHRL_QB:v4i8 DSPRegs:v4i8:$rt, (imm:i32):$rs_sa)
/*3851*/      /*Scope*/ 11, /*->3863*/
/*3852*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3854*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRLV_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:v4i8 1155:iPTR, DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHRLV_QB:v4i8 DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa)
/*3863*/      0, /*End of Scope*/
/*3864*/    /*Scope*/ 42, /*->3907*/
/*3865*/      OPC_CheckInteger, 125|128,8/*1149*/, 
/*3868*/      OPC_MoveParent,
/*3869*/      OPC_RecordChild1, // #0 = $rt
/*3870*/      OPC_RecordChild2, // #1 = $rs_sa
/*3871*/      OPC_Scope, 21, /*->3894*/ // 2 children in Scope
/*3873*/        OPC_MoveChild, 2,
/*3875*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3878*/        OPC_CheckPredicate, 24, // Predicate_immZExt4
/*3880*/        OPC_MoveParent,
/*3881*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3883*/        OPC_EmitConvertToTarget, 1,
/*3885*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRA_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:v2i16 1149:iPTR, DSPRegs:v2i16:$rt, (imm:i32)<<P:Predicate_immZExt4>>:$rs_sa) - Complexity = 12
                // Dst: (SHRA_PH:v2i16 DSPRegs:v2i16:$rt, (imm:i32):$rs_sa)
/*3894*/      /*Scope*/ 11, /*->3906*/
/*3895*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3897*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRAV_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:v2i16 1149:iPTR, DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHRAV_PH:v2i16 DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa)
/*3906*/      0, /*End of Scope*/
/*3907*/    /*Scope*/ 42, /*->3950*/
/*3908*/      OPC_CheckInteger, 127|128,8/*1151*/, 
/*3911*/      OPC_MoveParent,
/*3912*/      OPC_RecordChild1, // #0 = $rt
/*3913*/      OPC_RecordChild2, // #1 = $rs_sa
/*3914*/      OPC_Scope, 21, /*->3937*/ // 2 children in Scope
/*3916*/        OPC_MoveChild, 2,
/*3918*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3921*/        OPC_CheckPredicate, 24, // Predicate_immZExt4
/*3923*/        OPC_MoveParent,
/*3924*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3926*/        OPC_EmitConvertToTarget, 1,
/*3928*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRA_R_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:v2i16 1151:iPTR, DSPRegs:v2i16:$rt, (imm:i32)<<P:Predicate_immZExt4>>:$rs_sa) - Complexity = 12
                // Dst: (SHRA_R_PH:v2i16 DSPRegs:v2i16:$rt, (imm:i32):$rs_sa)
/*3937*/      /*Scope*/ 11, /*->3949*/
/*3938*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3940*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRAV_R_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:v2i16 1151:iPTR, DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHRAV_R_PH:v2i16 DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa)
/*3949*/      0, /*End of Scope*/
/*3950*/    /*Scope*/ 39, /*->3990*/
/*3951*/      OPC_CheckInteger, 119|128,8/*1143*/, 
/*3954*/      OPC_MoveParent,
/*3955*/      OPC_RecordChild1, // #0 = $imm
/*3956*/      OPC_Scope, 20, /*->3978*/ // 2 children in Scope
/*3958*/        OPC_MoveChild, 1,
/*3960*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3963*/        OPC_CheckPredicate, 26, // Predicate_immZExt8
/*3965*/        OPC_MoveParent,
/*3966*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3968*/        OPC_EmitConvertToTarget, 0,
/*3970*/        OPC_MorphNodeTo, TARGET_VAL(Oi::REPL_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 1/*#Ops*/, 1, 
                // Src: (intrinsic_wo_chain:v4i8 1143:iPTR, (imm:i32)<<P:Predicate_immZExt8>>:$imm) - Complexity = 12
                // Dst: (REPL_QB:v4i8 (imm:i32):$imm)
/*3978*/      /*Scope*/ 10, /*->3989*/
/*3979*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*3981*/        OPC_MorphNodeTo, TARGET_VAL(Oi::REPLV_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v4i8 1143:iPTR, CPURegs:i32:$rt) - Complexity = 8
                // Dst: (REPLV_QB:v4i8 CPURegs:i32:$rt)
/*3989*/      0, /*End of Scope*/
/*3990*/    /*Scope*/ 39, /*->4030*/
/*3991*/      OPC_CheckInteger, 118|128,8/*1142*/, 
/*3994*/      OPC_MoveParent,
/*3995*/      OPC_RecordChild1, // #0 = $imm
/*3996*/      OPC_Scope, 20, /*->4018*/ // 2 children in Scope
/*3998*/        OPC_MoveChild, 1,
/*4000*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4003*/        OPC_CheckPredicate, 22, // Predicate_immZExt10
/*4005*/        OPC_MoveParent,
/*4006*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4008*/        OPC_EmitConvertToTarget, 0,
/*4010*/        OPC_MorphNodeTo, TARGET_VAL(Oi::REPL_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 1, 
                // Src: (intrinsic_wo_chain:v2i16 1142:iPTR, (imm:i32)<<P:Predicate_immZExt10>>:$imm) - Complexity = 12
                // Dst: (REPL_PH:v2i16 (imm:i32):$imm)
/*4018*/      /*Scope*/ 10, /*->4029*/
/*4019*/        OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4021*/        OPC_MorphNodeTo, TARGET_VAL(Oi::REPLV_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v2i16 1142:iPTR, CPURegs:i32:$rt) - Complexity = 8
                // Dst: (REPLV_PH:v2i16 CPURegs:i32:$rt)
/*4029*/      0, /*End of Scope*/
/*4030*/    /*Scope*/ 29, /*->4060*/
/*4031*/      OPC_CheckInteger, 109|128,8/*1133*/, 
/*4034*/      OPC_MoveParent,
/*4035*/      OPC_RecordChild1, // #0 = $src
/*4036*/      OPC_RecordChild2, // #1 = $rs
/*4037*/      OPC_RecordChild3, // #2 = $sa
/*4038*/      OPC_MoveChild, 3,
/*4040*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4043*/      OPC_CheckPredicate, 21, // Predicate_immZExt5
/*4045*/      OPC_MoveParent,
/*4046*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4048*/      OPC_EmitConvertToTarget, 2,
/*4050*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECR_SRA_PH_W), 0,
                  1/*#VTs*/, MVT::v2i16, 3/*#Ops*/, 1, 3, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1133:iPTR, CPURegs:i32:$src, CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immZExt5>>:$sa) - Complexity = 12
              // Dst: (PRECR_SRA_PH_W:v2i16 CPURegs:i32:$rs, (imm:i32):$sa, CPURegs:i32:$src)
/*4060*/    /*Scope*/ 29, /*->4090*/
/*4061*/      OPC_CheckInteger, 110|128,8/*1134*/, 
/*4064*/      OPC_MoveParent,
/*4065*/      OPC_RecordChild1, // #0 = $src
/*4066*/      OPC_RecordChild2, // #1 = $rs
/*4067*/      OPC_RecordChild3, // #2 = $sa
/*4068*/      OPC_MoveChild, 3,
/*4070*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4073*/      OPC_CheckPredicate, 21, // Predicate_immZExt5
/*4075*/      OPC_MoveParent,
/*4076*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4078*/      OPC_EmitConvertToTarget, 2,
/*4080*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECR_SRA_R_PH_W), 0,
                  1/*#VTs*/, MVT::v2i16, 3/*#Ops*/, 1, 3, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1134:iPTR, CPURegs:i32:$src, CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immZExt5>>:$sa) - Complexity = 12
              // Dst: (PRECR_SRA_R_PH_W:v2i16 CPURegs:i32:$rs, (imm:i32):$sa, CPURegs:i32:$src)
/*4090*/    /*Scope*/ 42, /*->4133*/
/*4091*/      OPC_CheckInteger, 126|128,8/*1150*/, 
/*4094*/      OPC_MoveParent,
/*4095*/      OPC_RecordChild1, // #0 = $rt
/*4096*/      OPC_RecordChild2, // #1 = $rs_sa
/*4097*/      OPC_Scope, 21, /*->4120*/ // 2 children in Scope
/*4099*/        OPC_MoveChild, 2,
/*4101*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4104*/        OPC_CheckPredicate, 23, // Predicate_immZExt3
/*4106*/        OPC_MoveParent,
/*4107*/        OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4109*/        OPC_EmitConvertToTarget, 1,
/*4111*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRA_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:v4i8 1150:iPTR, DSPRegs:v4i8:$rt, (imm:i32)<<P:Predicate_immZExt3>>:$rs_sa) - Complexity = 12
                // Dst: (SHRA_QB:v4i8 DSPRegs:v4i8:$rt, (imm:i32):$rs_sa)
/*4120*/      /*Scope*/ 11, /*->4132*/
/*4121*/        OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4123*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRAV_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:v4i8 1150:iPTR, DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHRAV_QB:v4i8 DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa)
/*4132*/      0, /*End of Scope*/
/*4133*/    /*Scope*/ 42, /*->4176*/
/*4134*/      OPC_CheckInteger, 0|128,9/*1152*/, 
/*4137*/      OPC_MoveParent,
/*4138*/      OPC_RecordChild1, // #0 = $rt
/*4139*/      OPC_RecordChild2, // #1 = $rs_sa
/*4140*/      OPC_Scope, 21, /*->4163*/ // 2 children in Scope
/*4142*/        OPC_MoveChild, 2,
/*4144*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4147*/        OPC_CheckPredicate, 23, // Predicate_immZExt3
/*4149*/        OPC_MoveParent,
/*4150*/        OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4152*/        OPC_EmitConvertToTarget, 1,
/*4154*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRA_R_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:v4i8 1152:iPTR, DSPRegs:v4i8:$rt, (imm:i32)<<P:Predicate_immZExt3>>:$rs_sa) - Complexity = 12
                // Dst: (SHRA_R_QB:v4i8 DSPRegs:v4i8:$rt, (imm:i32):$rs_sa)
/*4163*/      /*Scope*/ 11, /*->4175*/
/*4164*/        OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4166*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRAV_R_QB), 0,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:v4i8 1152:iPTR, DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHRAV_R_QB:v4i8 DSPRegs:v4i8:$rt, CPURegs:i32:$rs_sa)
/*4175*/      0, /*End of Scope*/
/*4176*/    /*Scope*/ 42, /*->4219*/
/*4177*/      OPC_CheckInteger, 2|128,9/*1154*/, 
/*4180*/      OPC_MoveParent,
/*4181*/      OPC_RecordChild1, // #0 = $rt
/*4182*/      OPC_RecordChild2, // #1 = $rs_sa
/*4183*/      OPC_Scope, 21, /*->4206*/ // 2 children in Scope
/*4185*/        OPC_MoveChild, 2,
/*4187*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4190*/        OPC_CheckPredicate, 24, // Predicate_immZExt4
/*4192*/        OPC_MoveParent,
/*4193*/        OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4195*/        OPC_EmitConvertToTarget, 1,
/*4197*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRL_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:v2i16 1154:iPTR, DSPRegs:v2i16:$rt, (imm:i32)<<P:Predicate_immZExt4>>:$rs_sa) - Complexity = 12
                // Dst: (SHRL_PH:v2i16 DSPRegs:v2i16:$rt, (imm:i32):$rs_sa)
/*4206*/      /*Scope*/ 11, /*->4218*/
/*4207*/        OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4209*/        OPC_MorphNodeTo, TARGET_VAL(Oi::SHRLV_PH), 0,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:v2i16 1154:iPTR, DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa) - Complexity = 8
                // Dst: (SHRLV_PH:v2i16 DSPRegs:v2i16:$rt, CPURegs:i32:$rs_sa)
/*4218*/      0, /*End of Scope*/
/*4219*/    /*Scope*/ 17, /*->4237*/
/*4220*/      OPC_CheckInteger, 112|128,8/*1136*/, 
/*4223*/      OPC_MoveParent,
/*4224*/      OPC_RecordChild1, // #0 = $rs
/*4225*/      OPC_RecordChild2, // #1 = $rt
/*4226*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4228*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECRQ_QB_PH), 0,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i8 1136:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (PRECRQ_QB_PH:v4i8 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4237*/    /*Scope*/ 17, /*->4255*/
/*4238*/      OPC_CheckInteger, 111|128,8/*1135*/, 
/*4241*/      OPC_MoveParent,
/*4242*/      OPC_RecordChild1, // #0 = $rs
/*4243*/      OPC_RecordChild2, // #1 = $rt
/*4244*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4246*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECRQ_PH_W), 0,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v2i16 1135:iPTR, CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 8
              // Dst: (PRECRQ_PH_W:v2i16 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*4255*/    /*Scope*/ 15, /*->4271*/
/*4256*/      OPC_CheckInteger, 100|128,8/*1124*/, 
/*4259*/      OPC_MoveParent,
/*4260*/      OPC_RecordChild1, // #0 = $rt
/*4261*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4263*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEQU_PH_QBL), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1124:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEQU_PH_QBL:v2i16 DSPRegs:v4i8:$rt)
/*4271*/    /*Scope*/ 15, /*->4287*/
/*4272*/      OPC_CheckInteger, 102|128,8/*1126*/, 
/*4275*/      OPC_MoveParent,
/*4276*/      OPC_RecordChild1, // #0 = $rt
/*4277*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4279*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEQU_PH_QBR), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1126:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEQU_PH_QBR:v2i16 DSPRegs:v4i8:$rt)
/*4287*/    /*Scope*/ 15, /*->4303*/
/*4288*/      OPC_CheckInteger, 101|128,8/*1125*/, 
/*4291*/      OPC_MoveParent,
/*4292*/      OPC_RecordChild1, // #0 = $rt
/*4293*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4295*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEQU_PH_QBLA), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1125:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEQU_PH_QBLA:v2i16 DSPRegs:v4i8:$rt)
/*4303*/    /*Scope*/ 15, /*->4319*/
/*4304*/      OPC_CheckInteger, 103|128,8/*1127*/, 
/*4307*/      OPC_MoveParent,
/*4308*/      OPC_RecordChild1, // #0 = $rt
/*4309*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4311*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEQU_PH_QBRA), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1127:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEQU_PH_QBRA:v2i16 DSPRegs:v4i8:$rt)
/*4319*/    /*Scope*/ 15, /*->4335*/
/*4320*/      OPC_CheckInteger, 104|128,8/*1128*/, 
/*4323*/      OPC_MoveParent,
/*4324*/      OPC_RecordChild1, // #0 = $rt
/*4325*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4327*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEU_PH_QBL), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1128:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEU_PH_QBL:v2i16 DSPRegs:v4i8:$rt)
/*4335*/    /*Scope*/ 15, /*->4351*/
/*4336*/      OPC_CheckInteger, 106|128,8/*1130*/, 
/*4339*/      OPC_MoveParent,
/*4340*/      OPC_RecordChild1, // #0 = $rt
/*4341*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4343*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEU_PH_QBR), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1130:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEU_PH_QBR:v2i16 DSPRegs:v4i8:$rt)
/*4351*/    /*Scope*/ 15, /*->4367*/
/*4352*/      OPC_CheckInteger, 105|128,8/*1129*/, 
/*4355*/      OPC_MoveParent,
/*4356*/      OPC_RecordChild1, // #0 = $rt
/*4357*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4359*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEU_PH_QBLA), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1129:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEU_PH_QBLA:v2i16 DSPRegs:v4i8:$rt)
/*4367*/    /*Scope*/ 15, /*->4383*/
/*4368*/      OPC_CheckInteger, 107|128,8/*1131*/, 
/*4371*/      OPC_MoveParent,
/*4372*/      OPC_RecordChild1, // #0 = $rt
/*4373*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4375*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PRECEU_PH_QBRA), 0,
                  1/*#VTs*/, MVT::v2i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v2i16 1131:iPTR, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (PRECEU_PH_QBRA:v2i16 DSPRegs:v4i8:$rt)
/*4383*/    /*Scope*/ 17, /*->4401*/
/*4384*/      OPC_CheckInteger, 95|128,8/*1119*/, 
/*4387*/      OPC_MoveParent,
/*4388*/      OPC_RecordChild1, // #0 = $rs
/*4389*/      OPC_RecordChild2, // #1 = $rt
/*4390*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4392*/      OPC_MorphNodeTo, TARGET_VAL(Oi::PACKRL_PH), 0,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v2i16 1119:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (PACKRL_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4401*/    /*Scope*/ 17, /*->4419*/
/*4402*/      OPC_CheckInteger, 26|128,8/*1050*/, 
/*4405*/      OPC_MoveParent,
/*4406*/      OPC_RecordChild1, // #0 = $rs
/*4407*/      OPC_RecordChild2, // #1 = $rt
/*4408*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4410*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDUH_QB), 0,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i8 1050:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (ADDUH_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*4419*/    /*Scope*/ 17, /*->4437*/
/*4420*/      OPC_CheckInteger, 27|128,8/*1051*/, 
/*4423*/      OPC_MoveParent,
/*4424*/      OPC_RecordChild1, // #0 = $rs
/*4425*/      OPC_RecordChild2, // #1 = $rt
/*4426*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4428*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDUH_R_QB), 0,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i8 1051:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (ADDUH_R_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*4437*/    /*Scope*/ 17, /*->4455*/
/*4438*/      OPC_CheckInteger, 15|128,9/*1167*/, 
/*4441*/      OPC_MoveParent,
/*4442*/      OPC_RecordChild1, // #0 = $rs
/*4443*/      OPC_RecordChild2, // #1 = $rt
/*4444*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4446*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBUH_QB), 0,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i8 1167:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (SUBUH_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*4455*/    /*Scope*/ 17, /*->4473*/
/*4456*/      OPC_CheckInteger, 16|128,9/*1168*/, 
/*4459*/      OPC_MoveParent,
/*4460*/      OPC_RecordChild1, // #0 = $rs
/*4461*/      OPC_RecordChild2, // #1 = $rt
/*4462*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4464*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBUH_R_QB), 0,
                  1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i8 1168:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (SUBUH_R_QB:v4i8 DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*4473*/    /*Scope*/ 17, /*->4491*/
/*4474*/      OPC_CheckInteger, 17|128,8/*1041*/, 
/*4477*/      OPC_MoveParent,
/*4478*/      OPC_RecordChild1, // #0 = $rs
/*4479*/      OPC_RecordChild2, // #1 = $rt
/*4480*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4482*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDQH_PH), 0,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v2i16 1041:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (ADDQH_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4491*/    /*Scope*/ 17, /*->4509*/
/*4492*/      OPC_CheckInteger, 18|128,8/*1042*/, 
/*4495*/      OPC_MoveParent,
/*4496*/      OPC_RecordChild1, // #0 = $rs
/*4497*/      OPC_RecordChild2, // #1 = $rt
/*4498*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4500*/      OPC_MorphNodeTo, TARGET_VAL(Oi::ADDQH_R_PH), 0,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v2i16 1042:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (ADDQH_R_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4509*/    /*Scope*/ 17, /*->4527*/
/*4510*/      OPC_CheckInteger, 7|128,9/*1159*/, 
/*4513*/      OPC_MoveParent,
/*4514*/      OPC_RecordChild1, // #0 = $rs
/*4515*/      OPC_RecordChild2, // #1 = $rt
/*4516*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4518*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBQH_PH), 0,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v2i16 1159:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (SUBQH_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4527*/    /*Scope*/ 17, /*->4545*/
/*4528*/      OPC_CheckInteger, 8|128,9/*1160*/, 
/*4531*/      OPC_MoveParent,
/*4532*/      OPC_RecordChild1, // #0 = $rs
/*4533*/      OPC_RecordChild2, // #1 = $rt
/*4534*/      OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*4536*/      OPC_MorphNodeTo, TARGET_VAL(Oi::SUBQH_R_PH), 0,
                  1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v2i16 1160:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (SUBQH_R_PH:v2i16 DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4545*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 13|128,1/*141*/,  TARGET_VAL(ISD::INTRINSIC_VOID),// ->4691
/*4550*/    OPC_RecordNode,   // #0 = 'intrinsic_void' chained node
/*4551*/    OPC_MoveChild, 1,
/*4553*/    OPC_Scope, 27, /*->4582*/ // 7 children in Scope
/*4555*/      OPC_CheckInteger, 17|128,9/*1169*/, 
/*4558*/      OPC_MoveParent,
/*4559*/      OPC_RecordChild2, // #1 = $rs
/*4560*/      OPC_RecordChild3, // #2 = $mask
/*4561*/      OPC_MoveChild, 3,
/*4563*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4566*/      OPC_CheckPredicate, 22, // Predicate_immZExt10
/*4568*/      OPC_MoveParent,
/*4569*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4571*/      OPC_EmitMergeInputChains1_0,
/*4572*/      OPC_EmitConvertToTarget, 2,
/*4574*/      OPC_MorphNodeTo, TARGET_VAL(Oi::WRDSP), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 3, 
              // Src: (intrinsic_void 1169:iPTR, CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immZExt10>>:$mask) - Complexity = 12
              // Dst: (WRDSP CPURegs:i32:$rs, (imm:i32):$mask)
/*4582*/    /*Scope*/ 17, /*->4600*/
/*4583*/      OPC_CheckInteger, 42|128,8/*1066*/, 
/*4586*/      OPC_MoveParent,
/*4587*/      OPC_RecordChild2, // #1 = $rs
/*4588*/      OPC_RecordChild3, // #2 = $rt
/*4589*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4591*/      OPC_EmitMergeInputChains1_0,
/*4592*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPU_EQ_QB), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 1066:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPU_EQ_QB DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*4600*/    /*Scope*/ 17, /*->4618*/
/*4601*/      OPC_CheckInteger, 44|128,8/*1068*/, 
/*4604*/      OPC_MoveParent,
/*4605*/      OPC_RecordChild2, // #1 = $rs
/*4606*/      OPC_RecordChild3, // #2 = $rt
/*4607*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4609*/      OPC_EmitMergeInputChains1_0,
/*4610*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPU_LT_QB), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 1068:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPU_LT_QB DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*4618*/    /*Scope*/ 17, /*->4636*/
/*4619*/      OPC_CheckInteger, 43|128,8/*1067*/, 
/*4622*/      OPC_MoveParent,
/*4623*/      OPC_RecordChild2, // #1 = $rs
/*4624*/      OPC_RecordChild3, // #2 = $rt
/*4625*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4627*/      OPC_EmitMergeInputChains1_0,
/*4628*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMPU_LE_QB), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 1067:iPTR, DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt) - Complexity = 8
              // Dst: (CMPU_LE_QB DSPRegs:v4i8:$rs, DSPRegs:v4i8:$rt)
/*4636*/    /*Scope*/ 17, /*->4654*/
/*4637*/      OPC_CheckInteger, 33|128,8/*1057*/, 
/*4640*/      OPC_MoveParent,
/*4641*/      OPC_RecordChild2, // #1 = $rs
/*4642*/      OPC_RecordChild3, // #2 = $rt
/*4643*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4645*/      OPC_EmitMergeInputChains1_0,
/*4646*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMP_EQ_PH), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 1057:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (CMP_EQ_PH DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4654*/    /*Scope*/ 17, /*->4672*/
/*4655*/      OPC_CheckInteger, 35|128,8/*1059*/, 
/*4658*/      OPC_MoveParent,
/*4659*/      OPC_RecordChild2, // #1 = $rs
/*4660*/      OPC_RecordChild3, // #2 = $rt
/*4661*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4663*/      OPC_EmitMergeInputChains1_0,
/*4664*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMP_LT_PH), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 1059:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (CMP_LT_PH DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4672*/    /*Scope*/ 17, /*->4690*/
/*4673*/      OPC_CheckInteger, 34|128,8/*1058*/, 
/*4676*/      OPC_MoveParent,
/*4677*/      OPC_RecordChild2, // #1 = $rs
/*4678*/      OPC_RecordChild3, // #2 = $rt
/*4679*/      OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*4681*/      OPC_EmitMergeInputChains1_0,
/*4682*/      OPC_MorphNodeTo, TARGET_VAL(Oi::CMP_LE_PH), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 1058:iPTR, DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt) - Complexity = 8
              // Dst: (CMP_LE_PH DSPRegs:v2i16:$rs, DSPRegs:v2i16:$rt)
/*4690*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 69|128,1/*197*/,  TARGET_VAL(ISD::XOR),// ->4892
/*4695*/    OPC_Scope, 50, /*->4747*/ // 2 children in Scope
/*4697*/      OPC_MoveChild, 0,
/*4699*/      OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4702*/      OPC_RecordChild0, // #0 = $rs
/*4703*/      OPC_RecordChild1, // #1 = $rt
/*4704*/      OPC_MoveParent,
/*4705*/      OPC_MoveChild, 1,
/*4707*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4718*/      OPC_MoveParent,
/*4719*/      OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->4733
/*4722*/        OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*4724*/        OPC_MorphNodeTo, TARGET_VAL(Oi::NOR), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i32 (or:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt), -1:i32) - Complexity = 11
                // Dst: (NOR:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
              /*SwitchType*/ 11,  MVT::i64,// ->4746
/*4735*/        OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*4737*/        OPC_MorphNodeTo, TARGET_VAL(Oi::NOR64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i64 (or:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt), -1:i64) - Complexity = 11
                // Dst: (NOR64:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
              0, // EndSwitchType
/*4747*/    /*Scope*/ 14|128,1/*142*/, /*->4891*/
/*4749*/      OPC_RecordChild0, // #0 = $in
/*4750*/      OPC_Scope, 44, /*->4796*/ // 2 children in Scope
/*4752*/        OPC_MoveChild, 1,
/*4754*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4765*/        OPC_MoveParent,
/*4766*/        OPC_CheckType, MVT::i32,
/*4768*/        OPC_Scope, 14, /*->4784*/ // 2 children in Scope
/*4770*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*4772*/          OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*4775*/          OPC_MorphNodeTo, TARGET_VAL(Oi::NOR), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i32 CPURegs:i32:$in, -1:i32) - Complexity = 8
                  // Dst: (NOR:i32 CPURegsOpnd:i32:$in, ZERO:i32)
/*4784*/        /*Scope*/ 10, /*->4795*/
/*4785*/          OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*4787*/          OPC_MorphNodeTo, TARGET_VAL(Oi::NotRxRy16), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (xor:i32 CPU16Regs:i32:$r, -1:i32) - Complexity = 8
                  // Dst: (NotRxRy16:i32 CPU16Regs:i32:$r)
/*4795*/        0, /*End of Scope*/
/*4796*/      /*Scope*/ 93, /*->4890*/
/*4797*/        OPC_RecordChild1, // #1 = $imm16
/*4798*/        OPC_Scope, 46, /*->4846*/ // 3 children in Scope
/*4800*/          OPC_MoveChild, 1,
/*4802*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4805*/          OPC_CheckPredicate, 27, // Predicate_immZExt16
/*4807*/          OPC_MoveParent,
/*4808*/          OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->4827
/*4811*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*4813*/            OPC_EmitConvertToTarget, 1,
/*4815*/            OPC_EmitNodeXForm, 0, 2, // LO16
/*4818*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (xor:i32 CPURegsOpnd:i32:$rs, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$imm16) - Complexity = 7
                    // Dst: (XORi:i32 CPURegsOpnd:i32:$rs, (LO16:i32 (imm:i32):$imm16))
                  /*SwitchType*/ 16,  MVT::i64,// ->4845
/*4829*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*4831*/            OPC_EmitConvertToTarget, 1,
/*4833*/            OPC_EmitNodeXForm, 0, 2, // LO16
/*4836*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi64), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                    // Src: (xor:i64 CPU64RegsOpnd:i64:$rs, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$imm16) - Complexity = 7
                    // Dst: (XORi64:i64 CPU64RegsOpnd:i64:$rs, (LO16:i64 (imm:i64):$imm16))
                  0, // EndSwitchType
/*4846*/        /*Scope*/ 28, /*->4875*/
/*4847*/          OPC_CheckType, MVT::i32,
/*4849*/          OPC_Scope, 11, /*->4862*/ // 2 children in Scope
/*4851*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*4853*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XOR), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (xor:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
                    // Dst: (XOR:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*4862*/          /*Scope*/ 11, /*->4874*/
/*4863*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*4865*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XorRxRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (xor:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r) - Complexity = 3
                    // Dst: (XorRxRxRy16:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r)
/*4874*/          0, /*End of Scope*/
/*4875*/        /*Scope*/ 13, /*->4889*/
/*4876*/          OPC_CheckType, MVT::i64,
/*4878*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*4880*/          OPC_MorphNodeTo, TARGET_VAL(Oi::XOR64), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt) - Complexity = 3
                  // Dst: (XOR64:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
/*4889*/        0, /*End of Scope*/
/*4890*/      0, /*End of Scope*/
/*4891*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 78,  TARGET_VAL(ISD::CTLZ),// ->4973
/*4895*/    OPC_Scope, 47, /*->4944*/ // 2 children in Scope
/*4897*/      OPC_MoveChild, 0,
/*4899*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4902*/      OPC_RecordChild0, // #0 = $rs
/*4903*/      OPC_MoveChild, 1,
/*4905*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4916*/      OPC_MoveParent,
/*4917*/      OPC_MoveParent,
/*4918*/      OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->4931
/*4921*/        OPC_CheckPatternPredicate, 11, // (Subtarget.hasBitCount()) && (Subtarget.hasStandardEncoding())
/*4923*/        OPC_MorphNodeTo, TARGET_VAL(Oi::CLO), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (ctlz:i32 (xor:i32 CPURegsOpnd:i32:$rs, -1:i32)) - Complexity = 11
                // Dst: (CLO:i32 CPURegsOpnd:i32:$rs)
              /*SwitchType*/ 10,  MVT::i64,// ->4943
/*4933*/        OPC_CheckPatternPredicate, 11, // (Subtarget.hasBitCount()) && (Subtarget.hasStandardEncoding())
/*4935*/        OPC_MorphNodeTo, TARGET_VAL(Oi::DCLO), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (ctlz:i64 (xor:i64 CPU64RegsOpnd:i64:$rs, -1:i64)) - Complexity = 11
                // Dst: (DCLO:i64 CPU64RegsOpnd:i64:$rs)
              0, // EndSwitchType
/*4944*/    /*Scope*/ 27, /*->4972*/
/*4945*/      OPC_RecordChild0, // #0 = $rs
/*4946*/      OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->4959
/*4949*/        OPC_CheckPatternPredicate, 11, // (Subtarget.hasBitCount()) && (Subtarget.hasStandardEncoding())
/*4951*/        OPC_MorphNodeTo, TARGET_VAL(Oi::CLZ), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (ctlz:i32 CPURegsOpnd:i32:$rs) - Complexity = 3
                // Dst: (CLZ:i32 CPURegsOpnd:i32:$rs)
              /*SwitchType*/ 10,  MVT::i64,// ->4971
/*4961*/        OPC_CheckPatternPredicate, 11, // (Subtarget.hasBitCount()) && (Subtarget.hasStandardEncoding())
/*4963*/        OPC_MorphNodeTo, TARGET_VAL(Oi::DCLZ), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (ctlz:i64 CPU64RegsOpnd:i64:$rs) - Complexity = 3
                // Dst: (DCLZ:i64 CPU64RegsOpnd:i64:$rs)
              0, // EndSwitchType
/*4972*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 111|128,27/*3567*/,  TARGET_VAL(ISD::SELECT),// ->8544
/*4977*/    OPC_Scope, 96|128,13/*1760*/, /*->6740*/ // 4 children in Scope
/*4980*/      OPC_MoveChild, 0,
/*4982*/      OPC_CheckOpcode, TARGET_VAL(ISD::SETCC),
/*4985*/      OPC_RecordChild0, // #0 = $lhs
/*4986*/      OPC_Scope, 31|128,8/*1055*/, /*->6044*/ // 2 children in Scope
/*4989*/        OPC_CheckChild0Type, MVT::i32,
/*4991*/        OPC_Scope, 5|128,1/*133*/, /*->5127*/ // 2 children in Scope
/*4994*/          OPC_MoveChild, 1,
/*4996*/          OPC_CheckInteger, 0, 
/*4998*/          OPC_MoveParent,
/*4999*/          OPC_MoveChild, 2,
/*5001*/          OPC_Scope, 38, /*->5041*/ // 4 children in Scope
/*5003*/            OPC_CheckCondCode, ISD::SETEQ,
/*5005*/            OPC_MoveParent,
/*5006*/            OPC_CheckType, MVT::i32,
/*5008*/            OPC_MoveParent,
/*5009*/            OPC_RecordChild1, // #1 = $T
/*5010*/            OPC_RecordChild2, // #2 = $F
/*5011*/            OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->5026
/*5014*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5016*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETEQ:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 11
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, CPURegs:i32:$lhs, CPURegs:i32:$F)
                    /*SwitchType*/ 12,  MVT::i64,// ->5040
/*5028*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5030*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETEQ:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 11
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, CPURegs:i32:$lhs, CPU64Regs:i64:$F)
                    0, // EndSwitchType
/*5041*/          /*Scope*/ 38, /*->5080*/
/*5042*/            OPC_CheckCondCode, ISD::SETNE,
/*5044*/            OPC_MoveParent,
/*5045*/            OPC_CheckType, MVT::i32,
/*5047*/            OPC_MoveParent,
/*5048*/            OPC_RecordChild1, // #1 = $T
/*5049*/            OPC_RecordChild2, // #2 = $F
/*5050*/            OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->5065
/*5053*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5055*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETNE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 11
                      // Dst: (MOVN_I_I:i32 CPURegs:i32:$T, CPURegs:i32:$lhs, CPURegs:i32:$F)
                    /*SwitchType*/ 12,  MVT::i64,// ->5079
/*5067*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5069*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETNE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 11
                      // Dst: (MOVN_I_I64:i64 CPU64Regs:i64:$T, CPURegs:i32:$lhs, CPU64Regs:i64:$F)
                    0, // EndSwitchType
/*5080*/          /*Scope*/ 22, /*->5103*/
/*5081*/            OPC_CheckCondCode, ISD::SETEQ,
/*5083*/            OPC_MoveParent,
/*5084*/            OPC_CheckType, MVT::i32,
/*5086*/            OPC_MoveParent,
/*5087*/            OPC_RecordChild1, // #1 = $x
/*5088*/            OPC_RecordChild2, // #2 = $y
/*5089*/            OPC_CheckType, MVT::i32,
/*5091*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5093*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SelBeqZ), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 0, 
                    // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, 0:i32, SETEQ:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 11
                    // Dst: (SelBeqZ:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a)
/*5103*/          /*Scope*/ 22, /*->5126*/
/*5104*/            OPC_CheckCondCode, ISD::SETNE,
/*5106*/            OPC_MoveParent,
/*5107*/            OPC_CheckType, MVT::i32,
/*5109*/            OPC_MoveParent,
/*5110*/            OPC_RecordChild1, // #1 = $x
/*5111*/            OPC_RecordChild2, // #2 = $y
/*5112*/            OPC_CheckType, MVT::i32,
/*5114*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5116*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SelBneZ), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 0, 
                    // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, 0:i32, SETNE:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 11
                    // Dst: (SelBneZ:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a)
/*5126*/          0, /*End of Scope*/
/*5127*/        /*Scope*/ 18|128,7/*914*/, /*->6043*/
/*5129*/          OPC_RecordChild1, // #1 = $b
/*5130*/          OPC_Scope, 78|128,2/*334*/, /*->5467*/ // 2 children in Scope
/*5133*/            OPC_MoveChild, 1,
/*5135*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5138*/            OPC_Scope, 30, /*->5170*/ // 6 children in Scope
/*5140*/              OPC_CheckPredicate, 28, // Predicate_immSExt16
/*5142*/              OPC_MoveParent,
/*5143*/              OPC_MoveChild, 2,
/*5145*/              OPC_CheckCondCode, ISD::SETLT,
/*5147*/              OPC_MoveParent,
/*5148*/              OPC_CheckType, MVT::i32,
/*5150*/              OPC_MoveParent,
/*5151*/              OPC_RecordChild1, // #2 = $x
/*5152*/              OPC_RecordChild2, // #3 = $y
/*5153*/              OPC_CheckType, MVT::i32,
/*5155*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5157*/              OPC_EmitConvertToTarget, 1,
/*5159*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBtneZSlti), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 0, 4, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, (imm:i32)<<P:Predicate_immSExt16>>:$b, SETLT:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 10
                      // Dst: (SelTBtneZSlti:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a, (imm:i32)<<P:Predicate_immSExt16>>:$b)
/*5170*/            /*Scope*/ 65, /*->5236*/
/*5171*/              OPC_CheckPredicate, 27, // Predicate_immZExt16
/*5173*/              OPC_MoveParent,
/*5174*/              OPC_MoveChild, 2,
/*5176*/              OPC_Scope, 28, /*->5206*/ // 2 children in Scope
/*5178*/                OPC_CheckCondCode, ISD::SETEQ,
/*5180*/                OPC_MoveParent,
/*5181*/                OPC_CheckType, MVT::i32,
/*5183*/                OPC_MoveParent,
/*5184*/                OPC_RecordChild1, // #2 = $x
/*5185*/                OPC_RecordChild2, // #3 = $y
/*5186*/                OPC_CheckType, MVT::i32,
/*5188*/                OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5190*/                OPC_EmitConvertToTarget, 1,
/*5192*/                OPC_EmitNodeXForm, 0, 4, // LO16
/*5195*/                OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBteqZCmpi), 0,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 0, 5, 
                        // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$k, SETEQ:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 10
                        // Dst: (SelTBteqZCmpi:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a, (LO16:i32 (imm:i32)<<P:Predicate_immZExt16>>:$k))
/*5206*/              /*Scope*/ 28, /*->5235*/
/*5207*/                OPC_CheckCondCode, ISD::SETNE,
/*5209*/                OPC_MoveParent,
/*5210*/                OPC_CheckType, MVT::i32,
/*5212*/                OPC_MoveParent,
/*5213*/                OPC_RecordChild1, // #2 = $x
/*5214*/                OPC_RecordChild2, // #3 = $y
/*5215*/                OPC_CheckType, MVT::i32,
/*5217*/                OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5219*/                OPC_EmitConvertToTarget, 1,
/*5221*/                OPC_EmitNodeXForm, 0, 4, // LO16
/*5224*/                OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBtneZCmpi), 0,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 0, 5, 
                        // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$k, SETNE:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 10
                        // Dst: (SelTBtneZCmpi:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a, (LO16:i32 (imm:i32)<<P:Predicate_immZExt16>>:$k))
/*5235*/              0, /*End of Scope*/
/*5236*/            /*Scope*/ 75, /*->5312*/
/*5237*/              OPC_CheckPredicate, 28, // Predicate_immSExt16
/*5239*/              OPC_MoveParent,
/*5240*/              OPC_MoveChild, 2,
/*5242*/              OPC_Scope, 33, /*->5277*/ // 2 children in Scope
/*5244*/                OPC_CheckCondCode, ISD::SETGE,
/*5246*/                OPC_MoveParent,
/*5247*/                OPC_CheckType, MVT::i32,
/*5249*/                OPC_MoveParent,
/*5250*/                OPC_RecordChild1, // #2 = $T
/*5251*/                OPC_RecordChild2, // #3 = $F
/*5252*/                OPC_CheckType, MVT::i32,
/*5254*/                OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5256*/                OPC_EmitConvertToTarget, 1,
/*5258*/                OPC_EmitNode, TARGET_VAL(Oi::SLTi), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*5267*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), CPURegs:i32:$F)
/*5277*/              /*Scope*/ 33, /*->5311*/
/*5278*/                OPC_CheckCondCode, ISD::SETUGE,
/*5280*/                OPC_MoveParent,
/*5281*/                OPC_CheckType, MVT::i32,
/*5283*/                OPC_MoveParent,
/*5284*/                OPC_RecordChild1, // #2 = $T
/*5285*/                OPC_RecordChild2, // #3 = $F
/*5286*/                OPC_CheckType, MVT::i32,
/*5288*/                OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5290*/                OPC_EmitConvertToTarget, 1,
/*5292*/                OPC_EmitNode, TARGET_VAL(Oi::SLTiu), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*5301*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i32 (setcc:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTiu:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh), CPURegs:i32:$F)
/*5311*/              0, /*End of Scope*/
/*5312*/            /*Scope*/ 38, /*->5351*/
/*5313*/              OPC_CheckPredicate, 27, // Predicate_immZExt16
/*5315*/              OPC_MoveParent,
/*5316*/              OPC_MoveChild, 2,
/*5318*/              OPC_CheckCondCode, ISD::SETEQ,
/*5320*/              OPC_MoveParent,
/*5321*/              OPC_CheckType, MVT::i32,
/*5323*/              OPC_MoveParent,
/*5324*/              OPC_RecordChild1, // #2 = $T
/*5325*/              OPC_RecordChild2, // #3 = $F
/*5326*/              OPC_CheckType, MVT::i32,
/*5328*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5330*/              OPC_EmitConvertToTarget, 1,
/*5332*/              OPC_EmitNode, TARGET_VAL(Oi::XORi), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*5341*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16, SETEQ:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 10
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (XORi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16), CPURegs:i32:$F)
/*5351*/            /*Scope*/ 75, /*->5427*/
/*5352*/              OPC_CheckPredicate, 28, // Predicate_immSExt16
/*5354*/              OPC_MoveParent,
/*5355*/              OPC_MoveChild, 2,
/*5357*/              OPC_Scope, 33, /*->5392*/ // 2 children in Scope
/*5359*/                OPC_CheckCondCode, ISD::SETGE,
/*5361*/                OPC_MoveParent,
/*5362*/                OPC_CheckType, MVT::i32,
/*5364*/                OPC_MoveParent,
/*5365*/                OPC_RecordChild1, // #2 = $T
/*5366*/                OPC_RecordChild2, // #3 = $F
/*5367*/                OPC_CheckType, MVT::i64,
/*5369*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5371*/                OPC_EmitConvertToTarget, 1,
/*5373*/                OPC_EmitNode, TARGET_VAL(Oi::SLTi), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*5382*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), CPU64Regs:i64:$F)
/*5392*/              /*Scope*/ 33, /*->5426*/
/*5393*/                OPC_CheckCondCode, ISD::SETUGE,
/*5395*/                OPC_MoveParent,
/*5396*/                OPC_CheckType, MVT::i32,
/*5398*/                OPC_MoveParent,
/*5399*/                OPC_RecordChild1, // #2 = $T
/*5400*/                OPC_RecordChild2, // #3 = $F
/*5401*/                OPC_CheckType, MVT::i64,
/*5403*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5405*/                OPC_EmitConvertToTarget, 1,
/*5407*/                OPC_EmitNode, TARGET_VAL(Oi::SLTiu), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*5416*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i64 (setcc:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTiu:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh), CPU64Regs:i64:$F)
/*5426*/              0, /*End of Scope*/
/*5427*/            /*Scope*/ 38, /*->5466*/
/*5428*/              OPC_CheckPredicate, 27, // Predicate_immZExt16
/*5430*/              OPC_MoveParent,
/*5431*/              OPC_MoveChild, 2,
/*5433*/              OPC_CheckCondCode, ISD::SETEQ,
/*5435*/              OPC_MoveParent,
/*5436*/              OPC_CheckType, MVT::i32,
/*5438*/              OPC_MoveParent,
/*5439*/              OPC_RecordChild1, // #2 = $T
/*5440*/              OPC_RecordChild2, // #3 = $F
/*5441*/              OPC_CheckType, MVT::i64,
/*5443*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5445*/              OPC_EmitConvertToTarget, 1,
/*5447*/              OPC_EmitNode, TARGET_VAL(Oi::XORi), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*5456*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16, SETEQ:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 10
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (XORi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16), CPU64Regs:i64:$F)
/*5466*/            0, /*End of Scope*/
/*5467*/          /*Scope*/ 61|128,4/*573*/, /*->6042*/
/*5469*/            OPC_MoveChild, 2,
/*5471*/            OPC_Scope, 23, /*->5496*/ // 19 children in Scope
/*5473*/              OPC_CheckCondCode, ISD::SETGE,
/*5475*/              OPC_MoveParent,
/*5476*/              OPC_CheckType, MVT::i32,
/*5478*/              OPC_MoveParent,
/*5479*/              OPC_RecordChild1, // #2 = $x
/*5480*/              OPC_RecordChild2, // #3 = $y
/*5481*/              OPC_CheckType, MVT::i32,
/*5483*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5485*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBteqZSlt), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 0, 1, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETGE:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBteqZSlt:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a, CPU16Regs:i32:$b)
/*5496*/            /*Scope*/ 23, /*->5520*/
/*5497*/              OPC_CheckCondCode, ISD::SETGT,
/*5499*/              OPC_MoveParent,
/*5500*/              OPC_CheckType, MVT::i32,
/*5502*/              OPC_MoveParent,
/*5503*/              OPC_RecordChild1, // #2 = $x
/*5504*/              OPC_RecordChild2, // #3 = $y
/*5505*/              OPC_CheckType, MVT::i32,
/*5507*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5509*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBtneZSlt), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 1, 0, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETGT:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBtneZSlt:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$b, CPU16Regs:i32:$a)
/*5520*/            /*Scope*/ 23, /*->5544*/
/*5521*/              OPC_CheckCondCode, ISD::SETUGE,
/*5523*/              OPC_MoveParent,
/*5524*/              OPC_CheckType, MVT::i32,
/*5526*/              OPC_MoveParent,
/*5527*/              OPC_RecordChild1, // #2 = $x
/*5528*/              OPC_RecordChild2, // #3 = $y
/*5529*/              OPC_CheckType, MVT::i32,
/*5531*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5533*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBteqZSltu), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 0, 1, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETUGE:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBteqZSltu:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a, CPU16Regs:i32:$b)
/*5544*/            /*Scope*/ 23, /*->5568*/
/*5545*/              OPC_CheckCondCode, ISD::SETUGT,
/*5547*/              OPC_MoveParent,
/*5548*/              OPC_CheckType, MVT::i32,
/*5550*/              OPC_MoveParent,
/*5551*/              OPC_RecordChild1, // #2 = $x
/*5552*/              OPC_RecordChild2, // #3 = $y
/*5553*/              OPC_CheckType, MVT::i32,
/*5555*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5557*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBtneZSltu), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 1, 0, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETUGT:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBtneZSltu:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$b, CPU16Regs:i32:$a)
/*5568*/            /*Scope*/ 23, /*->5592*/
/*5569*/              OPC_CheckCondCode, ISD::SETLE,
/*5571*/              OPC_MoveParent,
/*5572*/              OPC_CheckType, MVT::i32,
/*5574*/              OPC_MoveParent,
/*5575*/              OPC_RecordChild1, // #2 = $x
/*5576*/              OPC_RecordChild2, // #3 = $y
/*5577*/              OPC_CheckType, MVT::i32,
/*5579*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5581*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBteqZSlt), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 1, 0, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETLE:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBteqZSlt:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$b, CPU16Regs:i32:$a)
/*5592*/            /*Scope*/ 23, /*->5616*/
/*5593*/              OPC_CheckCondCode, ISD::SETULE,
/*5595*/              OPC_MoveParent,
/*5596*/              OPC_CheckType, MVT::i32,
/*5598*/              OPC_MoveParent,
/*5599*/              OPC_RecordChild1, // #2 = $x
/*5600*/              OPC_RecordChild2, // #3 = $y
/*5601*/              OPC_CheckType, MVT::i32,
/*5603*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5605*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBteqZSltu), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 1, 0, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETULE:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBteqZSltu:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$b, CPU16Regs:i32:$a)
/*5616*/            /*Scope*/ 23, /*->5640*/
/*5617*/              OPC_CheckCondCode, ISD::SETEQ,
/*5619*/              OPC_MoveParent,
/*5620*/              OPC_CheckType, MVT::i32,
/*5622*/              OPC_MoveParent,
/*5623*/              OPC_RecordChild1, // #2 = $x
/*5624*/              OPC_RecordChild2, // #3 = $y
/*5625*/              OPC_CheckType, MVT::i32,
/*5627*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5629*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBteqZCmp), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 1, 0, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETEQ:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBteqZCmp:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$b, CPU16Regs:i32:$a)
/*5640*/            /*Scope*/ 23, /*->5664*/
/*5641*/              OPC_CheckCondCode, ISD::SETNE,
/*5643*/              OPC_MoveParent,
/*5644*/              OPC_CheckType, MVT::i32,
/*5646*/              OPC_MoveParent,
/*5647*/              OPC_RecordChild1, // #2 = $x
/*5648*/              OPC_RecordChild2, // #3 = $y
/*5649*/              OPC_CheckType, MVT::i32,
/*5651*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*5653*/              OPC_MorphNodeTo, TARGET_VAL(Oi::SelTBtneZCmp), 0,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 1, 0, 
                      // Src: (select:i32 (setcc:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$b, SETNE:Other), CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 6
                      // Dst: (SelTBtneZCmp:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$b, CPU16Regs:i32:$a)
/*5664*/            /*Scope*/ 31, /*->5696*/
/*5665*/              OPC_CheckCondCode, ISD::SETGE,
/*5667*/              OPC_MoveParent,
/*5668*/              OPC_CheckType, MVT::i32,
/*5670*/              OPC_MoveParent,
/*5671*/              OPC_RecordChild1, // #2 = $T
/*5672*/              OPC_RecordChild2, // #3 = $F
/*5673*/              OPC_CheckType, MVT::i32,
/*5675*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5677*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*5686*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLT:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPURegs:i32:$F)
/*5696*/            /*Scope*/ 31, /*->5728*/
/*5697*/              OPC_CheckCondCode, ISD::SETUGE,
/*5699*/              OPC_MoveParent,
/*5700*/              OPC_CheckType, MVT::i32,
/*5702*/              OPC_MoveParent,
/*5703*/              OPC_RecordChild1, // #2 = $T
/*5704*/              OPC_RecordChild2, // #3 = $F
/*5705*/              OPC_CheckType, MVT::i32,
/*5707*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5709*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*5718*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPURegs:i32:$F)
/*5728*/            /*Scope*/ 31, /*->5760*/
/*5729*/              OPC_CheckCondCode, ISD::SETLE,
/*5731*/              OPC_MoveParent,
/*5732*/              OPC_CheckType, MVT::i32,
/*5734*/              OPC_MoveParent,
/*5735*/              OPC_RecordChild1, // #2 = $T
/*5736*/              OPC_RecordChild2, // #3 = $F
/*5737*/              OPC_CheckType, MVT::i32,
/*5739*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5741*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*5750*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETLE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), CPURegs:i32:$F)
/*5760*/            /*Scope*/ 31, /*->5792*/
/*5761*/              OPC_CheckCondCode, ISD::SETULE,
/*5763*/              OPC_MoveParent,
/*5764*/              OPC_CheckType, MVT::i32,
/*5766*/              OPC_MoveParent,
/*5767*/              OPC_RecordChild1, // #2 = $T
/*5768*/              OPC_RecordChild2, // #3 = $F
/*5769*/              OPC_CheckType, MVT::i32,
/*5771*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5773*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*5782*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETULE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), CPURegs:i32:$F)
/*5792*/            /*Scope*/ 31, /*->5824*/
/*5793*/              OPC_CheckCondCode, ISD::SETEQ,
/*5795*/              OPC_MoveParent,
/*5796*/              OPC_CheckType, MVT::i32,
/*5798*/              OPC_MoveParent,
/*5799*/              OPC_RecordChild1, // #2 = $T
/*5800*/              OPC_RecordChild2, // #3 = $F
/*5801*/              OPC_CheckType, MVT::i32,
/*5803*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5805*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*5814*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETEQ:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPURegs:i32:$F)
/*5824*/            /*Scope*/ 31, /*->5856*/
/*5825*/              OPC_CheckCondCode, ISD::SETGE,
/*5827*/              OPC_MoveParent,
/*5828*/              OPC_CheckType, MVT::i32,
/*5830*/              OPC_MoveParent,
/*5831*/              OPC_RecordChild1, // #2 = $T
/*5832*/              OPC_RecordChild2, // #3 = $F
/*5833*/              OPC_CheckType, MVT::i64,
/*5835*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5837*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*5846*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLT:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPU64Regs:i64:$F)
/*5856*/            /*Scope*/ 31, /*->5888*/
/*5857*/              OPC_CheckCondCode, ISD::SETUGE,
/*5859*/              OPC_MoveParent,
/*5860*/              OPC_CheckType, MVT::i32,
/*5862*/              OPC_MoveParent,
/*5863*/              OPC_RecordChild1, // #2 = $T
/*5864*/              OPC_RecordChild2, // #3 = $F
/*5865*/              OPC_CheckType, MVT::i64,
/*5867*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5869*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*5878*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPU64Regs:i64:$F)
/*5888*/            /*Scope*/ 31, /*->5920*/
/*5889*/              OPC_CheckCondCode, ISD::SETLE,
/*5891*/              OPC_MoveParent,
/*5892*/              OPC_CheckType, MVT::i32,
/*5894*/              OPC_MoveParent,
/*5895*/              OPC_RecordChild1, // #2 = $T
/*5896*/              OPC_RecordChild2, // #3 = $F
/*5897*/              OPC_CheckType, MVT::i64,
/*5899*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5901*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*5910*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETLE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), CPU64Regs:i64:$F)
/*5920*/            /*Scope*/ 31, /*->5952*/
/*5921*/              OPC_CheckCondCode, ISD::SETULE,
/*5923*/              OPC_MoveParent,
/*5924*/              OPC_CheckType, MVT::i32,
/*5926*/              OPC_MoveParent,
/*5927*/              OPC_RecordChild1, // #2 = $T
/*5928*/              OPC_RecordChild2, // #3 = $F
/*5929*/              OPC_CheckType, MVT::i64,
/*5931*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5933*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*5942*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETULE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), CPU64Regs:i64:$F)
/*5952*/            /*Scope*/ 31, /*->5984*/
/*5953*/              OPC_CheckCondCode, ISD::SETEQ,
/*5955*/              OPC_MoveParent,
/*5956*/              OPC_CheckType, MVT::i32,
/*5958*/              OPC_MoveParent,
/*5959*/              OPC_RecordChild1, // #2 = $T
/*5960*/              OPC_RecordChild2, // #3 = $F
/*5961*/              OPC_CheckType, MVT::i64,
/*5963*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*5965*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*5974*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETEQ:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPU64Regs:i64:$F)
/*5984*/            /*Scope*/ 56, /*->6041*/
/*5985*/              OPC_CheckCondCode, ISD::SETNE,
/*5987*/              OPC_MoveParent,
/*5988*/              OPC_CheckType, MVT::i32,
/*5990*/              OPC_MoveParent,
/*5991*/              OPC_RecordChild1, // #2 = $T
/*5992*/              OPC_RecordChild2, // #3 = $F
/*5993*/              OPC_SwitchType /*2 cases */, 21,  MVT::i32,// ->6017
/*5996*/                OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*5998*/                OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*6007*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                        // Src: (select:i32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETNE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                        // Dst: (MOVN_I_I:i32 CPURegs:i32:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPURegs:i32:$F)
                      /*SwitchType*/ 21,  MVT::i64,// ->6040
/*6019*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6021*/                OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*6030*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                        // Src: (select:i64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETNE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                        // Dst: (MOVN_I_I64:i64 CPU64Regs:i64:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), CPU64Regs:i64:$F)
                      0, // EndSwitchType
/*6041*/            0, /*End of Scope*/
/*6042*/          0, /*End of Scope*/
/*6043*/        0, /*End of Scope*/
/*6044*/      /*Scope*/ 53|128,5/*693*/, /*->6739*/
/*6046*/        OPC_CheckChild0Type, MVT::i64,
/*6048*/        OPC_Scope, 87, /*->6137*/ // 2 children in Scope
/*6050*/          OPC_MoveChild, 1,
/*6052*/          OPC_CheckInteger, 0, 
/*6054*/          OPC_MoveParent,
/*6055*/          OPC_MoveChild, 2,
/*6057*/          OPC_Scope, 38, /*->6097*/ // 2 children in Scope
/*6059*/            OPC_CheckCondCode, ISD::SETEQ,
/*6061*/            OPC_MoveParent,
/*6062*/            OPC_CheckType, MVT::i32,
/*6064*/            OPC_MoveParent,
/*6065*/            OPC_RecordChild1, // #1 = $T
/*6066*/            OPC_RecordChild2, // #2 = $F
/*6067*/            OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->6082
/*6070*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6072*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETEQ:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 11
                      // Dst: (MOVZ_I64_I:i32 CPURegs:i32:$T, CPU64Regs:i64:$lhs, CPURegs:i32:$F)
                    /*SwitchType*/ 12,  MVT::i64,// ->6096
/*6084*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6086*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETEQ:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 11
                      // Dst: (MOVZ_I64_I64:i64 CPU64Regs:i64:$T, CPU64Regs:i64:$lhs, CPU64Regs:i64:$F)
                    0, // EndSwitchType
/*6097*/          /*Scope*/ 38, /*->6136*/
/*6098*/            OPC_CheckCondCode, ISD::SETNE,
/*6100*/            OPC_MoveParent,
/*6101*/            OPC_CheckType, MVT::i32,
/*6103*/            OPC_MoveParent,
/*6104*/            OPC_RecordChild1, // #1 = $T
/*6105*/            OPC_RecordChild2, // #2 = $F
/*6106*/            OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->6121
/*6109*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6111*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETNE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 11
                      // Dst: (MOVN_I64_I:i32 CPURegs:i32:$T, CPU64Regs:i64:$lhs, CPURegs:i32:$F)
                    /*SwitchType*/ 12,  MVT::i64,// ->6135
/*6123*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6125*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
                      // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETNE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 11
                      // Dst: (MOVN_I64_I64:i64 CPU64Regs:i64:$T, CPU64Regs:i64:$lhs, CPU64Regs:i64:$F)
                    0, // EndSwitchType
/*6136*/          0, /*End of Scope*/
/*6137*/        /*Scope*/ 87|128,4/*599*/, /*->6738*/
/*6139*/          OPC_RecordChild1, // #1 = $rhs
/*6140*/          OPC_Scope, 90|128,1/*218*/, /*->6361*/ // 2 children in Scope
/*6143*/            OPC_MoveChild, 1,
/*6145*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6148*/            OPC_Scope, 15|128,1/*143*/, /*->6294*/ // 2 children in Scope
/*6151*/              OPC_CheckPredicate, 28, // Predicate_immSExt16
/*6153*/              OPC_MoveParent,
/*6154*/              OPC_MoveChild, 2,
/*6156*/              OPC_Scope, 33, /*->6191*/ // 4 children in Scope
/*6158*/                OPC_CheckCondCode, ISD::SETGE,
/*6160*/                OPC_MoveParent,
/*6161*/                OPC_CheckType, MVT::i32,
/*6163*/                OPC_MoveParent,
/*6164*/                OPC_RecordChild1, // #2 = $T
/*6165*/                OPC_RecordChild2, // #3 = $F
/*6166*/                OPC_CheckType, MVT::i32,
/*6168*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6170*/                OPC_EmitConvertToTarget, 1,
/*6172*/                OPC_EmitNode, TARGET_VAL(Oi::SLTi64), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*6181*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTi64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), CPURegs:i32:$F)
/*6191*/              /*Scope*/ 33, /*->6225*/
/*6192*/                OPC_CheckCondCode, ISD::SETUGE,
/*6194*/                OPC_MoveParent,
/*6195*/                OPC_CheckType, MVT::i32,
/*6197*/                OPC_MoveParent,
/*6198*/                OPC_RecordChild1, // #2 = $T
/*6199*/                OPC_RecordChild2, // #3 = $F
/*6200*/                OPC_CheckType, MVT::i32,
/*6202*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6204*/                OPC_EmitConvertToTarget, 1,
/*6206*/                OPC_EmitNode, TARGET_VAL(Oi::SLTiu64), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*6215*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTiu64:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh), CPURegs:i32:$F)
/*6225*/              /*Scope*/ 33, /*->6259*/
/*6226*/                OPC_CheckCondCode, ISD::SETGE,
/*6228*/                OPC_MoveParent,
/*6229*/                OPC_CheckType, MVT::i32,
/*6231*/                OPC_MoveParent,
/*6232*/                OPC_RecordChild1, // #2 = $T
/*6233*/                OPC_RecordChild2, // #3 = $F
/*6234*/                OPC_CheckType, MVT::i64,
/*6236*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6238*/                OPC_EmitConvertToTarget, 1,
/*6240*/                OPC_EmitNode, TARGET_VAL(Oi::SLTi64), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*6249*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTi64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), CPU64Regs:i64:$F)
/*6259*/              /*Scope*/ 33, /*->6293*/
/*6260*/                OPC_CheckCondCode, ISD::SETUGE,
/*6262*/                OPC_MoveParent,
/*6263*/                OPC_CheckType, MVT::i32,
/*6265*/                OPC_MoveParent,
/*6266*/                OPC_RecordChild1, // #2 = $T
/*6267*/                OPC_RecordChild2, // #3 = $F
/*6268*/                OPC_CheckType, MVT::i64,
/*6270*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6272*/                OPC_EmitConvertToTarget, 1,
/*6274*/                OPC_EmitNode, TARGET_VAL(Oi::SLTiu64), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*6283*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 10
                        // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTiu64:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh), CPU64Regs:i64:$F)
/*6293*/              0, /*End of Scope*/
/*6294*/            /*Scope*/ 65, /*->6360*/
/*6295*/              OPC_CheckPredicate, 27, // Predicate_immZExt16
/*6297*/              OPC_MoveParent,
/*6298*/              OPC_MoveChild, 2,
/*6300*/              OPC_CheckCondCode, ISD::SETEQ,
/*6302*/              OPC_MoveParent,
/*6303*/              OPC_CheckType, MVT::i32,
/*6305*/              OPC_MoveParent,
/*6306*/              OPC_RecordChild1, // #2 = $T
/*6307*/              OPC_RecordChild2, // #3 = $F
/*6308*/              OPC_SwitchType /*2 cases */, 23,  MVT::i32,// ->6334
/*6311*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6313*/                OPC_EmitConvertToTarget, 1,
/*6315*/                OPC_EmitNode, TARGET_VAL(Oi::XORi64), 0,
                            1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 4,  // Results = #5
/*6324*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16, SETEQ:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 10
                        // Dst: (MOVZ_I64_I:i32 CPURegs:i32:$T, (XORi64:i64 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16), CPURegs:i32:$F)
                      /*SwitchType*/ 23,  MVT::i64,// ->6359
/*6336*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6338*/                OPC_EmitConvertToTarget, 1,
/*6340*/                OPC_EmitNode, TARGET_VAL(Oi::XORi64), 0,
                            1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 4,  // Results = #5
/*6349*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 5, 3, 
                        // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16, SETEQ:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 10
                        // Dst: (MOVZ_I64_I64:i64 CPU64Regs:i64:$T, (XORi64:i64 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$uimm16), CPU64Regs:i64:$F)
                      0, // EndSwitchType
/*6360*/            0, /*End of Scope*/
/*6361*/          /*Scope*/ 118|128,2/*374*/, /*->6737*/
/*6363*/            OPC_MoveChild, 2,
/*6365*/            OPC_Scope, 31, /*->6398*/ // 10 children in Scope
/*6367*/              OPC_CheckCondCode, ISD::SETGE,
/*6369*/              OPC_MoveParent,
/*6370*/              OPC_CheckType, MVT::i32,
/*6372*/              OPC_MoveParent,
/*6373*/              OPC_RecordChild1, // #2 = $T
/*6374*/              OPC_RecordChild2, // #3 = $F
/*6375*/              OPC_CheckType, MVT::i32,
/*6377*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6379*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*6388*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLT64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPURegs:i32:$F)
/*6398*/            /*Scope*/ 31, /*->6430*/
/*6399*/              OPC_CheckCondCode, ISD::SETUGE,
/*6401*/              OPC_MoveParent,
/*6402*/              OPC_CheckType, MVT::i32,
/*6404*/              OPC_MoveParent,
/*6405*/              OPC_RecordChild1, // #2 = $T
/*6406*/              OPC_RecordChild2, // #3 = $F
/*6407*/              OPC_CheckType, MVT::i32,
/*6409*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6411*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*6420*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETUGE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTu64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPURegs:i32:$F)
/*6430*/            /*Scope*/ 31, /*->6462*/
/*6431*/              OPC_CheckCondCode, ISD::SETLE,
/*6433*/              OPC_MoveParent,
/*6434*/              OPC_CheckType, MVT::i32,
/*6436*/              OPC_MoveParent,
/*6437*/              OPC_RecordChild1, // #2 = $T
/*6438*/              OPC_RecordChild2, // #3 = $F
/*6439*/              OPC_CheckType, MVT::i32,
/*6441*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6443*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*6452*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETLE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLT64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), CPURegs:i32:$F)
/*6462*/            /*Scope*/ 31, /*->6494*/
/*6463*/              OPC_CheckCondCode, ISD::SETULE,
/*6465*/              OPC_MoveParent,
/*6466*/              OPC_CheckType, MVT::i32,
/*6468*/              OPC_MoveParent,
/*6469*/              OPC_RecordChild1, // #2 = $T
/*6470*/              OPC_RecordChild2, // #3 = $F
/*6471*/              OPC_CheckType, MVT::i32,
/*6473*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6475*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*6484*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I), 0,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETULE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I:i32 CPURegs:i32:$T, (SLTu64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), CPURegs:i32:$F)
/*6494*/            /*Scope*/ 31, /*->6526*/
/*6495*/              OPC_CheckCondCode, ISD::SETGE,
/*6497*/              OPC_MoveParent,
/*6498*/              OPC_CheckType, MVT::i32,
/*6500*/              OPC_MoveParent,
/*6501*/              OPC_RecordChild1, // #2 = $T
/*6502*/              OPC_RecordChild2, // #3 = $F
/*6503*/              OPC_CheckType, MVT::i64,
/*6505*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6507*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*6516*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLT64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPU64Regs:i64:$F)
/*6526*/            /*Scope*/ 31, /*->6558*/
/*6527*/              OPC_CheckCondCode, ISD::SETUGE,
/*6529*/              OPC_MoveParent,
/*6530*/              OPC_CheckType, MVT::i32,
/*6532*/              OPC_MoveParent,
/*6533*/              OPC_RecordChild1, // #2 = $T
/*6534*/              OPC_RecordChild2, // #3 = $F
/*6535*/              OPC_CheckType, MVT::i64,
/*6537*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6539*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*6548*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETUGE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTu64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPU64Regs:i64:$F)
/*6558*/            /*Scope*/ 31, /*->6590*/
/*6559*/              OPC_CheckCondCode, ISD::SETLE,
/*6561*/              OPC_MoveParent,
/*6562*/              OPC_CheckType, MVT::i32,
/*6564*/              OPC_MoveParent,
/*6565*/              OPC_RecordChild1, // #2 = $T
/*6566*/              OPC_RecordChild2, // #3 = $F
/*6567*/              OPC_CheckType, MVT::i64,
/*6569*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6571*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*6580*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETLE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLT64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), CPU64Regs:i64:$F)
/*6590*/            /*Scope*/ 31, /*->6622*/
/*6591*/              OPC_CheckCondCode, ISD::SETULE,
/*6593*/              OPC_MoveParent,
/*6594*/              OPC_CheckType, MVT::i32,
/*6596*/              OPC_MoveParent,
/*6597*/              OPC_RecordChild1, // #2 = $T
/*6598*/              OPC_RecordChild2, // #3 = $F
/*6599*/              OPC_CheckType, MVT::i64,
/*6601*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6603*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*6612*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_I64), 0,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETULE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_I64:i64 CPU64Regs:i64:$T, (SLTu64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), CPU64Regs:i64:$F)
/*6622*/            /*Scope*/ 56, /*->6679*/
/*6623*/              OPC_CheckCondCode, ISD::SETEQ,
/*6625*/              OPC_MoveParent,
/*6626*/              OPC_CheckType, MVT::i32,
/*6628*/              OPC_MoveParent,
/*6629*/              OPC_RecordChild1, // #2 = $T
/*6630*/              OPC_RecordChild2, // #3 = $F
/*6631*/              OPC_SwitchType /*2 cases */, 21,  MVT::i32,// ->6655
/*6634*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6636*/                OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                            1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*6645*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                        // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETEQ:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                        // Dst: (MOVZ_I64_I:i32 CPURegs:i32:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPURegs:i32:$F)
                      /*SwitchType*/ 21,  MVT::i64,// ->6678
/*6657*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6659*/                OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                            1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*6668*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                        // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETEQ:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                        // Dst: (MOVZ_I64_I64:i64 CPU64Regs:i64:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPU64Regs:i64:$F)
                      0, // EndSwitchType
/*6679*/            /*Scope*/ 56, /*->6736*/
/*6680*/              OPC_CheckCondCode, ISD::SETNE,
/*6682*/              OPC_MoveParent,
/*6683*/              OPC_CheckType, MVT::i32,
/*6685*/              OPC_MoveParent,
/*6686*/              OPC_RecordChild1, // #2 = $T
/*6687*/              OPC_RecordChild2, // #3 = $F
/*6688*/              OPC_SwitchType /*2 cases */, 21,  MVT::i32,// ->6712
/*6691*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6693*/                OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                            1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*6702*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_I), 0,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 4, 3, 
                        // Src: (select:i32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETNE:Other), CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 6
                        // Dst: (MOVN_I64_I:i32 CPURegs:i32:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPURegs:i32:$F)
                      /*SwitchType*/ 21,  MVT::i64,// ->6735
/*6714*/                OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6716*/                OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                            1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*6725*/                OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_I64), 0,
                            1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 4, 3, 
                        // Src: (select:i64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETNE:Other), CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 6
                        // Dst: (MOVN_I64_I64:i64 CPU64Regs:i64:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), CPU64Regs:i64:$F)
                      0, // EndSwitchType
/*6736*/            0, /*End of Scope*/
/*6737*/          0, /*End of Scope*/
/*6738*/        0, /*End of Scope*/
/*6739*/      0, /*End of Scope*/
/*6740*/    /*Scope*/ 89, /*->6830*/
/*6741*/      OPC_RecordChild0, // #0 = $cond
/*6742*/      OPC_Scope, 50, /*->6794*/ // 2 children in Scope
/*6744*/        OPC_CheckChild0Type, MVT::i32,
/*6746*/        OPC_RecordChild1, // #1 = $T
/*6747*/        OPC_RecordChild2, // #2 = $F
/*6748*/        OPC_SwitchType /*2 cases */, 28,  MVT::i32,// ->6779
/*6751*/          OPC_Scope, 12, /*->6765*/ // 2 children in Scope
/*6753*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*6755*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_I), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:i32 CPURegs:i32:$cond, CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 3
                    // Dst: (MOVN_I_I:i32 CPURegs:i32:$T, CPURegs:i32:$cond, CPURegs:i32:$F)
/*6765*/          /*Scope*/ 12, /*->6778*/
/*6766*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*6768*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SelBneZ), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 0, 
                    // Src: (select:i32 CPU16Regs:i32:$a, CPU16Regs:i32:$x, CPU16Regs:i32:$y) - Complexity = 3
                    // Dst: (SelBneZ:i32 CPU16Regs:i32:$x, CPU16Regs:i32:$y, CPU16Regs:i32:$a)
/*6778*/          0, /*End of Scope*/
                /*SwitchType*/ 12,  MVT::i64,// ->6793
/*6781*/          OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6783*/          OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_I64), 0,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
                  // Src: (select:i64 CPURegs:i32:$cond, CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 3
                  // Dst: (MOVN_I_I64:i64 CPU64Regs:i64:$T, CPURegs:i32:$cond, CPU64Regs:i64:$F)
                0, // EndSwitchType
/*6794*/      /*Scope*/ 34, /*->6829*/
/*6795*/        OPC_CheckChild0Type, MVT::i64,
/*6797*/        OPC_RecordChild1, // #1 = $T
/*6798*/        OPC_RecordChild2, // #2 = $F
/*6799*/        OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->6814
/*6802*/          OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6804*/          OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_I), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 0, 2, 
                  // Src: (select:i32 CPU64Regs:i64:$cond, CPURegs:i32:$T, CPURegs:i32:$F) - Complexity = 3
                  // Dst: (MOVN_I64_I:i32 CPURegs:i32:$T, CPU64Regs:i64:$cond, CPURegs:i32:$F)
                /*SwitchType*/ 12,  MVT::i64,// ->6828
/*6816*/          OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*6818*/          OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_I64), 0,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
                  // Src: (select:i64 CPU64Regs:i64:$cond, CPU64Regs:i64:$T, CPU64Regs:i64:$F) - Complexity = 3
                  // Dst: (MOVN_I64_I64:i64 CPU64Regs:i64:$T, CPU64Regs:i64:$cond, CPU64Regs:i64:$F)
                0, // EndSwitchType
/*6829*/      0, /*End of Scope*/
/*6830*/    /*Scope*/ 85|128,12/*1621*/, /*->8453*/
/*6832*/      OPC_MoveChild, 0,
/*6834*/      OPC_CheckOpcode, TARGET_VAL(ISD::SETCC),
/*6837*/      OPC_RecordChild0, // #0 = $lhs
/*6838*/      OPC_Scope, 62|128,7/*958*/, /*->7799*/ // 2 children in Scope
/*6841*/        OPC_CheckChild0Type, MVT::i32,
/*6843*/        OPC_Scope, 19|128,1/*147*/, /*->6993*/ // 2 children in Scope
/*6846*/          OPC_MoveChild, 1,
/*6848*/          OPC_CheckInteger, 0, 
/*6850*/          OPC_MoveParent,
/*6851*/          OPC_MoveChild, 2,
/*6853*/          OPC_Scope, 22, /*->6877*/ // 6 children in Scope
/*6855*/            OPC_CheckCondCode, ISD::SETEQ,
/*6857*/            OPC_MoveParent,
/*6858*/            OPC_CheckType, MVT::i32,
/*6860*/            OPC_MoveParent,
/*6861*/            OPC_RecordChild1, // #1 = $T
/*6862*/            OPC_RecordChild2, // #2 = $F
/*6863*/            OPC_CheckType, MVT::f32,
/*6865*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*6867*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                        1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETEQ:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 11
                    // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, CPURegs:i32:$lhs, FGR32:f32:$F)
/*6877*/          /*Scope*/ 22, /*->6900*/
/*6878*/            OPC_CheckCondCode, ISD::SETNE,
/*6880*/            OPC_MoveParent,
/*6881*/            OPC_CheckType, MVT::i32,
/*6883*/            OPC_MoveParent,
/*6884*/            OPC_RecordChild1, // #1 = $T
/*6885*/            OPC_RecordChild2, // #2 = $F
/*6886*/            OPC_CheckType, MVT::f32,
/*6888*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*6890*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_S), 0,
                        1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETNE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 11
                    // Dst: (MOVN_I_S:f32 FGR32:f32:$T, CPURegs:i32:$lhs, FGR32:f32:$F)
/*6900*/          /*Scope*/ 22, /*->6923*/
/*6901*/            OPC_CheckCondCode, ISD::SETEQ,
/*6903*/            OPC_MoveParent,
/*6904*/            OPC_CheckType, MVT::i32,
/*6906*/            OPC_MoveParent,
/*6907*/            OPC_RecordChild1, // #1 = $T
/*6908*/            OPC_RecordChild2, // #2 = $F
/*6909*/            OPC_CheckType, MVT::f64,
/*6911*/            OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*6913*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETEQ:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 11
                    // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, CPURegs:i32:$lhs, AFGR64:f64:$F)
/*6923*/          /*Scope*/ 22, /*->6946*/
/*6924*/            OPC_CheckCondCode, ISD::SETNE,
/*6926*/            OPC_MoveParent,
/*6927*/            OPC_CheckType, MVT::i32,
/*6929*/            OPC_MoveParent,
/*6930*/            OPC_RecordChild1, // #1 = $T
/*6931*/            OPC_RecordChild2, // #2 = $F
/*6932*/            OPC_CheckType, MVT::f64,
/*6934*/            OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*6936*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_D32), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETNE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 11
                    // Dst: (MOVN_I_D32:f64 AFGR64:f64:$T, CPURegs:i32:$lhs, AFGR64:f64:$F)
/*6946*/          /*Scope*/ 22, /*->6969*/
/*6947*/            OPC_CheckCondCode, ISD::SETEQ,
/*6949*/            OPC_MoveParent,
/*6950*/            OPC_CheckType, MVT::i32,
/*6952*/            OPC_MoveParent,
/*6953*/            OPC_RecordChild1, // #1 = $T
/*6954*/            OPC_RecordChild2, // #2 = $F
/*6955*/            OPC_CheckType, MVT::f64,
/*6957*/            OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*6959*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETEQ:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 11
                    // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, CPURegs:i32:$lhs, FGR64:f64:$F)
/*6969*/          /*Scope*/ 22, /*->6992*/
/*6970*/            OPC_CheckCondCode, ISD::SETNE,
/*6972*/            OPC_MoveParent,
/*6973*/            OPC_CheckType, MVT::i32,
/*6975*/            OPC_MoveParent,
/*6976*/            OPC_RecordChild1, // #1 = $T
/*6977*/            OPC_RecordChild2, // #2 = $F
/*6978*/            OPC_CheckType, MVT::f64,
/*6980*/            OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*6982*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_D64), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETNE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 11
                    // Dst: (MOVN_I_D64:f64 FGR64:f64:$T, CPURegs:i32:$lhs, FGR64:f64:$F)
/*6992*/          0, /*End of Scope*/
/*6993*/        /*Scope*/ 35|128,6/*803*/, /*->7798*/
/*6995*/          OPC_RecordChild1, // #1 = $rhs
/*6996*/          OPC_Scope, 88|128,1/*216*/, /*->7215*/ // 2 children in Scope
/*6999*/            OPC_MoveChild, 1,
/*7001*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*7004*/            OPC_CheckPredicate, 28, // Predicate_immSExt16
/*7006*/            OPC_MoveParent,
/*7007*/            OPC_MoveChild, 2,
/*7009*/            OPC_Scope, 33, /*->7044*/ // 6 children in Scope
/*7011*/              OPC_CheckCondCode, ISD::SETGE,
/*7013*/              OPC_MoveParent,
/*7014*/              OPC_CheckType, MVT::i32,
/*7016*/              OPC_MoveParent,
/*7017*/              OPC_RecordChild1, // #2 = $T
/*7018*/              OPC_RecordChild2, // #3 = $F
/*7019*/              OPC_CheckType, MVT::f32,
/*7021*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7023*/              OPC_EmitConvertToTarget, 1,
/*7025*/              OPC_EmitNode, TARGET_VAL(Oi::SLTi), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7034*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 10
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), FGR32:f32:$F)
/*7044*/            /*Scope*/ 33, /*->7078*/
/*7045*/              OPC_CheckCondCode, ISD::SETUGE,
/*7047*/              OPC_MoveParent,
/*7048*/              OPC_CheckType, MVT::i32,
/*7050*/              OPC_MoveParent,
/*7051*/              OPC_RecordChild1, // #2 = $T
/*7052*/              OPC_RecordChild2, // #3 = $F
/*7053*/              OPC_CheckType, MVT::f32,
/*7055*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7057*/              OPC_EmitConvertToTarget, 1,
/*7059*/              OPC_EmitNode, TARGET_VAL(Oi::SLTiu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7068*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 10
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTiu:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh), FGR32:f32:$F)
/*7078*/            /*Scope*/ 33, /*->7112*/
/*7079*/              OPC_CheckCondCode, ISD::SETGE,
/*7081*/              OPC_MoveParent,
/*7082*/              OPC_CheckType, MVT::i32,
/*7084*/              OPC_MoveParent,
/*7085*/              OPC_RecordChild1, // #2 = $T
/*7086*/              OPC_RecordChild2, // #3 = $F
/*7087*/              OPC_CheckType, MVT::f64,
/*7089*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7091*/              OPC_EmitConvertToTarget, 1,
/*7093*/              OPC_EmitNode, TARGET_VAL(Oi::SLTi), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7102*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 10
                      // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, (SLTi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), AFGR64:f64:$F)
/*7112*/            /*Scope*/ 33, /*->7146*/
/*7113*/              OPC_CheckCondCode, ISD::SETUGE,
/*7115*/              OPC_MoveParent,
/*7116*/              OPC_CheckType, MVT::i32,
/*7118*/              OPC_MoveParent,
/*7119*/              OPC_RecordChild1, // #2 = $T
/*7120*/              OPC_RecordChild2, // #3 = $F
/*7121*/              OPC_CheckType, MVT::f64,
/*7123*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7125*/              OPC_EmitConvertToTarget, 1,
/*7127*/              OPC_EmitNode, TARGET_VAL(Oi::SLTiu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7136*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 10
                      // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, (SLTiu:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh), AFGR64:f64:$F)
/*7146*/            /*Scope*/ 33, /*->7180*/
/*7147*/              OPC_CheckCondCode, ISD::SETGE,
/*7149*/              OPC_MoveParent,
/*7150*/              OPC_CheckType, MVT::i32,
/*7152*/              OPC_MoveParent,
/*7153*/              OPC_RecordChild1, // #2 = $T
/*7154*/              OPC_RecordChild2, // #3 = $F
/*7155*/              OPC_CheckType, MVT::f64,
/*7157*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7159*/              OPC_EmitConvertToTarget, 1,
/*7161*/              OPC_EmitNode, TARGET_VAL(Oi::SLTi), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7170*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 10
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), FGR64:f64:$F)
/*7180*/            /*Scope*/ 33, /*->7214*/
/*7181*/              OPC_CheckCondCode, ISD::SETUGE,
/*7183*/              OPC_MoveParent,
/*7184*/              OPC_CheckType, MVT::i32,
/*7186*/              OPC_MoveParent,
/*7187*/              OPC_RecordChild1, // #2 = $T
/*7188*/              OPC_RecordChild2, // #3 = $F
/*7189*/              OPC_CheckType, MVT::f64,
/*7191*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7193*/              OPC_EmitConvertToTarget, 1,
/*7195*/              OPC_EmitNode, TARGET_VAL(Oi::SLTiu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7204*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 10
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTiu:i32 CPURegs:i32:$lh, (imm:i32)<<P:Predicate_immSExt16>>:$rh), FGR64:f64:$F)
/*7214*/            0, /*End of Scope*/
/*7215*/          /*Scope*/ 68|128,4/*580*/, /*->7797*/
/*7217*/            OPC_MoveChild, 2,
/*7219*/            OPC_Scope, 31, /*->7252*/ // 18 children in Scope
/*7221*/              OPC_CheckCondCode, ISD::SETGE,
/*7223*/              OPC_MoveParent,
/*7224*/              OPC_CheckType, MVT::i32,
/*7226*/              OPC_MoveParent,
/*7227*/              OPC_RecordChild1, // #2 = $T
/*7228*/              OPC_RecordChild2, // #3 = $F
/*7229*/              OPC_CheckType, MVT::f32,
/*7231*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7233*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7242*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLT:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR32:f32:$F)
/*7252*/            /*Scope*/ 31, /*->7284*/
/*7253*/              OPC_CheckCondCode, ISD::SETUGE,
/*7255*/              OPC_MoveParent,
/*7256*/              OPC_CheckType, MVT::i32,
/*7258*/              OPC_MoveParent,
/*7259*/              OPC_RecordChild1, // #2 = $T
/*7260*/              OPC_RecordChild2, // #3 = $F
/*7261*/              OPC_CheckType, MVT::f32,
/*7263*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7265*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7274*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR32:f32:$F)
/*7284*/            /*Scope*/ 31, /*->7316*/
/*7285*/              OPC_CheckCondCode, ISD::SETLE,
/*7287*/              OPC_MoveParent,
/*7288*/              OPC_CheckType, MVT::i32,
/*7290*/              OPC_MoveParent,
/*7291*/              OPC_RecordChild1, // #2 = $T
/*7292*/              OPC_RecordChild2, // #3 = $F
/*7293*/              OPC_CheckType, MVT::f32,
/*7295*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7297*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*7306*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETLE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), FGR32:f32:$F)
/*7316*/            /*Scope*/ 31, /*->7348*/
/*7317*/              OPC_CheckCondCode, ISD::SETULE,
/*7319*/              OPC_MoveParent,
/*7320*/              OPC_CheckType, MVT::i32,
/*7322*/              OPC_MoveParent,
/*7323*/              OPC_RecordChild1, // #2 = $T
/*7324*/              OPC_RecordChild2, // #3 = $F
/*7325*/              OPC_CheckType, MVT::f32,
/*7327*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7329*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*7338*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETULE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), FGR32:f32:$F)
/*7348*/            /*Scope*/ 31, /*->7380*/
/*7349*/              OPC_CheckCondCode, ISD::SETEQ,
/*7351*/              OPC_MoveParent,
/*7352*/              OPC_CheckType, MVT::i32,
/*7354*/              OPC_MoveParent,
/*7355*/              OPC_RecordChild1, // #2 = $T
/*7356*/              OPC_RecordChild2, // #3 = $F
/*7357*/              OPC_CheckType, MVT::f32,
/*7359*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7361*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7370*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETEQ:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR32:f32:$F)
/*7380*/            /*Scope*/ 31, /*->7412*/
/*7381*/              OPC_CheckCondCode, ISD::SETNE,
/*7383*/              OPC_MoveParent,
/*7384*/              OPC_CheckType, MVT::i32,
/*7386*/              OPC_MoveParent,
/*7387*/              OPC_RecordChild1, // #2 = $T
/*7388*/              OPC_RecordChild2, // #3 = $F
/*7389*/              OPC_CheckType, MVT::f32,
/*7391*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*7393*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7402*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETNE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVN_I_S:f32 FGR32:f32:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR32:f32:$F)
/*7412*/            /*Scope*/ 31, /*->7444*/
/*7413*/              OPC_CheckCondCode, ISD::SETGE,
/*7415*/              OPC_MoveParent,
/*7416*/              OPC_CheckType, MVT::i32,
/*7418*/              OPC_MoveParent,
/*7419*/              OPC_RecordChild1, // #2 = $T
/*7420*/              OPC_RecordChild2, // #3 = $F
/*7421*/              OPC_CheckType, MVT::f64,
/*7423*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7425*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7434*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, (SLT:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), AFGR64:f64:$F)
/*7444*/            /*Scope*/ 31, /*->7476*/
/*7445*/              OPC_CheckCondCode, ISD::SETUGE,
/*7447*/              OPC_MoveParent,
/*7448*/              OPC_CheckType, MVT::i32,
/*7450*/              OPC_MoveParent,
/*7451*/              OPC_RecordChild1, // #2 = $T
/*7452*/              OPC_RecordChild2, // #3 = $F
/*7453*/              OPC_CheckType, MVT::f64,
/*7455*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7457*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7466*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, (SLTu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), AFGR64:f64:$F)
/*7476*/            /*Scope*/ 31, /*->7508*/
/*7477*/              OPC_CheckCondCode, ISD::SETLE,
/*7479*/              OPC_MoveParent,
/*7480*/              OPC_CheckType, MVT::i32,
/*7482*/              OPC_MoveParent,
/*7483*/              OPC_RecordChild1, // #2 = $T
/*7484*/              OPC_RecordChild2, // #3 = $F
/*7485*/              OPC_CheckType, MVT::f64,
/*7487*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7489*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*7498*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETLE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), AFGR64:f64:$F)
/*7508*/            /*Scope*/ 31, /*->7540*/
/*7509*/              OPC_CheckCondCode, ISD::SETULE,
/*7511*/              OPC_MoveParent,
/*7512*/              OPC_CheckType, MVT::i32,
/*7514*/              OPC_MoveParent,
/*7515*/              OPC_RecordChild1, // #2 = $T
/*7516*/              OPC_RecordChild2, // #3 = $F
/*7517*/              OPC_CheckType, MVT::f64,
/*7519*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7521*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*7530*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETULE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), AFGR64:f64:$F)
/*7540*/            /*Scope*/ 31, /*->7572*/
/*7541*/              OPC_CheckCondCode, ISD::SETEQ,
/*7543*/              OPC_MoveParent,
/*7544*/              OPC_CheckType, MVT::i32,
/*7546*/              OPC_MoveParent,
/*7547*/              OPC_RecordChild1, // #2 = $T
/*7548*/              OPC_RecordChild2, // #3 = $F
/*7549*/              OPC_CheckType, MVT::f64,
/*7551*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7553*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7562*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETEQ:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D32:f64 AFGR64:f64:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), AFGR64:f64:$F)
/*7572*/            /*Scope*/ 31, /*->7604*/
/*7573*/              OPC_CheckCondCode, ISD::SETNE,
/*7575*/              OPC_MoveParent,
/*7576*/              OPC_CheckType, MVT::i32,
/*7578*/              OPC_MoveParent,
/*7579*/              OPC_RecordChild1, // #2 = $T
/*7580*/              OPC_RecordChild2, // #3 = $F
/*7581*/              OPC_CheckType, MVT::f64,
/*7583*/              OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7585*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7594*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETNE:Other), AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVN_I_D32:f64 AFGR64:f64:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), AFGR64:f64:$F)
/*7604*/            /*Scope*/ 31, /*->7636*/
/*7605*/              OPC_CheckCondCode, ISD::SETGE,
/*7607*/              OPC_MoveParent,
/*7608*/              OPC_CheckType, MVT::i32,
/*7610*/              OPC_MoveParent,
/*7611*/              OPC_RecordChild1, // #2 = $T
/*7612*/              OPC_RecordChild2, // #3 = $F
/*7613*/              OPC_CheckType, MVT::f64,
/*7615*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7617*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7626*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLT:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR64:f64:$F)
/*7636*/            /*Scope*/ 31, /*->7668*/
/*7637*/              OPC_CheckCondCode, ISD::SETUGE,
/*7639*/              OPC_MoveParent,
/*7640*/              OPC_CheckType, MVT::i32,
/*7642*/              OPC_MoveParent,
/*7643*/              OPC_RecordChild1, // #2 = $T
/*7644*/              OPC_RecordChild2, // #3 = $F
/*7645*/              OPC_CheckType, MVT::f64,
/*7647*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7649*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7658*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR64:f64:$F)
/*7668*/            /*Scope*/ 31, /*->7700*/
/*7669*/              OPC_CheckCondCode, ISD::SETLE,
/*7671*/              OPC_MoveParent,
/*7672*/              OPC_CheckType, MVT::i32,
/*7674*/              OPC_MoveParent,
/*7675*/              OPC_RecordChild1, // #2 = $T
/*7676*/              OPC_RecordChild2, // #3 = $F
/*7677*/              OPC_CheckType, MVT::f64,
/*7679*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7681*/              OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*7690*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETLE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), FGR64:f64:$F)
/*7700*/            /*Scope*/ 31, /*->7732*/
/*7701*/              OPC_CheckCondCode, ISD::SETULE,
/*7703*/              OPC_MoveParent,
/*7704*/              OPC_CheckType, MVT::i32,
/*7706*/              OPC_MoveParent,
/*7707*/              OPC_RecordChild1, // #2 = $T
/*7708*/              OPC_RecordChild2, // #3 = $F
/*7709*/              OPC_CheckType, MVT::f64,
/*7711*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7713*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*7722*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETULE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), FGR64:f64:$F)
/*7732*/            /*Scope*/ 31, /*->7764*/
/*7733*/              OPC_CheckCondCode, ISD::SETEQ,
/*7735*/              OPC_MoveParent,
/*7736*/              OPC_CheckType, MVT::i32,
/*7738*/              OPC_MoveParent,
/*7739*/              OPC_RecordChild1, // #2 = $T
/*7740*/              OPC_RecordChild2, // #3 = $F
/*7741*/              OPC_CheckType, MVT::f64,
/*7743*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7745*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7754*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETEQ:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR64:f64:$F)
/*7764*/            /*Scope*/ 31, /*->7796*/
/*7765*/              OPC_CheckCondCode, ISD::SETNE,
/*7767*/              OPC_MoveParent,
/*7768*/              OPC_CheckType, MVT::i32,
/*7770*/              OPC_MoveParent,
/*7771*/              OPC_RecordChild1, // #2 = $T
/*7772*/              OPC_RecordChild2, // #3 = $F
/*7773*/              OPC_CheckType, MVT::f64,
/*7775*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7777*/              OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*7786*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETNE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVN_I_D64:f64 FGR64:f64:$T, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), FGR64:f64:$F)
/*7796*/            0, /*End of Scope*/
/*7797*/          0, /*End of Scope*/
/*7798*/        0, /*End of Scope*/
/*7799*/      /*Scope*/ 11|128,5/*651*/, /*->8452*/
/*7801*/        OPC_CheckChild0Type, MVT::i64,
/*7803*/        OPC_Scope, 101, /*->7906*/ // 2 children in Scope
/*7805*/          OPC_MoveChild, 1,
/*7807*/          OPC_CheckInteger, 0, 
/*7809*/          OPC_MoveParent,
/*7810*/          OPC_MoveChild, 2,
/*7812*/          OPC_Scope, 22, /*->7836*/ // 4 children in Scope
/*7814*/            OPC_CheckCondCode, ISD::SETEQ,
/*7816*/            OPC_MoveParent,
/*7817*/            OPC_CheckType, MVT::i32,
/*7819*/            OPC_MoveParent,
/*7820*/            OPC_RecordChild1, // #1 = $T
/*7821*/            OPC_RecordChild2, // #2 = $F
/*7822*/            OPC_CheckType, MVT::f32,
/*7824*/            OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*7826*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_S), 0,
                        1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETEQ:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 11
                    // Dst: (MOVZ_I64_S:f32 FGR32:f32:$T, CPU64Regs:i64:$lhs, FGR32:f32:$F)
/*7836*/          /*Scope*/ 22, /*->7859*/
/*7837*/            OPC_CheckCondCode, ISD::SETNE,
/*7839*/            OPC_MoveParent,
/*7840*/            OPC_CheckType, MVT::i32,
/*7842*/            OPC_MoveParent,
/*7843*/            OPC_RecordChild1, // #1 = $T
/*7844*/            OPC_RecordChild2, // #2 = $F
/*7845*/            OPC_CheckType, MVT::f32,
/*7847*/            OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*7849*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_S), 0,
                        1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETNE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 11
                    // Dst: (MOVN_I64_S:f32 FGR32:f32:$T, CPU64Regs:i64:$lhs, FGR32:f32:$F)
/*7859*/          /*Scope*/ 22, /*->7882*/
/*7860*/            OPC_CheckCondCode, ISD::SETEQ,
/*7862*/            OPC_MoveParent,
/*7863*/            OPC_CheckType, MVT::i32,
/*7865*/            OPC_MoveParent,
/*7866*/            OPC_RecordChild1, // #1 = $T
/*7867*/            OPC_RecordChild2, // #2 = $F
/*7868*/            OPC_CheckType, MVT::f64,
/*7870*/            OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7872*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_D64), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETEQ:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 11
                    // Dst: (MOVZ_I64_D64:f64 FGR64:f64:$T, CPU64Regs:i64:$lhs, FGR64:f64:$F)
/*7882*/          /*Scope*/ 22, /*->7905*/
/*7883*/            OPC_CheckCondCode, ISD::SETNE,
/*7885*/            OPC_MoveParent,
/*7886*/            OPC_CheckType, MVT::i32,
/*7888*/            OPC_MoveParent,
/*7889*/            OPC_RecordChild1, // #1 = $T
/*7890*/            OPC_RecordChild2, // #2 = $F
/*7891*/            OPC_CheckType, MVT::f64,
/*7893*/            OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*7895*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_D64), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETNE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 11
                    // Dst: (MOVN_I64_D64:f64 FGR64:f64:$T, CPU64Regs:i64:$lhs, FGR64:f64:$F)
/*7905*/          0, /*End of Scope*/
/*7906*/        /*Scope*/ 31|128,4/*543*/, /*->8451*/
/*7908*/          OPC_RecordChild1, // #1 = $rhs
/*7909*/          OPC_Scope, 20|128,1/*148*/, /*->8060*/ // 2 children in Scope
/*7912*/            OPC_MoveChild, 1,
/*7914*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*7917*/            OPC_CheckPredicate, 28, // Predicate_immSExt16
/*7919*/            OPC_MoveParent,
/*7920*/            OPC_MoveChild, 2,
/*7922*/            OPC_Scope, 33, /*->7957*/ // 4 children in Scope
/*7924*/              OPC_CheckCondCode, ISD::SETGE,
/*7926*/              OPC_MoveParent,
/*7927*/              OPC_CheckType, MVT::i32,
/*7929*/              OPC_MoveParent,
/*7930*/              OPC_RecordChild1, // #2 = $T
/*7931*/              OPC_RecordChild2, // #3 = $F
/*7932*/              OPC_CheckType, MVT::f32,
/*7934*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*7936*/              OPC_EmitConvertToTarget, 1,
/*7938*/              OPC_EmitNode, TARGET_VAL(Oi::SLTi64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7947*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 10
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTi64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), FGR32:f32:$F)
/*7957*/            /*Scope*/ 33, /*->7991*/
/*7958*/              OPC_CheckCondCode, ISD::SETUGE,
/*7960*/              OPC_MoveParent,
/*7961*/              OPC_CheckType, MVT::i32,
/*7963*/              OPC_MoveParent,
/*7964*/              OPC_RecordChild1, // #2 = $T
/*7965*/              OPC_RecordChild2, // #3 = $F
/*7966*/              OPC_CheckType, MVT::f32,
/*7968*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*7970*/              OPC_EmitConvertToTarget, 1,
/*7972*/              OPC_EmitNode, TARGET_VAL(Oi::SLTiu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*7981*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 10
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTiu64:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh), FGR32:f32:$F)
/*7991*/            /*Scope*/ 33, /*->8025*/
/*7992*/              OPC_CheckCondCode, ISD::SETGE,
/*7994*/              OPC_MoveParent,
/*7995*/              OPC_CheckType, MVT::i32,
/*7997*/              OPC_MoveParent,
/*7998*/              OPC_RecordChild1, // #2 = $T
/*7999*/              OPC_RecordChild2, // #3 = $F
/*8000*/              OPC_CheckType, MVT::f64,
/*8002*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8004*/              OPC_EmitConvertToTarget, 1,
/*8006*/              OPC_EmitNode, TARGET_VAL(Oi::SLTi64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*8015*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 10
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTi64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), FGR64:f64:$F)
/*8025*/            /*Scope*/ 33, /*->8059*/
/*8026*/              OPC_CheckCondCode, ISD::SETUGE,
/*8028*/              OPC_MoveParent,
/*8029*/              OPC_CheckType, MVT::i32,
/*8031*/              OPC_MoveParent,
/*8032*/              OPC_RecordChild1, // #2 = $T
/*8033*/              OPC_RecordChild2, // #3 = $F
/*8034*/              OPC_CheckType, MVT::f64,
/*8036*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8038*/              OPC_EmitConvertToTarget, 1,
/*8040*/              OPC_EmitNode, TARGET_VAL(Oi::SLTiu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*8049*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 5, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh, SETUGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 10
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTiu64:i32 CPU64Regs:i64:$lh, (imm:i64)<<P:Predicate_immSExt16>>:$rh), FGR64:f64:$F)
/*8059*/            0, /*End of Scope*/
/*8060*/          /*Scope*/ 4|128,3/*388*/, /*->8450*/
/*8062*/            OPC_MoveChild, 2,
/*8064*/            OPC_Scope, 31, /*->8097*/ // 12 children in Scope
/*8066*/              OPC_CheckCondCode, ISD::SETGE,
/*8068*/              OPC_MoveParent,
/*8069*/              OPC_CheckType, MVT::i32,
/*8071*/              OPC_MoveParent,
/*8072*/              OPC_RecordChild1, // #2 = $T
/*8073*/              OPC_RecordChild2, // #3 = $F
/*8074*/              OPC_CheckType, MVT::f32,
/*8076*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*8078*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*8087*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLT64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR32:f32:$F)
/*8097*/            /*Scope*/ 31, /*->8129*/
/*8098*/              OPC_CheckCondCode, ISD::SETUGE,
/*8100*/              OPC_MoveParent,
/*8101*/              OPC_CheckType, MVT::i32,
/*8103*/              OPC_MoveParent,
/*8104*/              OPC_RecordChild1, // #2 = $T
/*8105*/              OPC_RecordChild2, // #3 = $F
/*8106*/              OPC_CheckType, MVT::f32,
/*8108*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*8110*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*8119*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETUGE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTu64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR32:f32:$F)
/*8129*/            /*Scope*/ 31, /*->8161*/
/*8130*/              OPC_CheckCondCode, ISD::SETLE,
/*8132*/              OPC_MoveParent,
/*8133*/              OPC_CheckType, MVT::i32,
/*8135*/              OPC_MoveParent,
/*8136*/              OPC_RecordChild1, // #2 = $T
/*8137*/              OPC_RecordChild2, // #3 = $F
/*8138*/              OPC_CheckType, MVT::f32,
/*8140*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*8142*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*8151*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETLE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLT64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), FGR32:f32:$F)
/*8161*/            /*Scope*/ 31, /*->8193*/
/*8162*/              OPC_CheckCondCode, ISD::SETULE,
/*8164*/              OPC_MoveParent,
/*8165*/              OPC_CheckType, MVT::i32,
/*8167*/              OPC_MoveParent,
/*8168*/              OPC_RecordChild1, // #2 = $T
/*8169*/              OPC_RecordChild2, // #3 = $F
/*8170*/              OPC_CheckType, MVT::f32,
/*8172*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*8174*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*8183*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETULE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I_S:f32 FGR32:f32:$T, (SLTu64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), FGR32:f32:$F)
/*8193*/            /*Scope*/ 31, /*->8225*/
/*8194*/              OPC_CheckCondCode, ISD::SETEQ,
/*8196*/              OPC_MoveParent,
/*8197*/              OPC_CheckType, MVT::i32,
/*8199*/              OPC_MoveParent,
/*8200*/              OPC_RecordChild1, // #2 = $T
/*8201*/              OPC_RecordChild2, // #3 = $F
/*8202*/              OPC_CheckType, MVT::f32,
/*8204*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*8206*/              OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                          1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*8215*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETEQ:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVZ_I64_S:f32 FGR32:f32:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR32:f32:$F)
/*8225*/            /*Scope*/ 31, /*->8257*/
/*8226*/              OPC_CheckCondCode, ISD::SETNE,
/*8228*/              OPC_MoveParent,
/*8229*/              OPC_CheckType, MVT::i32,
/*8231*/              OPC_MoveParent,
/*8232*/              OPC_RecordChild1, // #2 = $T
/*8233*/              OPC_RecordChild2, // #3 = $F
/*8234*/              OPC_CheckType, MVT::f32,
/*8236*/              OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*8238*/              OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                          1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*8247*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f32 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETNE:Other), FGR32:f32:$T, FGR32:f32:$F) - Complexity = 6
                      // Dst: (MOVN_I64_S:f32 FGR32:f32:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR32:f32:$F)
/*8257*/            /*Scope*/ 31, /*->8289*/
/*8258*/              OPC_CheckCondCode, ISD::SETGE,
/*8260*/              OPC_MoveParent,
/*8261*/              OPC_CheckType, MVT::i32,
/*8263*/              OPC_MoveParent,
/*8264*/              OPC_RecordChild1, // #2 = $T
/*8265*/              OPC_RecordChild2, // #3 = $F
/*8266*/              OPC_CheckType, MVT::f64,
/*8268*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8270*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*8279*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLT64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR64:f64:$F)
/*8289*/            /*Scope*/ 31, /*->8321*/
/*8290*/              OPC_CheckCondCode, ISD::SETUGE,
/*8292*/              OPC_MoveParent,
/*8293*/              OPC_CheckType, MVT::i32,
/*8295*/              OPC_MoveParent,
/*8296*/              OPC_RecordChild1, // #2 = $T
/*8297*/              OPC_RecordChild2, // #3 = $F
/*8298*/              OPC_CheckType, MVT::f64,
/*8300*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8302*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*8311*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETUGE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTu64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR64:f64:$F)
/*8321*/            /*Scope*/ 31, /*->8353*/
/*8322*/              OPC_CheckCondCode, ISD::SETLE,
/*8324*/              OPC_MoveParent,
/*8325*/              OPC_CheckType, MVT::i32,
/*8327*/              OPC_MoveParent,
/*8328*/              OPC_RecordChild1, // #2 = $T
/*8329*/              OPC_RecordChild2, // #3 = $F
/*8330*/              OPC_CheckType, MVT::f64,
/*8332*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8334*/              OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*8343*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETLE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLT64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), FGR64:f64:$F)
/*8353*/            /*Scope*/ 31, /*->8385*/
/*8354*/              OPC_CheckCondCode, ISD::SETULE,
/*8356*/              OPC_MoveParent,
/*8357*/              OPC_CheckType, MVT::i32,
/*8359*/              OPC_MoveParent,
/*8360*/              OPC_RecordChild1, // #2 = $T
/*8361*/              OPC_RecordChild2, // #3 = $F
/*8362*/              OPC_CheckType, MVT::f64,
/*8364*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8366*/              OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*8375*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETULE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I_D64:f64 FGR64:f64:$T, (SLTu64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), FGR64:f64:$F)
/*8385*/            /*Scope*/ 31, /*->8417*/
/*8386*/              OPC_CheckCondCode, ISD::SETEQ,
/*8388*/              OPC_MoveParent,
/*8389*/              OPC_CheckType, MVT::i32,
/*8391*/              OPC_MoveParent,
/*8392*/              OPC_RecordChild1, // #2 = $T
/*8393*/              OPC_RecordChild2, // #3 = $F
/*8394*/              OPC_CheckType, MVT::f64,
/*8396*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8398*/              OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                          1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*8407*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVZ_I64_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETEQ:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVZ_I64_D64:f64 FGR64:f64:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR64:f64:$F)
/*8417*/            /*Scope*/ 31, /*->8449*/
/*8418*/              OPC_CheckCondCode, ISD::SETNE,
/*8420*/              OPC_MoveParent,
/*8421*/              OPC_CheckType, MVT::i32,
/*8423*/              OPC_MoveParent,
/*8424*/              OPC_RecordChild1, // #2 = $T
/*8425*/              OPC_RecordChild2, // #3 = $F
/*8426*/              OPC_CheckType, MVT::f64,
/*8428*/              OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8430*/              OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                          1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #4
/*8439*/              OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 4, 3, 
                      // Src: (select:f64 (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETNE:Other), FGR64:f64:$T, FGR64:f64:$F) - Complexity = 6
                      // Dst: (MOVN_I64_D64:f64 FGR64:f64:$T, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), FGR64:f64:$F)
/*8449*/            0, /*End of Scope*/
/*8450*/          0, /*End of Scope*/
/*8451*/        0, /*End of Scope*/
/*8452*/      0, /*End of Scope*/
/*8453*/    /*Scope*/ 89, /*->8543*/
/*8454*/      OPC_RecordChild0, // #0 = $cond
/*8455*/      OPC_Scope, 50, /*->8507*/ // 2 children in Scope
/*8457*/        OPC_CheckChild0Type, MVT::i32,
/*8459*/        OPC_RecordChild1, // #1 = $T
/*8460*/        OPC_RecordChild2, // #2 = $F
/*8461*/        OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->8476
/*8464*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8466*/          OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_S), 0,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
                  // Src: (select:f32 CPURegs:i32:$cond, FGR32:f32:$T, FGR32:f32:$F) - Complexity = 3
                  // Dst: (MOVN_I_S:f32 FGR32:f32:$T, CPURegs:i32:$cond, FGR32:f32:$F)
                /*SwitchType*/ 28,  MVT::f64,// ->8506
/*8478*/          OPC_Scope, 12, /*->8492*/ // 2 children in Scope
/*8480*/            OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8482*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_D32), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 CPURegs:i32:$cond, AFGR64:f64:$T, AFGR64:f64:$F) - Complexity = 3
                    // Dst: (MOVN_I_D32:f64 AFGR64:f64:$T, CPURegs:i32:$cond, AFGR64:f64:$F)
/*8492*/          /*Scope*/ 12, /*->8505*/
/*8493*/            OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8495*/            OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I_D64), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                    // Src: (select:f64 CPURegs:i32:$cond, FGR64:f64:$T, FGR64:f64:$F) - Complexity = 3
                    // Dst: (MOVN_I_D64:f64 FGR64:f64:$T, CPURegs:i32:$cond, FGR64:f64:$F)
/*8505*/          0, /*End of Scope*/
                0, // EndSwitchType
/*8507*/      /*Scope*/ 34, /*->8542*/
/*8508*/        OPC_CheckChild0Type, MVT::i64,
/*8510*/        OPC_RecordChild1, // #1 = $T
/*8511*/        OPC_RecordChild2, // #2 = $F
/*8512*/        OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->8527
/*8515*/          OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*8517*/          OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_S), 0,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
                  // Src: (select:f32 CPU64Regs:i64:$cond, FGR32:f32:$T, FGR32:f32:$F) - Complexity = 3
                  // Dst: (MOVN_I64_S:f32 FGR32:f32:$T, CPU64Regs:i64:$cond, FGR32:f32:$F)
                /*SwitchType*/ 12,  MVT::f64,// ->8541
/*8529*/          OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*8531*/          OPC_MorphNodeTo, TARGET_VAL(Oi::MOVN_I64_D64), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
                  // Src: (select:f64 CPU64Regs:i64:$cond, FGR64:f64:$T, FGR64:f64:$F) - Complexity = 3
                  // Dst: (MOVN_I64_D64:f64 FGR64:f64:$T, CPU64Regs:i64:$cond, FGR64:f64:$F)
                0, // EndSwitchType
/*8542*/      0, /*End of Scope*/
/*8543*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 53,  TARGET_VAL(OiISD::Ext),// ->8600
/*8547*/    OPC_RecordChild0, // #0 = $rs
/*8548*/    OPC_RecordChild1, // #1 = $pos
/*8549*/    OPC_MoveChild, 1,
/*8551*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8554*/    OPC_MoveParent,
/*8555*/    OPC_RecordChild2, // #2 = $size
/*8556*/    OPC_MoveChild, 2,
/*8558*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8561*/    OPC_MoveParent,
/*8562*/    OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->8581
/*8565*/      OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*8567*/      OPC_EmitConvertToTarget, 1,
/*8569*/      OPC_EmitConvertToTarget, 2,
/*8571*/      OPC_MorphNodeTo, TARGET_VAL(Oi::EXT), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 3, 4, 
              // Src: (OiExt:i32 CPURegsOpnd:i32:$rs, (imm:i32):$pos, (imm:i32):$size) - Complexity = 9
              // Dst: (EXT:i32 CPURegsOpnd:i32:$rs, (imm:i32):$pos, (imm:i32):$size)
            /*SwitchType*/ 16,  MVT::i64,// ->8599
/*8583*/      OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*8585*/      OPC_EmitConvertToTarget, 1,
/*8587*/      OPC_EmitConvertToTarget, 2,
/*8589*/      OPC_MorphNodeTo, TARGET_VAL(Oi::DEXT), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 3, 4, 
              // Src: (OiExt:i64 CPU64RegsOpnd:i64:$rs, (imm:i32):$pos, (imm:i32):$size) - Complexity = 9
              // Dst: (DEXT:i64 CPU64RegsOpnd:i64:$rs, (imm:i32):$pos, (imm:i32):$size)
            0, // EndSwitchType
          /*SwitchOpcode*/ 56,  TARGET_VAL(OiISD::Ins),// ->8659
/*8603*/    OPC_RecordChild0, // #0 = $rs
/*8604*/    OPC_RecordChild1, // #1 = $pos
/*8605*/    OPC_MoveChild, 1,
/*8607*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8610*/    OPC_MoveParent,
/*8611*/    OPC_RecordChild2, // #2 = $size
/*8612*/    OPC_MoveChild, 2,
/*8614*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8617*/    OPC_MoveParent,
/*8618*/    OPC_RecordChild3, // #3 = $src
/*8619*/    OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->8639
/*8622*/      OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*8624*/      OPC_EmitConvertToTarget, 1,
/*8626*/      OPC_EmitConvertToTarget, 2,
/*8628*/      OPC_MorphNodeTo, TARGET_VAL(Oi::INS), 0,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 4, 5, 3, 
              // Src: (OiIns:i32 CPURegsOpnd:i32:$rs, (imm:i32):$pos, (imm:i32):$size, CPURegsOpnd:i32:$src) - Complexity = 9
              // Dst: (INS:i32 CPURegsOpnd:i32:$rs, (imm:i32):$pos, (imm:i32):$size, CPURegsOpnd:i32:$src)
            /*SwitchType*/ 17,  MVT::i64,// ->8658
/*8641*/      OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*8643*/      OPC_EmitConvertToTarget, 1,
/*8645*/      OPC_EmitConvertToTarget, 2,
/*8647*/      OPC_MorphNodeTo, TARGET_VAL(Oi::DINS), 0,
                  1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 4, 5, 3, 
              // Src: (OiIns:i64 CPU64RegsOpnd:i64:$rs, (imm:i32):$pos, (imm:i32):$size, CPU64RegsOpnd:i64:$src) - Complexity = 9
              // Dst: (DINS:i64 CPU64RegsOpnd:i64:$rs, (imm:i32):$pos, (imm:i32):$size, CPU64RegsOpnd:i64:$src)
            0, // EndSwitchType
          /*SwitchOpcode*/ 82|128,4/*594*/,  TARGET_VAL(ISD::ADD),// ->9257
/*8663*/    OPC_Scope, 110|128,1/*238*/, /*->8904*/ // 3 children in Scope
/*8666*/      OPC_RecordChild0, // #0 = $hi
/*8667*/      OPC_MoveChild, 1,
/*8669*/      OPC_SwitchOpcode /*2 cases */, 57|128,1/*185*/,  TARGET_VAL(OiISD::Lo),// ->8859
/*8674*/        OPC_RecordChild0, // #1 = $lo
/*8675*/        OPC_MoveChild, 0,
/*8677*/        OPC_SwitchOpcode /*5 cases */, 45,  TARGET_VAL(ISD::TargetGlobalAddress),// ->8726
/*8681*/          OPC_MoveParent,
/*8682*/          OPC_MoveParent,
/*8683*/          OPC_SwitchType /*2 cases */, 26,  MVT::i32,// ->8712
/*8686*/            OPC_Scope, 11, /*->8699*/ // 2 children in Scope
/*8688*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8690*/              OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                      // Src: (add:i32 CPURegs:i32:$hi, (OiLo:i32 (tglobaladdr:i32):$lo)) - Complexity = 9
                      // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tglobaladdr:i32):$lo)
/*8699*/            /*Scope*/ 11, /*->8711*/
/*8700*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*8702*/              OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRxImmX16), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                      // Src: (add:i32 CPU16Regs:i32:$hi, (OiLo:i32 (tglobaladdr:i32):$lo)) - Complexity = 9
                      // Dst: (AddiuRxRxImmX16:i32 CPU16Regs:i32:$hi, (tglobaladdr:i32):$lo)
/*8711*/            0, /*End of Scope*/
                  /*SwitchType*/ 11,  MVT::i64,// ->8725
/*8714*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8716*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 CPU64Regs:i64:$hi, (OiLo:i64 (tglobaladdr:i64):$lo)) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tglobaladdr:i64):$lo)
                  0, // EndSwitchType
                /*SwitchOpcode*/ 30,  TARGET_VAL(ISD::TargetBlockAddress),// ->8759
/*8729*/          OPC_MoveParent,
/*8730*/          OPC_MoveParent,
/*8731*/          OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->8745
/*8734*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8736*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 CPURegs:i32:$hi, (OiLo:i32 (tblockaddress:i32):$lo)) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tblockaddress:i32):$lo)
                  /*SwitchType*/ 11,  MVT::i64,// ->8758
/*8747*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8749*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 CPU64Regs:i64:$hi, (OiLo:i64 (tblockaddress:i64):$lo)) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tblockaddress:i64):$lo)
                  0, // EndSwitchType
                /*SwitchOpcode*/ 30,  TARGET_VAL(ISD::TargetJumpTable),// ->8792
/*8762*/          OPC_MoveParent,
/*8763*/          OPC_MoveParent,
/*8764*/          OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->8778
/*8767*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8769*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 CPURegs:i32:$hi, (OiLo:i32 (tjumptable:i32):$lo)) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tjumptable:i32):$lo)
                  /*SwitchType*/ 11,  MVT::i64,// ->8791
/*8780*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8782*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 CPU64Regs:i64:$hi, (OiLo:i64 (tjumptable:i64):$lo)) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tjumptable:i64):$lo)
                  0, // EndSwitchType
                /*SwitchOpcode*/ 30,  TARGET_VAL(ISD::TargetConstantPool),// ->8825
/*8795*/          OPC_MoveParent,
/*8796*/          OPC_MoveParent,
/*8797*/          OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->8811
/*8800*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8802*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 CPURegs:i32:$hi, (OiLo:i32 (tconstpool:i32):$lo)) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tconstpool:i32):$lo)
                  /*SwitchType*/ 11,  MVT::i64,// ->8824
/*8813*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8815*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 CPU64Regs:i64:$hi, (OiLo:i64 (tconstpool:i64):$lo)) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tconstpool:i64):$lo)
                  0, // EndSwitchType
                /*SwitchOpcode*/ 30,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->8858
/*8828*/          OPC_MoveParent,
/*8829*/          OPC_MoveParent,
/*8830*/          OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->8844
/*8833*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8835*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 CPURegs:i32:$hi, (OiLo:i32 (tglobaltlsaddr:i32):$lo)) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tglobaltlsaddr:i32):$lo)
                  /*SwitchType*/ 11,  MVT::i64,// ->8857
/*8846*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8848*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 CPU64Regs:i64:$hi, (OiLo:i64 (tglobaltlsaddr:i64):$lo)) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tglobaltlsaddr:i64):$lo)
                  0, // EndSwitchType
                0, // EndSwitchOpcode
              /*SwitchOpcode*/ 41,  TARGET_VAL(OiISD::GPRel),// ->8903
/*8862*/        OPC_RecordChild0, // #1 = $in
/*8863*/        OPC_MoveChild, 0,
/*8865*/        OPC_SwitchOpcode /*2 cases */, 15,  TARGET_VAL(ISD::TargetGlobalAddress),// ->8884
/*8869*/          OPC_MoveParent,
/*8870*/          OPC_MoveParent,
/*8871*/          OPC_CheckType, MVT::i32,
/*8873*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8875*/          OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 CPURegs:i32:$gp, (OiGPRel:i32 (tglobaladdr:i32):$in)) - Complexity = 9
                  // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tglobaladdr:i32):$in)
                /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::TargetConstantPool),// ->8902
/*8887*/          OPC_MoveParent,
/*8888*/          OPC_MoveParent,
/*8889*/          OPC_CheckType, MVT::i32,
/*8891*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8893*/          OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 CPURegs:i32:$gp, (OiGPRel:i32 (tconstpool:i32):$in)) - Complexity = 9
                  // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tconstpool:i32):$in)
                0, // EndSwitchOpcode
              0, // EndSwitchOpcode
/*8904*/    /*Scope*/ 116|128,1/*244*/, /*->9150*/
/*8906*/      OPC_MoveChild, 0,
/*8908*/      OPC_SwitchOpcode /*2 cases */, 62|128,1/*190*/,  TARGET_VAL(OiISD::Lo),// ->9103
/*8913*/        OPC_RecordChild0, // #0 = $lo
/*8914*/        OPC_MoveChild, 0,
/*8916*/        OPC_SwitchOpcode /*5 cases */, 46,  TARGET_VAL(ISD::TargetGlobalAddress),// ->8966
/*8920*/          OPC_MoveParent,
/*8921*/          OPC_MoveParent,
/*8922*/          OPC_RecordChild1, // #1 = $hi
/*8923*/          OPC_SwitchType /*2 cases */, 11,  MVT::i64,// ->8937
/*8926*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8928*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (OiLo:i64 (tglobaladdr:i64):$lo), CPU64Regs:i64:$hi) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tglobaladdr:i64):$lo)
                  /*SwitchType*/ 26,  MVT::i32,// ->8965
/*8939*/            OPC_Scope, 11, /*->8952*/ // 2 children in Scope
/*8941*/              OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*8943*/              OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRxImmX16), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                      // Src: (add:i32 (OiLo:i32 (tglobaladdr:i32):$lo), CPU16Regs:i32:$hi) - Complexity = 9
                      // Dst: (AddiuRxRxImmX16:i32 CPU16Regs:i32:$hi, (tglobaladdr:i32):$lo)
/*8952*/            /*Scope*/ 11, /*->8964*/
/*8953*/              OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8955*/              OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                      // Src: (add:i32 (OiLo:i32 (tglobaladdr:i32):$lo), CPURegs:i32:$hi) - Complexity = 9
                      // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tglobaladdr:i32):$lo)
/*8964*/            0, /*End of Scope*/
                  0, // EndSwitchType
                /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::TargetBlockAddress),// ->9000
/*8969*/          OPC_MoveParent,
/*8970*/          OPC_MoveParent,
/*8971*/          OPC_RecordChild1, // #1 = $hi
/*8972*/          OPC_SwitchType /*2 cases */, 11,  MVT::i64,// ->8986
/*8975*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8977*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (OiLo:i64 (tblockaddress:i64):$lo), CPU64Regs:i64:$hi) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tblockaddress:i64):$lo)
                  /*SwitchType*/ 11,  MVT::i32,// ->8999
/*8988*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*8990*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (OiLo:i32 (tblockaddress:i32):$lo), CPURegs:i32:$hi) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tblockaddress:i32):$lo)
                  0, // EndSwitchType
                /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::TargetJumpTable),// ->9034
/*9003*/          OPC_MoveParent,
/*9004*/          OPC_MoveParent,
/*9005*/          OPC_RecordChild1, // #1 = $hi
/*9006*/          OPC_SwitchType /*2 cases */, 11,  MVT::i64,// ->9020
/*9009*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9011*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (OiLo:i64 (tjumptable:i64):$lo), CPU64Regs:i64:$hi) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tjumptable:i64):$lo)
                  /*SwitchType*/ 11,  MVT::i32,// ->9033
/*9022*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9024*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (OiLo:i32 (tjumptable:i32):$lo), CPURegs:i32:$hi) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tjumptable:i32):$lo)
                  0, // EndSwitchType
                /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::TargetConstantPool),// ->9068
/*9037*/          OPC_MoveParent,
/*9038*/          OPC_MoveParent,
/*9039*/          OPC_RecordChild1, // #1 = $hi
/*9040*/          OPC_SwitchType /*2 cases */, 11,  MVT::i64,// ->9054
/*9043*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9045*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (OiLo:i64 (tconstpool:i64):$lo), CPU64Regs:i64:$hi) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tconstpool:i64):$lo)
                  /*SwitchType*/ 11,  MVT::i32,// ->9067
/*9056*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9058*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (OiLo:i32 (tconstpool:i32):$lo), CPURegs:i32:$hi) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tconstpool:i32):$lo)
                  0, // EndSwitchType
                /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->9102
/*9071*/          OPC_MoveParent,
/*9072*/          OPC_MoveParent,
/*9073*/          OPC_RecordChild1, // #1 = $hi
/*9074*/          OPC_SwitchType /*2 cases */, 11,  MVT::i64,// ->9088
/*9077*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9079*/            OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (OiLo:i64 (tglobaltlsaddr:i64):$lo), CPU64Regs:i64:$hi) - Complexity = 9
                    // Dst: (DADDiu:i64 CPU64Regs:i64:$hi, (tglobaltlsaddr:i64):$lo)
                  /*SwitchType*/ 11,  MVT::i32,// ->9101
/*9090*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9092*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (OiLo:i32 (tglobaltlsaddr:i32):$lo), CPURegs:i32:$hi) - Complexity = 9
                    // Dst: (ADDiu:i32 CPURegs:i32:$hi, (tglobaltlsaddr:i32):$lo)
                  0, // EndSwitchType
                0, // EndSwitchOpcode
              /*SwitchOpcode*/ 43,  TARGET_VAL(OiISD::GPRel),// ->9149
/*9106*/        OPC_RecordChild0, // #0 = $in
/*9107*/        OPC_MoveChild, 0,
/*9109*/        OPC_SwitchOpcode /*2 cases */, 16,  TARGET_VAL(ISD::TargetGlobalAddress),// ->9129
/*9113*/          OPC_MoveParent,
/*9114*/          OPC_MoveParent,
/*9115*/          OPC_RecordChild1, // #1 = $gp
/*9116*/          OPC_CheckType, MVT::i32,
/*9118*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9120*/          OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (add:i32 (OiGPRel:i32 (tglobaladdr:i32):$in), CPURegs:i32:$gp) - Complexity = 9
                  // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tglobaladdr:i32):$in)
                /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::TargetConstantPool),// ->9148
/*9132*/          OPC_MoveParent,
/*9133*/          OPC_MoveParent,
/*9134*/          OPC_RecordChild1, // #1 = $gp
/*9135*/          OPC_CheckType, MVT::i32,
/*9137*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9139*/          OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (add:i32 (OiGPRel:i32 (tconstpool:i32):$in), CPURegs:i32:$gp) - Complexity = 9
                  // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tconstpool:i32):$in)
                0, // EndSwitchOpcode
              0, // EndSwitchOpcode
/*9150*/    /*Scope*/ 105, /*->9256*/
/*9151*/      OPC_RecordChild0, // #0 = $rs
/*9152*/      OPC_RecordChild1, // #1 = $imm16
/*9153*/      OPC_Scope, 57, /*->9212*/ // 3 children in Scope
/*9155*/        OPC_MoveChild, 1,
/*9157*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*9160*/        OPC_CheckPredicate, 28, // Predicate_immSExt16
/*9162*/        OPC_MoveParent,
/*9163*/        OPC_SwitchType /*2 cases */, 30,  MVT::i32,// ->9196
/*9166*/          OPC_Scope, 13, /*->9181*/ // 2 children in Scope
/*9168*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9170*/            OPC_EmitConvertToTarget, 1,
/*9172*/            OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (add:i32 CPURegsOpnd:i32:$rs, (imm:i32)<<P:Predicate_immSExt16>>:$imm16) - Complexity = 7
                    // Dst: (ADDiu:i32 CPURegsOpnd:i32:$rs, (imm:i32):$imm16)
/*9181*/          /*Scope*/ 13, /*->9195*/
/*9182*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9184*/            OPC_EmitConvertToTarget, 1,
/*9186*/            OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (add:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immSExt16>>:$imm) - Complexity = 7
                    // Dst: (AddiuRxRxImmX16:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immSExt16>>:$imm)
/*9195*/          0, /*End of Scope*/
                /*SwitchType*/ 13,  MVT::i64,// ->9211
/*9198*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9200*/          OPC_EmitConvertToTarget, 1,
/*9202*/          OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (add:i64 CPU64RegsOpnd:i64:$rs, (imm:i64)<<P:Predicate_immSExt16>>:$imm16) - Complexity = 7
                  // Dst: (DADDiu:i64 CPU64RegsOpnd:i64:$rs, (imm:i64):$imm16)
                0, // EndSwitchType
/*9212*/      /*Scope*/ 28, /*->9241*/
/*9213*/        OPC_CheckType, MVT::i32,
/*9215*/        OPC_Scope, 11, /*->9228*/ // 2 children in Scope
/*9217*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9219*/          OPC_MorphNodeTo, TARGET_VAL(Oi::ADDu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
                  // Dst: (ADDu:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*9228*/        /*Scope*/ 11, /*->9240*/
/*9229*/          OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9231*/          OPC_MorphNodeTo, TARGET_VAL(Oi::AdduRxRyRz16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r) - Complexity = 3
                  // Dst: (AdduRxRyRz16:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r)
/*9240*/        0, /*End of Scope*/
/*9241*/      /*Scope*/ 13, /*->9255*/
/*9242*/        OPC_CheckType, MVT::i64,
/*9244*/        OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9246*/        OPC_MorphNodeTo, TARGET_VAL(Oi::DADDu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (add:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt) - Complexity = 3
                // Dst: (DADDu:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
/*9255*/      0, /*End of Scope*/
/*9256*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 67,  TARGET_VAL(ISD::SUB),// ->9327
/*9260*/    OPC_Scope, 18, /*->9280*/ // 2 children in Scope
/*9262*/      OPC_MoveChild, 0,
/*9264*/      OPC_CheckInteger, 0, 
/*9266*/      OPC_MoveParent,
/*9267*/      OPC_RecordChild1, // #0 = $r
/*9268*/      OPC_CheckType, MVT::i32,
/*9270*/      OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9272*/      OPC_MorphNodeTo, TARGET_VAL(Oi::NegRxRy16), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (sub:i32 0:i32, CPU16Regs:i32:$r) - Complexity = 8
              // Dst: (NegRxRy16:i32 CPU16Regs:i32:$r)
/*9280*/    /*Scope*/ 45, /*->9326*/
/*9281*/      OPC_RecordChild0, // #0 = $rs
/*9282*/      OPC_RecordChild1, // #1 = $rt
/*9283*/      OPC_SwitchType /*2 cases */, 26,  MVT::i32,// ->9312
/*9286*/        OPC_Scope, 11, /*->9299*/ // 2 children in Scope
/*9288*/          OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9290*/          OPC_MorphNodeTo, TARGET_VAL(Oi::SUBu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
                  // Dst: (SUBu:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*9299*/        /*Scope*/ 11, /*->9311*/
/*9300*/          OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9302*/          OPC_MorphNodeTo, TARGET_VAL(Oi::SubuRxRyRz16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r) - Complexity = 3
                  // Dst: (SubuRxRyRz16:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r)
/*9311*/        0, /*End of Scope*/
              /*SwitchType*/ 11,  MVT::i64,// ->9325
/*9314*/        OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9316*/        OPC_MorphNodeTo, TARGET_VAL(Oi::DSUBu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt) - Complexity = 3
                // Dst: (DSUBu:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
              0, // EndSwitchType
/*9326*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 5|128,9/*1157*/,  TARGET_VAL(ISD::SETCC),// ->10488
/*9331*/    OPC_RecordChild0, // #0 = $lhs
/*9332*/    OPC_Scope, 16|128,6/*784*/, /*->10119*/ // 2 children in Scope
/*9335*/      OPC_CheckChild0Type, MVT::i32,
/*9337*/      OPC_Scope, 92, /*->9431*/ // 2 children in Scope
/*9339*/        OPC_MoveChild, 1,
/*9341*/        OPC_Scope, 24, /*->9367*/ // 2 children in Scope
/*9343*/          OPC_CheckInteger, 0, 
/*9345*/          OPC_MoveParent,
/*9346*/          OPC_MoveChild, 2,
/*9348*/          OPC_CheckCondCode, ISD::SETEQ,
/*9350*/          OPC_MoveParent,
/*9351*/          OPC_CheckType, MVT::i32,
/*9353*/          OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9355*/          OPC_EmitInteger, MVT::i32, 1, 
/*9358*/          OPC_MorphNodeTo, TARGET_VAL(Oi::SltiuCCRxImmX16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (setcc:i32 CPU16Regs:i32:$lhs, 0:i32, SETEQ:Other) - Complexity = 8
                  // Dst: (SltiuCCRxImmX16:i32 CPU16Regs:i32:$lhs, 1:i32)
/*9367*/        /*Scope*/ 62, /*->9430*/
/*9368*/          OPC_CheckInteger, 127|128,127|128,125|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709518847*/, 
/*9379*/          OPC_MoveParent,
/*9380*/          OPC_MoveChild, 2,
/*9382*/          OPC_CheckCondCode, ISD::SETGT,
/*9384*/          OPC_MoveParent,
/*9385*/          OPC_CheckType, MVT::i32,
/*9387*/          OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9389*/          OPC_EmitInteger, MVT::i32, 0|128,0|128,126|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709518848*/, 
/*9401*/          OPC_EmitNode, TARGET_VAL(Oi::SltiCCRxImmX16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9410*/          OPC_EmitInteger, MVT::i32, 1, 
/*9413*/          OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*9421*/          OPC_MorphNodeTo, TARGET_VAL(Oi::XorRxRxRy16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 4, 
                  // Src: (setcc:i32 CPU16Regs:i32:$lhs, -32769:i32, SETGT:Other) - Complexity = 8
                  // Dst: (XorRxRxRy16:i32 (SltiCCRxImmX16:i32 CPU16Regs:i32:$lhs, -32768:i32), (LiRxImmX16:i32 1:i32))
/*9430*/        0, /*End of Scope*/
/*9431*/      /*Scope*/ 45|128,5/*685*/, /*->10118*/
/*9433*/        OPC_RecordChild1, // #1 = $imm16
/*9434*/        OPC_Scope, 22|128,1/*150*/, /*->9587*/ // 2 children in Scope
/*9437*/          OPC_MoveChild, 1,
/*9439*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*9442*/          OPC_CheckPredicate, 28, // Predicate_immSExt16
/*9444*/          OPC_MoveParent,
/*9445*/          OPC_MoveChild, 2,
/*9447*/          OPC_Scope, 18, /*->9467*/ // 6 children in Scope
/*9449*/            OPC_CheckCondCode, ISD::SETLT,
/*9451*/            OPC_MoveParent,
/*9452*/            OPC_CheckType, MVT::i32,
/*9454*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9456*/            OPC_EmitConvertToTarget, 1,
/*9458*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLTi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (setcc:i32 CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immSExt16>>:$imm16, SETLT:Other) - Complexity = 7
                    // Dst: (SLTi:i32 CPURegs:i32:$rs, (imm:i32):$imm16)
/*9467*/          /*Scope*/ 18, /*->9486*/
/*9468*/            OPC_CheckCondCode, ISD::SETULT,
/*9470*/            OPC_MoveParent,
/*9471*/            OPC_CheckType, MVT::i32,
/*9473*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9475*/            OPC_EmitConvertToTarget, 1,
/*9477*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLTiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (setcc:i32 CPURegs:i32:$rs, (imm:i32)<<P:Predicate_immSExt16>>:$imm16, SETULT:Other) - Complexity = 7
                    // Dst: (SLTiu:i32 CPURegs:i32:$rs, (imm:i32):$imm16)
/*9486*/          /*Scope*/ 18, /*->9505*/
/*9487*/            OPC_CheckCondCode, ISD::SETLT,
/*9489*/            OPC_MoveParent,
/*9490*/            OPC_CheckType, MVT::i32,
/*9492*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9494*/            OPC_EmitConvertToTarget, 1,
/*9496*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SltiCCRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (setcc:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm16, SETLT:Other) - Complexity = 7
                    // Dst: (SltiCCRxImmX16:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm16)
/*9505*/          /*Scope*/ 18, /*->9524*/
/*9506*/            OPC_CheckCondCode, ISD::SETULT,
/*9508*/            OPC_MoveParent,
/*9509*/            OPC_CheckType, MVT::i32,
/*9511*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9513*/            OPC_EmitConvertToTarget, 1,
/*9515*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SltiuCCRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (setcc:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm16, SETULT:Other) - Complexity = 7
                    // Dst: (SltiuCCRxImmX16:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm16)
/*9524*/          /*Scope*/ 30, /*->9555*/
/*9525*/            OPC_CheckCondCode, ISD::SETGE,
/*9527*/            OPC_MoveParent,
/*9528*/            OPC_CheckType, MVT::i32,
/*9530*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9532*/            OPC_EmitConvertToTarget, 1,
/*9534*/            OPC_EmitNode, TARGET_VAL(Oi::SLTi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*9543*/            OPC_EmitInteger, MVT::i32, 1, 
/*9546*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other) - Complexity = 7
                    // Dst: (XORi:i32 (SLTi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), 1:i32)
/*9555*/          /*Scope*/ 30, /*->9586*/
/*9556*/            OPC_CheckCondCode, ISD::SETUGE,
/*9558*/            OPC_MoveParent,
/*9559*/            OPC_CheckType, MVT::i32,
/*9561*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9563*/            OPC_EmitConvertToTarget, 1,
/*9565*/            OPC_EmitNode, TARGET_VAL(Oi::SLTiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*9574*/            OPC_EmitInteger, MVT::i32, 1, 
/*9577*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETUGE:Other) - Complexity = 7
                    // Dst: (XORi:i32 (SLTiu:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), 1:i32)
/*9586*/          0, /*End of Scope*/
/*9587*/        /*Scope*/ 16|128,4/*528*/, /*->10117*/
/*9589*/          OPC_MoveChild, 2,
/*9591*/          OPC_Scope, 16, /*->9609*/ // 20 children in Scope
/*9593*/            OPC_CheckCondCode, ISD::SETLT,
/*9595*/            OPC_MoveParent,
/*9596*/            OPC_CheckType, MVT::i32,
/*9598*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9600*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLT), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (setcc:i32 CPURegs:i32:$rs, CPURegs:i32:$rt, SETLT:Other) - Complexity = 3
                    // Dst: (SLT:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*9609*/          /*Scope*/ 16, /*->9626*/
/*9610*/            OPC_CheckCondCode, ISD::SETULT,
/*9612*/            OPC_MoveParent,
/*9613*/            OPC_CheckType, MVT::i32,
/*9615*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9617*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLTu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (setcc:i32 CPURegs:i32:$rs, CPURegs:i32:$rt, SETULT:Other) - Complexity = 3
                    // Dst: (SLTu:i32 CPURegs:i32:$rs, CPURegs:i32:$rt)
/*9626*/          /*Scope*/ 16, /*->9643*/
/*9627*/            OPC_CheckCondCode, ISD::SETGT,
/*9629*/            OPC_MoveParent,
/*9630*/            OPC_CheckType, MVT::i32,
/*9632*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9634*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLT), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGT:Other) - Complexity = 3
                    // Dst: (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs)
/*9643*/          /*Scope*/ 16, /*->9660*/
/*9644*/            OPC_CheckCondCode, ISD::SETUGT,
/*9646*/            OPC_MoveParent,
/*9647*/            OPC_CheckType, MVT::i32,
/*9649*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9651*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLTu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGT:Other) - Complexity = 3
                    // Dst: (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs)
/*9660*/          /*Scope*/ 16, /*->9677*/
/*9661*/            OPC_CheckCondCode, ISD::SETGT,
/*9663*/            OPC_MoveParent,
/*9664*/            OPC_CheckType, MVT::i32,
/*9666*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9668*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SltCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETGT:Other) - Complexity = 3
                    // Dst: (SltCCRxRy16:i32 CPU16Regs:i32:$rhs, CPU16Regs:i32:$lhs)
/*9677*/          /*Scope*/ 16, /*->9694*/
/*9678*/            OPC_CheckCondCode, ISD::SETLT,
/*9680*/            OPC_MoveParent,
/*9681*/            OPC_CheckType, MVT::i32,
/*9683*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9685*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SltCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETLT:Other) - Complexity = 3
                    // Dst: (SltCCRxRy16:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry)
/*9694*/          /*Scope*/ 16, /*->9711*/
/*9695*/            OPC_CheckCondCode, ISD::SETUGT,
/*9697*/            OPC_MoveParent,
/*9698*/            OPC_CheckType, MVT::i32,
/*9700*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9702*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SltuCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETUGT:Other) - Complexity = 3
                    // Dst: (SltuCCRxRy16:i32 CPU16Regs:i32:$rhs, CPU16Regs:i32:$lhs)
/*9711*/          /*Scope*/ 16, /*->9728*/
/*9712*/            OPC_CheckCondCode, ISD::SETULT,
/*9714*/            OPC_MoveParent,
/*9715*/            OPC_CheckType, MVT::i32,
/*9717*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9719*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SltuCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETULT:Other) - Complexity = 3
                    // Dst: (SltuCCRxRy16:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry)
/*9728*/          /*Scope*/ 28, /*->9757*/
/*9729*/            OPC_CheckCondCode, ISD::SETEQ,
/*9731*/            OPC_MoveParent,
/*9732*/            OPC_CheckType, MVT::i32,
/*9734*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9736*/            OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9745*/            OPC_EmitInteger, MVT::i32, 1, 
/*9748*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLTiu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETEQ:Other) - Complexity = 3
                    // Dst: (SLTiu:i32 (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), 1:i32)
/*9757*/          /*Scope*/ 28, /*->9786*/
/*9758*/            OPC_CheckCondCode, ISD::SETNE,
/*9760*/            OPC_MoveParent,
/*9761*/            OPC_CheckType, MVT::i32,
/*9763*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9765*/            OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*9768*/            OPC_EmitNode, TARGET_VAL(Oi::XOR), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #3
/*9777*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SLTu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETNE:Other) - Complexity = 3
                    // Dst: (SLTu:i32 ZERO:i32, (XOR:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs))
/*9786*/          /*Scope*/ 28, /*->9815*/
/*9787*/            OPC_CheckCondCode, ISD::SETLE,
/*9789*/            OPC_MoveParent,
/*9790*/            OPC_CheckType, MVT::i32,
/*9792*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9794*/            OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*9803*/            OPC_EmitInteger, MVT::i32, 1, 
/*9806*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETLE:Other) - Complexity = 3
                    // Dst: (XORi:i32 (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), 1:i32)
/*9815*/          /*Scope*/ 28, /*->9844*/
/*9816*/            OPC_CheckCondCode, ISD::SETULE,
/*9818*/            OPC_MoveParent,
/*9819*/            OPC_CheckType, MVT::i32,
/*9821*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9823*/            OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*9832*/            OPC_EmitInteger, MVT::i32, 1, 
/*9835*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETULE:Other) - Complexity = 3
                    // Dst: (XORi:i32 (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), 1:i32)
/*9844*/          /*Scope*/ 28, /*->9873*/
/*9845*/            OPC_CheckCondCode, ISD::SETGE,
/*9847*/            OPC_MoveParent,
/*9848*/            OPC_CheckType, MVT::i32,
/*9850*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9852*/            OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9861*/            OPC_EmitInteger, MVT::i32, 1, 
/*9864*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGE:Other) - Complexity = 3
                    // Dst: (XORi:i32 (SLT:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), 1:i32)
/*9873*/          /*Scope*/ 28, /*->9902*/
/*9874*/            OPC_CheckCondCode, ISD::SETUGE,
/*9876*/            OPC_MoveParent,
/*9877*/            OPC_CheckType, MVT::i32,
/*9879*/            OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*9881*/            OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9890*/            OPC_EmitInteger, MVT::i32, 1, 
/*9893*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                    // Src: (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGE:Other) - Complexity = 3
                    // Dst: (XORi:i32 (SLTu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), 1:i32)
/*9902*/          /*Scope*/ 28, /*->9931*/
/*9903*/            OPC_CheckCondCode, ISD::SETEQ,
/*9905*/            OPC_MoveParent,
/*9906*/            OPC_CheckType, MVT::i32,
/*9908*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9910*/            OPC_EmitNode, TARGET_VAL(Oi::XorRxRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9919*/            OPC_EmitInteger, MVT::i32, 1, 
/*9922*/            OPC_MorphNodeTo, TARGET_VAL(Oi::SltiuCCRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETEQ:Other) - Complexity = 3
                    // Dst: (SltiuCCRxImmX16:i32 (XorRxRxRy16:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs), 1:i32)
/*9931*/          /*Scope*/ 36, /*->9968*/
/*9932*/            OPC_CheckCondCode, ISD::SETGE,
/*9934*/            OPC_MoveParent,
/*9935*/            OPC_CheckType, MVT::i32,
/*9937*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9939*/            OPC_EmitNode, TARGET_VAL(Oi::SltCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9948*/            OPC_EmitInteger, MVT::i32, 1, 
/*9951*/            OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*9959*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XorRxRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 4, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETGE:Other) - Complexity = 3
                    // Dst: (XorRxRxRy16:i32 (SltCCRxRy16:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs), (LiRxImmX16:i32 1:i32))
/*9968*/          /*Scope*/ 36, /*->10005*/
/*9969*/            OPC_CheckCondCode, ISD::SETLE,
/*9971*/            OPC_MoveParent,
/*9972*/            OPC_CheckType, MVT::i32,
/*9974*/            OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*9976*/            OPC_EmitNode, TARGET_VAL(Oi::SltCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*9985*/            OPC_EmitInteger, MVT::i32, 1, 
/*9988*/            OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*9996*/            OPC_MorphNodeTo, TARGET_VAL(Oi::XorRxRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 4, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETLE:Other) - Complexity = 3
                    // Dst: (XorRxRxRy16:i32 (SltCCRxRy16:i32 CPU16Regs:i32:$rhs, CPU16Regs:i32:$lhs), (LiRxImmX16:i32 1:i32))
/*10005*/         /*Scope*/ 36, /*->10042*/
/*10006*/           OPC_CheckCondCode, ISD::SETNE,
/*10008*/           OPC_MoveParent,
/*10009*/           OPC_CheckType, MVT::i32,
/*10011*/           OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10013*/           OPC_EmitInteger, MVT::i32, 0, 
/*10016*/           OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*10024*/           OPC_EmitNode, TARGET_VAL(Oi::XorRxRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*10033*/           OPC_MorphNodeTo, TARGET_VAL(Oi::SltuCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETNE:Other) - Complexity = 3
                    // Dst: (SltuCCRxRy16:i32 (LiRxImmX16:i32 0:i32), (XorRxRxRy16:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs))
/*10042*/         /*Scope*/ 36, /*->10079*/
/*10043*/           OPC_CheckCondCode, ISD::SETUGE,
/*10045*/           OPC_MoveParent,
/*10046*/           OPC_CheckType, MVT::i32,
/*10048*/           OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10050*/           OPC_EmitNode, TARGET_VAL(Oi::SltuCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*10059*/           OPC_EmitInteger, MVT::i32, 1, 
/*10062*/           OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*10070*/           OPC_MorphNodeTo, TARGET_VAL(Oi::XorRxRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 4, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETUGE:Other) - Complexity = 3
                    // Dst: (XorRxRxRy16:i32 (SltuCCRxRy16:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs), (LiRxImmX16:i32 1:i32))
/*10079*/         /*Scope*/ 36, /*->10116*/
/*10080*/           OPC_CheckCondCode, ISD::SETULE,
/*10082*/           OPC_MoveParent,
/*10083*/           OPC_CheckType, MVT::i32,
/*10085*/           OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10087*/           OPC_EmitNode, TARGET_VAL(Oi::SltuCCRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*10096*/           OPC_EmitInteger, MVT::i32, 1, 
/*10099*/           OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*10107*/           OPC_MorphNodeTo, TARGET_VAL(Oi::XorRxRxRy16), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 4, 
                    // Src: (setcc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs, SETULE:Other) - Complexity = 3
                    // Dst: (XorRxRxRy16:i32 (SltuCCRxRy16:i32 CPU16Regs:i32:$rhs, CPU16Regs:i32:$lhs), (LiRxImmX16:i32 1:i32))
/*10116*/         0, /*End of Scope*/
/*10117*/       0, /*End of Scope*/
/*10118*/     0, /*End of Scope*/
/*10119*/   /*Scope*/ 110|128,2/*366*/, /*->10487*/
/*10121*/     OPC_CheckChild0Type, MVT::i64,
/*10123*/     OPC_RecordChild1, // #1 = $imm16
/*10124*/     OPC_Scope, 112, /*->10238*/ // 2 children in Scope
/*10126*/       OPC_MoveChild, 1,
/*10128*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*10131*/       OPC_CheckPredicate, 28, // Predicate_immSExt16
/*10133*/       OPC_MoveParent,
/*10134*/       OPC_MoveChild, 2,
/*10136*/       OPC_Scope, 18, /*->10156*/ // 4 children in Scope
/*10138*/         OPC_CheckCondCode, ISD::SETLT,
/*10140*/         OPC_MoveParent,
/*10141*/         OPC_CheckType, MVT::i32,
/*10143*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10145*/         OPC_EmitConvertToTarget, 1,
/*10147*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLTi64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (setcc:i32 CPU64Regs:i64:$rs, (imm:i64)<<P:Predicate_immSExt16>>:$imm16, SETLT:Other) - Complexity = 7
                  // Dst: (SLTi64:i32 CPU64Regs:i64:$rs, (imm:i64):$imm16)
/*10156*/       /*Scope*/ 18, /*->10175*/
/*10157*/         OPC_CheckCondCode, ISD::SETULT,
/*10159*/         OPC_MoveParent,
/*10160*/         OPC_CheckType, MVT::i32,
/*10162*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10164*/         OPC_EmitConvertToTarget, 1,
/*10166*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLTiu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (setcc:i32 CPU64Regs:i64:$rs, (imm:i64)<<P:Predicate_immSExt16>>:$imm16, SETULT:Other) - Complexity = 7
                  // Dst: (SLTiu64:i32 CPU64Regs:i64:$rs, (imm:i64):$imm16)
/*10175*/       /*Scope*/ 30, /*->10206*/
/*10176*/         OPC_CheckCondCode, ISD::SETGE,
/*10178*/         OPC_MoveParent,
/*10179*/         OPC_CheckType, MVT::i32,
/*10181*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10183*/         OPC_EmitConvertToTarget, 1,
/*10185*/         OPC_EmitNode, TARGET_VAL(Oi::SLTi64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*10194*/         OPC_EmitInteger, MVT::i32, 1, 
/*10197*/         OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other) - Complexity = 7
                  // Dst: (XORi:i32 (SLTi64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), 1:i32)
/*10206*/       /*Scope*/ 30, /*->10237*/
/*10207*/         OPC_CheckCondCode, ISD::SETUGE,
/*10209*/         OPC_MoveParent,
/*10210*/         OPC_CheckType, MVT::i32,
/*10212*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10214*/         OPC_EmitConvertToTarget, 1,
/*10216*/         OPC_EmitNode, TARGET_VAL(Oi::SLTiu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*10225*/         OPC_EmitInteger, MVT::i32, 1, 
/*10228*/         OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETUGE:Other) - Complexity = 7
                  // Dst: (XORi:i32 (SLTiu64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), 1:i32)
/*10237*/       0, /*End of Scope*/
/*10238*/     /*Scope*/ 118|128,1/*246*/, /*->10486*/
/*10240*/       OPC_MoveChild, 2,
/*10242*/       OPC_Scope, 16, /*->10260*/ // 10 children in Scope
/*10244*/         OPC_CheckCondCode, ISD::SETLT,
/*10246*/         OPC_MoveParent,
/*10247*/         OPC_CheckType, MVT::i32,
/*10249*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10251*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLT64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (setcc:i32 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt, SETLT:Other) - Complexity = 3
                  // Dst: (SLT64:i32 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt)
/*10260*/       /*Scope*/ 16, /*->10277*/
/*10261*/         OPC_CheckCondCode, ISD::SETULT,
/*10263*/         OPC_MoveParent,
/*10264*/         OPC_CheckType, MVT::i32,
/*10266*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10268*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLTu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (setcc:i32 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt, SETULT:Other) - Complexity = 3
                  // Dst: (SLTu64:i32 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt)
/*10277*/       /*Scope*/ 16, /*->10294*/
/*10278*/         OPC_CheckCondCode, ISD::SETGT,
/*10280*/         OPC_MoveParent,
/*10281*/         OPC_CheckType, MVT::i32,
/*10283*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10285*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLT64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETGT:Other) - Complexity = 3
                  // Dst: (SLT64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs)
/*10294*/       /*Scope*/ 16, /*->10311*/
/*10295*/         OPC_CheckCondCode, ISD::SETUGT,
/*10297*/         OPC_MoveParent,
/*10298*/         OPC_CheckType, MVT::i32,
/*10300*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10302*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLTu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETUGT:Other) - Complexity = 3
                  // Dst: (SLTu64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs)
/*10311*/       /*Scope*/ 28, /*->10340*/
/*10312*/         OPC_CheckCondCode, ISD::SETEQ,
/*10314*/         OPC_MoveParent,
/*10315*/         OPC_CheckType, MVT::i32,
/*10317*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10319*/         OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #2
/*10328*/         OPC_EmitInteger, MVT::i64, 1, 
/*10331*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLTiu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETEQ:Other) - Complexity = 3
                  // Dst: (SLTiu64:i32 (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), 1:i64)
/*10340*/       /*Scope*/ 28, /*->10369*/
/*10341*/         OPC_CheckCondCode, ISD::SETNE,
/*10343*/         OPC_MoveParent,
/*10344*/         OPC_CheckType, MVT::i32,
/*10346*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10348*/         OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*10351*/         OPC_EmitNode, TARGET_VAL(Oi::XOR64), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #3
/*10360*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLTu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETNE:Other) - Complexity = 3
                  // Dst: (SLTu64:i32 ZERO_64:i64, (XOR64:i64 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs))
/*10369*/       /*Scope*/ 28, /*->10398*/
/*10370*/         OPC_CheckCondCode, ISD::SETLE,
/*10372*/         OPC_MoveParent,
/*10373*/         OPC_CheckType, MVT::i32,
/*10375*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10377*/         OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*10386*/         OPC_EmitInteger, MVT::i32, 1, 
/*10389*/         OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETLE:Other) - Complexity = 3
                  // Dst: (XORi:i32 (SLT64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), 1:i32)
/*10398*/       /*Scope*/ 28, /*->10427*/
/*10399*/         OPC_CheckCondCode, ISD::SETULE,
/*10401*/         OPC_MoveParent,
/*10402*/         OPC_CheckType, MVT::i32,
/*10404*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10406*/         OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*10415*/         OPC_EmitInteger, MVT::i32, 1, 
/*10418*/         OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETULE:Other) - Complexity = 3
                  // Dst: (XORi:i32 (SLTu64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), 1:i32)
/*10427*/       /*Scope*/ 28, /*->10456*/
/*10428*/         OPC_CheckCondCode, ISD::SETGE,
/*10430*/         OPC_MoveParent,
/*10431*/         OPC_CheckType, MVT::i32,
/*10433*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10435*/         OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*10444*/         OPC_EmitInteger, MVT::i32, 1, 
/*10447*/         OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETGE:Other) - Complexity = 3
                  // Dst: (XORi:i32 (SLT64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), 1:i32)
/*10456*/       /*Scope*/ 28, /*->10485*/
/*10457*/         OPC_CheckCondCode, ISD::SETUGE,
/*10459*/         OPC_MoveParent,
/*10460*/         OPC_CheckType, MVT::i32,
/*10462*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10464*/         OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*10473*/         OPC_EmitInteger, MVT::i32, 1, 
/*10476*/         OPC_MorphNodeTo, TARGET_VAL(Oi::XORi), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETUGE:Other) - Complexity = 3
                  // Dst: (XORi:i32 (SLTu64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), 1:i32)
/*10485*/       0, /*End of Scope*/
/*10486*/     0, /*End of Scope*/
/*10487*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 94,  TARGET_VAL(ISD::AND),// ->10585
/*10491*/   OPC_RecordChild0, // #0 = $rs
/*10492*/   OPC_RecordChild1, // #1 = $imm16
/*10493*/   OPC_Scope, 46, /*->10541*/ // 3 children in Scope
/*10495*/     OPC_MoveChild, 1,
/*10497*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*10500*/     OPC_CheckPredicate, 27, // Predicate_immZExt16
/*10502*/     OPC_MoveParent,
/*10503*/     OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->10522
/*10506*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10508*/       OPC_EmitConvertToTarget, 1,
/*10510*/       OPC_EmitNodeXForm, 0, 2, // LO16
/*10513*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ANDi), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (and:i32 CPURegsOpnd:i32:$rs, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$imm16) - Complexity = 7
                // Dst: (ANDi:i32 CPURegsOpnd:i32:$rs, (LO16:i32 (imm:i32):$imm16))
              /*SwitchType*/ 16,  MVT::i64,// ->10540
/*10524*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10526*/       OPC_EmitConvertToTarget, 1,
/*10528*/       OPC_EmitNodeXForm, 0, 2, // LO16
/*10531*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DANDi), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (and:i64 CPU64RegsOpnd:i64:$rs, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$imm16) - Complexity = 7
                // Dst: (DANDi:i64 CPU64RegsOpnd:i64:$rs, (LO16:i64 (imm:i64):$imm16))
              0, // EndSwitchType
/*10541*/   /*Scope*/ 28, /*->10570*/
/*10542*/     OPC_CheckType, MVT::i32,
/*10544*/     OPC_Scope, 11, /*->10557*/ // 2 children in Scope
/*10546*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10548*/       OPC_MorphNodeTo, TARGET_VAL(Oi::AND), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
                // Dst: (AND:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*10557*/     /*Scope*/ 11, /*->10569*/
/*10558*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10560*/       OPC_MorphNodeTo, TARGET_VAL(Oi::AndRxRxRy16), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r) - Complexity = 3
                // Dst: (AndRxRxRy16:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r)
/*10569*/     0, /*End of Scope*/
/*10570*/   /*Scope*/ 13, /*->10584*/
/*10571*/     OPC_CheckType, MVT::i64,
/*10573*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10575*/     OPC_MorphNodeTo, TARGET_VAL(Oi::AND64), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (and:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt) - Complexity = 3
              // Dst: (AND64:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
/*10584*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 94,  TARGET_VAL(ISD::OR),// ->10682
/*10588*/   OPC_RecordChild0, // #0 = $rs
/*10589*/   OPC_RecordChild1, // #1 = $imm16
/*10590*/   OPC_Scope, 46, /*->10638*/ // 3 children in Scope
/*10592*/     OPC_MoveChild, 1,
/*10594*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*10597*/     OPC_CheckPredicate, 27, // Predicate_immZExt16
/*10599*/     OPC_MoveParent,
/*10600*/     OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->10619
/*10603*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10605*/       OPC_EmitConvertToTarget, 1,
/*10607*/       OPC_EmitNodeXForm, 0, 2, // LO16
/*10610*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ORi), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (or:i32 CPURegsOpnd:i32:$rs, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$imm16) - Complexity = 7
                // Dst: (ORi:i32 CPURegsOpnd:i32:$rs, (LO16:i32 (imm:i32):$imm16))
              /*SwitchType*/ 16,  MVT::i64,// ->10637
/*10621*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10623*/       OPC_EmitConvertToTarget, 1,
/*10625*/       OPC_EmitNodeXForm, 0, 2, // LO16
/*10628*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ORi64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (or:i64 CPU64RegsOpnd:i64:$rs, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$imm16) - Complexity = 7
                // Dst: (ORi64:i64 CPU64RegsOpnd:i64:$rs, (LO16:i64 (imm:i64):$imm16))
              0, // EndSwitchType
/*10638*/   /*Scope*/ 28, /*->10667*/
/*10639*/     OPC_CheckType, MVT::i32,
/*10641*/     OPC_Scope, 11, /*->10654*/ // 2 children in Scope
/*10643*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10645*/       OPC_MorphNodeTo, TARGET_VAL(Oi::OR), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
                // Dst: (OR:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*10654*/     /*Scope*/ 11, /*->10666*/
/*10655*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10657*/       OPC_MorphNodeTo, TARGET_VAL(Oi::OrRxRxRy16), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r) - Complexity = 3
                // Dst: (OrRxRxRy16:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r)
/*10666*/     0, /*End of Scope*/
/*10667*/   /*Scope*/ 13, /*->10681*/
/*10668*/     OPC_CheckType, MVT::i64,
/*10670*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10672*/     OPC_MorphNodeTo, TARGET_VAL(Oi::OR64), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (or:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt) - Complexity = 3
              // Dst: (OR64:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
/*10681*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 117,  TARGET_VAL(ISD::SHL),// ->10802
/*10685*/   OPC_RecordChild0, // #0 = $rt
/*10686*/   OPC_RecordChild1, // #1 = $shamt
/*10687*/   OPC_Scope, 66, /*->10755*/ // 2 children in Scope
/*10689*/     OPC_MoveChild, 1,
/*10691*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*10694*/     OPC_CheckType, MVT::i32,
/*10696*/     OPC_Scope, 18, /*->10716*/ // 3 children in Scope
/*10698*/       OPC_CheckPredicate, 21, // Predicate_immZExt5
/*10700*/       OPC_MoveParent,
/*10701*/       OPC_CheckType, MVT::i32,
/*10703*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10705*/       OPC_EmitConvertToTarget, 1,
/*10707*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SLL), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (shl:i32 CPURegsOpnd:i32:$rt, (imm:i32)<<P:Predicate_immZExt5>>:$shamt) - Complexity = 7
                // Dst: (SLL:i32 CPURegsOpnd:i32:$rt, (imm:i32):$shamt)
/*10716*/     /*Scope*/ 18, /*->10735*/
/*10717*/       OPC_CheckPredicate, 29, // Predicate_immZExt6
/*10719*/       OPC_MoveParent,
/*10720*/       OPC_CheckType, MVT::i64,
/*10722*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10724*/       OPC_EmitConvertToTarget, 1,
/*10726*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DSLL), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (shl:i64 CPU64RegsOpnd:i64:$rt, (imm:i32)<<P:Predicate_immZExt6>>:$shamt) - Complexity = 7
                // Dst: (DSLL:i64 CPU64RegsOpnd:i64:$rt, (imm:i32):$shamt)
/*10735*/     /*Scope*/ 18, /*->10754*/
/*10736*/       OPC_CheckPredicate, 21, // Predicate_immZExt5
/*10738*/       OPC_MoveParent,
/*10739*/       OPC_CheckType, MVT::i32,
/*10741*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10743*/       OPC_EmitConvertToTarget, 1,
/*10745*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SllX16), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (shl:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immZExt5>>:$imm) - Complexity = 7
                // Dst: (SllX16:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immZExt5>>:$imm)
/*10754*/     0, /*End of Scope*/
/*10755*/   /*Scope*/ 45, /*->10801*/
/*10756*/     OPC_CheckChild1Type, MVT::i32,
/*10758*/     OPC_SwitchType /*2 cases */, 26,  MVT::i32,// ->10787
/*10761*/       OPC_Scope, 11, /*->10774*/ // 2 children in Scope
/*10763*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10765*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SLLV), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (shl:i32 CPURegsOpnd:i32:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                  // Dst: (SLLV:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*10774*/       /*Scope*/ 11, /*->10786*/
/*10775*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10777*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SllvRxRy16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (shl:i32 CPU16Regs:i32:$r, CPU16Regs:i32:$ra) - Complexity = 3
                  // Dst: (SllvRxRy16:i32 CPU16Regs:i32:$r, CPU16Regs:i32:$ra)
/*10786*/       0, /*End of Scope*/
              /*SwitchType*/ 11,  MVT::i64,// ->10800
/*10789*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10791*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DSLLV), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (shl:i64 CPU64RegsOpnd:i64:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                // Dst: (DSLLV:i64 CPURegsOpnd:i32:$rs, CPU64RegsOpnd:i64:$rt)
              0, // EndSwitchType
/*10801*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 117,  TARGET_VAL(ISD::SRL),// ->10922
/*10805*/   OPC_RecordChild0, // #0 = $rt
/*10806*/   OPC_RecordChild1, // #1 = $shamt
/*10807*/   OPC_Scope, 66, /*->10875*/ // 2 children in Scope
/*10809*/     OPC_MoveChild, 1,
/*10811*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*10814*/     OPC_CheckType, MVT::i32,
/*10816*/     OPC_Scope, 18, /*->10836*/ // 3 children in Scope
/*10818*/       OPC_CheckPredicate, 21, // Predicate_immZExt5
/*10820*/       OPC_MoveParent,
/*10821*/       OPC_CheckType, MVT::i32,
/*10823*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10825*/       OPC_EmitConvertToTarget, 1,
/*10827*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SRL), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (srl:i32 CPURegsOpnd:i32:$rt, (imm:i32)<<P:Predicate_immZExt5>>:$shamt) - Complexity = 7
                // Dst: (SRL:i32 CPURegsOpnd:i32:$rt, (imm:i32):$shamt)
/*10836*/     /*Scope*/ 18, /*->10855*/
/*10837*/       OPC_CheckPredicate, 29, // Predicate_immZExt6
/*10839*/       OPC_MoveParent,
/*10840*/       OPC_CheckType, MVT::i64,
/*10842*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10844*/       OPC_EmitConvertToTarget, 1,
/*10846*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DSRL), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (srl:i64 CPU64RegsOpnd:i64:$rt, (imm:i32)<<P:Predicate_immZExt6>>:$shamt) - Complexity = 7
                // Dst: (DSRL:i64 CPU64RegsOpnd:i64:$rt, (imm:i32):$shamt)
/*10855*/     /*Scope*/ 18, /*->10874*/
/*10856*/       OPC_CheckPredicate, 21, // Predicate_immZExt5
/*10858*/       OPC_MoveParent,
/*10859*/       OPC_CheckType, MVT::i32,
/*10861*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10863*/       OPC_EmitConvertToTarget, 1,
/*10865*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SrlX16), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (srl:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immZExt5>>:$imm) - Complexity = 7
                // Dst: (SrlX16:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immZExt5>>:$imm)
/*10874*/     0, /*End of Scope*/
/*10875*/   /*Scope*/ 45, /*->10921*/
/*10876*/     OPC_CheckChild1Type, MVT::i32,
/*10878*/     OPC_SwitchType /*2 cases */, 26,  MVT::i32,// ->10907
/*10881*/       OPC_Scope, 11, /*->10894*/ // 2 children in Scope
/*10883*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10885*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SRLV), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (srl:i32 CPURegsOpnd:i32:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                  // Dst: (SRLV:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*10894*/       /*Scope*/ 11, /*->10906*/
/*10895*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10897*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SrlvRxRy16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (srl:i32 CPU16Regs:i32:$r, CPU16Regs:i32:$ra) - Complexity = 3
                  // Dst: (SrlvRxRy16:i32 CPU16Regs:i32:$r, CPU16Regs:i32:$ra)
/*10906*/       0, /*End of Scope*/
              /*SwitchType*/ 11,  MVT::i64,// ->10920
/*10909*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10911*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DSRLV), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (srl:i64 CPU64RegsOpnd:i64:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                // Dst: (DSRLV:i64 CPURegsOpnd:i32:$rs, CPU64RegsOpnd:i64:$rt)
              0, // EndSwitchType
/*10921*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 117,  TARGET_VAL(ISD::SRA),// ->11042
/*10925*/   OPC_RecordChild0, // #0 = $rt
/*10926*/   OPC_RecordChild1, // #1 = $shamt
/*10927*/   OPC_Scope, 66, /*->10995*/ // 2 children in Scope
/*10929*/     OPC_MoveChild, 1,
/*10931*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*10934*/     OPC_CheckType, MVT::i32,
/*10936*/     OPC_Scope, 18, /*->10956*/ // 3 children in Scope
/*10938*/       OPC_CheckPredicate, 21, // Predicate_immZExt5
/*10940*/       OPC_MoveParent,
/*10941*/       OPC_CheckType, MVT::i32,
/*10943*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10945*/       OPC_EmitConvertToTarget, 1,
/*10947*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SRA), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i32 CPURegsOpnd:i32:$rt, (imm:i32)<<P:Predicate_immZExt5>>:$shamt) - Complexity = 7
                // Dst: (SRA:i32 CPURegsOpnd:i32:$rt, (imm:i32):$shamt)
/*10956*/     /*Scope*/ 18, /*->10975*/
/*10957*/       OPC_CheckPredicate, 29, // Predicate_immZExt6
/*10959*/       OPC_MoveParent,
/*10960*/       OPC_CheckType, MVT::i64,
/*10962*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*10964*/       OPC_EmitConvertToTarget, 1,
/*10966*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DSRA), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i64 CPU64RegsOpnd:i64:$rt, (imm:i32)<<P:Predicate_immZExt6>>:$shamt) - Complexity = 7
                // Dst: (DSRA:i64 CPU64RegsOpnd:i64:$rt, (imm:i32):$shamt)
/*10975*/     /*Scope*/ 18, /*->10994*/
/*10976*/       OPC_CheckPredicate, 21, // Predicate_immZExt5
/*10978*/       OPC_MoveParent,
/*10979*/       OPC_CheckType, MVT::i32,
/*10981*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*10983*/       OPC_EmitConvertToTarget, 1,
/*10985*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SraX16), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immZExt5>>:$imm) - Complexity = 7
                // Dst: (SraX16:i32 CPU16Regs:i32:$in, (imm:i32)<<P:Predicate_immZExt5>>:$imm)
/*10994*/     0, /*End of Scope*/
/*10995*/   /*Scope*/ 45, /*->11041*/
/*10996*/     OPC_CheckChild1Type, MVT::i32,
/*10998*/     OPC_SwitchType /*2 cases */, 26,  MVT::i32,// ->11027
/*11001*/       OPC_Scope, 11, /*->11014*/ // 2 children in Scope
/*11003*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11005*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SRAV), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (sra:i32 CPURegsOpnd:i32:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                  // Dst: (SRAV:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*11014*/       /*Scope*/ 11, /*->11026*/
/*11015*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*11017*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SravRxRy16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sra:i32 CPU16Regs:i32:$r, CPU16Regs:i32:$ra) - Complexity = 3
                  // Dst: (SravRxRy16:i32 CPU16Regs:i32:$r, CPU16Regs:i32:$ra)
/*11026*/       0, /*End of Scope*/
              /*SwitchType*/ 11,  MVT::i64,// ->11040
/*11029*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11031*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DSRAV), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (sra:i64 CPU64RegsOpnd:i64:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                // Dst: (DSRAV:i64 CPURegsOpnd:i32:$rs, CPU64RegsOpnd:i64:$rt)
              0, // EndSwitchType
/*11041*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ROTR),// ->11128
/*11045*/   OPC_RecordChild0, // #0 = $rt
/*11046*/   OPC_RecordChild1, // #1 = $shamt
/*11047*/   OPC_Scope, 47, /*->11096*/ // 2 children in Scope
/*11049*/     OPC_MoveChild, 1,
/*11051*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11054*/     OPC_CheckType, MVT::i32,
/*11056*/     OPC_Scope, 18, /*->11076*/ // 2 children in Scope
/*11058*/       OPC_CheckPredicate, 21, // Predicate_immZExt5
/*11060*/       OPC_MoveParent,
/*11061*/       OPC_CheckType, MVT::i32,
/*11063*/       OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*11065*/       OPC_EmitConvertToTarget, 1,
/*11067*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ROTR), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (rotr:i32 CPURegsOpnd:i32:$rt, (imm:i32)<<P:Predicate_immZExt5>>:$shamt) - Complexity = 7
                // Dst: (ROTR:i32 CPURegsOpnd:i32:$rt, (imm:i32):$shamt)
/*11076*/     /*Scope*/ 18, /*->11095*/
/*11077*/       OPC_CheckPredicate, 29, // Predicate_immZExt6
/*11079*/       OPC_MoveParent,
/*11080*/       OPC_CheckType, MVT::i64,
/*11082*/       OPC_CheckPatternPredicate, 16, // (Subtarget.hasOi64r2()) && (Subtarget.hasStandardEncoding())
/*11084*/       OPC_EmitConvertToTarget, 1,
/*11086*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DROTR), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (rotr:i64 CPU64RegsOpnd:i64:$rt, (imm:i32)<<P:Predicate_immZExt6>>:$shamt) - Complexity = 7
                // Dst: (DROTR:i64 CPU64RegsOpnd:i64:$rt, (imm:i32):$shamt)
/*11095*/     0, /*End of Scope*/
/*11096*/   /*Scope*/ 30, /*->11127*/
/*11097*/     OPC_CheckChild1Type, MVT::i32,
/*11099*/     OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->11113
/*11102*/       OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*11104*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ROTRV), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (rotr:i32 CPURegsOpnd:i32:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                // Dst: (ROTRV:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
              /*SwitchType*/ 11,  MVT::i64,// ->11126
/*11115*/       OPC_CheckPatternPredicate, 16, // (Subtarget.hasOi64r2()) && (Subtarget.hasStandardEncoding())
/*11117*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DROTRV), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (rotr:i64 CPU64RegsOpnd:i64:$rt, CPURegsOpnd:i32:$rs) - Complexity = 3
                // Dst: (DROTRV:i64 CPURegsOpnd:i32:$rs, CPU64RegsOpnd:i64:$rt)
              0, // EndSwitchType
/*11127*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 74,  TARGET_VAL(ISD::ADDC),// ->11205
/*11131*/   OPC_RecordChild0, // #0 = $src
/*11132*/   OPC_RecordChild1, // #1 = $imm
/*11133*/   OPC_Scope, 40, /*->11175*/ // 2 children in Scope
/*11135*/     OPC_MoveChild, 1,
/*11137*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11140*/     OPC_CheckPredicate, 28, // Predicate_immSExt16
/*11142*/     OPC_MoveParent,
/*11143*/     OPC_CheckType, MVT::i32,
/*11145*/     OPC_Scope, 13, /*->11160*/ // 2 children in Scope
/*11147*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11149*/       OPC_EmitConvertToTarget, 1,
/*11151*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (addc:i32 CPURegs:i32:$src, (imm:i32)<<P:Predicate_immSExt16>>:$imm) - Complexity = 7
                // Dst: (ADDiu:i32 CPURegs:i32:$src, (imm:i32):$imm)
/*11160*/     /*Scope*/ 13, /*->11174*/
/*11161*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*11163*/       OPC_EmitConvertToTarget, 1,
/*11165*/       OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRxImmX16), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (addc:i32 CPU16Regs:i32:$src, (imm:i32)<<P:Predicate_immSExt16>>:$imm) - Complexity = 7
                // Dst: (AddiuRxRxImmX16:i32 CPU16Regs:i32:$src, (imm:i32):$imm)
/*11174*/     0, /*End of Scope*/
/*11175*/   /*Scope*/ 28, /*->11204*/
/*11176*/     OPC_CheckType, MVT::i32,
/*11178*/     OPC_Scope, 11, /*->11191*/ // 2 children in Scope
/*11180*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11182*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDu), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (addc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs) - Complexity = 3
                // Dst: (ADDu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs)
/*11191*/     /*Scope*/ 11, /*->11203*/
/*11192*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*11194*/       OPC_MorphNodeTo, TARGET_VAL(Oi::AdduRxRyRz16), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (addc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs) - Complexity = 3
                // Dst: (AdduRxRyRz16:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs)
/*11203*/     0, /*End of Scope*/
/*11204*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 47,  TARGET_VAL(OiISD::EXTP),// ->11255
/*11208*/   OPC_RecordNode,   // #0 = 'OiEXTP' chained node
/*11209*/   OPC_CaptureGlueInput,
/*11210*/   OPC_RecordChild1, // #1 = $shift
/*11211*/   OPC_Scope, 25, /*->11238*/ // 2 children in Scope
/*11213*/     OPC_MoveChild, 1,
/*11215*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11218*/     OPC_CheckPredicate, 21, // Predicate_immZExt5
/*11220*/     OPC_MoveParent,
/*11221*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11223*/     OPC_EmitMergeInputChains1_0,
/*11224*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11227*/     OPC_EmitConvertToTarget, 1,
/*11229*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (OiEXTP:i32 (imm:i32)<<P:Predicate_immZExt5>>:$shift) - Complexity = 7
              // Dst: (EXTP:i32 AC0:i64, (imm:i32)<<P:Predicate_immZExt5>>:$shift)
/*11238*/   /*Scope*/ 15, /*->11254*/
/*11239*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11241*/     OPC_EmitMergeInputChains1_0,
/*11242*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11245*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTPV), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (OiEXTP:i32 CPURegs:i32:$rs) - Complexity = 3
              // Dst: (EXTPV:i32 AC0:i64, CPURegs:i32:$rs)
/*11254*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 47,  TARGET_VAL(OiISD::EXTPDP),// ->11305
/*11258*/   OPC_RecordNode,   // #0 = 'OiEXTPDP' chained node
/*11259*/   OPC_CaptureGlueInput,
/*11260*/   OPC_RecordChild1, // #1 = $shift
/*11261*/   OPC_Scope, 25, /*->11288*/ // 2 children in Scope
/*11263*/     OPC_MoveChild, 1,
/*11265*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11268*/     OPC_CheckPredicate, 21, // Predicate_immZExt5
/*11270*/     OPC_MoveParent,
/*11271*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11273*/     OPC_EmitMergeInputChains1_0,
/*11274*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11277*/     OPC_EmitConvertToTarget, 1,
/*11279*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTPDP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (OiEXTPDP:i32 (imm:i32)<<P:Predicate_immZExt5>>:$shift) - Complexity = 7
              // Dst: (EXTPDP:i32 AC0:i64, (imm:i32)<<P:Predicate_immZExt5>>:$shift)
/*11288*/   /*Scope*/ 15, /*->11304*/
/*11289*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11291*/     OPC_EmitMergeInputChains1_0,
/*11292*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11295*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTPDPV), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (OiEXTPDP:i32 CPURegs:i32:$rs) - Complexity = 3
              // Dst: (EXTPDPV:i32 AC0:i64, CPURegs:i32:$rs)
/*11304*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 47,  TARGET_VAL(OiISD::EXTR_W),// ->11355
/*11308*/   OPC_RecordNode,   // #0 = 'OiEXTR_W' chained node
/*11309*/   OPC_CaptureGlueInput,
/*11310*/   OPC_RecordChild1, // #1 = $shift
/*11311*/   OPC_Scope, 25, /*->11338*/ // 2 children in Scope
/*11313*/     OPC_MoveChild, 1,
/*11315*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11318*/     OPC_CheckPredicate, 21, // Predicate_immZExt5
/*11320*/     OPC_MoveParent,
/*11321*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11323*/     OPC_EmitMergeInputChains1_0,
/*11324*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11327*/     OPC_EmitConvertToTarget, 1,
/*11329*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTR_W), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (OiEXTR_W:i32 (imm:i32)<<P:Predicate_immZExt5>>:$shift) - Complexity = 7
              // Dst: (EXTR_W:i32 AC0:i64, (imm:i32)<<P:Predicate_immZExt5>>:$shift)
/*11338*/   /*Scope*/ 15, /*->11354*/
/*11339*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11341*/     OPC_EmitMergeInputChains1_0,
/*11342*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11345*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTRV_W), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (OiEXTR_W:i32 CPURegs:i32:$rs) - Complexity = 3
              // Dst: (EXTRV_W:i32 AC0:i64, CPURegs:i32:$rs)
/*11354*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 47,  TARGET_VAL(OiISD::EXTR_R_W),// ->11405
/*11358*/   OPC_RecordNode,   // #0 = 'OiEXTR_R_W' chained node
/*11359*/   OPC_CaptureGlueInput,
/*11360*/   OPC_RecordChild1, // #1 = $shift
/*11361*/   OPC_Scope, 25, /*->11388*/ // 2 children in Scope
/*11363*/     OPC_MoveChild, 1,
/*11365*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11368*/     OPC_CheckPredicate, 21, // Predicate_immZExt5
/*11370*/     OPC_MoveParent,
/*11371*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11373*/     OPC_EmitMergeInputChains1_0,
/*11374*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11377*/     OPC_EmitConvertToTarget, 1,
/*11379*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTR_R_W), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (OiEXTR_R_W:i32 (imm:i32)<<P:Predicate_immZExt5>>:$shift) - Complexity = 7
              // Dst: (EXTR_R_W:i32 AC0:i64, (imm:i32)<<P:Predicate_immZExt5>>:$shift)
/*11388*/   /*Scope*/ 15, /*->11404*/
/*11389*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11391*/     OPC_EmitMergeInputChains1_0,
/*11392*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11395*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTRV_R_W), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (OiEXTR_R_W:i32 CPURegs:i32:$rs) - Complexity = 3
              // Dst: (EXTRV_R_W:i32 AC0:i64, CPURegs:i32:$rs)
/*11404*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 47,  TARGET_VAL(OiISD::EXTR_RS_W),// ->11455
/*11408*/   OPC_RecordNode,   // #0 = 'OiEXTR_RS_W' chained node
/*11409*/   OPC_CaptureGlueInput,
/*11410*/   OPC_RecordChild1, // #1 = $shift
/*11411*/   OPC_Scope, 25, /*->11438*/ // 2 children in Scope
/*11413*/     OPC_MoveChild, 1,
/*11415*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11418*/     OPC_CheckPredicate, 21, // Predicate_immZExt5
/*11420*/     OPC_MoveParent,
/*11421*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11423*/     OPC_EmitMergeInputChains1_0,
/*11424*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11427*/     OPC_EmitConvertToTarget, 1,
/*11429*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTR_RS_W), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (OiEXTR_RS_W:i32 (imm:i32)<<P:Predicate_immZExt5>>:$shift) - Complexity = 7
              // Dst: (EXTR_RS_W:i32 AC0:i64, (imm:i32)<<P:Predicate_immZExt5>>:$shift)
/*11438*/   /*Scope*/ 15, /*->11454*/
/*11439*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11441*/     OPC_EmitMergeInputChains1_0,
/*11442*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11445*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTRV_RS_W), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (OiEXTR_RS_W:i32 CPURegs:i32:$rs) - Complexity = 3
              // Dst: (EXTRV_RS_W:i32 AC0:i64, CPURegs:i32:$rs)
/*11454*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 47,  TARGET_VAL(OiISD::EXTR_S_H),// ->11505
/*11458*/   OPC_RecordNode,   // #0 = 'OiEXTR_S_H' chained node
/*11459*/   OPC_CaptureGlueInput,
/*11460*/   OPC_RecordChild1, // #1 = $shift
/*11461*/   OPC_Scope, 25, /*->11488*/ // 2 children in Scope
/*11463*/     OPC_MoveChild, 1,
/*11465*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11468*/     OPC_CheckPredicate, 21, // Predicate_immZExt5
/*11470*/     OPC_MoveParent,
/*11471*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11473*/     OPC_EmitMergeInputChains1_0,
/*11474*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11477*/     OPC_EmitConvertToTarget, 1,
/*11479*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTR_S_H), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (OiEXTR_S_H:i32 (imm:i32)<<P:Predicate_immZExt5>>:$shift) - Complexity = 7
              // Dst: (EXTR_S_H:i32 AC0:i64, (imm:i32)<<P:Predicate_immZExt5>>:$shift)
/*11488*/   /*Scope*/ 15, /*->11504*/
/*11489*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*11491*/     OPC_EmitMergeInputChains1_0,
/*11492*/     OPC_EmitRegister, MVT::i64, Oi::AC0,
/*11495*/     OPC_MorphNodeTo, TARGET_VAL(Oi::EXTRV_S_H), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (OiEXTR_S_H:i32 CPURegs:i32:$rs) - Complexity = 3
              // Dst: (EXTRV_S_H:i32 AC0:i64, CPURegs:i32:$rs)
/*11504*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 83|128,1/*211*/,  TARGET_VAL(OiISD::Hi),// ->11720
/*11509*/   OPC_RecordChild0, // #0 = $in
/*11510*/   OPC_MoveChild, 0,
/*11512*/   OPC_SwitchOpcode /*6 cases */, 27,  TARGET_VAL(ISD::TargetGlobalAddress),// ->11543
/*11516*/     OPC_MoveParent,
/*11517*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->11530
/*11520*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11522*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (OiHi:i32 (tglobaladdr:i32):$in) - Complexity = 6
                // Dst: (LUi:i32 (tglobaladdr:i32):$in)
              /*SwitchType*/ 10,  MVT::i64,// ->11542
/*11532*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11534*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (OiHi:i64 (tglobaladdr:i64):$in) - Complexity = 6
                // Dst: (LUi64:i64 (tglobaladdr:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 27,  TARGET_VAL(ISD::TargetBlockAddress),// ->11573
/*11546*/     OPC_MoveParent,
/*11547*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->11560
/*11550*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11552*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (OiHi:i32 (tblockaddress:i32):$in) - Complexity = 6
                // Dst: (LUi:i32 (tblockaddress:i32):$in)
              /*SwitchType*/ 10,  MVT::i64,// ->11572
/*11562*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11564*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (OiHi:i64 (tblockaddress:i64):$in) - Complexity = 6
                // Dst: (LUi64:i64 (tblockaddress:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 27,  TARGET_VAL(ISD::TargetJumpTable),// ->11603
/*11576*/     OPC_MoveParent,
/*11577*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->11590
/*11580*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11582*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (OiHi:i32 (tjumptable:i32):$in) - Complexity = 6
                // Dst: (LUi:i32 (tjumptable:i32):$in)
              /*SwitchType*/ 10,  MVT::i64,// ->11602
/*11592*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11594*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (OiHi:i64 (tjumptable:i64):$in) - Complexity = 6
                // Dst: (LUi64:i64 (tjumptable:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 27,  TARGET_VAL(ISD::TargetConstantPool),// ->11633
/*11606*/     OPC_MoveParent,
/*11607*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->11620
/*11610*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11612*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (OiHi:i32 (tconstpool:i32):$in) - Complexity = 6
                // Dst: (LUi:i32 (tconstpool:i32):$in)
              /*SwitchType*/ 10,  MVT::i64,// ->11632
/*11622*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11624*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (OiHi:i64 (tconstpool:i64):$in) - Complexity = 6
                // Dst: (LUi64:i64 (tconstpool:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 53,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->11689
/*11636*/     OPC_MoveParent,
/*11637*/     OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->11676
/*11640*/       OPC_Scope, 10, /*->11652*/ // 2 children in Scope
/*11642*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11644*/         OPC_MorphNodeTo, TARGET_VAL(Oi::LUi), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (OiHi:i32 (tglobaltlsaddr:i32):$in) - Complexity = 6
                  // Dst: (LUi:i32 (tglobaltlsaddr:i32):$in)
/*11652*/       /*Scope*/ 22, /*->11675*/
/*11653*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*11655*/         OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #1
/*11663*/         OPC_EmitInteger, MVT::i32, 16, 
/*11666*/         OPC_MorphNodeTo, TARGET_VAL(Oi::SllX16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (OiHi:i32 (tglobaltlsaddr:i32):$in) - Complexity = 6
                  // Dst: (SllX16:i32 (LiRxImmX16:i32 (tglobaltlsaddr:i32):$in), 16:i32)
/*11675*/       0, /*End of Scope*/
              /*SwitchType*/ 10,  MVT::i64,// ->11688
/*11678*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11680*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (OiHi:i64 (tglobaltlsaddr:i64):$in) - Complexity = 6
                // Dst: (LUi64:i64 (tglobaltlsaddr:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 27,  TARGET_VAL(ISD::TargetExternalSymbol),// ->11719
/*11692*/     OPC_MoveParent,
/*11693*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->11706
/*11696*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11698*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (OiHi:i32 (texternalsym:i32):$in) - Complexity = 6
                // Dst: (LUi:i32 (texternalsym:i32):$in)
              /*SwitchType*/ 10,  MVT::i64,// ->11718
/*11708*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11710*/       OPC_MorphNodeTo, TARGET_VAL(Oi::LUi64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (OiHi:i64 (texternalsym:i64):$in) - Complexity = 6
                // Dst: (LUi64:i64 (texternalsym:i64):$in)
              0, // EndSwitchType
            0, // EndSwitchOpcode
          /*SwitchOpcode*/ 105|128,1/*233*/,  TARGET_VAL(OiISD::Lo),// ->11957
/*11724*/   OPC_RecordChild0, // #0 = $in
/*11725*/   OPC_MoveChild, 0,
/*11727*/   OPC_SwitchOpcode /*6 cases */, 35,  TARGET_VAL(ISD::TargetGlobalAddress),// ->11766
/*11731*/     OPC_MoveParent,
/*11732*/     OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->11749
/*11735*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11737*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*11740*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i32 (tglobaladdr:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 ZERO:i32, (tglobaladdr:i32):$in)
              /*SwitchType*/ 14,  MVT::i64,// ->11765
/*11751*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11753*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*11756*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i64 (tglobaladdr:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 ZERO_64:i64, (tglobaladdr:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::TargetBlockAddress),// ->11804
/*11769*/     OPC_MoveParent,
/*11770*/     OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->11787
/*11773*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11775*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*11778*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i32 (tblockaddress:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 ZERO:i32, (tblockaddress:i32):$in)
              /*SwitchType*/ 14,  MVT::i64,// ->11803
/*11789*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11791*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*11794*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i64 (tblockaddress:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 ZERO_64:i64, (tblockaddress:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::TargetJumpTable),// ->11842
/*11807*/     OPC_MoveParent,
/*11808*/     OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->11825
/*11811*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11813*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*11816*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i32 (tjumptable:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 ZERO:i32, (tjumptable:i32):$in)
              /*SwitchType*/ 14,  MVT::i64,// ->11841
/*11827*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11829*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*11832*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i64 (tjumptable:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 ZERO_64:i64, (tjumptable:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::TargetConstantPool),// ->11880
/*11845*/     OPC_MoveParent,
/*11846*/     OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->11863
/*11849*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11851*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*11854*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i32 (tconstpool:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 ZERO:i32, (tconstpool:i32):$in)
              /*SwitchType*/ 14,  MVT::i64,// ->11879
/*11865*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11867*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*11870*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i64 (tconstpool:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 ZERO_64:i64, (tconstpool:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->11918
/*11883*/     OPC_MoveParent,
/*11884*/     OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->11901
/*11887*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11889*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*11892*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i32 (tglobaltlsaddr:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 ZERO:i32, (tglobaltlsaddr:i32):$in)
              /*SwitchType*/ 14,  MVT::i64,// ->11917
/*11903*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11905*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*11908*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i64 (tglobaltlsaddr:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 ZERO_64:i64, (tglobaltlsaddr:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::TargetExternalSymbol),// ->11956
/*11921*/     OPC_MoveParent,
/*11922*/     OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->11939
/*11925*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11927*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*11930*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i32 (texternalsym:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 ZERO:i32, (texternalsym:i32):$in)
              /*SwitchType*/ 14,  MVT::i64,// ->11955
/*11941*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11943*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*11946*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (OiLo:i64 (texternalsym:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 ZERO_64:i64, (texternalsym:i64):$in)
              0, // EndSwitchType
            0, // EndSwitchOpcode
          /*SwitchOpcode*/ 100|128,1/*228*/,  TARGET_VAL(OiISD::Wrapper),// ->12189
/*11961*/   OPC_RecordChild0, // #0 = $gp
/*11962*/   OPC_RecordChild1, // #1 = $in
/*11963*/   OPC_MoveChild, 1,
/*11965*/   OPC_SwitchOpcode /*6 cases */, 44,  TARGET_VAL(ISD::TargetGlobalAddress),// ->12013
/*11969*/     OPC_MoveParent,
/*11970*/     OPC_SwitchType /*2 cases */, 26,  MVT::i32,// ->11999
/*11973*/       OPC_Scope, 11, /*->11986*/ // 2 children in Scope
/*11975*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*11977*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (OiWrapper:i32 CPURegs:i32:$gp, (tglobaladdr:i32):$in) - Complexity = 6
                  // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tglobaladdr:i32):$in)
/*11986*/       /*Scope*/ 11, /*->11998*/
/*11987*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*11989*/         OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRxImmX16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (OiWrapper:i32 CPU16Regs:i32:$gp, (tglobaladdr:i32):$in) - Complexity = 6
                  // Dst: (AddiuRxRxImmX16:i32 CPU16Regs:i32:$gp, (tglobaladdr:i32):$in)
/*11998*/       0, /*End of Scope*/
              /*SwitchType*/ 11,  MVT::i64,// ->12012
/*12001*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12003*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i64 CPU64Regs:i64:$gp, (tglobaladdr:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 CPU64Regs:i64:$gp, (tglobaladdr:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 29,  TARGET_VAL(ISD::TargetConstantPool),// ->12045
/*12016*/     OPC_MoveParent,
/*12017*/     OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->12031
/*12020*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12022*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i32 CPURegs:i32:$gp, (tconstpool:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tconstpool:i32):$in)
              /*SwitchType*/ 11,  MVT::i64,// ->12044
/*12033*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12035*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i64 CPU64Regs:i64:$gp, (tconstpool:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 CPU64Regs:i64:$gp, (tconstpool:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 29,  TARGET_VAL(ISD::TargetExternalSymbol),// ->12077
/*12048*/     OPC_MoveParent,
/*12049*/     OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->12063
/*12052*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12054*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i32 CPURegs:i32:$gp, (texternalsym:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 CPURegs:i32:$gp, (texternalsym:i32):$in)
              /*SwitchType*/ 11,  MVT::i64,// ->12076
/*12065*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12067*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i64 CPU64Regs:i64:$gp, (texternalsym:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 CPU64Regs:i64:$gp, (texternalsym:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 29,  TARGET_VAL(ISD::TargetBlockAddress),// ->12109
/*12080*/     OPC_MoveParent,
/*12081*/     OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->12095
/*12084*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12086*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i32 CPURegs:i32:$gp, (tblockaddress:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tblockaddress:i32):$in)
              /*SwitchType*/ 11,  MVT::i64,// ->12108
/*12097*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12099*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i64 CPU64Regs:i64:$gp, (tblockaddress:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 CPU64Regs:i64:$gp, (tblockaddress:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 29,  TARGET_VAL(ISD::TargetJumpTable),// ->12141
/*12112*/     OPC_MoveParent,
/*12113*/     OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->12127
/*12116*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12118*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i32 CPURegs:i32:$gp, (tjumptable:i32):$in) - Complexity = 6
                // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tjumptable:i32):$in)
              /*SwitchType*/ 11,  MVT::i64,// ->12140
/*12129*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12131*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i64 CPU64Regs:i64:$gp, (tjumptable:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 CPU64Regs:i64:$gp, (tjumptable:i64):$in)
              0, // EndSwitchType
            /*SwitchOpcode*/ 44,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->12188
/*12144*/     OPC_MoveParent,
/*12145*/     OPC_SwitchType /*2 cases */, 26,  MVT::i32,// ->12174
/*12148*/       OPC_Scope, 11, /*->12161*/ // 2 children in Scope
/*12150*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12152*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (OiWrapper:i32 CPURegs:i32:$gp, (tglobaltlsaddr:i32):$in) - Complexity = 6
                  // Dst: (ADDiu:i32 CPURegs:i32:$gp, (tglobaltlsaddr:i32):$in)
/*12161*/       /*Scope*/ 11, /*->12173*/
/*12162*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*12164*/         OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRxImmX16), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (OiWrapper:i32 CPU16Regs:i32:$gp, (tglobaltlsaddr:i32):$in) - Complexity = 6
                  // Dst: (AddiuRxRxImmX16:i32 CPU16Regs:i32:$gp, (tglobaltlsaddr:i32):$in)
/*12173*/       0, /*End of Scope*/
              /*SwitchType*/ 11,  MVT::i64,// ->12187
/*12176*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12178*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DADDiu), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (OiWrapper:i64 CPU64Regs:i64:$gp, (tglobaltlsaddr:i64):$in) - Complexity = 6
                // Dst: (DADDiu:i64 CPU64Regs:i64:$gp, (tglobaltlsaddr:i64):$in)
              0, // EndSwitchType
            0, // EndSwitchOpcode
          /*SwitchOpcode*/ 21,  TARGET_VAL(OiISD::ExtractElementF64),// ->12213
/*12192*/   OPC_RecordChild0, // #0 = $src
/*12193*/   OPC_RecordChild1, // #1 = $n
/*12194*/   OPC_MoveChild, 1,
/*12196*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12199*/   OPC_MoveParent,
/*12200*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12202*/   OPC_EmitConvertToTarget, 1,
/*12204*/   OPC_MorphNodeTo, TARGET_VAL(Oi::ExtractElementF64), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
            // Src: (OiExtractElementF64:i32 AFGR64:f64:$src, (imm:i32):$n) - Complexity = 6
            // Dst: (ExtractElementF64:i32 AFGR64:f64:$src, (imm:i32):$n)
          /*SwitchOpcode*/ 61|128,1/*189*/,  TARGET_VAL(ISD::Constant),// ->12406
/*12217*/   OPC_RecordNode,   // #0 = $in
/*12218*/   OPC_CheckType, MVT::i32,
/*12220*/   OPC_Scope, 18, /*->12240*/ // 6 children in Scope
/*12222*/     OPC_CheckPredicate, 28, // Predicate_immSExt16
/*12224*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12226*/     OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*12229*/     OPC_EmitConvertToTarget, 0,
/*12231*/     OPC_MorphNodeTo, TARGET_VAL(Oi::ADDiu), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (imm:i32)<<P:Predicate_immSExt16>>:$in - Complexity = 4
              // Dst: (ADDiu:i32 ZERO:i32, (imm:i32):$in)
/*12240*/   /*Scope*/ 18, /*->12259*/
/*12241*/     OPC_CheckPredicate, 27, // Predicate_immZExt16
/*12243*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12245*/     OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*12248*/     OPC_EmitConvertToTarget, 0,
/*12250*/     OPC_MorphNodeTo, TARGET_VAL(Oi::ORi), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$in - Complexity = 4
              // Dst: (ORi:i32 ZERO:i32, (imm:i32):$in)
/*12259*/   /*Scope*/ 17, /*->12277*/
/*12260*/     OPC_CheckPredicate, 30, // Predicate_immLow16Zero
/*12262*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12264*/     OPC_EmitConvertToTarget, 0,
/*12266*/     OPC_EmitNodeXForm, 1, 1, // HI16
/*12269*/     OPC_MorphNodeTo, TARGET_VAL(Oi::LUi), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (imm:i32)<<P:Predicate_immLow16Zero>>:$in - Complexity = 4
              // Dst: (LUi:i32 (HI16:i32 (imm:i32):$in))
/*12277*/   /*Scope*/ 17, /*->12295*/
/*12278*/     OPC_CheckPredicate, 27, // Predicate_immZExt16
/*12280*/     OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*12282*/     OPC_EmitConvertToTarget, 0,
/*12284*/     OPC_EmitNodeXForm, 0, 1, // LO16
/*12287*/     OPC_MorphNodeTo, TARGET_VAL(Oi::LiRxImmX16), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$in - Complexity = 4
              // Dst: (LiRxImmX16:i32 (LO16:i32 (imm:i32)<<P:Predicate_immZExt16>>:$in))
/*12295*/   /*Scope*/ 26, /*->12322*/
/*12296*/     OPC_CheckPredicate, 28, // Predicate_immSExt16
/*12298*/     OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*12300*/     OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*12303*/     OPC_EmitNode, TARGET_VAL(Oi::Move32R16), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*12311*/     OPC_EmitConvertToTarget, 0,
/*12313*/     OPC_MorphNodeTo, TARGET_VAL(Oi::AddiuRxRxImmX16), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (imm:i32)<<P:Predicate_immSExt16>>:$in - Complexity = 4
              // Dst: (AddiuRxRxImmX16:i32 (Move32R16:i32 ZERO:i32), (imm:i32)<<P:Predicate_immSExt16>>:$in)
/*12322*/   /*Scope*/ 82, /*->12405*/
/*12323*/     OPC_Scope, 29, /*->12354*/ // 2 children in Scope
/*12325*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12327*/       OPC_EmitConvertToTarget, 0,
/*12329*/       OPC_EmitNodeXForm, 1, 1, // HI16
/*12332*/       OPC_EmitNode, TARGET_VAL(Oi::LUi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*12340*/       OPC_EmitConvertToTarget, 0,
/*12342*/       OPC_EmitNodeXForm, 0, 4, // LO16
/*12345*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ORi), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 5, 
                // Src: (imm:i32):$imm - Complexity = 3
                // Dst: (ORi:i32 (LUi:i32 (HI16:i32 (imm:i32):$imm)), (LO16:i32 (imm:i32):$imm))
/*12354*/     /*Scope*/ 49, /*->12404*/
/*12355*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*12357*/       OPC_EmitConvertToTarget, 0,
/*12359*/       OPC_EmitNodeXForm, 1, 1, // HI16
/*12362*/       OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*12370*/       OPC_EmitInteger, MVT::i32, 16, 
/*12373*/       OPC_EmitNode, TARGET_VAL(Oi::SllX16), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*12382*/       OPC_EmitConvertToTarget, 0,
/*12384*/       OPC_EmitNodeXForm, 0, 6, // LO16
/*12387*/       OPC_EmitNode, TARGET_VAL(Oi::LiRxImmX16), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 7,  // Results = #8
/*12395*/       OPC_MorphNodeTo, TARGET_VAL(Oi::OrRxRxRy16), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 5, 8, 
                // Src: (imm:i32):$imm - Complexity = 3
                // Dst: (OrRxRxRy16:i32 (SllX16:i32 (LiRxImmX16:i32 (HI16:i32 (imm:i32):$imm)), 16:i32), (LiRxImmX16:i32 (LO16:i32 (imm:i32):$imm)))
/*12404*/     0, /*End of Scope*/
/*12405*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 19|128,1/*147*/,  TARGET_VAL(ISD::ATOMIC_LOAD_ADD),// ->12557
/*12410*/   OPC_RecordMemRef,
/*12411*/   OPC_RecordNode,   // #0 = 'atomic_load_add' chained node
/*12412*/   OPC_RecordChild1, // #1 = $ptr
/*12413*/   OPC_Scope, 70, /*->12485*/ // 2 children in Scope
/*12415*/     OPC_CheckChild1Type, MVT::i32,
/*12417*/     OPC_RecordChild2, // #2 = $incr
/*12418*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12468
/*12421*/       OPC_Scope, 14, /*->12437*/ // 3 children in Scope
/*12423*/         OPC_CheckPredicate, 31, // Predicate_atomic_load_add_8
/*12425*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12427*/         OPC_EmitMergeInputChains1_0,
/*12428*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_add:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_add_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_ADD_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12437*/       /*Scope*/ 14, /*->12452*/
/*12438*/         OPC_CheckPredicate, 32, // Predicate_atomic_load_add_16
/*12440*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12442*/         OPC_EmitMergeInputChains1_0,
/*12443*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_add:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_add_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_ADD_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12452*/       /*Scope*/ 14, /*->12467*/
/*12453*/         OPC_CheckPredicate, 33, // Predicate_atomic_load_add_32
/*12455*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12457*/         OPC_EmitMergeInputChains1_0,
/*12458*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_add:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_add_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_ADD_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12467*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->12484
/*12470*/       OPC_CheckPredicate, 34, // Predicate_atomic_load_add_64
/*12472*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12474*/       OPC_EmitMergeInputChains1_0,
/*12475*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_add:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_add_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_ADD_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*12485*/   /*Scope*/ 70, /*->12556*/
/*12486*/     OPC_CheckChild1Type, MVT::i64,
/*12488*/     OPC_RecordChild2, // #2 = $incr
/*12489*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12539
/*12492*/       OPC_Scope, 14, /*->12508*/ // 3 children in Scope
/*12494*/         OPC_CheckPredicate, 31, // Predicate_atomic_load_add_8
/*12496*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12498*/         OPC_EmitMergeInputChains1_0,
/*12499*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_add:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_add_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_ADD_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12508*/       /*Scope*/ 14, /*->12523*/
/*12509*/         OPC_CheckPredicate, 32, // Predicate_atomic_load_add_16
/*12511*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12513*/         OPC_EmitMergeInputChains1_0,
/*12514*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_add:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_add_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_ADD_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12523*/       /*Scope*/ 14, /*->12538*/
/*12524*/         OPC_CheckPredicate, 33, // Predicate_atomic_load_add_32
/*12526*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12528*/         OPC_EmitMergeInputChains1_0,
/*12529*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_add:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_add_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_ADD_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12538*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->12555
/*12541*/       OPC_CheckPredicate, 34, // Predicate_atomic_load_add_64
/*12543*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12545*/       OPC_EmitMergeInputChains1_0,
/*12546*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_ADD_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_add:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_add_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_ADD_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*12556*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 19|128,1/*147*/,  TARGET_VAL(ISD::ATOMIC_LOAD_SUB),// ->12708
/*12561*/   OPC_RecordMemRef,
/*12562*/   OPC_RecordNode,   // #0 = 'atomic_load_sub' chained node
/*12563*/   OPC_RecordChild1, // #1 = $ptr
/*12564*/   OPC_Scope, 70, /*->12636*/ // 2 children in Scope
/*12566*/     OPC_CheckChild1Type, MVT::i32,
/*12568*/     OPC_RecordChild2, // #2 = $incr
/*12569*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12619
/*12572*/       OPC_Scope, 14, /*->12588*/ // 3 children in Scope
/*12574*/         OPC_CheckPredicate, 35, // Predicate_atomic_load_sub_8
/*12576*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12578*/         OPC_EmitMergeInputChains1_0,
/*12579*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_sub:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_sub_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_SUB_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12588*/       /*Scope*/ 14, /*->12603*/
/*12589*/         OPC_CheckPredicate, 36, // Predicate_atomic_load_sub_16
/*12591*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12593*/         OPC_EmitMergeInputChains1_0,
/*12594*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_sub:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_sub_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_SUB_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12603*/       /*Scope*/ 14, /*->12618*/
/*12604*/         OPC_CheckPredicate, 37, // Predicate_atomic_load_sub_32
/*12606*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12608*/         OPC_EmitMergeInputChains1_0,
/*12609*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_sub:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_sub_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_SUB_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12618*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->12635
/*12621*/       OPC_CheckPredicate, 38, // Predicate_atomic_load_sub_64
/*12623*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12625*/       OPC_EmitMergeInputChains1_0,
/*12626*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_sub:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_sub_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_SUB_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*12636*/   /*Scope*/ 70, /*->12707*/
/*12637*/     OPC_CheckChild1Type, MVT::i64,
/*12639*/     OPC_RecordChild2, // #2 = $incr
/*12640*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12690
/*12643*/       OPC_Scope, 14, /*->12659*/ // 3 children in Scope
/*12645*/         OPC_CheckPredicate, 35, // Predicate_atomic_load_sub_8
/*12647*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12649*/         OPC_EmitMergeInputChains1_0,
/*12650*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_sub:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_sub_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_SUB_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12659*/       /*Scope*/ 14, /*->12674*/
/*12660*/         OPC_CheckPredicate, 36, // Predicate_atomic_load_sub_16
/*12662*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12664*/         OPC_EmitMergeInputChains1_0,
/*12665*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_sub:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_sub_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_SUB_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12674*/       /*Scope*/ 14, /*->12689*/
/*12675*/         OPC_CheckPredicate, 37, // Predicate_atomic_load_sub_32
/*12677*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12679*/         OPC_EmitMergeInputChains1_0,
/*12680*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_sub:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_sub_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_SUB_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12689*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->12706
/*12692*/       OPC_CheckPredicate, 38, // Predicate_atomic_load_sub_64
/*12694*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12696*/       OPC_EmitMergeInputChains1_0,
/*12697*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_SUB_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_sub:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_sub_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_SUB_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*12707*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 19|128,1/*147*/,  TARGET_VAL(ISD::ATOMIC_LOAD_AND),// ->12859
/*12712*/   OPC_RecordMemRef,
/*12713*/   OPC_RecordNode,   // #0 = 'atomic_load_and' chained node
/*12714*/   OPC_RecordChild1, // #1 = $ptr
/*12715*/   OPC_Scope, 70, /*->12787*/ // 2 children in Scope
/*12717*/     OPC_CheckChild1Type, MVT::i32,
/*12719*/     OPC_RecordChild2, // #2 = $incr
/*12720*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12770
/*12723*/       OPC_Scope, 14, /*->12739*/ // 3 children in Scope
/*12725*/         OPC_CheckPredicate, 39, // Predicate_atomic_load_and_8
/*12727*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12729*/         OPC_EmitMergeInputChains1_0,
/*12730*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_and:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_and_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_AND_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12739*/       /*Scope*/ 14, /*->12754*/
/*12740*/         OPC_CheckPredicate, 40, // Predicate_atomic_load_and_16
/*12742*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12744*/         OPC_EmitMergeInputChains1_0,
/*12745*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_and:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_and_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_AND_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12754*/       /*Scope*/ 14, /*->12769*/
/*12755*/         OPC_CheckPredicate, 41, // Predicate_atomic_load_and_32
/*12757*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12759*/         OPC_EmitMergeInputChains1_0,
/*12760*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_and:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_and_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_AND_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12769*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->12786
/*12772*/       OPC_CheckPredicate, 42, // Predicate_atomic_load_and_64
/*12774*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12776*/       OPC_EmitMergeInputChains1_0,
/*12777*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_and:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_and_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_AND_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*12787*/   /*Scope*/ 70, /*->12858*/
/*12788*/     OPC_CheckChild1Type, MVT::i64,
/*12790*/     OPC_RecordChild2, // #2 = $incr
/*12791*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12841
/*12794*/       OPC_Scope, 14, /*->12810*/ // 3 children in Scope
/*12796*/         OPC_CheckPredicate, 39, // Predicate_atomic_load_and_8
/*12798*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12800*/         OPC_EmitMergeInputChains1_0,
/*12801*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_and:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_and_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_AND_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12810*/       /*Scope*/ 14, /*->12825*/
/*12811*/         OPC_CheckPredicate, 40, // Predicate_atomic_load_and_16
/*12813*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12815*/         OPC_EmitMergeInputChains1_0,
/*12816*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_and:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_and_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_AND_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12825*/       /*Scope*/ 14, /*->12840*/
/*12826*/         OPC_CheckPredicate, 41, // Predicate_atomic_load_and_32
/*12828*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12830*/         OPC_EmitMergeInputChains1_0,
/*12831*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_and:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_and_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_AND_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12840*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->12857
/*12843*/       OPC_CheckPredicate, 42, // Predicate_atomic_load_and_64
/*12845*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12847*/       OPC_EmitMergeInputChains1_0,
/*12848*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_AND_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_and:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_and_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_AND_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*12858*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 19|128,1/*147*/,  TARGET_VAL(ISD::ATOMIC_LOAD_OR),// ->13010
/*12863*/   OPC_RecordMemRef,
/*12864*/   OPC_RecordNode,   // #0 = 'atomic_load_or' chained node
/*12865*/   OPC_RecordChild1, // #1 = $ptr
/*12866*/   OPC_Scope, 70, /*->12938*/ // 2 children in Scope
/*12868*/     OPC_CheckChild1Type, MVT::i32,
/*12870*/     OPC_RecordChild2, // #2 = $incr
/*12871*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12921
/*12874*/       OPC_Scope, 14, /*->12890*/ // 3 children in Scope
/*12876*/         OPC_CheckPredicate, 43, // Predicate_atomic_load_or_8
/*12878*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12880*/         OPC_EmitMergeInputChains1_0,
/*12881*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_or:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_or_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_OR_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12890*/       /*Scope*/ 14, /*->12905*/
/*12891*/         OPC_CheckPredicate, 44, // Predicate_atomic_load_or_16
/*12893*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12895*/         OPC_EmitMergeInputChains1_0,
/*12896*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_or:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_or_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_OR_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12905*/       /*Scope*/ 14, /*->12920*/
/*12906*/         OPC_CheckPredicate, 45, // Predicate_atomic_load_or_32
/*12908*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12910*/         OPC_EmitMergeInputChains1_0,
/*12911*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_or:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_or_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_OR_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*12920*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->12937
/*12923*/       OPC_CheckPredicate, 46, // Predicate_atomic_load_or_64
/*12925*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12927*/       OPC_EmitMergeInputChains1_0,
/*12928*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_or:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_or_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_OR_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*12938*/   /*Scope*/ 70, /*->13009*/
/*12939*/     OPC_CheckChild1Type, MVT::i64,
/*12941*/     OPC_RecordChild2, // #2 = $incr
/*12942*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->12992
/*12945*/       OPC_Scope, 14, /*->12961*/ // 3 children in Scope
/*12947*/         OPC_CheckPredicate, 43, // Predicate_atomic_load_or_8
/*12949*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12951*/         OPC_EmitMergeInputChains1_0,
/*12952*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_or:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_or_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_OR_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12961*/       /*Scope*/ 14, /*->12976*/
/*12962*/         OPC_CheckPredicate, 44, // Predicate_atomic_load_or_16
/*12964*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12966*/         OPC_EmitMergeInputChains1_0,
/*12967*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_or:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_or_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_OR_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12976*/       /*Scope*/ 14, /*->12991*/
/*12977*/         OPC_CheckPredicate, 45, // Predicate_atomic_load_or_32
/*12979*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*12981*/         OPC_EmitMergeInputChains1_0,
/*12982*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_or:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_or_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_OR_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*12991*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->13008
/*12994*/       OPC_CheckPredicate, 46, // Predicate_atomic_load_or_64
/*12996*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*12998*/       OPC_EmitMergeInputChains1_0,
/*12999*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_OR_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_or:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_or_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_OR_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*13009*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 19|128,1/*147*/,  TARGET_VAL(ISD::ATOMIC_LOAD_XOR),// ->13161
/*13014*/   OPC_RecordMemRef,
/*13015*/   OPC_RecordNode,   // #0 = 'atomic_load_xor' chained node
/*13016*/   OPC_RecordChild1, // #1 = $ptr
/*13017*/   OPC_Scope, 70, /*->13089*/ // 2 children in Scope
/*13019*/     OPC_CheckChild1Type, MVT::i32,
/*13021*/     OPC_RecordChild2, // #2 = $incr
/*13022*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->13072
/*13025*/       OPC_Scope, 14, /*->13041*/ // 3 children in Scope
/*13027*/         OPC_CheckPredicate, 47, // Predicate_atomic_load_xor_8
/*13029*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13031*/         OPC_EmitMergeInputChains1_0,
/*13032*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_xor:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_xor_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_XOR_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13041*/       /*Scope*/ 14, /*->13056*/
/*13042*/         OPC_CheckPredicate, 48, // Predicate_atomic_load_xor_16
/*13044*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13046*/         OPC_EmitMergeInputChains1_0,
/*13047*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_xor:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_xor_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_XOR_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13056*/       /*Scope*/ 14, /*->13071*/
/*13057*/         OPC_CheckPredicate, 49, // Predicate_atomic_load_xor_32
/*13059*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13061*/         OPC_EmitMergeInputChains1_0,
/*13062*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_xor:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_xor_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_XOR_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13071*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->13088
/*13074*/       OPC_CheckPredicate, 50, // Predicate_atomic_load_xor_64
/*13076*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13078*/       OPC_EmitMergeInputChains1_0,
/*13079*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_xor:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_xor_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_XOR_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*13089*/   /*Scope*/ 70, /*->13160*/
/*13090*/     OPC_CheckChild1Type, MVT::i64,
/*13092*/     OPC_RecordChild2, // #2 = $incr
/*13093*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->13143
/*13096*/       OPC_Scope, 14, /*->13112*/ // 3 children in Scope
/*13098*/         OPC_CheckPredicate, 47, // Predicate_atomic_load_xor_8
/*13100*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13102*/         OPC_EmitMergeInputChains1_0,
/*13103*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_xor:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_xor_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_XOR_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13112*/       /*Scope*/ 14, /*->13127*/
/*13113*/         OPC_CheckPredicate, 48, // Predicate_atomic_load_xor_16
/*13115*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13117*/         OPC_EmitMergeInputChains1_0,
/*13118*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_xor:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_xor_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_XOR_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13127*/       /*Scope*/ 14, /*->13142*/
/*13128*/         OPC_CheckPredicate, 49, // Predicate_atomic_load_xor_32
/*13130*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13132*/         OPC_EmitMergeInputChains1_0,
/*13133*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_xor:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_xor_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_XOR_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13142*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->13159
/*13145*/       OPC_CheckPredicate, 50, // Predicate_atomic_load_xor_64
/*13147*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13149*/       OPC_EmitMergeInputChains1_0,
/*13150*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_XOR_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_xor:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_xor_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_XOR_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*13160*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 19|128,1/*147*/,  TARGET_VAL(ISD::ATOMIC_LOAD_NAND),// ->13312
/*13165*/   OPC_RecordMemRef,
/*13166*/   OPC_RecordNode,   // #0 = 'atomic_load_nand' chained node
/*13167*/   OPC_RecordChild1, // #1 = $ptr
/*13168*/   OPC_Scope, 70, /*->13240*/ // 2 children in Scope
/*13170*/     OPC_CheckChild1Type, MVT::i32,
/*13172*/     OPC_RecordChild2, // #2 = $incr
/*13173*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->13223
/*13176*/       OPC_Scope, 14, /*->13192*/ // 3 children in Scope
/*13178*/         OPC_CheckPredicate, 51, // Predicate_atomic_load_nand_8
/*13180*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13182*/         OPC_EmitMergeInputChains1_0,
/*13183*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_nand:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_nand_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_NAND_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13192*/       /*Scope*/ 14, /*->13207*/
/*13193*/         OPC_CheckPredicate, 52, // Predicate_atomic_load_nand_16
/*13195*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13197*/         OPC_EmitMergeInputChains1_0,
/*13198*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_nand:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_nand_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_NAND_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13207*/       /*Scope*/ 14, /*->13222*/
/*13208*/         OPC_CheckPredicate, 53, // Predicate_atomic_load_nand_32
/*13210*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13212*/         OPC_EmitMergeInputChains1_0,
/*13213*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_nand:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_nand_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_NAND_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13222*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->13239
/*13225*/       OPC_CheckPredicate, 54, // Predicate_atomic_load_nand_64
/*13227*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13229*/       OPC_EmitMergeInputChains1_0,
/*13230*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_nand:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_nand_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_NAND_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*13240*/   /*Scope*/ 70, /*->13311*/
/*13241*/     OPC_CheckChild1Type, MVT::i64,
/*13243*/     OPC_RecordChild2, // #2 = $incr
/*13244*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->13294
/*13247*/       OPC_Scope, 14, /*->13263*/ // 3 children in Scope
/*13249*/         OPC_CheckPredicate, 51, // Predicate_atomic_load_nand_8
/*13251*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13253*/         OPC_EmitMergeInputChains1_0,
/*13254*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_nand:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_nand_8>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_NAND_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13263*/       /*Scope*/ 14, /*->13278*/
/*13264*/         OPC_CheckPredicate, 52, // Predicate_atomic_load_nand_16
/*13266*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13268*/         OPC_EmitMergeInputChains1_0,
/*13269*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_nand:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_nand_16>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_NAND_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13278*/       /*Scope*/ 14, /*->13293*/
/*13279*/         OPC_CheckPredicate, 53, // Predicate_atomic_load_nand_32
/*13281*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13283*/         OPC_EmitMergeInputChains1_0,
/*13284*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_load_nand:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_load_nand_32>> - Complexity = 4
                  // Dst: (ATOMIC_LOAD_NAND_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13293*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->13310
/*13296*/       OPC_CheckPredicate, 54, // Predicate_atomic_load_nand_64
/*13298*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13300*/       OPC_EmitMergeInputChains1_0,
/*13301*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_LOAD_NAND_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_load_nand:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_load_nand_64>> - Complexity = 4
                // Dst: (ATOMIC_LOAD_NAND_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*13311*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 19|128,1/*147*/,  TARGET_VAL(ISD::ATOMIC_SWAP),// ->13463
/*13316*/   OPC_RecordMemRef,
/*13317*/   OPC_RecordNode,   // #0 = 'atomic_swap' chained node
/*13318*/   OPC_RecordChild1, // #1 = $ptr
/*13319*/   OPC_Scope, 70, /*->13391*/ // 2 children in Scope
/*13321*/     OPC_CheckChild1Type, MVT::i32,
/*13323*/     OPC_RecordChild2, // #2 = $incr
/*13324*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->13374
/*13327*/       OPC_Scope, 14, /*->13343*/ // 3 children in Scope
/*13329*/         OPC_CheckPredicate, 55, // Predicate_atomic_swap_8
/*13331*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13333*/         OPC_EmitMergeInputChains1_0,
/*13334*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_swap:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_swap_8>> - Complexity = 4
                  // Dst: (ATOMIC_SWAP_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13343*/       /*Scope*/ 14, /*->13358*/
/*13344*/         OPC_CheckPredicate, 56, // Predicate_atomic_swap_16
/*13346*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13348*/         OPC_EmitMergeInputChains1_0,
/*13349*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_swap:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_swap_16>> - Complexity = 4
                  // Dst: (ATOMIC_SWAP_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13358*/       /*Scope*/ 14, /*->13373*/
/*13359*/         OPC_CheckPredicate, 57, // Predicate_atomic_swap_32
/*13361*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13363*/         OPC_EmitMergeInputChains1_0,
/*13364*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_swap:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_swap_32>> - Complexity = 4
                  // Dst: (ATOMIC_SWAP_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$incr)
/*13373*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->13390
/*13376*/       OPC_CheckPredicate, 58, // Predicate_atomic_swap_64
/*13378*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13380*/       OPC_EmitMergeInputChains1_0,
/*13381*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_swap:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_swap_64>> - Complexity = 4
                // Dst: (ATOMIC_SWAP_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*13391*/   /*Scope*/ 70, /*->13462*/
/*13392*/     OPC_CheckChild1Type, MVT::i64,
/*13394*/     OPC_RecordChild2, // #2 = $incr
/*13395*/     OPC_SwitchType /*2 cases */, 47,  MVT::i32,// ->13445
/*13398*/       OPC_Scope, 14, /*->13414*/ // 3 children in Scope
/*13400*/         OPC_CheckPredicate, 55, // Predicate_atomic_swap_8
/*13402*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13404*/         OPC_EmitMergeInputChains1_0,
/*13405*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_swap:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_swap_8>> - Complexity = 4
                  // Dst: (ATOMIC_SWAP_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13414*/       /*Scope*/ 14, /*->13429*/
/*13415*/         OPC_CheckPredicate, 56, // Predicate_atomic_swap_16
/*13417*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13419*/         OPC_EmitMergeInputChains1_0,
/*13420*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_swap:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_swap_16>> - Complexity = 4
                  // Dst: (ATOMIC_SWAP_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13429*/       /*Scope*/ 14, /*->13444*/
/*13430*/         OPC_CheckPredicate, 57, // Predicate_atomic_swap_32
/*13432*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13434*/         OPC_EmitMergeInputChains1_0,
/*13435*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (atomic_swap:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)<<P:Predicate_atomic_swap_32>> - Complexity = 4
                  // Dst: (ATOMIC_SWAP_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$incr)
/*13444*/       0, /*End of Scope*/
              /*SwitchType*/ 14,  MVT::i64,// ->13461
/*13447*/       OPC_CheckPredicate, 58, // Predicate_atomic_swap_64
/*13449*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13451*/       OPC_EmitMergeInputChains1_0,
/*13452*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_SWAP_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (atomic_swap:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)<<P:Predicate_atomic_swap_64>> - Complexity = 4
                // Dst: (ATOMIC_SWAP_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$incr)
              0, // EndSwitchType
/*13462*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 29|128,1/*157*/,  TARGET_VAL(ISD::ATOMIC_CMP_SWAP),// ->13624
/*13467*/   OPC_RecordMemRef,
/*13468*/   OPC_RecordNode,   // #0 = 'atomic_cmp_swap' chained node
/*13469*/   OPC_RecordChild1, // #1 = $ptr
/*13470*/   OPC_Scope, 75, /*->13547*/ // 2 children in Scope
/*13472*/     OPC_CheckChild1Type, MVT::i32,
/*13474*/     OPC_RecordChild2, // #2 = $cmp
/*13475*/     OPC_RecordChild3, // #3 = $swap
/*13476*/     OPC_SwitchType /*2 cases */, 50,  MVT::i32,// ->13529
/*13479*/       OPC_Scope, 15, /*->13496*/ // 3 children in Scope
/*13481*/         OPC_CheckPredicate, 59, // Predicate_atomic_cmp_swap_8
/*13483*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13485*/         OPC_EmitMergeInputChains1_0,
/*13486*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (atomic_cmp_swap:i32 CPURegs:i32:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)<<P:Predicate_atomic_cmp_swap_8>> - Complexity = 4
                  // Dst: (ATOMIC_CMP_SWAP_I8:i32 CPURegs:i32:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)
/*13496*/       /*Scope*/ 15, /*->13512*/
/*13497*/         OPC_CheckPredicate, 60, // Predicate_atomic_cmp_swap_16
/*13499*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13501*/         OPC_EmitMergeInputChains1_0,
/*13502*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (atomic_cmp_swap:i32 CPURegs:i32:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)<<P:Predicate_atomic_cmp_swap_16>> - Complexity = 4
                  // Dst: (ATOMIC_CMP_SWAP_I16:i32 CPURegs:i32:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)
/*13512*/       /*Scope*/ 15, /*->13528*/
/*13513*/         OPC_CheckPredicate, 61, // Predicate_atomic_cmp_swap_32
/*13515*/         OPC_CheckPatternPredicate, 0, // (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13517*/         OPC_EmitMergeInputChains1_0,
/*13518*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I32), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (atomic_cmp_swap:i32 CPURegs:i32:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)<<P:Predicate_atomic_cmp_swap_32>> - Complexity = 4
                  // Dst: (ATOMIC_CMP_SWAP_I32:i32 CPURegs:i32:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)
/*13528*/       0, /*End of Scope*/
              /*SwitchType*/ 15,  MVT::i64,// ->13546
/*13531*/       OPC_CheckPredicate, 62, // Predicate_atomic_cmp_swap_64
/*13533*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13535*/       OPC_EmitMergeInputChains1_0,
/*13536*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: (atomic_cmp_swap:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$cmp, CPU64Regs:i64:$swap)<<P:Predicate_atomic_cmp_swap_64>> - Complexity = 4
                // Dst: (ATOMIC_CMP_SWAP_I64:i64 CPURegs:i32:$ptr, CPU64Regs:i64:$cmp, CPU64Regs:i64:$swap)
              0, // EndSwitchType
/*13547*/   /*Scope*/ 75, /*->13623*/
/*13548*/     OPC_CheckChild1Type, MVT::i64,
/*13550*/     OPC_RecordChild2, // #2 = $cmp
/*13551*/     OPC_RecordChild3, // #3 = $swap
/*13552*/     OPC_SwitchType /*2 cases */, 50,  MVT::i32,// ->13605
/*13555*/       OPC_Scope, 15, /*->13572*/ // 3 children in Scope
/*13557*/         OPC_CheckPredicate, 59, // Predicate_atomic_cmp_swap_8
/*13559*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13561*/         OPC_EmitMergeInputChains1_0,
/*13562*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I8_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (atomic_cmp_swap:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)<<P:Predicate_atomic_cmp_swap_8>> - Complexity = 4
                  // Dst: (ATOMIC_CMP_SWAP_I8_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)
/*13572*/       /*Scope*/ 15, /*->13588*/
/*13573*/         OPC_CheckPredicate, 60, // Predicate_atomic_cmp_swap_16
/*13575*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13577*/         OPC_EmitMergeInputChains1_0,
/*13578*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I16_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (atomic_cmp_swap:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)<<P:Predicate_atomic_cmp_swap_16>> - Complexity = 4
                  // Dst: (ATOMIC_CMP_SWAP_I16_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)
/*13588*/       /*Scope*/ 15, /*->13604*/
/*13589*/         OPC_CheckPredicate, 61, // Predicate_atomic_cmp_swap_32
/*13591*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*13593*/         OPC_EmitMergeInputChains1_0,
/*13594*/         OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I32_P8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (atomic_cmp_swap:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)<<P:Predicate_atomic_cmp_swap_32>> - Complexity = 4
                  // Dst: (ATOMIC_CMP_SWAP_I32_P8:i32 CPU64Regs:i64:$ptr, CPURegs:i32:$cmp, CPURegs:i32:$swap)
/*13604*/       0, /*End of Scope*/
              /*SwitchType*/ 15,  MVT::i64,// ->13622
/*13607*/       OPC_CheckPredicate, 62, // Predicate_atomic_cmp_swap_64
/*13609*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13611*/       OPC_EmitMergeInputChains1_0,
/*13612*/       OPC_MorphNodeTo, TARGET_VAL(Oi::ATOMIC_CMP_SWAP_I64_P8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: (atomic_cmp_swap:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$cmp, CPU64Regs:i64:$swap)<<P:Predicate_atomic_cmp_swap_64>> - Complexity = 4
                // Dst: (ATOMIC_CMP_SWAP_I64_P8:i64 CPU64Regs:i64:$ptr, CPU64Regs:i64:$cmp, CPU64Regs:i64:$swap)
              0, // EndSwitchType
/*13623*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::MUL),// ->13658
/*13627*/   OPC_RecordChild0, // #0 = $rs
/*13628*/   OPC_RecordChild1, // #1 = $rt
/*13629*/   OPC_CheckType, MVT::i32,
/*13631*/   OPC_Scope, 11, /*->13644*/ // 2 children in Scope
/*13633*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13635*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MUL), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
              // Dst: (MUL:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*13644*/   /*Scope*/ 12, /*->13657*/
/*13645*/     OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*13647*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MultRxRyRz16), 0,
                  2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r) - Complexity = 3
              // Dst: (MultRxRyRz16:i32:i32 CPU16Regs:i32:$l, CPU16Regs:i32:$r)
/*13657*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 79,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->13740
/*13661*/   OPC_RecordChild0, // #0 = $rt
/*13662*/   OPC_MoveChild, 1,
/*13664*/   OPC_Scope, 29, /*->13695*/ // 3 children in Scope
/*13666*/     OPC_CheckValueType, MVT::i8,
/*13668*/     OPC_MoveParent,
/*13669*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->13682
/*13672*/       OPC_CheckPatternPredicate, 17, // (Subtarget.hasSEInReg()) && (Subtarget.hasStandardEncoding())
/*13674*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SEB), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i32 CPURegs:i32:$rt, i8:Other) - Complexity = 3
                // Dst: (SEB:i32 CPURegs:i32:$rt)
              /*SwitchType*/ 10,  MVT::i64,// ->13694
/*13684*/       OPC_CheckPatternPredicate, 17, // (Subtarget.hasSEInReg()) && (Subtarget.hasStandardEncoding())
/*13686*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SEB64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i64 CPU64Regs:i64:$rt, i8:Other) - Complexity = 3
                // Dst: (SEB64:i64 CPU64Regs:i64:$rt)
              0, // EndSwitchType
/*13695*/   /*Scope*/ 29, /*->13725*/
/*13696*/     OPC_CheckValueType, MVT::i16,
/*13698*/     OPC_MoveParent,
/*13699*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->13712
/*13702*/       OPC_CheckPatternPredicate, 17, // (Subtarget.hasSEInReg()) && (Subtarget.hasStandardEncoding())
/*13704*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SEH), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i32 CPURegs:i32:$rt, i16:Other) - Complexity = 3
                // Dst: (SEH:i32 CPURegs:i32:$rt)
              /*SwitchType*/ 10,  MVT::i64,// ->13724
/*13714*/       OPC_CheckPatternPredicate, 17, // (Subtarget.hasSEInReg()) && (Subtarget.hasStandardEncoding())
/*13716*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SEH64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i64 CPU64Regs:i64:$rt, i16:Other) - Complexity = 3
                // Dst: (SEH64:i64 CPU64Regs:i64:$rt)
              0, // EndSwitchType
/*13725*/   /*Scope*/ 13, /*->13739*/
/*13726*/     OPC_CheckValueType, MVT::i32,
/*13728*/     OPC_MoveParent,
/*13729*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13731*/     OPC_MorphNodeTo, TARGET_VAL(Oi::SLL64_64), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (sext_inreg:i64 CPU64Regs:i64:$src, i32:Other) - Complexity = 3
              // Dst: (SLL64_64:i64 CPU64Regs:i64:$src)
/*13739*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 30,  TARGET_VAL(ISD::SUBC),// ->13773
/*13743*/   OPC_RecordChild0, // #0 = $lhs
/*13744*/   OPC_RecordChild1, // #1 = $rhs
/*13745*/   OPC_CheckType, MVT::i32,
/*13747*/   OPC_Scope, 11, /*->13760*/ // 2 children in Scope
/*13749*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13751*/     OPC_MorphNodeTo, TARGET_VAL(Oi::SUBu), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (subc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs) - Complexity = 3
              // Dst: (SUBu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs)
/*13760*/   /*Scope*/ 11, /*->13772*/
/*13761*/     OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*13763*/     OPC_MorphNodeTo, TARGET_VAL(Oi::SubuRxRyRz16), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (subc:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs) - Complexity = 3
              // Dst: (SubuRxRyRz16:i32 CPU16Regs:i32:$lhs, CPU16Regs:i32:$rhs)
/*13772*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 7|128,1/*135*/,  TARGET_VAL(ISD::BITCAST),// ->13912
/*13777*/   OPC_RecordChild0, // #0 = $fs
/*13778*/   OPC_Scope, 14, /*->13794*/ // 6 children in Scope
/*13780*/     OPC_CheckChild0Type, MVT::f32,
/*13782*/     OPC_CheckType, MVT::i32,
/*13784*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13786*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MFC1), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (bitconvert:i32 FGR32:f32:$fs) - Complexity = 3
              // Dst: (MFC1:i32 FGR32:f32:$fs)
/*13794*/   /*Scope*/ 14, /*->13809*/
/*13795*/     OPC_CheckChild0Type, MVT::f64,
/*13797*/     OPC_CheckType, MVT::i64,
/*13799*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13801*/     OPC_MorphNodeTo, TARGET_VAL(Oi::DMFC1), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (bitconvert:i64 FGR64:f64:$fs) - Complexity = 3
              // Dst: (DMFC1:i64 FGR64:f64:$fs)
/*13809*/   /*Scope*/ 18, /*->13828*/
/*13810*/     OPC_CheckChild0Type, MVT::v2i16,
/*13812*/     OPC_CheckType, MVT::i32,
/*13814*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*13816*/     OPC_EmitInteger, MVT::i32, Oi::CPURegsRegClassID,
/*13819*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (bitconvert:i32 DSPRegs:v2i16:$src) - Complexity = 3
              // Dst: (COPY_TO_REGCLASS:i32 DSPRegs:v2i16:$src, CPURegs:i32)
/*13828*/   /*Scope*/ 18, /*->13847*/
/*13829*/     OPC_CheckChild0Type, MVT::v4i8,
/*13831*/     OPC_CheckType, MVT::i32,
/*13833*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*13835*/     OPC_EmitInteger, MVT::i32, Oi::CPURegsRegClassID,
/*13838*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (bitconvert:i32 DSPRegs:v4i8:$src) - Complexity = 3
              // Dst: (COPY_TO_REGCLASS:i32 DSPRegs:v4i8:$src, CPURegs:i32)
/*13847*/   /*Scope*/ 48, /*->13896*/
/*13848*/     OPC_CheckChild0Type, MVT::i32,
/*13850*/     OPC_SwitchType /*3 cases */, 10,  MVT::f32,// ->13863
/*13853*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13855*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MTC1), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (bitconvert:f32 CPURegs:i32:$rt) - Complexity = 3
                // Dst: (MTC1:f32 CPURegs:i32:$rt)
              /*SwitchType*/ 14,  MVT::v2i16,// ->13879
/*13865*/       OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*13867*/       OPC_EmitInteger, MVT::i32, Oi::DSPRegsRegClassID,
/*13870*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                    1/*#VTs*/, MVT::v2i16, 2/*#Ops*/, 0, 1, 
                // Src: (bitconvert:v2i16 CPURegs:i32:$src) - Complexity = 3
                // Dst: (COPY_TO_REGCLASS:v2i16 CPURegs:i32:$src, DSPRegs:v4i8)
              /*SwitchType*/ 14,  MVT::v4i8,// ->13895
/*13881*/       OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*13883*/       OPC_EmitInteger, MVT::i32, Oi::DSPRegsRegClassID,
/*13886*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                    1/*#VTs*/, MVT::v4i8, 2/*#Ops*/, 0, 1, 
                // Src: (bitconvert:v4i8 CPURegs:i32:$src) - Complexity = 3
                // Dst: (COPY_TO_REGCLASS:v4i8 CPURegs:i32:$src, DSPRegs:v4i8)
              0, // EndSwitchType
/*13896*/   /*Scope*/ 14, /*->13911*/
/*13897*/     OPC_CheckChild0Type, MVT::i64,
/*13899*/     OPC_CheckType, MVT::f64,
/*13901*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13903*/     OPC_MorphNodeTo, TARGET_VAL(Oi::DMTC1), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (bitconvert:f64 CPU64Regs:i64:$rt) - Complexity = 3
              // Dst: (DMTC1:f64 CPU64Regs:i64:$rt)
/*13911*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::ANY_EXTEND),// ->13930
/*13915*/   OPC_RecordChild0, // #0 = $src
/*13916*/   OPC_CheckChild0Type, MVT::i32,
/*13918*/   OPC_CheckType, MVT::i64,
/*13920*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13922*/   OPC_MorphNodeTo, TARGET_VAL(Oi::SLL64_32), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
            // Src: (anyext:i64 CPURegs:i32:$src) - Complexity = 3
            // Dst: (SLL64_32:i64 CPURegs:i32:$src)
          /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::SIGN_EXTEND),// ->13948
/*13933*/   OPC_RecordChild0, // #0 = $src
/*13934*/   OPC_CheckChild0Type, MVT::i32,
/*13936*/   OPC_CheckType, MVT::i64,
/*13938*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13940*/   OPC_MorphNodeTo, TARGET_VAL(Oi::SLL64_32), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
            // Src: (sext:i64 CPURegs:i32:$src) - Complexity = 3
            // Dst: (SLL64_32:i64 CPURegs:i32:$src)
          /*SwitchOpcode*/ 72,  TARGET_VAL(OiISD::CMovFP_T),// ->14023
/*13951*/   OPC_CaptureGlueInput,
/*13952*/   OPC_RecordChild0, // #0 = $rs
/*13953*/   OPC_RecordChild1, // #1 = $F
/*13954*/   OPC_SwitchType /*4 cases */, 11,  MVT::i32,// ->13968
/*13957*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13959*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MOVT_I), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (OiCMovFP_T:i32 CPURegs:i32:$rs, CPURegs:i32:$F) - Complexity = 3
              // Dst: (MOVT_I:i32 CPURegs:i32:$rs, CPURegs:i32:$F)
            /*SwitchType*/ 11,  MVT::i64,// ->13981
/*13970*/     OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*13972*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MOVT_I64), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (OiCMovFP_T:i64 CPU64Regs:i64:$rs, CPU64Regs:i64:$F) - Complexity = 3
              // Dst: (MOVT_I64:i64 CPU64Regs:i64:$rs, CPU64Regs:i64:$F)
            /*SwitchType*/ 11,  MVT::f32,// ->13994
/*13983*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*13985*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MOVT_S), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (OiCMovFP_T:f32 FGR32:f32:$fs, FGR32:f32:$F) - Complexity = 3
              // Dst: (MOVT_S:f32 FGR32:f32:$fs, FGR32:f32:$F)
            /*SwitchType*/ 26,  MVT::f64,// ->14022
/*13996*/     OPC_Scope, 11, /*->14009*/ // 2 children in Scope
/*13998*/       OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14000*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MOVT_D32), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (OiCMovFP_T:f64 AFGR64:f64:$fs, AFGR64:f64:$F) - Complexity = 3
                // Dst: (MOVT_D32:f64 AFGR64:f64:$fs, AFGR64:f64:$F)
/*14009*/     /*Scope*/ 11, /*->14021*/
/*14010*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14012*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MOVT_D64), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (OiCMovFP_T:f64 FGR64:f64:$fs, FGR64:f64:$F) - Complexity = 3
                // Dst: (MOVT_D64:f64 FGR64:f64:$fs, FGR64:f64:$F)
/*14021*/     0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 72,  TARGET_VAL(OiISD::CMovFP_F),// ->14098
/*14026*/   OPC_CaptureGlueInput,
/*14027*/   OPC_RecordChild0, // #0 = $rs
/*14028*/   OPC_RecordChild1, // #1 = $F
/*14029*/   OPC_SwitchType /*4 cases */, 11,  MVT::i32,// ->14043
/*14032*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14034*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MOVF_I), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (OiCMovFP_F:i32 CPURegs:i32:$rs, CPURegs:i32:$F) - Complexity = 3
              // Dst: (MOVF_I:i32 CPURegs:i32:$rs, CPURegs:i32:$F)
            /*SwitchType*/ 11,  MVT::i64,// ->14056
/*14045*/     OPC_CheckPatternPredicate, 12, // (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding())
/*14047*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MOVF_I64), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (OiCMovFP_F:i64 CPU64Regs:i64:$rs, CPU64Regs:i64:$F) - Complexity = 3
              // Dst: (MOVF_I64:i64 CPU64Regs:i64:$rs, CPU64Regs:i64:$F)
            /*SwitchType*/ 11,  MVT::f32,// ->14069
/*14058*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14060*/     OPC_MorphNodeTo, TARGET_VAL(Oi::MOVF_S), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (OiCMovFP_F:f32 FGR32:f32:$fs, FGR32:f32:$F) - Complexity = 3
              // Dst: (MOVF_S:f32 FGR32:f32:$fs, FGR32:f32:$F)
            /*SwitchType*/ 26,  MVT::f64,// ->14097
/*14071*/     OPC_Scope, 11, /*->14084*/ // 2 children in Scope
/*14073*/       OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14075*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MOVF_D32), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (OiCMovFP_F:f64 AFGR64:f64:$fs, AFGR64:f64:$F) - Complexity = 3
                // Dst: (MOVF_D32:f64 AFGR64:f64:$fs, AFGR64:f64:$F)
/*14084*/     /*Scope*/ 11, /*->14096*/
/*14085*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14087*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MOVF_D64), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (OiCMovFP_F:f64 FGR64:f64:$fs, FGR64:f64:$F) - Complexity = 3
                // Dst: (MOVF_D64:f64 FGR64:f64:$fs, FGR64:f64:$F)
/*14096*/     0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 47,  TARGET_VAL(ISD::BSWAP),// ->14148
/*14101*/   OPC_RecordChild0, // #0 = $rt
/*14102*/   OPC_SwitchType /*2 cases */, 22,  MVT::i32,// ->14127
/*14105*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14107*/     OPC_EmitNode, TARGET_VAL(Oi::WSBH), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #1
/*14115*/     OPC_EmitInteger, MVT::i32, 16, 
/*14118*/     OPC_MorphNodeTo, TARGET_VAL(Oi::ROTR), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (bswap:i32 CPURegs:i32:$rt) - Complexity = 3
              // Dst: (ROTR:i32 (WSBH:i32 CPURegs:i32:$rt), 16:i32)
            /*SwitchType*/ 18,  MVT::i64,// ->14147
/*14129*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14131*/     OPC_EmitNode, TARGET_VAL(Oi::DSBH), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0,  // Results = #1
/*14139*/     OPC_MorphNodeTo, TARGET_VAL(Oi::DSHD), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
              // Src: (bswap:i64 CPU64Regs:i64:$rt) - Complexity = 3
              // Dst: (DSHD:i64 (DSBH:i64 CPU64Regs:i64:$rt))
            0, // EndSwitchType
          /*SwitchOpcode*/ 115,  TARGET_VAL(ISD::FP_TO_SINT),// ->14266
/*14151*/   OPC_RecordChild0, // #0 = $src
/*14152*/   OPC_Scope, 44, /*->14198*/ // 2 children in Scope
/*14154*/     OPC_CheckChild0Type, MVT::f32,
/*14156*/     OPC_SwitchType /*2 cases */, 18,  MVT::i32,// ->14177
/*14159*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14161*/       OPC_EmitNode, TARGET_VAL(Oi::TRUNC_W_S), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0,  // Results = #1
/*14169*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MFC1), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (fp_to_sint:i32 FGR32:f32:$src) - Complexity = 3
                // Dst: (MFC1:i32 (TRUNC_W_S:f32 FGR32:f32:$src))
              /*SwitchType*/ 18,  MVT::i64,// ->14197
/*14179*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14181*/       OPC_EmitNode, TARGET_VAL(Oi::TRUNC_L_S), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0,  // Results = #1
/*14189*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DMFC1), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (fp_to_sint:i64 FGR32:f32:$src) - Complexity = 3
                // Dst: (DMFC1:i64 (TRUNC_L_S:f64 FGR32:f32:$src))
              0, // EndSwitchType
/*14198*/   /*Scope*/ 66, /*->14265*/
/*14199*/     OPC_CheckChild0Type, MVT::f64,
/*14201*/     OPC_SwitchType /*2 cases */, 40,  MVT::i32,// ->14244
/*14204*/       OPC_Scope, 18, /*->14224*/ // 2 children in Scope
/*14206*/         OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14208*/         OPC_EmitNode, TARGET_VAL(Oi::TRUNC_W_D32), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0,  // Results = #1
/*14216*/         OPC_MorphNodeTo, TARGET_VAL(Oi::MFC1), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                  // Src: (fp_to_sint:i32 AFGR64:f64:$src) - Complexity = 3
                  // Dst: (MFC1:i32 (TRUNC_W_D32:f32 AFGR64:f64:$src))
/*14224*/       /*Scope*/ 18, /*->14243*/
/*14225*/         OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14227*/         OPC_EmitNode, TARGET_VAL(Oi::TRUNC_W_D64), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0,  // Results = #1
/*14235*/         OPC_MorphNodeTo, TARGET_VAL(Oi::MFC1), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                  // Src: (fp_to_sint:i32 FGR64:f64:$src) - Complexity = 3
                  // Dst: (MFC1:i32 (TRUNC_W_D64:f32 FGR64:f64:$src))
/*14243*/       0, /*End of Scope*/
              /*SwitchType*/ 18,  MVT::i64,// ->14264
/*14246*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14248*/       OPC_EmitNode, TARGET_VAL(Oi::TRUNC_L_D64), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0,  // Results = #1
/*14256*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DMFC1), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (fp_to_sint:i64 FGR64:f64:$src) - Complexity = 3
                // Dst: (DMFC1:i64 (TRUNC_L_D64:f64 FGR64:f64:$src))
              0, // EndSwitchType
/*14265*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 29,  TARGET_VAL(ISD::TRUNCATE),// ->14298
/*14269*/   OPC_RecordChild0, // #0 = $src
/*14270*/   OPC_CheckType, MVT::i32,
/*14272*/   OPC_CheckPatternPredicate, 1, // (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding())
/*14274*/   OPC_EmitInteger, MVT::i32, Oi::sub_32,
/*14277*/   OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*14286*/   OPC_EmitInteger, MVT::i32, 0, 
/*14289*/   OPC_MorphNodeTo, TARGET_VAL(Oi::SLL), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
            // Src: (trunc:i32 CPU64Regs:i64:$src) - Complexity = 3
            // Dst: (SLL:i32 (EXTRACT_SUBREG:i32 CPU64Regs:i64:$src, sub_32:i32), 0:i32)
          /*SwitchOpcode*/ 27,  TARGET_VAL(ISD::ZERO_EXTEND),// ->14328
/*14301*/   OPC_RecordChild0, // #0 = $src
/*14302*/   OPC_CheckChild0Type, MVT::i32,
/*14304*/   OPC_CheckType, MVT::i64,
/*14306*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14308*/   OPC_EmitNode, TARGET_VAL(Oi::DSLL64_32), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0,  // Results = #1
/*14316*/   OPC_EmitInteger, MVT::i32, 32, 
/*14319*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DSRL), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
            // Src: (zext:i64 CPURegs:i32:$src) - Complexity = 3
            // Dst: (DSRL:i64 (DSLL64_32:i64 CPURegs:i32:$src), 32:i32)
          /*SwitchOpcode*/ 40|128,2/*296*/,  TARGET_VAL(ISD::FSUB),// ->14628
/*14332*/   OPC_Scope, 118|128,1/*246*/, /*->14581*/ // 2 children in Scope
/*14335*/     OPC_MoveChild, 0,
/*14337*/     OPC_SwitchOpcode /*2 cases */, 57|128,1/*185*/,  TARGET_VAL(ISD::ConstantFP),// ->14527
/*14342*/       OPC_CheckPredicate, 63, // Predicate_fpimm0
/*14344*/       OPC_MoveParent,
/*14345*/       OPC_MoveChild, 1,
/*14347*/       OPC_SwitchOpcode /*2 cases */, 116,  TARGET_VAL(ISD::FADD),// ->14467
/*14351*/         OPC_Scope, 56, /*->14409*/ // 2 children in Scope
/*14353*/           OPC_MoveChild, 0,
/*14355*/           OPC_CheckOpcode, TARGET_VAL(ISD::FMUL),
/*14358*/           OPC_RecordChild0, // #0 = $fs
/*14359*/           OPC_RecordChild1, // #1 = $ft
/*14360*/           OPC_MoveParent,
/*14361*/           OPC_RecordChild1, // #2 = $fr
/*14362*/           OPC_MoveParent,
/*14363*/           OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->14378
/*14366*/             OPC_CheckPatternPredicate, 18, // (Subtarget.hasOi32r2()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14368*/             OPC_MorphNodeTo, TARGET_VAL(Oi::NMADD_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 0, 1, 
                      // Src: (fsub:f32 (fpimm:f32)<<P:Predicate_fpimm0>>, (fadd:f32 (fmul:f32 FGR32:f32:$fs, FGR32:f32:$ft), FGR32:f32:$fr)) - Complexity = 13
                      // Dst: (NMADD_S:f32 FGR32:f32:$fr, FGR32:f32:$fs, FGR32:f32:$ft)
                    /*SwitchType*/ 28,  MVT::f64,// ->14408
/*14380*/             OPC_Scope, 12, /*->14394*/ // 2 children in Scope
/*14382*/               OPC_CheckPatternPredicate, 19, // (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14384*/               OPC_MorphNodeTo, TARGET_VAL(Oi::NMADD_D32), 0,
                            1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                        // Src: (fsub:f64 (fpimm:f64)<<P:Predicate_fpimm0>>, (fadd:f64 (fmul:f64 AFGR64:f64:$fs, AFGR64:f64:$ft), AFGR64:f64:$fr)) - Complexity = 13
                        // Dst: (NMADD_D32:f64 AFGR64:f64:$fr, AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14394*/             /*Scope*/ 12, /*->14407*/
/*14395*/               OPC_CheckPatternPredicate, 20, // (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14397*/               OPC_MorphNodeTo, TARGET_VAL(Oi::NMADD_D64), 0,
                            1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                        // Src: (fsub:f64 (fpimm:f64)<<P:Predicate_fpimm0>>, (fadd:f64 (fmul:f64 FGR64:f64:$fs, FGR64:f64:$ft), FGR64:f64:$fr)) - Complexity = 13
                        // Dst: (NMADD_D64:f64 FGR64:f64:$fr, FGR64:f64:$fs, FGR64:f64:$ft)
/*14407*/             0, /*End of Scope*/
                    0, // EndSwitchType
/*14409*/         /*Scope*/ 56, /*->14466*/
/*14410*/           OPC_RecordChild0, // #0 = $fr
/*14411*/           OPC_MoveChild, 1,
/*14413*/           OPC_CheckOpcode, TARGET_VAL(ISD::FMUL),
/*14416*/           OPC_RecordChild0, // #1 = $fs
/*14417*/           OPC_RecordChild1, // #2 = $ft
/*14418*/           OPC_MoveParent,
/*14419*/           OPC_MoveParent,
/*14420*/           OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->14435
/*14423*/             OPC_CheckPatternPredicate, 18, // (Subtarget.hasOi32r2()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14425*/             OPC_MorphNodeTo, TARGET_VAL(Oi::NMADD_S), 0,
                          1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (fsub:f32 (fpimm:f32)<<P:Predicate_fpimm0>>, (fadd:f32 FGR32:f32:$fr, (fmul:f32 FGR32:f32:$fs, FGR32:f32:$ft))) - Complexity = 13
                      // Dst: (NMADD_S:f32 FGR32:f32:$fr, FGR32:f32:$fs, FGR32:f32:$ft)
                    /*SwitchType*/ 28,  MVT::f64,// ->14465
/*14437*/             OPC_Scope, 12, /*->14451*/ // 2 children in Scope
/*14439*/               OPC_CheckPatternPredicate, 19, // (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14441*/               OPC_MorphNodeTo, TARGET_VAL(Oi::NMADD_D32), 0,
                            1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                        // Src: (fsub:f64 (fpimm:f64)<<P:Predicate_fpimm0>>, (fadd:f64 AFGR64:f64:$fr, (fmul:f64 AFGR64:f64:$fs, AFGR64:f64:$ft))) - Complexity = 13
                        // Dst: (NMADD_D32:f64 AFGR64:f64:$fr, AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14451*/             /*Scope*/ 12, /*->14464*/
/*14452*/               OPC_CheckPatternPredicate, 20, // (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14454*/               OPC_MorphNodeTo, TARGET_VAL(Oi::NMADD_D64), 0,
                            1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                        // Src: (fsub:f64 (fpimm:f64)<<P:Predicate_fpimm0>>, (fadd:f64 FGR64:f64:$fr, (fmul:f64 FGR64:f64:$fs, FGR64:f64:$ft))) - Complexity = 13
                        // Dst: (NMADD_D64:f64 FGR64:f64:$fr, FGR64:f64:$fs, FGR64:f64:$ft)
/*14464*/             0, /*End of Scope*/
                    0, // EndSwitchType
/*14466*/         0, /*End of Scope*/
                /*SwitchOpcode*/ 56,  TARGET_VAL(ISD::FSUB),// ->14526
/*14470*/         OPC_MoveChild, 0,
/*14472*/         OPC_CheckOpcode, TARGET_VAL(ISD::FMUL),
/*14475*/         OPC_RecordChild0, // #0 = $fs
/*14476*/         OPC_RecordChild1, // #1 = $ft
/*14477*/         OPC_MoveParent,
/*14478*/         OPC_RecordChild1, // #2 = $fr
/*14479*/         OPC_MoveParent,
/*14480*/         OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->14495
/*14483*/           OPC_CheckPatternPredicate, 18, // (Subtarget.hasOi32r2()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14485*/           OPC_MorphNodeTo, TARGET_VAL(Oi::NMSUB_S), 0,
                        1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 0, 1, 
                    // Src: (fsub:f32 (fpimm:f32)<<P:Predicate_fpimm0>>, (fsub:f32 (fmul:f32 FGR32:f32:$fs, FGR32:f32:$ft), FGR32:f32:$fr)) - Complexity = 13
                    // Dst: (NMSUB_S:f32 FGR32:f32:$fr, FGR32:f32:$fs, FGR32:f32:$ft)
                  /*SwitchType*/ 28,  MVT::f64,// ->14525
/*14497*/           OPC_Scope, 12, /*->14511*/ // 2 children in Scope
/*14499*/             OPC_CheckPatternPredicate, 19, // (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14501*/             OPC_MorphNodeTo, TARGET_VAL(Oi::NMSUB_D32), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                      // Src: (fsub:f64 (fpimm:f64)<<P:Predicate_fpimm0>>, (fsub:f64 (fmul:f64 AFGR64:f64:$fs, AFGR64:f64:$ft), AFGR64:f64:$fr)) - Complexity = 13
                      // Dst: (NMSUB_D32:f64 AFGR64:f64:$fr, AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14511*/           /*Scope*/ 12, /*->14524*/
/*14512*/             OPC_CheckPatternPredicate, 20, // (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14514*/             OPC_MorphNodeTo, TARGET_VAL(Oi::NMSUB_D64), 0,
                          1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                      // Src: (fsub:f64 (fpimm:f64)<<P:Predicate_fpimm0>>, (fsub:f64 (fmul:f64 FGR64:f64:$fs, FGR64:f64:$ft), FGR64:f64:$fr)) - Complexity = 13
                      // Dst: (NMSUB_D64:f64 FGR64:f64:$fr, FGR64:f64:$fs, FGR64:f64:$ft)
/*14524*/           0, /*End of Scope*/
                  0, // EndSwitchType
                0, // EndSwitchOpcode
              /*SwitchOpcode*/ 50,  TARGET_VAL(ISD::FMUL),// ->14580
/*14530*/       OPC_RecordChild0, // #0 = $fs
/*14531*/       OPC_RecordChild1, // #1 = $ft
/*14532*/       OPC_MoveParent,
/*14533*/       OPC_RecordChild1, // #2 = $fr
/*14534*/       OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->14549
/*14537*/         OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*14539*/         OPC_MorphNodeTo, TARGET_VAL(Oi::MSUB_S), 0,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 0, 1, 
                  // Src: (fsub:f32 (fmul:f32 FGR32:f32:$fs, FGR32:f32:$ft), FGR32:f32:$fr) - Complexity = 6
                  // Dst: (MSUB_S:f32 FGR32:f32:$fr, FGR32:f32:$fs, FGR32:f32:$ft)
                /*SwitchType*/ 28,  MVT::f64,// ->14579
/*14551*/         OPC_Scope, 12, /*->14565*/ // 2 children in Scope
/*14553*/           OPC_CheckPatternPredicate, 21, // (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14555*/           OPC_MorphNodeTo, TARGET_VAL(Oi::MSUB_D32), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                    // Src: (fsub:f64 (fmul:f64 AFGR64:f64:$fs, AFGR64:f64:$ft), AFGR64:f64:$fr) - Complexity = 6
                    // Dst: (MSUB_D32:f64 AFGR64:f64:$fr, AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14565*/         /*Scope*/ 12, /*->14578*/
/*14566*/           OPC_CheckPatternPredicate, 22, // (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14568*/           OPC_MorphNodeTo, TARGET_VAL(Oi::MSUB_D64), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                    // Src: (fsub:f64 (fmul:f64 FGR64:f64:$fs, FGR64:f64:$ft), FGR64:f64:$fr) - Complexity = 6
                    // Dst: (MSUB_D64:f64 FGR64:f64:$fr, FGR64:f64:$fs, FGR64:f64:$ft)
/*14578*/         0, /*End of Scope*/
                0, // EndSwitchType
              0, // EndSwitchOpcode
/*14581*/   /*Scope*/ 45, /*->14627*/
/*14582*/     OPC_RecordChild0, // #0 = $fs
/*14583*/     OPC_RecordChild1, // #1 = $ft
/*14584*/     OPC_SwitchType /*2 cases */, 11,  MVT::f32,// ->14598
/*14587*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14589*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FSUB_S), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (fsub:f32 FGR32:f32:$fs, FGR32:f32:$ft) - Complexity = 3
                // Dst: (FSUB_S:f32 FGR32:f32:$fs, FGR32:f32:$ft)
              /*SwitchType*/ 26,  MVT::f64,// ->14626
/*14600*/       OPC_Scope, 11, /*->14613*/ // 2 children in Scope
/*14602*/         OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14604*/         OPC_MorphNodeTo, TARGET_VAL(Oi::FSUB_D32), 0,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                  // Src: (fsub:f64 AFGR64:f64:$fs, AFGR64:f64:$ft) - Complexity = 3
                  // Dst: (FSUB_D32:f64 AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14613*/       /*Scope*/ 11, /*->14625*/
/*14614*/         OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14616*/         OPC_MorphNodeTo, TARGET_VAL(Oi::FSUB_D64), 0,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                  // Src: (fsub:f64 FGR64:f64:$fs, FGR64:f64:$ft) - Complexity = 3
                  // Dst: (FSUB_D64:f64 FGR64:f64:$fs, FGR64:f64:$ft)
/*14625*/       0, /*End of Scope*/
              0, // EndSwitchType
/*14627*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 34|128,1/*162*/,  TARGET_VAL(ISD::FADD),// ->14794
/*14632*/   OPC_Scope, 55, /*->14689*/ // 2 children in Scope
/*14634*/     OPC_MoveChild, 0,
/*14636*/     OPC_CheckOpcode, TARGET_VAL(ISD::FMUL),
/*14639*/     OPC_RecordChild0, // #0 = $fs
/*14640*/     OPC_RecordChild1, // #1 = $ft
/*14641*/     OPC_MoveParent,
/*14642*/     OPC_RecordChild1, // #2 = $fr
/*14643*/     OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->14658
/*14646*/       OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*14648*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MADD_S), 0,
                    1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 0, 1, 
                // Src: (fadd:f32 (fmul:f32 FGR32:f32:$fs, FGR32:f32:$ft), FGR32:f32:$fr) - Complexity = 6
                // Dst: (MADD_S:f32 FGR32:f32:$fr, FGR32:f32:$fs, FGR32:f32:$ft)
              /*SwitchType*/ 28,  MVT::f64,// ->14688
/*14660*/       OPC_Scope, 12, /*->14674*/ // 2 children in Scope
/*14662*/         OPC_CheckPatternPredicate, 21, // (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14664*/         OPC_MorphNodeTo, TARGET_VAL(Oi::MADD_D32), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                  // Src: (fadd:f64 (fmul:f64 AFGR64:f64:$fs, AFGR64:f64:$ft), AFGR64:f64:$fr) - Complexity = 6
                  // Dst: (MADD_D32:f64 AFGR64:f64:$fr, AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14674*/       /*Scope*/ 12, /*->14687*/
/*14675*/         OPC_CheckPatternPredicate, 22, // (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14677*/         OPC_MorphNodeTo, TARGET_VAL(Oi::MADD_D64), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                  // Src: (fadd:f64 (fmul:f64 FGR64:f64:$fs, FGR64:f64:$ft), FGR64:f64:$fr) - Complexity = 6
                  // Dst: (MADD_D64:f64 FGR64:f64:$fr, FGR64:f64:$fs, FGR64:f64:$ft)
/*14687*/       0, /*End of Scope*/
              0, // EndSwitchType
/*14689*/   /*Scope*/ 103, /*->14793*/
/*14690*/     OPC_RecordChild0, // #0 = $fr
/*14691*/     OPC_Scope, 54, /*->14747*/ // 2 children in Scope
/*14693*/       OPC_MoveChild, 1,
/*14695*/       OPC_CheckOpcode, TARGET_VAL(ISD::FMUL),
/*14698*/       OPC_RecordChild0, // #1 = $fs
/*14699*/       OPC_RecordChild1, // #2 = $ft
/*14700*/       OPC_MoveParent,
/*14701*/       OPC_SwitchType /*2 cases */, 12,  MVT::f32,// ->14716
/*14704*/         OPC_CheckPatternPredicate, 15, // (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding())
/*14706*/         OPC_MorphNodeTo, TARGET_VAL(Oi::MADD_S), 0,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (fadd:f32 FGR32:f32:$fr, (fmul:f32 FGR32:f32:$fs, FGR32:f32:$ft)) - Complexity = 6
                  // Dst: (MADD_S:f32 FGR32:f32:$fr, FGR32:f32:$fs, FGR32:f32:$ft)
                /*SwitchType*/ 28,  MVT::f64,// ->14746
/*14718*/         OPC_Scope, 12, /*->14732*/ // 2 children in Scope
/*14720*/           OPC_CheckPatternPredicate, 21, // (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14722*/           OPC_MorphNodeTo, TARGET_VAL(Oi::MADD_D32), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (fadd:f64 AFGR64:f64:$fr, (fmul:f64 AFGR64:f64:$fs, AFGR64:f64:$ft)) - Complexity = 6
                    // Dst: (MADD_D32:f64 AFGR64:f64:$fr, AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14732*/         /*Scope*/ 12, /*->14745*/
/*14733*/           OPC_CheckPatternPredicate, 22, // (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14735*/           OPC_MorphNodeTo, TARGET_VAL(Oi::MADD_D64), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (fadd:f64 FGR64:f64:$fr, (fmul:f64 FGR64:f64:$fs, FGR64:f64:$ft)) - Complexity = 6
                    // Dst: (MADD_D64:f64 FGR64:f64:$fr, FGR64:f64:$fs, FGR64:f64:$ft)
/*14745*/         0, /*End of Scope*/
                0, // EndSwitchType
/*14747*/     /*Scope*/ 44, /*->14792*/
/*14748*/       OPC_RecordChild1, // #1 = $ft
/*14749*/       OPC_SwitchType /*2 cases */, 11,  MVT::f32,// ->14763
/*14752*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14754*/         OPC_MorphNodeTo, TARGET_VAL(Oi::FADD_S), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (fadd:f32 FGR32:f32:$fs, FGR32:f32:$ft) - Complexity = 3
                  // Dst: (FADD_S:f32 FGR32:f32:$fs, FGR32:f32:$ft)
                /*SwitchType*/ 26,  MVT::f64,// ->14791
/*14765*/         OPC_Scope, 11, /*->14778*/ // 2 children in Scope
/*14767*/           OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14769*/           OPC_MorphNodeTo, TARGET_VAL(Oi::FADD_D32), 0,
                        1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                    // Src: (fadd:f64 AFGR64:f64:$fs, AFGR64:f64:$ft) - Complexity = 3
                    // Dst: (FADD_D32:f64 AFGR64:f64:$fs, AFGR64:f64:$ft)
/*14778*/         /*Scope*/ 11, /*->14790*/
/*14779*/           OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14781*/           OPC_MorphNodeTo, TARGET_VAL(Oi::FADD_D64), 0,
                        1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                    // Src: (fadd:f64 FGR64:f64:$fs, FGR64:f64:$ft) - Complexity = 3
                    // Dst: (FADD_D64:f64 FGR64:f64:$fs, FGR64:f64:$ft)
/*14790*/         0, /*End of Scope*/
                0, // EndSwitchType
/*14792*/     0, /*End of Scope*/
/*14793*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 88,  TARGET_VAL(ISD::ConstantFP),// ->14885
/*14797*/   OPC_Scope, 34, /*->14833*/ // 2 children in Scope
/*14799*/     OPC_CheckPredicate, 63, // Predicate_fpimm0
/*14801*/     OPC_SwitchType /*2 cases */, 13,  MVT::f32,// ->14817
/*14804*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14806*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*14809*/       OPC_MorphNodeTo, TARGET_VAL(Oi::MTC1), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (fpimm:f32)<<P:Predicate_fpimm0>> - Complexity = 4
                // Dst: (MTC1:f32 ZERO:i32)
              /*SwitchType*/ 13,  MVT::f64,// ->14832
/*14819*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14821*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*14824*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DMTC1), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fpimm:f64)<<P:Predicate_fpimm0>> - Complexity = 4
                // Dst: (DMTC1:f64 ZERO_64:i64)
              0, // EndSwitchType
/*14833*/   /*Scope*/ 50, /*->14884*/
/*14834*/     OPC_CheckPredicate, 64, // Predicate_fpimm0neg
/*14836*/     OPC_SwitchType /*2 cases */, 21,  MVT::f32,// ->14860
/*14839*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14841*/       OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*14844*/       OPC_EmitNode, TARGET_VAL(Oi::MTC1), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0,  // Results = #1
/*14852*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FNEG_S), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 1, 
                // Src: (fpimm:f32)<<P:Predicate_fpimm0neg>> - Complexity = 4
                // Dst: (FNEG_S:f32 (MTC1:f32 ZERO:i32))
              /*SwitchType*/ 21,  MVT::f64,// ->14883
/*14862*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14864*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*14867*/       OPC_EmitNode, TARGET_VAL(Oi::DMTC1), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0,  // Results = #1
/*14875*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FNEG_D64), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 1, 
                // Src: (fpimm:f64)<<P:Predicate_fpimm0neg>> - Complexity = 4
                // Dst: (FNEG_D64:f64 (DMTC1:f64 ZERO_64:i64))
              0, // EndSwitchType
/*14884*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FABS),// ->14927
/*14888*/   OPC_RecordChild0, // #0 = $fs
/*14889*/   OPC_SwitchType /*2 cases */, 10,  MVT::f32,// ->14902
/*14892*/     OPC_CheckPatternPredicate, 23, // (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14894*/     OPC_MorphNodeTo, TARGET_VAL(Oi::FABS_S), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fabs:f32 FGR32:f32:$fs) - Complexity = 3
              // Dst: (FABS_S:f32 FGR32:f32:$fs)
            /*SwitchType*/ 22,  MVT::f64,// ->14926
/*14904*/     OPC_CheckPatternPredicate, 23, // (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14906*/     OPC_Scope, 8, /*->14916*/ // 2 children in Scope
/*14908*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FABS_D32), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fabs:f64 AFGR64:f64:$fs) - Complexity = 3
                // Dst: (FABS_D32:f64 AFGR64:f64:$fs)
/*14916*/     /*Scope*/ 8, /*->14925*/
/*14917*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FABS_D64), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fabs:f64 FGR64:f64:$fs) - Complexity = 3
                // Dst: (FABS_D64:f64 FGR64:f64:$fs)
/*14925*/     0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FNEG),// ->14969
/*14930*/   OPC_RecordChild0, // #0 = $fs
/*14931*/   OPC_SwitchType /*2 cases */, 10,  MVT::f32,// ->14944
/*14934*/     OPC_CheckPatternPredicate, 23, // (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14936*/     OPC_MorphNodeTo, TARGET_VAL(Oi::FNEG_S), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fneg:f32 FGR32:f32:$fs) - Complexity = 3
              // Dst: (FNEG_S:f32 FGR32:f32:$fs)
            /*SwitchType*/ 22,  MVT::f64,// ->14968
/*14946*/     OPC_CheckPatternPredicate, 23, // (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding())
/*14948*/     OPC_Scope, 8, /*->14958*/ // 2 children in Scope
/*14950*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FNEG_D32), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fneg:f64 AFGR64:f64:$fs) - Complexity = 3
                // Dst: (FNEG_D32:f64 AFGR64:f64:$fs)
/*14958*/     /*Scope*/ 8, /*->14967*/
/*14959*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FNEG_D64), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fneg:f64 FGR64:f64:$fs) - Complexity = 3
                // Dst: (FNEG_D64:f64 FGR64:f64:$fs)
/*14967*/     0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 41,  TARGET_VAL(ISD::FSQRT),// ->15013
/*14972*/   OPC_RecordChild0, // #0 = $fs
/*14973*/   OPC_SwitchType /*2 cases */, 10,  MVT::f32,// ->14986
/*14976*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*14978*/     OPC_MorphNodeTo, TARGET_VAL(Oi::FSQRT_S), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fsqrt:f32 FGR32:f32:$fs) - Complexity = 3
              // Dst: (FSQRT_S:f32 FGR32:f32:$fs)
            /*SwitchType*/ 24,  MVT::f64,// ->15012
/*14988*/     OPC_Scope, 10, /*->15000*/ // 2 children in Scope
/*14990*/       OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*14992*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FSQRT_D32), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fsqrt:f64 AFGR64:f64:$fs) - Complexity = 3
                // Dst: (FSQRT_D32:f64 AFGR64:f64:$fs)
/*15000*/     /*Scope*/ 10, /*->15011*/
/*15001*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15003*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FSQRT_D64), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fsqrt:f64 FGR64:f64:$fs) - Complexity = 3
                // Dst: (FSQRT_D64:f64 FGR64:f64:$fs)
/*15011*/     0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 45,  TARGET_VAL(ISD::FDIV),// ->15061
/*15016*/   OPC_RecordChild0, // #0 = $fs
/*15017*/   OPC_RecordChild1, // #1 = $ft
/*15018*/   OPC_SwitchType /*2 cases */, 11,  MVT::f32,// ->15032
/*15021*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15023*/     OPC_MorphNodeTo, TARGET_VAL(Oi::FDIV_S), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fdiv:f32 FGR32:f32:$fs, FGR32:f32:$ft) - Complexity = 3
              // Dst: (FDIV_S:f32 FGR32:f32:$fs, FGR32:f32:$ft)
            /*SwitchType*/ 26,  MVT::f64,// ->15060
/*15034*/     OPC_Scope, 11, /*->15047*/ // 2 children in Scope
/*15036*/       OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15038*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FDIV_D32), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fdiv:f64 AFGR64:f64:$fs, AFGR64:f64:$ft) - Complexity = 3
                // Dst: (FDIV_D32:f64 AFGR64:f64:$fs, AFGR64:f64:$ft)
/*15047*/     /*Scope*/ 11, /*->15059*/
/*15048*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15050*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FDIV_D64), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fdiv:f64 FGR64:f64:$fs, FGR64:f64:$ft) - Complexity = 3
                // Dst: (FDIV_D64:f64 FGR64:f64:$fs, FGR64:f64:$ft)
/*15059*/     0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 45,  TARGET_VAL(ISD::FMUL),// ->15109
/*15064*/   OPC_RecordChild0, // #0 = $fs
/*15065*/   OPC_RecordChild1, // #1 = $ft
/*15066*/   OPC_SwitchType /*2 cases */, 11,  MVT::f32,// ->15080
/*15069*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15071*/     OPC_MorphNodeTo, TARGET_VAL(Oi::FMUL_S), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fmul:f32 FGR32:f32:$fs, FGR32:f32:$ft) - Complexity = 3
              // Dst: (FMUL_S:f32 FGR32:f32:$fs, FGR32:f32:$ft)
            /*SwitchType*/ 26,  MVT::f64,// ->15108
/*15082*/     OPC_Scope, 11, /*->15095*/ // 2 children in Scope
/*15084*/       OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15086*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FMUL_D32), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f64 AFGR64:f64:$fs, AFGR64:f64:$ft) - Complexity = 3
                // Dst: (FMUL_D32:f64 AFGR64:f64:$fs, AFGR64:f64:$ft)
/*15095*/     /*Scope*/ 11, /*->15107*/
/*15096*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15098*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FMUL_D64), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f64 FGR64:f64:$fs, FGR64:f64:$ft) - Complexity = 3
                // Dst: (FMUL_D64:f64 FGR64:f64:$fs, FGR64:f64:$ft)
/*15107*/     0, /*End of Scope*/
            0, // EndSwitchType
          /*SwitchOpcode*/ 13,  TARGET_VAL(OiISD::BuildPairF64),// ->15125
/*15112*/   OPC_RecordChild0, // #0 = $lo
/*15113*/   OPC_RecordChild1, // #1 = $hi
/*15114*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15116*/   OPC_MorphNodeTo, TARGET_VAL(Oi::BuildPairF64), 0,
                1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
            // Src: (OiBuildPairF64:f64 CPURegs:i32:$lo, CPURegs:i32:$hi) - Complexity = 3
            // Dst: (BuildPairF64:f64 CPURegs:i32:$lo, CPURegs:i32:$hi)
          /*SwitchOpcode*/ 25,  TARGET_VAL(ISD::FP_ROUND),// ->15153
/*15128*/   OPC_RecordChild0, // #0 = $src
/*15129*/   OPC_Scope, 10, /*->15141*/ // 2 children in Scope
/*15131*/     OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15133*/     OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_S_D32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fround:f32 AFGR64:f64:$src) - Complexity = 3
              // Dst: (CVT_S_D32:f32 AFGR64:f64:$src)
/*15141*/   /*Scope*/ 10, /*->15152*/
/*15142*/     OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15144*/     OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_S_D64), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fround:f32 FGR64:f64:$src) - Complexity = 3
              // Dst: (CVT_S_D64:f32 FGR64:f64:$src)
/*15152*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 25,  TARGET_VAL(ISD::FP_EXTEND),// ->15181
/*15156*/   OPC_RecordChild0, // #0 = $src
/*15157*/   OPC_Scope, 10, /*->15169*/ // 2 children in Scope
/*15159*/     OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15161*/     OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_D32_S), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fextend:f64 FGR32:f32:$src) - Complexity = 3
              // Dst: (CVT_D32_S:f64 FGR32:f32:$src)
/*15169*/   /*Scope*/ 10, /*->15180*/
/*15170*/     OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15172*/     OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_D64_S), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fextend:f64 FGR32:f32:$src) - Complexity = 3
              // Dst: (CVT_D64_S:f64 FGR32:f32:$src)
/*15180*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 115,  TARGET_VAL(ISD::SINT_TO_FP),// ->15299
/*15184*/   OPC_RecordChild0, // #0 = $src
/*15185*/   OPC_Scope, 66, /*->15253*/ // 2 children in Scope
/*15187*/     OPC_CheckChild0Type, MVT::i32,
/*15189*/     OPC_SwitchType /*2 cases */, 18,  MVT::f32,// ->15210
/*15192*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15194*/       OPC_EmitNode, TARGET_VAL(Oi::MTC1), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0,  // Results = #1
/*15202*/       OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_S_W), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 1, 
                // Src: (sint_to_fp:f32 CPURegs:i32:$src) - Complexity = 3
                // Dst: (CVT_S_W:f32 (MTC1:f32 CPURegs:i32:$src))
              /*SwitchType*/ 40,  MVT::f64,// ->15252
/*15212*/       OPC_Scope, 18, /*->15232*/ // 2 children in Scope
/*15214*/         OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15216*/         OPC_EmitNode, TARGET_VAL(Oi::MTC1), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0,  // Results = #1
/*15224*/         OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_D32_W), 0,
                      1/*#VTs*/, MVT::f64, 1/*#Ops*/, 1, 
                  // Src: (sint_to_fp:f64 CPURegs:i32:$src) - Complexity = 3
                  // Dst: (CVT_D32_W:f64 (MTC1:f32 CPURegs:i32:$src))
/*15232*/       /*Scope*/ 18, /*->15251*/
/*15233*/         OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15235*/         OPC_EmitNode, TARGET_VAL(Oi::MTC1), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0,  // Results = #1
/*15243*/         OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_D64_W), 0,
                      1/*#VTs*/, MVT::f64, 1/*#Ops*/, 1, 
                  // Src: (sint_to_fp:f64 CPURegs:i32:$src) - Complexity = 3
                  // Dst: (CVT_D64_W:f64 (MTC1:f32 CPURegs:i32:$src))
/*15251*/       0, /*End of Scope*/
              0, // EndSwitchType
/*15253*/   /*Scope*/ 44, /*->15298*/
/*15254*/     OPC_CheckChild0Type, MVT::i64,
/*15256*/     OPC_SwitchType /*2 cases */, 18,  MVT::f32,// ->15277
/*15259*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15261*/       OPC_EmitNode, TARGET_VAL(Oi::DMTC1), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0,  // Results = #1
/*15269*/       OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_S_L), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 1, 
                // Src: (sint_to_fp:f32 CPU64Regs:i64:$src) - Complexity = 3
                // Dst: (CVT_S_L:f32 (DMTC1:f64 CPU64Regs:i64:$src))
              /*SwitchType*/ 18,  MVT::f64,// ->15297
/*15279*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*15281*/       OPC_EmitNode, TARGET_VAL(Oi::DMTC1), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0,  // Results = #1
/*15289*/       OPC_MorphNodeTo, TARGET_VAL(Oi::CVT_D64_L), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 1, 
                // Src: (sint_to_fp:f64 CPU64Regs:i64:$src) - Complexity = 3
                // Dst: (CVT_D64_L:f64 (DMTC1:f64 CPU64Regs:i64:$src))
              0, // EndSwitchType
/*15298*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 98|128,10/*1378*/,  TARGET_VAL(ISD::BRCOND),// ->16681
/*15303*/   OPC_RecordNode,   // #0 = 'brcond' chained node
/*15304*/   OPC_Scope, 24|128,10/*1304*/, /*->16611*/ // 2 children in Scope
/*15307*/     OPC_MoveChild, 1,
/*15309*/     OPC_CheckOpcode, TARGET_VAL(ISD::SETCC),
/*15312*/     OPC_RecordChild0, // #1 = $rs
/*15313*/     OPC_Scope, 43|128,6/*811*/, /*->16127*/ // 2 children in Scope
/*15316*/       OPC_CheckChild0Type, MVT::i32,
/*15318*/       OPC_Scope, 79|128,1/*207*/, /*->15528*/ // 2 children in Scope
/*15321*/         OPC_MoveChild, 1,
/*15323*/         OPC_CheckInteger, 0, 
/*15325*/         OPC_MoveParent,
/*15326*/         OPC_MoveChild, 2,
/*15328*/         OPC_Scope, 24, /*->15354*/ // 7 children in Scope
/*15330*/           OPC_CheckCondCode, ISD::SETGE,
/*15332*/           OPC_MoveParent,
/*15333*/           OPC_CheckType, MVT::i32,
/*15335*/           OPC_MoveParent,
/*15336*/           OPC_RecordChild2, // #2 = $offset
/*15337*/           OPC_MoveChild, 2,
/*15339*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15342*/           OPC_MoveParent,
/*15343*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15345*/           OPC_EmitMergeInputChains1_0,
/*15346*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BGEZ), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPURegs:i32:$rs, 0:i32, SETGE:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BGEZ CPURegs:i32:$rs, (bb:Other):$offset)
/*15354*/         /*Scope*/ 24, /*->15379*/
/*15355*/           OPC_CheckCondCode, ISD::SETGT,
/*15357*/           OPC_MoveParent,
/*15358*/           OPC_CheckType, MVT::i32,
/*15360*/           OPC_MoveParent,
/*15361*/           OPC_RecordChild2, // #2 = $offset
/*15362*/           OPC_MoveChild, 2,
/*15364*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15367*/           OPC_MoveParent,
/*15368*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15370*/           OPC_EmitMergeInputChains1_0,
/*15371*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BGTZ), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPURegs:i32:$rs, 0:i32, SETGT:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BGTZ CPURegs:i32:$rs, (bb:Other):$offset)
/*15379*/         /*Scope*/ 24, /*->15404*/
/*15380*/           OPC_CheckCondCode, ISD::SETLE,
/*15382*/           OPC_MoveParent,
/*15383*/           OPC_CheckType, MVT::i32,
/*15385*/           OPC_MoveParent,
/*15386*/           OPC_RecordChild2, // #2 = $offset
/*15387*/           OPC_MoveChild, 2,
/*15389*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15392*/           OPC_MoveParent,
/*15393*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15395*/           OPC_EmitMergeInputChains1_0,
/*15396*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BLEZ), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPURegs:i32:$rs, 0:i32, SETLE:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BLEZ CPURegs:i32:$rs, (bb:Other):$offset)
/*15404*/         /*Scope*/ 24, /*->15429*/
/*15405*/           OPC_CheckCondCode, ISD::SETLT,
/*15407*/           OPC_MoveParent,
/*15408*/           OPC_CheckType, MVT::i32,
/*15410*/           OPC_MoveParent,
/*15411*/           OPC_RecordChild2, // #2 = $offset
/*15412*/           OPC_MoveChild, 2,
/*15414*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15417*/           OPC_MoveParent,
/*15418*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15420*/           OPC_EmitMergeInputChains1_0,
/*15421*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BLTZ), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPURegs:i32:$rs, 0:i32, SETLT:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BLTZ CPURegs:i32:$rs, (bb:Other):$offset)
/*15429*/         /*Scope*/ 28, /*->15458*/
/*15430*/           OPC_CheckCondCode, ISD::SETNE,
/*15432*/           OPC_MoveParent,
/*15433*/           OPC_CheckType, MVT::i32,
/*15435*/           OPC_MoveParent,
/*15436*/           OPC_RecordChild2, // #2 = $dst
/*15437*/           OPC_MoveChild, 2,
/*15439*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15442*/           OPC_MoveParent,
/*15443*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15445*/           OPC_EmitMergeInputChains1_0,
/*15446*/           OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*15449*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BNE), 0|OPFL_Chain,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                    // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETNE:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BNE CPURegs:i32:$lhs, ZERO:i32, (bb:Other):$dst)
/*15458*/         /*Scope*/ 43, /*->15502*/
/*15459*/           OPC_CheckCondCode, ISD::SETEQ,
/*15461*/           OPC_MoveParent,
/*15462*/           OPC_CheckType, MVT::i32,
/*15464*/           OPC_MoveParent,
/*15465*/           OPC_RecordChild2, // #2 = $dst
/*15466*/           OPC_MoveChild, 2,
/*15468*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15471*/           OPC_MoveParent,
/*15472*/           OPC_Scope, 15, /*->15489*/ // 2 children in Scope
/*15474*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15476*/             OPC_EmitMergeInputChains1_0,
/*15477*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*15480*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                      // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, 0:i32, SETEQ:Other), (bb:Other):$dst) - Complexity = 11
                      // Dst: (BEQ CPURegs:i32:$lhs, ZERO:i32, (bb:Other):$dst)
/*15489*/           /*Scope*/ 11, /*->15501*/
/*15490*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15492*/             OPC_EmitMergeInputChains1_0,
/*15493*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BeqzRxImmX16), 0|OPFL_Chain,
                          0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, 0:i32, SETEQ:Other), (bb:Other):$targ16) - Complexity = 11
                      // Dst: (BeqzRxImmX16 CPU16Regs:i32:$rx, (bb:Other):$targ16)
/*15501*/           0, /*End of Scope*/
/*15502*/         /*Scope*/ 24, /*->15527*/
/*15503*/           OPC_CheckCondCode, ISD::SETNE,
/*15505*/           OPC_MoveParent,
/*15506*/           OPC_CheckType, MVT::i32,
/*15508*/           OPC_MoveParent,
/*15509*/           OPC_RecordChild2, // #2 = $targ16
/*15510*/           OPC_MoveChild, 2,
/*15512*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15515*/           OPC_MoveParent,
/*15516*/           OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15518*/           OPC_EmitMergeInputChains1_0,
/*15519*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BnezRxImmX16), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, 0:i32, SETNE:Other), (bb:Other):$targ16) - Complexity = 11
                    // Dst: (BnezRxImmX16 CPU16Regs:i32:$rx, (bb:Other):$targ16)
/*15527*/         0, /*End of Scope*/
/*15528*/       /*Scope*/ 84|128,4/*596*/, /*->16126*/
/*15530*/         OPC_RecordChild1, // #2 = $imm
/*15531*/         OPC_Scope, 97|128,1/*225*/, /*->15759*/ // 2 children in Scope
/*15534*/           OPC_MoveChild, 1,
/*15536*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15539*/           OPC_Scope, 32, /*->15573*/ // 4 children in Scope
/*15541*/             OPC_CheckPredicate, 27, // Predicate_immZExt16
/*15543*/             OPC_MoveParent,
/*15544*/             OPC_MoveChild, 2,
/*15546*/             OPC_CheckCondCode, ISD::SETEQ,
/*15548*/             OPC_MoveParent,
/*15549*/             OPC_CheckType, MVT::i32,
/*15551*/             OPC_MoveParent,
/*15552*/             OPC_RecordChild2, // #3 = $targ16
/*15553*/             OPC_MoveChild, 2,
/*15555*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15558*/             OPC_MoveParent,
/*15559*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15561*/             OPC_EmitMergeInputChains1_0,
/*15562*/             OPC_EmitConvertToTarget, 2,
/*15564*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BteqzT8CmpiX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$imm, SETEQ:Other), (bb:Other):$targ16) - Complexity = 10
                      // Dst: (BteqzT8CmpiX16 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm, (bb:Other):$targ16)
/*15573*/           /*Scope*/ 63, /*->15637*/
/*15574*/             OPC_CheckPredicate, 28, // Predicate_immSExt16
/*15576*/             OPC_MoveParent,
/*15577*/             OPC_MoveChild, 2,
/*15579*/             OPC_Scope, 27, /*->15608*/ // 2 children in Scope
/*15581*/               OPC_CheckCondCode, ISD::SETGE,
/*15583*/               OPC_MoveParent,
/*15584*/               OPC_CheckType, MVT::i32,
/*15586*/               OPC_MoveParent,
/*15587*/               OPC_RecordChild2, // #3 = $imm16
/*15588*/               OPC_MoveChild, 2,
/*15590*/               OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15593*/               OPC_MoveParent,
/*15594*/               OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15596*/               OPC_EmitMergeInputChains1_0,
/*15597*/               OPC_EmitConvertToTarget, 2,
/*15599*/               OPC_MorphNodeTo, TARGET_VAL(Oi::BteqzT8SltiX16), 0|OPFL_Chain,
                            0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                        // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm, SETGE:Other), (bb:Other):$imm16) - Complexity = 10
                        // Dst: (BteqzT8SltiX16 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm, (bb:Other):$imm16)
/*15608*/             /*Scope*/ 27, /*->15636*/
/*15609*/               OPC_CheckCondCode, ISD::SETLT,
/*15611*/               OPC_MoveParent,
/*15612*/               OPC_CheckType, MVT::i32,
/*15614*/               OPC_MoveParent,
/*15615*/               OPC_RecordChild2, // #3 = $imm16
/*15616*/               OPC_MoveChild, 2,
/*15618*/               OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15621*/               OPC_MoveParent,
/*15622*/               OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15624*/               OPC_EmitMergeInputChains1_0,
/*15625*/               OPC_EmitConvertToTarget, 2,
/*15627*/               OPC_MorphNodeTo, TARGET_VAL(Oi::BtnezT8SltiX16), 0|OPFL_Chain,
                            0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                        // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm, SETLT:Other), (bb:Other):$imm16) - Complexity = 10
                        // Dst: (BtnezT8SltiX16 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm, (bb:Other):$imm16)
/*15636*/             0, /*End of Scope*/
/*15637*/           /*Scope*/ 32, /*->15670*/
/*15638*/             OPC_CheckPredicate, 27, // Predicate_immZExt16
/*15640*/             OPC_MoveParent,
/*15641*/             OPC_MoveChild, 2,
/*15643*/             OPC_CheckCondCode, ISD::SETNE,
/*15645*/             OPC_MoveParent,
/*15646*/             OPC_CheckType, MVT::i32,
/*15648*/             OPC_MoveParent,
/*15649*/             OPC_RecordChild2, // #3 = $targ16
/*15650*/             OPC_MoveChild, 2,
/*15652*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15655*/             OPC_MoveParent,
/*15656*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15658*/             OPC_EmitMergeInputChains1_0,
/*15659*/             OPC_EmitConvertToTarget, 2,
/*15661*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BtnezT8CmpiX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$imm, SETNE:Other), (bb:Other):$targ16) - Complexity = 10
                      // Dst: (BtnezT8CmpiX16 CPU16Regs:i32:$rx, (imm:i32)<<P:Predicate_immSExt16>>:$imm, (bb:Other):$targ16)
/*15670*/           /*Scope*/ 87, /*->15758*/
/*15671*/             OPC_CheckPredicate, 28, // Predicate_immSExt16
/*15673*/             OPC_MoveParent,
/*15674*/             OPC_MoveChild, 2,
/*15676*/             OPC_Scope, 39, /*->15717*/ // 2 children in Scope
/*15678*/               OPC_CheckCondCode, ISD::SETGE,
/*15680*/               OPC_MoveParent,
/*15681*/               OPC_CheckType, MVT::i32,
/*15683*/               OPC_MoveParent,
/*15684*/               OPC_RecordChild2, // #3 = $dst
/*15685*/               OPC_MoveChild, 2,
/*15687*/               OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15690*/               OPC_MoveParent,
/*15691*/               OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15693*/               OPC_EmitMergeInputChains1_0,
/*15694*/               OPC_EmitConvertToTarget, 2,
/*15696*/               OPC_EmitNode, TARGET_VAL(Oi::SLTi), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*15705*/               OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*15708*/               OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                            0/*#VTs*/, 3/*#Ops*/, 5, 6, 3, 
                        // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), (bb:Other):$dst) - Complexity = 10
                        // Dst: (BEQ (SLTi:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), ZERO:i32, (bb:Other):$dst)
/*15717*/             /*Scope*/ 39, /*->15757*/
/*15718*/               OPC_CheckCondCode, ISD::SETUGE,
/*15720*/               OPC_MoveParent,
/*15721*/               OPC_CheckType, MVT::i32,
/*15723*/               OPC_MoveParent,
/*15724*/               OPC_RecordChild2, // #3 = $dst
/*15725*/               OPC_MoveChild, 2,
/*15727*/               OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15730*/               OPC_MoveParent,
/*15731*/               OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15733*/               OPC_EmitMergeInputChains1_0,
/*15734*/               OPC_EmitConvertToTarget, 2,
/*15736*/               OPC_EmitNode, TARGET_VAL(Oi::SLTiu), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*15745*/               OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*15748*/               OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                            0/*#VTs*/, 3/*#Ops*/, 5, 6, 3, 
                        // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs, SETUGE:Other), (bb:Other):$dst) - Complexity = 10
                        // Dst: (BEQ (SLTiu:i32 CPURegs:i32:$lhs, (imm:i32)<<P:Predicate_immSExt16>>:$rhs), ZERO:i32, (bb:Other):$dst)
/*15757*/             0, /*End of Scope*/
/*15758*/           0, /*End of Scope*/
/*15759*/         /*Scope*/ 108|128,2/*364*/, /*->16125*/
/*15761*/           OPC_MoveChild, 2,
/*15763*/           OPC_Scope, 25, /*->15790*/ // 12 children in Scope
/*15765*/             OPC_CheckCondCode, ISD::SETEQ,
/*15767*/             OPC_MoveParent,
/*15768*/             OPC_CheckType, MVT::i32,
/*15770*/             OPC_MoveParent,
/*15771*/             OPC_RecordChild2, // #3 = $offset
/*15772*/             OPC_MoveChild, 2,
/*15774*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15777*/             OPC_MoveParent,
/*15778*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15780*/             OPC_EmitMergeInputChains1_0,
/*15781*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPURegs:i32:$rs, CPURegs:i32:$rt, SETEQ:Other), (bb:Other):$offset) - Complexity = 6
                      // Dst: (BEQ CPURegs:i32:$rs, CPURegs:i32:$rt, (bb:Other):$offset)
/*15790*/           /*Scope*/ 25, /*->15816*/
/*15791*/             OPC_CheckCondCode, ISD::SETNE,
/*15793*/             OPC_MoveParent,
/*15794*/             OPC_CheckType, MVT::i32,
/*15796*/             OPC_MoveParent,
/*15797*/             OPC_RecordChild2, // #3 = $offset
/*15798*/             OPC_MoveChild, 2,
/*15800*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15803*/             OPC_MoveParent,
/*15804*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15806*/             OPC_EmitMergeInputChains1_0,
/*15807*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BNE), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPURegs:i32:$rs, CPURegs:i32:$rt, SETNE:Other), (bb:Other):$offset) - Complexity = 6
                      // Dst: (BNE CPURegs:i32:$rs, CPURegs:i32:$rt, (bb:Other):$offset)
/*15816*/           /*Scope*/ 25, /*->15842*/
/*15817*/             OPC_CheckCondCode, ISD::SETEQ,
/*15819*/             OPC_MoveParent,
/*15820*/             OPC_CheckType, MVT::i32,
/*15822*/             OPC_MoveParent,
/*15823*/             OPC_RecordChild2, // #3 = $imm16
/*15824*/             OPC_MoveChild, 2,
/*15826*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15829*/             OPC_MoveParent,
/*15830*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15832*/             OPC_EmitMergeInputChains1_0,
/*15833*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BteqzT8CmpX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETEQ:Other), (bb:Other):$imm16) - Complexity = 6
                      // Dst: (BteqzT8CmpX16 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, (bb:Other):$imm16)
/*15842*/           /*Scope*/ 25, /*->15868*/
/*15843*/             OPC_CheckCondCode, ISD::SETGT,
/*15845*/             OPC_MoveParent,
/*15846*/             OPC_CheckType, MVT::i32,
/*15848*/             OPC_MoveParent,
/*15849*/             OPC_RecordChild2, // #3 = $imm16
/*15850*/             OPC_MoveChild, 2,
/*15852*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15855*/             OPC_MoveParent,
/*15856*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15858*/             OPC_EmitMergeInputChains1_0,
/*15859*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BtnezT8SltX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 2, 1, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETGT:Other), (bb:Other):$imm16) - Complexity = 6
                      // Dst: (BtnezT8SltX16 CPU16Regs:i32:$ry, CPU16Regs:i32:$rx, (bb:Other):$imm16)
/*15868*/           /*Scope*/ 25, /*->15894*/
/*15869*/             OPC_CheckCondCode, ISD::SETGE,
/*15871*/             OPC_MoveParent,
/*15872*/             OPC_CheckType, MVT::i32,
/*15874*/             OPC_MoveParent,
/*15875*/             OPC_RecordChild2, // #3 = $imm16
/*15876*/             OPC_MoveChild, 2,
/*15878*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15881*/             OPC_MoveParent,
/*15882*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15884*/             OPC_EmitMergeInputChains1_0,
/*15885*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BteqzT8SltX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETGE:Other), (bb:Other):$imm16) - Complexity = 6
                      // Dst: (BteqzT8SltX16 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, (bb:Other):$imm16)
/*15894*/           /*Scope*/ 25, /*->15920*/
/*15895*/             OPC_CheckCondCode, ISD::SETLT,
/*15897*/             OPC_MoveParent,
/*15898*/             OPC_CheckType, MVT::i32,
/*15900*/             OPC_MoveParent,
/*15901*/             OPC_RecordChild2, // #3 = $imm16
/*15902*/             OPC_MoveChild, 2,
/*15904*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15907*/             OPC_MoveParent,
/*15908*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15910*/             OPC_EmitMergeInputChains1_0,
/*15911*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BtnezT8SltX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETLT:Other), (bb:Other):$imm16) - Complexity = 6
                      // Dst: (BtnezT8SltX16 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, (bb:Other):$imm16)
/*15920*/           /*Scope*/ 25, /*->15946*/
/*15921*/             OPC_CheckCondCode, ISD::SETLE,
/*15923*/             OPC_MoveParent,
/*15924*/             OPC_CheckType, MVT::i32,
/*15926*/             OPC_MoveParent,
/*15927*/             OPC_RecordChild2, // #3 = $imm16
/*15928*/             OPC_MoveChild, 2,
/*15930*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15933*/             OPC_MoveParent,
/*15934*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15936*/             OPC_EmitMergeInputChains1_0,
/*15937*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BteqzT8SltX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 2, 1, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETLE:Other), (bb:Other):$imm16) - Complexity = 6
                      // Dst: (BteqzT8SltX16 CPU16Regs:i32:$ry, CPU16Regs:i32:$rx, (bb:Other):$imm16)
/*15946*/           /*Scope*/ 25, /*->15972*/
/*15947*/             OPC_CheckCondCode, ISD::SETNE,
/*15949*/             OPC_MoveParent,
/*15950*/             OPC_CheckType, MVT::i32,
/*15952*/             OPC_MoveParent,
/*15953*/             OPC_RecordChild2, // #3 = $imm16
/*15954*/             OPC_MoveChild, 2,
/*15956*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15959*/             OPC_MoveParent,
/*15960*/             OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*15962*/             OPC_EmitMergeInputChains1_0,
/*15963*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BtnezT8CmpX16), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, SETNE:Other), (bb:Other):$imm16) - Complexity = 6
                      // Dst: (BtnezT8CmpX16 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry, (bb:Other):$imm16)
/*15972*/           /*Scope*/ 37, /*->16010*/
/*15973*/             OPC_CheckCondCode, ISD::SETGE,
/*15975*/             OPC_MoveParent,
/*15976*/             OPC_CheckType, MVT::i32,
/*15978*/             OPC_MoveParent,
/*15979*/             OPC_RecordChild2, // #3 = $dst
/*15980*/             OPC_MoveChild, 2,
/*15982*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*15985*/             OPC_MoveParent,
/*15986*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*15988*/             OPC_EmitMergeInputChains1_0,
/*15989*/             OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*15998*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16001*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETGE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLT:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), ZERO:i32, (bb:Other):$dst)
/*16010*/           /*Scope*/ 37, /*->16048*/
/*16011*/             OPC_CheckCondCode, ISD::SETUGE,
/*16013*/             OPC_MoveParent,
/*16014*/             OPC_CheckType, MVT::i32,
/*16016*/             OPC_MoveParent,
/*16017*/             OPC_RecordChild2, // #3 = $dst
/*16018*/             OPC_MoveChild, 2,
/*16020*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16023*/             OPC_MoveParent,
/*16024*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16026*/             OPC_EmitMergeInputChains1_0,
/*16027*/             OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*16036*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16039*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETUGE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLTu:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs), ZERO:i32, (bb:Other):$dst)
/*16048*/           /*Scope*/ 37, /*->16086*/
/*16049*/             OPC_CheckCondCode, ISD::SETLE,
/*16051*/             OPC_MoveParent,
/*16052*/             OPC_CheckType, MVT::i32,
/*16054*/             OPC_MoveParent,
/*16055*/             OPC_RecordChild2, // #3 = $dst
/*16056*/             OPC_MoveChild, 2,
/*16058*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16061*/             OPC_MoveParent,
/*16062*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16064*/             OPC_EmitMergeInputChains1_0,
/*16065*/             OPC_EmitNode, TARGET_VAL(Oi::SLT), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*16074*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16077*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETLE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLT:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), ZERO:i32, (bb:Other):$dst)
/*16086*/           /*Scope*/ 37, /*->16124*/
/*16087*/             OPC_CheckCondCode, ISD::SETULE,
/*16089*/             OPC_MoveParent,
/*16090*/             OPC_CheckType, MVT::i32,
/*16092*/             OPC_MoveParent,
/*16093*/             OPC_RecordChild2, // #3 = $dst
/*16094*/             OPC_MoveChild, 2,
/*16096*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16099*/             OPC_MoveParent,
/*16100*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16102*/             OPC_EmitMergeInputChains1_0,
/*16103*/             OPC_EmitNode, TARGET_VAL(Oi::SLTu), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*16112*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16115*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPURegs:i32:$lhs, CPURegs:i32:$rhs, SETULE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLTu:i32 CPURegs:i32:$rhs, CPURegs:i32:$lhs), ZERO:i32, (bb:Other):$dst)
/*16124*/           0, /*End of Scope*/
/*16125*/         0, /*End of Scope*/
/*16126*/       0, /*End of Scope*/
/*16127*/     /*Scope*/ 97|128,3/*481*/, /*->16610*/
/*16129*/       OPC_CheckChild0Type, MVT::i64,
/*16131*/       OPC_Scope, 39|128,1/*167*/, /*->16301*/ // 2 children in Scope
/*16134*/         OPC_MoveChild, 1,
/*16136*/         OPC_CheckInteger, 0, 
/*16138*/         OPC_MoveParent,
/*16139*/         OPC_MoveChild, 2,
/*16141*/         OPC_Scope, 24, /*->16167*/ // 6 children in Scope
/*16143*/           OPC_CheckCondCode, ISD::SETGE,
/*16145*/           OPC_MoveParent,
/*16146*/           OPC_CheckType, MVT::i32,
/*16148*/           OPC_MoveParent,
/*16149*/           OPC_RecordChild2, // #2 = $offset
/*16150*/           OPC_MoveChild, 2,
/*16152*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16155*/           OPC_MoveParent,
/*16156*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16158*/           OPC_EmitMergeInputChains1_0,
/*16159*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BGEZ64), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPU64Regs:i64:$rs, 0:i64, SETGE:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BGEZ64 CPU64Regs:i64:$rs, (bb:Other):$offset)
/*16167*/         /*Scope*/ 24, /*->16192*/
/*16168*/           OPC_CheckCondCode, ISD::SETGT,
/*16170*/           OPC_MoveParent,
/*16171*/           OPC_CheckType, MVT::i32,
/*16173*/           OPC_MoveParent,
/*16174*/           OPC_RecordChild2, // #2 = $offset
/*16175*/           OPC_MoveChild, 2,
/*16177*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16180*/           OPC_MoveParent,
/*16181*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16183*/           OPC_EmitMergeInputChains1_0,
/*16184*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BGTZ64), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPU64Regs:i64:$rs, 0:i64, SETGT:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BGTZ64 CPU64Regs:i64:$rs, (bb:Other):$offset)
/*16192*/         /*Scope*/ 24, /*->16217*/
/*16193*/           OPC_CheckCondCode, ISD::SETLE,
/*16195*/           OPC_MoveParent,
/*16196*/           OPC_CheckType, MVT::i32,
/*16198*/           OPC_MoveParent,
/*16199*/           OPC_RecordChild2, // #2 = $offset
/*16200*/           OPC_MoveChild, 2,
/*16202*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16205*/           OPC_MoveParent,
/*16206*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16208*/           OPC_EmitMergeInputChains1_0,
/*16209*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BLEZ64), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPU64Regs:i64:$rs, 0:i64, SETLE:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BLEZ64 CPU64Regs:i64:$rs, (bb:Other):$offset)
/*16217*/         /*Scope*/ 24, /*->16242*/
/*16218*/           OPC_CheckCondCode, ISD::SETLT,
/*16220*/           OPC_MoveParent,
/*16221*/           OPC_CheckType, MVT::i32,
/*16223*/           OPC_MoveParent,
/*16224*/           OPC_RecordChild2, // #2 = $offset
/*16225*/           OPC_MoveChild, 2,
/*16227*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16230*/           OPC_MoveParent,
/*16231*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16233*/           OPC_EmitMergeInputChains1_0,
/*16234*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BLTZ64), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 CPU64Regs:i64:$rs, 0:i64, SETLT:Other), (bb:Other):$offset) - Complexity = 11
                    // Dst: (BLTZ64 CPU64Regs:i64:$rs, (bb:Other):$offset)
/*16242*/         /*Scope*/ 28, /*->16271*/
/*16243*/           OPC_CheckCondCode, ISD::SETNE,
/*16245*/           OPC_MoveParent,
/*16246*/           OPC_CheckType, MVT::i32,
/*16248*/           OPC_MoveParent,
/*16249*/           OPC_RecordChild2, // #2 = $dst
/*16250*/           OPC_MoveChild, 2,
/*16252*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16255*/           OPC_MoveParent,
/*16256*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16258*/           OPC_EmitMergeInputChains1_0,
/*16259*/           OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*16262*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BNE64), 0|OPFL_Chain,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                    // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETNE:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BNE64 CPU64Regs:i64:$lhs, ZERO_64:i64, (bb:Other):$dst)
/*16271*/         /*Scope*/ 28, /*->16300*/
/*16272*/           OPC_CheckCondCode, ISD::SETEQ,
/*16274*/           OPC_MoveParent,
/*16275*/           OPC_CheckType, MVT::i32,
/*16277*/           OPC_MoveParent,
/*16278*/           OPC_RecordChild2, // #2 = $dst
/*16279*/           OPC_MoveChild, 2,
/*16281*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16284*/           OPC_MoveParent,
/*16285*/           OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16287*/           OPC_EmitMergeInputChains1_0,
/*16288*/           OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*16291*/           OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ64), 0|OPFL_Chain,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                    // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, 0:i64, SETEQ:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BEQ64 CPU64Regs:i64:$lhs, ZERO_64:i64, (bb:Other):$dst)
/*16300*/         0, /*End of Scope*/
/*16301*/       /*Scope*/ 50|128,2/*306*/, /*->16609*/
/*16303*/         OPC_RecordChild1, // #2 = $rhs
/*16304*/         OPC_Scope, 92, /*->16398*/ // 2 children in Scope
/*16306*/           OPC_MoveChild, 1,
/*16308*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16311*/           OPC_CheckPredicate, 28, // Predicate_immSExt16
/*16313*/           OPC_MoveParent,
/*16314*/           OPC_MoveChild, 2,
/*16316*/           OPC_Scope, 39, /*->16357*/ // 2 children in Scope
/*16318*/             OPC_CheckCondCode, ISD::SETGE,
/*16320*/             OPC_MoveParent,
/*16321*/             OPC_CheckType, MVT::i32,
/*16323*/             OPC_MoveParent,
/*16324*/             OPC_RecordChild2, // #3 = $dst
/*16325*/             OPC_MoveChild, 2,
/*16327*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16330*/             OPC_MoveParent,
/*16331*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16333*/             OPC_EmitMergeInputChains1_0,
/*16334*/             OPC_EmitConvertToTarget, 2,
/*16336*/             OPC_EmitNode, TARGET_VAL(Oi::SLTi64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*16345*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16348*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 5, 6, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETGE:Other), (bb:Other):$dst) - Complexity = 10
                      // Dst: (BEQ (SLTi64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), ZERO:i32, (bb:Other):$dst)
/*16357*/           /*Scope*/ 39, /*->16397*/
/*16358*/             OPC_CheckCondCode, ISD::SETUGE,
/*16360*/             OPC_MoveParent,
/*16361*/             OPC_CheckType, MVT::i32,
/*16363*/             OPC_MoveParent,
/*16364*/             OPC_RecordChild2, // #3 = $dst
/*16365*/             OPC_MoveChild, 2,
/*16367*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16370*/             OPC_MoveParent,
/*16371*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16373*/             OPC_EmitMergeInputChains1_0,
/*16374*/             OPC_EmitConvertToTarget, 2,
/*16376*/             OPC_EmitNode, TARGET_VAL(Oi::SLTiu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*16385*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16388*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 5, 6, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs, SETUGE:Other), (bb:Other):$dst) - Complexity = 10
                      // Dst: (BEQ (SLTiu64:i32 CPU64Regs:i64:$lhs, (imm:i64)<<P:Predicate_immSExt16>>:$rhs), ZERO:i32, (bb:Other):$dst)
/*16397*/           0, /*End of Scope*/
/*16398*/         /*Scope*/ 80|128,1/*208*/, /*->16608*/
/*16400*/           OPC_MoveChild, 2,
/*16402*/           OPC_Scope, 25, /*->16429*/ // 6 children in Scope
/*16404*/             OPC_CheckCondCode, ISD::SETEQ,
/*16406*/             OPC_MoveParent,
/*16407*/             OPC_CheckType, MVT::i32,
/*16409*/             OPC_MoveParent,
/*16410*/             OPC_RecordChild2, // #3 = $offset
/*16411*/             OPC_MoveChild, 2,
/*16413*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16416*/             OPC_MoveParent,
/*16417*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16419*/             OPC_EmitMergeInputChains1_0,
/*16420*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ64), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt, SETEQ:Other), (bb:Other):$offset) - Complexity = 6
                      // Dst: (BEQ64 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt, (bb:Other):$offset)
/*16429*/           /*Scope*/ 25, /*->16455*/
/*16430*/             OPC_CheckCondCode, ISD::SETNE,
/*16432*/             OPC_MoveParent,
/*16433*/             OPC_CheckType, MVT::i32,
/*16435*/             OPC_MoveParent,
/*16436*/             OPC_RecordChild2, // #3 = $offset
/*16437*/             OPC_MoveChild, 2,
/*16439*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16442*/             OPC_MoveParent,
/*16443*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16445*/             OPC_EmitMergeInputChains1_0,
/*16446*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BNE64), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt, SETNE:Other), (bb:Other):$offset) - Complexity = 6
                      // Dst: (BNE64 CPU64Regs:i64:$rs, CPU64Regs:i64:$rt, (bb:Other):$offset)
/*16455*/           /*Scope*/ 37, /*->16493*/
/*16456*/             OPC_CheckCondCode, ISD::SETGE,
/*16458*/             OPC_MoveParent,
/*16459*/             OPC_CheckType, MVT::i32,
/*16461*/             OPC_MoveParent,
/*16462*/             OPC_RecordChild2, // #3 = $dst
/*16463*/             OPC_MoveChild, 2,
/*16465*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16468*/             OPC_MoveParent,
/*16469*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16471*/             OPC_EmitMergeInputChains1_0,
/*16472*/             OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*16481*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16484*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETGE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLT64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), ZERO:i32, (bb:Other):$dst)
/*16493*/           /*Scope*/ 37, /*->16531*/
/*16494*/             OPC_CheckCondCode, ISD::SETUGE,
/*16496*/             OPC_MoveParent,
/*16497*/             OPC_CheckType, MVT::i32,
/*16499*/             OPC_MoveParent,
/*16500*/             OPC_RecordChild2, // #3 = $dst
/*16501*/             OPC_MoveChild, 2,
/*16503*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16506*/             OPC_MoveParent,
/*16507*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16509*/             OPC_EmitMergeInputChains1_0,
/*16510*/             OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*16519*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16522*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETUGE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLTu64:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs), ZERO:i32, (bb:Other):$dst)
/*16531*/           /*Scope*/ 37, /*->16569*/
/*16532*/             OPC_CheckCondCode, ISD::SETLE,
/*16534*/             OPC_MoveParent,
/*16535*/             OPC_CheckType, MVT::i32,
/*16537*/             OPC_MoveParent,
/*16538*/             OPC_RecordChild2, // #3 = $dst
/*16539*/             OPC_MoveChild, 2,
/*16541*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16544*/             OPC_MoveParent,
/*16545*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16547*/             OPC_EmitMergeInputChains1_0,
/*16548*/             OPC_EmitNode, TARGET_VAL(Oi::SLT64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*16557*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16560*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETLE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLT64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), ZERO:i32, (bb:Other):$dst)
/*16569*/           /*Scope*/ 37, /*->16607*/
/*16570*/             OPC_CheckCondCode, ISD::SETULE,
/*16572*/             OPC_MoveParent,
/*16573*/             OPC_CheckType, MVT::i32,
/*16575*/             OPC_MoveParent,
/*16576*/             OPC_RecordChild2, // #3 = $dst
/*16577*/             OPC_MoveChild, 2,
/*16579*/             OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16582*/             OPC_MoveParent,
/*16583*/             OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16585*/             OPC_EmitMergeInputChains1_0,
/*16586*/             OPC_EmitNode, TARGET_VAL(Oi::SLTu64), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*16595*/             OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16598*/             OPC_MorphNodeTo, TARGET_VAL(Oi::BEQ), 0|OPFL_Chain,
                          0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (brcond (setcc:i32 CPU64Regs:i64:$lhs, CPU64Regs:i64:$rhs, SETULE:Other), (bb:Other):$dst) - Complexity = 6
                      // Dst: (BEQ (SLTu64:i32 CPU64Regs:i64:$rhs, CPU64Regs:i64:$lhs), ZERO:i32, (bb:Other):$dst)
/*16607*/           0, /*End of Scope*/
/*16608*/         0, /*End of Scope*/
/*16609*/       0, /*End of Scope*/
/*16610*/     0, /*End of Scope*/
/*16611*/   /*Scope*/ 68, /*->16680*/
/*16612*/     OPC_RecordChild1, // #1 = $cond
/*16613*/     OPC_Scope, 39, /*->16654*/ // 2 children in Scope
/*16615*/       OPC_CheckChild1Type, MVT::i32,
/*16617*/       OPC_RecordChild2, // #2 = $dst
/*16618*/       OPC_MoveChild, 2,
/*16620*/       OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16623*/       OPC_MoveParent,
/*16624*/       OPC_Scope, 15, /*->16641*/ // 2 children in Scope
/*16626*/         OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16628*/         OPC_EmitMergeInputChains1_0,
/*16629*/         OPC_EmitRegister, MVT::i32, Oi::ZERO,
/*16632*/         OPC_MorphNodeTo, TARGET_VAL(Oi::BNE), 0|OPFL_Chain,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                  // Src: (brcond CPURegs:i32:$cond, (bb:Other):$dst) - Complexity = 3
                  // Dst: (BNE CPURegs:i32:$cond, ZERO:i32, (bb:Other):$dst)
/*16641*/       /*Scope*/ 11, /*->16653*/
/*16642*/         OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*16644*/         OPC_EmitMergeInputChains1_0,
/*16645*/         OPC_MorphNodeTo, TARGET_VAL(Oi::BnezRxImmX16), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                  // Src: (brcond CPU16Regs:i32:$rx, (bb:Other):$targ16) - Complexity = 3
                  // Dst: (BnezRxImmX16 CPU16Regs:i32:$rx, (bb:Other):$targ16)
/*16653*/       0, /*End of Scope*/
/*16654*/     /*Scope*/ 24, /*->16679*/
/*16655*/       OPC_CheckChild1Type, MVT::i64,
/*16657*/       OPC_RecordChild2, // #2 = $dst
/*16658*/       OPC_MoveChild, 2,
/*16660*/       OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16663*/       OPC_MoveParent,
/*16664*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16666*/       OPC_EmitMergeInputChains1_0,
/*16667*/       OPC_EmitRegister, MVT::i64, Oi::ZERO_64,
/*16670*/       OPC_MorphNodeTo, TARGET_VAL(Oi::BNE64), 0|OPFL_Chain,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                // Src: (brcond CPU64Regs:i64:$cond, (bb:Other):$dst) - Complexity = 3
                // Dst: (BNE64 CPU64Regs:i64:$cond, ZERO_64:i64, (bb:Other):$dst)
/*16679*/     0, /*End of Scope*/
/*16680*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 25,  TARGET_VAL(ISD::CALLSEQ_END),// ->16709
/*16684*/   OPC_RecordNode,   // #0 = 'callseq_end' chained node
/*16685*/   OPC_CaptureGlueInput,
/*16686*/   OPC_RecordChild1, // #1 = $amt1
/*16687*/   OPC_MoveChild, 1,
/*16689*/   OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*16692*/   OPC_MoveParent,
/*16693*/   OPC_RecordChild2, // #2 = $amt2
/*16694*/   OPC_MoveChild, 2,
/*16696*/   OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*16699*/   OPC_MoveParent,
/*16700*/   OPC_EmitMergeInputChains1_0,
/*16701*/   OPC_MorphNodeTo, TARGET_VAL(Oi::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:i32):$amt1, (timm:i32):$amt2) - Complexity = 9
            // Dst: (ADJCALLSTACKUP (timm:i32):$amt1, (timm:i32):$amt2)
          /*SwitchOpcode*/ 50,  TARGET_VAL(OiISD::FPBrcond),// ->16762
/*16712*/   OPC_RecordNode,   // #0 = 'OiFPBrcond' chained node
/*16713*/   OPC_CaptureGlueInput,
/*16714*/   OPC_MoveChild, 1,
/*16716*/   OPC_CheckType, MVT::i32,
/*16718*/   OPC_Scope, 20, /*->16740*/ // 2 children in Scope
/*16720*/     OPC_CheckInteger, 0, 
/*16722*/     OPC_MoveParent,
/*16723*/     OPC_RecordChild2, // #1 = $offset
/*16724*/     OPC_MoveChild, 2,
/*16726*/     OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16729*/     OPC_MoveParent,
/*16730*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16732*/     OPC_EmitMergeInputChains1_0,
/*16733*/     OPC_MorphNodeTo, TARGET_VAL(Oi::BC1F), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (OiFPBrcond 0:i32, (bb:Other):$offset) - Complexity = 8
              // Dst: (BC1F (bb:Other):$offset)
/*16740*/   /*Scope*/ 20, /*->16761*/
/*16741*/     OPC_CheckInteger, 1, 
/*16743*/     OPC_MoveParent,
/*16744*/     OPC_RecordChild2, // #1 = $offset
/*16745*/     OPC_MoveChild, 2,
/*16747*/     OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*16750*/     OPC_MoveParent,
/*16751*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16753*/     OPC_EmitMergeInputChains1_0,
/*16754*/     OPC_MorphNodeTo, TARGET_VAL(Oi::BC1T), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (OiFPBrcond 1:i32, (bb:Other):$offset) - Complexity = 8
              // Dst: (BC1T (bb:Other):$offset)
/*16761*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 37,  TARGET_VAL(OiISD::SHILO),// ->16802
/*16765*/   OPC_RecordNode,   // #0 = 'OiSHILO' chained node
/*16766*/   OPC_CaptureGlueInput,
/*16767*/   OPC_RecordChild1, // #1 = $shift
/*16768*/   OPC_Scope, 20, /*->16790*/ // 2 children in Scope
/*16770*/     OPC_MoveChild, 1,
/*16772*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16775*/     OPC_CheckPredicate, 65, // Predicate_immSExt6
/*16777*/     OPC_MoveParent,
/*16778*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*16780*/     OPC_EmitMergeInputChains1_0,
/*16781*/     OPC_EmitConvertToTarget, 1,
/*16783*/     OPC_MorphNodeTo, TARGET_VAL(Oi::SHILO_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  0/*#VTs*/, 1/*#Ops*/, 2, 
              // Src: (OiSHILO (imm:i32)<<P:Predicate_immSExt6>>:$shift) - Complexity = 7
              // Dst: (SHILO_PSEUDO (imm:i32):$shift)
/*16790*/   /*Scope*/ 10, /*->16801*/
/*16791*/     OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*16793*/     OPC_EmitMergeInputChains1_0,
/*16794*/     OPC_MorphNodeTo, TARGET_VAL(Oi::SHILOV_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (OiSHILO CPURegs:i32:$rs) - Complexity = 3
              // Dst: (SHILOV_PSEUDO CPURegs:i32:$rs)
/*16801*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::CALLSEQ_START),// ->16821
/*16805*/   OPC_RecordNode,   // #0 = 'callseq_start' chained node
/*16806*/   OPC_RecordChild1, // #1 = $amt
/*16807*/   OPC_MoveChild, 1,
/*16809*/   OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*16812*/   OPC_MoveParent,
/*16813*/   OPC_EmitMergeInputChains1_0,
/*16814*/   OPC_MorphNodeTo, TARGET_VAL(Oi::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (callseq_start (timm:i32):$amt) - Complexity = 6
            // Dst: (ADJCALLSTACKDOWN (timm:i32):$amt)
          /*SwitchOpcode*/ 20,  TARGET_VAL(OiISD::Sync),// ->16844
/*16824*/   OPC_RecordNode,   // #0 = 'OiSync' chained node
/*16825*/   OPC_RecordChild1, // #1 = $stype
/*16826*/   OPC_MoveChild, 1,
/*16828*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16831*/   OPC_MoveParent,
/*16832*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16834*/   OPC_EmitMergeInputChains1_0,
/*16835*/   OPC_EmitConvertToTarget, 1,
/*16837*/   OPC_MorphNodeTo, TARGET_VAL(Oi::SYNC), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 2, 
            // Src: (OiSync (imm:i32):$stype) - Complexity = 6
            // Dst: (SYNC (imm:i32):$stype)
          /*SwitchOpcode*/ 98,  TARGET_VAL(OiISD::JmpLink),// ->16945
/*16847*/   OPC_RecordNode,   // #0 = 'OiJmpLink' chained node
/*16848*/   OPC_CaptureGlueInput,
/*16849*/   OPC_RecordChild1, // #1 = $target
/*16850*/   OPC_Scope, 52, /*->16904*/ // 3 children in Scope
/*16852*/     OPC_MoveChild, 1,
/*16854*/     OPC_SwitchOpcode /*3 cases */, 13,  TARGET_VAL(ISD::Constant),// ->16871
/*16858*/       OPC_MoveParent,
/*16859*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16861*/       OPC_EmitMergeInputChains1_0,
/*16862*/       OPC_EmitConvertToTarget, 1,
/*16864*/       OPC_MorphNodeTo, TARGET_VAL(Oi::JAL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (OiJmpLink (imm:iPTR):$target) - Complexity = 6
                // Dst: (JAL (imm:iPTR):$target)
              /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TargetGlobalAddress),// ->16887
/*16874*/       OPC_CheckType, MVT::i32,
/*16876*/       OPC_MoveParent,
/*16877*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16879*/       OPC_EmitMergeInputChains1_0,
/*16880*/       OPC_MorphNodeTo, TARGET_VAL(Oi::JAL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (OiJmpLink (tglobaladdr:i32):$dst) - Complexity = 6
                // Dst: (JAL (tglobaladdr:i32):$dst)
              /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TargetExternalSymbol),// ->16903
/*16890*/       OPC_CheckType, MVT::i32,
/*16892*/       OPC_MoveParent,
/*16893*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16895*/       OPC_EmitMergeInputChains1_0,
/*16896*/       OPC_MorphNodeTo, TARGET_VAL(Oi::JAL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (OiJmpLink (texternalsym:i32):$dst) - Complexity = 6
                // Dst: (JAL (texternalsym:i32):$dst)
              0, // EndSwitchOpcode
/*16904*/   /*Scope*/ 26, /*->16931*/
/*16905*/     OPC_CheckChild1Type, MVT::i32,
/*16907*/     OPC_Scope, 10, /*->16919*/ // 2 children in Scope
/*16909*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16911*/       OPC_EmitMergeInputChains1_0,
/*16912*/       OPC_MorphNodeTo, TARGET_VAL(Oi::JALR), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (OiJmpLink CPURegs:i32:$rs) - Complexity = 3
                // Dst: (JALR CPURegs:i32:$rs)
/*16919*/     /*Scope*/ 10, /*->16930*/
/*16920*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*16922*/       OPC_EmitMergeInputChains1_0,
/*16923*/       OPC_MorphNodeTo, TARGET_VAL(Oi::JumpLinkReg16), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (OiJmpLink CPU16Regs:i32:$rs) - Complexity = 3
                // Dst: (JumpLinkReg16 CPU16Regs:i32:$rs)
/*16930*/     0, /*End of Scope*/
/*16931*/   /*Scope*/ 12, /*->16944*/
/*16932*/     OPC_CheckChild1Type, MVT::i64,
/*16934*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16936*/     OPC_EmitMergeInputChains1_0,
/*16937*/     OPC_MorphNodeTo, TARGET_VAL(Oi::JALR64), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (OiJmpLink CPU64Regs:i64:$rs) - Complexity = 3
              // Dst: (JALR64 CPU64Regs:i64:$rs)
/*16944*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 80,  TARGET_VAL(OiISD::TailCall),// ->17028
/*16948*/   OPC_RecordNode,   // #0 = 'OiTailCall' chained node
/*16949*/   OPC_CaptureGlueInput,
/*16950*/   OPC_RecordChild1, // #1 = $target
/*16951*/   OPC_Scope, 48, /*->17001*/ // 3 children in Scope
/*16953*/     OPC_MoveChild, 1,
/*16955*/     OPC_SwitchOpcode /*3 cases */, 13,  TARGET_VAL(ISD::Constant),// ->16972
/*16959*/       OPC_MoveParent,
/*16960*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16962*/       OPC_EmitMergeInputChains1_0,
/*16963*/       OPC_EmitConvertToTarget, 1,
/*16965*/       OPC_MorphNodeTo, TARGET_VAL(Oi::TAILCALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (OiTailCall (imm:iPTR):$target) - Complexity = 6
                // Dst: (TAILCALL (imm:iPTR):$target)
              /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetGlobalAddress),// ->16986
/*16975*/       OPC_MoveParent,
/*16976*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16978*/       OPC_EmitMergeInputChains1_0,
/*16979*/       OPC_MorphNodeTo, TARGET_VAL(Oi::TAILCALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (OiTailCall (tglobaladdr:iPTR):$dst) - Complexity = 6
                // Dst: (TAILCALL (tglobaladdr:iPTR):$dst)
              /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetExternalSymbol),// ->17000
/*16989*/       OPC_MoveParent,
/*16990*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*16992*/       OPC_EmitMergeInputChains1_0,
/*16993*/       OPC_MorphNodeTo, TARGET_VAL(Oi::TAILCALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (OiTailCall (texternalsym:iPTR):$dst) - Complexity = 6
                // Dst: (TAILCALL (texternalsym:iPTR):$dst)
              0, // EndSwitchOpcode
/*17001*/   /*Scope*/ 12, /*->17014*/
/*17002*/     OPC_CheckChild1Type, MVT::i32,
/*17004*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17006*/     OPC_EmitMergeInputChains1_0,
/*17007*/     OPC_MorphNodeTo, TARGET_VAL(Oi::TAILCALL_R), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (OiTailCall CPURegs:i32:$rs) - Complexity = 3
              // Dst: (TAILCALL_R CPURegs:i32:$rs)
/*17014*/   /*Scope*/ 12, /*->17027*/
/*17015*/     OPC_CheckChild1Type, MVT::i64,
/*17017*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17019*/     OPC_EmitMergeInputChains1_0,
/*17020*/     OPC_MorphNodeTo, TARGET_VAL(Oi::TAILCALL64_R), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (OiTailCall CPU64Regs:i64:$rs) - Complexity = 3
              // Dst: (TAILCALL64_R CPU64Regs:i64:$rs)
/*17027*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 71,  TARGET_VAL(OiISD::FPCmp),// ->17102
/*17031*/   OPC_RecordChild0, // #0 = $fs
/*17032*/   OPC_Scope, 24, /*->17058*/ // 2 children in Scope
/*17034*/     OPC_CheckChild0Type, MVT::f32,
/*17036*/     OPC_RecordChild1, // #1 = $ft
/*17037*/     OPC_RecordChild2, // #2 = $cond
/*17038*/     OPC_MoveChild, 2,
/*17040*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*17043*/     OPC_MoveParent,
/*17044*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17046*/     OPC_EmitConvertToTarget, 2,
/*17048*/     OPC_MorphNodeTo, TARGET_VAL(Oi::FCMP_S32), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
              // Src: (OiFPCmp FGR32:f32:$fs, FGR32:f32:$ft, (imm:i32):$cond) - Complexity = 6
              // Dst: (FCMP_S32:i32 FGR32:f32:$fs, FGR32:f32:$ft, (imm:i32):$cond)
/*17058*/   /*Scope*/ 42, /*->17101*/
/*17059*/     OPC_CheckChild0Type, MVT::f64,
/*17061*/     OPC_RecordChild1, // #1 = $ft
/*17062*/     OPC_RecordChild2, // #2 = $cond
/*17063*/     OPC_MoveChild, 2,
/*17065*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*17068*/     OPC_MoveParent,
/*17069*/     OPC_Scope, 14, /*->17085*/ // 2 children in Scope
/*17071*/       OPC_CheckPatternPredicate, 13, // (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*17073*/       OPC_EmitConvertToTarget, 2,
/*17075*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FCMP_D32), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
                // Src: (OiFPCmp AFGR64:f64:$fs, AFGR64:f64:$ft, (imm:i32):$cond) - Complexity = 6
                // Dst: (FCMP_D32:i32 AFGR64:f64:$fs, AFGR64:f64:$ft, (imm:i32):$cond)
/*17085*/     /*Scope*/ 14, /*->17100*/
/*17086*/       OPC_CheckPatternPredicate, 14, // (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding())
/*17088*/       OPC_EmitConvertToTarget, 2,
/*17090*/       OPC_MorphNodeTo, TARGET_VAL(Oi::FCMP_D64), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
                // Src: (OiFPCmp FGR64:f64:$fs, FGR64:f64:$ft, (imm:i32):$cond) - Complexity = 6
                // Dst: (FCMP_D64:i32 FGR64:f64:$fs, FGR64:f64:$ft, (imm:i32):$cond)
/*17100*/     0, /*End of Scope*/
/*17101*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 24,  TARGET_VAL(OiISD::Ret),// ->17129
/*17105*/   OPC_RecordNode,   // #0 = 'OiRet' chained node
/*17106*/   OPC_CaptureGlueInput,
/*17107*/   OPC_Scope, 9, /*->17118*/ // 2 children in Scope
/*17109*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17111*/     OPC_EmitMergeInputChains1_0,
/*17112*/     OPC_MorphNodeTo, TARGET_VAL(Oi::RetRA), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (OiRet) - Complexity = 3
              // Dst: (RetRA)
/*17118*/   /*Scope*/ 9, /*->17128*/
/*17119*/     OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*17121*/     OPC_EmitMergeInputChains1_0,
/*17122*/     OPC_MorphNodeTo, TARGET_VAL(Oi::RetRA16), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (OiRet) - Complexity = 3
              // Dst: (RetRA16)
/*17128*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 43,  TARGET_VAL(ISD::BR),// ->17175
/*17132*/   OPC_RecordNode,   // #0 = 'br' chained node
/*17133*/   OPC_RecordChild1, // #1 = $target
/*17134*/   OPC_MoveChild, 1,
/*17136*/   OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*17139*/   OPC_MoveParent,
/*17140*/   OPC_Scope, 10, /*->17152*/ // 3 children in Scope
/*17142*/     OPC_CheckPatternPredicate, 24, // (TM.getRelocationModel() == Reloc::Static) && (Subtarget.hasStandardEncoding())
/*17144*/     OPC_EmitMergeInputChains1_0,
/*17145*/     OPC_MorphNodeTo, TARGET_VAL(Oi::J), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$target) - Complexity = 3
              // Dst: (J (bb:Other):$target)
/*17152*/   /*Scope*/ 10, /*->17163*/
/*17153*/     OPC_CheckPatternPredicate, 25, // (TM.getRelocationModel() == Reloc::PIC_) && (Subtarget.hasStandardEncoding())
/*17155*/     OPC_EmitMergeInputChains1_0,
/*17156*/     OPC_MorphNodeTo, TARGET_VAL(Oi::B), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$offset) - Complexity = 3
              // Dst: (B (bb:Other):$offset)
/*17163*/   /*Scope*/ 10, /*->17174*/
/*17164*/     OPC_CheckPatternPredicate, 26, // (TM.getRelocationModel() == Reloc::PIC_) && (Subtarget.inOi16Mode())
/*17166*/     OPC_EmitMergeInputChains1_0,
/*17167*/     OPC_MorphNodeTo, TARGET_VAL(Oi::BimmX16), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$imm16) - Complexity = 3
              // Dst: (BimmX16 (bb:Other):$imm16)
/*17174*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 44,  TARGET_VAL(ISD::BRIND),// ->17222
/*17178*/   OPC_RecordNode,   // #0 = 'brind' chained node
/*17179*/   OPC_RecordChild1, // #1 = $rs
/*17180*/   OPC_Scope, 26, /*->17208*/ // 2 children in Scope
/*17182*/     OPC_CheckChild1Type, MVT::i32,
/*17184*/     OPC_Scope, 10, /*->17196*/ // 2 children in Scope
/*17186*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17188*/       OPC_EmitMergeInputChains1_0,
/*17189*/       OPC_MorphNodeTo, TARGET_VAL(Oi::JR), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (brind CPURegs:i32:$rs) - Complexity = 3
                // Dst: (JR CPURegs:i32:$rs)
/*17196*/     /*Scope*/ 10, /*->17207*/
/*17197*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*17199*/       OPC_EmitMergeInputChains1_0,
/*17200*/       OPC_MorphNodeTo, TARGET_VAL(Oi::JrcRx16), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (brind CPU16Regs:i32:$rs) - Complexity = 3
                // Dst: (JrcRx16 CPU16Regs:i32:$rs)
/*17207*/     0, /*End of Scope*/
/*17208*/   /*Scope*/ 12, /*->17221*/
/*17209*/     OPC_CheckChild1Type, MVT::i64,
/*17211*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17213*/     OPC_EmitMergeInputChains1_0,
/*17214*/     OPC_MorphNodeTo, TARGET_VAL(Oi::JR64), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (brind CPU64Regs:i64:$rs) - Complexity = 3
              // Dst: (JR64 CPU64Regs:i64:$rs)
/*17221*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 48,  TARGET_VAL(OiISD::DivRem),// ->17273
/*17225*/   OPC_RecordChild0, // #0 = $rs
/*17226*/   OPC_Scope, 29, /*->17257*/ // 2 children in Scope
/*17228*/     OPC_CheckChild0Type, MVT::i32,
/*17230*/     OPC_RecordChild1, // #1 = $rt
/*17231*/     OPC_Scope, 11, /*->17244*/ // 2 children in Scope
/*17233*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17235*/       OPC_MorphNodeTo, TARGET_VAL(Oi::SDIV), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiDivRem CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
                // Dst: (SDIV:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*17244*/     /*Scope*/ 11, /*->17256*/
/*17245*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*17247*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DivRxRy16), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiDivRem CPU16Regs:i32:$rx, CPU16Regs:i32:$ry) - Complexity = 3
                // Dst: (DivRxRy16:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry)
/*17256*/     0, /*End of Scope*/
/*17257*/   /*Scope*/ 14, /*->17272*/
/*17258*/     OPC_CheckChild0Type, MVT::i64,
/*17260*/     OPC_RecordChild1, // #1 = $rt
/*17261*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17263*/     OPC_MorphNodeTo, TARGET_VAL(Oi::DSDIV), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (OiDivRem CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt) - Complexity = 3
              // Dst: (DSDIV:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
/*17272*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 48,  TARGET_VAL(OiISD::DivRemU),// ->17324
/*17276*/   OPC_RecordChild0, // #0 = $rs
/*17277*/   OPC_Scope, 29, /*->17308*/ // 2 children in Scope
/*17279*/     OPC_CheckChild0Type, MVT::i32,
/*17281*/     OPC_RecordChild1, // #1 = $rt
/*17282*/     OPC_Scope, 11, /*->17295*/ // 2 children in Scope
/*17284*/       OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17286*/       OPC_MorphNodeTo, TARGET_VAL(Oi::UDIV), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiDivRemU CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt) - Complexity = 3
                // Dst: (UDIV:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
/*17295*/     /*Scope*/ 11, /*->17307*/
/*17296*/       OPC_CheckPatternPredicate, 2, // (Subtarget.inOi16Mode())
/*17298*/       OPC_MorphNodeTo, TARGET_VAL(Oi::DivuRxRy16), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (OiDivRemU CPU16Regs:i32:$rx, CPU16Regs:i32:$ry) - Complexity = 3
                // Dst: (DivuRxRy16:i32 CPU16Regs:i32:$rx, CPU16Regs:i32:$ry)
/*17307*/     0, /*End of Scope*/
/*17308*/   /*Scope*/ 14, /*->17323*/
/*17309*/     OPC_CheckChild0Type, MVT::i64,
/*17311*/     OPC_RecordChild1, // #1 = $rt
/*17312*/     OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17314*/     OPC_MorphNodeTo, TARGET_VAL(Oi::DUDIV), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (OiDivRemU CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt) - Complexity = 3
              // Dst: (DUDIV:i64 CPU64RegsOpnd:i64:$rs, CPU64RegsOpnd:i64:$rt)
/*17323*/   0, /*End of Scope*/
          /*SwitchOpcode*/ 22,  TARGET_VAL(OiISD::MAdd),// ->17349
/*17327*/   OPC_CaptureGlueInput,
/*17328*/   OPC_RecordChild0, // #0 = $rs
/*17329*/   OPC_RecordChild1, // #1 = $rt
/*17330*/   OPC_RecordChild2, // #2 = physreg input LO
/*17331*/   OPC_RecordChild3, // #3 = physreg input HI
/*17332*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17334*/   OPC_EmitCopyToReg, 2, Oi::LO,
/*17337*/   OPC_EmitCopyToReg, 3, Oi::HI,
/*17340*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MADD), 0|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (OiMAdd CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt, LO:i32, HI:i32) - Complexity = 3
            // Dst: (MADD:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
          /*SwitchOpcode*/ 22,  TARGET_VAL(OiISD::MAddu),// ->17374
/*17352*/   OPC_CaptureGlueInput,
/*17353*/   OPC_RecordChild0, // #0 = $rs
/*17354*/   OPC_RecordChild1, // #1 = $rt
/*17355*/   OPC_RecordChild2, // #2 = physreg input LO
/*17356*/   OPC_RecordChild3, // #3 = physreg input HI
/*17357*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17359*/   OPC_EmitCopyToReg, 2, Oi::LO,
/*17362*/   OPC_EmitCopyToReg, 3, Oi::HI,
/*17365*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MADDU), 0|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (OiMAddu CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt, LO:i32, HI:i32) - Complexity = 3
            // Dst: (MADDU:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
          /*SwitchOpcode*/ 22,  TARGET_VAL(OiISD::MSub),// ->17399
/*17377*/   OPC_CaptureGlueInput,
/*17378*/   OPC_RecordChild0, // #0 = $rs
/*17379*/   OPC_RecordChild1, // #1 = $rt
/*17380*/   OPC_RecordChild2, // #2 = physreg input LO
/*17381*/   OPC_RecordChild3, // #3 = physreg input HI
/*17382*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17384*/   OPC_EmitCopyToReg, 2, Oi::LO,
/*17387*/   OPC_EmitCopyToReg, 3, Oi::HI,
/*17390*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MSUB), 0|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (OiMSub CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt, LO:i32, HI:i32) - Complexity = 3
            // Dst: (MSUB:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
          /*SwitchOpcode*/ 22,  TARGET_VAL(OiISD::MSubu),// ->17424
/*17402*/   OPC_CaptureGlueInput,
/*17403*/   OPC_RecordChild0, // #0 = $rs
/*17404*/   OPC_RecordChild1, // #1 = $rt
/*17405*/   OPC_RecordChild2, // #2 = physreg input LO
/*17406*/   OPC_RecordChild3, // #3 = physreg input HI
/*17407*/   OPC_CheckPatternPredicate, 9, // (Subtarget.hasStandardEncoding())
/*17409*/   OPC_EmitCopyToReg, 2, Oi::LO,
/*17412*/   OPC_EmitCopyToReg, 3, Oi::HI,
/*17415*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MSUBU), 0|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (OiMSubu CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt, LO:i32, HI:i32) - Complexity = 3
            // Dst: (MSUBU:i32 CPURegsOpnd:i32:$rs, CPURegsOpnd:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MULSAQ_S_W_PH),// ->17442
/*17427*/   OPC_RecordNode,   // #0 = 'OiMULSAQ_S_W_PH' chained node
/*17428*/   OPC_CaptureGlueInput,
/*17429*/   OPC_RecordChild1, // #1 = $rs
/*17430*/   OPC_RecordChild2, // #2 = $rt
/*17431*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17433*/   OPC_EmitMergeInputChains1_0,
/*17434*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MULSAQ_S_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMULSAQ_S_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MULSAQ_S_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MAQ_S_W_PHL),// ->17460
/*17445*/   OPC_RecordNode,   // #0 = 'OiMAQ_S_W_PHL' chained node
/*17446*/   OPC_CaptureGlueInput,
/*17447*/   OPC_RecordChild1, // #1 = $rs
/*17448*/   OPC_RecordChild2, // #2 = $rt
/*17449*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17451*/   OPC_EmitMergeInputChains1_0,
/*17452*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MAQ_S_W_PHL_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMAQ_S_W_PHL CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MAQ_S_W_PHL_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MAQ_S_W_PHR),// ->17478
/*17463*/   OPC_RecordNode,   // #0 = 'OiMAQ_S_W_PHR' chained node
/*17464*/   OPC_CaptureGlueInput,
/*17465*/   OPC_RecordChild1, // #1 = $rs
/*17466*/   OPC_RecordChild2, // #2 = $rt
/*17467*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17469*/   OPC_EmitMergeInputChains1_0,
/*17470*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MAQ_S_W_PHR_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMAQ_S_W_PHR CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MAQ_S_W_PHR_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MAQ_SA_W_PHL),// ->17496
/*17481*/   OPC_RecordNode,   // #0 = 'OiMAQ_SA_W_PHL' chained node
/*17482*/   OPC_CaptureGlueInput,
/*17483*/   OPC_RecordChild1, // #1 = $rs
/*17484*/   OPC_RecordChild2, // #2 = $rt
/*17485*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17487*/   OPC_EmitMergeInputChains1_0,
/*17488*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MAQ_SA_W_PHL_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMAQ_SA_W_PHL CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MAQ_SA_W_PHL_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MAQ_SA_W_PHR),// ->17514
/*17499*/   OPC_RecordNode,   // #0 = 'OiMAQ_SA_W_PHR' chained node
/*17500*/   OPC_CaptureGlueInput,
/*17501*/   OPC_RecordChild1, // #1 = $rs
/*17502*/   OPC_RecordChild2, // #2 = $rt
/*17503*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17505*/   OPC_EmitMergeInputChains1_0,
/*17506*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MAQ_SA_W_PHR_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMAQ_SA_W_PHR CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MAQ_SA_W_PHR_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPAU_H_QBL),// ->17532
/*17517*/   OPC_RecordNode,   // #0 = 'OiDPAU_H_QBL' chained node
/*17518*/   OPC_CaptureGlueInput,
/*17519*/   OPC_RecordChild1, // #1 = $rs
/*17520*/   OPC_RecordChild2, // #2 = $rt
/*17521*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17523*/   OPC_EmitMergeInputChains1_0,
/*17524*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPAU_H_QBL_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPAU_H_QBL CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPAU_H_QBL_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPAU_H_QBR),// ->17550
/*17535*/   OPC_RecordNode,   // #0 = 'OiDPAU_H_QBR' chained node
/*17536*/   OPC_CaptureGlueInput,
/*17537*/   OPC_RecordChild1, // #1 = $rs
/*17538*/   OPC_RecordChild2, // #2 = $rt
/*17539*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17541*/   OPC_EmitMergeInputChains1_0,
/*17542*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPAU_H_QBR_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPAU_H_QBR CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPAU_H_QBR_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPSU_H_QBL),// ->17568
/*17553*/   OPC_RecordNode,   // #0 = 'OiDPSU_H_QBL' chained node
/*17554*/   OPC_CaptureGlueInput,
/*17555*/   OPC_RecordChild1, // #1 = $rs
/*17556*/   OPC_RecordChild2, // #2 = $rt
/*17557*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17559*/   OPC_EmitMergeInputChains1_0,
/*17560*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPSU_H_QBL_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPSU_H_QBL CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPSU_H_QBL_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPSU_H_QBR),// ->17586
/*17571*/   OPC_RecordNode,   // #0 = 'OiDPSU_H_QBR' chained node
/*17572*/   OPC_CaptureGlueInput,
/*17573*/   OPC_RecordChild1, // #1 = $rs
/*17574*/   OPC_RecordChild2, // #2 = $rt
/*17575*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17577*/   OPC_EmitMergeInputChains1_0,
/*17578*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPSU_H_QBR_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPSU_H_QBR CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPSU_H_QBR_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPAQ_S_W_PH),// ->17604
/*17589*/   OPC_RecordNode,   // #0 = 'OiDPAQ_S_W_PH' chained node
/*17590*/   OPC_CaptureGlueInput,
/*17591*/   OPC_RecordChild1, // #1 = $rs
/*17592*/   OPC_RecordChild2, // #2 = $rt
/*17593*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17595*/   OPC_EmitMergeInputChains1_0,
/*17596*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPAQ_S_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPAQ_S_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPAQ_S_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPSQ_S_W_PH),// ->17622
/*17607*/   OPC_RecordNode,   // #0 = 'OiDPSQ_S_W_PH' chained node
/*17608*/   OPC_CaptureGlueInput,
/*17609*/   OPC_RecordChild1, // #1 = $rs
/*17610*/   OPC_RecordChild2, // #2 = $rt
/*17611*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17613*/   OPC_EmitMergeInputChains1_0,
/*17614*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPSQ_S_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPSQ_S_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPSQ_S_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPAQ_SA_L_W),// ->17640
/*17625*/   OPC_RecordNode,   // #0 = 'OiDPAQ_SA_L_W' chained node
/*17626*/   OPC_CaptureGlueInput,
/*17627*/   OPC_RecordChild1, // #1 = $rs
/*17628*/   OPC_RecordChild2, // #2 = $rt
/*17629*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17631*/   OPC_EmitMergeInputChains1_0,
/*17632*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPAQ_SA_L_W_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPAQ_SA_L_W CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPAQ_SA_L_W_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPSQ_SA_L_W),// ->17658
/*17643*/   OPC_RecordNode,   // #0 = 'OiDPSQ_SA_L_W' chained node
/*17644*/   OPC_CaptureGlueInput,
/*17645*/   OPC_RecordChild1, // #1 = $rs
/*17646*/   OPC_RecordChild2, // #2 = $rt
/*17647*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17649*/   OPC_EmitMergeInputChains1_0,
/*17650*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPSQ_SA_L_W_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPSQ_SA_L_W CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPSQ_SA_L_W_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MULT),// ->17676
/*17661*/   OPC_RecordNode,   // #0 = 'OiMULT' chained node
/*17662*/   OPC_CaptureGlueInput,
/*17663*/   OPC_RecordChild1, // #1 = $rs
/*17664*/   OPC_RecordChild2, // #2 = $rt
/*17665*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17667*/   OPC_EmitMergeInputChains1_0,
/*17668*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MULT_DSP_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMULT CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MULT_DSP_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MULTU),// ->17694
/*17679*/   OPC_RecordNode,   // #0 = 'OiMULTU' chained node
/*17680*/   OPC_CaptureGlueInput,
/*17681*/   OPC_RecordChild1, // #1 = $rs
/*17682*/   OPC_RecordChild2, // #2 = $rt
/*17683*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17685*/   OPC_EmitMergeInputChains1_0,
/*17686*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MULTU_DSP_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMULTU CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MULTU_DSP_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MADD_DSP),// ->17712
/*17697*/   OPC_RecordNode,   // #0 = 'OiMADD_DSP' chained node
/*17698*/   OPC_CaptureGlueInput,
/*17699*/   OPC_RecordChild1, // #1 = $rs
/*17700*/   OPC_RecordChild2, // #2 = $rt
/*17701*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17703*/   OPC_EmitMergeInputChains1_0,
/*17704*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MADD_DSP_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMADD_DSP CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MADD_DSP_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MADDU_DSP),// ->17730
/*17715*/   OPC_RecordNode,   // #0 = 'OiMADDU_DSP' chained node
/*17716*/   OPC_CaptureGlueInput,
/*17717*/   OPC_RecordChild1, // #1 = $rs
/*17718*/   OPC_RecordChild2, // #2 = $rt
/*17719*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17721*/   OPC_EmitMergeInputChains1_0,
/*17722*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MADDU_DSP_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMADDU_DSP CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MADDU_DSP_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MSUB_DSP),// ->17748
/*17733*/   OPC_RecordNode,   // #0 = 'OiMSUB_DSP' chained node
/*17734*/   OPC_CaptureGlueInput,
/*17735*/   OPC_RecordChild1, // #1 = $rs
/*17736*/   OPC_RecordChild2, // #2 = $rt
/*17737*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17739*/   OPC_EmitMergeInputChains1_0,
/*17740*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MSUB_DSP_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMSUB_DSP CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MSUB_DSP_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MSUBU_DSP),// ->17766
/*17751*/   OPC_RecordNode,   // #0 = 'OiMSUBU_DSP' chained node
/*17752*/   OPC_CaptureGlueInput,
/*17753*/   OPC_RecordChild1, // #1 = $rs
/*17754*/   OPC_RecordChild2, // #2 = $rt
/*17755*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17757*/   OPC_EmitMergeInputChains1_0,
/*17758*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MSUBU_DSP_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMSUBU_DSP CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MSUBU_DSP_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 13,  TARGET_VAL(OiISD::MTHLIP),// ->17782
/*17769*/   OPC_RecordNode,   // #0 = 'OiMTHLIP' chained node
/*17770*/   OPC_CaptureGlueInput,
/*17771*/   OPC_RecordChild1, // #1 = $rs
/*17772*/   OPC_CheckPatternPredicate, 8, // (Subtarget.hasDSP())
/*17774*/   OPC_EmitMergeInputChains1_0,
/*17775*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MTHLIP_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (OiMTHLIP CPURegs:i32:$rs) - Complexity = 3
            // Dst: (MTHLIP_PSEUDO CPURegs:i32:$rs)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPA_W_PH),// ->17800
/*17785*/   OPC_RecordNode,   // #0 = 'OiDPA_W_PH' chained node
/*17786*/   OPC_CaptureGlueInput,
/*17787*/   OPC_RecordChild1, // #1 = $rs
/*17788*/   OPC_RecordChild2, // #2 = $rt
/*17789*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17791*/   OPC_EmitMergeInputChains1_0,
/*17792*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPA_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPA_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPA_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPS_W_PH),// ->17818
/*17803*/   OPC_RecordNode,   // #0 = 'OiDPS_W_PH' chained node
/*17804*/   OPC_CaptureGlueInput,
/*17805*/   OPC_RecordChild1, // #1 = $rs
/*17806*/   OPC_RecordChild2, // #2 = $rt
/*17807*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17809*/   OPC_EmitMergeInputChains1_0,
/*17810*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPS_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPS_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPS_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPAQX_S_W_PH),// ->17836
/*17821*/   OPC_RecordNode,   // #0 = 'OiDPAQX_S_W_PH' chained node
/*17822*/   OPC_CaptureGlueInput,
/*17823*/   OPC_RecordChild1, // #1 = $rs
/*17824*/   OPC_RecordChild2, // #2 = $rt
/*17825*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17827*/   OPC_EmitMergeInputChains1_0,
/*17828*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPAQX_S_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPAQX_S_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPAQX_S_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPAQX_SA_W_PH),// ->17854
/*17839*/   OPC_RecordNode,   // #0 = 'OiDPAQX_SA_W_PH' chained node
/*17840*/   OPC_CaptureGlueInput,
/*17841*/   OPC_RecordChild1, // #1 = $rs
/*17842*/   OPC_RecordChild2, // #2 = $rt
/*17843*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17845*/   OPC_EmitMergeInputChains1_0,
/*17846*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPAQX_SA_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPAQX_SA_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPAQX_SA_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPAX_W_PH),// ->17872
/*17857*/   OPC_RecordNode,   // #0 = 'OiDPAX_W_PH' chained node
/*17858*/   OPC_CaptureGlueInput,
/*17859*/   OPC_RecordChild1, // #1 = $rs
/*17860*/   OPC_RecordChild2, // #2 = $rt
/*17861*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17863*/   OPC_EmitMergeInputChains1_0,
/*17864*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPAX_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPAX_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPAX_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPSX_W_PH),// ->17890
/*17875*/   OPC_RecordNode,   // #0 = 'OiDPSX_W_PH' chained node
/*17876*/   OPC_CaptureGlueInput,
/*17877*/   OPC_RecordChild1, // #1 = $rs
/*17878*/   OPC_RecordChild2, // #2 = $rt
/*17879*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17881*/   OPC_EmitMergeInputChains1_0,
/*17882*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPSX_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPSX_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPSX_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPSQX_S_W_PH),// ->17908
/*17893*/   OPC_RecordNode,   // #0 = 'OiDPSQX_S_W_PH' chained node
/*17894*/   OPC_CaptureGlueInput,
/*17895*/   OPC_RecordChild1, // #1 = $rs
/*17896*/   OPC_RecordChild2, // #2 = $rt
/*17897*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17899*/   OPC_EmitMergeInputChains1_0,
/*17900*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPSQX_S_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPSQX_S_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPSQX_S_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::DPSQX_SA_W_PH),// ->17926
/*17911*/   OPC_RecordNode,   // #0 = 'OiDPSQX_SA_W_PH' chained node
/*17912*/   OPC_CaptureGlueInput,
/*17913*/   OPC_RecordChild1, // #1 = $rs
/*17914*/   OPC_RecordChild2, // #2 = $rt
/*17915*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17917*/   OPC_EmitMergeInputChains1_0,
/*17918*/   OPC_MorphNodeTo, TARGET_VAL(Oi::DPSQX_SA_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiDPSQX_SA_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (DPSQX_SA_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          /*SwitchOpcode*/ 15,  TARGET_VAL(OiISD::MULSA_W_PH),// ->17944
/*17929*/   OPC_RecordNode,   // #0 = 'OiMULSA_W_PH' chained node
/*17930*/   OPC_CaptureGlueInput,
/*17931*/   OPC_RecordChild1, // #1 = $rs
/*17932*/   OPC_RecordChild2, // #2 = $rt
/*17933*/   OPC_CheckPatternPredicate, 10, // (Subtarget.hasDSPR2())
/*17935*/   OPC_EmitMergeInputChains1_0,
/*17936*/   OPC_MorphNodeTo, TARGET_VAL(Oi::MULSA_W_PH_PSEUDO), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (OiMULSA_W_PH CPURegs:i32:$rs, CPURegs:i32:$rt) - Complexity = 3
            // Dst: (MULSA_W_PH_PSEUDO CPURegs:i32:$rs, CPURegs:i32:$rt)
          0, // EndSwitchOpcode
    0
  }; // Total Array size is 17946 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 240
  // #OPC_RecordNode                     = 68
  // #OPC_RecordChild                    = 705
  // #OPC_RecordMemRef                   = 18
  // #OPC_CaptureGlueInput               = 47
  // #OPC_MoveChild                      = 175
  // #OPC_MoveParent                     = 620
  // #OPC_CheckSame                      = 0
  // #OPC_CheckPatternPredicate          = 795
  // #OPC_CheckPredicate                 = 223
  // #OPC_CheckOpcode                    = 112
  // #OPC_SwitchOpcode                   = 14
  // #OPC_CheckType                      = 340
  // #OPC_SwitchType                     = 105
  // #OPC_CheckChildType                 = 74
  // #OPC_CheckInteger                   = 114
  // #OPC_CheckCondCode                  = 180
  // #OPC_CheckValueType                 = 3
  // #OPC_CheckComplexPat                = 105
  // #OPC_CheckAndImm                    = 0
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 0
  // #OPC_EmitInteger                    = 28
  // #OPC_EmitStringInteger              = 9
  // #OPC_EmitRegister                   = 54
  // #OPC_EmitConvertToTarget            = 116
  // #OPC_EmitMergeInputChains           = 347
  // #OPC_EmitCopyToReg                  = 8
  // #OPC_EmitNode                       = 143
  // #OPC_EmitNodeXForm                  = 14
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 800

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

virtual bool CheckPatternPredicate(unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: return (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding());
  case 1: return (Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding());
  case 2: return (Subtarget.inOi16Mode());
  case 3: return (Subtarget.hasFPIdx()) && (Subtarget.hasStandardEncoding());
  case 4: return (!Subtarget.isABI_N64()) && (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding());
  case 5: return (!Subtarget.isABI_N64()) && (!Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding());
  case 6: return (Subtarget.hasOi32r2()) && (!Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding());
  case 7: return (Subtarget.hasOi64()) && (!Subtarget.isABI_N64()) && (Subtarget.hasStandardEncoding());
  case 8: return (Subtarget.hasDSP());
  case 9: return (Subtarget.hasStandardEncoding());
  case 10: return (Subtarget.hasDSPR2());
  case 11: return (Subtarget.hasBitCount()) && (Subtarget.hasStandardEncoding());
  case 12: return (Subtarget.hasOi64()) && (Subtarget.hasStandardEncoding());
  case 13: return (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding());
  case 14: return (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding());
  case 15: return (Subtarget.hasOi32r2()) && (Subtarget.hasStandardEncoding());
  case 16: return (Subtarget.hasOi64r2()) && (Subtarget.hasStandardEncoding());
  case 17: return (Subtarget.hasSEInReg()) && (Subtarget.hasStandardEncoding());
  case 18: return (Subtarget.hasOi32r2()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding());
  case 19: return (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding());
  case 20: return (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding());
  case 21: return (Subtarget.hasOi32r2()) && (!Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding());
  case 22: return (Subtarget.hasOi32r2()) && (Subtarget.isFP64bit()) && (Subtarget.hasStandardEncoding());
  case 23: return (TM.Options.NoNaNsFPMath) && (Subtarget.hasStandardEncoding());
  case 24: return (TM.getRelocationModel() == Reloc::Static) && (Subtarget.hasStandardEncoding());
  case 25: return (TM.getRelocationModel() == Reloc::PIC_) && (Subtarget.hasStandardEncoding());
  case 26: return (TM.getRelocationModel() == Reloc::PIC_) && (Subtarget.inOi16Mode());
  }
}

virtual bool CheckNodePredicate(SDNode *Node,
                                unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 1: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 2: { // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 3: { // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 4: { // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 5: { // Predicate_truncstorei32
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 6: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 7: { // Predicate_sextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::SEXTLOAD;

  }
  case 8: { // Predicate_sextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 9: { // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 10: { // Predicate_zextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 11: { // Predicate_sextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 12: { // Predicate_zextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 13: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 14: { // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 15: { // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 16: { // Predicate_extloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 17: { // Predicate_extloadi1
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i1;

  }
  case 18: { // Predicate_sextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 19: { // Predicate_zextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 20: { // Predicate_extloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 21: { // Predicate_immZExt5
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return Imm == (Imm & 0x1f);
  }
  case 22: { // Predicate_immZExt10
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return isUInt<10>(Imm);
  }
  case 23: { // Predicate_immZExt3
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return isUInt<3>(Imm);
  }
  case 24: { // Predicate_immZExt4
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return isUInt<4>(Imm);
  }
  case 25: { // Predicate_immZExt2
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return isUInt<2>(Imm);
  }
  case 26: { // Predicate_immZExt8
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return isUInt<8>(Imm);
  }
  case 27: { // Predicate_immZExt16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  if (N->getValueType(0) == MVT::i32)
    return (uint32_t)N->getZExtValue() == (unsigned short)N->getZExtValue();
  else
    return (uint64_t)N->getZExtValue() == (unsigned short)N->getZExtValue();

  }
  case 28: { // Predicate_immSExt16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
 return isInt<16>(N->getSExtValue()); 
  }
  case 29: { // Predicate_immZExt6
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return Imm == (Imm & 0x3f);
  }
  case 30: { // Predicate_immLow16Zero
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  int64_t Val = N->getSExtValue();
  return isInt<32>(Val) && !(Val & 0xffff);

  }
  case 31: { // Predicate_atomic_load_add_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 32: { // Predicate_atomic_load_add_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 33: { // Predicate_atomic_load_add_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 34: { // Predicate_atomic_load_add_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 35: { // Predicate_atomic_load_sub_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 36: { // Predicate_atomic_load_sub_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 37: { // Predicate_atomic_load_sub_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 38: { // Predicate_atomic_load_sub_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 39: { // Predicate_atomic_load_and_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 40: { // Predicate_atomic_load_and_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 41: { // Predicate_atomic_load_and_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 42: { // Predicate_atomic_load_and_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 43: { // Predicate_atomic_load_or_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 44: { // Predicate_atomic_load_or_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 45: { // Predicate_atomic_load_or_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 46: { // Predicate_atomic_load_or_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 47: { // Predicate_atomic_load_xor_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 48: { // Predicate_atomic_load_xor_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 49: { // Predicate_atomic_load_xor_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 50: { // Predicate_atomic_load_xor_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 51: { // Predicate_atomic_load_nand_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 52: { // Predicate_atomic_load_nand_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 53: { // Predicate_atomic_load_nand_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 54: { // Predicate_atomic_load_nand_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 55: { // Predicate_atomic_swap_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 56: { // Predicate_atomic_swap_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 57: { // Predicate_atomic_swap_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 58: { // Predicate_atomic_swap_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 59: { // Predicate_atomic_cmp_swap_8
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 60: { // Predicate_atomic_cmp_swap_16
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 61: { // Predicate_atomic_cmp_swap_32
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 62: { // Predicate_atomic_cmp_swap_64
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;

  }
  case 63: { // Predicate_fpimm0
    ConstantFPSDNode*N = cast<ConstantFPSDNode>(Node);

  return N->isExactlyValue(+0.0);

  }
  case 64: { // Predicate_fpimm0neg
    ConstantFPSDNode*N = cast<ConstantFPSDNode>(Node);

  return N->isExactlyValue(-0.0);

  }
  case 65: { // Predicate_immSExt6
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return isInt<6>(Imm);
  }
  }
}

virtual bool CheckComplexPattern(SDNode *Root, SDNode *Parent,
                                 SDValue N, unsigned PatternNo,
         SmallVectorImpl<std::pair<SDValue, SDNode*> > &Result) {
  unsigned NextRes = Result.size();
  switch (PatternNo) {
  default: llvm_unreachable("Invalid pattern # in table?");
  case 0:
    Result.resize(NextRes+2);
    return SelectAddr(Parent, N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 1:
    Result.resize(NextRes+3);
    return SelectAddr16(Parent, N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  }
}

virtual SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) {
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // LO16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return getImm(N, N->getZExtValue() & 0xFFFF);

  }
  case 1: {  // HI16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return getImm(N, (N->getZExtValue() >> 16) & 0xFFFF);

  }
  }
}

