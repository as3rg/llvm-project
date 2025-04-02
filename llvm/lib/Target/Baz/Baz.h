#pragma once

#include "MCTargetDesc/BazMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define BAZ_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define BAZ_DUMP(Color) {}

#define BAZ_DUMP_RED BAZ_DUMP(llvm::raw_ostream::RED)
#define BAZ_DUMP_GREEN BAZ_DUMP(llvm::raw_ostream::GREEN)
#define BAZ_DUMP_YELLOW BAZ_DUMP(llvm::raw_ostream::YELLOW)
#define BAZ_DUMP_CYAN BAZ_DUMP(llvm::raw_ostream::CYAN)
#define BAZ_DUMP_MAGENTA BAZ_DUMP(llvm::raw_ostream::MAGENTA)
#define BAZ_DUMP_WHITE BAZ_DUMP(llvm::raw_ostream::WHITE)

namespace llvm {
class BazTargetMachine;
class FunctionPass;
class BazSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerBazMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerBazMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createBazISelDag(BazTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm
  