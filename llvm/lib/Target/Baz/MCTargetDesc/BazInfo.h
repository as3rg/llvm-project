#pragma once

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace BazOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace BazOp

} // end namespace llvm
