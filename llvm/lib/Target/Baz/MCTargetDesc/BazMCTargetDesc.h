#pragma once


namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createBazMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createBazAsmBackend(const Target &T, const MCSubtargetInfo &STI,
    const MCRegisterInfo &MRI,
    const MCTargetOptions &Options);
} // namespace llvm

#define GET_REGINFO_ENUM
#include "BazGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "BazGenInstrInfo.inc"
