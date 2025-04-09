#include "Baz.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void BazTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__baz__");
}

ArrayRef<Builtin::Info> BazTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}