#include "MCTargetDesc/BazInfo.h"
#include "Baz.h"
#include "TargetInfo/BazTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "BazGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "BazGenInstrInfo.inc"

static MCRegisterInfo *createBazMCRegisterInfo(const Triple &TT) {
  BAZ_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitBazMCRegisterInfo(X, Baz::R0);
  return X;
}


static MCInstrInfo *createBazMCInstrInfo() {
  BAZ_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitBazMCInstrInfo(X);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeBazTargetMC() {
  BAZ_DUMP_MAGENTA
  Target &TheBazTarget = getTheBazTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheBazTarget, createBazMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(TheBazTarget, createBazMCInstrInfo);
}