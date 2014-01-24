//===-- OiInstrFormats.td - Oi Instruction Formats -----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Describe OI instructions format
//
//  CPU INSTRUCTION FORMATS
//
//  opcode  - operation code.
//  rs      - src reg.
//  rt      - dst reg (on a 2 regs instr) or src reg (on a 3 reg instr).
//  rd      - dst reg, only used on 3 regs instr.
//  shamt   - only used on shift instructions, contains the shift amount.
//  funct   - combined with opcode field give us an operation code.
//
//===----------------------------------------------------------------------===//

// Format specifies the encoding used by the instruction.  This is part of the
// ad-hoc solution used to emit machine instruction encodings by our machine
// code emitter.
class Format<bits<4> val> {
  bits<4> Value = val;
}

def Pseudo    : Format<0>;
def FrmR      : Format<1>;
def FrmI      : Format<2>;
def FrmJ      : Format<3>;
def FrmFR     : Format<4>;
def FrmFI     : Format<5>;
def FrmOther  : Format<6>; // Instruction w/ a custom format

class MMRel;

def Std2MicroOi : InstrMapping {
  let FilterClass = "MMRel";
  // Instructions with the same BaseOpcode and isNVStore values form a row.
  let RowFields = ["BaseOpcode"];
  // Instructions with the same predicate sense form a column.
  let ColFields = ["Arch"];
  // The key column is the unpredicated instructions.
  let KeyCol = ["se"];
  // Value columns are PredSense=true and PredSense=false
  let ValueCols = [["se"], ["microoi"]];
}

class StdArch {
  string Arch = "se";
}

// Generic Oi Format
class OiInst<dag outs, dag ins, string asmstr, list<dag> pattern,
               InstrItinClass itin, Format f>: Instruction
{
  field bits<64> Inst;
  Format Form = f;

  let Namespace = "Oi";

  let Size = 8;

  bits<6> Opcode = 0;

  // Top 6 bits are the 'opcode' field
  let Inst{39-34} = Opcode;

  let OutOperandList = outs;
  let InOperandList  = ins;

  let AsmString   = asmstr;
  let Pattern     = pattern;
  let Itinerary   = itin;

  //
  // Attributes specific to Oi instructions...
  //
  bits<4> FormBits = Form.Value;

  // TSFlags layout should be kept in sync with OiInstrInfo.h.
  let TSFlags{3-0}   = FormBits;

  let DecoderNamespace = "Oi";

  field bits<64> SoftFail = 0;
}

// Oi32/64 Instruction Format
class InstSE<dag outs, dag ins, string asmstr, list<dag> pattern,
             InstrItinClass itin, Format f, string opstr = ""> :
  OiInst<outs, ins, asmstr, pattern, itin, f> {
  let Predicates = [HasStdEnc];
  string BaseOpcode = opstr;
  string Arch;
}

//class OiInstNOP <dag outs, dag ins, string asmstr, list<dag> pattern>:
//Instruction
//{
//  let Namespace = "Oi";
//  let DecoderNamespace = "Oi";
//
//
//  let OutOperandList = outs;
//  let InOperandList  = ins;
//
//  let AsmString   = asmstr;
//  let Pattern     = pattern;
//  let Itinerary   = NoItinerary;
//
//  field bits<8> Inst;
//  bits<8> Opcode = 0;
//
//  // Top 5 bits are the 'opcode' field
//  let Inst{7-0} = Opcode;
//  
//  let Opcode = 0;
//
//  let Size=1;
//  field bits<8> SoftFail = 0;
//}

