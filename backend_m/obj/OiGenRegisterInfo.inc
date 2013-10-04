/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Register Enum Values                                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM
namespace llvm {

class MCRegisterClass;
extern const MCRegisterClass OiMCRegisterClasses[];

namespace Oi {
enum {
  NoRegister,
  A0 = 1,
  A0_64 = 2,
  A1 = 3,
  A1_64 = 4,
  A2 = 5,
  A2_64 = 6,
  A3 = 7,
  A3_64 = 8,
  AC0 = 9,
  AC1 = 10,
  AC2 = 11,
  AC3 = 12,
  AT = 13,
  AT_64 = 14,
  D0 = 15,
  D0_64 = 16,
  D1 = 17,
  D1_64 = 18,
  D2 = 19,
  D2_64 = 20,
  D3 = 21,
  D3_64 = 22,
  D4 = 23,
  D4_64 = 24,
  D5 = 25,
  D5_64 = 26,
  D6 = 27,
  D6_64 = 28,
  D7 = 29,
  D7_64 = 30,
  D8 = 31,
  D8_64 = 32,
  D9 = 33,
  D9_64 = 34,
  D10 = 35,
  D10_64 = 36,
  D11 = 37,
  D11_64 = 38,
  D12 = 39,
  D12_64 = 40,
  D13 = 41,
  D13_64 = 42,
  D14 = 43,
  D14_64 = 44,
  D15 = 45,
  D15_64 = 46,
  D16_64 = 47,
  D17_64 = 48,
  D18_64 = 49,
  D19_64 = 50,
  D20_64 = 51,
  D21_64 = 52,
  D22_64 = 53,
  D23_64 = 54,
  D24_64 = 55,
  D25_64 = 56,
  D26_64 = 57,
  D27_64 = 58,
  D28_64 = 59,
  D29_64 = 60,
  D30_64 = 61,
  D31_64 = 62,
  DSPCtrl = 63,
  F0 = 64,
  F1 = 65,
  F2 = 66,
  F3 = 67,
  F4 = 68,
  F5 = 69,
  F6 = 70,
  F7 = 71,
  F8 = 72,
  F9 = 73,
  F10 = 74,
  F11 = 75,
  F12 = 76,
  F13 = 77,
  F14 = 78,
  F15 = 79,
  F16 = 80,
  F17 = 81,
  F18 = 82,
  F19 = 83,
  F20 = 84,
  F21 = 85,
  F22 = 86,
  F23 = 87,
  F24 = 88,
  F25 = 89,
  F26 = 90,
  F27 = 91,
  F28 = 92,
  F29 = 93,
  F30 = 94,
  F31 = 95,
  FCC0 = 96,
  FCR31 = 97,
  FP = 98,
  FP_64 = 99,
  GP = 100,
  GP_64 = 101,
  HI = 102,
  HI64 = 103,
  HWR29 = 104,
  HWR29_64 = 105,
  K0 = 106,
  K0_64 = 107,
  K1 = 108,
  K1_64 = 109,
  LO = 110,
  LO64 = 111,
  PC = 112,
  RA = 113,
  RA_64 = 114,
  S0 = 115,
  S0_64 = 116,
  S1 = 117,
  S1_64 = 118,
  S2 = 119,
  S2_64 = 120,
  S3 = 121,
  S3_64 = 122,
  S4 = 123,
  S4_64 = 124,
  S5 = 125,
  S5_64 = 126,
  S6 = 127,
  S6_64 = 128,
  S7 = 129,
  S7_64 = 130,
  SP = 131,
  SP_64 = 132,
  T0 = 133,
  T0_64 = 134,
  T1 = 135,
  T1_64 = 136,
  T2 = 137,
  T2_64 = 138,
  T3 = 139,
  T3_64 = 140,
  T4 = 141,
  T4_64 = 142,
  T5 = 143,
  T5_64 = 144,
  T6 = 145,
  T6_64 = 146,
  T7 = 147,
  T7_64 = 148,
  T8 = 149,
  T8_64 = 150,
  T9 = 151,
  T9_64 = 152,
  V0 = 153,
  V0_64 = 154,
  V1 = 155,
  V1_64 = 156,
  ZERO = 157,
  ZERO_64 = 158,
  NUM_TARGET_REGS 	// 159
};
}

// Register classes
namespace Oi {
enum {
  CPURegsRegClassID = 0,
  DSPRegsRegClassID = 1,
  FGR32RegClassID = 2,
  CPU16RegsRegClassID = 3,
  CCRRegClassID = 4,
  HILORegClassID = 5,
  CPURARegRegClassID = 6,
  CPUSPRegRegClassID = 7,
  HWRegsRegClassID = 8,
  HWRegs64RegClassID = 9,
  CPU64RegsRegClassID = 10,
  FGR64RegClassID = 11,
  AFGR64RegClassID = 12,
  CPU64Regs_with_sub_32_in_CPU16RegsRegClassID = 13,
  ACRegsRegClassID = 14,
  HILO64RegClassID = 15,
  ACRegs_with_sub_hiRegClassID = 16,
  CPU64Regs_with_sub_32_in_CPURARegRegClassID = 17,
  CPU64Regs_with_sub_32_in_CPUSPRegRegClassID = 18
  };
}

// Subregister indices
namespace Oi {
enum {
  NoSubRegister,
  sub_32,	// 1
  sub_fpeven,	// 2
  sub_fpodd,	// 3
  sub_hi,	// 4
  sub_lo,	// 5
  NUM_TARGET_SUBREGS
};
}
} // End llvm namespace 
#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*MC Register Information                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC
namespace llvm {

extern const MCPhysReg OiRegDiffLists[] = {
  /* 0 */ 0, 0,
  /* 2 */ 4, 1, 0,
  /* 5 */ 93, 1, 7, 1, 0,
  /* 10 */ 10, 1, 0,
  /* 13 */ 12, 1, 0,
  /* 16 */ 14, 1, 0,
  /* 19 */ 16, 1, 0,
  /* 22 */ 18, 1, 0,
  /* 25 */ 20, 1, 0,
  /* 28 */ 22, 1, 0,
  /* 31 */ 24, 1, 0,
  /* 34 */ 26, 1, 0,
  /* 37 */ 28, 1, 0,
  /* 40 */ 30, 1, 0,
  /* 43 */ 16, 1, 32, 1, 0,
  /* 48 */ 15, 2, 32, 1, 0,
  /* 53 */ 13, 2, 34, 1, 0,
  /* 58 */ 11, 2, 36, 1, 0,
  /* 63 */ 9, 2, 38, 1, 0,
  /* 68 */ 7, 2, 40, 1, 0,
  /* 73 */ 5, 2, 42, 1, 0,
  /* 78 */ 3, 2, 44, 1, 0,
  /* 83 */ 1, 2, 46, 1, 0,
  /* 88 */ 49, 1, 0,
  /* 91 */ 65487, 1, 0,
  /* 94 */ 2, 0,
  /* 96 */ 65486, 3, 0,
  /* 99 */ 65487, 3, 0,
  /* 102 */ 4, 0,
  /* 104 */ 65486, 5, 0,
  /* 107 */ 65487, 5, 0,
  /* 110 */ 65486, 7, 0,
  /* 113 */ 65487, 7, 0,
  /* 116 */ 65486, 9, 0,
  /* 119 */ 65487, 9, 0,
  /* 122 */ 10, 0,
  /* 124 */ 65486, 11, 0,
  /* 127 */ 65487, 11, 0,
  /* 130 */ 12, 0,
  /* 132 */ 65486, 13, 0,
  /* 135 */ 65487, 13, 0,
  /* 138 */ 14, 0,
  /* 140 */ 65486, 15, 0,
  /* 143 */ 65487, 15, 0,
  /* 146 */ 65487, 16, 0,
  /* 149 */ 65486, 17, 0,
  /* 152 */ 18, 0,
  /* 154 */ 19, 0,
  /* 156 */ 20, 0,
  /* 158 */ 21, 0,
  /* 160 */ 22, 0,
  /* 162 */ 23, 0,
  /* 164 */ 24, 0,
  /* 166 */ 33, 0,
  /* 168 */ 34, 0,
  /* 170 */ 35, 0,
  /* 172 */ 36, 0,
  /* 174 */ 37, 0,
  /* 176 */ 38, 0,
  /* 178 */ 39, 0,
  /* 180 */ 40, 0,
  /* 182 */ 41, 0,
  /* 184 */ 42, 0,
  /* 186 */ 43, 0,
  /* 188 */ 44, 0,
  /* 190 */ 45, 0,
  /* 192 */ 46, 0,
  /* 194 */ 47, 0,
  /* 196 */ 48, 0,
  /* 198 */ 65520, 49, 0,
  /* 201 */ 65521, 49, 0,
  /* 204 */ 65523, 49, 0,
  /* 207 */ 65525, 49, 0,
  /* 210 */ 65527, 49, 0,
  /* 213 */ 65529, 49, 0,
  /* 216 */ 65531, 49, 0,
  /* 219 */ 65533, 49, 0,
  /* 222 */ 65535, 49, 0,
  /* 225 */ 65519, 50, 0,
  /* 228 */ 65521, 50, 0,
  /* 231 */ 65523, 50, 0,
  /* 234 */ 65525, 50, 0,
  /* 237 */ 65527, 50, 0,
  /* 240 */ 65529, 50, 0,
  /* 243 */ 65531, 50, 0,
  /* 246 */ 65533, 50, 0,
  /* 249 */ 52, 0,
  /* 251 */ 53, 0,
  /* 253 */ 54, 0,
  /* 255 */ 55, 0,
  /* 257 */ 56, 0,
  /* 259 */ 57, 0,
  /* 261 */ 58, 0,
  /* 263 */ 59, 0,
  /* 265 */ 60, 0,
  /* 267 */ 61, 0,
  /* 269 */ 62, 0,
  /* 271 */ 63, 0,
  /* 273 */ 64, 0,
  /* 275 */ 65, 0,
  /* 277 */ 66, 0,
  /* 279 */ 67, 0,
  /* 281 */ 68, 0,
  /* 283 */ 69, 0,
  /* 285 */ 70, 0,
  /* 287 */ 71, 0,
  /* 289 */ 72, 0,
  /* 291 */ 73, 0,
  /* 293 */ 74, 0,
  /* 295 */ 65442, 93, 0,
  /* 298 */ 65443, 94, 0,
  /* 301 */ 65434, 101, 0,
  /* 304 */ 65435, 102, 0,
  /* 307 */ 65475, 0,
  /* 309 */ 65479, 0,
  /* 311 */ 65482, 0,
  /* 313 */ 65483, 0,
  /* 315 */ 65515, 0,
  /* 317 */ 101, 65528, 0,
  /* 320 */ 65532, 0,
  /* 322 */ 65535, 0,
};

extern const uint16_t OiSubRegIdxLists[] = {
  /* 0 */ 1, 0,
  /* 2 */ 2, 3, 0,
  /* 5 */ 5, 4, 0,
};

extern const char OiRegStrings[] = {
  /* 0 */ 'D', '1', '0', 0,
  /* 4 */ 'F', '1', '0', 0,
  /* 8 */ 'F', '2', '0', 0,
  /* 12 */ 'F', '3', '0', 0,
  /* 16 */ 'A', '0', 0,
  /* 19 */ 'A', 'C', '0', 0,
  /* 23 */ 'F', 'C', 'C', '0', 0,
  /* 28 */ 'D', '0', 0,
  /* 31 */ 'F', '0', 0,
  /* 34 */ 'K', '0', 0,
  /* 37 */ 'S', '0', 0,
  /* 40 */ 'T', '0', 0,
  /* 43 */ 'V', '0', 0,
  /* 46 */ 'D', '1', '1', 0,
  /* 50 */ 'F', '1', '1', 0,
  /* 54 */ 'F', '2', '1', 0,
  /* 58 */ 'F', '3', '1', 0,
  /* 62 */ 'F', 'C', 'R', '3', '1', 0,
  /* 68 */ 'A', '1', 0,
  /* 71 */ 'A', 'C', '1', 0,
  /* 75 */ 'D', '1', 0,
  /* 78 */ 'F', '1', 0,
  /* 81 */ 'K', '1', 0,
  /* 84 */ 'S', '1', 0,
  /* 87 */ 'T', '1', 0,
  /* 90 */ 'V', '1', 0,
  /* 93 */ 'D', '1', '2', 0,
  /* 97 */ 'F', '1', '2', 0,
  /* 101 */ 'F', '2', '2', 0,
  /* 105 */ 'A', '2', 0,
  /* 108 */ 'A', 'C', '2', 0,
  /* 112 */ 'D', '2', 0,
  /* 115 */ 'F', '2', 0,
  /* 118 */ 'S', '2', 0,
  /* 121 */ 'T', '2', 0,
  /* 124 */ 'D', '1', '3', 0,
  /* 128 */ 'F', '1', '3', 0,
  /* 132 */ 'F', '2', '3', 0,
  /* 136 */ 'A', '3', 0,
  /* 139 */ 'A', 'C', '3', 0,
  /* 143 */ 'D', '3', 0,
  /* 146 */ 'F', '3', 0,
  /* 149 */ 'S', '3', 0,
  /* 152 */ 'T', '3', 0,
  /* 155 */ 'D', '1', '4', 0,
  /* 159 */ 'F', '1', '4', 0,
  /* 163 */ 'F', '2', '4', 0,
  /* 167 */ 'H', 'I', '6', '4', 0,
  /* 172 */ 'L', 'O', '6', '4', 0,
  /* 177 */ 'D', '1', '0', '_', '6', '4', 0,
  /* 184 */ 'D', '2', '0', '_', '6', '4', 0,
  /* 191 */ 'D', '3', '0', '_', '6', '4', 0,
  /* 198 */ 'A', '0', '_', '6', '4', 0,
  /* 204 */ 'D', '0', '_', '6', '4', 0,
  /* 210 */ 'K', '0', '_', '6', '4', 0,
  /* 216 */ 'S', '0', '_', '6', '4', 0,
  /* 222 */ 'T', '0', '_', '6', '4', 0,
  /* 228 */ 'V', '0', '_', '6', '4', 0,
  /* 234 */ 'D', '1', '1', '_', '6', '4', 0,
  /* 241 */ 'D', '2', '1', '_', '6', '4', 0,
  /* 248 */ 'D', '3', '1', '_', '6', '4', 0,
  /* 255 */ 'A', '1', '_', '6', '4', 0,
  /* 261 */ 'D', '1', '_', '6', '4', 0,
  /* 267 */ 'K', '1', '_', '6', '4', 0,
  /* 273 */ 'S', '1', '_', '6', '4', 0,
  /* 279 */ 'T', '1', '_', '6', '4', 0,
  /* 285 */ 'V', '1', '_', '6', '4', 0,
  /* 291 */ 'D', '1', '2', '_', '6', '4', 0,
  /* 298 */ 'D', '2', '2', '_', '6', '4', 0,
  /* 305 */ 'A', '2', '_', '6', '4', 0,
  /* 311 */ 'D', '2', '_', '6', '4', 0,
  /* 317 */ 'S', '2', '_', '6', '4', 0,
  /* 323 */ 'T', '2', '_', '6', '4', 0,
  /* 329 */ 'D', '1', '3', '_', '6', '4', 0,
  /* 336 */ 'D', '2', '3', '_', '6', '4', 0,
  /* 343 */ 'A', '3', '_', '6', '4', 0,
  /* 349 */ 'D', '3', '_', '6', '4', 0,
  /* 355 */ 'S', '3', '_', '6', '4', 0,
  /* 361 */ 'T', '3', '_', '6', '4', 0,
  /* 367 */ 'D', '1', '4', '_', '6', '4', 0,
  /* 374 */ 'D', '2', '4', '_', '6', '4', 0,
  /* 381 */ 'D', '4', '_', '6', '4', 0,
  /* 387 */ 'S', '4', '_', '6', '4', 0,
  /* 393 */ 'T', '4', '_', '6', '4', 0,
  /* 399 */ 'D', '1', '5', '_', '6', '4', 0,
  /* 406 */ 'D', '2', '5', '_', '6', '4', 0,
  /* 413 */ 'D', '5', '_', '6', '4', 0,
  /* 419 */ 'S', '5', '_', '6', '4', 0,
  /* 425 */ 'T', '5', '_', '6', '4', 0,
  /* 431 */ 'D', '1', '6', '_', '6', '4', 0,
  /* 438 */ 'D', '2', '6', '_', '6', '4', 0,
  /* 445 */ 'D', '6', '_', '6', '4', 0,
  /* 451 */ 'S', '6', '_', '6', '4', 0,
  /* 457 */ 'T', '6', '_', '6', '4', 0,
  /* 463 */ 'D', '1', '7', '_', '6', '4', 0,
  /* 470 */ 'D', '2', '7', '_', '6', '4', 0,
  /* 477 */ 'D', '7', '_', '6', '4', 0,
  /* 483 */ 'S', '7', '_', '6', '4', 0,
  /* 489 */ 'T', '7', '_', '6', '4', 0,
  /* 495 */ 'D', '1', '8', '_', '6', '4', 0,
  /* 502 */ 'D', '2', '8', '_', '6', '4', 0,
  /* 509 */ 'D', '8', '_', '6', '4', 0,
  /* 515 */ 'T', '8', '_', '6', '4', 0,
  /* 521 */ 'D', '1', '9', '_', '6', '4', 0,
  /* 528 */ 'D', '2', '9', '_', '6', '4', 0,
  /* 535 */ 'H', 'W', 'R', '2', '9', '_', '6', '4', 0,
  /* 544 */ 'D', '9', '_', '6', '4', 0,
  /* 550 */ 'T', '9', '_', '6', '4', 0,
  /* 556 */ 'R', 'A', '_', '6', '4', 0,
  /* 562 */ 'Z', 'E', 'R', 'O', '_', '6', '4', 0,
  /* 570 */ 'F', 'P', '_', '6', '4', 0,
  /* 576 */ 'G', 'P', '_', '6', '4', 0,
  /* 582 */ 'S', 'P', '_', '6', '4', 0,
  /* 588 */ 'A', 'T', '_', '6', '4', 0,
  /* 594 */ 'D', '4', 0,
  /* 597 */ 'F', '4', 0,
  /* 600 */ 'S', '4', 0,
  /* 603 */ 'T', '4', 0,
  /* 606 */ 'D', '1', '5', 0,
  /* 610 */ 'F', '1', '5', 0,
  /* 614 */ 'F', '2', '5', 0,
  /* 618 */ 'D', '5', 0,
  /* 621 */ 'F', '5', 0,
  /* 624 */ 'S', '5', 0,
  /* 627 */ 'T', '5', 0,
  /* 630 */ 'F', '1', '6', 0,
  /* 634 */ 'F', '2', '6', 0,
  /* 638 */ 'D', '6', 0,
  /* 641 */ 'F', '6', 0,
  /* 644 */ 'S', '6', 0,
  /* 647 */ 'T', '6', 0,
  /* 650 */ 'F', '1', '7', 0,
  /* 654 */ 'F', '2', '7', 0,
  /* 658 */ 'D', '7', 0,
  /* 661 */ 'F', '7', 0,
  /* 664 */ 'S', '7', 0,
  /* 667 */ 'T', '7', 0,
  /* 670 */ 'F', '1', '8', 0,
  /* 674 */ 'F', '2', '8', 0,
  /* 678 */ 'D', '8', 0,
  /* 681 */ 'F', '8', 0,
  /* 684 */ 'T', '8', 0,
  /* 687 */ 'F', '1', '9', 0,
  /* 691 */ 'F', '2', '9', 0,
  /* 695 */ 'H', 'W', 'R', '2', '9', 0,
  /* 701 */ 'D', '9', 0,
  /* 704 */ 'F', '9', 0,
  /* 707 */ 'T', '9', 0,
  /* 710 */ 'R', 'A', 0,
  /* 713 */ 'P', 'C', 0,
  /* 716 */ 'H', 'I', 0,
  /* 719 */ 'L', 'O', 0,
  /* 722 */ 'Z', 'E', 'R', 'O', 0,
  /* 727 */ 'F', 'P', 0,
  /* 730 */ 'G', 'P', 0,
  /* 733 */ 'S', 'P', 0,
  /* 736 */ 'A', 'T', 0,
  /* 739 */ 'D', 'S', 'P', 'C', 't', 'r', 'l', 0,
};

extern const MCRegisterDesc OiRegDesc[] = { // Descriptors
  { 3, 0, 0, 0, 0, 0 },
  { 16, 3, 1, 3, 1, 0 },
  { 198, 322, 322, 1, 0, 0 },
  { 68, 3, 1, 3, 1, 48 },
  { 255, 322, 322, 1, 0, 48 },
  { 105, 3, 1, 3, 1, 1504 },
  { 305, 322, 322, 1, 0, 1504 },
  { 136, 3, 1, 3, 1, 1552 },
  { 343, 322, 322, 1, 0, 1552 },
  { 19, 5, 317, 1, 5, 32 },
  { 71, 1, 1, 1, 1, 5121 },
  { 108, 1, 1, 1, 1, 5121 },
  { 139, 1, 1, 1, 1, 5121 },
  { 736, 3, 1, 3, 1, 1872 },
  { 588, 322, 322, 1, 0, 1872 },
  { 28, 83, 88, 1, 2, 160 },
  { 204, 222, 196, 1, 0, 1952 },
  { 75, 78, 88, 1, 2, 208 },
  { 261, 246, 194, 1, 0, 2000 },
  { 112, 73, 88, 1, 2, 256 },
  { 311, 219, 192, 1, 0, 2080 },
  { 143, 68, 88, 1, 2, 304 },
  { 349, 243, 190, 1, 0, 2128 },
  { 594, 63, 88, 1, 2, 352 },
  { 381, 216, 188, 1, 0, 2208 },
  { 618, 58, 88, 1, 2, 400 },
  { 413, 240, 186, 1, 0, 2256 },
  { 638, 53, 88, 1, 2, 448 },
  { 445, 213, 184, 1, 0, 2352 },
  { 658, 48, 88, 1, 2, 496 },
  { 477, 237, 182, 1, 0, 2400 },
  { 678, 43, 88, 1, 2, 544 },
  { 509, 210, 180, 1, 0, 2432 },
  { 701, 43, 88, 1, 2, 592 },
  { 544, 234, 178, 1, 0, 2464 },
  { 0, 43, 88, 1, 2, 640 },
  { 177, 207, 176, 1, 0, 2496 },
  { 46, 43, 88, 1, 2, 720 },
  { 234, 231, 174, 1, 0, 2528 },
  { 93, 43, 88, 1, 2, 880 },
  { 291, 204, 172, 1, 0, 2560 },
  { 124, 43, 88, 1, 2, 960 },
  { 329, 228, 170, 1, 0, 2592 },
  { 155, 43, 88, 1, 2, 1040 },
  { 367, 201, 168, 1, 0, 2624 },
  { 606, 43, 88, 1, 2, 1120 },
  { 399, 225, 166, 1, 0, 5041 },
  { 431, 198, 166, 1, 0, 5041 },
  { 463, 225, 166, 1, 0, 5041 },
  { 495, 198, 166, 1, 0, 5041 },
  { 521, 225, 166, 1, 0, 5041 },
  { 184, 198, 166, 1, 0, 5041 },
  { 241, 225, 166, 1, 0, 5041 },
  { 298, 198, 166, 1, 0, 5041 },
  { 336, 225, 166, 1, 0, 5041 },
  { 374, 198, 166, 1, 0, 5041 },
  { 406, 225, 166, 1, 0, 5041 },
  { 438, 198, 166, 1, 0, 5041 },
  { 470, 225, 166, 1, 0, 5041 },
  { 502, 198, 166, 1, 0, 5041 },
  { 528, 225, 166, 1, 0, 5041 },
  { 191, 198, 166, 1, 0, 5041 },
  { 248, 225, 166, 1, 0, 5041 },
  { 739, 1, 1, 1, 1, 5041 },
  { 31, 91, 1, 91, 1, 4977 },
  { 78, 96, 1, 96, 1, 4977 },
  { 115, 99, 1, 99, 1, 4977 },
  { 146, 104, 1, 104, 1, 4977 },
  { 597, 107, 1, 107, 1, 4977 },
  { 621, 110, 1, 110, 1, 4977 },
  { 641, 113, 1, 113, 1, 4977 },
  { 661, 116, 1, 116, 1, 4977 },
  { 681, 119, 1, 119, 1, 4977 },
  { 704, 124, 1, 124, 1, 4977 },
  { 4, 127, 1, 127, 1, 4977 },
  { 50, 132, 1, 132, 1, 4977 },
  { 97, 135, 1, 135, 1, 4977 },
  { 128, 140, 1, 140, 1, 4977 },
  { 159, 143, 1, 143, 1, 4977 },
  { 610, 149, 1, 149, 1, 4977 },
  { 630, 146, 1, 146, 1, 4977 },
  { 650, 149, 1, 149, 1, 4977 },
  { 670, 146, 1, 146, 1, 4977 },
  { 687, 149, 1, 149, 1, 4977 },
  { 8, 146, 1, 146, 1, 4977 },
  { 54, 149, 1, 149, 1, 4977 },
  { 101, 146, 1, 146, 1, 4977 },
  { 132, 149, 1, 149, 1, 4977 },
  { 163, 146, 1, 146, 1, 4977 },
  { 614, 149, 1, 149, 1, 4977 },
  { 634, 146, 1, 146, 1, 4977 },
  { 654, 149, 1, 149, 1, 4977 },
  { 674, 146, 1, 146, 1, 4977 },
  { 691, 149, 1, 149, 1, 4977 },
  { 12, 146, 1, 146, 1, 4977 },
  { 58, 149, 1, 149, 1, 4977 },
  { 23, 1, 1, 1, 1, 5009 },
  { 62, 1, 1, 1, 1, 5009 },
  { 727, 3, 1, 3, 1, 3040 },
  { 570, 322, 322, 1, 0, 3040 },
  { 730, 3, 1, 3, 1, 3072 },
  { 576, 322, 322, 1, 0, 3072 },
  { 716, 298, 1, 298, 1, 1680 },
  { 167, 295, 322, 1, 0, 1680 },
  { 695, 1, 1, 1, 1, 4945 },
  { 535, 1, 1, 1, 1, 4945 },
  { 34, 3, 1, 3, 1, 3184 },
  { 210, 322, 322, 1, 0, 3184 },
  { 81, 3, 1, 3, 1, 3616 },
  { 267, 322, 322, 1, 0, 3616 },
  { 719, 304, 1, 304, 1, 1632 },
  { 172, 301, 322, 1, 0, 1632 },
  { 713, 1, 1, 1, 1, 4913 },
  { 710, 3, 1, 3, 1, 3984 },
  { 556, 322, 322, 1, 0, 3984 },
  { 37, 3, 1, 3, 1, 4016 },
  { 216, 322, 322, 1, 0, 4016 },
  { 84, 3, 1, 3, 1, 4048 },
  { 273, 322, 322, 1, 0, 4048 },
  { 118, 3, 1, 3, 1, 4080 },
  { 317, 322, 322, 1, 0, 4080 },
  { 149, 3, 1, 3, 1, 4112 },
  { 355, 322, 322, 1, 0, 4112 },
  { 600, 3, 1, 3, 1, 4144 },
  { 387, 322, 322, 1, 0, 4144 },
  { 624, 3, 1, 3, 1, 4176 },
  { 419, 322, 322, 1, 0, 4176 },
  { 644, 3, 1, 3, 1, 4208 },
  { 451, 322, 322, 1, 0, 4208 },
  { 664, 3, 1, 3, 1, 4240 },
  { 483, 322, 322, 1, 0, 4240 },
  { 733, 3, 1, 3, 1, 4272 },
  { 582, 322, 322, 1, 0, 4272 },
  { 40, 3, 1, 3, 1, 4304 },
  { 222, 322, 322, 1, 0, 4304 },
  { 87, 3, 1, 3, 1, 4336 },
  { 279, 322, 322, 1, 0, 4336 },
  { 121, 3, 1, 3, 1, 4368 },
  { 323, 322, 322, 1, 0, 4368 },
  { 152, 3, 1, 3, 1, 4400 },
  { 361, 322, 322, 1, 0, 4400 },
  { 603, 3, 1, 3, 1, 4432 },
  { 393, 322, 322, 1, 0, 4432 },
  { 627, 3, 1, 3, 1, 4464 },
  { 425, 322, 322, 1, 0, 4464 },
  { 647, 3, 1, 3, 1, 4496 },
  { 457, 322, 322, 1, 0, 4496 },
  { 667, 3, 1, 3, 1, 4528 },
  { 489, 322, 322, 1, 0, 4528 },
  { 684, 3, 1, 3, 1, 4560 },
  { 515, 322, 322, 1, 0, 4560 },
  { 707, 3, 1, 3, 1, 4592 },
  { 550, 322, 322, 1, 0, 4592 },
  { 43, 3, 1, 3, 1, 4624 },
  { 228, 322, 322, 1, 0, 4624 },
  { 90, 3, 1, 3, 1, 4656 },
  { 285, 322, 322, 1, 0, 4656 },
  { 722, 3, 1, 3, 1, 4688 },
  { 562, 322, 322, 1, 0, 4688 },
};

extern const uint16_t OiRegUnitRoots[][2] = {
  { Oi::A0 },
  { Oi::A1 },
  { Oi::A2 },
  { Oi::A3 },
  { Oi::LO },
  { Oi::HI },
  { Oi::AC1 },
  { Oi::AC2 },
  { Oi::AC3 },
  { Oi::AT },
  { Oi::F0 },
  { Oi::F1 },
  { Oi::F2 },
  { Oi::F3 },
  { Oi::F4 },
  { Oi::F5 },
  { Oi::F6 },
  { Oi::F7 },
  { Oi::F8 },
  { Oi::F9 },
  { Oi::F10 },
  { Oi::F11 },
  { Oi::F12 },
  { Oi::F13 },
  { Oi::F14 },
  { Oi::F15 },
  { Oi::F16 },
  { Oi::F17 },
  { Oi::F18 },
  { Oi::F19 },
  { Oi::F20 },
  { Oi::F21 },
  { Oi::F22 },
  { Oi::F23 },
  { Oi::F24 },
  { Oi::F25 },
  { Oi::F26 },
  { Oi::F27 },
  { Oi::F28 },
  { Oi::F29 },
  { Oi::F30 },
  { Oi::F31 },
  { Oi::DSPCtrl },
  { Oi::FCC0 },
  { Oi::FCR31 },
  { Oi::FP },
  { Oi::GP },
  { Oi::HWR29 },
  { Oi::HWR29_64 },
  { Oi::K0 },
  { Oi::K1 },
  { Oi::PC },
  { Oi::RA },
  { Oi::S0 },
  { Oi::S1 },
  { Oi::S2 },
  { Oi::S3 },
  { Oi::S4 },
  { Oi::S5 },
  { Oi::S6 },
  { Oi::S7 },
  { Oi::SP },
  { Oi::T0 },
  { Oi::T1 },
  { Oi::T2 },
  { Oi::T3 },
  { Oi::T4 },
  { Oi::T5 },
  { Oi::T6 },
  { Oi::T7 },
  { Oi::T8 },
  { Oi::T9 },
  { Oi::V0 },
  { Oi::V1 },
  { Oi::ZERO },
};

namespace {     // Register classes...
  // CPURegs Register Class...
  const uint16_t CPURegs[] = {
    Oi::ZERO, Oi::AT, Oi::V0, Oi::V1, Oi::A0, Oi::A1, Oi::A2, Oi::A3, Oi::T0, Oi::T1, Oi::T2, Oi::T3, Oi::T4, Oi::T5, Oi::T6, Oi::T7, Oi::S0, Oi::S1, Oi::S2, Oi::S3, Oi::S4, Oi::S5, Oi::S6, Oi::S7, Oi::T8, Oi::T9, Oi::K0, Oi::K1, Oi::GP, Oi::SP, Oi::FP, Oi::RA, 
  };

