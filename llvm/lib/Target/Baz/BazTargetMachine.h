#pragma once

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "BazSubtarget.h"
#include <optional>

namespace llvm {
extern Target TheBazTarget;

class BazTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  BazSubtarget Subtarget;
public:
  BazTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const BazSubtarget *getSubtargetImpl(const Function &) const override {
    BAZ_DUMP_CYAN
    return &Subtarget;
  }

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm
