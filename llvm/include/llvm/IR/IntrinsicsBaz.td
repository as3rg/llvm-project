let TargetPrefix = "baz" in {  // All intrinsics start with "llvm.baz.".
 
  def int_baz_putpixel:
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
  def int_baz_flush:
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
} // TargetPrefix = "baz"