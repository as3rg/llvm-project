add_llvm_component_library(LLVMBazDesc
  BazMCTargetDesc.cpp
  BazMCAsmInfo.cpp
  BazInstPrinter.cpp
  BazMCCodeEmitter.cpp
  BazAsmBackend.cpp

  LINK_COMPONENTS
  MC
  BazInfo
  Support

  ADD_TO_COMPONENT
  Baz
  )
