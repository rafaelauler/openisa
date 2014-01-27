//===-- OiRegisterInfo.td - Oi Register defs -----------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the OI register file
//===----------------------------------------------------------------------===//
let Namespace = "Oi" in {
def sub_fpeven : SubRegIndex;
def sub_fpodd  : SubRegIndex;
def sub_32     : SubRegIndex;
def sub_lo     : SubRegIndex;
def sub_hi     : SubRegIndex;
def sub_dsp16_19 : SubRegIndex;
def sub_dsp20    : SubRegIndex;
def sub_dsp21    : SubRegIndex;
def sub_dsp22    : SubRegIndex;
def sub_dsp23    : SubRegIndex;
}

class Unallocatable {
  bit isAllocatable = 0;
}

// We have banks of 32 registers each.
class OiReg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
  let Namespace = "Oi";
}

class OiRegWithSubRegs<bits<16> Enc, string n, list<Register> subregs>
  : RegisterWithSubRegs<n, subregs> {
  let HWEncoding = Enc;
  let Namespace = "Oi";
}

// Oi CPU Registers
class OiGPRReg<bits<16> Enc, string n> : OiReg<Enc, n>;

// Oi 64-bit CPU Registers
class Oi64GPRReg<bits<16> Enc, string n, list<Register> subregs>
  : OiRegWithSubRegs<Enc, n, subregs> {
  let SubRegIndices = [sub_32];
}

// Oi 32-bit FPU Registers
class FPR<bits<16> Enc, string n> : OiReg<Enc, n>;

// Oi 64-bit (aliased) FPU Registers
class AFPR<bits<16> Enc, string n, list<Register> subregs>
  : OiRegWithSubRegs<Enc, n, subregs> {
  let SubRegIndices = [sub_fpeven, sub_fpodd];
  let CoveredBySubRegs = 1;
}

class AFPR64<bits<16> Enc, string n, list<Register> subregs>
  : OiRegWithSubRegs<Enc, n, subregs> {
  let SubRegIndices = [sub_32];
}

// Accumulator Registers
class ACC<bits<16> Enc, string n, list<Register> subregs>
  : OiRegWithSubRegs<Enc, n, subregs> {
  let SubRegIndices = [sub_lo, sub_hi];
  let CoveredBySubRegs = 1;
}

// Oi Hardware Registers
class HWR<bits<16> Enc, string n> : OiReg<Enc, n>;

//===----------------------------------------------------------------------===//
//  Registers
//===----------------------------------------------------------------------===//