//class OiInstWide<dag outs, dag ins, string asmstr, list<dag> pattern,
//               InstrItinClass itin, Format f>: Instruction
//{
//  field bits<56> Inst;
//  Format Form = f;
//
//  let Namespace = "Oi";
//
//  let Size = 7;
//
//  bits<6> Opcode = 0;
//
//  // Top 6 bits are the 'opcode' field
//  let Inst{55-50} = Opcode;
//
//  let OutOperandList = outs;
//  let InOperandList  = ins;
//
//  let AsmString   = asmstr;
//  let Pattern     = pattern;
//  let Itinerary   = itin;
//
//  //
//  // Attributes specific to Oi instructions...
//  //
//  bits<4> FormBits = Form.Value;
//
//  // TSFlags layout should be kept in sync with OiInstrInfo.h.
//  let TSFlags{3-0}   = FormBits;
//
//  let DecoderNamespace = "Oi";
//
//  field bits<32> SoftFail = 0;
//}
//
//// Oi32/64 Instruction Format
//class InstSEWide<dag outs, dag ins, string asmstr, list<dag> pattern,
//             InstrItinClass itin, Format f, string opstr = ""> :
//  OiInstWide<outs, ins, asmstr, pattern, itin, f> {
//  let Predicates = [HasStdEnc];
//  string BaseOpcode = opstr;
//  string Arch;
//}


// Oi Pseudo Instructions Format
class OiPseudo<dag outs, dag ins, list<dag> pattern,
                 InstrItinClass itin = IIPseudo> :
  OiInst<outs, ins, "", pattern, itin, Pseudo> {
  let isCodeGenOnly = 1;
  let isPseudo = 1;
}

// Oi32/64 Pseudo Instruction Format
class PseudoSE<dag outs, dag ins, list<dag> pattern,
               InstrItinClass itin = IIPseudo>:
  OiPseudo<outs, ins, pattern, itin> {
  let Predicates = [HasStdEnc];
}

// Pseudo-instructions for alternate assembly syntax (never used by codegen).
// These are aliases that require C++ handling to convert to the target
// instruction, while InstAliases can be handled directly by tblgen.
class OiAsmPseudoInst<dag outs, dag ins, string asmstr>:
  OiInst<outs, ins, asmstr, [], IIPseudo, Pseudo> {
  let isPseudo = 1;
  let Pattern = [];
}
//===----------------------------------------------------------------------===//
// Format R instruction class in Oi : <|opcode|rs|rt|rd|shamt|funct|>
//===----------------------------------------------------------------------===//

class FR<bits<6> op, bits<8> _funct, dag outs, dag ins, string asmstr,
         list<dag> pattern, InstrItinClass itin>:
  InstSE<outs, ins, asmstr, pattern, itin, FrmR>
{
  bits<7>  rd;
  bits<7>  rs;
  bits<7>  rt;
  bits<5>  shamt;
  bits<8>  funct;

  let Opcode = op;
  let funct  = _funct;

  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-8}  = shamt;
  let Inst{7-0}   = funct;
}

//===----------------------------------------------------------------------===//
// Format I instruction class in Oi : <|opcode|rs|rt|immediate|>
//===----------------------------------------------------------------------===//

class FI<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern,
         InstrItinClass itin>: InstSE<outs, ins, asmstr, pattern, itin, FrmI>
{
  bits<7>  rt;
  bits<7>  rs;
  bits<4> funct2;
  bits<16> imm16;

  let Opcode = op;

  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{19-16} = funct2;
  let Inst{15-0}  = imm16;
}

//class FIWide<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern,
//         InstrItinClass itin>: InstSEWide<outs, ins, asmstr, pattern, itin, FrmI>
//{
//  bits<7>  rt;
//  bits<7>  rs;
//  bits<4>  funct2;
//  bits<32> imm32;
//
//  let Opcode = op;
//
//  let Inst{49-43} = rs;
//  let Inst{42-36} = rt;
//  let Inst{35-32} = funct2;
//  let Inst{31-0}  = imm32;
//}

class BranchBase<bits<6> op, dag outs, dag ins, string asmstr,
                  list<dag> pattern, InstrItinClass itin>:
  InstSE<outs, ins, asmstr, pattern, itin, FrmI>
{
  bits<7>  rs;
  bits<7>  rt;
  bits<16> imm16;

  let Opcode = op;

  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{15-0}  = imm16;
}

