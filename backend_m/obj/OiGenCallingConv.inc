/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Calling Convention Implementation Fragment                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

static bool CC_OiEABI(unsigned ValNo, MVT ValVT,
                      MVT LocVT, CCValAssign::LocInfo LocInfo,
                      ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_OiN(unsigned ValNo, MVT ValVT,
                   MVT LocVT, CCValAssign::LocInfo LocInfo,
                   ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_OiN_FastCC(unsigned ValNo, MVT ValVT,
                          MVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_OiN_VarArg(unsigned ValNo, MVT ValVT,
                          MVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_OiO32_FastCC(unsigned ValNo, MVT ValVT,
                            MVT LocVT, CCValAssign::LocInfo LocInfo,
                            ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_Oi_FastCC(unsigned ValNo, MVT ValVT,
                         MVT LocVT, CCValAssign::LocInfo LocInfo,
                         ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool RetCC_Oi(unsigned ValNo, MVT ValVT,
                     MVT LocVT, CCValAssign::LocInfo LocInfo,
                     ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool RetCC_OiAndroid(unsigned ValNo, MVT ValVT,
                            MVT LocVT, CCValAssign::LocInfo LocInfo,
                            ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool RetCC_OiEABI(unsigned ValNo, MVT ValVT,
                         MVT LocVT, CCValAssign::LocInfo LocInfo,
                         ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool RetCC_OiN(unsigned ValNo, MVT ValVT,
                      MVT LocVT, CCValAssign::LocInfo LocInfo,
                      ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool RetCC_OiO32(unsigned ValNo, MVT ValVT,
                        MVT LocVT, CCValAssign::LocInfo LocInfo,
                        ISD::ArgFlagsTy ArgFlags, CCState &State);


static bool CC_OiEABI(unsigned ValNo, MVT ValVT,
                      MVT LocVT, CCValAssign::LocInfo LocInfo,
                      ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i8 ||
      LocVT == MVT::i16) {
    LocVT = MVT::i32;
    if (ArgFlags.isSExt())
        LocInfo = CCValAssign::SExt;
    else if (ArgFlags.isZExt())
        LocInfo = CCValAssign::ZExt;
    else
        LocInfo = CCValAssign::AExt;
  }

  if (LocVT == MVT::i32) {
    static const uint16_t RegList1[] = {
      Oi::A0, Oi::A1, Oi::A2, Oi::A3, Oi::T0, Oi::T1, Oi::T2, Oi::T3
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 8)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    if (State.getTarget().getSubtarget<OiSubtarget>().isSingleFloat()) {
      static const uint16_t RegList2[] = {
        Oi::F12, Oi::F13, Oi::F14, Oi::F15, Oi::F16, Oi::F17, Oi::F18, Oi::F19
      };
      if (unsigned Reg = State.AllocateReg(RegList2, 8)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  if (LocVT == MVT::f32) {
    if (State.getTarget().getSubtarget<OiSubtarget>().isNotSingleFloat()) {
      static const uint16_t RegList3[] = {
        Oi::F12, Oi::F14, Oi::F16, Oi::F18
      };
      if (unsigned Reg = State.AllocateReg(RegList3, 4)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  if (LocVT == MVT::f64) {
    if (State.getTarget().getSubtarget<OiSubtarget>().isNotSingleFloat()) {
      static const uint16_t RegList4[] = {
        Oi::D6, Oi::D7, Oi::D8, Oi::D9
      };
      if (unsigned Reg = State.AllocateReg(RegList4, 4)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  if (LocVT == MVT::i32 ||
      LocVT == MVT::f32) {
    unsigned Offset5 = State.AllocateStack(4, 4);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset5, LocVT, LocInfo));
    return false;
  }

  if (LocVT == MVT::f64) {
    if (State.getTarget().getSubtarget<OiSubtarget>().isNotSingleFloat()) {
      unsigned Offset6 = State.AllocateStack(8, 8);
      State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset6, LocVT, LocInfo));
      return false;
    }
  }

  return true;  // CC didn't match.
}


static bool CC_OiN(unsigned ValNo, MVT ValVT,
                   MVT LocVT, CCValAssign::LocInfo LocInfo,
                   ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i8 ||
      LocVT == MVT::i16) {
    LocVT = MVT::i32;
    if (ArgFlags.isSExt())
        LocInfo = CCValAssign::SExt;
    else if (ArgFlags.isZExt())
        LocInfo = CCValAssign::ZExt;
    else
        LocInfo = CCValAssign::AExt;
  }

  if (LocVT == MVT::i32) {
    static const uint16_t RegList1[] = {
      Oi::A0, Oi::A1, Oi::A2, Oi::A3, Oi::T0, Oi::T1, Oi::T2, Oi::T3
    };
    static const uint16_t RegList2[] = {
      Oi::F12, Oi::F13, Oi::F14, Oi::F15, Oi::F16, Oi::F17, Oi::F18, Oi::F19
    };
    if (unsigned Reg = State.AllocateReg(RegList1, RegList2, 8)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i64) {
    static const uint16_t RegList3[] = {
      Oi::A0_64, Oi::A1_64, Oi::A2_64, Oi::A3_64, Oi::T0_64, Oi::T1_64, Oi::T2_64, Oi::T3_64
    };
    static const uint16_t RegList4[] = {
      Oi::D12_64, Oi::D13_64, Oi::D14_64, Oi::D15_64, Oi::D16_64, Oi::D17_64, Oi::D18_64, Oi::D19_64
    };
    if (unsigned Reg = State.AllocateReg(RegList3, RegList4, 8)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    static const uint16_t RegList5[] = {
      Oi::F12, Oi::F13, Oi::F14, Oi::F15, Oi::F16, Oi::F17, Oi::F18, Oi::F19
    };
    static const uint16_t RegList6[] = {
      Oi::A0_64, Oi::A1_64, Oi::A2_64, Oi::A3_64, Oi::T0_64, Oi::T1_64, Oi::T2_64, Oi::T3_64
    };
    if (unsigned Reg = State.AllocateReg(RegList5, RegList6, 8)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    static const uint16_t RegList7[] = {
      Oi::D12_64, Oi::D13_64, Oi::D14_64, Oi::D15_64, Oi::D16_64, Oi::D17_64, Oi::D18_64, Oi::D19_64
    };
    static const uint16_t RegList8[] = {
      Oi::A0_64, Oi::A1_64, Oi::A2_64, Oi::A3_64, Oi::T0_64, Oi::T1_64, Oi::T2_64, Oi::T3_64
    };
    if (unsigned Reg = State.AllocateReg(RegList7, RegList8, 8)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i32 ||
      LocVT == MVT::f32) {
    unsigned Offset9 = State.AllocateStack(4, 8);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset9, LocVT, LocInfo));
    return false;
  }

  if (LocVT == MVT::i64 ||
      LocVT == MVT::f64) {
    unsigned Offset10 = State.AllocateStack(8, 8);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset10, LocVT, LocInfo));
    return false;
  }

  return true;  // CC didn't match.
}


static bool CC_OiN_FastCC(unsigned ValNo, MVT ValVT,
                          MVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i64) {
    static const uint16_t RegList1[] = {
      Oi::A0_64, Oi::A1_64, Oi::A2_64, Oi::A3_64, Oi::T0_64, Oi::T1_64, Oi::T2_64, Oi::T3_64, Oi::T4_64, Oi::T5_64, Oi::T6_64, Oi::T7_64, Oi::T8_64, Oi::V1_64
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 14)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    static const uint16_t RegList2[] = {
      Oi::D0_64, Oi::D1_64, Oi::D2_64, Oi::D3_64, Oi::D4_64, Oi::D5_64, Oi::D6_64, Oi::D7_64, Oi::D8_64, Oi::D9_64, Oi::D10_64, Oi::D11_64, Oi::D12_64, Oi::D13_64, Oi::D14_64, Oi::D15_64, Oi::D16_64, Oi::D17_64, Oi::D18_64, Oi::D19_64
    };
    if (unsigned Reg = State.AllocateReg(RegList2, 20)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i64 ||
      LocVT == MVT::f64) {
    unsigned Offset3 = State.AllocateStack(8, 8);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset3, LocVT, LocInfo));
    return false;
  }

  return true;  // CC didn't match.
}


static bool CC_OiN_VarArg(unsigned ValNo, MVT ValVT,
                          MVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i8 ||
      LocVT == MVT::i16) {
    LocVT = MVT::i32;
    if (ArgFlags.isSExt())
        LocInfo = CCValAssign::SExt;
    else if (ArgFlags.isZExt())
        LocInfo = CCValAssign::ZExt;
    else
        LocInfo = CCValAssign::AExt;
  }

  if (LocVT == MVT::i32 ||
      LocVT == MVT::f32) {
    static const uint16_t RegList1[] = {
      Oi::A0, Oi::A1, Oi::A2, Oi::A3, Oi::T0, Oi::T1, Oi::T2, Oi::T3
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 8)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i64 ||
      LocVT == MVT::f64) {
    static const uint16_t RegList2[] = {
      Oi::A0_64, Oi::A1_64, Oi::A2_64, Oi::A3_64, Oi::T0_64, Oi::T1_64, Oi::T2_64, Oi::T3_64
    };
    if (unsigned Reg = State.AllocateReg(RegList2, 8)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i32 ||
      LocVT == MVT::f32) {
    unsigned Offset3 = State.AllocateStack(4, 8);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset3, LocVT, LocInfo));
    return false;
  }

  if (LocVT == MVT::i64 ||
      LocVT == MVT::f64) {
    unsigned Offset4 = State.AllocateStack(8, 8);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset4, LocVT, LocInfo));
    return false;
  }

  return true;  // CC didn't match.
}


static bool CC_OiO32_FastCC(unsigned ValNo, MVT ValVT,
                            MVT LocVT, CCValAssign::LocInfo LocInfo,
                            ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::f64) {
    static const uint16_t RegList1[] = {
      Oi::D0, Oi::D1, Oi::D2, Oi::D3, Oi::D4, Oi::D5, Oi::D6, Oi::D7, Oi::D8, Oi::D9
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 10)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    unsigned Offset2 = State.AllocateStack(8, 8);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset2, LocVT, LocInfo));
    return false;
  }

  return true;  // CC didn't match.
}


static bool CC_Oi_FastCC(unsigned ValNo, MVT ValVT,
                         MVT LocVT, CCValAssign::LocInfo LocInfo,
                         ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (ArgFlags.isByVal()) {
    State.HandleByVal(ValNo, ValVT, LocVT, LocInfo, 4, 4, ArgFlags);
    return false;
  }

  if (LocVT == MVT::i8 ||
      LocVT == MVT::i16) {
    LocVT = MVT::i32;
    if (ArgFlags.isSExt())
        LocInfo = CCValAssign::SExt;
    else if (ArgFlags.isZExt())
        LocInfo = CCValAssign::ZExt;
    else
        LocInfo = CCValAssign::AExt;
  }

  if (LocVT == MVT::i32) {
    static const uint16_t RegList1[] = {
      Oi::A0, Oi::A1, Oi::A2, Oi::A3, Oi::T0, Oi::T1, Oi::T2, Oi::T3, Oi::T4, Oi::T5, Oi::T6, Oi::T7, Oi::T8, Oi::V1
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 14)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    static const uint16_t RegList2[] = {
      Oi::F0, Oi::F1, Oi::F2, Oi::F3, Oi::F4, Oi::F5, Oi::F6, Oi::F7, Oi::F8, Oi::F9, Oi::F10, Oi::F11, Oi::F12, Oi::F13, Oi::F14, Oi::F15, Oi::F16, Oi::F17, Oi::F18, Oi::F19
    };
    if (unsigned Reg = State.AllocateReg(RegList2, 20)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i32 ||
      LocVT == MVT::f32) {
    unsigned Offset3 = State.AllocateStack(4, 4);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset3, LocVT, LocInfo));
    return false;
  }

  if (State.getTarget().getSubtarget<OiSubtarget>().isABI_EABI()) {
    if (!CC_OiEABI(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (State.getTarget().getSubtarget<OiSubtarget>().isABI_O32()) {
    if (!CC_OiO32_FastCC(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (!CC_OiN_FastCC(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
    return false;

  return true;  // CC didn't match.
}


static bool RetCC_Oi(unsigned ValNo, MVT ValVT,
                     MVT LocVT, CCValAssign::LocInfo LocInfo,
                     ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (State.getTarget().getSubtarget<OiSubtarget>().isABI_EABI()) {
    if (!RetCC_OiEABI(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (State.getTarget().getSubtarget<OiSubtarget>().isABI_N32()) {
    if (!RetCC_OiN(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (State.getTarget().getSubtarget<OiSubtarget>().isABI_N64()) {
    if (!RetCC_OiN(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (State.getTarget().getSubtarget<OiSubtarget>().isAndroid()) {
    if (!RetCC_OiAndroid(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (!RetCC_OiO32(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
    return false;

  return true;  // CC didn't match.
}


static bool RetCC_OiAndroid(unsigned ValNo, MVT ValVT,
                            MVT LocVT, CCValAssign::LocInfo LocInfo,
                            ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::f32) {
    static const uint16_t RegList1[] = {
      Oi::F0, Oi::F2, Oi::F1, Oi::F3
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 4)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (!RetCC_OiO32(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
    return false;

  return true;  // CC didn't match.
}


static bool RetCC_OiEABI(unsigned ValNo, MVT ValVT,
                         MVT LocVT, CCValAssign::LocInfo LocInfo,
                         ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i32) {
    static const uint16_t RegList1[] = {
      Oi::V0, Oi::V1
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    static const uint16_t RegList2[] = {
      Oi::F0, Oi::F1
    };
    if (unsigned Reg = State.AllocateReg(RegList2, 2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    if (State.getTarget().getSubtarget<OiSubtarget>().isNotSingleFloat()) {
      if (unsigned Reg = State.AllocateReg(Oi::D0)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  return true;  // CC didn't match.
}


static bool RetCC_OiN(unsigned ValNo, MVT ValVT,
                      MVT LocVT, CCValAssign::LocInfo LocInfo,
                      ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i32) {
    static const uint16_t RegList1[] = {
      Oi::V0, Oi::V1
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i64) {
    static const uint16_t RegList2[] = {
      Oi::V0_64, Oi::V1_64
    };
    if (unsigned Reg = State.AllocateReg(RegList2, 2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    static const uint16_t RegList3[] = {
      Oi::F0, Oi::F2
    };
    if (unsigned Reg = State.AllocateReg(RegList3, 2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    static const uint16_t RegList4[] = {
      Oi::D0_64, Oi::D2_64
    };
    if (unsigned Reg = State.AllocateReg(RegList4, 2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  return true;  // CC didn't match.
}


static bool RetCC_OiO32(unsigned ValNo, MVT ValVT,
                        MVT LocVT, CCValAssign::LocInfo LocInfo,
                        ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i32) {
    static const uint16_t RegList1[] = {
      Oi::V0, Oi::V1, Oi::A0, Oi::A1
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 4)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    static const uint16_t RegList2[] = {
      Oi::F0, Oi::F2
    };
    if (unsigned Reg = State.AllocateReg(RegList2, 2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    if (State.getTarget().getSubtarget<OiSubtarget>().isNotSingleFloat()) {
      static const uint16_t RegList3[] = {
        Oi::D0, Oi::D1
      };
      if (unsigned Reg = State.AllocateReg(RegList3, 2)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  return true;  // CC didn't match.
}
