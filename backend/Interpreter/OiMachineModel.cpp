//===-- OiMachineModel.cpp - Convert Oi MCInst to LLVM IR ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class translates an Oi MCInst to LLVM IR using static binary translation
// techniques.
//
//===----------------------------------------------------------------------===//

//#define NDEBUG

#define DEBUG_TYPE "staticbt"
#include "OiMachineModel.h"
#include "OiInstrInfo.h"
#include "StringRefMemoryObject.h"
#include "InterpUtils.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/Object/ELF.h"
using namespace llvm;

void OiMachineModel::StartFunction(Twine &N) {
}

void OiMachineModel::FinishFunction() {
}

void OiMachineModel::FinishModule() {
}

uint32_t OiMachineModel::HandleAluSrcOperand(const MCOperand &o) {
  if (o.isReg()) {
    return Bank[ConvToDirective(conv32(o.getReg()))];  
  } else if (o.isImm()) {
    return o.getImm();    
  } else if (o.isFPImm()) {
  }
  llvm_unreachable("Invalid Src operand");
}

double OiMachineModel::HandleDoubleSrcOperand(const MCOperand &o) {
  if (o.isReg())
    return DblBank[ConvToDirectiveDbl(conv32(o.getReg()))];
  llvm_unreachable("Invalid Src operand");
}

uint32_t OiMachineModel::HandleFloatSrcOperand(const MCOperand &o) {
  llvm_unreachable("Invalid Src operand");
}

uint32_t OiMachineModel::HandleDoubleDstOperand(const MCOperand &o) {
  if (o.isReg())
    return ConvToDirectiveDbl(conv32(o.getReg()));
  llvm_unreachable("Invalid dst operand");
}

uint32_t OiMachineModel::HandleFloatDstOperand(const MCOperand &o) {
  llvm_unreachable("Invalid dst operand");
}

double OiMachineModel::HandleDoubleLoadOperand(const MCOperand &o, const MCOperand &o2) {
  if (o.isReg() && o2.isImm()) {
    uint32_t myimm = o2.getImm();
    uint32_t reg = ConvToDirective(conv32(o.getReg()));
    return *reinterpret_cast<double*>(&Mem->memory[Bank[reg] + myimm]);
  }
  llvm_unreachable("Invalid Src operand");
}

void OiMachineModel::HandleDoubleSaveOperand(const MCOperand &o, const MCOperand &o2,
                                             double val) {
  if (o.isReg() && o2.isImm()) {
    uint32_t myimm = o2.getImm();
    uint32_t reg = ConvToDirective(conv32(o.getReg()));
    *reinterpret_cast<double*>(&Mem->memory[Bank[reg] + myimm]) = val;
  }
  llvm_unreachable("Invalid Src operand");
}

uint32_t OiMachineModel::HandleFloatMemOperand(const MCOperand &o, const MCOperand &o2,
                                             bool IsLoad) {
  llvm_unreachable("Invalid Src operand");
}

uint32_t OiMachineModel::HandleSaveDouble(Value *In, Value *&Low, Value *&High) {
  return true;
}

uint32_t OiMachineModel::HandleSaveFloat(Value *In, Value *&V) {
  return true;
}

uint32_t OiMachineModel::HandleMemExpr(const MCExpr &exp,  bool IsLoad) {
  llvm_unreachable("Invalid Load Expr");
}

uint32_t OiMachineModel::HandleLUiOperand(const MCOperand &o) {
  if (o.isImm()) {
    uint32_t val = o.getImm();
    return val << 16;
  }
  llvm_unreachable("Invalid Src operand");
}

uint32_t* OiMachineModel::HandleMemOperand(const MCOperand &o, const MCOperand &o2) {
  if (o.isReg() && o2.isImm()) {
    uint32_t r = ConvToDirective(conv32(o.getReg()));
    uint32_t imm = o2.getImm();
    return reinterpret_cast<uint32_t*>(&Mem->memory[Bank[r]+imm]);
  }
  llvm_unreachable("Invalid Src operand");
}

