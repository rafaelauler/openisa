include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/.. )

add_llvm_library(LLVMOiInfo
  OiTargetInfo.cpp
  )

add_dependencies(LLVMOiInfo OiCommonTableGen)
