add_llvm_component_library(LLVMBazInfo
  BazTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Baz
  )
