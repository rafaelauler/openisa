/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* * Oi Disassembler                                                          *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include "llvm/MC/MCInst.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/LEB128.h"
#include "llvm/Support/raw_ostream.h"
#include <assert.h>

namespace llvm {

// Helper function for extracting fields from encoded instructions.
template<typename InsnType>
static InsnType fieldFromInstruction(InsnType insn, unsigned startBit,
                                     unsigned numBits) {
    assert(startBit + numBits <= (sizeof(InsnType)*8) &&
           "Instruction field out of bounds!");
    InsnType fieldMask;
    if (numBits == sizeof(InsnType)*8)
      fieldMask = (InsnType)(-1LL);
    else
      fieldMask = (((InsnType)1 << numBits) - 1) << startBit;
    return (insn & fieldMask) >> startBit;
}

static const uint8_t DecoderTableOi32[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 145, 2, // Skip to: 664
/* 7 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10 */      MCD::OPC_FilterValue, 0, 29, 0, // Skip to: 43
/* 14 */      MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 17 */      MCD::OPC_FilterValue, 0, 183, 18, // Skip to: 4812
/* 21 */      MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 35
/* 25 */      MCD::OPC_CheckField, 6, 15, 0, 4, 0, // Skip to: 35
/* 31 */      MCD::OPC_Decode, 243, 3, 0, // Opcode: NOP
/* 35 */      MCD::OPC_CheckPredicate, 0, 165, 18, // Skip to: 4812
/* 39 */      MCD::OPC_Decode, 221, 4, 1, // Opcode: SLL
/* 43 */      MCD::OPC_FilterValue, 1, 39, 0, // Skip to: 86
/* 47 */      MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 50 */      MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 68
/* 54 */      MCD::OPC_CheckPredicate, 0, 146, 18, // Skip to: 4812
/* 58 */      MCD::OPC_CheckField, 6, 5, 0, 140, 18, // Skip to: 4812
/* 64 */      MCD::OPC_Decode, 164, 3, 2, // Opcode: MOVF_I
/* 68 */      MCD::OPC_FilterValue, 1, 132, 18, // Skip to: 4812
/* 72 */      MCD::OPC_CheckPredicate, 0, 128, 18, // Skip to: 4812
/* 76 */      MCD::OPC_CheckField, 6, 5, 0, 122, 18, // Skip to: 4812
/* 82 */      MCD::OPC_Decode, 178, 3, 2, // Opcode: MOVT_I
/* 86 */      MCD::OPC_FilterValue, 2, 27, 0, // Skip to: 117
/* 90 */      MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 93 */      MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 105
/* 97 */      MCD::OPC_CheckPredicate, 0, 103, 18, // Skip to: 4812
/* 101 */     MCD::OPC_Decode, 235, 4, 1, // Opcode: SRL
/* 105 */     MCD::OPC_FilterValue, 1, 95, 18, // Skip to: 4812
/* 109 */     MCD::OPC_CheckPredicate, 1, 91, 18, // Skip to: 4812
/* 113 */     MCD::OPC_Decode, 155, 4, 1, // Opcode: ROTR
/* 117 */     MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 135
/* 121 */     MCD::OPC_CheckPredicate, 0, 79, 18, // Skip to: 4812
/* 125 */     MCD::OPC_CheckField, 21, 5, 0, 73, 18, // Skip to: 4812
/* 131 */     MCD::OPC_Decode, 233, 4, 1, // Opcode: SRA
/* 135 */     MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 153
/* 139 */     MCD::OPC_CheckPredicate, 0, 61, 18, // Skip to: 4812
/* 143 */     MCD::OPC_CheckField, 6, 5, 0, 55, 18, // Skip to: 4812
/* 149 */     MCD::OPC_Decode, 224, 4, 3, // Opcode: SLLV
/* 153 */     MCD::OPC_FilterValue, 6, 27, 0, // Skip to: 184
/* 157 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 160 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 172
/* 164 */     MCD::OPC_CheckPredicate, 0, 36, 18, // Skip to: 4812
/* 168 */     MCD::OPC_Decode, 236, 4, 3, // Opcode: SRLV
/* 172 */     MCD::OPC_FilterValue, 1, 28, 18, // Skip to: 4812
/* 176 */     MCD::OPC_CheckPredicate, 1, 24, 18, // Skip to: 4812
/* 180 */     MCD::OPC_Decode, 156, 4, 3, // Opcode: ROTRV
/* 184 */     MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 202
/* 188 */     MCD::OPC_CheckPredicate, 0, 12, 18, // Skip to: 4812
/* 192 */     MCD::OPC_CheckField, 6, 5, 0, 6, 18, // Skip to: 4812
/* 198 */     MCD::OPC_Decode, 234, 4, 3, // Opcode: SRAV
/* 202 */     MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 220
/* 206 */     MCD::OPC_CheckPredicate, 0, 250, 17, // Skip to: 4812
/* 210 */     MCD::OPC_CheckField, 6, 15, 0, 244, 17, // Skip to: 4812
/* 216 */     MCD::OPC_Decode, 188, 2, 4, // Opcode: JR
/* 220 */     MCD::OPC_FilterValue, 9, 15, 0, // Skip to: 239
/* 224 */     MCD::OPC_CheckPredicate, 0, 232, 17, // Skip to: 4812
/* 228 */     MCD::OPC_CheckField, 6, 15, 224, 7, 225, 17, // Skip to: 4812
/* 235 */     MCD::OPC_Decode, 186, 2, 4, // Opcode: JALR
/* 239 */     MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 257
/* 243 */     MCD::OPC_CheckPredicate, 0, 213, 17, // Skip to: 4812
/* 247 */     MCD::OPC_CheckField, 6, 5, 0, 207, 17, // Skip to: 4812
/* 253 */     MCD::OPC_Decode, 187, 3, 5, // Opcode: MOVZ_I_I
/* 257 */     MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 275
/* 261 */     MCD::OPC_CheckPredicate, 0, 195, 17, // Skip to: 4812
/* 265 */     MCD::OPC_CheckField, 6, 5, 0, 189, 17, // Skip to: 4812
/* 271 */     MCD::OPC_Decode, 173, 3, 5, // Opcode: MOVN_I_I
/* 275 */     MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 287
/* 279 */     MCD::OPC_CheckPredicate, 0, 177, 17, // Skip to: 4812
/* 283 */     MCD::OPC_Decode, 142, 5, 6, // Opcode: SYNC
/* 287 */     MCD::OPC_FilterValue, 16, 20, 0, // Skip to: 311
/* 291 */     MCD::OPC_CheckPredicate, 0, 165, 17, // Skip to: 4812
/* 295 */     MCD::OPC_CheckField, 16, 10, 0, 159, 17, // Skip to: 4812
/* 301 */     MCD::OPC_CheckField, 6, 5, 0, 153, 17, // Skip to: 4812
/* 307 */     MCD::OPC_Decode, 156, 3, 7, // Opcode: MFHI
/* 311 */     MCD::OPC_FilterValue, 17, 14, 0, // Skip to: 329
/* 315 */     MCD::OPC_CheckPredicate, 0, 141, 17, // Skip to: 4812
/* 319 */     MCD::OPC_CheckField, 6, 15, 0, 135, 17, // Skip to: 4812
/* 325 */     MCD::OPC_Decode, 202, 3, 4, // Opcode: MTHI
/* 329 */     MCD::OPC_FilterValue, 18, 20, 0, // Skip to: 353
/* 333 */     MCD::OPC_CheckPredicate, 0, 123, 17, // Skip to: 4812
/* 337 */     MCD::OPC_CheckField, 16, 10, 0, 117, 17, // Skip to: 4812
/* 343 */     MCD::OPC_CheckField, 6, 5, 0, 111, 17, // Skip to: 4812
/* 349 */     MCD::OPC_Decode, 158, 3, 7, // Opcode: MFLO
/* 353 */     MCD::OPC_FilterValue, 19, 14, 0, // Skip to: 371
/* 357 */     MCD::OPC_CheckPredicate, 0, 99, 17, // Skip to: 4812
/* 361 */     MCD::OPC_CheckField, 6, 15, 0, 93, 17, // Skip to: 4812
/* 367 */     MCD::OPC_Decode, 206, 3, 4, // Opcode: MTLO
/* 371 */     MCD::OPC_FilterValue, 24, 36, 0, // Skip to: 411
/* 375 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 378 */     MCD::OPC_FilterValue, 0, 78, 17, // Skip to: 4812
/* 382 */     MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 385 */     MCD::OPC_FilterValue, 0, 71, 17, // Skip to: 4812
/* 389 */     MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 403
/* 393 */     MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 403
/* 399 */     MCD::OPC_Decode, 221, 3, 8, // Opcode: MULT
/* 403 */     MCD::OPC_CheckPredicate, 2, 53, 17, // Skip to: 4812
/* 407 */     MCD::OPC_Decode, 224, 3, 9, // Opcode: MULT_DSP
/* 411 */     MCD::OPC_FilterValue, 25, 36, 0, // Skip to: 451
/* 415 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 418 */     MCD::OPC_FilterValue, 0, 38, 17, // Skip to: 4812
/* 422 */     MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 425 */     MCD::OPC_FilterValue, 0, 31, 17, // Skip to: 4812
/* 429 */     MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 443
/* 433 */     MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 443
/* 439 */     MCD::OPC_Decode, 226, 3, 8, // Opcode: MULTu
/* 443 */     MCD::OPC_CheckPredicate, 2, 13, 17, // Skip to: 4812
/* 447 */     MCD::OPC_Decode, 222, 3, 9, // Opcode: MULTU_DSP
/* 451 */     MCD::OPC_FilterValue, 26, 14, 0, // Skip to: 469
/* 455 */     MCD::OPC_CheckPredicate, 0, 1, 17, // Skip to: 4812
/* 459 */     MCD::OPC_CheckField, 6, 10, 0, 251, 16, // Skip to: 4812
/* 465 */     MCD::OPC_Decode, 178, 4, 8, // Opcode: SDIV
/* 469 */     MCD::OPC_FilterValue, 27, 14, 0, // Skip to: 487
/* 473 */     MCD::OPC_CheckPredicate, 0, 239, 16, // Skip to: 4812
/* 477 */     MCD::OPC_CheckField, 6, 10, 0, 233, 16, // Skip to: 4812
/* 483 */     MCD::OPC_Decode, 184, 5, 8, // Opcode: UDIV
/* 487 */     MCD::OPC_FilterValue, 32, 13, 0, // Skip to: 504
/* 491 */     MCD::OPC_CheckPredicate, 0, 221, 16, // Skip to: 4812
/* 495 */     MCD::OPC_CheckField, 6, 5, 0, 215, 16, // Skip to: 4812
/* 501 */     MCD::OPC_Decode, 20, 3, // Opcode: ADD
/* 504 */     MCD::OPC_FilterValue, 33, 13, 0, // Skip to: 521
/* 508 */     MCD::OPC_CheckPredicate, 0, 204, 16, // Skip to: 4812
/* 512 */     MCD::OPC_CheckField, 6, 5, 0, 198, 16, // Skip to: 4812
/* 518 */     MCD::OPC_Decode, 38, 3, // Opcode: ADDu
/* 521 */     MCD::OPC_FilterValue, 34, 14, 0, // Skip to: 539
/* 525 */     MCD::OPC_CheckPredicate, 0, 187, 16, // Skip to: 4812
/* 529 */     MCD::OPC_CheckField, 6, 5, 0, 181, 16, // Skip to: 4812
/* 535 */     MCD::OPC_Decode, 237, 4, 3, // Opcode: SUB
/* 539 */     MCD::OPC_FilterValue, 35, 14, 0, // Skip to: 557
/* 543 */     MCD::OPC_CheckPredicate, 0, 169, 16, // Skip to: 4812
/* 547 */     MCD::OPC_CheckField, 6, 5, 0, 163, 16, // Skip to: 4812
/* 553 */     MCD::OPC_Decode, 251, 4, 3, // Opcode: SUBu
/* 557 */     MCD::OPC_FilterValue, 36, 13, 0, // Skip to: 574
/* 561 */     MCD::OPC_CheckPredicate, 0, 151, 16, // Skip to: 4812
/* 565 */     MCD::OPC_CheckField, 6, 5, 0, 145, 16, // Skip to: 4812
/* 571 */     MCD::OPC_Decode, 41, 3, // Opcode: AND
/* 574 */     MCD::OPC_FilterValue, 37, 14, 0, // Skip to: 592
/* 578 */     MCD::OPC_CheckPredicate, 0, 134, 16, // Skip to: 4812
/* 582 */     MCD::OPC_CheckField, 6, 5, 0, 128, 16, // Skip to: 4812
/* 588 */     MCD::OPC_Decode, 248, 3, 3, // Opcode: OR
/* 592 */     MCD::OPC_FilterValue, 38, 14, 0, // Skip to: 610
/* 596 */     MCD::OPC_CheckPredicate, 0, 116, 16, // Skip to: 4812
/* 600 */     MCD::OPC_CheckField, 6, 5, 0, 110, 16, // Skip to: 4812
/* 606 */     MCD::OPC_Decode, 187, 5, 3, // Opcode: XOR
/* 610 */     MCD::OPC_FilterValue, 39, 14, 0, // Skip to: 628
/* 614 */     MCD::OPC_CheckPredicate, 0, 98, 16, // Skip to: 4812
/* 618 */     MCD::OPC_CheckField, 6, 5, 0, 92, 16, // Skip to: 4812
/* 624 */     MCD::OPC_Decode, 244, 3, 3, // Opcode: NOR
/* 628 */     MCD::OPC_FilterValue, 42, 14, 0, // Skip to: 646
/* 632 */     MCD::OPC_CheckPredicate, 0, 80, 16, // Skip to: 4812
/* 636 */     MCD::OPC_CheckField, 6, 5, 0, 74, 16, // Skip to: 4812
/* 642 */     MCD::OPC_Decode, 225, 4, 3, // Opcode: SLT
/* 646 */     MCD::OPC_FilterValue, 43, 66, 16, // Skip to: 4812
/* 650 */     MCD::OPC_CheckPredicate, 0, 62, 16, // Skip to: 4812
/* 654 */     MCD::OPC_CheckField, 6, 5, 0, 56, 16, // Skip to: 4812
/* 660 */     MCD::OPC_Decode, 231, 4, 3, // Opcode: SLTu
/* 664 */     MCD::OPC_FilterValue, 1, 80, 0, // Skip to: 748
/* 668 */     MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 671 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 683
/* 675 */     MCD::OPC_CheckPredicate, 0, 37, 16, // Skip to: 4812
/* 679 */     MCD::OPC_Decode, 131, 1, 10, // Opcode: BLTZ
/* 683 */     MCD::OPC_FilterValue, 1, 7, 0, // Skip to: 694
/* 687 */     MCD::OPC_CheckPredicate, 0, 25, 16, // Skip to: 4812
/* 691 */     MCD::OPC_Decode, 123, 10, // Opcode: BGEZ
/* 694 */     MCD::OPC_FilterValue, 16, 8, 0, // Skip to: 706
/* 698 */     MCD::OPC_CheckPredicate, 0, 14, 16, // Skip to: 4812
/* 702 */     MCD::OPC_Decode, 133, 1, 10, // Opcode: BLTZAL
/* 706 */     MCD::OPC_FilterValue, 17, 20, 0, // Skip to: 730
/* 710 */     MCD::OPC_CheckPredicate, 0, 9, 0, // Skip to: 723
/* 714 */     MCD::OPC_CheckField, 21, 5, 0, 3, 0, // Skip to: 723
/* 720 */     MCD::OPC_Decode, 118, 11, // Opcode: BAL_BR
/* 723 */     MCD::OPC_CheckPredicate, 0, 245, 15, // Skip to: 4812
/* 727 */     MCD::OPC_Decode, 125, 10, // Opcode: BGEZAL
/* 730 */     MCD::OPC_FilterValue, 28, 238, 15, // Skip to: 4812
/* 734 */     MCD::OPC_CheckPredicate, 2, 234, 15, // Skip to: 4812
/* 738 */     MCD::OPC_CheckField, 21, 5, 0, 228, 15, // Skip to: 4812
/* 744 */     MCD::OPC_Decode, 136, 1, 11, // Opcode: BPOSGE32
/* 748 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 760
/* 752 */     MCD::OPC_CheckPredicate, 3, 216, 15, // Skip to: 4812
/* 756 */     MCD::OPC_Decode, 184, 2, 12, // Opcode: J
/* 760 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 772
/* 764 */     MCD::OPC_CheckPredicate, 0, 204, 15, // Skip to: 4812
/* 768 */     MCD::OPC_Decode, 185, 2, 12, // Opcode: JAL
/* 772 */     MCD::OPC_FilterValue, 4, 20, 0, // Skip to: 796
/* 776 */     MCD::OPC_CheckPredicate, 3, 9, 0, // Skip to: 789
/* 780 */     MCD::OPC_CheckField, 16, 10, 0, 3, 0, // Skip to: 789
/* 786 */     MCD::OPC_Decode, 116, 11, // Opcode: B
/* 789 */     MCD::OPC_CheckPredicate, 0, 179, 15, // Skip to: 4812
/* 793 */     MCD::OPC_Decode, 121, 13, // Opcode: BEQ
/* 796 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 808
/* 800 */     MCD::OPC_CheckPredicate, 0, 168, 15, // Skip to: 4812
/* 804 */     MCD::OPC_Decode, 134, 1, 13, // Opcode: BNE
/* 808 */     MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 826
/* 812 */     MCD::OPC_CheckPredicate, 0, 156, 15, // Skip to: 4812
/* 816 */     MCD::OPC_CheckField, 16, 5, 0, 150, 15, // Skip to: 4812
/* 822 */     MCD::OPC_Decode, 129, 1, 10, // Opcode: BLEZ
/* 826 */     MCD::OPC_FilterValue, 7, 13, 0, // Skip to: 843
/* 830 */     MCD::OPC_CheckPredicate, 0, 138, 15, // Skip to: 4812
/* 834 */     MCD::OPC_CheckField, 16, 5, 0, 132, 15, // Skip to: 4812
/* 840 */     MCD::OPC_Decode, 126, 10, // Opcode: BGTZ
/* 843 */     MCD::OPC_FilterValue, 8, 7, 0, // Skip to: 854
/* 847 */     MCD::OPC_CheckPredicate, 0, 121, 15, // Skip to: 4812
/* 851 */     MCD::OPC_Decode, 36, 14, // Opcode: ADDi
/* 854 */     MCD::OPC_FilterValue, 9, 7, 0, // Skip to: 865
/* 858 */     MCD::OPC_CheckPredicate, 0, 110, 15, // Skip to: 4812
/* 862 */     MCD::OPC_Decode, 37, 14, // Opcode: ADDiu
/* 865 */     MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 877
/* 869 */     MCD::OPC_CheckPredicate, 0, 99, 15, // Skip to: 4812
/* 873 */     MCD::OPC_Decode, 227, 4, 14, // Opcode: SLTi
/* 877 */     MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 889
/* 881 */     MCD::OPC_CheckPredicate, 0, 87, 15, // Skip to: 4812
/* 885 */     MCD::OPC_Decode, 229, 4, 14, // Opcode: SLTiu
/* 889 */     MCD::OPC_FilterValue, 12, 7, 0, // Skip to: 900
/* 893 */     MCD::OPC_CheckPredicate, 0, 75, 15, // Skip to: 4812
/* 897 */     MCD::OPC_Decode, 43, 15, // Opcode: ANDi
/* 900 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 912
/* 904 */     MCD::OPC_CheckPredicate, 0, 64, 15, // Skip to: 4812
/* 908 */     MCD::OPC_Decode, 250, 3, 15, // Opcode: ORi
/* 912 */     MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 924
/* 916 */     MCD::OPC_CheckPredicate, 0, 52, 15, // Skip to: 4812
/* 920 */     MCD::OPC_Decode, 189, 5, 15, // Opcode: XORi
/* 924 */     MCD::OPC_FilterValue, 15, 14, 0, // Skip to: 942
/* 928 */     MCD::OPC_CheckPredicate, 0, 40, 15, // Skip to: 4812
/* 932 */     MCD::OPC_CheckField, 21, 5, 0, 34, 15, // Skip to: 4812
/* 938 */     MCD::OPC_Decode, 232, 2, 16, // Opcode: LUi
/* 942 */     MCD::OPC_FilterValue, 16, 39, 0, // Skip to: 985
/* 946 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 949 */     MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 967
/* 953 */     MCD::OPC_CheckPredicate, 0, 15, 15, // Skip to: 4812
/* 957 */     MCD::OPC_CheckField, 3, 8, 0, 9, 15, // Skip to: 4812
/* 963 */     MCD::OPC_Decode, 153, 3, 17, // Opcode: MFC0_3OP
/* 967 */     MCD::OPC_FilterValue, 4, 1, 15, // Skip to: 4812
/* 971 */     MCD::OPC_CheckPredicate, 0, 253, 14, // Skip to: 4812
/* 975 */     MCD::OPC_CheckField, 3, 8, 0, 247, 14, // Skip to: 4812
/* 981 */     MCD::OPC_Decode, 199, 3, 18, // Opcode: MTC0_3OP
/* 985 */     MCD::OPC_FilterValue, 17, 109, 3, // Skip to: 1866
/* 989 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 992 */     MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 1010
/* 996 */     MCD::OPC_CheckPredicate, 0, 228, 14, // Skip to: 4812
/* 1000 */    MCD::OPC_CheckField, 0, 11, 0, 222, 14, // Skip to: 4812
/* 1006 */    MCD::OPC_Decode, 154, 3, 19, // Opcode: MFC1
/* 1010 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1028
/* 1014 */    MCD::OPC_CheckPredicate, 0, 210, 14, // Skip to: 4812
/* 1018 */    MCD::OPC_CheckField, 0, 11, 0, 204, 14, // Skip to: 4812
/* 1024 */    MCD::OPC_Decode, 206, 1, 20, // Opcode: DMFC1
/* 1028 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 1046
/* 1032 */    MCD::OPC_CheckPredicate, 0, 192, 14, // Skip to: 4812
/* 1036 */    MCD::OPC_CheckField, 0, 11, 0, 186, 14, // Skip to: 4812
/* 1042 */    MCD::OPC_Decode, 161, 1, 21, // Opcode: CFC1
/* 1046 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 1064
/* 1050 */    MCD::OPC_CheckPredicate, 0, 174, 14, // Skip to: 4812
/* 1054 */    MCD::OPC_CheckField, 0, 11, 0, 168, 14, // Skip to: 4812
/* 1060 */    MCD::OPC_Decode, 200, 3, 22, // Opcode: MTC1
/* 1064 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 1082
/* 1068 */    MCD::OPC_CheckPredicate, 0, 156, 14, // Skip to: 4812
/* 1072 */    MCD::OPC_CheckField, 0, 11, 0, 150, 14, // Skip to: 4812
/* 1078 */    MCD::OPC_Decode, 209, 1, 23, // Opcode: DMTC1
/* 1082 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 1100
/* 1086 */    MCD::OPC_CheckPredicate, 0, 138, 14, // Skip to: 4812
/* 1090 */    MCD::OPC_CheckField, 0, 11, 0, 132, 14, // Skip to: 4812
/* 1096 */    MCD::OPC_Decode, 176, 1, 24, // Opcode: CTC1
/* 1100 */    MCD::OPC_FilterValue, 8, 25, 0, // Skip to: 1129
/* 1104 */    MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 1107 */    MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 1118
/* 1111 */    MCD::OPC_CheckPredicate, 0, 113, 14, // Skip to: 4812
/* 1115 */    MCD::OPC_Decode, 119, 25, // Opcode: BC1F
/* 1118 */    MCD::OPC_FilterValue, 1, 106, 14, // Skip to: 4812
/* 1122 */    MCD::OPC_CheckPredicate, 0, 102, 14, // Skip to: 4812
/* 1126 */    MCD::OPC_Decode, 120, 25, // Opcode: BC1T
/* 1129 */    MCD::OPC_FilterValue, 16, 87, 1, // Skip to: 1476
/* 1133 */    MCD::OPC_ExtractField, 4, 2,  // Inst{5-4} ...
/* 1136 */    MCD::OPC_FilterValue, 0, 195, 0, // Skip to: 1335
/* 1140 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1143 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1155
/* 1147 */    MCD::OPC_CheckPredicate, 0, 77, 14, // Skip to: 4812
/* 1151 */    MCD::OPC_Decode, 155, 2, 26, // Opcode: FADD_S
/* 1155 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1167
/* 1159 */    MCD::OPC_CheckPredicate, 0, 65, 14, // Skip to: 4812
/* 1163 */    MCD::OPC_Decode, 181, 2, 26, // Opcode: FSUB_S
/* 1167 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1179
/* 1171 */    MCD::OPC_CheckPredicate, 0, 53, 14, // Skip to: 4812
/* 1175 */    MCD::OPC_Decode, 172, 2, 26, // Opcode: FMUL_S
/* 1179 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1191
/* 1183 */    MCD::OPC_CheckPredicate, 0, 41, 14, // Skip to: 4812
/* 1187 */    MCD::OPC_Decode, 161, 2, 26, // Opcode: FDIV_S
/* 1191 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 1209
/* 1195 */    MCD::OPC_CheckPredicate, 0, 29, 14, // Skip to: 4812
/* 1199 */    MCD::OPC_CheckField, 16, 5, 0, 23, 14, // Skip to: 4812
/* 1205 */    MCD::OPC_Decode, 178, 2, 27, // Opcode: FSQRT_S
/* 1209 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 1227
/* 1213 */    MCD::OPC_CheckPredicate, 3, 11, 14, // Skip to: 4812
/* 1217 */    MCD::OPC_CheckField, 16, 5, 0, 5, 14, // Skip to: 4812
/* 1223 */    MCD::OPC_Decode, 152, 2, 27, // Opcode: FABS_S
/* 1227 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 1245
/* 1231 */    MCD::OPC_CheckPredicate, 0, 249, 13, // Skip to: 4812
/* 1235 */    MCD::OPC_CheckField, 16, 5, 0, 243, 13, // Skip to: 4812
/* 1241 */    MCD::OPC_Decode, 169, 2, 27, // Opcode: FMOV_S
/* 1245 */    MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 1263
/* 1249 */    MCD::OPC_CheckPredicate, 3, 231, 13, // Skip to: 4812
/* 1253 */    MCD::OPC_CheckField, 16, 5, 0, 225, 13, // Skip to: 4812
/* 1259 */    MCD::OPC_Decode, 175, 2, 27, // Opcode: FNEG_S
/* 1263 */    MCD::OPC_FilterValue, 12, 14, 0, // Skip to: 1281
/* 1267 */    MCD::OPC_CheckPredicate, 0, 213, 13, // Skip to: 4812
/* 1271 */    MCD::OPC_CheckField, 16, 5, 0, 207, 13, // Skip to: 4812
/* 1277 */    MCD::OPC_Decode, 161, 4, 27, // Opcode: ROUND_W_S
/* 1281 */    MCD::OPC_FilterValue, 13, 14, 0, // Skip to: 1299
/* 1285 */    MCD::OPC_CheckPredicate, 0, 195, 13, // Skip to: 4812
/* 1289 */    MCD::OPC_CheckField, 16, 5, 0, 189, 13, // Skip to: 4812
/* 1295 */    MCD::OPC_Decode, 183, 5, 27, // Opcode: TRUNC_W_S
/* 1299 */    MCD::OPC_FilterValue, 14, 14, 0, // Skip to: 1317
/* 1303 */    MCD::OPC_CheckPredicate, 0, 177, 13, // Skip to: 4812
/* 1307 */    MCD::OPC_CheckField, 16, 5, 0, 171, 13, // Skip to: 4812
/* 1313 */    MCD::OPC_Decode, 160, 1, 27, // Opcode: CEIL_W_S
/* 1317 */    MCD::OPC_FilterValue, 15, 163, 13, // Skip to: 4812
/* 1321 */    MCD::OPC_CheckPredicate, 0, 159, 13, // Skip to: 4812
/* 1325 */    MCD::OPC_CheckField, 16, 5, 0, 153, 13, // Skip to: 4812
/* 1331 */    MCD::OPC_Decode, 166, 2, 27, // Opcode: FLOOR_W_S
/* 1335 */    MCD::OPC_FilterValue, 1, 58, 0, // Skip to: 1397
/* 1339 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1342 */    MCD::OPC_FilterValue, 1, 27, 0, // Skip to: 1373
/* 1346 */    MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 1349 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1361
/* 1353 */    MCD::OPC_CheckPredicate, 0, 127, 13, // Skip to: 4812
/* 1357 */    MCD::OPC_Decode, 166, 3, 28, // Opcode: MOVF_S
/* 1361 */    MCD::OPC_FilterValue, 1, 119, 13, // Skip to: 4812
/* 1365 */    MCD::OPC_CheckPredicate, 0, 115, 13, // Skip to: 4812
/* 1369 */    MCD::OPC_Decode, 180, 3, 28, // Opcode: MOVT_S
/* 1373 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1385
/* 1377 */    MCD::OPC_CheckPredicate, 0, 103, 13, // Skip to: 4812
/* 1381 */    MCD::OPC_Decode, 189, 3, 29, // Opcode: MOVZ_I_S
/* 1385 */    MCD::OPC_FilterValue, 3, 95, 13, // Skip to: 4812
/* 1389 */    MCD::OPC_CheckPredicate, 0, 91, 13, // Skip to: 4812
/* 1393 */    MCD::OPC_Decode, 175, 3, 29, // Opcode: MOVN_I_S
/* 1397 */    MCD::OPC_FilterValue, 2, 57, 0, // Skip to: 1458
/* 1401 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1404 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1422
/* 1408 */    MCD::OPC_CheckPredicate, 4, 72, 13, // Skip to: 4812
/* 1412 */    MCD::OPC_CheckField, 16, 5, 0, 66, 13, // Skip to: 4812
/* 1418 */    MCD::OPC_Decode, 177, 1, 30, // Opcode: CVT_D32_S
/* 1422 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 1440
/* 1426 */    MCD::OPC_CheckPredicate, 0, 54, 13, // Skip to: 4812
/* 1430 */    MCD::OPC_CheckField, 16, 5, 0, 48, 13, // Skip to: 4812
/* 1436 */    MCD::OPC_Decode, 190, 1, 27, // Opcode: CVT_W_S
/* 1440 */    MCD::OPC_FilterValue, 5, 40, 13, // Skip to: 4812
/* 1444 */    MCD::OPC_CheckPredicate, 0, 36, 13, // Skip to: 4812
/* 1448 */    MCD::OPC_CheckField, 16, 5, 0, 30, 13, // Skip to: 4812
/* 1454 */    MCD::OPC_Decode, 183, 1, 31, // Opcode: CVT_L_S
/* 1458 */    MCD::OPC_FilterValue, 3, 22, 13, // Skip to: 4812
/* 1462 */    MCD::OPC_CheckPredicate, 0, 18, 13, // Skip to: 4812
/* 1466 */    MCD::OPC_CheckField, 6, 5, 0, 12, 13, // Skip to: 4812
/* 1472 */    MCD::OPC_Decode, 158, 2, 32, // Opcode: FCMP_S32
/* 1476 */    MCD::OPC_FilterValue, 17, 87, 1, // Skip to: 1823
/* 1480 */    MCD::OPC_ExtractField, 4, 2,  // Inst{5-4} ...
/* 1483 */    MCD::OPC_FilterValue, 0, 195, 0, // Skip to: 1682
/* 1487 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1490 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1502
/* 1494 */    MCD::OPC_CheckPredicate, 4, 242, 12, // Skip to: 4812
/* 1498 */    MCD::OPC_Decode, 153, 2, 33, // Opcode: FADD_D32
/* 1502 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1514
/* 1506 */    MCD::OPC_CheckPredicate, 4, 230, 12, // Skip to: 4812
/* 1510 */    MCD::OPC_Decode, 179, 2, 33, // Opcode: FSUB_D32
/* 1514 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1526
/* 1518 */    MCD::OPC_CheckPredicate, 4, 218, 12, // Skip to: 4812
/* 1522 */    MCD::OPC_Decode, 170, 2, 33, // Opcode: FMUL_D32
/* 1526 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1538
/* 1530 */    MCD::OPC_CheckPredicate, 4, 206, 12, // Skip to: 4812
/* 1534 */    MCD::OPC_Decode, 159, 2, 33, // Opcode: FDIV_D32
/* 1538 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 1556
/* 1542 */    MCD::OPC_CheckPredicate, 4, 194, 12, // Skip to: 4812
/* 1546 */    MCD::OPC_CheckField, 16, 5, 0, 188, 12, // Skip to: 4812
/* 1552 */    MCD::OPC_Decode, 176, 2, 34, // Opcode: FSQRT_D32
/* 1556 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 1574
/* 1560 */    MCD::OPC_CheckPredicate, 3, 176, 12, // Skip to: 4812
/* 1564 */    MCD::OPC_CheckField, 16, 5, 0, 170, 12, // Skip to: 4812
/* 1570 */    MCD::OPC_Decode, 150, 2, 34, // Opcode: FABS_D32
/* 1574 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 1592
/* 1578 */    MCD::OPC_CheckPredicate, 4, 158, 12, // Skip to: 4812
/* 1582 */    MCD::OPC_CheckField, 16, 5, 0, 152, 12, // Skip to: 4812
/* 1588 */    MCD::OPC_Decode, 167, 2, 34, // Opcode: FMOV_D32
/* 1592 */    MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 1610
/* 1596 */    MCD::OPC_CheckPredicate, 3, 140, 12, // Skip to: 4812
/* 1600 */    MCD::OPC_CheckField, 16, 5, 0, 134, 12, // Skip to: 4812
/* 1606 */    MCD::OPC_Decode, 173, 2, 34, // Opcode: FNEG_D32
/* 1610 */    MCD::OPC_FilterValue, 12, 14, 0, // Skip to: 1628
/* 1614 */    MCD::OPC_CheckPredicate, 4, 122, 12, // Skip to: 4812
/* 1618 */    MCD::OPC_CheckField, 16, 5, 0, 116, 12, // Skip to: 4812
/* 1624 */    MCD::OPC_Decode, 159, 4, 35, // Opcode: ROUND_W_D32
/* 1628 */    MCD::OPC_FilterValue, 13, 14, 0, // Skip to: 1646
/* 1632 */    MCD::OPC_CheckPredicate, 4, 104, 12, // Skip to: 4812
/* 1636 */    MCD::OPC_CheckField, 16, 5, 0, 98, 12, // Skip to: 4812
/* 1642 */    MCD::OPC_Decode, 181, 5, 35, // Opcode: TRUNC_W_D32
/* 1646 */    MCD::OPC_FilterValue, 14, 14, 0, // Skip to: 1664
/* 1650 */    MCD::OPC_CheckPredicate, 4, 86, 12, // Skip to: 4812
/* 1654 */    MCD::OPC_CheckField, 16, 5, 0, 80, 12, // Skip to: 4812
/* 1660 */    MCD::OPC_Decode, 158, 1, 35, // Opcode: CEIL_W_D32
/* 1664 */    MCD::OPC_FilterValue, 15, 72, 12, // Skip to: 4812
/* 1668 */    MCD::OPC_CheckPredicate, 4, 68, 12, // Skip to: 4812
/* 1672 */    MCD::OPC_CheckField, 16, 5, 0, 62, 12, // Skip to: 4812
/* 1678 */    MCD::OPC_Decode, 164, 2, 35, // Opcode: FLOOR_W_D32
/* 1682 */    MCD::OPC_FilterValue, 1, 58, 0, // Skip to: 1744
/* 1686 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1689 */    MCD::OPC_FilterValue, 1, 27, 0, // Skip to: 1720
/* 1693 */    MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 1696 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1708
/* 1700 */    MCD::OPC_CheckPredicate, 4, 36, 12, // Skip to: 4812
/* 1704 */    MCD::OPC_Decode, 162, 3, 36, // Opcode: MOVF_D32
/* 1708 */    MCD::OPC_FilterValue, 1, 28, 12, // Skip to: 4812
/* 1712 */    MCD::OPC_CheckPredicate, 4, 24, 12, // Skip to: 4812
/* 1716 */    MCD::OPC_Decode, 176, 3, 36, // Opcode: MOVT_D32
/* 1720 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1732
/* 1724 */    MCD::OPC_CheckPredicate, 4, 12, 12, // Skip to: 4812
/* 1728 */    MCD::OPC_Decode, 185, 3, 37, // Opcode: MOVZ_I_D32
/* 1732 */    MCD::OPC_FilterValue, 3, 4, 12, // Skip to: 4812
/* 1736 */    MCD::OPC_CheckPredicate, 4, 0, 12, // Skip to: 4812
/* 1740 */    MCD::OPC_Decode, 171, 3, 37, // Opcode: MOVN_I_D32
/* 1744 */    MCD::OPC_FilterValue, 2, 57, 0, // Skip to: 1805
/* 1748 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1751 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 1769
/* 1755 */    MCD::OPC_CheckPredicate, 4, 237, 11, // Skip to: 4812
/* 1759 */    MCD::OPC_CheckField, 16, 5, 0, 231, 11, // Skip to: 4812
/* 1765 */    MCD::OPC_Decode, 184, 1, 35, // Opcode: CVT_S_D32
/* 1769 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 1787
/* 1773 */    MCD::OPC_CheckPredicate, 4, 219, 11, // Skip to: 4812
/* 1777 */    MCD::OPC_CheckField, 16, 5, 0, 213, 11, // Skip to: 4812
/* 1783 */    MCD::OPC_Decode, 188, 1, 35, // Opcode: CVT_W_D32
/* 1787 */    MCD::OPC_FilterValue, 5, 205, 11, // Skip to: 4812
/* 1791 */    MCD::OPC_CheckPredicate, 0, 201, 11, // Skip to: 4812
/* 1795 */    MCD::OPC_CheckField, 16, 5, 0, 195, 11, // Skip to: 4812
/* 1801 */    MCD::OPC_Decode, 182, 1, 38, // Opcode: CVT_L_D64
/* 1805 */    MCD::OPC_FilterValue, 3, 187, 11, // Skip to: 4812
/* 1809 */    MCD::OPC_CheckPredicate, 4, 183, 11, // Skip to: 4812
/* 1813 */    MCD::OPC_CheckField, 6, 5, 0, 177, 11, // Skip to: 4812
/* 1819 */    MCD::OPC_Decode, 156, 2, 39, // Opcode: FCMP_D32
/* 1823 */    MCD::OPC_FilterValue, 20, 169, 11, // Skip to: 4812
/* 1827 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1830 */    MCD::OPC_FilterValue, 32, 14, 0, // Skip to: 1848
/* 1834 */    MCD::OPC_CheckPredicate, 0, 158, 11, // Skip to: 4812
/* 1838 */    MCD::OPC_CheckField, 16, 5, 0, 152, 11, // Skip to: 4812
/* 1844 */    MCD::OPC_Decode, 187, 1, 27, // Opcode: CVT_S_W
/* 1848 */    MCD::OPC_FilterValue, 33, 144, 11, // Skip to: 4812
/* 1852 */    MCD::OPC_CheckPredicate, 4, 140, 11, // Skip to: 4812
/* 1856 */    MCD::OPC_CheckField, 16, 5, 0, 134, 11, // Skip to: 4812
/* 1862 */    MCD::OPC_Decode, 178, 1, 30, // Opcode: CVT_D32_W
/* 1866 */    MCD::OPC_FilterValue, 18, 39, 0, // Skip to: 1909
/* 1870 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1873 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 1891
/* 1877 */    MCD::OPC_CheckPredicate, 0, 115, 11, // Skip to: 4812
/* 1881 */    MCD::OPC_CheckField, 3, 8, 0, 109, 11, // Skip to: 4812
/* 1887 */    MCD::OPC_Decode, 155, 3, 17, // Opcode: MFC2_3OP
/* 1891 */    MCD::OPC_FilterValue, 4, 101, 11, // Skip to: 4812
/* 1895 */    MCD::OPC_CheckPredicate, 0, 97, 11, // Skip to: 4812
/* 1899 */    MCD::OPC_CheckField, 3, 8, 0, 91, 11, // Skip to: 4812
/* 1905 */    MCD::OPC_Decode, 201, 3, 18, // Opcode: MTC2_3OP
/* 1909 */    MCD::OPC_FilterValue, 19, 207, 0, // Skip to: 2120
/* 1913 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1916 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 1934
/* 1920 */    MCD::OPC_CheckPredicate, 5, 72, 11, // Skip to: 4812
/* 1924 */    MCD::OPC_CheckField, 11, 5, 0, 66, 11, // Skip to: 4812
/* 1930 */    MCD::OPC_Decode, 248, 2, 40, // Opcode: LWXC1
/* 1934 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1952
/* 1938 */    MCD::OPC_CheckPredicate, 6, 54, 11, // Skip to: 4812
/* 1942 */    MCD::OPC_CheckField, 11, 5, 0, 48, 11, // Skip to: 4812
/* 1948 */    MCD::OPC_Decode, 211, 2, 41, // Opcode: LDXC1
/* 1952 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 1970
/* 1956 */    MCD::OPC_CheckPredicate, 7, 36, 11, // Skip to: 4812
/* 1960 */    MCD::OPC_CheckField, 11, 5, 0, 30, 11, // Skip to: 4812
/* 1966 */    MCD::OPC_Decode, 230, 2, 41, // Opcode: LUXC1
/* 1970 */    MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 1988
/* 1974 */    MCD::OPC_CheckPredicate, 5, 18, 11, // Skip to: 4812
/* 1978 */    MCD::OPC_CheckField, 6, 5, 0, 12, 11, // Skip to: 4812
/* 1984 */    MCD::OPC_Decode, 139, 5, 42, // Opcode: SWXC1
/* 1988 */    MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 2006
/* 1992 */    MCD::OPC_CheckPredicate, 6, 0, 11, // Skip to: 4812
/* 1996 */    MCD::OPC_CheckField, 6, 5, 0, 250, 10, // Skip to: 4812
/* 2002 */    MCD::OPC_Decode, 183, 4, 43, // Opcode: SDXC1
/* 2006 */    MCD::OPC_FilterValue, 13, 14, 0, // Skip to: 2024
/* 2010 */    MCD::OPC_CheckPredicate, 7, 238, 10, // Skip to: 4812
/* 2014 */    MCD::OPC_CheckField, 6, 5, 0, 232, 10, // Skip to: 4812
/* 2020 */    MCD::OPC_Decode, 252, 4, 43, // Opcode: SUXC1
/* 2024 */    MCD::OPC_FilterValue, 32, 8, 0, // Skip to: 2036
/* 2028 */    MCD::OPC_CheckPredicate, 1, 220, 10, // Skip to: 4812
/* 2032 */    MCD::OPC_Decode, 144, 3, 44, // Opcode: MADD_S
/* 2036 */    MCD::OPC_FilterValue, 33, 8, 0, // Skip to: 2048
/* 2040 */    MCD::OPC_CheckPredicate, 8, 208, 10, // Skip to: 4812
/* 2044 */    MCD::OPC_Decode, 140, 3, 45, // Opcode: MADD_D32
/* 2048 */    MCD::OPC_FilterValue, 40, 8, 0, // Skip to: 2060
/* 2052 */    MCD::OPC_CheckPredicate, 1, 196, 10, // Skip to: 4812
/* 2056 */    MCD::OPC_Decode, 198, 3, 44, // Opcode: MSUB_S
/* 2060 */    MCD::OPC_FilterValue, 41, 8, 0, // Skip to: 2072
/* 2064 */    MCD::OPC_CheckPredicate, 8, 184, 10, // Skip to: 4812
/* 2068 */    MCD::OPC_Decode, 194, 3, 45, // Opcode: MSUB_D32
/* 2072 */    MCD::OPC_FilterValue, 48, 8, 0, // Skip to: 2084
/* 2076 */    MCD::OPC_CheckPredicate, 9, 172, 10, // Skip to: 4812
/* 2080 */    MCD::OPC_Decode, 239, 3, 44, // Opcode: NMADD_S
/* 2084 */    MCD::OPC_FilterValue, 49, 8, 0, // Skip to: 2096
/* 2088 */    MCD::OPC_CheckPredicate, 10, 160, 10, // Skip to: 4812
/* 2092 */    MCD::OPC_Decode, 237, 3, 45, // Opcode: NMADD_D32
/* 2096 */    MCD::OPC_FilterValue, 56, 8, 0, // Skip to: 2108
/* 2100 */    MCD::OPC_CheckPredicate, 9, 148, 10, // Skip to: 4812
/* 2104 */    MCD::OPC_Decode, 242, 3, 44, // Opcode: NMSUB_S
/* 2108 */    MCD::OPC_FilterValue, 57, 140, 10, // Skip to: 4812
/* 2112 */    MCD::OPC_CheckPredicate, 10, 136, 10, // Skip to: 4812
/* 2116 */    MCD::OPC_Decode, 240, 3, 45, // Opcode: NMSUB_D32
/* 2120 */    MCD::OPC_FilterValue, 28, 171, 0, // Skip to: 2295
/* 2124 */    MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 2127 */    MCD::OPC_FilterValue, 0, 29, 0, // Skip to: 2160
/* 2131 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2134 */    MCD::OPC_FilterValue, 0, 114, 10, // Skip to: 4812
/* 2138 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 2152
/* 2142 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2152
/* 2148 */    MCD::OPC_Decode, 136, 3, 8, // Opcode: MADD
/* 2152 */    MCD::OPC_CheckPredicate, 2, 96, 10, // Skip to: 4812
/* 2156 */    MCD::OPC_Decode, 142, 3, 9, // Opcode: MADD_DSP
/* 2160 */    MCD::OPC_FilterValue, 1, 29, 0, // Skip to: 2193
/* 2164 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2167 */    MCD::OPC_FilterValue, 0, 81, 10, // Skip to: 4812
/* 2171 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 2185
/* 2175 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2185
/* 2181 */    MCD::OPC_Decode, 137, 3, 8, // Opcode: MADDU
/* 2185 */    MCD::OPC_CheckPredicate, 2, 63, 10, // Skip to: 4812
/* 2189 */    MCD::OPC_Decode, 138, 3, 9, // Opcode: MADDU_DSP
/* 2193 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2205
/* 2197 */    MCD::OPC_CheckPredicate, 0, 51, 10, // Skip to: 4812
/* 2201 */    MCD::OPC_Decode, 208, 3, 3, // Opcode: MUL
/* 2205 */    MCD::OPC_FilterValue, 4, 29, 0, // Skip to: 2238
/* 2209 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2212 */    MCD::OPC_FilterValue, 0, 36, 10, // Skip to: 4812
/* 2216 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 2230
/* 2220 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2230
/* 2226 */    MCD::OPC_Decode, 190, 3, 8, // Opcode: MSUB
/* 2230 */    MCD::OPC_CheckPredicate, 2, 18, 10, // Skip to: 4812
/* 2234 */    MCD::OPC_Decode, 196, 3, 9, // Opcode: MSUB_DSP
/* 2238 */    MCD::OPC_FilterValue, 5, 29, 0, // Skip to: 2271
/* 2242 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2245 */    MCD::OPC_FilterValue, 0, 3, 10, // Skip to: 4812
/* 2249 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 2263
/* 2253 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2263
/* 2259 */    MCD::OPC_Decode, 191, 3, 8, // Opcode: MSUBU
/* 2263 */    MCD::OPC_CheckPredicate, 2, 241, 9, // Skip to: 4812
/* 2267 */    MCD::OPC_Decode, 192, 3, 9, // Opcode: MSUBU_DSP
/* 2271 */    MCD::OPC_FilterValue, 32, 8, 0, // Skip to: 2283
/* 2275 */    MCD::OPC_CheckPredicate, 11, 229, 9, // Skip to: 4812
/* 2279 */    MCD::OPC_Decode, 163, 1, 46, // Opcode: CLZ
/* 2283 */    MCD::OPC_FilterValue, 33, 221, 9, // Skip to: 4812
/* 2287 */    MCD::OPC_CheckPredicate, 11, 217, 9, // Skip to: 4812
/* 2291 */    MCD::OPC_Decode, 162, 1, 46, // Opcode: CLO
/* 2295 */    MCD::OPC_FilterValue, 31, 249, 8, // Skip to: 4596
/* 2299 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 2302 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2314
/* 2306 */    MCD::OPC_CheckPredicate, 1, 198, 9, // Skip to: 4812
/* 2310 */    MCD::OPC_Decode, 136, 2, 47, // Opcode: EXT
/* 2314 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2326
/* 2318 */    MCD::OPC_CheckPredicate, 1, 186, 9, // Skip to: 4812
/* 2322 */    MCD::OPC_Decode, 182, 2, 48, // Opcode: INS
/* 2326 */    MCD::OPC_FilterValue, 10, 39, 0, // Skip to: 2369
/* 2330 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 2333 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2345
/* 2337 */    MCD::OPC_CheckPredicate, 2, 167, 9, // Skip to: 4812
/* 2341 */    MCD::OPC_Decode, 247, 2, 3, // Opcode: LWX
/* 2345 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2357
/* 2349 */    MCD::OPC_CheckPredicate, 2, 155, 9, // Skip to: 4812
/* 2353 */    MCD::OPC_Decode, 220, 2, 3, // Opcode: LHX
/* 2357 */    MCD::OPC_FilterValue, 6, 147, 9, // Skip to: 4812
/* 2361 */    MCD::OPC_CheckPredicate, 2, 143, 9, // Skip to: 4812
/* 2365 */    MCD::OPC_Decode, 197, 2, 3, // Opcode: LBUX
/* 2369 */    MCD::OPC_FilterValue, 12, 14, 0, // Skip to: 2387
/* 2373 */    MCD::OPC_CheckPredicate, 2, 131, 9, // Skip to: 4812
/* 2377 */    MCD::OPC_CheckField, 6, 10, 0, 125, 9, // Skip to: 4812
/* 2383 */    MCD::OPC_Decode, 183, 2, 49, // Opcode: INSV
/* 2387 */    MCD::OPC_FilterValue, 16, 32, 1, // Skip to: 2679
/* 2391 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 2394 */    MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 2405
/* 2398 */    MCD::OPC_CheckPredicate, 2, 106, 9, // Skip to: 4812
/* 2402 */    MCD::OPC_Decode, 32, 50, // Opcode: ADDU_QB
/* 2405 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2417
/* 2409 */    MCD::OPC_CheckPredicate, 2, 95, 9, // Skip to: 4812
/* 2413 */    MCD::OPC_Decode, 248, 4, 50, // Opcode: SUBU_QB
/* 2417 */    MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 2428
/* 2421 */    MCD::OPC_CheckPredicate, 2, 83, 9, // Skip to: 4812
/* 2425 */    MCD::OPC_Decode, 34, 50, // Opcode: ADDU_S_QB
/* 2428 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2440
/* 2432 */    MCD::OPC_CheckPredicate, 2, 72, 9, // Skip to: 4812
/* 2436 */    MCD::OPC_Decode, 250, 4, 50, // Opcode: SUBU_S_QB
/* 2440 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2452
/* 2444 */    MCD::OPC_CheckPredicate, 2, 60, 9, // Skip to: 4812
/* 2448 */    MCD::OPC_Decode, 211, 3, 50, // Opcode: MULEU_S_PH_QBL
/* 2452 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 2464
/* 2456 */    MCD::OPC_CheckPredicate, 2, 48, 9, // Skip to: 4812
/* 2460 */    MCD::OPC_Decode, 212, 3, 50, // Opcode: MULEU_S_PH_QBR
/* 2464 */    MCD::OPC_FilterValue, 8, 7, 0, // Skip to: 2475
/* 2468 */    MCD::OPC_CheckPredicate, 12, 36, 9, // Skip to: 4812
/* 2472 */    MCD::OPC_Decode, 31, 50, // Opcode: ADDU_PH
/* 2475 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 2487
/* 2479 */    MCD::OPC_CheckPredicate, 12, 25, 9, // Skip to: 4812
/* 2483 */    MCD::OPC_Decode, 247, 4, 50, // Opcode: SUBU_PH
/* 2487 */    MCD::OPC_FilterValue, 10, 7, 0, // Skip to: 2498
/* 2491 */    MCD::OPC_CheckPredicate, 2, 13, 9, // Skip to: 4812
/* 2495 */    MCD::OPC_Decode, 25, 50, // Opcode: ADDQ_PH
/* 2498 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 2510
/* 2502 */    MCD::OPC_CheckPredicate, 2, 2, 9, // Skip to: 4812
/* 2506 */    MCD::OPC_Decode, 242, 4, 50, // Opcode: SUBQ_PH
/* 2510 */    MCD::OPC_FilterValue, 12, 7, 0, // Skip to: 2521
/* 2514 */    MCD::OPC_CheckPredicate, 12, 246, 8, // Skip to: 4812
/* 2518 */    MCD::OPC_Decode, 33, 50, // Opcode: ADDU_S_PH
/* 2521 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2533
/* 2525 */    MCD::OPC_CheckPredicate, 12, 235, 8, // Skip to: 4812
/* 2529 */    MCD::OPC_Decode, 249, 4, 50, // Opcode: SUBU_S_PH
/* 2533 */    MCD::OPC_FilterValue, 14, 7, 0, // Skip to: 2544
/* 2537 */    MCD::OPC_CheckPredicate, 2, 223, 8, // Skip to: 4812
/* 2541 */    MCD::OPC_Decode, 26, 50, // Opcode: ADDQ_S_PH
/* 2544 */    MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 2556
/* 2548 */    MCD::OPC_CheckPredicate, 2, 212, 8, // Skip to: 4812
/* 2552 */    MCD::OPC_Decode, 243, 4, 50, // Opcode: SUBQ_S_PH
/* 2556 */    MCD::OPC_FilterValue, 16, 7, 0, // Skip to: 2567
/* 2560 */    MCD::OPC_CheckPredicate, 2, 200, 8, // Skip to: 4812
/* 2564 */    MCD::OPC_Decode, 28, 3, // Opcode: ADDSC
/* 2567 */    MCD::OPC_FilterValue, 17, 7, 0, // Skip to: 2578
/* 2571 */    MCD::OPC_CheckPredicate, 2, 189, 8, // Skip to: 4812
/* 2575 */    MCD::OPC_Decode, 35, 3, // Opcode: ADDWC
/* 2578 */    MCD::OPC_FilterValue, 18, 8, 0, // Skip to: 2590
/* 2582 */    MCD::OPC_CheckPredicate, 2, 178, 8, // Skip to: 4812
/* 2586 */    MCD::OPC_Decode, 160, 3, 3, // Opcode: MODSUB
/* 2590 */    MCD::OPC_FilterValue, 20, 14, 0, // Skip to: 2608
/* 2594 */    MCD::OPC_CheckPredicate, 2, 166, 8, // Skip to: 4812
/* 2598 */    MCD::OPC_CheckField, 16, 5, 0, 160, 8, // Skip to: 4812
/* 2604 */    MCD::OPC_Decode, 146, 4, 51, // Opcode: RADDU_W_QB
/* 2608 */    MCD::OPC_FilterValue, 22, 7, 0, // Skip to: 2619
/* 2612 */    MCD::OPC_CheckPredicate, 2, 148, 8, // Skip to: 4812
/* 2616 */    MCD::OPC_Decode, 27, 3, // Opcode: ADDQ_S_W
/* 2619 */    MCD::OPC_FilterValue, 23, 8, 0, // Skip to: 2631
/* 2623 */    MCD::OPC_CheckPredicate, 2, 137, 8, // Skip to: 4812
/* 2627 */    MCD::OPC_Decode, 244, 4, 3, // Opcode: SUBQ_S_W
/* 2631 */    MCD::OPC_FilterValue, 28, 8, 0, // Skip to: 2643
/* 2635 */    MCD::OPC_CheckPredicate, 2, 125, 8, // Skip to: 4812
/* 2639 */    MCD::OPC_Decode, 209, 3, 52, // Opcode: MULEQ_S_W_PHL
/* 2643 */    MCD::OPC_FilterValue, 29, 8, 0, // Skip to: 2655
/* 2647 */    MCD::OPC_CheckPredicate, 2, 113, 8, // Skip to: 4812
/* 2651 */    MCD::OPC_Decode, 210, 3, 52, // Opcode: MULEQ_S_W_PHR
/* 2655 */    MCD::OPC_FilterValue, 30, 8, 0, // Skip to: 2667
/* 2659 */    MCD::OPC_CheckPredicate, 12, 101, 8, // Skip to: 4812
/* 2663 */    MCD::OPC_Decode, 215, 3, 50, // Opcode: MULQ_S_PH
/* 2667 */    MCD::OPC_FilterValue, 31, 93, 8, // Skip to: 4812
/* 2671 */    MCD::OPC_CheckPredicate, 2, 89, 8, // Skip to: 4812
/* 2675 */    MCD::OPC_Decode, 213, 3, 50, // Opcode: MULQ_RS_PH
/* 2679 */    MCD::OPC_FilterValue, 17, 47, 1, // Skip to: 2986
/* 2683 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 2686 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 2704
/* 2690 */    MCD::OPC_CheckPredicate, 2, 70, 8, // Skip to: 4812
/* 2694 */    MCD::OPC_CheckField, 11, 5, 0, 64, 8, // Skip to: 4812
/* 2700 */    MCD::OPC_Decode, 170, 1, 53, // Opcode: CMPU_EQ_QB
/* 2704 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 2722
/* 2708 */    MCD::OPC_CheckPredicate, 2, 52, 8, // Skip to: 4812
/* 2712 */    MCD::OPC_CheckField, 11, 5, 0, 46, 8, // Skip to: 4812
/* 2718 */    MCD::OPC_Decode, 172, 1, 53, // Opcode: CMPU_LT_QB
/* 2722 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 2740
/* 2726 */    MCD::OPC_CheckPredicate, 2, 34, 8, // Skip to: 4812
/* 2730 */    MCD::OPC_CheckField, 11, 5, 0, 28, 8, // Skip to: 4812
/* 2736 */    MCD::OPC_Decode, 171, 1, 53, // Opcode: CMPU_LE_QB
/* 2740 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 2752
/* 2744 */    MCD::OPC_CheckPredicate, 2, 16, 8, // Skip to: 4812
/* 2748 */    MCD::OPC_Decode, 255, 3, 50, // Opcode: PICK_QB
/* 2752 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2764
/* 2756 */    MCD::OPC_CheckPredicate, 2, 4, 8, // Skip to: 4812
/* 2760 */    MCD::OPC_Decode, 167, 1, 52, // Opcode: CMPGU_EQ_QB
/* 2764 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2776
/* 2768 */    MCD::OPC_CheckPredicate, 2, 248, 7, // Skip to: 4812
/* 2772 */    MCD::OPC_Decode, 169, 1, 52, // Opcode: CMPGU_LT_QB
/* 2776 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2788
/* 2780 */    MCD::OPC_CheckPredicate, 2, 236, 7, // Skip to: 4812
/* 2784 */    MCD::OPC_Decode, 168, 1, 52, // Opcode: CMPGU_LE_QB
/* 2788 */    MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 2806
/* 2792 */    MCD::OPC_CheckPredicate, 2, 224, 7, // Skip to: 4812
/* 2796 */    MCD::OPC_CheckField, 11, 5, 0, 218, 7, // Skip to: 4812
/* 2802 */    MCD::OPC_Decode, 173, 1, 53, // Opcode: CMP_EQ_PH
/* 2806 */    MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 2824
/* 2810 */    MCD::OPC_CheckPredicate, 2, 206, 7, // Skip to: 4812
/* 2814 */    MCD::OPC_CheckField, 11, 5, 0, 200, 7, // Skip to: 4812
/* 2820 */    MCD::OPC_Decode, 175, 1, 53, // Opcode: CMP_LT_PH
/* 2824 */    MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 2842
/* 2828 */    MCD::OPC_CheckPredicate, 2, 188, 7, // Skip to: 4812
/* 2832 */    MCD::OPC_CheckField, 11, 5, 0, 182, 7, // Skip to: 4812
/* 2838 */    MCD::OPC_Decode, 174, 1, 53, // Opcode: CMP_LE_PH
/* 2842 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 2854
/* 2846 */    MCD::OPC_CheckPredicate, 2, 170, 7, // Skip to: 4812
/* 2850 */    MCD::OPC_Decode, 254, 3, 50, // Opcode: PICK_PH
/* 2854 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 2866
/* 2858 */    MCD::OPC_CheckPredicate, 2, 158, 7, // Skip to: 4812
/* 2862 */    MCD::OPC_Decode, 140, 4, 50, // Opcode: PRECRQ_QB_PH
/* 2866 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2878
/* 2870 */    MCD::OPC_CheckPredicate, 12, 146, 7, // Skip to: 4812
/* 2874 */    MCD::OPC_Decode, 142, 4, 50, // Opcode: PRECR_QB_PH
/* 2878 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 2890
/* 2882 */    MCD::OPC_CheckPredicate, 2, 134, 7, // Skip to: 4812
/* 2886 */    MCD::OPC_Decode, 253, 3, 50, // Opcode: PACKRL_PH
/* 2890 */    MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 2902
/* 2894 */    MCD::OPC_CheckPredicate, 2, 122, 7, // Skip to: 4812
/* 2898 */    MCD::OPC_Decode, 138, 4, 50, // Opcode: PRECRQU_S_QB_PH
/* 2902 */    MCD::OPC_FilterValue, 20, 8, 0, // Skip to: 2914
/* 2906 */    MCD::OPC_CheckPredicate, 2, 110, 7, // Skip to: 4812
/* 2910 */    MCD::OPC_Decode, 139, 4, 54, // Opcode: PRECRQ_PH_W
/* 2914 */    MCD::OPC_FilterValue, 21, 8, 0, // Skip to: 2926
/* 2918 */    MCD::OPC_CheckPredicate, 2, 98, 7, // Skip to: 4812
/* 2922 */    MCD::OPC_Decode, 141, 4, 54, // Opcode: PRECRQ_RS_PH_W
/* 2926 */    MCD::OPC_FilterValue, 24, 8, 0, // Skip to: 2938
/* 2930 */    MCD::OPC_CheckPredicate, 12, 86, 7, // Skip to: 4812
/* 2934 */    MCD::OPC_Decode, 164, 1, 52, // Opcode: CMPGDU_EQ_QB
/* 2938 */    MCD::OPC_FilterValue, 25, 8, 0, // Skip to: 2950
/* 2942 */    MCD::OPC_CheckPredicate, 12, 74, 7, // Skip to: 4812
/* 2946 */    MCD::OPC_Decode, 166, 1, 52, // Opcode: CMPGDU_LT_QB
/* 2950 */    MCD::OPC_FilterValue, 26, 8, 0, // Skip to: 2962
/* 2954 */    MCD::OPC_CheckPredicate, 12, 62, 7, // Skip to: 4812
/* 2958 */    MCD::OPC_Decode, 165, 1, 52, // Opcode: CMPGDU_LE_QB
/* 2962 */    MCD::OPC_FilterValue, 30, 8, 0, // Skip to: 2974
/* 2966 */    MCD::OPC_CheckPredicate, 12, 50, 7, // Skip to: 4812
/* 2970 */    MCD::OPC_Decode, 143, 4, 55, // Opcode: PRECR_SRA_PH_W
/* 2974 */    MCD::OPC_FilterValue, 31, 42, 7, // Skip to: 4812
/* 2978 */    MCD::OPC_CheckPredicate, 12, 38, 7, // Skip to: 4812
/* 2982 */    MCD::OPC_Decode, 144, 4, 55, // Opcode: PRECR_SRA_R_PH_W
/* 2986 */    MCD::OPC_FilterValue, 18, 56, 1, // Skip to: 3302
/* 2990 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 2993 */    MCD::OPC_FilterValue, 1, 13, 0, // Skip to: 3010
/* 2997 */    MCD::OPC_CheckPredicate, 12, 19, 7, // Skip to: 4812
/* 3001 */    MCD::OPC_CheckField, 21, 5, 0, 13, 7, // Skip to: 4812
/* 3007 */    MCD::OPC_Decode, 18, 56, // Opcode: ABSQ_S_QB
/* 3010 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3022
/* 3014 */    MCD::OPC_CheckPredicate, 2, 2, 7, // Skip to: 4812
/* 3018 */    MCD::OPC_Decode, 153, 4, 57, // Opcode: REPL_QB
/* 3022 */    MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 3040
/* 3026 */    MCD::OPC_CheckPredicate, 2, 246, 6, // Skip to: 4812
/* 3030 */    MCD::OPC_CheckField, 21, 5, 0, 240, 6, // Skip to: 4812
/* 3036 */    MCD::OPC_Decode, 151, 4, 58, // Opcode: REPLV_QB
/* 3040 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 3058
/* 3044 */    MCD::OPC_CheckPredicate, 2, 228, 6, // Skip to: 4812
/* 3048 */    MCD::OPC_CheckField, 21, 5, 0, 222, 6, // Skip to: 4812
/* 3054 */    MCD::OPC_Decode, 128, 4, 56, // Opcode: PRECEQU_PH_QBL
/* 3058 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 3076
/* 3062 */    MCD::OPC_CheckPredicate, 2, 210, 6, // Skip to: 4812
/* 3066 */    MCD::OPC_CheckField, 21, 5, 0, 204, 6, // Skip to: 4812
/* 3072 */    MCD::OPC_Decode, 130, 4, 56, // Opcode: PRECEQU_PH_QBR
/* 3076 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 3094
/* 3080 */    MCD::OPC_CheckPredicate, 2, 192, 6, // Skip to: 4812
/* 3084 */    MCD::OPC_CheckField, 21, 5, 0, 186, 6, // Skip to: 4812
/* 3090 */    MCD::OPC_Decode, 129, 4, 56, // Opcode: PRECEQU_PH_QBLA
/* 3094 */    MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 3112
/* 3098 */    MCD::OPC_CheckPredicate, 2, 174, 6, // Skip to: 4812
/* 3102 */    MCD::OPC_CheckField, 21, 5, 0, 168, 6, // Skip to: 4812
/* 3108 */    MCD::OPC_Decode, 131, 4, 56, // Opcode: PRECEQU_PH_QBRA
/* 3112 */    MCD::OPC_FilterValue, 9, 13, 0, // Skip to: 3129
/* 3116 */    MCD::OPC_CheckPredicate, 2, 156, 6, // Skip to: 4812
/* 3120 */    MCD::OPC_CheckField, 21, 5, 0, 150, 6, // Skip to: 4812
/* 3126 */    MCD::OPC_Decode, 17, 56, // Opcode: ABSQ_S_PH
/* 3129 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 3141
/* 3133 */    MCD::OPC_CheckPredicate, 2, 139, 6, // Skip to: 4812
/* 3137 */    MCD::OPC_Decode, 152, 4, 57, // Opcode: REPL_PH
/* 3141 */    MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 3159
/* 3145 */    MCD::OPC_CheckPredicate, 2, 127, 6, // Skip to: 4812
/* 3149 */    MCD::OPC_CheckField, 21, 5, 0, 121, 6, // Skip to: 4812
/* 3155 */    MCD::OPC_Decode, 150, 4, 58, // Opcode: REPLV_PH
/* 3159 */    MCD::OPC_FilterValue, 12, 14, 0, // Skip to: 3177
/* 3163 */    MCD::OPC_CheckPredicate, 2, 109, 6, // Skip to: 4812
/* 3167 */    MCD::OPC_CheckField, 21, 5, 0, 103, 6, // Skip to: 4812
/* 3173 */    MCD::OPC_Decode, 132, 4, 59, // Opcode: PRECEQ_W_PHL
/* 3177 */    MCD::OPC_FilterValue, 13, 14, 0, // Skip to: 3195
/* 3181 */    MCD::OPC_CheckPredicate, 2, 91, 6, // Skip to: 4812
/* 3185 */    MCD::OPC_CheckField, 21, 5, 0, 85, 6, // Skip to: 4812
/* 3191 */    MCD::OPC_Decode, 133, 4, 59, // Opcode: PRECEQ_W_PHR
/* 3195 */    MCD::OPC_FilterValue, 17, 13, 0, // Skip to: 3212
/* 3199 */    MCD::OPC_CheckPredicate, 2, 73, 6, // Skip to: 4812
/* 3203 */    MCD::OPC_CheckField, 21, 5, 0, 67, 6, // Skip to: 4812
/* 3209 */    MCD::OPC_Decode, 19, 60, // Opcode: ABSQ_S_W
/* 3212 */    MCD::OPC_FilterValue, 27, 14, 0, // Skip to: 3230
/* 3216 */    MCD::OPC_CheckPredicate, 2, 56, 6, // Skip to: 4812
/* 3220 */    MCD::OPC_CheckField, 21, 5, 0, 50, 6, // Skip to: 4812
/* 3226 */    MCD::OPC_Decode, 128, 1, 60, // Opcode: BITREV
/* 3230 */    MCD::OPC_FilterValue, 28, 14, 0, // Skip to: 3248
/* 3234 */    MCD::OPC_CheckPredicate, 2, 38, 6, // Skip to: 4812
/* 3238 */    MCD::OPC_CheckField, 21, 5, 0, 32, 6, // Skip to: 4812
/* 3244 */    MCD::OPC_Decode, 134, 4, 56, // Opcode: PRECEU_PH_QBL
/* 3248 */    MCD::OPC_FilterValue, 29, 14, 0, // Skip to: 3266
/* 3252 */    MCD::OPC_CheckPredicate, 2, 20, 6, // Skip to: 4812
/* 3256 */    MCD::OPC_CheckField, 21, 5, 0, 14, 6, // Skip to: 4812
/* 3262 */    MCD::OPC_Decode, 136, 4, 56, // Opcode: PRECEU_PH_QBR
/* 3266 */    MCD::OPC_FilterValue, 30, 14, 0, // Skip to: 3284
/* 3270 */    MCD::OPC_CheckPredicate, 2, 2, 6, // Skip to: 4812
/* 3274 */    MCD::OPC_CheckField, 21, 5, 0, 252, 5, // Skip to: 4812
/* 3280 */    MCD::OPC_Decode, 135, 4, 56, // Opcode: PRECEU_PH_QBLA
/* 3284 */    MCD::OPC_FilterValue, 31, 244, 5, // Skip to: 4812
/* 3288 */    MCD::OPC_CheckPredicate, 2, 240, 5, // Skip to: 4812
/* 3292 */    MCD::OPC_CheckField, 21, 5, 0, 234, 5, // Skip to: 4812
/* 3298 */    MCD::OPC_Decode, 137, 4, 56, // Opcode: PRECEU_PH_QBRA
/* 3302 */    MCD::OPC_FilterValue, 19, 11, 1, // Skip to: 3573
/* 3306 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3309 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3321
/* 3313 */    MCD::OPC_CheckPredicate, 2, 215, 5, // Skip to: 4812
/* 3317 */    MCD::OPC_Decode, 203, 4, 61, // Opcode: SHLL_QB
/* 3321 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3333
/* 3325 */    MCD::OPC_CheckPredicate, 2, 203, 5, // Skip to: 4812
/* 3329 */    MCD::OPC_Decode, 219, 4, 61, // Opcode: SHRL_QB
/* 3333 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3345
/* 3337 */    MCD::OPC_CheckPredicate, 2, 191, 5, // Skip to: 4812
/* 3341 */    MCD::OPC_Decode, 199, 4, 62, // Opcode: SHLLV_QB
/* 3345 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 3357
/* 3349 */    MCD::OPC_CheckPredicate, 2, 179, 5, // Skip to: 4812
/* 3353 */    MCD::OPC_Decode, 217, 4, 62, // Opcode: SHRLV_QB
/* 3357 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 3369
/* 3361 */    MCD::OPC_CheckPredicate, 12, 167, 5, // Skip to: 4812
/* 3365 */    MCD::OPC_Decode, 212, 4, 61, // Opcode: SHRA_QB
/* 3369 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 3381
/* 3373 */    MCD::OPC_CheckPredicate, 12, 155, 5, // Skip to: 4812
/* 3377 */    MCD::OPC_Decode, 214, 4, 61, // Opcode: SHRA_R_QB
/* 3381 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 3393
/* 3385 */    MCD::OPC_CheckPredicate, 12, 143, 5, // Skip to: 4812
/* 3389 */    MCD::OPC_Decode, 207, 4, 62, // Opcode: SHRAV_QB
/* 3393 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 3405
/* 3397 */    MCD::OPC_CheckPredicate, 12, 131, 5, // Skip to: 4812
/* 3401 */    MCD::OPC_Decode, 209, 4, 62, // Opcode: SHRAV_R_QB
/* 3405 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 3417
/* 3409 */    MCD::OPC_CheckPredicate, 2, 119, 5, // Skip to: 4812
/* 3413 */    MCD::OPC_Decode, 202, 4, 61, // Opcode: SHLL_PH
/* 3417 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 3429
/* 3421 */    MCD::OPC_CheckPredicate, 2, 107, 5, // Skip to: 4812
/* 3425 */    MCD::OPC_Decode, 211, 4, 61, // Opcode: SHRA_PH
/* 3429 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 3441
/* 3433 */    MCD::OPC_CheckPredicate, 2, 95, 5, // Skip to: 4812
/* 3437 */    MCD::OPC_Decode, 198, 4, 62, // Opcode: SHLLV_PH
/* 3441 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 3453
/* 3445 */    MCD::OPC_CheckPredicate, 2, 83, 5, // Skip to: 4812
/* 3449 */    MCD::OPC_Decode, 206, 4, 62, // Opcode: SHRAV_PH
/* 3453 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 3465
/* 3457 */    MCD::OPC_CheckPredicate, 2, 71, 5, // Skip to: 4812
/* 3461 */    MCD::OPC_Decode, 204, 4, 61, // Opcode: SHLL_S_PH
/* 3465 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 3477
/* 3469 */    MCD::OPC_CheckPredicate, 2, 59, 5, // Skip to: 4812
/* 3473 */    MCD::OPC_Decode, 213, 4, 61, // Opcode: SHRA_R_PH
/* 3477 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 3489
/* 3481 */    MCD::OPC_CheckPredicate, 2, 47, 5, // Skip to: 4812
/* 3485 */    MCD::OPC_Decode, 200, 4, 62, // Opcode: SHLLV_S_PH
/* 3489 */    MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 3501
/* 3493 */    MCD::OPC_CheckPredicate, 2, 35, 5, // Skip to: 4812
/* 3497 */    MCD::OPC_Decode, 208, 4, 62, // Opcode: SHRAV_R_PH
/* 3501 */    MCD::OPC_FilterValue, 20, 8, 0, // Skip to: 3513
/* 3505 */    MCD::OPC_CheckPredicate, 2, 23, 5, // Skip to: 4812
/* 3509 */    MCD::OPC_Decode, 205, 4, 63, // Opcode: SHLL_S_W
/* 3513 */    MCD::OPC_FilterValue, 21, 8, 0, // Skip to: 3525
/* 3517 */    MCD::OPC_CheckPredicate, 2, 11, 5, // Skip to: 4812
/* 3521 */    MCD::OPC_Decode, 215, 4, 63, // Opcode: SHRA_R_W
/* 3525 */    MCD::OPC_FilterValue, 22, 8, 0, // Skip to: 3537
/* 3529 */    MCD::OPC_CheckPredicate, 2, 255, 4, // Skip to: 4812
/* 3533 */    MCD::OPC_Decode, 201, 4, 64, // Opcode: SHLLV_S_W
/* 3537 */    MCD::OPC_FilterValue, 23, 8, 0, // Skip to: 3549
/* 3541 */    MCD::OPC_CheckPredicate, 2, 243, 4, // Skip to: 4812
/* 3545 */    MCD::OPC_Decode, 210, 4, 64, // Opcode: SHRAV_R_W
/* 3549 */    MCD::OPC_FilterValue, 25, 8, 0, // Skip to: 3561
/* 3553 */    MCD::OPC_CheckPredicate, 12, 231, 4, // Skip to: 4812
/* 3557 */    MCD::OPC_Decode, 218, 4, 61, // Opcode: SHRL_PH
/* 3561 */    MCD::OPC_FilterValue, 27, 223, 4, // Skip to: 4812
/* 3565 */    MCD::OPC_CheckPredicate, 12, 219, 4, // Skip to: 4812
/* 3569 */    MCD::OPC_Decode, 216, 4, 62, // Opcode: SHRLV_PH
/* 3573 */    MCD::OPC_FilterValue, 24, 189, 0, // Skip to: 3766
/* 3577 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3580 */    MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 3591
/* 3584 */    MCD::OPC_CheckPredicate, 12, 200, 4, // Skip to: 4812
/* 3588 */    MCD::OPC_Decode, 29, 50, // Opcode: ADDUH_QB
/* 3591 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3603
/* 3595 */    MCD::OPC_CheckPredicate, 12, 189, 4, // Skip to: 4812
/* 3599 */    MCD::OPC_Decode, 245, 4, 50, // Opcode: SUBUH_QB
/* 3603 */    MCD::OPC_FilterValue, 2, 7, 0, // Skip to: 3614
/* 3607 */    MCD::OPC_CheckPredicate, 12, 177, 4, // Skip to: 4812
/* 3611 */    MCD::OPC_Decode, 30, 50, // Opcode: ADDUH_R_QB
/* 3614 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 3626
/* 3618 */    MCD::OPC_CheckPredicate, 12, 166, 4, // Skip to: 4812
/* 3622 */    MCD::OPC_Decode, 246, 4, 50, // Opcode: SUBUH_R_QB
/* 3626 */    MCD::OPC_FilterValue, 8, 7, 0, // Skip to: 3637
/* 3630 */    MCD::OPC_CheckPredicate, 12, 154, 4, // Skip to: 4812
/* 3634 */    MCD::OPC_Decode, 21, 50, // Opcode: ADDQH_PH
/* 3637 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 3649
/* 3641 */    MCD::OPC_CheckPredicate, 12, 143, 4, // Skip to: 4812
/* 3645 */    MCD::OPC_Decode, 238, 4, 50, // Opcode: SUBQH_PH
/* 3649 */    MCD::OPC_FilterValue, 10, 7, 0, // Skip to: 3660
/* 3653 */    MCD::OPC_CheckPredicate, 12, 131, 4, // Skip to: 4812
/* 3657 */    MCD::OPC_Decode, 22, 50, // Opcode: ADDQH_R_PH
/* 3660 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 3672
/* 3664 */    MCD::OPC_CheckPredicate, 12, 120, 4, // Skip to: 4812
/* 3668 */    MCD::OPC_Decode, 239, 4, 50, // Opcode: SUBQH_R_PH
/* 3672 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 3684
/* 3676 */    MCD::OPC_CheckPredicate, 12, 108, 4, // Skip to: 4812
/* 3680 */    MCD::OPC_Decode, 227, 3, 50, // Opcode: MUL_PH
/* 3684 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 3696
/* 3688 */    MCD::OPC_CheckPredicate, 12, 96, 4, // Skip to: 4812
/* 3692 */    MCD::OPC_Decode, 228, 3, 50, // Opcode: MUL_S_PH
/* 3696 */    MCD::OPC_FilterValue, 16, 7, 0, // Skip to: 3707
/* 3700 */    MCD::OPC_CheckPredicate, 12, 84, 4, // Skip to: 4812
/* 3704 */    MCD::OPC_Decode, 24, 3, // Opcode: ADDQH_W
/* 3707 */    MCD::OPC_FilterValue, 17, 8, 0, // Skip to: 3719
/* 3711 */    MCD::OPC_CheckPredicate, 12, 73, 4, // Skip to: 4812
/* 3715 */    MCD::OPC_Decode, 241, 4, 3, // Opcode: SUBQH_W
/* 3719 */    MCD::OPC_FilterValue, 18, 7, 0, // Skip to: 3730
/* 3723 */    MCD::OPC_CheckPredicate, 12, 61, 4, // Skip to: 4812
/* 3727 */    MCD::OPC_Decode, 23, 3, // Opcode: ADDQH_R_W
/* 3730 */    MCD::OPC_FilterValue, 19, 8, 0, // Skip to: 3742
/* 3734 */    MCD::OPC_CheckPredicate, 12, 50, 4, // Skip to: 4812
/* 3738 */    MCD::OPC_Decode, 240, 4, 3, // Opcode: SUBQH_R_W
/* 3742 */    MCD::OPC_FilterValue, 22, 8, 0, // Skip to: 3754
/* 3746 */    MCD::OPC_CheckPredicate, 12, 38, 4, // Skip to: 4812
/* 3750 */    MCD::OPC_Decode, 216, 3, 3, // Opcode: MULQ_S_W
/* 3754 */    MCD::OPC_FilterValue, 23, 30, 4, // Skip to: 4812
/* 3758 */    MCD::OPC_CheckPredicate, 12, 26, 4, // Skip to: 4812
/* 3762 */    MCD::OPC_Decode, 214, 3, 3, // Opcode: MULQ_RS_W
/* 3766 */    MCD::OPC_FilterValue, 32, 57, 0, // Skip to: 3827
/* 3770 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3773 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 3791
/* 3777 */    MCD::OPC_CheckPredicate, 13, 7, 4, // Skip to: 4812
/* 3781 */    MCD::OPC_CheckField, 21, 5, 0, 1, 4, // Skip to: 4812
/* 3787 */    MCD::OPC_Decode, 186, 5, 60, // Opcode: WSBH
/* 3791 */    MCD::OPC_FilterValue, 16, 14, 0, // Skip to: 3809
/* 3795 */    MCD::OPC_CheckPredicate, 14, 245, 3, // Skip to: 4812
/* 3799 */    MCD::OPC_CheckField, 21, 5, 0, 239, 3, // Skip to: 4812
/* 3805 */    MCD::OPC_Decode, 187, 4, 60, // Opcode: SEB
/* 3809 */    MCD::OPC_FilterValue, 24, 231, 3, // Skip to: 4812
/* 3813 */    MCD::OPC_CheckPredicate, 14, 227, 3, // Skip to: 4812
/* 3817 */    MCD::OPC_CheckField, 21, 5, 0, 221, 3, // Skip to: 4812
/* 3823 */    MCD::OPC_Decode, 189, 4, 60, // Opcode: SEH
/* 3827 */    MCD::OPC_FilterValue, 48, 143, 1, // Skip to: 4230
/* 3831 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3834 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 3852
/* 3838 */    MCD::OPC_CheckPredicate, 12, 202, 3, // Skip to: 4812
/* 3842 */    MCD::OPC_CheckField, 13, 3, 0, 196, 3, // Skip to: 4812
/* 3848 */    MCD::OPC_Decode, 227, 1, 9, // Opcode: DPA_W_PH
/* 3852 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 3870
/* 3856 */    MCD::OPC_CheckPredicate, 12, 184, 3, // Skip to: 4812
/* 3860 */    MCD::OPC_CheckField, 13, 3, 0, 178, 3, // Skip to: 4812
/* 3866 */    MCD::OPC_Decode, 243, 1, 9, // Opcode: DPS_W_PH
/* 3870 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 3888
/* 3874 */    MCD::OPC_CheckPredicate, 12, 166, 3, // Skip to: 4812
/* 3878 */    MCD::OPC_CheckField, 13, 3, 0, 160, 3, // Skip to: 4812
/* 3884 */    MCD::OPC_Decode, 219, 3, 9, // Opcode: MULSA_W_PH
/* 3888 */    MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 3906
/* 3892 */    MCD::OPC_CheckPredicate, 2, 148, 3, // Skip to: 4812
/* 3896 */    MCD::OPC_CheckField, 13, 3, 0, 142, 3, // Skip to: 4812
/* 3902 */    MCD::OPC_Decode, 221, 1, 9, // Opcode: DPAU_H_QBL
/* 3906 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 3924
/* 3910 */    MCD::OPC_CheckPredicate, 2, 130, 3, // Skip to: 4812
/* 3914 */    MCD::OPC_CheckField, 13, 3, 0, 124, 3, // Skip to: 4812
/* 3920 */    MCD::OPC_Decode, 219, 1, 9, // Opcode: DPAQ_S_W_PH
/* 3924 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 3942
/* 3928 */    MCD::OPC_CheckPredicate, 2, 112, 3, // Skip to: 4812
/* 3932 */    MCD::OPC_CheckField, 13, 3, 0, 106, 3, // Skip to: 4812
/* 3938 */    MCD::OPC_Decode, 235, 1, 9, // Opcode: DPSQ_S_W_PH
/* 3942 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 3960
/* 3946 */    MCD::OPC_CheckPredicate, 2, 94, 3, // Skip to: 4812
/* 3950 */    MCD::OPC_CheckField, 13, 3, 0, 88, 3, // Skip to: 4812
/* 3956 */    MCD::OPC_Decode, 217, 3, 9, // Opcode: MULSAQ_S_W_PH
/* 3960 */    MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 3978
/* 3964 */    MCD::OPC_CheckPredicate, 2, 76, 3, // Skip to: 4812
/* 3968 */    MCD::OPC_CheckField, 13, 3, 0, 70, 3, // Skip to: 4812
/* 3974 */    MCD::OPC_Decode, 223, 1, 9, // Opcode: DPAU_H_QBR
/* 3978 */    MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 3996
/* 3982 */    MCD::OPC_CheckPredicate, 12, 58, 3, // Skip to: 4812
/* 3986 */    MCD::OPC_CheckField, 13, 3, 0, 52, 3, // Skip to: 4812
/* 3992 */    MCD::OPC_Decode, 225, 1, 9, // Opcode: DPAX_W_PH
/* 3996 */    MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 4014
/* 4000 */    MCD::OPC_CheckPredicate, 12, 40, 3, // Skip to: 4812
/* 4004 */    MCD::OPC_CheckField, 13, 3, 0, 34, 3, // Skip to: 4812
/* 4010 */    MCD::OPC_Decode, 241, 1, 9, // Opcode: DPSX_W_PH
/* 4014 */    MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 4032
/* 4018 */    MCD::OPC_CheckPredicate, 2, 22, 3, // Skip to: 4812
/* 4022 */    MCD::OPC_CheckField, 13, 3, 0, 16, 3, // Skip to: 4812
/* 4028 */    MCD::OPC_Decode, 237, 1, 9, // Opcode: DPSU_H_QBL
/* 4032 */    MCD::OPC_FilterValue, 12, 14, 0, // Skip to: 4050
/* 4036 */    MCD::OPC_CheckPredicate, 2, 4, 3, // Skip to: 4812
/* 4040 */    MCD::OPC_CheckField, 13, 3, 0, 254, 2, // Skip to: 4812
/* 4046 */    MCD::OPC_Decode, 217, 1, 9, // Opcode: DPAQ_SA_L_W
/* 4050 */    MCD::OPC_FilterValue, 13, 14, 0, // Skip to: 4068
/* 4054 */    MCD::OPC_CheckPredicate, 2, 242, 2, // Skip to: 4812
/* 4058 */    MCD::OPC_CheckField, 13, 3, 0, 236, 2, // Skip to: 4812
/* 4064 */    MCD::OPC_Decode, 233, 1, 9, // Opcode: DPSQ_SA_L_W
/* 4068 */    MCD::OPC_FilterValue, 15, 14, 0, // Skip to: 4086
/* 4072 */    MCD::OPC_CheckPredicate, 2, 224, 2, // Skip to: 4812
/* 4076 */    MCD::OPC_CheckField, 13, 3, 0, 218, 2, // Skip to: 4812
/* 4082 */    MCD::OPC_Decode, 239, 1, 9, // Opcode: DPSU_H_QBR
/* 4086 */    MCD::OPC_FilterValue, 16, 14, 0, // Skip to: 4104
/* 4090 */    MCD::OPC_CheckPredicate, 2, 206, 2, // Skip to: 4812
/* 4094 */    MCD::OPC_CheckField, 13, 3, 0, 200, 2, // Skip to: 4812
/* 4100 */    MCD::OPC_Decode, 145, 3, 9, // Opcode: MAQ_SA_W_PHL
/* 4104 */    MCD::OPC_FilterValue, 18, 14, 0, // Skip to: 4122
/* 4108 */    MCD::OPC_CheckPredicate, 2, 188, 2, // Skip to: 4812
/* 4112 */    MCD::OPC_CheckField, 13, 3, 0, 182, 2, // Skip to: 4812
/* 4118 */    MCD::OPC_Decode, 147, 3, 9, // Opcode: MAQ_SA_W_PHR
/* 4122 */    MCD::OPC_FilterValue, 20, 14, 0, // Skip to: 4140
/* 4126 */    MCD::OPC_CheckPredicate, 2, 170, 2, // Skip to: 4812
/* 4130 */    MCD::OPC_CheckField, 13, 3, 0, 164, 2, // Skip to: 4812
/* 4136 */    MCD::OPC_Decode, 149, 3, 9, // Opcode: MAQ_S_W_PHL
/* 4140 */    MCD::OPC_FilterValue, 22, 14, 0, // Skip to: 4158
/* 4144 */    MCD::OPC_CheckPredicate, 2, 152, 2, // Skip to: 4812
/* 4148 */    MCD::OPC_CheckField, 13, 3, 0, 146, 2, // Skip to: 4812
/* 4154 */    MCD::OPC_Decode, 151, 3, 9, // Opcode: MAQ_S_W_PHR
/* 4158 */    MCD::OPC_FilterValue, 24, 14, 0, // Skip to: 4176
/* 4162 */    MCD::OPC_CheckPredicate, 12, 134, 2, // Skip to: 4812
/* 4166 */    MCD::OPC_CheckField, 13, 3, 0, 128, 2, // Skip to: 4812
/* 4172 */    MCD::OPC_Decode, 215, 1, 9, // Opcode: DPAQX_S_W_PH
/* 4176 */    MCD::OPC_FilterValue, 25, 14, 0, // Skip to: 4194
/* 4180 */    MCD::OPC_CheckPredicate, 12, 116, 2, // Skip to: 4812
/* 4184 */    MCD::OPC_CheckField, 13, 3, 0, 110, 2, // Skip to: 4812
/* 4190 */    MCD::OPC_Decode, 231, 1, 9, // Opcode: DPSQX_S_W_PH
/* 4194 */    MCD::OPC_FilterValue, 26, 14, 0, // Skip to: 4212
/* 4198 */    MCD::OPC_CheckPredicate, 12, 98, 2, // Skip to: 4812
/* 4202 */    MCD::OPC_CheckField, 13, 3, 0, 92, 2, // Skip to: 4812
/* 4208 */    MCD::OPC_Decode, 213, 1, 9, // Opcode: DPAQX_SA_W_PH
/* 4212 */    MCD::OPC_FilterValue, 27, 84, 2, // Skip to: 4812
/* 4216 */    MCD::OPC_CheckPredicate, 12, 80, 2, // Skip to: 4812
/* 4220 */    MCD::OPC_CheckField, 13, 3, 0, 74, 2, // Skip to: 4812
/* 4226 */    MCD::OPC_Decode, 229, 1, 9, // Opcode: DPSQX_SA_W_PH
/* 4230 */    MCD::OPC_FilterValue, 49, 37, 0, // Skip to: 4271
/* 4234 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 4237 */    MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 4248
/* 4241 */    MCD::OPC_CheckPredicate, 12, 55, 2, // Skip to: 4812
/* 4245 */    MCD::OPC_Decode, 44, 65, // Opcode: APPEND
/* 4248 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 4260
/* 4252 */    MCD::OPC_CheckPredicate, 12, 44, 2, // Skip to: 4812
/* 4256 */    MCD::OPC_Decode, 145, 4, 65, // Opcode: PREPEND
/* 4260 */    MCD::OPC_FilterValue, 16, 36, 2, // Skip to: 4812
/* 4264 */    MCD::OPC_CheckPredicate, 12, 32, 2, // Skip to: 4812
/* 4268 */    MCD::OPC_Decode, 117, 65, // Opcode: BALIGN
/* 4271 */    MCD::OPC_FilterValue, 56, 41, 1, // Skip to: 4572
/* 4275 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 4278 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 4296
/* 4282 */    MCD::OPC_CheckPredicate, 2, 14, 2, // Skip to: 4812
/* 4286 */    MCD::OPC_CheckField, 13, 3, 0, 8, 2, // Skip to: 4812
/* 4292 */    MCD::OPC_Decode, 148, 2, 66, // Opcode: EXTR_W
/* 4296 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 4314
/* 4300 */    MCD::OPC_CheckPredicate, 2, 252, 1, // Skip to: 4812
/* 4304 */    MCD::OPC_CheckField, 13, 3, 0, 246, 1, // Skip to: 4812
/* 4310 */    MCD::OPC_Decode, 144, 2, 67, // Opcode: EXTRV_W
/* 4314 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 4332
/* 4318 */    MCD::OPC_CheckPredicate, 2, 234, 1, // Skip to: 4812
/* 4322 */    MCD::OPC_CheckField, 13, 3, 0, 228, 1, // Skip to: 4812
/* 4328 */    MCD::OPC_Decode, 137, 2, 66, // Opcode: EXTP
/* 4332 */    MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 4350
/* 4336 */    MCD::OPC_CheckPredicate, 2, 216, 1, // Skip to: 4812
/* 4340 */    MCD::OPC_CheckField, 13, 3, 0, 210, 1, // Skip to: 4812
/* 4346 */    MCD::OPC_Decode, 140, 2, 67, // Opcode: EXTPV
/* 4350 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 4368
/* 4354 */    MCD::OPC_CheckPredicate, 2, 198, 1, // Skip to: 4812
/* 4358 */    MCD::OPC_CheckField, 13, 3, 0, 192, 1, // Skip to: 4812
/* 4364 */    MCD::OPC_Decode, 146, 2, 66, // Opcode: EXTR_R_W
/* 4368 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 4386
/* 4372 */    MCD::OPC_CheckPredicate, 2, 180, 1, // Skip to: 4812
/* 4376 */    MCD::OPC_CheckField, 13, 3, 0, 174, 1, // Skip to: 4812
/* 4382 */    MCD::OPC_Decode, 142, 2, 67, // Opcode: EXTRV_R_W
/* 4386 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 4404
/* 4390 */    MCD::OPC_CheckPredicate, 2, 162, 1, // Skip to: 4812
/* 4394 */    MCD::OPC_CheckField, 13, 3, 0, 156, 1, // Skip to: 4812
/* 4400 */    MCD::OPC_Decode, 145, 2, 66, // Opcode: EXTR_RS_W
/* 4404 */    MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 4422
/* 4408 */    MCD::OPC_CheckPredicate, 2, 144, 1, // Skip to: 4812
/* 4412 */    MCD::OPC_CheckField, 13, 3, 0, 138, 1, // Skip to: 4812
/* 4418 */    MCD::OPC_Decode, 141, 2, 67, // Opcode: EXTRV_RS_W
/* 4422 */    MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 4440
/* 4426 */    MCD::OPC_CheckPredicate, 2, 126, 1, // Skip to: 4812
/* 4430 */    MCD::OPC_CheckField, 13, 3, 0, 120, 1, // Skip to: 4812
/* 4436 */    MCD::OPC_Decode, 138, 2, 66, // Opcode: EXTPDP
/* 4440 */    MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 4458
/* 4444 */    MCD::OPC_CheckPredicate, 2, 108, 1, // Skip to: 4812
/* 4448 */    MCD::OPC_CheckField, 13, 3, 0, 102, 1, // Skip to: 4812
/* 4454 */    MCD::OPC_Decode, 139, 2, 67, // Opcode: EXTPDPV
/* 4458 */    MCD::OPC_FilterValue, 14, 14, 0, // Skip to: 4476
/* 4462 */    MCD::OPC_CheckPredicate, 2, 90, 1, // Skip to: 4812
/* 4466 */    MCD::OPC_CheckField, 13, 3, 0, 84, 1, // Skip to: 4812
/* 4472 */    MCD::OPC_Decode, 147, 2, 66, // Opcode: EXTR_S_H
/* 4476 */    MCD::OPC_FilterValue, 15, 14, 0, // Skip to: 4494
/* 4480 */    MCD::OPC_CheckPredicate, 2, 72, 1, // Skip to: 4812
/* 4484 */    MCD::OPC_CheckField, 13, 3, 0, 66, 1, // Skip to: 4812
/* 4490 */    MCD::OPC_Decode, 143, 2, 67, // Opcode: EXTRV_S_H
/* 4494 */    MCD::OPC_FilterValue, 18, 8, 0, // Skip to: 4506
/* 4498 */    MCD::OPC_CheckPredicate, 2, 54, 1, // Skip to: 4812
/* 4502 */    MCD::OPC_Decode, 147, 4, 68, // Opcode: RDDSP
/* 4506 */    MCD::OPC_FilterValue, 19, 8, 0, // Skip to: 4518
/* 4510 */    MCD::OPC_CheckPredicate, 2, 42, 1, // Skip to: 4812
/* 4514 */    MCD::OPC_Decode, 185, 5, 69, // Opcode: WRDSP
/* 4518 */    MCD::OPC_FilterValue, 26, 14, 0, // Skip to: 4536
/* 4522 */    MCD::OPC_CheckPredicate, 2, 30, 1, // Skip to: 4812
/* 4526 */    MCD::OPC_CheckField, 13, 7, 0, 24, 1, // Skip to: 4812
/* 4532 */    MCD::OPC_Decode, 194, 4, 70, // Opcode: SHILO
/* 4536 */    MCD::OPC_FilterValue, 27, 14, 0, // Skip to: 4554
/* 4540 */    MCD::OPC_CheckPredicate, 2, 12, 1, // Skip to: 4812
/* 4544 */    MCD::OPC_CheckField, 13, 8, 0, 6, 1, // Skip to: 4812
/* 4550 */    MCD::OPC_Decode, 195, 4, 71, // Opcode: SHILOV
/* 4554 */    MCD::OPC_FilterValue, 31, 254, 0, // Skip to: 4812
/* 4558 */    MCD::OPC_CheckPredicate, 2, 250, 0, // Skip to: 4812
/* 4562 */    MCD::OPC_CheckField, 13, 8, 0, 244, 0, // Skip to: 4812
/* 4568 */    MCD::OPC_Decode, 204, 3, 71, // Opcode: MTHLIP
/* 4572 */    MCD::OPC_FilterValue, 59, 236, 0, // Skip to: 4812
/* 4576 */    MCD::OPC_CheckPredicate, 0, 232, 0, // Skip to: 4812
/* 4580 */    MCD::OPC_CheckField, 21, 5, 0, 226, 0, // Skip to: 4812
/* 4586 */    MCD::OPC_CheckField, 6, 5, 0, 220, 0, // Skip to: 4812
/* 4592 */    MCD::OPC_Decode, 148, 4, 72, // Opcode: RDHWR
/* 4596 */    MCD::OPC_FilterValue, 32, 8, 0, // Skip to: 4608
/* 4600 */    MCD::OPC_CheckPredicate, 15, 208, 0, // Skip to: 4812
/* 4604 */    MCD::OPC_Decode, 194, 2, 73, // Opcode: LB
/* 4608 */    MCD::OPC_FilterValue, 33, 8, 0, // Skip to: 4620
/* 4612 */    MCD::OPC_CheckPredicate, 15, 196, 0, // Skip to: 4812
/* 4616 */    MCD::OPC_Decode, 217, 2, 73, // Opcode: LH
/* 4620 */    MCD::OPC_FilterValue, 34, 8, 0, // Skip to: 4632
/* 4624 */    MCD::OPC_CheckPredicate, 15, 184, 0, // Skip to: 4812
/* 4628 */    MCD::OPC_Decode, 239, 2, 73, // Opcode: LWL
/* 4632 */    MCD::OPC_FilterValue, 35, 8, 0, // Skip to: 4644
/* 4636 */    MCD::OPC_CheckPredicate, 15, 172, 0, // Skip to: 4812
/* 4640 */    MCD::OPC_Decode, 234, 2, 73, // Opcode: LW
/* 4644 */    MCD::OPC_FilterValue, 36, 8, 0, // Skip to: 4656
/* 4648 */    MCD::OPC_CheckPredicate, 15, 160, 0, // Skip to: 4812
/* 4652 */    MCD::OPC_Decode, 199, 2, 73, // Opcode: LBu
/* 4656 */    MCD::OPC_FilterValue, 37, 8, 0, // Skip to: 4668
/* 4660 */    MCD::OPC_CheckPredicate, 15, 148, 0, // Skip to: 4812
/* 4664 */    MCD::OPC_Decode, 222, 2, 73, // Opcode: LHu
/* 4668 */    MCD::OPC_FilterValue, 38, 8, 0, // Skip to: 4680
/* 4672 */    MCD::OPC_CheckPredicate, 15, 136, 0, // Skip to: 4812
/* 4676 */    MCD::OPC_Decode, 243, 2, 73, // Opcode: LWR
/* 4680 */    MCD::OPC_FilterValue, 40, 8, 0, // Skip to: 4692
/* 4684 */    MCD::OPC_CheckPredicate, 15, 124, 0, // Skip to: 4812
/* 4688 */    MCD::OPC_Decode, 166, 4, 73, // Opcode: SB
/* 4692 */    MCD::OPC_FilterValue, 41, 8, 0, // Skip to: 4704
/* 4696 */    MCD::OPC_CheckPredicate, 15, 112, 0, // Skip to: 4812
/* 4700 */    MCD::OPC_Decode, 191, 4, 73, // Opcode: SH
/* 4704 */    MCD::OPC_FilterValue, 42, 8, 0, // Skip to: 4716
/* 4708 */    MCD::OPC_CheckPredicate, 15, 100, 0, // Skip to: 4812
/* 4712 */    MCD::OPC_Decode, 131, 5, 73, // Opcode: SWL
/* 4716 */    MCD::OPC_FilterValue, 43, 8, 0, // Skip to: 4728
/* 4720 */    MCD::OPC_CheckPredicate, 15, 88, 0, // Skip to: 4812
/* 4724 */    MCD::OPC_Decode, 254, 4, 73, // Opcode: SW
/* 4728 */    MCD::OPC_FilterValue, 46, 8, 0, // Skip to: 4740
/* 4732 */    MCD::OPC_CheckPredicate, 15, 76, 0, // Skip to: 4812
/* 4736 */    MCD::OPC_Decode, 135, 5, 73, // Opcode: SWR
/* 4740 */    MCD::OPC_FilterValue, 48, 8, 0, // Skip to: 4752
/* 4744 */    MCD::OPC_CheckPredicate, 15, 64, 0, // Skip to: 4812
/* 4748 */    MCD::OPC_Decode, 226, 2, 73, // Opcode: LL
/* 4752 */    MCD::OPC_FilterValue, 49, 8, 0, // Skip to: 4764
/* 4756 */    MCD::OPC_CheckPredicate, 15, 52, 0, // Skip to: 4812
/* 4760 */    MCD::OPC_Decode, 237, 2, 74, // Opcode: LWC1
/* 4764 */    MCD::OPC_FilterValue, 53, 8, 0, // Skip to: 4776
/* 4768 */    MCD::OPC_CheckPredicate, 16, 40, 0, // Skip to: 4812
/* 4772 */    MCD::OPC_Decode, 204, 2, 74, // Opcode: LDC1
/* 4776 */    MCD::OPC_FilterValue, 56, 8, 0, // Skip to: 4788
/* 4780 */    MCD::OPC_CheckPredicate, 15, 28, 0, // Skip to: 4812
/* 4784 */    MCD::OPC_Decode, 170, 4, 73, // Opcode: SC
/* 4788 */    MCD::OPC_FilterValue, 57, 8, 0, // Skip to: 4800
/* 4792 */    MCD::OPC_CheckPredicate, 15, 16, 0, // Skip to: 4812
/* 4796 */    MCD::OPC_Decode, 129, 5, 74, // Opcode: SWC1
/* 4800 */    MCD::OPC_FilterValue, 61, 8, 0, // Skip to: 4812
/* 4804 */    MCD::OPC_CheckPredicate, 16, 4, 0, // Skip to: 4812
/* 4808 */    MCD::OPC_Decode, 175, 4, 74, // Opcode: SDC1
/* 4812 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableOi6432[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 112, 2, // Skip to: 631
/* 7 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10 */      MCD::OPC_FilterValue, 1, 39, 0, // Skip to: 53
/* 14 */      MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 17 */      MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 35
/* 21 */      MCD::OPC_CheckPredicate, 17, 62, 8, // Skip to: 2135
/* 25 */      MCD::OPC_CheckField, 6, 5, 0, 56, 8, // Skip to: 2135
/* 31 */      MCD::OPC_Decode, 165, 3, 75, // Opcode: MOVF_I64
/* 35 */      MCD::OPC_FilterValue, 1, 48, 8, // Skip to: 2135
/* 39 */      MCD::OPC_CheckPredicate, 17, 44, 8, // Skip to: 2135
/* 43 */      MCD::OPC_CheckField, 6, 5, 0, 38, 8, // Skip to: 2135
/* 49 */      MCD::OPC_Decode, 179, 3, 75, // Opcode: MOVT_I64
/* 53 */      MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 71
/* 57 */      MCD::OPC_CheckPredicate, 0, 26, 8, // Skip to: 2135
/* 61 */      MCD::OPC_CheckField, 6, 15, 0, 20, 8, // Skip to: 2135
/* 67 */      MCD::OPC_Decode, 189, 2, 76, // Opcode: JR64
/* 71 */      MCD::OPC_FilterValue, 9, 15, 0, // Skip to: 90
/* 75 */      MCD::OPC_CheckPredicate, 0, 8, 8, // Skip to: 2135
/* 79 */      MCD::OPC_CheckField, 6, 15, 224, 7, 1, 8, // Skip to: 2135
/* 86 */      MCD::OPC_Decode, 187, 2, 76, // Opcode: JALR64
/* 90 */      MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 108
/* 94 */      MCD::OPC_CheckPredicate, 0, 245, 7, // Skip to: 2135
/* 98 */      MCD::OPC_CheckField, 6, 5, 0, 239, 7, // Skip to: 2135
/* 104 */     MCD::OPC_Decode, 188, 3, 77, // Opcode: MOVZ_I_I64
/* 108 */     MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 126
/* 112 */     MCD::OPC_CheckPredicate, 0, 227, 7, // Skip to: 2135
/* 116 */     MCD::OPC_CheckField, 6, 5, 0, 221, 7, // Skip to: 2135
/* 122 */     MCD::OPC_Decode, 174, 3, 77, // Opcode: MOVN_I_I64
/* 126 */     MCD::OPC_FilterValue, 16, 20, 0, // Skip to: 150
/* 130 */     MCD::OPC_CheckPredicate, 0, 209, 7, // Skip to: 2135
/* 134 */     MCD::OPC_CheckField, 16, 10, 0, 203, 7, // Skip to: 2135
/* 140 */     MCD::OPC_CheckField, 6, 5, 0, 197, 7, // Skip to: 2135
/* 146 */     MCD::OPC_Decode, 157, 3, 78, // Opcode: MFHI64
/* 150 */     MCD::OPC_FilterValue, 17, 14, 0, // Skip to: 168
/* 154 */     MCD::OPC_CheckPredicate, 0, 185, 7, // Skip to: 2135
/* 158 */     MCD::OPC_CheckField, 6, 15, 0, 179, 7, // Skip to: 2135
/* 164 */     MCD::OPC_Decode, 203, 3, 76, // Opcode: MTHI64
/* 168 */     MCD::OPC_FilterValue, 18, 20, 0, // Skip to: 192
/* 172 */     MCD::OPC_CheckPredicate, 0, 167, 7, // Skip to: 2135
/* 176 */     MCD::OPC_CheckField, 16, 10, 0, 161, 7, // Skip to: 2135
/* 182 */     MCD::OPC_CheckField, 6, 5, 0, 155, 7, // Skip to: 2135
/* 188 */     MCD::OPC_Decode, 159, 3, 78, // Opcode: MFLO64
/* 192 */     MCD::OPC_FilterValue, 19, 14, 0, // Skip to: 210
/* 196 */     MCD::OPC_CheckPredicate, 0, 143, 7, // Skip to: 2135
/* 200 */     MCD::OPC_CheckField, 6, 15, 0, 137, 7, // Skip to: 2135
/* 206 */     MCD::OPC_Decode, 207, 3, 76, // Opcode: MTLO64
/* 210 */     MCD::OPC_FilterValue, 20, 14, 0, // Skip to: 228
/* 214 */     MCD::OPC_CheckPredicate, 0, 125, 7, // Skip to: 2135
/* 218 */     MCD::OPC_CheckField, 6, 5, 0, 119, 7, // Skip to: 2135
/* 224 */     MCD::OPC_Decode, 253, 1, 79, // Opcode: DSLLV
/* 228 */     MCD::OPC_FilterValue, 22, 27, 0, // Skip to: 259
/* 232 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 235 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 247
/* 239 */     MCD::OPC_CheckPredicate, 0, 100, 7, // Skip to: 2135
/* 243 */     MCD::OPC_Decode, 131, 2, 79, // Opcode: DSRLV
/* 247 */     MCD::OPC_FilterValue, 1, 92, 7, // Skip to: 2135
/* 251 */     MCD::OPC_CheckPredicate, 18, 88, 7, // Skip to: 2135
/* 255 */     MCD::OPC_Decode, 246, 1, 79, // Opcode: DROTRV
/* 259 */     MCD::OPC_FilterValue, 23, 14, 0, // Skip to: 277
/* 263 */     MCD::OPC_CheckPredicate, 0, 76, 7, // Skip to: 2135
/* 267 */     MCD::OPC_CheckField, 6, 5, 0, 70, 7, // Skip to: 2135
/* 273 */     MCD::OPC_Decode, 128, 2, 79, // Opcode: DSRAV
/* 277 */     MCD::OPC_FilterValue, 28, 14, 0, // Skip to: 295
/* 281 */     MCD::OPC_CheckPredicate, 0, 58, 7, // Skip to: 2135
/* 285 */     MCD::OPC_CheckField, 6, 10, 0, 52, 7, // Skip to: 2135
/* 291 */     MCD::OPC_Decode, 211, 1, 80, // Opcode: DMULT
/* 295 */     MCD::OPC_FilterValue, 29, 14, 0, // Skip to: 313
/* 299 */     MCD::OPC_CheckPredicate, 0, 40, 7, // Skip to: 2135
/* 303 */     MCD::OPC_CheckField, 6, 10, 0, 34, 7, // Skip to: 2135
/* 309 */     MCD::OPC_Decode, 212, 1, 80, // Opcode: DMULTu
/* 313 */     MCD::OPC_FilterValue, 30, 14, 0, // Skip to: 331
/* 317 */     MCD::OPC_CheckPredicate, 0, 22, 7, // Skip to: 2135
/* 321 */     MCD::OPC_CheckField, 6, 10, 0, 16, 7, // Skip to: 2135
/* 327 */     MCD::OPC_Decode, 248, 1, 80, // Opcode: DSDIV
/* 331 */     MCD::OPC_FilterValue, 31, 14, 0, // Skip to: 349
/* 335 */     MCD::OPC_CheckPredicate, 0, 4, 7, // Skip to: 2135
/* 339 */     MCD::OPC_CheckField, 6, 10, 0, 254, 6, // Skip to: 2135
/* 345 */     MCD::OPC_Decode, 133, 2, 80, // Opcode: DUDIV
/* 349 */     MCD::OPC_FilterValue, 36, 13, 0, // Skip to: 366
/* 353 */     MCD::OPC_CheckPredicate, 0, 242, 6, // Skip to: 2135
/* 357 */     MCD::OPC_CheckField, 6, 5, 0, 236, 6, // Skip to: 2135
/* 363 */     MCD::OPC_Decode, 42, 81, // Opcode: AND64
/* 366 */     MCD::OPC_FilterValue, 37, 14, 0, // Skip to: 384
/* 370 */     MCD::OPC_CheckPredicate, 0, 225, 6, // Skip to: 2135
/* 374 */     MCD::OPC_CheckField, 6, 5, 0, 219, 6, // Skip to: 2135
/* 380 */     MCD::OPC_Decode, 249, 3, 81, // Opcode: OR64
/* 384 */     MCD::OPC_FilterValue, 38, 14, 0, // Skip to: 402
/* 388 */     MCD::OPC_CheckPredicate, 0, 207, 6, // Skip to: 2135
/* 392 */     MCD::OPC_CheckField, 6, 5, 0, 201, 6, // Skip to: 2135
/* 398 */     MCD::OPC_Decode, 188, 5, 81, // Opcode: XOR64
/* 402 */     MCD::OPC_FilterValue, 39, 14, 0, // Skip to: 420
/* 406 */     MCD::OPC_CheckPredicate, 0, 189, 6, // Skip to: 2135
/* 410 */     MCD::OPC_CheckField, 6, 5, 0, 183, 6, // Skip to: 2135
/* 416 */     MCD::OPC_Decode, 245, 3, 81, // Opcode: NOR64
/* 420 */     MCD::OPC_FilterValue, 42, 14, 0, // Skip to: 438
/* 424 */     MCD::OPC_CheckPredicate, 0, 171, 6, // Skip to: 2135
/* 428 */     MCD::OPC_CheckField, 6, 5, 0, 165, 6, // Skip to: 2135
/* 434 */     MCD::OPC_Decode, 226, 4, 82, // Opcode: SLT64
/* 438 */     MCD::OPC_FilterValue, 43, 14, 0, // Skip to: 456
/* 442 */     MCD::OPC_CheckPredicate, 0, 153, 6, // Skip to: 2135
/* 446 */     MCD::OPC_CheckField, 6, 5, 0, 147, 6, // Skip to: 2135
/* 452 */     MCD::OPC_Decode, 232, 4, 82, // Opcode: SLTu64
/* 456 */     MCD::OPC_FilterValue, 44, 14, 0, // Skip to: 474
/* 460 */     MCD::OPC_CheckPredicate, 0, 135, 6, // Skip to: 2135
/* 464 */     MCD::OPC_CheckField, 6, 5, 0, 129, 6, // Skip to: 2135
/* 470 */     MCD::OPC_Decode, 192, 1, 81, // Opcode: DADD
/* 474 */     MCD::OPC_FilterValue, 45, 14, 0, // Skip to: 492
/* 478 */     MCD::OPC_CheckPredicate, 0, 117, 6, // Skip to: 2135
/* 482 */     MCD::OPC_CheckField, 6, 5, 0, 111, 6, // Skip to: 2135
/* 488 */     MCD::OPC_Decode, 195, 1, 81, // Opcode: DADDu
/* 492 */     MCD::OPC_FilterValue, 47, 14, 0, // Skip to: 510
/* 496 */     MCD::OPC_CheckPredicate, 0, 99, 6, // Skip to: 2135
/* 500 */     MCD::OPC_CheckField, 6, 5, 0, 93, 6, // Skip to: 2135
/* 506 */     MCD::OPC_Decode, 132, 2, 81, // Opcode: DSUBu
/* 510 */     MCD::OPC_FilterValue, 56, 14, 0, // Skip to: 528
/* 514 */     MCD::OPC_CheckPredicate, 0, 81, 6, // Skip to: 2135
/* 518 */     MCD::OPC_CheckField, 21, 5, 0, 75, 6, // Skip to: 2135
/* 524 */     MCD::OPC_Decode, 250, 1, 83, // Opcode: DSLL
/* 528 */     MCD::OPC_FilterValue, 58, 27, 0, // Skip to: 559
/* 532 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 535 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 547
/* 539 */     MCD::OPC_CheckPredicate, 0, 56, 6, // Skip to: 2135
/* 543 */     MCD::OPC_Decode, 129, 2, 83, // Opcode: DSRL
/* 547 */     MCD::OPC_FilterValue, 1, 48, 6, // Skip to: 2135
/* 551 */     MCD::OPC_CheckPredicate, 18, 44, 6, // Skip to: 2135
/* 555 */     MCD::OPC_Decode, 245, 1, 83, // Opcode: DROTR
/* 559 */     MCD::OPC_FilterValue, 59, 14, 0, // Skip to: 577
/* 563 */     MCD::OPC_CheckPredicate, 0, 32, 6, // Skip to: 2135
/* 567 */     MCD::OPC_CheckField, 21, 5, 0, 26, 6, // Skip to: 2135
/* 573 */     MCD::OPC_Decode, 254, 1, 83, // Opcode: DSRA
/* 577 */     MCD::OPC_FilterValue, 60, 14, 0, // Skip to: 595
/* 581 */     MCD::OPC_CheckPredicate, 0, 14, 6, // Skip to: 2135
/* 585 */     MCD::OPC_CheckField, 21, 5, 0, 8, 6, // Skip to: 2135
/* 591 */     MCD::OPC_Decode, 251, 1, 83, // Opcode: DSLL32
/* 595 */     MCD::OPC_FilterValue, 62, 14, 0, // Skip to: 613
/* 599 */     MCD::OPC_CheckPredicate, 0, 252, 5, // Skip to: 2135
/* 603 */     MCD::OPC_CheckField, 21, 5, 0, 246, 5, // Skip to: 2135
/* 609 */     MCD::OPC_Decode, 130, 2, 83, // Opcode: DSRL32
/* 613 */     MCD::OPC_FilterValue, 63, 238, 5, // Skip to: 2135
/* 617 */     MCD::OPC_CheckPredicate, 0, 234, 5, // Skip to: 2135
/* 621 */     MCD::OPC_CheckField, 21, 5, 0, 228, 5, // Skip to: 2135
/* 627 */     MCD::OPC_Decode, 255, 1, 83, // Opcode: DSRA32
/* 631 */     MCD::OPC_FilterValue, 1, 26, 0, // Skip to: 661
/* 635 */     MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 638 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 650
/* 642 */     MCD::OPC_CheckPredicate, 0, 209, 5, // Skip to: 2135
/* 646 */     MCD::OPC_Decode, 132, 1, 84, // Opcode: BLTZ64
/* 650 */     MCD::OPC_FilterValue, 1, 201, 5, // Skip to: 2135
/* 654 */     MCD::OPC_CheckPredicate, 0, 197, 5, // Skip to: 2135
/* 658 */     MCD::OPC_Decode, 124, 84, // Opcode: BGEZ64
/* 661 */     MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 672
/* 665 */     MCD::OPC_CheckPredicate, 0, 186, 5, // Skip to: 2135
/* 669 */     MCD::OPC_Decode, 122, 85, // Opcode: BEQ64
/* 672 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 684
/* 676 */     MCD::OPC_CheckPredicate, 0, 175, 5, // Skip to: 2135
/* 680 */     MCD::OPC_Decode, 135, 1, 85, // Opcode: BNE64
/* 684 */     MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 702
/* 688 */     MCD::OPC_CheckPredicate, 0, 163, 5, // Skip to: 2135
/* 692 */     MCD::OPC_CheckField, 16, 5, 0, 157, 5, // Skip to: 2135
/* 698 */     MCD::OPC_Decode, 130, 1, 84, // Opcode: BLEZ64
/* 702 */     MCD::OPC_FilterValue, 7, 13, 0, // Skip to: 719
/* 706 */     MCD::OPC_CheckPredicate, 0, 145, 5, // Skip to: 2135
/* 710 */     MCD::OPC_CheckField, 16, 5, 0, 139, 5, // Skip to: 2135
/* 716 */     MCD::OPC_Decode, 127, 84, // Opcode: BGTZ64
/* 719 */     MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 731
/* 723 */     MCD::OPC_CheckPredicate, 0, 128, 5, // Skip to: 2135
/* 727 */     MCD::OPC_Decode, 228, 4, 86, // Opcode: SLTi64
/* 731 */     MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 743
/* 735 */     MCD::OPC_CheckPredicate, 0, 116, 5, // Skip to: 2135
/* 739 */     MCD::OPC_Decode, 230, 4, 86, // Opcode: SLTiu64
/* 743 */     MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 755
/* 747 */     MCD::OPC_CheckPredicate, 0, 104, 5, // Skip to: 2135
/* 751 */     MCD::OPC_Decode, 196, 1, 87, // Opcode: DANDi
/* 755 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 767
/* 759 */     MCD::OPC_CheckPredicate, 0, 92, 5, // Skip to: 2135
/* 763 */     MCD::OPC_Decode, 251, 3, 87, // Opcode: ORi64
/* 767 */     MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 779
/* 771 */     MCD::OPC_CheckPredicate, 0, 80, 5, // Skip to: 2135
/* 775 */     MCD::OPC_Decode, 190, 5, 87, // Opcode: XORi64
/* 779 */     MCD::OPC_FilterValue, 15, 14, 0, // Skip to: 797
/* 783 */     MCD::OPC_CheckPredicate, 0, 68, 5, // Skip to: 2135
/* 787 */     MCD::OPC_CheckField, 21, 5, 0, 62, 5, // Skip to: 2135
/* 793 */     MCD::OPC_Decode, 233, 2, 88, // Opcode: LUi64
/* 797 */     MCD::OPC_FilterValue, 16, 39, 0, // Skip to: 840
/* 801 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 804 */     MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 822
/* 808 */     MCD::OPC_CheckPredicate, 0, 43, 5, // Skip to: 2135
/* 812 */     MCD::OPC_CheckField, 3, 8, 0, 37, 5, // Skip to: 2135
/* 818 */     MCD::OPC_Decode, 205, 1, 89, // Opcode: DMFC0_3OP64
/* 822 */     MCD::OPC_FilterValue, 5, 29, 5, // Skip to: 2135
/* 826 */     MCD::OPC_CheckPredicate, 0, 25, 5, // Skip to: 2135
/* 830 */     MCD::OPC_CheckField, 3, 8, 0, 19, 5, // Skip to: 2135
/* 836 */     MCD::OPC_Decode, 208, 1, 90, // Opcode: DMTC0_3OP64
/* 840 */     MCD::OPC_FilterValue, 17, 89, 2, // Skip to: 1445
/* 844 */     MCD::OPC_ExtractField, 4, 2,  // Inst{5-4} ...
/* 847 */     MCD::OPC_FilterValue, 0, 103, 1, // Skip to: 1210
/* 851 */     MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 854 */     MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 872
/* 858 */     MCD::OPC_CheckPredicate, 19, 249, 4, // Skip to: 2135
/* 862 */     MCD::OPC_CheckField, 21, 5, 17, 243, 4, // Skip to: 2135
/* 868 */     MCD::OPC_Decode, 154, 2, 91, // Opcode: FADD_D64
/* 872 */     MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 890
/* 876 */     MCD::OPC_CheckPredicate, 19, 231, 4, // Skip to: 2135
/* 880 */     MCD::OPC_CheckField, 21, 5, 17, 225, 4, // Skip to: 2135
/* 886 */     MCD::OPC_Decode, 180, 2, 91, // Opcode: FSUB_D64
/* 890 */     MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 908
/* 894 */     MCD::OPC_CheckPredicate, 19, 213, 4, // Skip to: 2135
/* 898 */     MCD::OPC_CheckField, 21, 5, 17, 207, 4, // Skip to: 2135
/* 904 */     MCD::OPC_Decode, 171, 2, 91, // Opcode: FMUL_D64
/* 908 */     MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 926
/* 912 */     MCD::OPC_CheckPredicate, 19, 195, 4, // Skip to: 2135
/* 916 */     MCD::OPC_CheckField, 21, 5, 17, 189, 4, // Skip to: 2135
/* 922 */     MCD::OPC_Decode, 160, 2, 91, // Opcode: FDIV_D64
/* 926 */     MCD::OPC_FilterValue, 4, 15, 0, // Skip to: 945
/* 930 */     MCD::OPC_CheckPredicate, 19, 177, 4, // Skip to: 2135
/* 934 */     MCD::OPC_CheckField, 16, 10, 160, 4, 170, 4, // Skip to: 2135
/* 941 */     MCD::OPC_Decode, 177, 2, 38, // Opcode: FSQRT_D64
/* 945 */     MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 964
/* 949 */     MCD::OPC_CheckPredicate, 3, 158, 4, // Skip to: 2135
/* 953 */     MCD::OPC_CheckField, 16, 10, 160, 4, 151, 4, // Skip to: 2135
/* 960 */     MCD::OPC_Decode, 151, 2, 38, // Opcode: FABS_D64
/* 964 */     MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 983
/* 968 */     MCD::OPC_CheckPredicate, 19, 139, 4, // Skip to: 2135
/* 972 */     MCD::OPC_CheckField, 16, 10, 160, 4, 132, 4, // Skip to: 2135
/* 979 */     MCD::OPC_Decode, 168, 2, 38, // Opcode: FMOV_D64
/* 983 */     MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 1002
/* 987 */     MCD::OPC_CheckPredicate, 3, 120, 4, // Skip to: 2135
/* 991 */     MCD::OPC_CheckField, 16, 10, 160, 4, 113, 4, // Skip to: 2135
/* 998 */     MCD::OPC_Decode, 174, 2, 38, // Opcode: FNEG_D64
/* 1002 */    MCD::OPC_FilterValue, 8, 29, 0, // Skip to: 1035
/* 1006 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 1009 */    MCD::OPC_FilterValue, 128, 4, 8, 0, // Skip to: 1022
/* 1014 */    MCD::OPC_CheckPredicate, 19, 93, 4, // Skip to: 2135
/* 1018 */    MCD::OPC_Decode, 158, 4, 31, // Opcode: ROUND_L_S
/* 1022 */    MCD::OPC_FilterValue, 160, 4, 84, 4, // Skip to: 2135
/* 1027 */    MCD::OPC_CheckPredicate, 19, 80, 4, // Skip to: 2135
/* 1031 */    MCD::OPC_Decode, 157, 4, 38, // Opcode: ROUND_L_D64
/* 1035 */    MCD::OPC_FilterValue, 9, 29, 0, // Skip to: 1068
/* 1039 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 1042 */    MCD::OPC_FilterValue, 128, 4, 8, 0, // Skip to: 1055
/* 1047 */    MCD::OPC_CheckPredicate, 19, 60, 4, // Skip to: 2135
/* 1051 */    MCD::OPC_Decode, 180, 5, 31, // Opcode: TRUNC_L_S
/* 1055 */    MCD::OPC_FilterValue, 160, 4, 51, 4, // Skip to: 2135
/* 1060 */    MCD::OPC_CheckPredicate, 19, 47, 4, // Skip to: 2135
/* 1064 */    MCD::OPC_Decode, 179, 5, 38, // Opcode: TRUNC_L_D64
/* 1068 */    MCD::OPC_FilterValue, 10, 29, 0, // Skip to: 1101
/* 1072 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 1075 */    MCD::OPC_FilterValue, 128, 4, 8, 0, // Skip to: 1088
/* 1080 */    MCD::OPC_CheckPredicate, 19, 27, 4, // Skip to: 2135
/* 1084 */    MCD::OPC_Decode, 157, 1, 31, // Opcode: CEIL_L_S
/* 1088 */    MCD::OPC_FilterValue, 160, 4, 18, 4, // Skip to: 2135
/* 1093 */    MCD::OPC_CheckPredicate, 19, 14, 4, // Skip to: 2135
/* 1097 */    MCD::OPC_Decode, 156, 1, 38, // Opcode: CEIL_L_D64
/* 1101 */    MCD::OPC_FilterValue, 11, 29, 0, // Skip to: 1134
/* 1105 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 1108 */    MCD::OPC_FilterValue, 128, 4, 8, 0, // Skip to: 1121
/* 1113 */    MCD::OPC_CheckPredicate, 19, 250, 3, // Skip to: 2135
/* 1117 */    MCD::OPC_Decode, 163, 2, 31, // Opcode: FLOOR_L_S
/* 1121 */    MCD::OPC_FilterValue, 160, 4, 241, 3, // Skip to: 2135
/* 1126 */    MCD::OPC_CheckPredicate, 19, 237, 3, // Skip to: 2135
/* 1130 */    MCD::OPC_Decode, 162, 2, 38, // Opcode: FLOOR_L_D64
/* 1134 */    MCD::OPC_FilterValue, 12, 15, 0, // Skip to: 1153
/* 1138 */    MCD::OPC_CheckPredicate, 19, 225, 3, // Skip to: 2135
/* 1142 */    MCD::OPC_CheckField, 16, 10, 160, 4, 218, 3, // Skip to: 2135
/* 1149 */    MCD::OPC_Decode, 160, 4, 92, // Opcode: ROUND_W_D64
/* 1153 */    MCD::OPC_FilterValue, 13, 15, 0, // Skip to: 1172
/* 1157 */    MCD::OPC_CheckPredicate, 19, 206, 3, // Skip to: 2135
/* 1161 */    MCD::OPC_CheckField, 16, 10, 160, 4, 199, 3, // Skip to: 2135
/* 1168 */    MCD::OPC_Decode, 182, 5, 92, // Opcode: TRUNC_W_D64
/* 1172 */    MCD::OPC_FilterValue, 14, 15, 0, // Skip to: 1191
/* 1176 */    MCD::OPC_CheckPredicate, 19, 187, 3, // Skip to: 2135
/* 1180 */    MCD::OPC_CheckField, 16, 10, 160, 4, 180, 3, // Skip to: 2135
/* 1187 */    MCD::OPC_Decode, 159, 1, 92, // Opcode: CEIL_W_D64
/* 1191 */    MCD::OPC_FilterValue, 15, 172, 3, // Skip to: 2135
/* 1195 */    MCD::OPC_CheckPredicate, 19, 168, 3, // Skip to: 2135
/* 1199 */    MCD::OPC_CheckField, 16, 10, 160, 4, 161, 3, // Skip to: 2135
/* 1206 */    MCD::OPC_Decode, 165, 2, 92, // Opcode: FLOOR_W_D64
/* 1210 */    MCD::OPC_FilterValue, 1, 98, 0, // Skip to: 1312
/* 1214 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1217 */    MCD::OPC_FilterValue, 1, 29, 0, // Skip to: 1250
/* 1221 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 1224 */    MCD::OPC_FilterValue, 160, 4, 8, 0, // Skip to: 1237
/* 1229 */    MCD::OPC_CheckPredicate, 19, 134, 3, // Skip to: 2135
/* 1233 */    MCD::OPC_Decode, 163, 3, 93, // Opcode: MOVF_D64
/* 1237 */    MCD::OPC_FilterValue, 161, 4, 125, 3, // Skip to: 2135
/* 1242 */    MCD::OPC_CheckPredicate, 19, 121, 3, // Skip to: 2135
/* 1246 */    MCD::OPC_Decode, 177, 3, 93, // Opcode: MOVT_D64
/* 1250 */    MCD::OPC_FilterValue, 2, 27, 0, // Skip to: 1281
/* 1254 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1257 */    MCD::OPC_FilterValue, 16, 8, 0, // Skip to: 1269
/* 1261 */    MCD::OPC_CheckPredicate, 17, 102, 3, // Skip to: 2135
/* 1265 */    MCD::OPC_Decode, 184, 3, 94, // Opcode: MOVZ_I64_S
/* 1269 */    MCD::OPC_FilterValue, 17, 94, 3, // Skip to: 2135
/* 1273 */    MCD::OPC_CheckPredicate, 19, 90, 3, // Skip to: 2135
/* 1277 */    MCD::OPC_Decode, 186, 3, 95, // Opcode: MOVZ_I_D64
/* 1281 */    MCD::OPC_FilterValue, 3, 82, 3, // Skip to: 2135
/* 1285 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1288 */    MCD::OPC_FilterValue, 16, 8, 0, // Skip to: 1300
/* 1292 */    MCD::OPC_CheckPredicate, 17, 71, 3, // Skip to: 2135
/* 1296 */    MCD::OPC_Decode, 170, 3, 94, // Opcode: MOVN_I64_S
/* 1300 */    MCD::OPC_FilterValue, 17, 63, 3, // Skip to: 2135
/* 1304 */    MCD::OPC_CheckPredicate, 19, 59, 3, // Skip to: 2135
/* 1308 */    MCD::OPC_Decode, 172, 3, 95, // Opcode: MOVN_I_D64
/* 1312 */    MCD::OPC_FilterValue, 2, 105, 0, // Skip to: 1421
/* 1316 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 1319 */    MCD::OPC_FilterValue, 128, 4, 14, 0, // Skip to: 1338
/* 1324 */    MCD::OPC_CheckPredicate, 19, 39, 3, // Skip to: 2135
/* 1328 */    MCD::OPC_CheckField, 0, 4, 1, 33, 3, // Skip to: 2135
/* 1334 */    MCD::OPC_Decode, 180, 1, 31, // Opcode: CVT_D64_S
/* 1338 */    MCD::OPC_FilterValue, 160, 4, 27, 0, // Skip to: 1370
/* 1343 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1346 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1358
/* 1350 */    MCD::OPC_CheckPredicate, 19, 13, 3, // Skip to: 2135
/* 1354 */    MCD::OPC_Decode, 185, 1, 92, // Opcode: CVT_S_D64
/* 1358 */    MCD::OPC_FilterValue, 4, 5, 3, // Skip to: 2135
/* 1362 */    MCD::OPC_CheckPredicate, 19, 1, 3, // Skip to: 2135
/* 1366 */    MCD::OPC_Decode, 189, 1, 92, // Opcode: CVT_W_D64
/* 1370 */    MCD::OPC_FilterValue, 128, 5, 14, 0, // Skip to: 1389
/* 1375 */    MCD::OPC_CheckPredicate, 19, 244, 2, // Skip to: 2135
/* 1379 */    MCD::OPC_CheckField, 0, 4, 1, 238, 2, // Skip to: 2135
/* 1385 */    MCD::OPC_Decode, 181, 1, 31, // Opcode: CVT_D64_W
/* 1389 */    MCD::OPC_FilterValue, 160, 5, 229, 2, // Skip to: 2135
/* 1394 */    MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 1397 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1409
/* 1401 */    MCD::OPC_CheckPredicate, 19, 218, 2, // Skip to: 2135
/* 1405 */    MCD::OPC_Decode, 186, 1, 92, // Opcode: CVT_S_L
/* 1409 */    MCD::OPC_FilterValue, 1, 210, 2, // Skip to: 2135
/* 1413 */    MCD::OPC_CheckPredicate, 19, 206, 2, // Skip to: 2135
/* 1417 */    MCD::OPC_Decode, 179, 1, 38, // Opcode: CVT_D64_L
/* 1421 */    MCD::OPC_FilterValue, 3, 198, 2, // Skip to: 2135
/* 1425 */    MCD::OPC_CheckPredicate, 19, 194, 2, // Skip to: 2135
/* 1429 */    MCD::OPC_CheckField, 21, 5, 17, 188, 2, // Skip to: 2135
/* 1435 */    MCD::OPC_CheckField, 6, 5, 0, 182, 2, // Skip to: 2135
/* 1441 */    MCD::OPC_Decode, 157, 2, 96, // Opcode: FCMP_D64
/* 1445 */    MCD::OPC_FilterValue, 18, 39, 0, // Skip to: 1488
/* 1449 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1452 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1470
/* 1456 */    MCD::OPC_CheckPredicate, 0, 163, 2, // Skip to: 2135
/* 1460 */    MCD::OPC_CheckField, 3, 8, 0, 157, 2, // Skip to: 2135
/* 1466 */    MCD::OPC_Decode, 207, 1, 89, // Opcode: DMFC2_3OP64
/* 1470 */    MCD::OPC_FilterValue, 5, 149, 2, // Skip to: 2135
/* 1474 */    MCD::OPC_CheckPredicate, 0, 145, 2, // Skip to: 2135
/* 1478 */    MCD::OPC_CheckField, 3, 8, 0, 139, 2, // Skip to: 2135
/* 1484 */    MCD::OPC_Decode, 210, 1, 90, // Opcode: DMTC2_3OP64
/* 1488 */    MCD::OPC_FilterValue, 19, 75, 0, // Skip to: 1567
/* 1492 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1495 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1513
/* 1499 */    MCD::OPC_CheckPredicate, 20, 120, 2, // Skip to: 2135
/* 1503 */    MCD::OPC_CheckField, 11, 5, 0, 114, 2, // Skip to: 2135
/* 1509 */    MCD::OPC_Decode, 212, 2, 97, // Opcode: LDXC164
/* 1513 */    MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 1531
/* 1517 */    MCD::OPC_CheckPredicate, 17, 102, 2, // Skip to: 2135
/* 1521 */    MCD::OPC_CheckField, 11, 5, 0, 96, 2, // Skip to: 2135
/* 1527 */    MCD::OPC_Decode, 231, 2, 97, // Opcode: LUXC164
/* 1531 */    MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 1549
/* 1535 */    MCD::OPC_CheckPredicate, 20, 84, 2, // Skip to: 2135
/* 1539 */    MCD::OPC_CheckField, 6, 5, 0, 78, 2, // Skip to: 2135
/* 1545 */    MCD::OPC_Decode, 184, 4, 98, // Opcode: SDXC164
/* 1549 */    MCD::OPC_FilterValue, 13, 70, 2, // Skip to: 2135
/* 1553 */    MCD::OPC_CheckPredicate, 17, 66, 2, // Skip to: 2135
/* 1557 */    MCD::OPC_CheckField, 6, 5, 0, 60, 2, // Skip to: 2135
/* 1563 */    MCD::OPC_Decode, 253, 4, 98, // Opcode: SUXC164
/* 1567 */    MCD::OPC_FilterValue, 24, 8, 0, // Skip to: 1579
/* 1571 */    MCD::OPC_CheckPredicate, 0, 48, 2, // Skip to: 2135
/* 1575 */    MCD::OPC_Decode, 193, 1, 87, // Opcode: DADDi
/* 1579 */    MCD::OPC_FilterValue, 25, 8, 0, // Skip to: 1591
/* 1583 */    MCD::OPC_CheckPredicate, 0, 36, 2, // Skip to: 2135
/* 1587 */    MCD::OPC_Decode, 194, 1, 87, // Opcode: DADDiu
/* 1591 */    MCD::OPC_FilterValue, 26, 8, 0, // Skip to: 1603
/* 1595 */    MCD::OPC_CheckPredicate, 15, 24, 2, // Skip to: 2135
/* 1599 */    MCD::OPC_Decode, 207, 2, 73, // Opcode: LDL
/* 1603 */    MCD::OPC_FilterValue, 27, 8, 0, // Skip to: 1615
/* 1607 */    MCD::OPC_CheckPredicate, 15, 12, 2, // Skip to: 2135
/* 1611 */    MCD::OPC_Decode, 209, 2, 73, // Opcode: LDR
/* 1615 */    MCD::OPC_FilterValue, 28, 27, 0, // Skip to: 1646
/* 1619 */    MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 1622 */    MCD::OPC_FilterValue, 36, 8, 0, // Skip to: 1634
/* 1626 */    MCD::OPC_CheckPredicate, 11, 249, 1, // Skip to: 2135
/* 1630 */    MCD::OPC_Decode, 198, 1, 99, // Opcode: DCLZ
/* 1634 */    MCD::OPC_FilterValue, 37, 241, 1, // Skip to: 2135
/* 1638 */    MCD::OPC_CheckPredicate, 11, 237, 1, // Skip to: 2135
/* 1642 */    MCD::OPC_Decode, 197, 1, 99, // Opcode: DCLO
/* 1646 */    MCD::OPC_FilterValue, 31, 185, 0, // Skip to: 1835
/* 1650 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1653 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1665
/* 1657 */    MCD::OPC_CheckPredicate, 1, 218, 1, // Skip to: 2135
/* 1661 */    MCD::OPC_Decode, 200, 1, 100, // Opcode: DEXTM
/* 1665 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1677
/* 1669 */    MCD::OPC_CheckPredicate, 1, 206, 1, // Skip to: 2135
/* 1673 */    MCD::OPC_Decode, 201, 1, 100, // Opcode: DEXTU
/* 1677 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1689
/* 1681 */    MCD::OPC_CheckPredicate, 1, 194, 1, // Skip to: 2135
/* 1685 */    MCD::OPC_Decode, 199, 1, 100, // Opcode: DEXT
/* 1689 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 1701
/* 1693 */    MCD::OPC_CheckPredicate, 1, 182, 1, // Skip to: 2135
/* 1697 */    MCD::OPC_Decode, 203, 1, 101, // Opcode: DINSM
/* 1701 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 1713
/* 1705 */    MCD::OPC_CheckPredicate, 1, 170, 1, // Skip to: 2135
/* 1709 */    MCD::OPC_Decode, 204, 1, 101, // Opcode: DINSU
/* 1713 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 1725
/* 1717 */    MCD::OPC_CheckPredicate, 1, 158, 1, // Skip to: 2135
/* 1721 */    MCD::OPC_Decode, 202, 1, 101, // Opcode: DINS
/* 1725 */    MCD::OPC_FilterValue, 32, 39, 0, // Skip to: 1768
/* 1729 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1732 */    MCD::OPC_FilterValue, 16, 14, 0, // Skip to: 1750
/* 1736 */    MCD::OPC_CheckPredicate, 14, 139, 1, // Skip to: 2135
/* 1740 */    MCD::OPC_CheckField, 21, 5, 0, 133, 1, // Skip to: 2135
/* 1746 */    MCD::OPC_Decode, 188, 4, 102, // Opcode: SEB64
/* 1750 */    MCD::OPC_FilterValue, 24, 125, 1, // Skip to: 2135
/* 1754 */    MCD::OPC_CheckPredicate, 14, 121, 1, // Skip to: 2135
/* 1758 */    MCD::OPC_CheckField, 21, 5, 0, 115, 1, // Skip to: 2135
/* 1764 */    MCD::OPC_Decode, 190, 4, 102, // Opcode: SEH64
/* 1768 */    MCD::OPC_FilterValue, 36, 39, 0, // Skip to: 1811
/* 1772 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1775 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 1793
/* 1779 */    MCD::OPC_CheckPredicate, 13, 96, 1, // Skip to: 2135
/* 1783 */    MCD::OPC_CheckField, 21, 5, 0, 90, 1, // Skip to: 2135
/* 1789 */    MCD::OPC_Decode, 247, 1, 102, // Opcode: DSBH
/* 1793 */    MCD::OPC_FilterValue, 5, 82, 1, // Skip to: 2135
/* 1797 */    MCD::OPC_CheckPredicate, 13, 78, 1, // Skip to: 2135
/* 1801 */    MCD::OPC_CheckField, 21, 5, 0, 72, 1, // Skip to: 2135
/* 1807 */    MCD::OPC_Decode, 249, 1, 102, // Opcode: DSHD
/* 1811 */    MCD::OPC_FilterValue, 59, 64, 1, // Skip to: 2135
/* 1815 */    MCD::OPC_CheckPredicate, 0, 60, 1, // Skip to: 2135
/* 1819 */    MCD::OPC_CheckField, 21, 5, 0, 54, 1, // Skip to: 2135
/* 1825 */    MCD::OPC_CheckField, 6, 5, 0, 48, 1, // Skip to: 2135
/* 1831 */    MCD::OPC_Decode, 149, 4, 103, // Opcode: RDHWR64
/* 1835 */    MCD::OPC_FilterValue, 32, 8, 0, // Skip to: 1847
/* 1839 */    MCD::OPC_CheckPredicate, 15, 36, 1, // Skip to: 2135
/* 1843 */    MCD::OPC_Decode, 195, 2, 73, // Opcode: LB64
/* 1847 */    MCD::OPC_FilterValue, 33, 8, 0, // Skip to: 1859
/* 1851 */    MCD::OPC_CheckPredicate, 15, 24, 1, // Skip to: 2135
/* 1855 */    MCD::OPC_Decode, 218, 2, 73, // Opcode: LH64
/* 1859 */    MCD::OPC_FilterValue, 34, 8, 0, // Skip to: 1871
/* 1863 */    MCD::OPC_CheckPredicate, 15, 12, 1, // Skip to: 2135
/* 1867 */    MCD::OPC_Decode, 240, 2, 73, // Opcode: LWL64
/* 1871 */    MCD::OPC_FilterValue, 35, 8, 0, // Skip to: 1883
/* 1875 */    MCD::OPC_CheckPredicate, 15, 0, 1, // Skip to: 2135
/* 1879 */    MCD::OPC_Decode, 235, 2, 73, // Opcode: LW64
/* 1883 */    MCD::OPC_FilterValue, 36, 8, 0, // Skip to: 1895
/* 1887 */    MCD::OPC_CheckPredicate, 15, 244, 0, // Skip to: 2135
/* 1891 */    MCD::OPC_Decode, 200, 2, 73, // Opcode: LBu64
/* 1895 */    MCD::OPC_FilterValue, 37, 8, 0, // Skip to: 1907
/* 1899 */    MCD::OPC_CheckPredicate, 15, 232, 0, // Skip to: 2135
/* 1903 */    MCD::OPC_Decode, 223, 2, 73, // Opcode: LHu64
/* 1907 */    MCD::OPC_FilterValue, 38, 8, 0, // Skip to: 1919
/* 1911 */    MCD::OPC_CheckPredicate, 15, 220, 0, // Skip to: 2135
/* 1915 */    MCD::OPC_Decode, 244, 2, 73, // Opcode: LWR64
/* 1919 */    MCD::OPC_FilterValue, 39, 8, 0, // Skip to: 1931
/* 1923 */    MCD::OPC_CheckPredicate, 15, 208, 0, // Skip to: 2135
/* 1927 */    MCD::OPC_Decode, 251, 2, 73, // Opcode: LWu64
/* 1931 */    MCD::OPC_FilterValue, 40, 8, 0, // Skip to: 1943
/* 1935 */    MCD::OPC_CheckPredicate, 15, 196, 0, // Skip to: 2135
/* 1939 */    MCD::OPC_Decode, 167, 4, 73, // Opcode: SB64
/* 1943 */    MCD::OPC_FilterValue, 41, 8, 0, // Skip to: 1955
/* 1947 */    MCD::OPC_CheckPredicate, 15, 184, 0, // Skip to: 2135
/* 1951 */    MCD::OPC_Decode, 192, 4, 73, // Opcode: SH64
/* 1955 */    MCD::OPC_FilterValue, 42, 8, 0, // Skip to: 1967
/* 1959 */    MCD::OPC_CheckPredicate, 15, 172, 0, // Skip to: 2135
/* 1963 */    MCD::OPC_Decode, 132, 5, 73, // Opcode: SWL64
/* 1967 */    MCD::OPC_FilterValue, 43, 8, 0, // Skip to: 1979
/* 1971 */    MCD::OPC_CheckPredicate, 15, 160, 0, // Skip to: 2135
/* 1975 */    MCD::OPC_Decode, 255, 4, 73, // Opcode: SW64
/* 1979 */    MCD::OPC_FilterValue, 44, 8, 0, // Skip to: 1991
/* 1983 */    MCD::OPC_CheckPredicate, 15, 148, 0, // Skip to: 2135
/* 1987 */    MCD::OPC_Decode, 179, 4, 73, // Opcode: SDL
/* 1991 */    MCD::OPC_FilterValue, 45, 8, 0, // Skip to: 2003
/* 1995 */    MCD::OPC_CheckPredicate, 15, 136, 0, // Skip to: 2135
/* 1999 */    MCD::OPC_Decode, 181, 4, 73, // Opcode: SDR
/* 2003 */    MCD::OPC_FilterValue, 46, 8, 0, // Skip to: 2015
/* 2007 */    MCD::OPC_CheckPredicate, 15, 124, 0, // Skip to: 2135
/* 2011 */    MCD::OPC_Decode, 136, 5, 73, // Opcode: SWR64
/* 2015 */    MCD::OPC_FilterValue, 48, 8, 0, // Skip to: 2027
/* 2019 */    MCD::OPC_CheckPredicate, 21, 112, 0, // Skip to: 2135
/* 2023 */    MCD::OPC_Decode, 229, 2, 73, // Opcode: LL_P8
/* 2027 */    MCD::OPC_FilterValue, 49, 8, 0, // Skip to: 2039
/* 2031 */    MCD::OPC_CheckPredicate, 21, 100, 0, // Skip to: 2135
/* 2035 */    MCD::OPC_Decode, 238, 2, 74, // Opcode: LWC1_P8
/* 2039 */    MCD::OPC_FilterValue, 52, 8, 0, // Skip to: 2051
/* 2043 */    MCD::OPC_CheckPredicate, 15, 88, 0, // Skip to: 2135
/* 2047 */    MCD::OPC_Decode, 227, 2, 73, // Opcode: LLD
/* 2051 */    MCD::OPC_FilterValue, 53, 8, 0, // Skip to: 2063
/* 2055 */    MCD::OPC_CheckPredicate, 22, 76, 0, // Skip to: 2135
/* 2059 */    MCD::OPC_Decode, 205, 2, 74, // Opcode: LDC164
/* 2063 */    MCD::OPC_FilterValue, 55, 8, 0, // Skip to: 2075
/* 2067 */    MCD::OPC_CheckPredicate, 15, 64, 0, // Skip to: 2135
/* 2071 */    MCD::OPC_Decode, 203, 2, 73, // Opcode: LD
/* 2075 */    MCD::OPC_FilterValue, 56, 8, 0, // Skip to: 2087
/* 2079 */    MCD::OPC_CheckPredicate, 21, 52, 0, // Skip to: 2135
/* 2083 */    MCD::OPC_Decode, 173, 4, 73, // Opcode: SC_P8
/* 2087 */    MCD::OPC_FilterValue, 57, 8, 0, // Skip to: 2099
/* 2091 */    MCD::OPC_CheckPredicate, 21, 40, 0, // Skip to: 2135
/* 2095 */    MCD::OPC_Decode, 130, 5, 74, // Opcode: SWC1_P8
/* 2099 */    MCD::OPC_FilterValue, 60, 8, 0, // Skip to: 2111
/* 2103 */    MCD::OPC_CheckPredicate, 15, 28, 0, // Skip to: 2135
/* 2107 */    MCD::OPC_Decode, 171, 4, 73, // Opcode: SCD
/* 2111 */    MCD::OPC_FilterValue, 61, 8, 0, // Skip to: 2123
/* 2115 */    MCD::OPC_CheckPredicate, 22, 16, 0, // Skip to: 2135
/* 2119 */    MCD::OPC_Decode, 176, 4, 74, // Opcode: SDC164
/* 2123 */    MCD::OPC_FilterValue, 63, 8, 0, // Skip to: 2135
/* 2127 */    MCD::OPC_CheckPredicate, 15, 4, 0, // Skip to: 2135
/* 2131 */    MCD::OPC_Decode, 174, 4, 73, // Opcode: SD
/* 2135 */    MCD::OPC_Fail,
  0
};

static bool checkDecoderPredicate(unsigned Idx, uint64_t Bits) {
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    return (!(Bits & Oi::FeatureOi16));
  case 1:
    return ((Bits & Oi::FeatureOi32r2) && !(Bits & Oi::FeatureOi16));
  case 2:
    return ((Bits & Oi::FeatureDSP));
  case 3:
    return ((Bits & Oi::FeatureOi32) && !(Bits & Oi::FeatureOi16));
  case 4:
    return (!(Bits & Oi::FeatureFP64Bit) && !(Bits & Oi::FeatureOi16));
  case 5:
    return ((Bits & Oi::FeatureFPIdx) && !(Bits & Oi::FeatureOi16));
  case 6:
    return ((Bits & Oi::FeatureOi32r2) && !(Bits & Oi::FeatureOi64) && !(Bits & Oi::FeatureOi16));
  case 7:
    return (!(Bits & Oi::FeatureOi64) && !(Bits & Oi::FeatureOi16));
  case 8:
    return ((Bits & Oi::FeatureOi32r2) && !(Bits & Oi::FeatureFP64Bit) && !(Bits & Oi::FeatureOi16));
  case 9:
    return ((Bits & Oi::FeatureOi32r2) && (Bits & Oi::FeatureOi32) && !(Bits & Oi::FeatureOi16));
  case 10:
    return ((Bits & Oi::FeatureOi32r2) && !(Bits & Oi::FeatureFP64Bit) && (Bits & Oi::FeatureOi32) && !(Bits & Oi::FeatureOi16));
  case 11:
    return ((Bits & Oi::FeatureBitCount) && !(Bits & Oi::FeatureOi16));
  case 12:
    return ((Bits & Oi::FeatureDSPR2));
  case 13:
    return ((Bits & Oi::FeatureSwap) && !(Bits & Oi::FeatureOi16));
  case 14:
    return ((Bits & Oi::FeatureSEInReg) && !(Bits & Oi::FeatureOi16));
  case 15:
    return (!(Bits & Oi::FeatureN64) && !(Bits & Oi::FeatureOi16));
  case 16:
    return (!(Bits & Oi::FeatureN64) && !(Bits & Oi::FeatureOi64) && !(Bits & Oi::FeatureOi16));
  case 17:
    return ((Bits & Oi::FeatureOi64) && !(Bits & Oi::FeatureOi16));
  case 18:
    return ((Bits & Oi::FeatureOi64r2) && !(Bits & Oi::FeatureOi16));
  case 19:
    return ((Bits & Oi::FeatureFP64Bit) && !(Bits & Oi::FeatureOi16));
  case 20:
    return ((Bits & Oi::FeatureOi64) && !(Bits & Oi::FeatureN64) && !(Bits & Oi::FeatureOi16));
  case 21:
    return ((Bits & Oi::FeatureN64) && !(Bits & Oi::FeatureOi16));
  case 22:
    return (!(Bits & Oi::FeatureN64) && (Bits & Oi::FeatureOi64) && !(Bits & Oi::FeatureOi16));
  }
}