  // CPURegs Bit set.
  const uint8_t CPURegsBits[] = {
    0xaa, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x14, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x2a, 
  };

  // DSPRegs Register Class...
  const uint16_t DSPRegs[] = {
    Oi::ZERO, Oi::AT, Oi::V0, Oi::V1, Oi::A0, Oi::A1, Oi::A2, Oi::A3, Oi::T0, Oi::T1, Oi::T2, Oi::T3, Oi::T4, Oi::T5, Oi::T6, Oi::T7, Oi::S0, Oi::S1, Oi::S2, Oi::S3, Oi::S4, Oi::S5, Oi::S6, Oi::S7, Oi::T8, Oi::T9, Oi::K0, Oi::K1, Oi::GP, Oi::SP, Oi::FP, Oi::RA, 
  };

  // DSPRegs Bit set.
  const uint8_t DSPRegsBits[] = {
    0xaa, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x14, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x2a, 
  };

  // FGR32 Register Class...
  const uint16_t FGR32[] = {
    Oi::F0, Oi::F1, Oi::F2, Oi::F3, Oi::F4, Oi::F5, Oi::F6, Oi::F7, Oi::F8, Oi::F9, Oi::F10, Oi::F11, Oi::F12, Oi::F13, Oi::F14, Oi::F15, Oi::F16, Oi::F17, Oi::F18, Oi::F19, Oi::F20, Oi::F21, Oi::F22, Oi::F23, Oi::F24, Oi::F25, Oi::F26, Oi::F27, Oi::F28, Oi::F29, Oi::F30, Oi::F31, 
  };