let Namespace = "Oi" in {
  // General Purpose Registers
  def ZERO : OiGPRReg< 0, "zero">, DwarfRegNum<[0]>;
  def AT   : OiGPRReg< 1, "1">,    DwarfRegNum<[1]>;
  def V0   : OiGPRReg< 2, "2">,    DwarfRegNum<[2]>;
  def V1   : OiGPRReg< 3, "3">,    DwarfRegNum<[3]>;
  def A0   : OiGPRReg< 4, "4">,    DwarfRegNum<[4]>;
  def A1   : OiGPRReg< 5, "5">,    DwarfRegNum<[5]>;
  def A2   : OiGPRReg< 6, "6">,    DwarfRegNum<[6]>;
  def A3   : OiGPRReg< 7, "7">,    DwarfRegNum<[7]>;
  def T0   : OiGPRReg< 8, "8">,    DwarfRegNum<[8]>;
  def T1   : OiGPRReg< 9, "9">,    DwarfRegNum<[9]>;
  def T2   : OiGPRReg< 10, "10">,  DwarfRegNum<[10]>;
  def T3   : OiGPRReg< 11, "11">,  DwarfRegNum<[11]>;
  def T4   : OiGPRReg< 12, "12">,  DwarfRegNum<[12]>;
  def T5   : OiGPRReg< 13, "13">,  DwarfRegNum<[13]>;
  def T6   : OiGPRReg< 14, "14">,  DwarfRegNum<[14]>;
  def T7   : OiGPRReg< 15, "15">,  DwarfRegNum<[15]>;
  def S0   : OiGPRReg< 16, "16">,  DwarfRegNum<[16]>;
  def S1   : OiGPRReg< 17, "17">,  DwarfRegNum<[17]>;
  def S2   : OiGPRReg< 18, "18">,  DwarfRegNum<[18]>;
  def S3   : OiGPRReg< 19, "19">,  DwarfRegNum<[19]>;
  def S4   : OiGPRReg< 20, "20">,  DwarfRegNum<[20]>;
  def S5   : OiGPRReg< 21, "21">,  DwarfRegNum<[21]>;
  def S6   : OiGPRReg< 22, "22">,  DwarfRegNum<[22]>;
  def S7   : OiGPRReg< 23, "23">,  DwarfRegNum<[23]>;
  def T8   : OiGPRReg< 24, "24">,  DwarfRegNum<[24]>;
  def T9   : OiGPRReg< 25, "25">,  DwarfRegNum<[25]>;
  def K0   : OiGPRReg< 26, "26">,  DwarfRegNum<[26]>;
  def K1   : OiGPRReg< 27, "27">,  DwarfRegNum<[27]>;
  def GP   : OiGPRReg< 28, "gp">,  DwarfRegNum<[28]>;
  def SP   : OiGPRReg< 29, "sp">,  DwarfRegNum<[29]>;
  def FP   : OiGPRReg< 30, "fp">,  DwarfRegNum<[30]>;
  def RA   : OiGPRReg< 31, "ra">,  DwarfRegNum<[31]>;
  def R32  : OiGPRReg< 32, "32">,  DwarfRegNum<[32]>;
  def R33  : OiGPRReg< 33, "33">,  DwarfRegNum<[33]>;
  def R34  : OiGPRReg< 34, "34">,  DwarfRegNum<[34]>;
  def R35  : OiGPRReg< 35, "35">,  DwarfRegNum<[35]>;
  def R36  : OiGPRReg< 36, "36">,  DwarfRegNum<[36]>;
  def R37  : OiGPRReg< 37, "37">,  DwarfRegNum<[37]>;
  def R38  : OiGPRReg< 38, "38">,  DwarfRegNum<[38]>;
  def R39  : OiGPRReg< 39, "39">,  DwarfRegNum<[39]>;
  def R40  : OiGPRReg< 40, "40">,  DwarfRegNum<[40]>;
  def R41  : OiGPRReg< 41, "41">,  DwarfRegNum<[41]>;
  def R42  : OiGPRReg< 42, "42">,  DwarfRegNum<[42]>;
  def R43  : OiGPRReg< 43, "43">,  DwarfRegNum<[43]>;
  def R44  : OiGPRReg< 44, "44">,  DwarfRegNum<[44]>;
  def R45  : OiGPRReg< 45, "45">,  DwarfRegNum<[45]>;
  def R46  : OiGPRReg< 46, "46">,  DwarfRegNum<[46]>;
  def R47  : OiGPRReg< 47, "47">,  DwarfRegNum<[47]>;
  def R48  : OiGPRReg< 48, "48">,  DwarfRegNum<[48]>;
  def R49  : OiGPRReg< 49, "49">,  DwarfRegNum<[49]>;
  def R50  : OiGPRReg< 50, "50">,  DwarfRegNum<[50]>;
  def R51  : OiGPRReg< 51, "51">,  DwarfRegNum<[51]>;
  def R52  : OiGPRReg< 52, "52">,  DwarfRegNum<[52]>;
  def R53  : OiGPRReg< 53, "53">,  DwarfRegNum<[53]>;
  def R54  : OiGPRReg< 54, "54">,  DwarfRegNum<[54]>;
  def R55  : OiGPRReg< 55, "55">,  DwarfRegNum<[55]>;
  def R56  : OiGPRReg< 56, "56">,  DwarfRegNum<[56]>;
  def R57  : OiGPRReg< 57, "57">,  DwarfRegNum<[57]>;
  def R58  : OiGPRReg< 58, "58">,  DwarfRegNum<[58]>;
  def R59  : OiGPRReg< 59, "59">,  DwarfRegNum<[59]>;
  def R60  : OiGPRReg< 60, "60">,  DwarfRegNum<[60]>;
  def R61  : OiGPRReg< 61, "61">,  DwarfRegNum<[61]>;
  def R62  : OiGPRReg< 62, "62">,  DwarfRegNum<[62]>;
  def R63  : OiGPRReg< 63, "63">,  DwarfRegNum<[63]>;
  def R64  : OiGPRReg< 64, "64">,  DwarfRegNum<[64]>;
  def R65  : OiGPRReg< 65, "65">,  DwarfRegNum<[65]>;



  // General Purpose 64-bit Registers
  def ZERO_64 : Oi64GPRReg< 0, "zero", [ZERO]>, DwarfRegNum<[0]>;
  def AT_64   : Oi64GPRReg< 1, "1",    [AT]>, DwarfRegNum<[1]>;
  def V0_64   : Oi64GPRReg< 2, "2",    [V0]>, DwarfRegNum<[2]>;
  def V1_64   : Oi64GPRReg< 3, "3",    [V1]>, DwarfRegNum<[3]>;
  def A0_64   : Oi64GPRReg< 4, "4",    [A0]>, DwarfRegNum<[4]>;
  def A1_64   : Oi64GPRReg< 5, "5",    [A1]>, DwarfRegNum<[5]>;
  def A2_64   : Oi64GPRReg< 6, "6",    [A2]>, DwarfRegNum<[6]>;
  def A3_64   : Oi64GPRReg< 7, "7",    [A3]>, DwarfRegNum<[7]>;
  def T0_64   : Oi64GPRReg< 8, "8",    [T0]>, DwarfRegNum<[8]>;
  def T1_64   : Oi64GPRReg< 9, "9",    [T1]>, DwarfRegNum<[9]>;
  def T2_64   : Oi64GPRReg< 10, "10",  [T2]>, DwarfRegNum<[10]>;
  def T3_64   : Oi64GPRReg< 11, "11",  [T3]>, DwarfRegNum<[11]>;
  def T4_64   : Oi64GPRReg< 12, "12",  [T4]>, DwarfRegNum<[12]>;
  def T5_64   : Oi64GPRReg< 13, "13",  [T5]>, DwarfRegNum<[13]>;
  def T6_64   : Oi64GPRReg< 14, "14",  [T6]>, DwarfRegNum<[14]>;
  def T7_64   : Oi64GPRReg< 15, "15",  [T7]>, DwarfRegNum<[15]>;
  def S0_64   : Oi64GPRReg< 16, "16",  [S0]>, DwarfRegNum<[16]>;
  def S1_64   : Oi64GPRReg< 17, "17",  [S1]>, DwarfRegNum<[17]>;
  def S2_64   : Oi64GPRReg< 18, "18",  [S2]>, DwarfRegNum<[18]>;
  def S3_64   : Oi64GPRReg< 19, "19",  [S3]>, DwarfRegNum<[19]>;
  def S4_64   : Oi64GPRReg< 20, "20",  [S4]>, DwarfRegNum<[20]>;
  def S5_64   : Oi64GPRReg< 21, "21",  [S5]>, DwarfRegNum<[21]>;
  def S6_64   : Oi64GPRReg< 22, "22",  [S6]>, DwarfRegNum<[22]>;
  def S7_64   : Oi64GPRReg< 23, "23",  [S7]>, DwarfRegNum<[23]>;
  def T8_64   : Oi64GPRReg< 24, "24",  [T8]>, DwarfRegNum<[24]>;
  def T9_64   : Oi64GPRReg< 25, "25",  [T9]>, DwarfRegNum<[25]>;
  def K0_64   : Oi64GPRReg< 26, "26",  [K0]>, DwarfRegNum<[26]>;
  def K1_64   : Oi64GPRReg< 27, "27",  [K1]>, DwarfRegNum<[27]>;
  def GP_64   : Oi64GPRReg< 28, "gp",  [GP]>, DwarfRegNum<[28]>;
  def SP_64   : Oi64GPRReg< 29, "sp",  [SP]>, DwarfRegNum<[29]>;
  def FP_64   : Oi64GPRReg< 30, "fp",  [FP]>, DwarfRegNum<[30]>;
  def RA_64   : Oi64GPRReg< 31, "ra",  [RA]>, DwarfRegNum<[31]>;

  /// Oi Single point precision FPU Registers
  def F0  : FPR< 0,  "f0">, DwarfRegNum<[32]>;
  def F1  : FPR< 1,  "f1">, DwarfRegNum<[33]>;
  def F2  : FPR< 2,  "f2">, DwarfRegNum<[34]>;
  def F3  : FPR< 3,  "f3">, DwarfRegNum<[35]>;
  def F4  : FPR< 4,  "f4">, DwarfRegNum<[36]>;
  def F5  : FPR< 5,  "f5">, DwarfRegNum<[37]>;
  def F6  : FPR< 6,  "f6">, DwarfRegNum<[38]>;
  def F7  : FPR< 7,  "f7">, DwarfRegNum<[39]>;
  def F8  : FPR< 8,  "f8">, DwarfRegNum<[40]>;
  def F9  : FPR< 9,  "f9">, DwarfRegNum<[41]>;
  def F10 : FPR<10, "f10">, DwarfRegNum<[42]>;
  def F11 : FPR<11, "f11">, DwarfRegNum<[43]>;
  def F12 : FPR<12, "f12">, DwarfRegNum<[44]>;
  def F13 : FPR<13, "f13">, DwarfRegNum<[45]>;
  def F14 : FPR<14, "f14">, DwarfRegNum<[46]>;
  def F15 : FPR<15, "f15">, DwarfRegNum<[47]>;
  def F16 : FPR<16, "f16">, DwarfRegNum<[48]>;
  def F17 : FPR<17, "f17">, DwarfRegNum<[49]>;
  def F18 : FPR<18, "f18">, DwarfRegNum<[50]>;
  def F19 : FPR<19, "f19">, DwarfRegNum<[51]>;
  def F20 : FPR<20, "f20">, DwarfRegNum<[52]>;
  def F21 : FPR<21, "f21">, DwarfRegNum<[53]>;
  def F22 : FPR<22, "f22">, DwarfRegNum<[54]>;
  def F23 : FPR<23, "f23">, DwarfRegNum<[55]>;
  def F24 : FPR<24, "f24">, DwarfRegNum<[56]>;
  def F25 : FPR<25, "f25">, DwarfRegNum<[57]>;
  def F26 : FPR<26, "f26">, DwarfRegNum<[58]>;
  def F27 : FPR<27, "f27">, DwarfRegNum<[59]>;
  def F28 : FPR<28, "f28">, DwarfRegNum<[60]>;
  def F29 : FPR<29, "f29">, DwarfRegNum<[61]>;
  def F30 : FPR<30, "f30">, DwarfRegNum<[62]>;
  def F31 : FPR<31, "f31">, DwarfRegNum<[63]>;
  def F32 : FPR<32, "f32">, DwarfRegNum<[63]>;
  def F33 : FPR<33, "f33">, DwarfRegNum<[63]>;
  def F34 : FPR<34, "f34">, DwarfRegNum<[63]>;
  def F35 : FPR<35, "f35">, DwarfRegNum<[63]>;
  def F36 : FPR<36, "f36">, DwarfRegNum<[63]>;
  def F37 : FPR<37, "f37">, DwarfRegNum<[63]>;
  def F38 : FPR<38, "f38">, DwarfRegNum<[63]>;
  def F39 : FPR<39, "f39">, DwarfRegNum<[63]>;
  def F40 : FPR<40, "f40">, DwarfRegNum<[63]>;
  def F41 : FPR<41, "f41">, DwarfRegNum<[63]>;
  def F42 : FPR<42, "f42">, DwarfRegNum<[63]>;
  def F43 : FPR<43, "f43">, DwarfRegNum<[63]>;
  def F44 : FPR<44, "f44">, DwarfRegNum<[63]>;
  def F45 : FPR<45, "f45">, DwarfRegNum<[63]>;
  def F46 : FPR<46, "f46">, DwarfRegNum<[63]>;
  def F47 : FPR<47, "f47">, DwarfRegNum<[63]>;
  def F48 : FPR<48, "f48">, DwarfRegNum<[63]>;
  def F49 : FPR<49, "f49">, DwarfRegNum<[63]>;
  def F50 : FPR<50, "f50">, DwarfRegNum<[63]>;
  def F51 : FPR<51, "f51">, DwarfRegNum<[63]>;
  def F52 : FPR<52, "f52">, DwarfRegNum<[63]>;
  def F53 : FPR<53, "f53">, DwarfRegNum<[63]>;
  def F54 : FPR<54, "f54">, DwarfRegNum<[63]>;
  def F55 : FPR<55, "f55">, DwarfRegNum<[63]>;
  def F56 : FPR<56, "f56">, DwarfRegNum<[63]>;
  def F57 : FPR<57, "f57">, DwarfRegNum<[63]>;
  def F58 : FPR<58, "f58">, DwarfRegNum<[63]>;
  def F59 : FPR<59, "f59">, DwarfRegNum<[63]>;
  def F60 : FPR<60, "f60">, DwarfRegNum<[63]>;
  def F61 : FPR<61, "f61">, DwarfRegNum<[63]>;
  def F62 : FPR<62, "f62">, DwarfRegNum<[63]>;
  def F63 : FPR<63, "f63">, DwarfRegNum<[63]>;


  /// Oi Double point precision FPU Registers (aliased
  /// with the single precision to hold 64 bit values)
  def D0  : AFPR< 0,  "f0", [F0,   F1]>;
  def D1  : AFPR< 2,  "f2", [F2,   F3]>;
  def D2  : AFPR< 4,  "f4", [F4,   F5]>;
  def D3  : AFPR< 6,  "f6", [F6,   F7]>;
  def D4  : AFPR< 8,  "f8", [F8,   F9]>;
  def D5  : AFPR<10, "f10", [F10, F11]>;
  def D6  : AFPR<12, "f12", [F12, F13]>;
  def D7  : AFPR<14, "f14", [F14, F15]>;
  def D8  : AFPR<16, "f16", [F16, F17]>;
  def D9  : AFPR<18, "f18", [F18, F19]>;
  def D10 : AFPR<20, "f20", [F20, F21]>;
  def D11 : AFPR<22, "f22", [F22, F23]>;
  def D12 : AFPR<24, "f24", [F24, F25]>;
  def D13 : AFPR<26, "f26", [F26, F27]>;
  def D14 : AFPR<28, "f28", [F28, F29]>;
  def D15 : AFPR<30, "f30", [F30, F31]>;
  def D16 : AFPR<32, "f32", [F32, F33]>;
  def D17 : AFPR<34, "f34", [F34, F35]>;
  def D18 : AFPR<36, "f36", [F36, F37]>;
  def D19 : AFPR<38, "f38", [F38, F39]>;
  def D20 : AFPR<40, "f40", [F40, F41]>;
  def D21 : AFPR<42, "f42", [F42, F43]>;
  def D22 : AFPR<44, "f44", [F44, F45]>;
  def D23 : AFPR<46, "f46", [F46, F47]>;
  def D24 : AFPR<48, "f48", [F48, F49]>;
  def D25 : AFPR<50, "f50", [F50, F51]>;
  def D26 : AFPR<52, "f52", [F52, F53]>;
  def D27 : AFPR<54, "f54", [F54, F55]>;
  def D28 : AFPR<56, "f56", [F56, F57]>;
  def D29 : AFPR<58, "f58", [F58, F59]>;
  def D30 : AFPR<60, "f60", [F60, F61]>;
  def D31 : AFPR<62, "f62", [F62, F63]>;

  /// Oi Double point precision FPU Registers in MFP64 mode.
  def D0_64  : AFPR64<0, "f0", [F0]>, DwarfRegNum<[32]>;
  def D1_64  : AFPR64<1, "f1", [F1]>, DwarfRegNum<[33]>;
  def D2_64  : AFPR64<2, "f2", [F2]>, DwarfRegNum<[34]>;
  def D3_64  : AFPR64<3, "f3", [F3]>, DwarfRegNum<[35]>;
  def D4_64  : AFPR64<4, "f4", [F4]>, DwarfRegNum<[36]>;
  def D5_64  : AFPR64<5, "f5", [F5]>, DwarfRegNum<[37]>;
  def D6_64  : AFPR64<6, "f6", [F6]>, DwarfRegNum<[38]>;
  def D7_64  : AFPR64<7, "f7", [F7]>, DwarfRegNum<[39]>;
  def D8_64  : AFPR64<8, "f8", [F8]>, DwarfRegNum<[40]>;
  def D9_64  : AFPR64<9, "f9", [F9]>, DwarfRegNum<[41]>;
  def D10_64  : AFPR64<10, "f10", [F10]>, DwarfRegNum<[42]>;
  def D11_64  : AFPR64<11, "f11", [F11]>, DwarfRegNum<[43]>;
  def D12_64  : AFPR64<12, "f12", [F12]>, DwarfRegNum<[44]>;
  def D13_64  : AFPR64<13, "f13", [F13]>, DwarfRegNum<[45]>;
  def D14_64  : AFPR64<14, "f14", [F14]>, DwarfRegNum<[46]>;
  def D15_64  : AFPR64<15, "f15", [F15]>, DwarfRegNum<[47]>;
  def D16_64  : AFPR64<16, "f16", [F16]>, DwarfRegNum<[48]>;
  def D17_64  : AFPR64<17, "f17", [F17]>, DwarfRegNum<[49]>;
  def D18_64  : AFPR64<18, "f18", [F18]>, DwarfRegNum<[50]>;
  def D19_64  : AFPR64<19, "f19", [F19]>, DwarfRegNum<[51]>;
  def D20_64  : AFPR64<20, "f20", [F20]>, DwarfRegNum<[52]>;
  def D21_64  : AFPR64<21, "f21", [F21]>, DwarfRegNum<[53]>;
  def D22_64  : AFPR64<22, "f22", [F22]>, DwarfRegNum<[54]>;
  def D23_64  : AFPR64<23, "f23", [F23]>, DwarfRegNum<[55]>;
  def D24_64  : AFPR64<24, "f24", [F24]>, DwarfRegNum<[56]>;
  def D25_64  : AFPR64<25, "f25", [F25]>, DwarfRegNum<[57]>;
  def D26_64  : AFPR64<26, "f26", [F26]>, DwarfRegNum<[58]>;
  def D27_64  : AFPR64<27, "f27", [F27]>, DwarfRegNum<[59]>;
  def D28_64  : AFPR64<28, "f28", [F28]>, DwarfRegNum<[60]>;
  def D29_64  : AFPR64<29, "f29", [F29]>, DwarfRegNum<[61]>;
  def D30_64  : AFPR64<30, "f30", [F30]>, DwarfRegNum<[62]>;
  def D31_64  : AFPR64<31, "f31", [F31]>, DwarfRegNum<[63]>;

  // Hi/Lo registers
  def HI  : Register<"ac0">, DwarfRegNum<[64]>;
  def HI1 : Register<"ac1">, DwarfRegNum<[176]>;
  def HI2 : Register<"ac2">, DwarfRegNum<[178]>;
  def HI3 : Register<"ac3">, DwarfRegNum<[180]>;
  def LO  : Register<"ac0">, DwarfRegNum<[65]>;
  def LO1 : Register<"ac1">, DwarfRegNum<[177]>;
  def LO2 : Register<"ac2">, DwarfRegNum<[179]>;
  def LO3 : Register<"ac3">, DwarfRegNum<[181]>;

  let SubRegIndices = [sub_32] in {
  def HI64  : RegisterWithSubRegs<"hi", [HI]>;
  def LO64  : RegisterWithSubRegs<"lo", [LO]>;
  }

  // Status flags register
  def FCR31 : Register<"31">;

  // fcc0 register
  def FCC0 : OiReg<0, "fcc0">;

  // PC register
  def PC : Register<"pc">;

  // Hardware register $29
  def HWR29 : OiReg<29, "29">;
  def HWR29_64 : OiReg<29, "29">;

  // Accum registers
  def AC0 : ACC<0, "ac0", [LO, HI]>;
  def AC1 : ACC<1, "ac1", [LO1, HI1]>;
  def AC2 : ACC<2, "ac2", [LO2, HI2]>;
  def AC3 : ACC<3, "ac3", [LO3, HI3]>;

  def AC0_64 : ACC<0, "ac0", [LO64, HI64]>;

  // DSP-ASE control register fields.
  def DSPPos : Register<"">;
  def DSPSCount : Register<"">;
  def DSPCarry : Register<"">;
  def DSPEFI : Register<"">;
  def DSPOutFlag16_19 : Register<"">;
  def DSPOutFlag20 : Register<"">;
  def DSPOutFlag21 : Register<"">;
  def DSPOutFlag22 : Register<"">;
  def DSPOutFlag23 : Register<"">;
  def DSPCCond : Register<"">;

  let SubRegIndices = [sub_dsp16_19, sub_dsp20, sub_dsp21, sub_dsp22,
                       sub_dsp23] in
  def DSPOutFlag : RegisterWithSubRegs<"", [DSPOutFlag16_19, DSPOutFlag20,
                                            DSPOutFlag21, DSPOutFlag22,
                                            DSPOutFlag23]>;
}

