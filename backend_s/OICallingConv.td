//===-- OICallingConv.td - Calling Conventions OI ----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This describes the calling conventions for the OI architectures.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Return Value Calling Conventions
//===----------------------------------------------------------------------===//

// OI 32-bit C return-value convention.
def RetCC_OI32 : CallingConv<[
  CCIfType<[i32], CCAssignToReg<[I0, I1, I2, I3, I4, I5]>>,
  CCIfType<[f32], CCAssignToReg<[F0, F1, F2, F3]>>,
  CCIfType<[f64], CCAssignToReg<[D0, D1]>>
]>;

// OI 32-bit C Calling convention.
def CC_OI32 : CallingConv<[
  //Custom assign SRet to [sp+64].
  CCIfSRet<CCCustom<"CC_OI_Assign_SRet">>,
  // i32 f32 arguments get passed in integer registers if there is space.
  CCIfType<[i32, f32], CCAssignToReg<[I0, I1, I2, I3, I4, I5]>>,
  // f64 arguments are split and passed through registers or through stack.
  CCIfType<[f64], CCCustom<"CC_OI_Assign_f64">>,

  // Alternatively, they are assigned to the stack in 4-byte aligned units.
  CCAssignToStack<4, 4>
]>;