uint32_t OiMachineModel::HandleSpilledOperand(const MCOperand &o, const MCOperand &o2,
                                            bool IsLoad) {
  return true;
}

uint32_t OiMachineModel::HandleGetSpilledAddress(const MCOperand &o, const MCOperand &o2,
                                                 const MCOperand &dst) {
                                
  return true;
}

uint32_t OiMachineModel::HandleAluDstOperand(const MCOperand &o) {
  if (o.isReg()) {
    unsigned reg = ConvToDirective(conv32(o.getReg()));
    assert (reg != 0 && "Cannot write to register 0");
    return reg;
  }
  llvm_unreachable("Invalid Dst operand");
}

uint32_t OiMachineModel::HandleCallTarget(const MCOperand &o) {
  return false;
}

bool OiMachineModel::HandleFCmpOperand(const MCOperand &o, double o0, double o1) {
  if (o.isImm()) {
    uint64_t cond = o.getImm();
    switch (cond) {
    case 0: // OI_FCOND_F  false
      return false;
    case 1: // OI_FCOND_UN unordered - true if either nans
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 2: // OI_FCOND_OEQ equal
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 3: // OI_FCOND_UEQ unordered or equal
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 4: // OI_FCOND_OLT
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 5: // OI_FCOND_ULT
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 6: // OI_FCOND_OLE
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 7: // OI_FCOND_ULE
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 8: // OI_FCOND_SF
      // Exception not implemented
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 9: // OI_FCOND_NGLE - compare not greater or less than equal double 
            // (w/ except.)
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 10: // OI_FCOND_SEQ
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 11: // OI_FCOND_NGL
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 12: // OI_FCOND_LT
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 13: // OI_FCOND_NGE
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 14: // OI_FCOND_LE
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    case 15: // OI_FCOND_NGT
      llvm_unreachable("Unimplemented FCmp Operand");
      break;
    }    
  }
  llvm_unreachable("Unrecognized FCmp Operand");
}

uint32_t OiMachineModel::HandleBranchTarget(const MCOperand &o, bool IsRelative,
                                            uint64_t CurPC) {
  if (o.isImm()) {
    if (IsRelative)
      return (CurPC + o.getImm()) & 0xFFFFFFFFULL;
    else
      return o.getImm();
  }
  llvm_unreachable("Unrecognized branch target");
}


