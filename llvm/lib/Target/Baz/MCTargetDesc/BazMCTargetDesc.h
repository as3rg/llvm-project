#pragma once

#include <memory>

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
std::unique_ptr<MCObjectTargetWriter> createBazELFObjectWriter(bool Is64Bit, uint8_t OSABI);
} // namespace llvm

#define GET_REGINFO_ENUM
#include "BazGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "BazGenInstrInfo.inc"
