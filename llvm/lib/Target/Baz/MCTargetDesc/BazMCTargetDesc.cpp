#include "MCTargetDesc/BazInfo.h"
#include "Baz.h"
#include "BazInstPrinter.h"
#include "BazMCAsmInfo.h"
#include "TargetInfo/BazTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "BazGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "BazGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "BazGenSubtargetInfo.inc"

static MCRegisterInfo *createBazMCRegisterInfo(const Triple &TT) {
  BAZ_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitBazMCRegisterInfo(X, Baz::R0);
  return X;
}

static MCAsmInfo *createBazMCAsmInfo(const MCRegisterInfo &MRI, const Triple &TT, const MCTargetOptions &Options) {
  BAZ_DUMP_MAGENTA
  MCAsmInfo *MAI = new BazELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Baz::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstrInfo *createBazMCInstrInfo() {
  BAZ_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitBazMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createBazMCSubtargetInfo(const Triple &TT,
  StringRef CPU, StringRef FS) {
BAZ_DUMP_MAGENTA
return createBazMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCInstPrinter *createBazMCInstPrinter(const Triple &T,
  unsigned SyntaxVariant,
  const MCAsmInfo &MAI,
  const MCInstrInfo &MII,
  const MCRegisterInfo &MRI) {
  BAZ_DUMP_MAGENTA
  return new BazInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeBazTargetMC() {
  BAZ_DUMP_MAGENTA
  Target &TheBazTarget = getTheBazTarget();
  RegisterMCAsmInfoFn X(TheBazTarget, createBazMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheBazTarget, createBazMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(TheBazTarget, createBazMCInstrInfo);

  TargetRegistry::RegisterMCSubtargetInfo(TheBazTarget, createBazMCSubtargetInfo);

  TargetRegistry::RegisterMCInstPrinter(TheBazTarget, createBazMCInstPrinter);
}