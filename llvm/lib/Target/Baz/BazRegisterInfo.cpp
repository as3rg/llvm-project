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

const MCPhysReg *
BazRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  BAZ_DUMP_GREEN
  return CSR_Baz_SaveList;
}

BitVector BazRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BAZ_DUMP_GREEN
  BazFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Baz::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Baz::R2);
  }
  return Reserved;
}

bool BazRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool BazRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  BAZ_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register BazRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  BAZ_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Baz::R2 : Baz::R1;
}

const uint32_t *
BazRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  BAZ_DUMP_GREEN
  return CSR_Baz_RegMask;
}