template<typename InsnType>
static DecodeStatus decodeToMCInst(DecodeStatus S, unsigned Idx, InsnType insn, MCInst &MI,
                                   uint64_t Address, const void *Decoder) {
  InsnType tmp;
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    return S;
  case 1:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 2:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 3:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 4:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 5:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 6:
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 7:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 8:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 9:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 10:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 11:
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 12:
    if (DecodeJumpTarget(MI, insn, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 13:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 14:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 15:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 16:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 17:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 18:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 19:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 20:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 21:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCCRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 22:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 23:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 24:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCCRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 25:
    if (DecodeBC1(MI, insn, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 26:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 28:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 29:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 30:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 31:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 32:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeCondCode(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 33:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 34:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 35:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 36:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 37:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 38:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeCondCode(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 41:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 42:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 43:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 44:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 45:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 46:
    tmp = 0;
    tmp |= (fieldFromInstruction(insn, 11, 5) << 0);
    tmp |= (fieldFromInstruction(insn, 16, 5) << 0);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 47:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeExtSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 48:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeInsSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 49:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 50:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 51:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 52:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 53:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 54:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 55:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 56:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 57:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 10);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 58:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 59:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 60:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 61:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 62:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 63:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 64:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 65:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 66:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 67:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 68:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 10);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 69:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 10);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 70:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 6);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 71:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 72:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeHWRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 73:
    if (DecodeMem(MI, insn, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 74:
    if (DecodeFMem(MI, insn, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 75:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 76:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 77:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 78:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 79:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 80:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 81:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 82:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 83:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 84:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 85:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 86:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 87:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 88:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 89:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::CreateImm(tmp));
    return S;
  case 90:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 91:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 92:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 93:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 94:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 95:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 96:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeCondCode(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 97:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 98:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPURegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 99:
    tmp = 0;
    tmp |= (fieldFromInstruction(insn, 11, 5) << 0);
    tmp |= (fieldFromInstruction(insn, 16, 5) << 0);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 100:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeExtSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 101:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::CreateImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeInsSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 102:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 103:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCPU64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeHWRegs64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  }
}

template<typename InsnType>
static DecodeStatus decodeInstruction(const uint8_t DecodeTable[], MCInst &MI,
                                      InsnType insn, uint64_t Address,
                                      const void *DisAsm,
                                      const MCSubtargetInfo &STI) {
  uint64_t Bits = STI.getFeatureBits();

  const uint8_t *Ptr = DecodeTable;
  uint32_t CurFieldValue = 0;
  DecodeStatus S = MCDisassembler::Success;
  for (;;) {
    ptrdiff_t Loc = Ptr - DecodeTable;
    switch (*Ptr) {
    default:
      errs() << Loc << ": Unexpected decode table opcode!\n";
      return MCDisassembler::Fail;
    case MCD::OPC_ExtractField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      ++Ptr;
      CurFieldValue = fieldFromInstruction(insn, Start, Len);
      DEBUG(dbgs() << Loc << ": OPC_ExtractField(" << Start << ", "
                   << Len << "): " << CurFieldValue << "\n");
      break;
    }
    case MCD::OPC_FilterValue: {
      // Decode the field value.
      unsigned Len;
      InsnType Val = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;

      // Perform the filter operation.
      if (Val != CurFieldValue)
        Ptr += NumToSkip;
      DEBUG(dbgs() << Loc << ": OPC_FilterValue(" << Val << ", " << NumToSkip
                   << "): " << ((Val != CurFieldValue) ? "FAIL:" : "PASS:")
                   << " continuing at " << (Ptr - DecodeTable) << "\n");

      break;
    }
    case MCD::OPC_CheckField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      InsnType FieldValue = fieldFromInstruction(insn, Start, Len);
      // Decode the field value.
      uint32_t ExpectedValue = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;

      // If the actual and expected values don't match, skip.
      if (ExpectedValue != FieldValue)
        Ptr += NumToSkip;
      DEBUG(dbgs() << Loc << ": OPC_CheckField(" << Start << ", "
                   << Len << ", " << ExpectedValue << ", " << NumToSkip
                   << "): FieldValue = " << FieldValue << ", ExpectedValue = "
                   << ExpectedValue << ": "
                   << ((ExpectedValue == FieldValue) ? "PASS\n" : "FAIL\n"));
      break;
    }
    case MCD::OPC_CheckPredicate: {
      unsigned Len;
      // Decode the Predicate Index value.
      unsigned PIdx = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;
      // Check the predicate.
      bool Pred;
      if (!(Pred = checkDecoderPredicate(PIdx, Bits)))
        Ptr += NumToSkip;
      (void)Pred;
      DEBUG(dbgs() << Loc << ": OPC_CheckPredicate(" << PIdx << "): "
            << (Pred ? "PASS\n" : "FAIL\n"));

      break;
    }
    case MCD::OPC_Decode: {
      unsigned Len;
      // Decode the Opcode value.
      unsigned Opc = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      unsigned DecodeIdx = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      DEBUG(dbgs() << Loc << ": OPC_Decode: opcode " << Opc
                   << ", using decoder " << DecodeIdx << "\n" );
      DEBUG(dbgs() << "----- DECODE SUCCESSFUL -----\n");

      MI.setOpcode(Opc);
      return decodeToMCInst(S, DecodeIdx, insn, MI, Address, DisAsm);
    }
    case MCD::OPC_SoftFail: {
      // Decode the mask values.
      unsigned Len;
      InsnType PositiveMask = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      InsnType NegativeMask = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      bool Fail = (insn & PositiveMask) || (~insn & NegativeMask);
      if (Fail)
        S = MCDisassembler::SoftFail;
      DEBUG(dbgs() << Loc << ": OPC_SoftFail: " << (Fail ? "FAIL\n":"PASS\n"));
      break;
    }
    case MCD::OPC_Fail: {
      DEBUG(dbgs() << Loc << ": OPC_Fail\n");
      return MCDisassembler::Fail;
    }
    }
  }
  llvm_unreachable("bogosity detected in disassembler state machine!");
}


} // End llvm namespace
