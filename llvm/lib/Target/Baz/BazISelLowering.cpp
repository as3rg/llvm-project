#include "BazISelLowering.h"
#include "Baz.h"
#include "BazRegisterInfo.h"
#include "BazSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "Baz-lower"

using namespace llvm;

BazTargetLowering::BazTargetLowering(const TargetMachine &TM,
                                     const BazSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  BAZ_DUMP_RED
  addRegisterClass(MVT::i32, &Baz::GPRRegClass);
}

const char *BazTargetLowering::getTargetNodeName(unsigned Opcode) const {
  BAZ_DUMP_RED
  switch (Opcode) {
  case BazISD::CALL:
    return "BazISD::CALL";
  case BazISD::RET:
    return "BazISD::RET";
  }
  return nullptr;
}