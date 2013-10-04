set(LLVM_TARGET_DEFINITIONS Oi.td)

tablegen(LLVM OiGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM OiGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM OiGenDisassemblerTables.inc -gen-disassembler)
tablegen(LLVM OiGenCodeEmitter.inc -gen-emitter)
tablegen(LLVM OiGenMCCodeEmitter.inc -gen-emitter -mc-emitter)
tablegen(LLVM OiGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM OiGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM OiGenCallingConv.inc -gen-callingconv)
tablegen(LLVM OiGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM OiGenAsmMatcher.inc -gen-asm-matcher)
tablegen(LLVM OiGenMCPseudoLowering.inc -gen-pseudo-lowering)
add_public_tablegen_target(OiCommonTableGen)

add_llvm_target(OiCodeGen
  Oi16FrameLowering.cpp
  Oi16InstrInfo.cpp
  Oi16ISelDAGToDAG.cpp
  Oi16ISelLowering.cpp
  Oi16RegisterInfo.cpp
  OiAnalyzeImmediate.cpp
  OiAsmPrinter.cpp
  OiCodeEmitter.cpp
  OiConstantIslandPass.cpp
  OiDelaySlotFiller.cpp
  OiJITInfo.cpp
  OiInstrInfo.cpp
  OiISelDAGToDAG.cpp
  OiISelLowering.cpp
  OiFrameLowering.cpp
  OiLongBranch.cpp
  OiMCInstLower.cpp
  OiMachineFunction.cpp
  OiModuleISelDAGToDAG.cpp
  OiOs16.cpp
  OiRegisterInfo.cpp
  OiSEFrameLowering.cpp
  OiSEInstrInfo.cpp
  OiSEISelDAGToDAG.cpp
  OiSEISelLowering.cpp
  OiSERegisterInfo.cpp
  OiSubtarget.cpp
  OiTargetMachine.cpp
  OiTargetObjectFile.cpp
  OiSelectionDAGInfo.cpp
  )

add_dependencies(LLVMOiCodeGen intrinsics_gen)

add_subdirectory(InstPrinter)
add_subdirectory(Disassembler)
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
add_subdirectory(AsmParser)