//===----------------------------------------------------------------------===//
// Format J instruction class in Oi : <|opcode|address|>
//===----------------------------------------------------------------------===//

class FJ<bits<6> op>
{
  bits<34> target;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-0}  = target;
}

//===----------------------------------------------------------------------===//
// MFC instruction class in Oi : <|op|mf|rt|rd|0000000|sel|>
//===----------------------------------------------------------------------===//
class MFC3OP_FM<bits<6> op, bits<5> mfmt>
{
  bits<7> rt;
  bits<7> rd;
  bits<3> sel;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-32} = 0;
  let Inst{31-27} = mfmt;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-3}  = 0;
  let Inst{2-0}   = sel;
}

class ADD_FM<bits<6> op, bits<8> funct> : StdArch {
  bits<7> rd;
  bits<7> rs;
  bits<7> rt;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-8}  = 0;
  let Inst{7-0}   = funct;
}

class ADDI_FM<bits<6> op> : StdArch {
  bits<7>  rs;
  bits<7>  rt;
  bits<16> imm16;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{15-0}  = imm16;
}

class SRA_FM<bits<8> funct, bit rotate> : StdArch {
  bits<7> rd;
  bits<7> rt;
  bits<5> shamt;

  bits<64> Inst;

  let Inst{39-34} = 0;
  let Inst{33-28} = 0;
  let Inst{27}    = rotate;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-8}  = shamt;
  let Inst{7-0}   = funct;
}

class SRLV_FM<bits<8> funct, bit rotate> : StdArch {
  bits<7> rd;
  bits<7> rt;
  bits<7> rs;

  bits<64> Inst;

  let Inst{39-34} = 0;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-9}  = 0;
  let Inst{8}     = rotate;
  let Inst{7-0}   = funct;
}

class BEQ_FM<bits<6> op> {
  bits<7>  rs;
  bits<7>  rt;
  bits<16> offset;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{15-0}  = offset;
}

class BGEZ_FM<bits<6> op, bits<5> funct> {
  bits<7>  rs;
  bits<16> offset;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-27} = rs;
  let Inst{20-16} = funct;
  let Inst{15-0}  = offset;
}

class B_FM {
  bits<16> offset;

  bits<64> Inst;

  let Inst{39-34} = 4;
  let Inst{33-27} = 0;
  let Inst{26-20} = 0;
  let Inst{15-0}  = offset;
}

class SLTI_FM<bits<6> op> : StdArch {
  bits<7> rt;
  bits<7> rs;
  bits<16> imm16;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{15-0}  = imm16;
}

class MFLO_FM<bits<8> funct> {
  bits<7> rd;

  bits<64> Inst;

  let Inst{39-34} = 0;
  let Inst{33-20} = 0;
  let Inst{19-13} = rd;
  let Inst{12-8}  = 0;
  let Inst{7-0}   = funct;
}

class MTLO_FM<bits<8> funct> {
  bits<7> rs;

  bits<64> Inst;

  let Inst{39-34} = 0;
  let Inst{33-27} = rs;
  let Inst{26-8}  = 0;
  let Inst{7-0}   = funct;
}

class SEB_FM<bits<5> funct, bits<8> funct2> {
  bits<7> rd;
  bits<7> rt;

  bits<64> Inst;

  let Inst{39-34} = 0x1f;
  let Inst{33-27} = 0;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-8}  = funct;
  let Inst{7-0}   = funct2;
}

class CLO_FM<bits<8> funct> {
  bits<7> rd;
  bits<7> rs;
  bits<7> rt;

  bits<64> Inst;

  let Inst{39-34} = 0x1c;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-8}  = 0;
  let Inst{7-0}   = funct;
  let rt = rd;
}

class LUI_FM {
  bits<7> rt;
  bits<16> imm16;

  bits<64> Inst;

  let Inst{39-34} = 0xf;
  let Inst{33-27} = 0;
  let Inst{26-20} = rt;
  let Inst{15-0}  = imm16;
}