//===----------------------------------------------------------------------===//
// Register Classes
//===----------------------------------------------------------------------===//

class CPURegsClass<list<ValueType> regTypes> :
  RegisterClass<"Oi", regTypes, 32, (add
  // Reserved
  ZERO, AT,
  // Return Values and Arguments
  V0, V1, A0, A1, A2, A3,
  // Not preserved across procedure calls
  T0, T1, T2, T3, T4, T5, T6, T7,
  // Callee save
  S0, S1, S2, S3, S4, S5, S6, S7,
  // Not preserved across procedure calls
  T8, T9,
  // Reserved
  K0, K1, GP, SP, FP, RA,
  // Extra
  R32,
  R33, R34, R35, R36, R37, R38, R39, R40, R41, R42, R43, R44, R45, R46, R47,
  R48, R49, R50, R51, R52, R53, R54, R55, R56, R57, R58, R59, R60, R61, R62,
  R63, R64, R65)>;

def CPURegs : CPURegsClass<[i32]>;
def DSPRegs : CPURegsClass<[v4i8, v2i16]>;

def CPU64Regs : RegisterClass<"Oi", [i64], 64, (add
// Reserved
  ZERO_64, AT_64,
  // Return Values and Arguments
  V0_64, V1_64, A0_64, A1_64, A2_64, A3_64,
  // Not preserved across procedure calls
  T0_64, T1_64, T2_64, T3_64, T4_64, T5_64, T6_64, T7_64,
  // Callee save
  S0_64, S1_64, S2_64, S3_64, S4_64, S5_64, S6_64, S7_64,
  // Not preserved across procedure calls
  T8_64, T9_64,
  // Reserved
  K0_64, K1_64, GP_64, SP_64, FP_64, RA_64)>;

