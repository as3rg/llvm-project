#include "BazSubtarget.h"
#include "Baz.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "baz-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "BazGenSubtargetInfo.inc"

BazSubtarget::BazSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : BazGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  BAZ_DUMP_CYAN
}