class JALR_FM {
  bits<7> rd;
  bits<7> rs;

  bits<64> Inst;

  let Inst{39-34} = 0;
  let Inst{33-27} = rs;
  let Inst{26-20} = 0;
  let Inst{19-13} = rd;
  let Inst{12-8}  = 0;
  let Inst{7-0}   = 9;
}

class BAL_FM {
  bits<16> offset;

  bits<64> Inst;

  let Inst{39-34} = 1;
  let Inst{33-27} = 0;
  let Inst{26-20} = 0x11;
  let Inst{15-0}  = offset;
}

class BGEZAL_FM<bits<8> funct> {
  bits<7>  rs;
  bits<16> offset;

  bits<64> Inst;

  let Inst{39-34} = 1;
  let Inst{33-27} = rs;
  let Inst{26-19} = funct;
  let Inst{15-0}  = offset;
}

class SYNC_FM {
  bits<5> stype;

  bits<64> Inst;

  let Inst{39-34} = 0;
  let Inst{12-8}  = stype;
  let Inst{7-0}   = 0xf;
}

class MULT_FM<bits<6> op, bits<8> funct> : StdArch {
  bits<7>  rs;
  bits<7>  rt;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{19-8}  = 0;
  let Inst{7-0}   = funct;
}

class EXT_FM<bits<8> funct> {
  bits<7> rt;
  bits<7> rs;
  bits<5> pos;
  bits<7> size;

  bits<64> Inst;

  let Inst{39-34} = 0x1f;
  let Inst{33-27} = rs;
  let Inst{26-20} = rt;
  let Inst{19-13} = size;
  let Inst{12-8}  = pos;
  let Inst{7-0}   = funct;
}

class RDHWR_FM {
  bits<7> rt;
  bits<7> rd;

  bits<64> Inst;

  let Inst{39-34} = 0x1f;
  let Inst{33-27} = 0;
  let Inst{26-20} = rt;
  let Inst{19-13} = rd;
  let Inst{12-8}  = 0;
  let Inst{7-0}   = 0x3b;
}

//===----------------------------------------------------------------------===//
//
//  FLOATING POINT INSTRUCTION FORMATS
//
//  opcode  - operation code.
//  fs      - src reg.
//  ft      - dst reg (on a 2 regs instr) or src reg (on a 3 reg instr).
//  fd      - dst reg, only used on 3 regs instr.
//  fmt     - double or single precision.
//  funct   - combined with opcode field give us an operation code.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Format FI instruction class in Oi : <|opcode|base|ft|immediate|>
//===----------------------------------------------------------------------===//

class FFI<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern>:
  InstSE<outs, ins, asmstr, pattern, NoItinerary, FrmFI>
{
  bits<7>  ft;
  bits<7>  base;
  bits<16> imm16;

  let Opcode = op;

  let Inst{33-27} = base;
  let Inst{26-20} = ft;
  let Inst{15-0}  = imm16;
}

class ADDS_FM<bits<6> funct, bits<7> fmt> {
  bits<7> fd;
  bits<7> fs;
  bits<7> ft;

  bits<64> Inst;

  let Inst{39-34} = 0x11;
  let Inst{33-27} = fmt;
  let Inst{26-20} = ft;
  let Inst{19-13} = fs;
  let Inst{12-6}  = fd;
  let Inst{5-0}   = funct;
}

class ABSS_FM<bits<6> funct, bits<7> fmt> {
  bits<7> fd;
  bits<7> fs;

  bits<64> Inst;

  let Inst{39-34} = 0x11;
  let Inst{33-27} = fmt;
  let Inst{26-20} = 0;
  let Inst{19-13} = fs;
  let Inst{12-6}  = fd;
  let Inst{5-0}   = funct;
}

class MFC1_FM<bits<7> funct> {
  bits<7> rt;
  bits<7> fs;

  bits<64> Inst;