def CPU16Regs : RegisterClass<"Oi", [i32], 32, (add
  // Return Values and Arguments
  V0, V1, A0, A1, A2, A3,
  // Callee save
  S0, S1)>;

def CPURAReg : RegisterClass<"Oi", [i32], 32, (add RA)>, Unallocatable;

def CPUSPReg : RegisterClass<"Oi", [i32], 32, (add SP)>, Unallocatable;

// 64bit fp:
// * FGR64  - 32 64-bit registers
// * AFGR64 - 16 32-bit even registers (32-bit FP Mode)
//
// 32bit fp:
// * FGR32 - 16 32-bit even registers
// * FGR32 - 32 32-bit registers (single float only mode)
def FGR32 : RegisterClass<"Oi", [f32], 32, (sequence "F%u", 0, 31)>;

def AFGR64 : RegisterClass<"Oi", [f64], 64, (add
  // Return Values and Arguments
  D0, D1,
  // Not preserved across procedure calls
  D2, D3, D4, D5,
  // Return Values and Arguments
  D6, D7,
  // Not preserved across procedure calls
  D8, D9,
  // Callee save
  D10, D11, D12, D13, D14, D15)>;

def FGR64 : RegisterClass<"Oi", [f64], 64, (sequence "D%u_64", 0, 31)>;

