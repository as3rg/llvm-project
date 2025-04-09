let TargetPrefix = "baz" in {  // All intrinsics start with "llvm.baz.".
 
  def int_baz_putpixel: ClangBuiltin<"bazPutPixel">,
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
  def int_baz_flush: ClangBuiltin<"bazFlush">,
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
} // TargetPrefix = "baz"