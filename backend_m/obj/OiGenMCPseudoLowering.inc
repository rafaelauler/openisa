/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Pseudo-instruction MC lowering Source Fragment                              *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

bool OiAsmPrinter::
emitPseudoExpansionLowering(MCStreamer &OutStreamer,
                            const MachineInstr *MI) {
  switch (MI->getOpcode()) {
    default: return false;
    case Oi::DPAQX_SA_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPAQX_SA_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPAQX_S_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPAQX_S_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPAQ_SA_L_W_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPAQ_SA_L_W);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPAQ_S_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPAQ_S_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPAU_H_QBL_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPAU_H_QBL);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPAU_H_QBR_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPAU_H_QBR);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPAX_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPAX_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPA_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPA_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPSQX_SA_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPSQX_SA_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPSQX_S_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPSQX_S_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPSQ_SA_L_W_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPSQ_SA_L_W);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPSQ_S_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPSQ_S_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPSU_H_QBL_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPSU_H_QBL);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPSU_H_QBR_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPSU_H_QBR);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPSX_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPSX_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::DPS_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::DPS_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MADDU_DSP_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MADDU_DSP);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MADD_DSP_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MADD_DSP);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MAQ_SA_W_PHL_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MAQ_SA_W_PHL);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MAQ_SA_W_PHR_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MAQ_SA_W_PHR);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MAQ_S_W_PHL_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MAQ_S_W_PHL);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MAQ_S_W_PHR_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MAQ_S_W_PHR);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MSUBU_DSP_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MSUBU_DSP);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MSUB_DSP_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MSUB_DSP);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MTHLIP_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MTHLIP);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MULSAQ_S_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MULSAQ_S_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MULSA_W_PH_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MULSA_W_PH);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MULTU_DSP_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MULTU_DSP);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::MULT_DSP_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::MULT_DSP);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: rt
      lowerOperand(MI->getOperand(1), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::SHILOV_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::SHILOV);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: rs
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
    case Oi::SHILO_PSEUDO: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(Oi::SHILO);
      // Operand: ac
      TmpInst.addOperand(MCOperand::CreateReg(Oi::AC0));
      // Operand: shift
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      OutStreamer.EmitInstruction(TmpInst);
      break;
    }
  }
  return true;
}

