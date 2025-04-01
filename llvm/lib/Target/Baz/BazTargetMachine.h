#pragma once

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheBazTarget;

class BazTargetMachine : public CodeGenTargetMachineImpl {
public:
  BazTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};
} // end namespace llvm