// Condition Register for floating point operations
def CCR  : RegisterClass<"Oi", [i32], 32, (add FCR31,FCC0)>, Unallocatable;

// Hi/Lo Registers
def LORegs : RegisterClass<"Oi", [i32], 32, (add LO)>;
def HIRegs : RegisterClass<"Oi", [i32], 32, (add HI)>;
def LORegsDSP : RegisterClass<"Oi", [i32], 32, (add LO, LO1, LO2, LO3)>;
def HIRegsDSP : RegisterClass<"Oi", [i32], 32, (add HI, HI1, HI2, HI3)>;
def LORegs64 : RegisterClass<"Oi", [i64], 64, (add LO64)>;
def HIRegs64 : RegisterClass<"Oi", [i64], 64, (add HI64)>;

// Hardware registers
def HWRegs : RegisterClass<"Oi", [i32], 32, (add HWR29)>, Unallocatable;
def HWRegs64 : RegisterClass<"Oi", [i64], 64, (add HWR29_64)>, Unallocatable;

// Accumulator Registers
def ACRegs : RegisterClass<"Oi", [untyped], 64, (add AC0)> {
  let Size = 64;
}

def ACRegs128 : RegisterClass<"Oi", [untyped], 128, (add AC0_64)> {
  let Size = 128;
}

