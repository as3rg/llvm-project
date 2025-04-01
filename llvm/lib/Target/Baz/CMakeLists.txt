add_llvm_component_group(Baz)

set(LLVM_TARGET_DEFINITIONS Baz.td)

tablegen(LLVM BazGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM BazGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM BazGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM BazGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM BazGenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(BazCommonTableGen)

add_llvm_target(BazCodeGen
  BazTargetMachine.cpp
  BazRegisterInfo.cpp
  BazInstrInfo.cpp
  BazSubtarget.cpp
  BazAsmPrinter.cpp
  BazISelDagToDag.cpp


  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  BazInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Baz
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
