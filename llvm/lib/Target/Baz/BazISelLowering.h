#pragma once

#include "Baz.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class BazSubtarget;
class BazTargetMachine;

namespace BazISD {

enum NodeType : unsigned {
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace BazISD

class BazTargetLowering : public TargetLowering {
public:
    explicit BazTargetLowering(const TargetMachine &TM, const BazSubtarget &STI);

    /// This method returns the name of a target specific DAG node.
    const char *getTargetNodeName(unsigned Opcode) const override;

    BazSubtarget const &getSubtarget() const { return STI; }

private:
    const BazSubtarget &STI;
};

} // end namespace llvm
