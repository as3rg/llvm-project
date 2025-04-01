add_llvm_component_library(LLVMBazDesc
  BazMCTargetDesc.cpp
  BazMCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  BazInfo
  Support

  ADD_TO_COMPONENT
  Baz
  )
