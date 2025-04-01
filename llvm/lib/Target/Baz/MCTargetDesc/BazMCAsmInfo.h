#pragma once

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class BazELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit BazELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm
