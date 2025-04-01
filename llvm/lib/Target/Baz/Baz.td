include "llvm/Target/Target.td"
include "BazRegisterInfo.td"
include "BazInstrInfo.td"

def BazInstrInfo : InstrInfo;
def Baz : Target {
  let InstructionSet = BazInstrInfo;
}