  // FGR32 Bit set.
  const uint8_t FGR32Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
  };

  // CPU16Regs Register Class...
  const uint16_t CPU16Regs[] = {
    Oi::V0, Oi::V1, Oi::A0, Oi::A1, Oi::A2, Oi::A3, Oi::S0, Oi::S1, 
  };

  // CPU16Regs Bit set.
  const uint8_t CPU16RegsBits[] = {
    0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x0a, 
  };

  // CCR Register Class...
  const uint16_t CCR[] = {
    Oi::FCR31, Oi::FCC0, 
  };

  // CCR Bit set.
  const uint8_t CCRBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
  };

  // HILO Register Class...
  const uint16_t HILO[] = {
    Oi::HI, Oi::LO, 
  };

  // HILO Bit set.
  const uint8_t HILOBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 
  };

  // CPURAReg Register Class...
  const uint16_t CPURAReg[] = {
    Oi::RA, 
  };

  // CPURAReg Bit set.
  const uint8_t CPURARegBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  };

  // CPUSPReg Register Class...
  const uint16_t CPUSPReg[] = {
    Oi::SP, 
  };

  // CPUSPReg Bit set.
  const uint8_t CPUSPRegBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
  };

  // HWRegs Register Class...
  const uint16_t HWRegs[] = {
    Oi::HWR29, 
  };

  // HWRegs Bit set.
  const uint8_t HWRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
  };

  // HWRegs64 Register Class...
  const uint16_t HWRegs64[] = {
    Oi::HWR29_64, 
  };

  // HWRegs64 Bit set.
  const uint8_t HWRegs64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  };

  // CPU64Regs Register Class...
  const uint16_t CPU64Regs[] = {
    Oi::ZERO_64, Oi::AT_64, Oi::V0_64, Oi::V1_64, Oi::A0_64, Oi::A1_64, Oi::A2_64, Oi::A3_64, Oi::T0_64, Oi::T1_64, Oi::T2_64, Oi::T3_64, Oi::T4_64, Oi::T5_64, Oi::T6_64, Oi::T7_64, Oi::S0_64, Oi::S1_64, Oi::S2_64, Oi::S3_64, Oi::S4_64, Oi::S5_64, Oi::S6_64, Oi::S7_64, Oi::T8_64, Oi::T9_64, Oi::K0_64, Oi::K1_64, Oi::GP_64, Oi::SP_64, Oi::FP_64, Oi::RA_64, 
  };

  // CPU64Regs Bit set.
  const uint8_t CPU64RegsBits[] = {
    0x54, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x28, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 
  };

  // FGR64 Register Class...
  const uint16_t FGR64[] = {
    Oi::D0_64, Oi::D1_64, Oi::D2_64, Oi::D3_64, Oi::D4_64, Oi::D5_64, Oi::D6_64, Oi::D7_64, Oi::D8_64, Oi::D9_64, Oi::D10_64, Oi::D11_64, Oi::D12_64, Oi::D13_64, Oi::D14_64, Oi::D15_64, Oi::D16_64, Oi::D17_64, Oi::D18_64, Oi::D19_64, Oi::D20_64, Oi::D21_64, Oi::D22_64, Oi::D23_64, Oi::D24_64, Oi::D25_64, Oi::D26_64, Oi::D27_64, Oi::D28_64, Oi::D29_64, Oi::D30_64, Oi::D31_64, 
  };

  // FGR64 Bit set.
  const uint8_t FGR64Bits[] = {
    0x00, 0x00, 0x55, 0x55, 0x55, 0xd5, 0xff, 0x7f, 
  };

  // AFGR64 Register Class...
  const uint16_t AFGR64[] = {
    Oi::D0, Oi::D1, Oi::D2, Oi::D3, Oi::D4, Oi::D5, Oi::D6, Oi::D7, Oi::D8, Oi::D9, Oi::D10, Oi::D11, Oi::D12, Oi::D13, Oi::D14, Oi::D15, 
  };

  // AFGR64 Bit set.
  const uint8_t AFGR64Bits[] = {
    0x00, 0x80, 0xaa, 0xaa, 0xaa, 0x2a, 
  };

  // CPU64Regs_with_sub_32_in_CPU16Regs Register Class...
  const uint16_t CPU64Regs_with_sub_32_in_CPU16Regs[] = {
    Oi::V0_64, Oi::V1_64, Oi::A0_64, Oi::A1_64, Oi::A2_64, Oi::A3_64, Oi::S0_64, Oi::S1_64, 
  };

  // CPU64Regs_with_sub_32_in_CPU16Regs Bit set.
  const uint8_t CPU64Regs_with_sub_32_in_CPU16RegsBits[] = {
    0x54, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x14, 
  };

  // ACRegs Register Class...
  const uint16_t ACRegs[] = {
    Oi::AC0, Oi::AC1, Oi::AC2, Oi::AC3, 
  };

  // ACRegs Bit set.
  const uint8_t ACRegsBits[] = {
    0x00, 0x1e, 
  };

  // HILO64 Register Class...
  const uint16_t HILO64[] = {
    Oi::HI64, Oi::LO64, 
  };

  // HILO64 Bit set.
  const uint8_t HILO64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
  };

  // ACRegs_with_sub_hi Register Class...
  const uint16_t ACRegs_with_sub_hi[] = {
    Oi::AC0, 
  };

  // ACRegs_with_sub_hi Bit set.
  const uint8_t ACRegs_with_sub_hiBits[] = {
    0x00, 0x02, 
  };

  // CPU64Regs_with_sub_32_in_CPURAReg Register Class...
  const uint16_t CPU64Regs_with_sub_32_in_CPURAReg[] = {
    Oi::RA_64, 
  };

  // CPU64Regs_with_sub_32_in_CPURAReg Bit set.
  const uint8_t CPU64Regs_with_sub_32_in_CPURARegBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
  };

  // CPU64Regs_with_sub_32_in_CPUSPReg Register Class...
  const uint16_t CPU64Regs_with_sub_32_in_CPUSPReg[] = {
    Oi::SP_64, 
  };

  // CPU64Regs_with_sub_32_in_CPUSPReg Bit set.
  const uint8_t CPU64Regs_with_sub_32_in_CPUSPRegBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
  };

}

