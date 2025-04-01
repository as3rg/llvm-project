include "llvm/Target/Target.td"
include "BazRegisterInfo.td"
include "BazInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def BazInstrInfo : InstrInfo;
def Baz : Target {
  let InstructionSet = BazInstrInfo;
}