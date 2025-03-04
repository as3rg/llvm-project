add_llvm_component_group(Baz)

add_llvm_target(BazCodeGen
  BazTargetMachine.cpp


  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  BazInfo

  ADD_TO_COMPONENT
  Baz
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