extern const MCRegisterClass OiMCRegisterClasses[] = {
  { "CPURegs", CPURegs, CPURegsBits, 32, sizeof(CPURegsBits), Oi::CPURegsRegClassID, 4, 4, 1, 1 },
  { "DSPRegs", DSPRegs, DSPRegsBits, 32, sizeof(DSPRegsBits), Oi::DSPRegsRegClassID, 4, 4, 1, 1 },
  { "FGR32", FGR32, FGR32Bits, 32, sizeof(FGR32Bits), Oi::FGR32RegClassID, 4, 4, 1, 1 },
  { "CPU16Regs", CPU16Regs, CPU16RegsBits, 8, sizeof(CPU16RegsBits), Oi::CPU16RegsRegClassID, 4, 4, 1, 1 },
  { "CCR", CCR, CCRBits, 2, sizeof(CCRBits), Oi::CCRRegClassID, 4, 4, 1, 1 },
  { "HILO", HILO, HILOBits, 2, sizeof(HILOBits), Oi::HILORegClassID, 4, 4, 1, 1 },
  { "CPURAReg", CPURAReg, CPURARegBits, 1, sizeof(CPURARegBits), Oi::CPURARegRegClassID, 4, 4, 1, 1 },
  { "CPUSPReg", CPUSPReg, CPUSPRegBits, 1, sizeof(CPUSPRegBits), Oi::CPUSPRegRegClassID, 4, 4, 1, 1 },
  { "HWRegs", HWRegs, HWRegsBits, 1, sizeof(HWRegsBits), Oi::HWRegsRegClassID, 4, 4, 1, 1 },
  { "HWRegs64", HWRegs64, HWRegs64Bits, 1, sizeof(HWRegs64Bits), Oi::HWRegs64RegClassID, 8, 4, 1, 1 },
  { "CPU64Regs", CPU64Regs, CPU64RegsBits, 32, sizeof(CPU64RegsBits), Oi::CPU64RegsRegClassID, 8, 8, 1, 1 },
  { "FGR64", FGR64, FGR64Bits, 32, sizeof(FGR64Bits), Oi::FGR64RegClassID, 8, 8, 1, 1 },
  { "AFGR64", AFGR64, AFGR64Bits, 16, sizeof(AFGR64Bits), Oi::AFGR64RegClassID, 8, 8, 1, 1 },
  { "CPU64Regs_with_sub_32_in_CPU16Regs", CPU64Regs_with_sub_32_in_CPU16Regs, CPU64Regs_with_sub_32_in_CPU16RegsBits, 8, sizeof(CPU64Regs_with_sub_32_in_CPU16RegsBits), Oi::CPU64Regs_with_sub_32_in_CPU16RegsRegClassID, 8, 8, 1, 1 },
  { "ACRegs", ACRegs, ACRegsBits, 4, sizeof(ACRegsBits), Oi::ACRegsRegClassID, 8, 8, 1, 1 },
  { "HILO64", HILO64, HILO64Bits, 2, sizeof(HILO64Bits), Oi::HILO64RegClassID, 8, 8, 1, 1 },
  { "ACRegs_with_sub_hi", ACRegs_with_sub_hi, ACRegs_with_sub_hiBits, 1, sizeof(ACRegs_with_sub_hiBits), Oi::ACRegs_with_sub_hiRegClassID, 8, 8, 1, 1 },
  { "CPU64Regs_with_sub_32_in_CPURAReg", CPU64Regs_with_sub_32_in_CPURAReg, CPU64Regs_with_sub_32_in_CPURARegBits, 1, sizeof(CPU64Regs_with_sub_32_in_CPURARegBits), Oi::CPU64Regs_with_sub_32_in_CPURARegRegClassID, 8, 8, 1, 1 },
  { "CPU64Regs_with_sub_32_in_CPUSPReg", CPU64Regs_with_sub_32_in_CPUSPReg, CPU64Regs_with_sub_32_in_CPUSPRegBits, 1, sizeof(CPU64Regs_with_sub_32_in_CPUSPRegBits), Oi::CPU64Regs_with_sub_32_in_CPUSPRegRegClassID, 8, 8, 1, 1 },
};

