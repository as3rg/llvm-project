#include "BazInstrInfo.h"
#include "Baz.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "BazGenInstrInfo.inc"

#define DEBUG_TYPE "Baz-inst-info"

BazInstrInfo::BazInstrInfo() : BazGenInstrInfo() { BAZ_DUMP_GREEN }