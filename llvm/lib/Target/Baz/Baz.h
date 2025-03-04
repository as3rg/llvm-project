#ifndef LLVM_LIB_TARGET_BAZ_BAZ_H
#define LLVM_LIB_TARGET_BAZ_BAZ_H

#include "llvm/Support/raw_ostream.h"

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

#endif // LLVM_LIB_TARGET_BAZ_BAZ_H