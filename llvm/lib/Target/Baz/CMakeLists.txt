add_llvm_component_group(Baz)

set(LLVM_TARGET_DEFINITIONS Baz.td)

tablegen(LLVM BazGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(BazCommonTableGen)

add_llvm_target(BazCodeGen
  BazTargetMachine.cpp
  BazRegisterInfo.cpp


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
