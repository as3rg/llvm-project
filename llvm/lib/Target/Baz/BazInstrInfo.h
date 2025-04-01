#pragma once

#include "BazRegisterInfo.h"
#include "MCTargetDesc/BazInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "BazGenInstrInfo.inc"

namespace llvm {

class BazSubtarget;

class BazInstrInfo : public BazGenInstrInfo {
public:
  BazInstrInfo();

};

} // end namespace llvm