  let Inst{39-34} = 0x11;
  let Inst{33-27} = funct;
  let Inst{26-20} = rt;
  let Inst{19-13} = fs;
  let Inst{12-0}  = 0;
}

class LW_FM<bits<6> op> : StdArch {
  bits<7> rt;
  bits<23> addr;

  bits<64> Inst;

  let Inst{39-34} = op;
  let Inst{33-27} = addr{22-16};
  let Inst{26-20} = rt;
  let Inst{15-0}  = addr{15-0};
}

class MADDS_FM<bits<3> funct, bits<3> fmt> {
  bits<7> fd;
  bits<7> fr;
  bits<7> fs;
  bits<7> ft;

  bits<64> Inst;

  let Inst{39-34} = 0x13;
  let Inst{33-27} = fr;
  let Inst{26-20} = ft;
  let Inst{19-13} = fs;
  let Inst{12-6}  = fd;
  let Inst{5-3}   = funct;
  let Inst{2-0}   = fmt;
}

class LWXC1_FM<bits<6> funct> {
  bits<7> fd;
  bits<7> base;
  bits<7> index;

  bits<64> Inst;

  let Inst{39-34} = 0x13;
  let Inst{33-27} = base;
  let Inst{26-20} = index;
  let Inst{19-13} = 0;
  let Inst{12-6}  = fd;
  let Inst{5-0}   = funct;
}

class SWXC1_FM<bits<6> funct> {
  bits<7> fs;
  bits<7> base;
  bits<7> index;

  bits<64> Inst;

  let Inst{39-34} = 0x13;
  let Inst{33-27} = base;
  let Inst{26-20} = index;
  let Inst{19-13} = fs;
  let Inst{12-6}  = 0;
  let Inst{5-0}   = funct;
}

class BC1F_FM<bit nd, bit tf> {
  bits<16> offset;

  bits<64> Inst;

  let Inst{39-34} = 0x11;
  let Inst{33-27} = 0x8;
  let Inst{26-24} = 0; // cc
  let Inst{23} = nd;
  let Inst{22} = tf;
  let Inst{15-0} = offset;
}

class CEQS_FM<bits<7> fmt> {
  bits<7> fs;
  bits<7> ft;
  bits<4> cond;

  bits<64> Inst;

  let Inst{39-34} = 0x11;
  let Inst{33-27} = fmt;
  let Inst{26-20} = ft;
  let Inst{19-13} = fs;
  let Inst{12-8} = 0; // cc
  let Inst{7-4} = 0x3;
  let Inst{3-0} = cond;
}

class CMov_I_F_FM<bits<6> funct, bits<7> fmt> {
  bits<7> fd;
  bits<7> fs;
  bits<7> rt;

  bits<64> Inst;

  let Inst{39-34} = 0x11;
  let Inst{33-27} = fmt;
  let Inst{26-20} = rt;
  let Inst{19-13} = fs;
  let Inst{12-6} = fd;
  let Inst{5-0} = funct;
}

class CMov_F_I_FM<bit tf> {
  bits<7> rd;
  bits<7> rs;

  bits<64> Inst;

  let Inst{39-34} = 0;
  let Inst{33-27} = rs;
  let Inst{26-24} = 0; // cc
  let Inst{23} = 0;
  let Inst{22} = tf;
  let Inst{21-20} = 0; // filling
  let Inst{19-13} = rd;
  let Inst{12-6} = 0;
  let Inst{5-0} = 1;
}

class CMov_F_F_FM<bits<7> fmt, bit tf> {
  bits<7> fd;
  bits<7> fs;

  bits<64> Inst;

  let Inst{39-34} = 0x11;
  let Inst{33-27} = fmt;
  let Inst{26-24} = 0; // cc
  let Inst{23} = 0;
  let Inst{22} = tf;
  let Inst{21-20} = 0; //filling
  let Inst{19-13} = fs;
  let Inst{12-6} = fd;
  let Inst{5-0} = 0x11;
}
