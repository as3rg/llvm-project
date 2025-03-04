#include "TargetInfo/BazTargetInfo.h"
#include "Baz.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheBazTarget() {
  BAZ_DUMP_YELLOW
  static Target TheBazTarget;
  return TheBazTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeBazTargetInfo() {
  BAZ_DUMP_YELLOW
  RegisterTarget<Triple::baz> X(getTheBazTarget(), "baz",
                                "Simulator target for LLVM course", "BAZ");
}