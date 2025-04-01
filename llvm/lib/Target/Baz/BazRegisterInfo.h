#pragma once

#define GET_REGINFO_HEADER
#include "BazGenRegisterInfo.inc"

namespace llvm {

struct BazRegisterInfo : public BazGenRegisterInfo {
public:
  BazRegisterInfo();
};

} // end namespace llvm