// Oi Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair OiDwarfFlavour0Dwarf2L[] = {
  { 0U, Oi::ZERO_64 },
  { 1U, Oi::AT_64 },
  { 2U, Oi::V0_64 },
  { 3U, Oi::V1_64 },
  { 4U, Oi::A0_64 },
  { 5U, Oi::A1_64 },
  { 6U, Oi::A2_64 },
  { 7U, Oi::A3_64 },
  { 8U, Oi::T0_64 },
  { 9U, Oi::T1_64 },
  { 10U, Oi::T2_64 },
  { 11U, Oi::T3_64 },
  { 12U, Oi::T4_64 },
  { 13U, Oi::T5_64 },
  { 14U, Oi::T6_64 },
  { 15U, Oi::T7_64 },
  { 16U, Oi::S0_64 },
  { 17U, Oi::S1_64 },
  { 18U, Oi::S2_64 },
  { 19U, Oi::S3_64 },
  { 20U, Oi::S4_64 },
  { 21U, Oi::S5_64 },
  { 22U, Oi::S6_64 },
  { 23U, Oi::S7_64 },
  { 24U, Oi::T8_64 },
  { 25U, Oi::T9_64 },
  { 26U, Oi::K0_64 },
  { 27U, Oi::K1_64 },
  { 28U, Oi::GP_64 },
  { 29U, Oi::SP_64 },
  { 30U, Oi::FP_64 },
  { 31U, Oi::RA_64 },
  { 32U, Oi::F0 },
  { 33U, Oi::F1 },
  { 34U, Oi::F2 },
  { 35U, Oi::F3 },
  { 36U, Oi::F4 },
  { 37U, Oi::F5 },
  { 38U, Oi::F6 },
  { 39U, Oi::F7 },
  { 40U, Oi::F8 },
  { 41U, Oi::F9 },
  { 42U, Oi::F10 },
  { 43U, Oi::F11 },
  { 44U, Oi::F12 },
  { 45U, Oi::F13 },
  { 46U, Oi::F14 },
  { 47U, Oi::F15 },
  { 48U, Oi::F16 },
  { 49U, Oi::F17 },
  { 50U, Oi::F18 },
  { 51U, Oi::F19 },
  { 52U, Oi::F20 },
  { 53U, Oi::F21 },
  { 54U, Oi::F22 },
  { 55U, Oi::F23 },
  { 56U, Oi::F24 },
  { 57U, Oi::F25 },
  { 58U, Oi::F26 },
  { 59U, Oi::F27 },
  { 60U, Oi::F28 },
  { 61U, Oi::F29 },
  { 62U, Oi::F30 },
  { 63U, Oi::F31 },
  { 64U, Oi::HI },
  { 65U, Oi::LO },
};
extern const unsigned OiDwarfFlavour0Dwarf2LSize = sizeof(OiDwarfFlavour0Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair OiEHFlavour0Dwarf2L[] = {
  { 0U, Oi::ZERO_64 },
  { 1U, Oi::AT_64 },
  { 2U, Oi::V0_64 },
  { 3U, Oi::V1_64 },
  { 4U, Oi::A0_64 },
  { 5U, Oi::A1_64 },
  { 6U, Oi::A2_64 },
  { 7U, Oi::A3_64 },
  { 8U, Oi::T0_64 },
  { 9U, Oi::T1_64 },
  { 10U, Oi::T2_64 },
  { 11U, Oi::T3_64 },
  { 12U, Oi::T4_64 },
  { 13U, Oi::T5_64 },
  { 14U, Oi::T6_64 },
  { 15U, Oi::T7_64 },
  { 16U, Oi::S0_64 },
  { 17U, Oi::S1_64 },
  { 18U, Oi::S2_64 },
  { 19U, Oi::S3_64 },
  { 20U, Oi::S4_64 },
  { 21U, Oi::S5_64 },
  { 22U, Oi::S6_64 },
  { 23U, Oi::S7_64 },
  { 24U, Oi::T8_64 },
  { 25U, Oi::T9_64 },
  { 26U, Oi::K0_64 },
  { 27U, Oi::K1_64 },
  { 28U, Oi::GP_64 },
  { 29U, Oi::SP_64 },
  { 30U, Oi::FP_64 },
  { 31U, Oi::RA_64 },
  { 32U, Oi::F0 },
  { 33U, Oi::F1 },
  { 34U, Oi::F2 },
  { 35U, Oi::F3 },
  { 36U, Oi::F4 },
  { 37U, Oi::F5 },
  { 38U, Oi::F6 },
  { 39U, Oi::F7 },
  { 40U, Oi::F8 },
  { 41U, Oi::F9 },
  { 42U, Oi::F10 },
  { 43U, Oi::F11 },
  { 44U, Oi::F12 },
  { 45U, Oi::F13 },
  { 46U, Oi::F14 },
  { 47U, Oi::F15 },
  { 48U, Oi::F16 },
  { 49U, Oi::F17 },
  { 50U, Oi::F18 },
  { 51U, Oi::F19 },
  { 52U, Oi::F20 },
  { 53U, Oi::F21 },
  { 54U, Oi::F22 },
  { 55U, Oi::F23 },
  { 56U, Oi::F24 },
  { 57U, Oi::F25 },
  { 58U, Oi::F26 },
  { 59U, Oi::F27 },
  { 60U, Oi::F28 },
  { 61U, Oi::F29 },
  { 62U, Oi::F30 },
  { 63U, Oi::F31 },
  { 64U, Oi::HI },
  { 65U, Oi::LO },
};
extern const unsigned OiEHFlavour0Dwarf2LSize = sizeof(OiEHFlavour0Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair OiDwarfFlavour0L2Dwarf[] = {
  { Oi::A0, 4U },
  { Oi::A0_64, 4U },
  { Oi::A1, 5U },
  { Oi::A1_64, 5U },
  { Oi::A2, 6U },
  { Oi::A2_64, 6U },
  { Oi::A3, 7U },
  { Oi::A3_64, 7U },
  { Oi::AT, 1U },
  { Oi::AT_64, 1U },
  { Oi::D0_64, 32U },
  { Oi::D1_64, 33U },
  { Oi::D2_64, 34U },
  { Oi::D3_64, 35U },
  { Oi::D4_64, 36U },
  { Oi::D5_64, 37U },
  { Oi::D6_64, 38U },
  { Oi::D7_64, 39U },
  { Oi::D8_64, 40U },
  { Oi::D9_64, 41U },
  { Oi::D10_64, 42U },
  { Oi::D11_64, 43U },
  { Oi::D12_64, 44U },
  { Oi::D13_64, 45U },
  { Oi::D14_64, 46U },
  { Oi::D15_64, 47U },
  { Oi::D16_64, 48U },
  { Oi::D17_64, 49U },
  { Oi::D18_64, 50U },
  { Oi::D19_64, 51U },
  { Oi::D20_64, 52U },
  { Oi::D21_64, 53U },
  { Oi::D22_64, 54U },
  { Oi::D23_64, 55U },
  { Oi::D24_64, 56U },
  { Oi::D25_64, 57U },
  { Oi::D26_64, 58U },
  { Oi::D27_64, 59U },
  { Oi::D28_64, 60U },
  { Oi::D29_64, 61U },
  { Oi::D30_64, 62U },
  { Oi::D31_64, 63U },
  { Oi::F0, 32U },
  { Oi::F1, 33U },
  { Oi::F2, 34U },
  { Oi::F3, 35U },
  { Oi::F4, 36U },
  { Oi::F5, 37U },
  { Oi::F6, 38U },
  { Oi::F7, 39U },
  { Oi::F8, 40U },
  { Oi::F9, 41U },
  { Oi::F10, 42U },
  { Oi::F11, 43U },
  { Oi::F12, 44U },
  { Oi::F13, 45U },
  { Oi::F14, 46U },
  { Oi::F15, 47U },
  { Oi::F16, 48U },
  { Oi::F17, 49U },
  { Oi::F18, 50U },
  { Oi::F19, 51U },
  { Oi::F20, 52U },
  { Oi::F21, 53U },
  { Oi::F22, 54U },
  { Oi::F23, 55U },
  { Oi::F24, 56U },
  { Oi::F25, 57U },
  { Oi::F26, 58U },
  { Oi::F27, 59U },
  { Oi::F28, 60U },
  { Oi::F29, 61U },
  { Oi::F30, 62U },
  { Oi::F31, 63U },
  { Oi::FP, 30U },
  { Oi::FP_64, 30U },
  { Oi::GP, 28U },
  { Oi::GP_64, 28U },
  { Oi::HI, 64U },
  { Oi::K0, 26U },
  { Oi::K0_64, 26U },
  { Oi::K1, 27U },
  { Oi::K1_64, 27U },
  { Oi::LO, 65U },
  { Oi::RA, 31U },
  { Oi::RA_64, 31U },
  { Oi::S0, 16U },
  { Oi::S0_64, 16U },
  { Oi::S1, 17U },
  { Oi::S1_64, 17U },
  { Oi::S2, 18U },
  { Oi::S2_64, 18U },
  { Oi::S3, 19U },
  { Oi::S3_64, 19U },
  { Oi::S4, 20U },
  { Oi::S4_64, 20U },
  { Oi::S5, 21U },
  { Oi::S5_64, 21U },
  { Oi::S6, 22U },
  { Oi::S6_64, 22U },
  { Oi::S7, 23U },
  { Oi::S7_64, 23U },
  { Oi::SP, 29U },
  { Oi::SP_64, 29U },
  { Oi::T0, 8U },
  { Oi::T0_64, 8U },
  { Oi::T1, 9U },
  { Oi::T1_64, 9U },
  { Oi::T2, 10U },
  { Oi::T2_64, 10U },
  { Oi::T3, 11U },
  { Oi::T3_64, 11U },
  { Oi::T4, 12U },
  { Oi::T4_64, 12U },
  { Oi::T5, 13U },
  { Oi::T5_64, 13U },
  { Oi::T6, 14U },
  { Oi::T6_64, 14U },
  { Oi::T7, 15U },
  { Oi::T7_64, 15U },
  { Oi::T8, 24U },
  { Oi::T8_64, 24U },
  { Oi::T9, 25U },
  { Oi::T9_64, 25U },
  { Oi::V0, 2U },
  { Oi::V0_64, 2U },
  { Oi::V1, 3U },
  { Oi::V1_64, 3U },
  { Oi::ZERO, 0U },
  { Oi::ZERO_64, 0U },
};
extern const unsigned OiDwarfFlavour0L2DwarfSize = sizeof(OiDwarfFlavour0L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair OiEHFlavour0L2Dwarf[] = {
  { Oi::A0, 4U },
  { Oi::A0_64, 4U },
  { Oi::A1, 5U },
  { Oi::A1_64, 5U },
  { Oi::A2, 6U },
  { Oi::A2_64, 6U },
  { Oi::A3, 7U },
  { Oi::A3_64, 7U },
  { Oi::AT, 1U },
  { Oi::AT_64, 1U },
  { Oi::D0_64, 32U },
  { Oi::D1_64, 33U },
  { Oi::D2_64, 34U },
  { Oi::D3_64, 35U },
  { Oi::D4_64, 36U },
  { Oi::D5_64, 37U },
  { Oi::D6_64, 38U },
  { Oi::D7_64, 39U },
  { Oi::D8_64, 40U },
  { Oi::D9_64, 41U },
  { Oi::D10_64, 42U },
  { Oi::D11_64, 43U },
  { Oi::D12_64, 44U },
  { Oi::D13_64, 45U },
  { Oi::D14_64, 46U },
  { Oi::D15_64, 47U },
  { Oi::D16_64, 48U },
  { Oi::D17_64, 49U },
  { Oi::D18_64, 50U },
  { Oi::D19_64, 51U },
  { Oi::D20_64, 52U },
  { Oi::D21_64, 53U },
  { Oi::D22_64, 54U },
  { Oi::D23_64, 55U },
  { Oi::D24_64, 56U },
  { Oi::D25_64, 57U },
  { Oi::D26_64, 58U },
  { Oi::D27_64, 59U },
  { Oi::D28_64, 60U },
  { Oi::D29_64, 61U },
  { Oi::D30_64, 62U },
  { Oi::D31_64, 63U },
  { Oi::F0, 32U },
  { Oi::F1, 33U },
  { Oi::F2, 34U },
  { Oi::F3, 35U },
  { Oi::F4, 36U },
  { Oi::F5, 37U },
  { Oi::F6, 38U },
  { Oi::F7, 39U },
  { Oi::F8, 40U },
  { Oi::F9, 41U },
  { Oi::F10, 42U },
  { Oi::F11, 43U },
  { Oi::F12, 44U },
  { Oi::F13, 45U },
  { Oi::F14, 46U },
  { Oi::F15, 47U },
  { Oi::F16, 48U },
  { Oi::F17, 49U },
  { Oi::F18, 50U },
  { Oi::F19, 51U },
  { Oi::F20, 52U },
  { Oi::F21, 53U },
  { Oi::F22, 54U },
  { Oi::F23, 55U },
  { Oi::F24, 56U },
  { Oi::F25, 57U },
  { Oi::F26, 58U },
  { Oi::F27, 59U },
  { Oi::F28, 60U },
  { Oi::F29, 61U },
  { Oi::F30, 62U },
  { Oi::F31, 63U },
  { Oi::FP, 30U },
  { Oi::FP_64, 30U },
  { Oi::GP, 28U },
  { Oi::GP_64, 28U },
  { Oi::HI, 64U },
  { Oi::K0, 26U },
  { Oi::K0_64, 26U },
  { Oi::K1, 27U },
  { Oi::K1_64, 27U },
  { Oi::LO, 65U },
  { Oi::RA, 31U },
  { Oi::RA_64, 31U },
  { Oi::S0, 16U },
  { Oi::S0_64, 16U },
  { Oi::S1, 17U },
  { Oi::S1_64, 17U },
  { Oi::S2, 18U },
  { Oi::S2_64, 18U },
  { Oi::S3, 19U },
  { Oi::S3_64, 19U },
  { Oi::S4, 20U },
  { Oi::S4_64, 20U },
  { Oi::S5, 21U },
  { Oi::S5_64, 21U },
  { Oi::S6, 22U },
  { Oi::S6_64, 22U },
  { Oi::S7, 23U },
  { Oi::S7_64, 23U },
  { Oi::SP, 29U },
  { Oi::SP_64, 29U },
  { Oi::T0, 8U },
  { Oi::T0_64, 8U },
  { Oi::T1, 9U },
  { Oi::T1_64, 9U },
  { Oi::T2, 10U },
  { Oi::T2_64, 10U },
  { Oi::T3, 11U },
  { Oi::T3_64, 11U },
  { Oi::T4, 12U },
  { Oi::T4_64, 12U },
  { Oi::T5, 13U },
  { Oi::T5_64, 13U },
  { Oi::T6, 14U },
  { Oi::T6_64, 14U },
  { Oi::T7, 15U },
  { Oi::T7_64, 15U },
  { Oi::T8, 24U },
  { Oi::T8_64, 24U },
  { Oi::T9, 25U },
  { Oi::T9_64, 25U },
  { Oi::V0, 2U },
  { Oi::V0_64, 2U },
  { Oi::V1, 3U },
  { Oi::V1_64, 3U },
  { Oi::ZERO, 0U },
  { Oi::ZERO_64, 0U },
};
extern const unsigned OiEHFlavour0L2DwarfSize = sizeof(OiEHFlavour0L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const uint16_t OiRegEncodingTable[] = {
  0,
  4,
  4,
  5,
  5,
  6,
  6,
  7,
  7,
  0,
  1,
  2,
  3,
  1,
  1,
  0,
  0,
  2,
  1,
  4,
  2,
  6,
  3,
  8,
  4,
  10,
  5,
  12,
  6,
  14,
  7,
  16,
  8,
  18,
  9,
  20,
  10,
  22,
  11,
  24,
  12,
  26,
  13,
  28,
  14,
  30,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
  30,
  31,
  0,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
  30,
  31,
  0,
  0,
  30,
  30,
  28,
  28,
  0,
  0,
  29,
  29,
  26,
  26,
  27,
  27,
  0,
  0,
  0,
  31,
  31,
  16,
  16,
  17,
  17,
  18,
  18,
  19,
  19,
  20,
  20,
  21,
  21,
  22,
  22,
  23,
  23,
  29,
  29,
  8,
  8,
  9,
  9,
  10,
  10,
  11,
  11,
  12,
  12,
  13,
  13,
  14,
  14,
  15,
  15,
  24,
  24,
  25,
  25,
  2,
  2,
  3,
  3,
  0,
  0,
};
static inline void InitOiMCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(OiRegDesc, 159, RA, PC, OiMCRegisterClasses, 19, OiRegUnitRoots, 75, OiRegDiffLists, OiRegStrings, OiSubRegIdxLists, 6,
  OiRegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(OiDwarfFlavour0Dwarf2L, OiDwarfFlavour0Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(OiEHFlavour0Dwarf2L, OiEHFlavour0Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(OiDwarfFlavour0L2Dwarf, OiDwarfFlavour0L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(OiEHFlavour0L2Dwarf, OiEHFlavour0L2DwarfSize, true);
    break;
  }
}

} // End llvm namespace 
#endif // GET_REGINFO_MC_DESC

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Register Information Header Fragment                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_HEADER
#undef GET_REGINFO_HEADER
#include "llvm/Target/TargetRegisterInfo.h"

namespace llvm {

struct OiGenRegisterInfo : public TargetRegisterInfo {
  explicit OiGenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0, unsigned PC = 0);
  virtual bool needsStackRealignment(const MachineFunction &) const
     { return false; }
  virtual unsigned composeSubRegIndicesImpl(unsigned, unsigned) const;
  virtual const TargetRegisterClass *getSubClassWithSubReg(const TargetRegisterClass*, unsigned) const;
  virtual const RegClassWeight &getRegClassWeight(const TargetRegisterClass *RC) const;
  virtual unsigned getRegUnitWeight(unsigned RegUnit) const;
  virtual unsigned getNumRegPressureSets() const;
  virtual const char *getRegPressureSetName(unsigned Idx) const;
  virtual unsigned getRegPressureSetLimit(unsigned Idx) const;
  virtual const int *getRegClassPressureSets(const TargetRegisterClass *RC) const;
  virtual const int *getRegUnitPressureSets(unsigned RegUnit) const;
};

namespace Oi { // Register classes
  extern const TargetRegisterClass CPURegsRegClass;
  extern const TargetRegisterClass DSPRegsRegClass;
  extern const TargetRegisterClass FGR32RegClass;
  extern const TargetRegisterClass CPU16RegsRegClass;
  extern const TargetRegisterClass CCRRegClass;
  extern const TargetRegisterClass HILORegClass;
  extern const TargetRegisterClass CPURARegRegClass;
  extern const TargetRegisterClass CPUSPRegRegClass;
  extern const TargetRegisterClass HWRegsRegClass;
  extern const TargetRegisterClass HWRegs64RegClass;
  extern const TargetRegisterClass CPU64RegsRegClass;
  extern const TargetRegisterClass FGR64RegClass;
  extern const TargetRegisterClass AFGR64RegClass;
  extern const TargetRegisterClass CPU64Regs_with_sub_32_in_CPU16RegsRegClass;
  extern const TargetRegisterClass ACRegsRegClass;
  extern const TargetRegisterClass HILO64RegClass;
  extern const TargetRegisterClass ACRegs_with_sub_hiRegClass;
  extern const TargetRegisterClass CPU64Regs_with_sub_32_in_CPURARegRegClass;
  extern const TargetRegisterClass CPU64Regs_with_sub_32_in_CPUSPRegRegClass;
} // end of namespace Oi

} // End llvm namespace 
#endif // GET_REGINFO_HEADER

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Register and Register Classes Information                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_TARGET_DESC
#undef GET_REGINFO_TARGET_DESC
namespace llvm {

extern const MCRegisterClass OiMCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i32, MVT::Other,
  /* 2 */ MVT::i64, MVT::Other,
  /* 4 */ MVT::f32, MVT::Other,
  /* 6 */ MVT::f64, MVT::Other,
  /* 8 */ MVT::v4i8, MVT::v2i16, MVT::Other,
};

static const char *const SubRegIndexNameTable[] = { "sub_32", "sub_fpeven", "sub_fpodd", "sub_hi", "sub_lo" };


static const unsigned SubRegIndexLaneMaskTable[] = {
  ~0u,
  0x00000001, // sub_32
  0x00000002, // sub_fpeven
  0x00000004, // sub_fpodd
  0x00000008, // sub_hi
  0x00000010, // sub_lo
 };



static const TargetRegisterClass *const NullRegClasses[] = { NULL };

static const uint32_t CPURegsSubClassMask[] = {
  0x000000cb, 
  0x00062400, // sub_32
};

static const uint32_t DSPRegsSubClassMask[] = {
  0x000000cb, 
  0x00062400, // sub_32
};

static const uint32_t FGR32SubClassMask[] = {
  0x00000004, 
  0x00000800, // sub_32
  0x00001000, // sub_fpeven
  0x00001000, // sub_fpodd
};

static const uint32_t CPU16RegsSubClassMask[] = {
  0x00000008, 
  0x00002000, // sub_32
};

static const uint32_t CCRSubClassMask[] = {
  0x00000010, 
};

static const uint32_t HILOSubClassMask[] = {
  0x00000020, 
  0x00008000, // sub_32
  0x00010000, // sub_hi
  0x00010000, // sub_lo
};

static const uint32_t CPURARegSubClassMask[] = {
  0x00000040, 
  0x00020000, // sub_32
};

static const uint32_t CPUSPRegSubClassMask[] = {
  0x00000080, 
  0x00040000, // sub_32
};

static const uint32_t HWRegsSubClassMask[] = {
  0x00000100, 
};

static const uint32_t HWRegs64SubClassMask[] = {
  0x00000200, 
};

static const uint32_t CPU64RegsSubClassMask[] = {
  0x00062400, 
};

static const uint32_t FGR64SubClassMask[] = {
  0x00000800, 
};

static const uint32_t AFGR64SubClassMask[] = {
  0x00001000, 
};

static const uint32_t CPU64Regs_with_sub_32_in_CPU16RegsSubClassMask[] = {
  0x00002000, 
};

static const uint32_t ACRegsSubClassMask[] = {
  0x00014000, 
};

static const uint32_t HILO64SubClassMask[] = {
  0x00008000, 
};

static const uint32_t ACRegs_with_sub_hiSubClassMask[] = {
  0x00010000, 
};

static const uint32_t CPU64Regs_with_sub_32_in_CPURARegSubClassMask[] = {
  0x00020000, 
};

static const uint32_t CPU64Regs_with_sub_32_in_CPUSPRegSubClassMask[] = {
  0x00040000, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 1, 0,
  /* 2 */ 1, 2, 3, 0,
  /* 6 */ 1, 4, 5, 0,
};

static const TargetRegisterClass *const CPURegsSuperclasses[] = {
  &Oi::DSPRegsRegClass,
  NULL
};

static const TargetRegisterClass *const DSPRegsSuperclasses[] = {
  &Oi::CPURegsRegClass,
  NULL
};

static const TargetRegisterClass *const CPU16RegsSuperclasses[] = {
  &Oi::CPURegsRegClass,
  &Oi::DSPRegsRegClass,
  NULL
};

static const TargetRegisterClass *const CPURARegSuperclasses[] = {
  &Oi::CPURegsRegClass,
  &Oi::DSPRegsRegClass,
  NULL
};

static const TargetRegisterClass *const CPUSPRegSuperclasses[] = {
  &Oi::CPURegsRegClass,
  &Oi::DSPRegsRegClass,
  NULL
};

static const TargetRegisterClass *const CPU64Regs_with_sub_32_in_CPU16RegsSuperclasses[] = {
  &Oi::CPU64RegsRegClass,
  NULL
};

static const TargetRegisterClass *const ACRegs_with_sub_hiSuperclasses[] = {
  &Oi::ACRegsRegClass,
  NULL
};

static const TargetRegisterClass *const CPU64Regs_with_sub_32_in_CPURARegSuperclasses[] = {
  &Oi::CPU64RegsRegClass,
  NULL
};

static const TargetRegisterClass *const CPU64Regs_with_sub_32_in_CPUSPRegSuperclasses[] = {
  &Oi::CPU64RegsRegClass,
  NULL
};

namespace Oi {   // Register class instances
  extern const TargetRegisterClass CPURegsRegClass = {
    &OiMCRegisterClasses[CPURegsRegClassID],
    VTLists + 0,
    CPURegsSubClassMask,
    SuperRegIdxSeqs + 0,
    CPURegsSuperclasses,
    0
  };

  extern const TargetRegisterClass DSPRegsRegClass = {
    &OiMCRegisterClasses[DSPRegsRegClassID],
    VTLists + 8,
    DSPRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    DSPRegsSuperclasses,
    0
  };

  extern const TargetRegisterClass FGR32RegClass = {
    &OiMCRegisterClasses[FGR32RegClassID],
    VTLists + 4,
    FGR32SubClassMask,
    SuperRegIdxSeqs + 2,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass CPU16RegsRegClass = {
    &OiMCRegisterClasses[CPU16RegsRegClassID],
    VTLists + 0,
    CPU16RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    CPU16RegsSuperclasses,
    0
  };

  extern const TargetRegisterClass CCRRegClass = {
    &OiMCRegisterClasses[CCRRegClassID],
    VTLists + 0,
    CCRSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass HILORegClass = {
    &OiMCRegisterClasses[HILORegClassID],
    VTLists + 0,
    HILOSubClassMask,
    SuperRegIdxSeqs + 6,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass CPURARegRegClass = {
    &OiMCRegisterClasses[CPURARegRegClassID],
    VTLists + 0,
    CPURARegSubClassMask,
    SuperRegIdxSeqs + 0,
    CPURARegSuperclasses,
    0
  };

  extern const TargetRegisterClass CPUSPRegRegClass = {
    &OiMCRegisterClasses[CPUSPRegRegClassID],
    VTLists + 0,
    CPUSPRegSubClassMask,
    SuperRegIdxSeqs + 0,
    CPUSPRegSuperclasses,
    0
  };

  extern const TargetRegisterClass HWRegsRegClass = {
    &OiMCRegisterClasses[HWRegsRegClassID],
    VTLists + 0,
    HWRegsSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass HWRegs64RegClass = {
    &OiMCRegisterClasses[HWRegs64RegClassID],
    VTLists + 2,
    HWRegs64SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass CPU64RegsRegClass = {
    &OiMCRegisterClasses[CPU64RegsRegClassID],
    VTLists + 2,
    CPU64RegsSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass FGR64RegClass = {
    &OiMCRegisterClasses[FGR64RegClassID],
    VTLists + 6,
    FGR64SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass AFGR64RegClass = {
    &OiMCRegisterClasses[AFGR64RegClassID],
    VTLists + 6,
    AFGR64SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass CPU64Regs_with_sub_32_in_CPU16RegsRegClass = {
    &OiMCRegisterClasses[CPU64Regs_with_sub_32_in_CPU16RegsRegClassID],
    VTLists + 2,
    CPU64Regs_with_sub_32_in_CPU16RegsSubClassMask,
    SuperRegIdxSeqs + 1,
    CPU64Regs_with_sub_32_in_CPU16RegsSuperclasses,
    0
  };

  extern const TargetRegisterClass ACRegsRegClass = {
    &OiMCRegisterClasses[ACRegsRegClassID],
    VTLists + 2,
    ACRegsSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass HILO64RegClass = {
    &OiMCRegisterClasses[HILO64RegClassID],
    VTLists + 2,
    HILO64SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass ACRegs_with_sub_hiRegClass = {
    &OiMCRegisterClasses[ACRegs_with_sub_hiRegClassID],
    VTLists + 2,
    ACRegs_with_sub_hiSubClassMask,
    SuperRegIdxSeqs + 1,
    ACRegs_with_sub_hiSuperclasses,
    0
  };

  extern const TargetRegisterClass CPU64Regs_with_sub_32_in_CPURARegRegClass = {
    &OiMCRegisterClasses[CPU64Regs_with_sub_32_in_CPURARegRegClassID],
    VTLists + 2,
    CPU64Regs_with_sub_32_in_CPURARegSubClassMask,
    SuperRegIdxSeqs + 1,
    CPU64Regs_with_sub_32_in_CPURARegSuperclasses,
    0
  };

  extern const TargetRegisterClass CPU64Regs_with_sub_32_in_CPUSPRegRegClass = {
    &OiMCRegisterClasses[CPU64Regs_with_sub_32_in_CPUSPRegRegClassID],
    VTLists + 2,
    CPU64Regs_with_sub_32_in_CPUSPRegSubClassMask,
    SuperRegIdxSeqs + 1,
    CPU64Regs_with_sub_32_in_CPUSPRegSuperclasses,
    0
  };

}

namespace {
  const TargetRegisterClass* const RegisterClasses[] = {
    &Oi::CPURegsRegClass,
    &Oi::DSPRegsRegClass,
    &Oi::FGR32RegClass,
    &Oi::CPU16RegsRegClass,
    &Oi::CCRRegClass,
    &Oi::HILORegClass,
    &Oi::CPURARegRegClass,
    &Oi::CPUSPRegRegClass,
    &Oi::HWRegsRegClass,
    &Oi::HWRegs64RegClass,
    &Oi::CPU64RegsRegClass,
    &Oi::FGR64RegClass,
    &Oi::AFGR64RegClass,
    &Oi::CPU64Regs_with_sub_32_in_CPU16RegsRegClass,
    &Oi::ACRegsRegClass,
    &Oi::HILO64RegClass,
    &Oi::ACRegs_with_sub_hiRegClass,
    &Oi::CPU64Regs_with_sub_32_in_CPURARegRegClass,
    &Oi::CPU64Regs_with_sub_32_in_CPUSPRegRegClass,
  };
}

static const TargetRegisterInfoDesc OiRegInfoDesc[] = { // Extra Descriptors
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
};
unsigned OiGenRegisterInfo::composeSubRegIndicesImpl(unsigned IdxA, unsigned IdxB) const {
  static const uint8_t Rows[1][5] = {
    { 0, 0, 0, 0, 0, },
  };

  --IdxA; assert(IdxA < 5);
  --IdxB; assert(IdxB < 5);
  return Rows[0][IdxB];
}

const TargetRegisterClass *OiGenRegisterInfo::getSubClassWithSubReg(const TargetRegisterClass *RC, unsigned Idx) const {
  static const uint8_t Table[19][5] = {
    {	// CPURegs
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// DSPRegs
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// FGR32
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// CPU16Regs
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// CCR
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// HILO
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// CPURAReg
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// CPUSPReg
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// HWRegs
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// HWRegs64
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// CPU64Regs
      11,	// sub_32 -> CPU64Regs
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// FGR64
      12,	// sub_32 -> FGR64
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// AFGR64
      0,	// sub_32
      13,	// sub_fpeven -> AFGR64
      13,	// sub_fpodd -> AFGR64
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// CPU64Regs_with_sub_32_in_CPU16Regs
      14,	// sub_32 -> CPU64Regs_with_sub_32_in_CPU16Regs
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// ACRegs
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      17,	// sub_hi -> ACRegs_with_sub_hi
      17,	// sub_lo -> ACRegs_with_sub_hi
    },
    {	// HILO64
      16,	// sub_32 -> HILO64
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// ACRegs_with_sub_hi
      0,	// sub_32
      0,	// sub_fpeven
      0,	// sub_fpodd
      17,	// sub_hi -> ACRegs_with_sub_hi
      17,	// sub_lo -> ACRegs_with_sub_hi
    },
    {	// CPU64Regs_with_sub_32_in_CPURAReg
      18,	// sub_32 -> CPU64Regs_with_sub_32_in_CPURAReg
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
    {	// CPU64Regs_with_sub_32_in_CPUSPReg
      19,	// sub_32 -> CPU64Regs_with_sub_32_in_CPUSPReg
      0,	// sub_fpeven
      0,	// sub_fpodd
      0,	// sub_hi
      0,	// sub_lo
    },
  };
  assert(RC && "Missing regclass");
  if (!Idx) return RC;
  --Idx;
  assert(Idx < 5 && "Bad subreg");
  unsigned TV = Table[RC->getID()][Idx];
  return TV ? getRegClass(TV - 1) : 0;
}

/// Get the weight in units of pressure for this register class.
const RegClassWeight &OiGenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 32},  	// CPURegs
    {1, 32},  	// DSPRegs
    {1, 32},  	// FGR32
    {1, 8},  	// CPU16Regs
    {1, 2},  	// CCR
    {1, 2},  	// HILO
    {1, 1},  	// CPURAReg
    {1, 1},  	// CPUSPReg
    {1, 1},  	// HWRegs
    {1, 1},  	// HWRegs64
    {1, 32},  	// CPU64Regs
    {1, 32},  	// FGR64
    {2, 32},  	// AFGR64
    {1, 8},  	// CPU64Regs_with_sub_32_in_CPU16Regs
    {2, 8},  	// ACRegs
    {1, 2},  	// HILO64
    {2, 2},  	// ACRegs_with_sub_hi
    {1, 1},  	// CPU64Regs_with_sub_32_in_CPURAReg
    {1, 1},  	// CPU64Regs_with_sub_32_in_CPUSPReg
    {0, 0} };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned OiGenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 75 && "invalid register unit");
  static const uint8_t RUWeightTable[] = {
    1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
  return RUWeightTable[RegUnit];
}


// Get the number of dimensions of register pressure.
unsigned OiGenRegisterInfo::getNumRegPressureSets() const {
  return 10;
}

// Get the name of this register unit pressure set.
const char *OiGenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *PressureNameTable[] = {
    "CPURegs",
    "FGR32",
    "CPU16Regs",
    "CCR",
    "HILO",
    "CPURAReg",
    "CPUSPReg",
    "HWRegs",
    "HWRegs64",
    "ACRegs",
    0 };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned OiGenRegisterInfo::
getRegPressureSetLimit(unsigned Idx) const {
  static const unsigned PressureLimitTable[] = {
    32,  	// 0: CPURegs
    32,  	// 1: FGR32
    8,  	// 2: CPU16Regs
    2,  	// 3: CCR
    2,  	// 4: HILO
    1,  	// 5: CPURAReg
    1,  	// 6: CPUSPReg
    1,  	// 7: HWRegs
    1,  	// 8: HWRegs64
    8,  	// 9: ACRegs
    0 };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
    0,  -1,  	// #0 CPURegs
    0,  -1,  	// #2 DSPRegs
    1,  -1,  	// #4 FGR32
    0,  2,  -1,  	// #6 CPU16Regs
    3,  -1,  	// #9 CCR
    4,  9,  -1,  	// #11 HILO
    0,  5,  -1,  	// #14 CPURAReg
    0,  6,  -1,  	// #17 CPUSPReg
    7,  -1,  	// #20 HWRegs
    8,  -1,  	// #22 HWRegs64
    0,  -1,  	// #24 CPU64Regs
    1,  -1,  	// #26 FGR64
    1,  -1,  	// #28 AFGR64
    0,  2,  -1,  	// #30 CPU64Regs_with_sub_32_in_CPU16Regs
    9,  -1,  	// #33 ACRegs
    4,  9,  -1,  	// #35 HILO64
    4,  9,  -1,  	// #38 ACRegs_with_sub_hi
    0,  5,  -1,  	// #41 CPU64Regs_with_sub_32_in_CPURAReg
    0,  6,  -1,  	// #44 CPU64Regs_with_sub_32_in_CPUSPReg
    -1,  	// #47 inferred
    -1 };

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int* OiGenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const unsigned RCSetStartTable[] = {
    0,2,4,6,9,11,14,17,20,22,24,26,28,30,33,35,38,41,44,0 };
  unsigned SetListStart = RCSetStartTable[RC->getID()];
  return &RCSetsTable[SetListStart];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int* OiGenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 75 && "invalid register unit");
  static const unsigned RUSetStartTable[] = {
    6,6,6,6,11,11,33,33,33,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,47,9,9,0,0,20,22,0,0,47,14,6,6,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,6,6,0,0 };
  unsigned SetListStart = RUSetStartTable[RegUnit];
  return &RCSetsTable[SetListStart];
}

extern const MCRegisterDesc OiRegDesc[];
extern const MCPhysReg OiRegDiffLists[];
extern const char OiRegStrings[];
extern const uint16_t OiRegUnitRoots[][2];
extern const uint16_t OiSubRegIdxLists[];
extern const uint16_t OiRegEncodingTable[];
// Oi Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair OiDwarfFlavour0Dwarf2L[];
extern const unsigned OiDwarfFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair OiEHFlavour0Dwarf2L[];
extern const unsigned OiEHFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair OiDwarfFlavour0L2Dwarf[];
extern const unsigned OiDwarfFlavour0L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair OiEHFlavour0L2Dwarf[];
extern const unsigned OiEHFlavour0L2DwarfSize;

OiGenRegisterInfo::
OiGenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour, unsigned PC)
  : TargetRegisterInfo(OiRegInfoDesc, RegisterClasses, RegisterClasses+19,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable) {
  InitMCRegisterInfo(OiRegDesc, 159, RA, PC,
                     OiMCRegisterClasses, 19,
                     OiRegUnitRoots,
                     75,
                     OiRegDiffLists,
                     OiRegStrings,
                     OiSubRegIdxLists,
                     6,
                     OiRegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(OiDwarfFlavour0Dwarf2L, OiDwarfFlavour0Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(OiEHFlavour0Dwarf2L, OiEHFlavour0Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(OiDwarfFlavour0L2Dwarf, OiDwarfFlavour0L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(OiEHFlavour0L2Dwarf, OiEHFlavour0L2DwarfSize, true);
    break;
  }
}

static const MCPhysReg CSR_N32_SaveList[] = { Oi::D31_64, Oi::D29_64, Oi::D27_64, Oi::D25_64, Oi::D24_64, Oi::D23_64, Oi::D22_64, Oi::D21_64, Oi::RA_64, Oi::FP_64, Oi::GP_64, Oi::S7_64, Oi::S6_64, Oi::S5_64, Oi::S4_64, Oi::S3_64, Oi::S2_64, Oi::S1_64, Oi::S0_64, 0 };
static const uint32_t CSR_N32_RegMask[] = { 0x00000000, 0x55f000a0, 0xabe00000, 0xfffe003c, 0x00000007, };
static const MCPhysReg CSR_N64_SaveList[] = { Oi::D31_64, Oi::D30_64, Oi::D29_64, Oi::D28_64, Oi::D27_64, Oi::D26_64, Oi::D25_64, Oi::D24_64, Oi::RA_64, Oi::FP_64, Oi::GP_64, Oi::S7_64, Oi::S6_64, Oi::S5_64, Oi::S4_64, Oi::S3_64, Oi::S2_64, Oi::S1_64, Oi::S0_64, 0 };
static const uint32_t CSR_N64_RegMask[] = { 0x00000000, 0x7f802a80, 0xff000000, 0xfffe003c, 0x00000007, };
static const MCPhysReg CSR_O32_SaveList[] = { Oi::D15, Oi::D14, Oi::D13, Oi::D12, Oi::D11, Oi::D10, Oi::RA, Oi::FP, Oi::S7, Oi::S6, Oi::S5, Oi::S4, Oi::S3, Oi::S2, Oi::S1, Oi::S0, 0 };
static const uint32_t CSR_O32_RegMask[] = { 0x00000000, 0x00002aa8, 0xfff00000, 0xaaaa0004, 0x00000002, };
static const MCPhysReg CSR_SingleFloatOnly_SaveList[] = { Oi::F31, Oi::F30, Oi::F29, Oi::F28, Oi::F27, Oi::F26, Oi::F25, Oi::F24, Oi::F23, Oi::F22, Oi::F21, Oi::F20, Oi::RA, Oi::FP, Oi::S7, Oi::S6, Oi::S5, Oi::S4, Oi::S3, Oi::S2, Oi::S1, Oi::S0, 0 };
static const uint32_t CSR_SingleFloatOnly_RegMask[] = { 0x00000000, 0x00002aa8, 0xfff00000, 0xaaaa0004, 0x00000002, };


} // End llvm namespace 
#endif // GET_REGINFO_TARGET_DESC