def ACRegsDSP : RegisterClass<"Oi", [untyped], 64, (sequence "AC%u", 0, 3)> {
  let Size = 64;
}

def DSPCC : RegisterClass<"Oi", [v4i8, v2i16], 32, (add DSPCCond)>;

// Register Operands.
def CPURegsAsmOperand : AsmOperandClass {
  let Name = "CPURegsAsm";
  let ParserMethod = "parseCPURegs";
}

def CPU64RegsAsmOperand : AsmOperandClass {
  let Name = "CPU64RegsAsm";
  let ParserMethod = "parseCPU64Regs";
}

def CCRAsmOperand : AsmOperandClass {
  let Name = "CCRAsm";
  let ParserMethod = "parseCCRRegs";
}

def CPURegsOpnd : RegisterOperand<CPURegs, "printCPURegs"> {
  let ParserMatchClass = CPURegsAsmOperand;
}

def CPU64RegsOpnd : RegisterOperand<CPU64Regs, "printCPURegs"> {
  let ParserMatchClass = CPU64RegsAsmOperand;
}

def CCROpnd : RegisterOperand<CCR, "printCPURegs"> {
  let ParserMatchClass = CCRAsmOperand;
}

def HWRegsAsmOperand : AsmOperandClass {
  let Name = "HWRegsAsm";
  let ParserMethod = "parseHWRegs";
}

def HW64RegsAsmOperand : AsmOperandClass {
  let Name = "HW64RegsAsm";
  let ParserMethod = "parseHW64Regs";
}

def HWRegsOpnd : RegisterOperand<HWRegs, "printCPURegs"> {
  let ParserMatchClass = HWRegsAsmOperand;
}

def HW64RegsOpnd : RegisterOperand<HWRegs64, "printCPURegs"> {
  let ParserMatchClass = HW64RegsAsmOperand;
}
