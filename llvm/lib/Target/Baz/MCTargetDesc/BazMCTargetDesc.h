#pragma once


namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;

MCCodeEmitter *createBazMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
} // namespace llvm

#define GET_REGINFO_ENUM
#include "BazGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "BazGenInstrInfo.inc"
