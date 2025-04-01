#include "BazRegisterInfo.h"
#include "Baz.h"
#include "BazFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "BazGenRegisterInfo.inc"

BazRegisterInfo::BazRegisterInfo() : BazGenRegisterInfo(Baz::R0) {
  BAZ_DUMP_GREEN
}