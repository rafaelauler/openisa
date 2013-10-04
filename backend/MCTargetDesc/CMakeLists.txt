add_llvm_library(LLVMOiDesc
  OiAsmBackend.cpp
  OiDirectObjLower.cpp
  OiMCAsmInfo.cpp
  OiMCCodeEmitter.cpp
  OiMCTargetDesc.cpp
  OiELFObjectWriter.cpp
  OiReginfo.cpp
  OiELFStreamer.cpp
  )

add_dependencies(LLVMOiDesc OiCommonTableGen)