uint64_t OiMachineModel::executeInstruction(const MCInst *MI, uint64_t CurPC) {
#ifndef NDEBUG
  raw_ostream &DebugOut = outs();
#else
  raw_ostream &DebugOut = nulls();
#endif

  switch (MI->getOpcode()) {
  case Oi::ADDiu:
  case Oi::ADDi:
  case Oi::ADDu:
  case Oi::ADD:
    {
      DebugOut << "Handling ADDiu, ADDi, ADDu, ADD\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = o1 + o2;
      return CurPC + 8;
    }
  case Oi::SUBu:
  case Oi::SUB:
    {
      DebugOut << "Handling SUBu, SUB\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = o1 - o2;
      return CurPC + 8;
    }
  case Oi::MUL:
    {
      DebugOut << "Handling MUL\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = o1 * o2;
      return CurPC + 8;
    }
  case Oi::MULT:
    {
      DebugOut << "Handling MULT\n";
      uint64_t o1 = HandleAluSrcOperand(MI->getOperand(0));
      uint64_t o2 = HandleAluSrcOperand(MI->getOperand(1));
      uint64_t ans = o1 * o2;
      Hi = ans >> 32;
      Lo = ans & 0xFFFFFFFFULL;
      return CurPC + 8;
    }
  case Oi::SDIV:
  case Oi::UDIV:
    {
      DebugOut << "Handling DIV\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(0));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(1));
      Lo = o1 / o2;
      Hi = o1 % o2;
      return CurPC + 8;
    }
  case Oi::MFHI:
    {
      DebugOut << "Handling MFHI\n";
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = Hi;
      return CurPC + 8;
    }
  case Oi::MFLO:
    {
      DebugOut << "Handling MFLO\n";
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = Lo;
      return CurPC + 8;
    }
  case Oi::LDC1:
    {
      DebugOut << "Handling LDC1\n";
      uint32_t o1 = HandleDoubleDstOperand(MI->getOperand(0));
      double o2 = HandleDoubleLoadOperand(MI->getOperand(1), MI->getOperand(2));
      DblBank[o1] = o2;
      return CurPC + 8;
    }
  case Oi::LWC1:
    {
      DebugOut << "Handling LWC1\n";
      llvm_unreachable("LWC1 unimplemented!");
      break;
    }
  case Oi::SDC1:
    {
      DebugOut << "Handling SDC1\n";
      double o1 = HandleDoubleSrcOperand(MI->getOperand(0));
      HandleDoubleSaveOperand(MI->getOperand(1), MI->getOperand(2), 
                              o1);
      return CurPC + 8;
    }
  case Oi::SWC1:
    {
      DebugOut << "Handling SWC1\n";
      llvm_unreachable("LWC1 unimplemented!");
      break;
    }
  // XXX: Note for FCMP and MOVT: MIPS IV defines several FCC, floating-point
  // codes. We always use the 0th bit (MIPS I mode).
  // TODO: Implement all 8 CC bits.
  case Oi::FCMP_D32:
    {
      DebugOut << "Handling FCMP_D32\n";
      double o0 = HandleDoubleSrcOperand(MI->getOperand(0));
      double o1 = HandleDoubleSrcOperand(MI->getOperand(1));
      if (HandleFCmpOperand(MI->getOperand(2), o0, o1))
        FCC = 1;
      else
        FCC = 0;
      return CurPC + 8;
    }
  case Oi::FCMP_S32:
    {
      DebugOut << "Handling FCMP_S32\n";
      llvm_unreachable("FCMP_S32 unimplemented!");
      break;
    }
  case Oi::MOVT_I:
    {
      DebugOut << "Handling MOVT\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      if (!FCC) {
        Bank[o0] = o1;
      } 
      return CurPC + 8;
    }
  case Oi::FSUB_D32:
  case Oi::FADD_D32:
    {
      DebugOut << "Handling FADD_D32 FSUB_D32\n";
      double o1 = HandleDoubleSrcOperand(MI->getOperand(1));
      double o2 = HandleDoubleSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleDoubleDstOperand(MI->getOperand(0));
      if (MI->getOpcode() == Oi::FADD_D32)
        DblBank[o0] = o1 + o2;
      else
        DblBank[o0] = o1 - o2;
      return CurPC + 8;
    }
  case Oi::FSUB_S:
  case Oi::FADD_S:
  case Oi::FMUL_S:
  case Oi::FDIV_S:
    {
      DebugOut << "Handling FADD_S FSUB_S FMUL_S FDIV_S\n";
      llvm_unreachable("FSUB_S.. unimplemented!");
      break;
    }
  case Oi::FMOV_D32:
    {
      DebugOut << "Handling FMOV\n";
      double o1 = HandleDoubleSrcOperand(MI->getOperand(1));
      uint32_t o0 = HandleDoubleDstOperand(MI->getOperand(0));
      DblBank[o0] = o1;
      return CurPC + 8;
    }
  case Oi::FMUL_D32:
    {
      DebugOut << "Handling FMUL\n";
      double o1 = HandleDoubleSrcOperand(MI->getOperand(1));
      double o2 = HandleDoubleSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleDoubleDstOperand(MI->getOperand(0));
      DblBank[o0] = o1 * o2;
      return CurPC + 8;
    }
  case Oi::FDIV_D32:
    {
      DebugOut << "Handling FDIV\n";
      double o1 = HandleDoubleSrcOperand(MI->getOperand(1));
      double o2 = HandleDoubleSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleDoubleDstOperand(MI->getOperand(0));
      DblBank[o0] = o1 / o2;
      return CurPC + 8;
    }
  case Oi::CVT_D32_W:
    {
      DebugOut << "Handling CVT.D.W\n";
      llvm_unreachable("CVT.D.W unimplemented!");
      break;
    }
  case Oi::CVT_S_W:
    {
      DebugOut << "Handling CVT.S.W\n";
      llvm_unreachable("CVT.S.W unimplemented!");
      break;
    }
  case Oi::CVT_D32_S:
    {
      DebugOut << "Handling CVT.D.S\n";
      llvm_unreachable("CVT.D.S unimplemented!");
      break;
    }
  case Oi::CVT_S_D32:
    {
      DebugOut << "Handling CVT.S.D\n";
      llvm_unreachable("CVT.S.D unimplemented!");
      break;
    }
  case Oi::TRUNC_W_D32:
    {
      DebugOut << "Handling TRUNC.W.D\n";
      llvm_unreachable("TRUNC.W.D unimplemented!");
      break;
    }
  case Oi::TRUNC_W_S:
    {
      DebugOut << "Handling TRUNC.W.S\n";
      llvm_unreachable("TRUNC.W.S unimplemented!");
      break;
    }
  case Oi::MFC1:
    {
      DebugOut << "Handling MFC1\n";
      double o1 = HandleDoubleSrcOperand(MI->getOperand(1));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      uint64_t tmp = 0;
      memcpy(&tmp,&o1,sizeof(uint64_t));
      if (ConvToDirective(conv32(MI->getOperand(1).getReg())) % 2) {
        Bank[o0] = tmp >> 32;
      } else {
        Bank[o0] = tmp & 0xFFFFFFFFULL;
      }
      return CurPC + 8;
    }
  case Oi::MTC1:
    {
      DebugOut << "Handling MTC1\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o0 = HandleDoubleDstOperand(MI->getOperand(0));
      uint64_t val = 0;
      memcpy(&val,&DblBank[o0],sizeof(uint64_t));
      if (ConvToDirective(conv32(MI->getOperand(0).getReg())) % 2) {
        val = val & 0xFFFFFFFFULL;
        val |= ((uint64_t)(o1)) << 32;
      } else {
        val = val & 0xFFFFFFFF00000000ULL;
        val |= o1;
      }      
      DblBank[o0] = val;
      return CurPC + 8;
    }
  case Oi::BC1T:
  case Oi::BC1F:
    {
      DebugOut << "Handling BC1F, BC1T\n";
      if (MI->getOpcode() == Oi::BC1T && FCC)
        return HandleBranchTarget(MI->getOperand(0), true, CurPC);
      else if (MI->getOpcode() == Oi::BC1F && !FCC)
        return HandleBranchTarget(MI->getOperand(0), true, CurPC);
      return CurPC + 8;
    }
  case Oi::J:
    {
      DebugOut << "Handling J\n";
      return HandleBranchTarget(MI->getOperand(0), true, CurPC);
    }
  case Oi::SRA:
    {
      DebugOut << "Handling SRA\n";
      int32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      int32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = o1 / (1 << o2);
      return CurPC + 8;
    }
  case Oi::SRL:
  case Oi::SRLV:
    {
      DebugOut << "Handling SRL SRLV\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      //XXX: SRLV is decoded with operands inverted!
      if (MI->getOpcode() == Oi::SRLV)
        Bank[o0] = o2 >> o1;
      else
        Bank[o0] = o1 >> o2;
      return CurPC + 8;
    }
  case Oi::SLL:
  case Oi::SLLV:
    {
      DebugOut << "Handling SLL SLLV";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      //XXX: SRLV is decoded with operands inverted!
      if (MI->getOpcode() == Oi::SRLV)
        Bank[o0] = o2 << o1;
      else
        Bank[o0] = o1 << o2;
      return CurPC + 8;
    }
  case Oi::MOVN_I_I:
  case Oi::MOVZ_I_I:
    {
      DebugOut << "Handling MOVN, MOVZ\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      if (MI->getOpcode() == Oi::MOVN_I_I && o2)
        Bank[o0] =  o1;
      else if (MI->getOpcode() == Oi::MOVZ_I_I && !o2)
        Bank[o0] = o1;
      return CurPC + 8;
    }
  case Oi::ORi:
  case Oi::OR:
    {
      DebugOut << "Handling ORi, OR\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = o1 | o2;
      return CurPC + 8;
    }
  case Oi::NOR:
    {
      DebugOut << "Handling NORi, NOR\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = ~(o1 | o2);
      return CurPC + 8;
    }
  case Oi::ANDi:
  case Oi::AND:
    {
      DebugOut << "Handling ANDi, AND\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = o1 & o2;
      return CurPC + 8;
    }
  case Oi::XORi:
  case Oi::XOR:
    {
      DebugOut << "Handling XORi, XOR\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
      Bank[o0] = o1 ^ o2;
      return CurPC + 8;
    }
  case Oi::SLTiu:
  case Oi::SLTu:
    {
      DebugOut << "Handling SLT\n";
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      uint32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));      
      Bank[o0] = o1 < o2;
      return CurPC + 8;
    }
  case Oi::SLTi:
  case Oi::SLT:
    {
      DebugOut << "Handling SLT\n";
      int32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      int32_t o2 = HandleAluSrcOperand(MI->getOperand(2));
      uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));      
      Bank[o0] = o1 < o2;
      return CurPC + 8;
    }
  case Oi::BEQ:
    {
      DebugOut << "Handling BEQ, BNE, BLTZ\n";
      uint32_t o0 = HandleAluSrcOperand(MI->getOperand(0));
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      if (o0 == o1)
        return HandleBranchTarget(MI->getOperand(2), true, CurPC);
      return CurPC + 8;
    }
  case Oi::BNE:
    {
      DebugOut << "Handling BEQ, BNE, BLTZ\n";
      uint32_t o0 = HandleAluSrcOperand(MI->getOperand(0));
      uint32_t o1 = HandleAluSrcOperand(MI->getOperand(1));
      if (o0 != o1)
        return HandleBranchTarget(MI->getOperand(2), true, CurPC);
      return CurPC + 8;
    }
  case Oi::BLTZ:
    {
      DebugOut << "Handling BEQ, BNE, BLTZ\n";
      int32_t o0 = HandleAluSrcOperand(MI->getOperand(0));
      if (o0 < 0)
        return HandleBranchTarget(MI->getOperand(1), true, CurPC);
      return CurPC + 8;
    }
  case Oi::BGTZ:
    {
      DebugOut << "Handling BEQ, BNE, BLTZ\n";
      int32_t o0 = HandleAluSrcOperand(MI->getOperand(0));
      if (o0 > 0)
        return HandleBranchTarget(MI->getOperand(1), true, CurPC);
      return CurPC + 8;
    }
  case Oi::BLEZ:
    {
      DebugOut << "Handling BEQ, BNE, BLTZ\n";
      int32_t o0 = HandleAluSrcOperand(MI->getOperand(0));
      if (o0 <= 0)
        return HandleBranchTarget(MI->getOperand(1), true, CurPC);
      return CurPC + 8;
    }
  case Oi::LUi:
  case Oi::LUi64: {
    DebugOut << "Handling LUi\n";
    uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
    uint32_t o1 = HandleLUiOperand(MI->getOperand(1));
    Bank[o0] = o1;
    return CurPC + 8;
  }
  case Oi::LW:
  case Oi::LW64: {
    DebugOut << "Handling LW\n";
    uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
    uint32_t* o1 = HandleMemOperand(MI->getOperand(1), MI->getOperand(2));
    Bank[o0] = *o1;
    return CurPC + 8;
  }
  case Oi::SPILLLW: {
    DebugOut << "Handling SPILLLW\n";
    uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
    uint32_t* o1 = HandleMemOperand(MI->getOperand(1), MI->getOperand(2));
    Bank[o0] = *o1;
    return CurPC + 8;
  }
  case Oi::SPILLSW: {
    DebugOut << "Handling SPILLSW\n";
    uint32_t o0 = HandleAluSrcOperand(MI->getOperand(0));
    uint32_t* o1 = HandleMemOperand(MI->getOperand(1), MI->getOperand(2));
    *o1 = o0;
    return CurPC + 8;
  }
  case Oi::LHu: {
    DebugOut << "Handling LHu\n";
    uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
    uint16_t* o1 = reinterpret_cast<uint16_t*>
      (HandleMemOperand(MI->getOperand(1), MI->getOperand(2)));
    Bank[o0] = *o1;
    return CurPC + 8;
  }
  case Oi::LH: {   
    DebugOut << "Handling LH\n";
    uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
    int16_t* o1 = reinterpret_cast<int16_t*>
      (HandleMemOperand(MI->getOperand(1), MI->getOperand(2)));
    int32_t tmp = *o1;
    Bank[o0] = tmp;
    return CurPC + 8;
  }
  case Oi::LBu: {
    DebugOut << "Handling LBu\n";
    uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
    uint8_t* o1 = reinterpret_cast<uint8_t*>
      (HandleMemOperand(MI->getOperand(1), MI->getOperand(2)));
    Bank[o0] = *o1;
    return CurPC + 8;
  }
  case Oi::LB: {   
    DebugOut << "Handling LB\n";
    uint32_t o0 = HandleAluDstOperand(MI->getOperand(0));
    int8_t* o1 = reinterpret_cast<int8_t*>
      (HandleMemOperand(MI->getOperand(1), MI->getOperand(2)));
    int32_t tmp = *o1;
    Bank[o0] = tmp;
    return CurPC + 8;
  }
  case Oi::SW:
  case Oi::SW64: {
    DebugOut << "Handling SW\n";
    uint32_t o0 = HandleAluSrcOperand(MI->getOperand(0));
    uint32_t* o1 = HandleMemOperand(MI->getOperand(1), MI->getOperand(2));
    *o1 = o0;
    return CurPC + 8;
  }
  case Oi::SB: {
    DebugOut << "Handling SB\n";
    uint8_t o0 = HandleAluSrcOperand(MI->getOperand(0));
    uint8_t* o1 = reinterpret_cast<uint8_t*>
      (HandleMemOperand(MI->getOperand(1), MI->getOperand(2)));
    *o1 = o0;
    return CurPC + 8;
  }
  case Oi::SH: {
    DebugOut << "Handling SH\n";
    uint16_t o0 = HandleAluSrcOperand(MI->getOperand(0));
    uint16_t* o1 = reinterpret_cast<uint16_t*>
      (HandleMemOperand(MI->getOperand(1), MI->getOperand(2)));
    *o1 = o0;
    return CurPC + 8;
  }
  case Oi::JALR64:
  case Oi::JALR: {
    DebugOut << "Handling JALR\n";
    Bank[31] = CurPC + 8;
    return HandleAluSrcOperand(MI->getOperand(0));
  }
  case Oi::JAL: {
    DebugOut << "Handling JAL\n";
    Bank[31] = CurPC + 8;
    return HandleBranchTarget(MI->getOperand(0), true, CurPC);
  }
  case Oi::JR64:
  case Oi::JR: {
    DebugOut << "Handling JR\n";
    return HandleAluSrcOperand(MI->getOperand(0));
  }
  case Oi::NOP:
    DebugOut << "Handling NOP\n";
    break;
  default: 
    llvm_unreachable("Unimplemented instruction!");
  }
  return CurPC + 8;
}

