/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Machine Code Emitter                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

uint64_t OiCodeEmitter::getBinaryCodeForInstr(const MachineInstr &MI) const {
  static const uint64_t InstBits[] = {
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(2080375378),	// ABSQ_S_PH
    UINT64_C(2080374866),	// ABSQ_S_QB
    UINT64_C(2080375890),	// ABSQ_S_W
    UINT64_C(32),	// ADD
    UINT64_C(2080375320),	// ADDQH_PH
    UINT64_C(2080375448),	// ADDQH_R_PH
    UINT64_C(2080375960),	// ADDQH_R_W
    UINT64_C(2080375832),	// ADDQH_W
    UINT64_C(2080375440),	// ADDQ_PH
    UINT64_C(2080375696),	// ADDQ_S_PH
    UINT64_C(2080376208),	// ADDQ_S_W
    UINT64_C(2080375824),	// ADDSC
    UINT64_C(2080374808),	// ADDUH_QB
    UINT64_C(2080374936),	// ADDUH_R_QB
    UINT64_C(2080375312),	// ADDU_PH
    UINT64_C(2080374800),	// ADDU_QB
    UINT64_C(2080375568),	// ADDU_S_PH
    UINT64_C(2080375056),	// ADDU_S_QB
    UINT64_C(2080375888),	// ADDWC
    UINT64_C(536870912),	// ADDi
    UINT64_C(603979776),	// ADDiu
    UINT64_C(33),	// ADDu
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(36),	// AND
    UINT64_C(36),	// AND64
    UINT64_C(805306368),	// ANDi
    UINT64_C(2080374833),	// APPEND
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(4026550272),	// AddiuRxImmX16
    UINT64_C(4026533888),	// AddiuRxPcImmX16
    UINT64_C(4026550272),	// AddiuRxRxImmX16
    UINT64_C(4026548224),	// AddiuRxRyOffMemX16
    UINT64_C(4026544896),	// AddiuSpImmX16
    UINT64_C(57345),	// AdduRxRyRz16
    UINT64_C(59404),	// AndRxRxRy16
    UINT64_C(268435456),	// B
    UINT64_C(2080375857),	// BALIGN
    UINT64_C(68222976),	// BAL_BR
    UINT64_C(1157627904),	// BC1F
    UINT64_C(1157693440),	// BC1T
    UINT64_C(268435456),	// BEQ
    UINT64_C(268435456),	// BEQ64
    UINT64_C(67174400),	// BGEZ
    UINT64_C(67174400),	// BGEZ64
    UINT64_C(68222976),	// BGEZAL
    UINT64_C(469762048),	// BGTZ
    UINT64_C(469762048),	// BGTZ64
    UINT64_C(2080376530),	// BITREV
    UINT64_C(402653184),	// BLEZ
    UINT64_C(402653184),	// BLEZ64
    UINT64_C(67108864),	// BLTZ
    UINT64_C(67108864),	// BLTZ64
    UINT64_C(68157440),	// BLTZAL
    UINT64_C(335544320),	// BNE
    UINT64_C(335544320),	// BNE64
    UINT64_C(68943872),	// BPOSGE32
    UINT64_C(0),
    UINT64_C(4026540032),	// BeqzRxImmX16
    UINT64_C(4026535936),	// BimmX16
    UINT64_C(4026542080),	// BnezRxImmX16
    UINT64_C(4026544128),	// BteqzT8CmpX16
    UINT64_C(4026544128),	// BteqzT8CmpiX16
    UINT64_C(4026544128),	// BteqzT8SltX16
    UINT64_C(4026544128),	// BteqzT8SltiX16
    UINT64_C(4026544128),	// BteqzT8SltiuX16
    UINT64_C(4026544128),	// BteqzT8SltuX16
    UINT64_C(4026544128),	// BteqzX16
    UINT64_C(4026544128),	// BtnezT8CmpX16
    UINT64_C(4026544128),	// BtnezT8CmpiX16
    UINT64_C(4026544128),	// BtnezT8SltX16
    UINT64_C(4026544128),	// BtnezT8SltiX16
    UINT64_C(4026544128),	// BtnezT8SltiuX16
    UINT64_C(4026544128),	// BtnezT8SltuX16
    UINT64_C(4026544384),	// BtnezX16
    UINT64_C(0),
    UINT64_C(1176502282),	// CEIL_L_D64
    UINT64_C(1174405130),	// CEIL_L_S
    UINT64_C(1176502286),	// CEIL_W_D32
    UINT64_C(1176502286),	// CEIL_W_D64
    UINT64_C(1174405134),	// CEIL_W_S
    UINT64_C(1145044992),	// CFC1
    UINT64_C(1879048225),	// CLO
    UINT64_C(1879048224),	// CLZ
    UINT64_C(2080376337),	// CMPGDU_EQ_QB
    UINT64_C(2080376465),	// CMPGDU_LE_QB
    UINT64_C(2080376401),	// CMPGDU_LT_QB
    UINT64_C(2080375057),	// CMPGU_EQ_QB
    UINT64_C(2080375185),	// CMPGU_LE_QB
    UINT64_C(2080375121),	// CMPGU_LT_QB
    UINT64_C(2080374801),	// CMPU_EQ_QB
    UINT64_C(2080374929),	// CMPU_LE_QB
    UINT64_C(2080374865),	// CMPU_LT_QB
    UINT64_C(2080375313),	// CMP_EQ_PH
    UINT64_C(2080375441),	// CMP_LE_PH
    UINT64_C(2080375377),	// CMP_LT_PH
    UINT64_C(1153433600),	// CTC1
    UINT64_C(1174405153),	// CVT_D32_S
    UINT64_C(1182793761),	// CVT_D32_W
    UINT64_C(1184890913),	// CVT_D64_L
    UINT64_C(1174405153),	// CVT_D64_S
    UINT64_C(1182793761),	// CVT_D64_W
    UINT64_C(1176502309),	// CVT_L_D64
    UINT64_C(1174405157),	// CVT_L_S
    UINT64_C(1176502304),	// CVT_S_D32
    UINT64_C(1176502304),	// CVT_S_D64
    UINT64_C(1184890912),	// CVT_S_L
    UINT64_C(1182793760),	// CVT_S_W
    UINT64_C(1176502308),	// CVT_W_D32
    UINT64_C(1176502308),	// CVT_W_D64
    UINT64_C(1174405156),	// CVT_W_S
    UINT64_C(0),
    UINT64_C(44),	// DADD
    UINT64_C(1610612736),	// DADDi
    UINT64_C(1677721600),	// DADDiu
    UINT64_C(45),	// DADDu
    UINT64_C(805306368),	// DANDi
    UINT64_C(1879048229),	// DCLO
    UINT64_C(1879048228),	// DCLZ
    UINT64_C(2080374787),	// DEXT
    UINT64_C(2080374785),	// DEXTM
    UINT64_C(2080374786),	// DEXTU
    UINT64_C(2080374791),	// DINS
    UINT64_C(2080374789),	// DINSM
    UINT64_C(2080374790),	// DINSU
    UINT64_C(1075838976),	// DMFC0_3OP64
    UINT64_C(1142947840),	// DMFC1
    UINT64_C(1210056704),	// DMFC2_3OP64
    UINT64_C(1084227584),	// DMTC0_3OP64
    UINT64_C(1151336448),	// DMTC1
    UINT64_C(1218445312),	// DMTC2_3OP64
    UINT64_C(28),	// DMULT
    UINT64_C(29),	// DMULTu
    UINT64_C(2080376496),	// DPAQX_SA_W_PH
    UINT64_C(0),
    UINT64_C(2080376368),	// DPAQX_S_W_PH
    UINT64_C(0),
    UINT64_C(2080375600),	// DPAQ_SA_L_W
    UINT64_C(0),
    UINT64_C(2080375088),	// DPAQ_S_W_PH
    UINT64_C(0),
    UINT64_C(2080375024),	// DPAU_H_QBL
    UINT64_C(0),
    UINT64_C(2080375280),	// DPAU_H_QBR
    UINT64_C(0),
    UINT64_C(2080375344),	// DPAX_W_PH
    UINT64_C(0),
    UINT64_C(2080374832),	// DPA_W_PH
    UINT64_C(0),
    UINT64_C(2080376560),	// DPSQX_SA_W_PH
    UINT64_C(0),
    UINT64_C(2080376432),	// DPSQX_S_W_PH
    UINT64_C(0),
    UINT64_C(2080375664),	// DPSQ_SA_L_W
    UINT64_C(0),
    UINT64_C(2080375152),	// DPSQ_S_W_PH
    UINT64_C(0),
    UINT64_C(2080375536),	// DPSU_H_QBL
    UINT64_C(0),
    UINT64_C(2080375792),	// DPSU_H_QBR
    UINT64_C(0),
    UINT64_C(2080375408),	// DPSX_W_PH
    UINT64_C(0),
    UINT64_C(2080374896),	// DPS_W_PH
    UINT64_C(0),
    UINT64_C(2097210),	// DROTR
    UINT64_C(86),	// DROTRV
    UINT64_C(2080374948),	// DSBH
    UINT64_C(30),	// DSDIV
    UINT64_C(2080375140),	// DSHD
    UINT64_C(56),	// DSLL
    UINT64_C(60),	// DSLL32
    UINT64_C(60),	// DSLL64_32
    UINT64_C(20),	// DSLLV
    UINT64_C(59),	// DSRA
    UINT64_C(63),	// DSRA32
    UINT64_C(23),	// DSRAV
    UINT64_C(58),	// DSRL
    UINT64_C(62),	// DSRL32
    UINT64_C(22),	// DSRLV
    UINT64_C(47),	// DSUBu
    UINT64_C(31),	// DUDIV
    UINT64_C(59418),	// DivRxRy16
    UINT64_C(59419),	// DivuRxRy16
    UINT64_C(2080374784),	// EXT
    UINT64_C(2080374968),	// EXTP
    UINT64_C(2080375480),	// EXTPDP
    UINT64_C(2080375544),	// EXTPDPV
    UINT64_C(2080375032),	// EXTPV
    UINT64_C(2080375288),	// EXTRV_RS_W
    UINT64_C(2080375160),	// EXTRV_R_W
    UINT64_C(2080375800),	// EXTRV_S_H
    UINT64_C(2080374904),	// EXTRV_W
    UINT64_C(2080375224),	// EXTR_RS_W
    UINT64_C(2080375096),	// EXTR_R_W
    UINT64_C(2080375736),	// EXTR_S_H
    UINT64_C(2080374840),	// EXTR_W
    UINT64_C(0),
    UINT64_C(1176502277),	// FABS_D32
    UINT64_C(1176502277),	// FABS_D64
    UINT64_C(1174405125),	// FABS_S
    UINT64_C(1176502272),	// FADD_D32
    UINT64_C(1176502272),	// FADD_D64
    UINT64_C(1174405120),	// FADD_S
    UINT64_C(1176502320),	// FCMP_D32
    UINT64_C(1176502320),	// FCMP_D64
    UINT64_C(1174405168),	// FCMP_S32
    UINT64_C(1176502275),	// FDIV_D32
    UINT64_C(1176502275),	// FDIV_D64
    UINT64_C(1174405123),	// FDIV_S
    UINT64_C(1176502283),	// FLOOR_L_D64
    UINT64_C(1174405131),	// FLOOR_L_S
    UINT64_C(1176502287),	// FLOOR_W_D32
    UINT64_C(1176502287),	// FLOOR_W_D64
    UINT64_C(1174405135),	// FLOOR_W_S
    UINT64_C(1176502278),	// FMOV_D32
    UINT64_C(1176502278),	// FMOV_D64
    UINT64_C(1174405126),	// FMOV_S
    UINT64_C(1176502274),	// FMUL_D32
    UINT64_C(1176502274),	// FMUL_D64
    UINT64_C(1174405122),	// FMUL_S
    UINT64_C(1176502279),	// FNEG_D32
    UINT64_C(1176502279),	// FNEG_D64
    UINT64_C(1174405127),	// FNEG_S
    UINT64_C(1176502276),	// FSQRT_D32
    UINT64_C(1176502276),	// FSQRT_D64
    UINT64_C(1174405124),	// FSQRT_S
    UINT64_C(1176502273),	// FSUB_D32
    UINT64_C(1176502273),	// FSUB_D64
    UINT64_C(1174405121),	// FSUB_S
    UINT64_C(2080374788),	// INS
    UINT64_C(2080374796),	// INSV
    UINT64_C(134217728),	// J
    UINT64_C(201326592),	// JAL
    UINT64_C(63497),	// JALR
    UINT64_C(63497),	// JALR64
    UINT64_C(8),	// JR
    UINT64_C(8),	// JR64
    UINT64_C(59424),	// JrRa16
    UINT64_C(59424),	// JrcRa16
    UINT64_C(59584),	// JrcRx16
    UINT64_C(59392),	// JumpLinkReg16
    UINT64_C(2147483648),	// LB
    UINT64_C(2147483648),	// LB64
    UINT64_C(2147483648),	// LB64_P8
    UINT64_C(2080375178),	// LBUX
    UINT64_C(2147483648),	// LB_P8
    UINT64_C(2415919104),	// LBu
    UINT64_C(2415919104),	// LBu64
    UINT64_C(2415919104),	// LBu64_P8
    UINT64_C(2415919104),	// LBu_P8
    UINT64_C(3690987520),	// LD
    UINT64_C(3556769792),	// LDC1
    UINT64_C(3556769792),	// LDC164
    UINT64_C(3556769792),	// LDC164_P8
    UINT64_C(1744830464),	// LDL
    UINT64_C(1744830464),	// LDL_P8
    UINT64_C(1811939328),	// LDR
    UINT64_C(1811939328),	// LDR_P8
    UINT64_C(1275068417),	// LDXC1
    UINT64_C(1275068417),	// LDXC164
    UINT64_C(1275068417),	// LDXC164_P8
    UINT64_C(3690987520),	// LD_P8
    UINT64_C(603979776),	// LEA_ADDiu
    UINT64_C(1677721600),	// LEA_ADDiu64
    UINT64_C(2214592512),	// LH
    UINT64_C(2214592512),	// LH64
    UINT64_C(2214592512),	// LH64_P8
    UINT64_C(2080375050),	// LHX
    UINT64_C(2214592512),	// LH_P8
    UINT64_C(2483027968),	// LHu
    UINT64_C(2483027968),	// LHu64
    UINT64_C(2483027968),	// LHu64_P8
    UINT64_C(2483027968),	// LHu_P8
    UINT64_C(3221225472),	// LL
    UINT64_C(3489660928),	// LLD
    UINT64_C(3489660928),	// LLD_P8
    UINT64_C(3221225472),	// LL_P8
    UINT64_C(1275068421),	// LUXC1
    UINT64_C(1275068421),	// LUXC164
    UINT64_C(1006632960),	// LUi
    UINT64_C(1006632960),	// LUi64
    UINT64_C(2348810240),	// LW
    UINT64_C(2348810240),	// LW64
    UINT64_C(2348810240),	// LW64_P8
    UINT64_C(3288334336),	// LWC1
    UINT64_C(3288334336),	// LWC1_P8
    UINT64_C(2281701376),	// LWL
    UINT64_C(2281701376),	// LWL64
    UINT64_C(2281701376),	// LWL64_P8
    UINT64_C(2281701376),	// LWL_P8
    UINT64_C(2550136832),	// LWR
    UINT64_C(2550136832),	// LWR64
    UINT64_C(2550136832),	// LWR64_P8
    UINT64_C(2550136832),	// LWR_P8
    UINT64_C(2080374794),	// LWX
    UINT64_C(1275068416),	// LWXC1
    UINT64_C(1275068416),	// LWXC1_P8
    UINT64_C(2348810240),	// LW_P8
    UINT64_C(2617245696),	// LWu64
    UINT64_C(2617245696),	// LWu64_P8
    UINT64_C(4026570752),	// LbRxRyOffMemX16
    UINT64_C(4026572800),	// LbuRxRyOffMemX16
    UINT64_C(4026572800),	// LhRxRyOffMemX16
    UINT64_C(4026572800),	// LhuRxRyOffMemX16
    UINT64_C(4026558464),	// LiRxImmX16
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(4026570752),	// LwRxRyOffMemX16
    UINT64_C(4026576896),	// LwRxSpImmX16
    UINT64_C(1879048192),	// MADD
    UINT64_C(1879048193),	// MADDU
    UINT64_C(1879048193),	// MADDU_DSP
    UINT64_C(0),
    UINT64_C(1275068449),	// MADD_D32
    UINT64_C(1275068449),	// MADD_D64
    UINT64_C(1879048192),	// MADD_DSP
    UINT64_C(0),
    UINT64_C(1275068448),	// MADD_S
    UINT64_C(2080375856),	// MAQ_SA_W_PHL
    UINT64_C(0),
    UINT64_C(2080375984),	// MAQ_SA_W_PHR
    UINT64_C(0),
    UINT64_C(2080376112),	// MAQ_S_W_PHL
    UINT64_C(0),
    UINT64_C(2080376240),	// MAQ_S_W_PHR
    UINT64_C(0),
    UINT64_C(1073741824),	// MFC0_3OP
    UINT64_C(1140850688),	// MFC1
    UINT64_C(1207959552),	// MFC2_3OP
    UINT64_C(16),	// MFHI
    UINT64_C(16),	// MFHI64
    UINT64_C(18),	// MFLO
    UINT64_C(18),	// MFLO64
    UINT64_C(2080375952),	// MODSUB
    UINT64_C(0),
    UINT64_C(1176502289),	// MOVF_D32
    UINT64_C(1176502289),	// MOVF_D64
    UINT64_C(1),	// MOVF_I
    UINT64_C(1),	// MOVF_I64
    UINT64_C(1174405137),	// MOVF_S
    UINT64_C(1176502291),	// MOVN_I64_D64
    UINT64_C(11),	// MOVN_I64_I
    UINT64_C(11),	// MOVN_I64_I64
    UINT64_C(1174405139),	// MOVN_I64_S
    UINT64_C(1176502291),	// MOVN_I_D32
    UINT64_C(1176502291),	// MOVN_I_D64
    UINT64_C(11),	// MOVN_I_I
    UINT64_C(11),	// MOVN_I_I64
    UINT64_C(1174405139),	// MOVN_I_S
    UINT64_C(1176567825),	// MOVT_D32
    UINT64_C(1176567825),	// MOVT_D64
    UINT64_C(65537),	// MOVT_I
    UINT64_C(65537),	// MOVT_I64
    UINT64_C(1174470673),	// MOVT_S
    UINT64_C(1176502290),	// MOVZ_I64_D64
    UINT64_C(10),	// MOVZ_I64_I
    UINT64_C(10),	// MOVZ_I64_I64
    UINT64_C(1174405138),	// MOVZ_I64_S
    UINT64_C(1176502290),	// MOVZ_I_D32
    UINT64_C(1176502290),	// MOVZ_I_D64
    UINT64_C(10),	// MOVZ_I_I
    UINT64_C(10),	// MOVZ_I_I64
    UINT64_C(1174405138),	// MOVZ_I_S
    UINT64_C(1879048196),	// MSUB
    UINT64_C(1879048197),	// MSUBU
    UINT64_C(1879048197),	// MSUBU_DSP
    UINT64_C(0),
    UINT64_C(1275068457),	// MSUB_D32
    UINT64_C(1275068457),	// MSUB_D64
    UINT64_C(1879048196),	// MSUB_DSP
    UINT64_C(0),
    UINT64_C(1275068456),	// MSUB_S
    UINT64_C(1082130432),	// MTC0_3OP
    UINT64_C(1149239296),	// MTC1
    UINT64_C(1216348160),	// MTC2_3OP
    UINT64_C(17),	// MTHI
    UINT64_C(17),	// MTHI64
    UINT64_C(2080376824),	// MTHLIP
    UINT64_C(0),
    UINT64_C(19),	// MTLO
    UINT64_C(19),	// MTLO64
    UINT64_C(1879048194),	// MUL
    UINT64_C(2080376592),	// MULEQ_S_W_PHL
    UINT64_C(2080376656),	// MULEQ_S_W_PHR
    UINT64_C(2080375184),	// MULEU_S_PH_QBL
    UINT64_C(2080375248),	// MULEU_S_PH_QBR
    UINT64_C(2080376784),	// MULQ_RS_PH
    UINT64_C(2080376280),	// MULQ_RS_W
    UINT64_C(2080376720),	// MULQ_S_PH
    UINT64_C(2080376216),	// MULQ_S_W
    UINT64_C(2080375216),	// MULSAQ_S_W_PH
    UINT64_C(0),
    UINT64_C(2080374960),	// MULSA_W_PH
    UINT64_C(0),
    UINT64_C(24),	// MULT
    UINT64_C(25),	// MULTU_DSP
    UINT64_C(0),
    UINT64_C(24),	// MULT_DSP
    UINT64_C(0),
    UINT64_C(25),	// MULTu
    UINT64_C(2080375576),	// MUL_PH
    UINT64_C(2080375704),	// MUL_S_PH
    UINT64_C(59408),	// Mfhi16
    UINT64_C(59410),	// Mflo16
    UINT64_C(25856),	// Move32R16
    UINT64_C(26368),	// MoveR3216
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(1275068465),	// NMADD_D32
    UINT64_C(1275068465),	// NMADD_D64
    UINT64_C(1275068464),	// NMADD_S
    UINT64_C(1275068473),	// NMSUB_D32
    UINT64_C(1275068473),	// NMSUB_D64
    UINT64_C(1275068472),	// NMSUB_S
    UINT64_C(0),	// NOP
    UINT64_C(39),	// NOR
    UINT64_C(39),	// NOR64
    UINT64_C(59421),	// NegRxRy16
    UINT64_C(59407),	// NotRxRy16
    UINT64_C(37),	// OR
    UINT64_C(37),	// OR64
    UINT64_C(872415232),	// ORi
    UINT64_C(872415232),	// ORi64
    UINT64_C(59405),	// OrRxRxRy16
    UINT64_C(2080375697),	// PACKRL_PH
    UINT64_C(2080375505),	// PICK_PH
    UINT64_C(2080374993),	// PICK_QB
    UINT64_C(2080375058),	// PRECEQU_PH_QBL
    UINT64_C(2080375186),	// PRECEQU_PH_QBLA
    UINT64_C(2080375122),	// PRECEQU_PH_QBR
    UINT64_C(2080375250),	// PRECEQU_PH_QBRA
    UINT64_C(2080375570),	// PRECEQ_W_PHL
    UINT64_C(2080375634),	// PRECEQ_W_PHR
    UINT64_C(2080376594),	// PRECEU_PH_QBL
    UINT64_C(2080376722),	// PRECEU_PH_QBLA
    UINT64_C(2080376658),	// PRECEU_PH_QBR
    UINT64_C(2080376786),	// PRECEU_PH_QBRA
    UINT64_C(2080375761),	// PRECRQU_S_QB_PH
    UINT64_C(2080376081),	// PRECRQ_PH_W
    UINT64_C(2080375569),	// PRECRQ_QB_PH
    UINT64_C(2080376145),	// PRECRQ_RS_PH_W
    UINT64_C(2080375633),	// PRECR_QB_PH
    UINT64_C(2080376721),	// PRECR_SRA_PH_W
    UINT64_C(2080376785),	// PRECR_SRA_R_PH_W
    UINT64_C(2080374897),	// PREPEND
    UINT64_C(2080376080),	// RADDU_W_QB
    UINT64_C(2080375992),	// RDDSP
    UINT64_C(2080374843),	// RDHWR
    UINT64_C(2080374843),	// RDHWR64
    UINT64_C(2080375506),	// REPLV_PH
    UINT64_C(2080374994),	// REPLV_QB
    UINT64_C(2080375442),	// REPL_PH
    UINT64_C(2080374930),	// REPL_QB
    UINT64_C(8),	// RET
    UINT64_C(2097154),	// ROTR
    UINT64_C(70),	// ROTRV
    UINT64_C(1176502280),	// ROUND_L_D64
    UINT64_C(1174405128),	// ROUND_L_S
    UINT64_C(1176502284),	// ROUND_W_D32
    UINT64_C(1176502284),	// ROUND_W_D64
    UINT64_C(1174405132),	// ROUND_W_S
    UINT64_C(25600),	// RestoreIncSpF16
    UINT64_C(25712),	// RestoreRaF16
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(2684354560),	// SB
    UINT64_C(2684354560),	// SB64
    UINT64_C(2684354560),	// SB64_P8
    UINT64_C(2684354560),	// SB_P8
    UINT64_C(3758096384),	// SC
    UINT64_C(4026531840),	// SCD
    UINT64_C(4026531840),	// SCD_P8
    UINT64_C(3758096384),	// SC_P8
    UINT64_C(4227858432),	// SD
    UINT64_C(4093640704),	// SDC1
    UINT64_C(4093640704),	// SDC164
    UINT64_C(4093640704),	// SDC164_P8
    UINT64_C(26),	// SDIV
    UINT64_C(2952790016),	// SDL
    UINT64_C(2952790016),	// SDL_P8
    UINT64_C(3019898880),	// SDR
    UINT64_C(3019898880),	// SDR_P8
    UINT64_C(1275068425),	// SDXC1
    UINT64_C(1275068425),	// SDXC164
    UINT64_C(1275068425),	// SDXC164_P8
    UINT64_C(4227858432),	// SD_P8
    UINT64_C(2080375840),	// SEB
    UINT64_C(2080375840),	// SEB64
    UINT64_C(2080376352),	// SEH
    UINT64_C(2080376352),	// SEH64
    UINT64_C(2751463424),	// SH
    UINT64_C(2751463424),	// SH64
    UINT64_C(2751463424),	// SH64_P8
    UINT64_C(2080376504),	// SHILO
    UINT64_C(2080376568),	// SHILOV
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(2080375443),	// SHLLV_PH
    UINT64_C(2080374931),	// SHLLV_QB
    UINT64_C(2080375699),	// SHLLV_S_PH
    UINT64_C(2080376211),	// SHLLV_S_W
    UINT64_C(2080375315),	// SHLL_PH
    UINT64_C(2080374803),	// SHLL_QB
    UINT64_C(2080375571),	// SHLL_S_PH
    UINT64_C(2080376083),	// SHLL_S_W
    UINT64_C(2080375507),	// SHRAV_PH
    UINT64_C(2080375187),	// SHRAV_QB
    UINT64_C(2080375763),	// SHRAV_R_PH
    UINT64_C(2080375251),	// SHRAV_R_QB
    UINT64_C(2080376275),	// SHRAV_R_W
    UINT64_C(2080375379),	// SHRA_PH
    UINT64_C(2080375059),	// SHRA_QB
    UINT64_C(2080375635),	// SHRA_R_PH
    UINT64_C(2080375123),	// SHRA_R_QB
    UINT64_C(2080376147),	// SHRA_R_W
    UINT64_C(2080376531),	// SHRLV_PH
    UINT64_C(2080374995),	// SHRLV_QB
    UINT64_C(2080376403),	// SHRL_PH
    UINT64_C(2080374867),	// SHRL_QB
    UINT64_C(2751463424),	// SH_P8
    UINT64_C(0),	// SLL
    UINT64_C(0),	// SLL64_32
    UINT64_C(0),	// SLL64_64
    UINT64_C(4),	// SLLV
    UINT64_C(42),	// SLT
    UINT64_C(42),	// SLT64
    UINT64_C(671088640),	// SLTi
    UINT64_C(671088640),	// SLTi64
    UINT64_C(738197504),	// SLTiu
    UINT64_C(738197504),	// SLTiu64
    UINT64_C(43),	// SLTu
    UINT64_C(43),	// SLTu64
    UINT64_C(3),	// SRA
    UINT64_C(7),	// SRAV
    UINT64_C(2),	// SRL
    UINT64_C(6),	// SRLV
    UINT64_C(34),	// SUB
    UINT64_C(2080375384),	// SUBQH_PH
    UINT64_C(2080375512),	// SUBQH_R_PH
    UINT64_C(2080376024),	// SUBQH_R_W
    UINT64_C(2080375896),	// SUBQH_W
    UINT64_C(2080375504),	// SUBQ_PH
    UINT64_C(2080375760),	// SUBQ_S_PH
    UINT64_C(2080376272),	// SUBQ_S_W
    UINT64_C(2080374872),	// SUBUH_QB
    UINT64_C(2080375000),	// SUBUH_R_QB
    UINT64_C(2080375376),	// SUBU_PH
    UINT64_C(2080374864),	// SUBU_QB
    UINT64_C(2080375632),	// SUBU_S_PH
    UINT64_C(2080375120),	// SUBU_S_QB
    UINT64_C(35),	// SUBu
    UINT64_C(1275068429),	// SUXC1
    UINT64_C(1275068429),	// SUXC164
    UINT64_C(2885681152),	// SW
    UINT64_C(2885681152),	// SW64
    UINT64_C(2885681152),	// SW64_P8
    UINT64_C(3825205248),	// SWC1
    UINT64_C(3825205248),	// SWC1_P8
    UINT64_C(2818572288),	// SWL
    UINT64_C(2818572288),	// SWL64
    UINT64_C(2818572288),	// SWL64_P8
    UINT64_C(2818572288),	// SWL_P8
    UINT64_C(3087007744),	// SWR
    UINT64_C(3087007744),	// SWR64
    UINT64_C(3087007744),	// SWR64_P8
    UINT64_C(3087007744),	// SWR_P8
    UINT64_C(1275068424),	// SWXC1
    UINT64_C(1275068424),	// SWXC1_P8
    UINT64_C(2885681152),	// SW_P8
    UINT64_C(15),	// SYNC
    UINT64_C(25600),	// SaveDecSpF16
    UINT64_C(25840),	// SaveRaF16
    UINT64_C(4026580992),	// SbRxRyOffMemX16
    UINT64_C(0),	// SelBeqZ
    UINT64_C(0),	// SelBneZ
    UINT64_C(0),	// SelTBteqZCmp
    UINT64_C(0),	// SelTBteqZCmpi
    UINT64_C(0),	// SelTBteqZSlt
    UINT64_C(0),	// SelTBteqZSlti
    UINT64_C(0),	// SelTBteqZSltiu
    UINT64_C(0),	// SelTBteqZSltu
    UINT64_C(0),	// SelTBtneZCmp
    UINT64_C(0),	// SelTBtneZCmpi
    UINT64_C(0),	// SelTBtneZSlt
    UINT64_C(0),	// SelTBtneZSlti
    UINT64_C(0),	// SelTBtneZSltiu
    UINT64_C(0),	// SelTBtneZSltu
    UINT64_C(4026583040),	// ShRxRyOffMemX16
    UINT64_C(4026544128),	// SllX16
    UINT64_C(59396),	// SllvRxRy16
    UINT64_C(59394),	// SltCCRxRy16
    UINT64_C(59394),	// SltRxRy16
    UINT64_C(4026552320),	// SltiCCRxImmX16
    UINT64_C(4026554368),	// SltiuCCRxImmX16
    UINT64_C(59395),	// SltuCCRxRy16
    UINT64_C(59395),	// SltuRxRyRz16
    UINT64_C(4026544131),	// SraX16
    UINT64_C(59399),	// SravRxRy16
    UINT64_C(4026544130),	// SrlX16
    UINT64_C(59398),	// SrlvRxRy16
    UINT64_C(57347),	// SubuRxRyRz16
    UINT64_C(4026587136),	// SwRxRyOffMemX16
    UINT64_C(4026585088),	// SwRxSpImmX16
    UINT64_C(134217728),	// TAILCALL
    UINT64_C(8),	// TAILCALL64_R
    UINT64_C(8),	// TAILCALL_R
    UINT64_C(1176502281),	// TRUNC_L_D64
    UINT64_C(1174405129),	// TRUNC_L_S
    UINT64_C(1176502285),	// TRUNC_W_D32
    UINT64_C(1176502285),	// TRUNC_W_D64
    UINT64_C(1174405133),	// TRUNC_W_S
    UINT64_C(27),	// UDIV
    UINT64_C(2080376056),	// WRDSP
    UINT64_C(2080374944),	// WSBH
    UINT64_C(38),	// XOR
    UINT64_C(38),	// XOR64
    UINT64_C(939524096),	// XORi
    UINT64_C(939524096),	// XORi64
    UINT64_C(59406),	// XorRxRxRy16
    UINT64_C(0)
  };
  const unsigned opcode = MI.getOpcode();
  uint64_t Value = InstBits[opcode];
  uint64_t op = 0;
  (void)op;  // suppress warning
  switch (opcode) {
    case Oi::JrRa16:
    case Oi::JrcRa16:
    case Oi::NOP:
    case Oi::RestoreIncSpF16:
    case Oi::RestoreRaF16:
    case Oi::SaveDecSpF16:
    case Oi::SaveRaF16:
    case Oi::SelBeqZ:
    case Oi::SelBneZ:
    case Oi::SelTBteqZCmp:
    case Oi::SelTBteqZCmpi:
    case Oi::SelTBteqZSlt:
    case Oi::SelTBteqZSlti:
    case Oi::SelTBteqZSltiu:
    case Oi::SelTBteqZSltu:
    case Oi::SelTBtneZCmp:
    case Oi::SelTBtneZCmpi:
    case Oi::SelTBtneZSlt:
    case Oi::SelTBtneZSlti:
    case Oi::SelTBtneZSltiu:
    case Oi::SelTBtneZSltu: {
      break;
    }
    case Oi::MTHLIP:
    case Oi::SHILOV: {
      // op: ac
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(3)) << 11;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::DPAQX_SA_W_PH:
    case Oi::DPAQX_S_W_PH:
    case Oi::DPAQ_SA_L_W:
    case Oi::DPAQ_S_W_PH:
    case Oi::DPAU_H_QBL:
    case Oi::DPAU_H_QBR:
    case Oi::DPAX_W_PH:
    case Oi::DPA_W_PH:
    case Oi::DPSQX_SA_W_PH:
    case Oi::DPSQX_S_W_PH:
    case Oi::DPSQ_SA_L_W:
    case Oi::DPSQ_S_W_PH:
    case Oi::DPSU_H_QBL:
    case Oi::DPSU_H_QBR:
    case Oi::DPSX_W_PH:
    case Oi::DPS_W_PH:
    case Oi::MADDU_DSP:
    case Oi::MADD_DSP:
    case Oi::MAQ_SA_W_PHL:
    case Oi::MAQ_SA_W_PHR:
    case Oi::MAQ_S_W_PHL:
    case Oi::MAQ_S_W_PHR:
    case Oi::MSUBU_DSP:
    case Oi::MSUB_DSP:
    case Oi::MULSAQ_S_W_PH:
    case Oi::MULSA_W_PH:
    case Oi::MULTU_DSP:
    case Oi::MULT_DSP: {
      // op: ac
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(3)) << 11;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::SHILO: {
      // op: ac
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(3)) << 11;
      // op: shift
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(63)) << 20;
      break;
    }
    case Oi::LDXC1:
    case Oi::LDXC164:
    case Oi::LDXC164_P8:
    case Oi::LUXC1:
    case Oi::LUXC164:
    case Oi::LWXC1:
    case Oi::LWXC1_P8: {
      // op: fd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 6;
      // op: base
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: index
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::MADD_D32:
    case Oi::MADD_D64:
    case Oi::MADD_S:
    case Oi::MSUB_D32:
    case Oi::MSUB_D64:
    case Oi::MSUB_S:
    case Oi::NMADD_D32:
    case Oi::NMADD_D64:
    case Oi::NMADD_S:
    case Oi::NMSUB_D32:
    case Oi::NMSUB_D64:
    case Oi::NMSUB_S: {
      // op: fd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 6;
      // op: fr
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 11;
      // op: ft
      op = getMachineOpValue(MI, MI.getOperand(3));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::CEIL_L_D64:
    case Oi::CEIL_L_S:
    case Oi::CEIL_W_D32:
    case Oi::CEIL_W_D64:
    case Oi::CEIL_W_S:
    case Oi::CVT_D32_S:
    case Oi::CVT_D32_W:
    case Oi::CVT_D64_L:
    case Oi::CVT_D64_S:
    case Oi::CVT_D64_W:
    case Oi::CVT_L_D64:
    case Oi::CVT_L_S:
    case Oi::CVT_S_D32:
    case Oi::CVT_S_D64:
    case Oi::CVT_S_L:
    case Oi::CVT_S_W:
    case Oi::CVT_W_D32:
    case Oi::CVT_W_D64:
    case Oi::CVT_W_S:
    case Oi::FABS_D32:
    case Oi::FABS_D64:
    case Oi::FABS_S:
    case Oi::FLOOR_L_D64:
    case Oi::FLOOR_L_S:
    case Oi::FLOOR_W_D32:
    case Oi::FLOOR_W_D64:
    case Oi::FLOOR_W_S:
    case Oi::FMOV_D32:
    case Oi::FMOV_D64:
    case Oi::FMOV_S:
    case Oi::FNEG_D32:
    case Oi::FNEG_D64:
    case Oi::FNEG_S:
    case Oi::FSQRT_D32:
    case Oi::FSQRT_D64:
    case Oi::FSQRT_S:
    case Oi::MOVF_D32:
    case Oi::MOVF_D64:
    case Oi::MOVF_S:
    case Oi::MOVT_D32:
    case Oi::MOVT_D64:
    case Oi::MOVT_S:
    case Oi::ROUND_L_D64:
    case Oi::ROUND_L_S:
    case Oi::ROUND_W_D32:
    case Oi::ROUND_W_D64:
    case Oi::ROUND_W_S:
    case Oi::TRUNC_L_D64:
    case Oi::TRUNC_L_S:
    case Oi::TRUNC_W_D32:
    case Oi::TRUNC_W_D64:
    case Oi::TRUNC_W_S: {
      // op: fd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 6;
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::FADD_D32:
    case Oi::FADD_D64:
    case Oi::FADD_S:
    case Oi::FDIV_D32:
    case Oi::FDIV_D64:
    case Oi::FDIV_S:
    case Oi::FMUL_D32:
    case Oi::FMUL_D64:
    case Oi::FMUL_S:
    case Oi::FSUB_D32:
    case Oi::FSUB_D64:
    case Oi::FSUB_S: {
      // op: fd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 6;
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 11;
      // op: ft
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::MOVN_I64_D64:
    case Oi::MOVN_I64_S:
    case Oi::MOVN_I_D32:
    case Oi::MOVN_I_D64:
    case Oi::MOVN_I_S:
    case Oi::MOVZ_I64_D64:
    case Oi::MOVZ_I64_S:
    case Oi::MOVZ_I_D32:
    case Oi::MOVZ_I_D64:
    case Oi::MOVZ_I_S: {
      // op: fd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 6;
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 11;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::SDXC1:
    case Oi::SDXC164:
    case Oi::SDXC164_P8:
    case Oi::SUXC1:
    case Oi::SUXC164:
    case Oi::SWXC1:
    case Oi::SWXC1_P8: {
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: base
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: index
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::FCMP_D32:
    case Oi::FCMP_D64:
    case Oi::FCMP_S32: {
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: ft
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      // op: cond
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(15);
      break;
    }
    case Oi::AddiuRxRyOffMemX16: {
      // op: imm15
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(2032)) << 16;
      Value |= (op & UINT64_C(30720)) << 5;
      Value |= op & UINT64_C(15);
      // op: rx
      op = getMemEncoding(MI, 1);
      Value |= (op & UINT64_C(7)) << 8;
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 5;
      break;
    }
    case Oi::BimmX16: {
      // op: imm16
      op = getBranchTargetOpValue(MI, 0);
      Value |= (op & UINT64_C(2016)) << 16;
      Value |= (op & UINT64_C(63488)) << 5;
      Value |= op & UINT64_C(31);
      break;
    }
    case Oi::AddiuSpImmX16:
    case Oi::BteqzT8CmpX16:
    case Oi::BteqzT8CmpiX16:
    case Oi::BteqzT8SltX16:
    case Oi::BteqzT8SltiX16:
    case Oi::BteqzT8SltiuX16:
    case Oi::BteqzT8SltuX16:
    case Oi::BteqzX16:
    case Oi::BtnezT8CmpX16:
    case Oi::BtnezT8CmpiX16:
    case Oi::BtnezT8SltX16:
    case Oi::BtnezT8SltiX16:
    case Oi::BtnezT8SltiuX16:
    case Oi::BtnezT8SltuX16:
    case Oi::BtnezX16: {
      // op: imm16
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(2016)) << 16;
      Value |= (op & UINT64_C(63488)) << 5;
      Value |= op & UINT64_C(31);
      break;
    }
    case Oi::AddiuRxImmX16:
    case Oi::AddiuRxPcImmX16:
    case Oi::AddiuRxRxImmX16:
    case Oi::BeqzRxImmX16:
    case Oi::BnezRxImmX16:
    case Oi::LiRxImmX16:
    case Oi::LwRxSpImmX16:
    case Oi::SwRxSpImmX16: {
      // op: imm16
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(2016)) << 16;
      Value |= (op & UINT64_C(63488)) << 5;
      Value |= op & UINT64_C(31);
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 8;
      break;
    }
    case Oi::SltiCCRxImmX16:
    case Oi::SltiuCCRxImmX16: {
      // op: imm16
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(2016)) << 16;
      Value |= (op & UINT64_C(63488)) << 5;
      Value |= op & UINT64_C(31);
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(7)) << 8;
      break;
    }
    case Oi::LbRxRyOffMemX16:
    case Oi::LbuRxRyOffMemX16:
    case Oi::LhRxRyOffMemX16:
    case Oi::LhuRxRyOffMemX16:
    case Oi::LwRxRyOffMemX16:
    case Oi::SbRxRyOffMemX16:
    case Oi::ShRxRyOffMemX16:
    case Oi::SwRxRyOffMemX16: {
      // op: imm16
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(2016)) << 16;
      Value |= (op & UINT64_C(63488)) << 5;
      Value |= op & UINT64_C(31);
      // op: rx
      op = getMemEncoding(MI, 1);
      Value |= (op & UINT64_C(7)) << 8;
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 5;
      break;
    }
    case Oi::B:
    case Oi::BAL_BR:
    case Oi::BC1F:
    case Oi::BC1T:
    case Oi::BPOSGE32: {
      // op: offset
      op = getBranchTargetOpValue(MI, 0);
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::Move32R16: {
      // op: r32
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 5;
      Value |= op & UINT64_C(24);
      // op: rz
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(7);
      break;
    }
    case Oi::MFHI:
    case Oi::MFHI64:
    case Oi::MFLO:
    case Oi::MFLO64: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::LBUX:
    case Oi::LHX:
    case Oi::LWX: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: base
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: index
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::REPL_PH:
    case Oi::REPL_QB: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(1023)) << 16;
      break;
    }
    case Oi::RDDSP: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: mask
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(1023)) << 16;
      break;
    }
    case Oi::MOVF_I:
    case Oi::MOVF_I64:
    case Oi::MOVT_I:
    case Oi::MOVT_I64:
    case Oi::RADDU_W_QB: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::ADD:
    case Oi::ADDQH_PH:
    case Oi::ADDQH_R_PH:
    case Oi::ADDQH_R_W:
    case Oi::ADDQH_W:
    case Oi::ADDQ_PH:
    case Oi::ADDQ_S_PH:
    case Oi::ADDQ_S_W:
    case Oi::ADDSC:
    case Oi::ADDUH_QB:
    case Oi::ADDUH_R_QB:
    case Oi::ADDU_PH:
    case Oi::ADDU_QB:
    case Oi::ADDU_S_PH:
    case Oi::ADDU_S_QB:
    case Oi::ADDWC:
    case Oi::ADDu:
    case Oi::AND:
    case Oi::AND64:
    case Oi::DADD:
    case Oi::DADDu:
    case Oi::DSUBu:
    case Oi::MODSUB:
    case Oi::MOVN_I64_I:
    case Oi::MOVN_I64_I64:
    case Oi::MOVN_I_I:
    case Oi::MOVN_I_I64:
    case Oi::MOVZ_I64_I:
    case Oi::MOVZ_I64_I64:
    case Oi::MOVZ_I_I:
    case Oi::MOVZ_I_I64:
    case Oi::MUL:
    case Oi::MULEQ_S_W_PHL:
    case Oi::MULEQ_S_W_PHR:
    case Oi::MULEU_S_PH_QBL:
    case Oi::MULEU_S_PH_QBR:
    case Oi::MULQ_RS_PH:
    case Oi::MULQ_RS_W:
    case Oi::MULQ_S_PH:
    case Oi::MULQ_S_W:
    case Oi::MUL_PH:
    case Oi::MUL_S_PH:
    case Oi::NOR:
    case Oi::NOR64:
    case Oi::OR:
    case Oi::OR64:
    case Oi::SLT:
    case Oi::SLT64:
    case Oi::SLTu:
    case Oi::SLTu64:
    case Oi::SUB:
    case Oi::SUBQH_PH:
    case Oi::SUBQH_R_PH:
    case Oi::SUBQH_R_W:
    case Oi::SUBQH_W:
    case Oi::SUBQ_PH:
    case Oi::SUBQ_S_PH:
    case Oi::SUBQ_S_W:
    case Oi::SUBUH_QB:
    case Oi::SUBUH_R_QB:
    case Oi::SUBU_PH:
    case Oi::SUBU_QB:
    case Oi::SUBU_S_PH:
    case Oi::SUBU_S_QB:
    case Oi::SUBu:
    case Oi::XOR:
    case Oi::XOR64: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::ABSQ_S_PH:
    case Oi::ABSQ_S_QB:
    case Oi::ABSQ_S_W:
    case Oi::BITREV:
    case Oi::DSBH:
    case Oi::DSHD:
    case Oi::DSLL64_32:
    case Oi::PRECEQU_PH_QBL:
    case Oi::PRECEQU_PH_QBLA:
    case Oi::PRECEQU_PH_QBR:
    case Oi::PRECEQU_PH_QBRA:
    case Oi::PRECEQ_W_PHL:
    case Oi::PRECEQ_W_PHR:
    case Oi::PRECEU_PH_QBL:
    case Oi::PRECEU_PH_QBLA:
    case Oi::PRECEU_PH_QBR:
    case Oi::PRECEU_PH_QBRA:
    case Oi::REPLV_PH:
    case Oi::REPLV_QB:
    case Oi::SEB:
    case Oi::SEB64:
    case Oi::SEH:
    case Oi::SEH64:
    case Oi::SLL64_32:
    case Oi::SLL64_64:
    case Oi::WSBH: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::SHLLV_PH:
    case Oi::SHLLV_QB:
    case Oi::SHLLV_S_PH:
    case Oi::SHLLV_S_W:
    case Oi::SHLL_PH:
    case Oi::SHLL_QB:
    case Oi::SHLL_S_PH:
    case Oi::SHLL_S_W:
    case Oi::SHRAV_PH:
    case Oi::SHRAV_QB:
    case Oi::SHRAV_R_PH:
    case Oi::SHRAV_R_QB:
    case Oi::SHRAV_R_W:
    case Oi::SHRA_PH:
    case Oi::SHRA_QB:
    case Oi::SHRA_R_PH:
    case Oi::SHRA_R_QB:
    case Oi::SHRA_R_W:
    case Oi::SHRLV_PH:
    case Oi::SHRLV_QB:
    case Oi::SHRL_PH:
    case Oi::SHRL_QB: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rs_sa
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::DROTR:
    case Oi::DSLL:
    case Oi::DSLL32:
    case Oi::DSRA:
    case Oi::DSRA32:
    case Oi::DSRL:
    case Oi::DSRL32:
    case Oi::ROTR:
    case Oi::SLL:
    case Oi::SRA:
    case Oi::SRL: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      // op: shamt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 6;
      break;
    }
    case Oi::DROTRV:
    case Oi::DSLLV:
    case Oi::DSRAV:
    case Oi::DSRLV:
    case Oi::ROTRV:
    case Oi::SLLV:
    case Oi::SRAV:
    case Oi::SRLV: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::CLO:
    case Oi::CLZ:
    case Oi::DCLO:
    case Oi::DCLZ: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      Value |= (op & UINT64_C(31)) << 11;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::JALR:
    case Oi::JALR64:
    case Oi::JR:
    case Oi::JR64:
    case Oi::MTHI:
    case Oi::MTHI64:
    case Oi::MTLO:
    case Oi::MTLO64:
    case Oi::RET:
    case Oi::TAILCALL64_R:
    case Oi::TAILCALL_R: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::WRDSP: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 21;
      // op: mask
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(1023)) << 11;
      break;
    }
    case Oi::BGEZ:
    case Oi::BGEZ64:
    case Oi::BGEZAL:
    case Oi::BGTZ:
    case Oi::BGTZ64:
    case Oi::BLEZ:
    case Oi::BLEZ64:
    case Oi::BLTZ:
    case Oi::BLTZ64:
    case Oi::BLTZAL: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 21;
      // op: offset
      op = getBranchTargetOpValue(MI, 1);
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::CMPU_EQ_QB:
    case Oi::CMPU_LE_QB:
    case Oi::CMPU_LT_QB:
    case Oi::CMP_EQ_PH:
    case Oi::CMP_LE_PH:
    case Oi::CMP_LT_PH:
    case Oi::DMULT:
    case Oi::DMULTu:
    case Oi::DSDIV:
    case Oi::DUDIV:
    case Oi::MADD:
    case Oi::MADDU:
    case Oi::MSUB:
    case Oi::MSUBU:
    case Oi::MULT:
    case Oi::MULTu:
    case Oi::SDIV:
    case Oi::UDIV: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 21;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      break;
    }
    case Oi::BEQ:
    case Oi::BEQ64:
    case Oi::BNE:
    case Oi::BNE64: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 21;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      // op: offset
      op = getBranchTargetOpValue(MI, 2);
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::ADDi:
    case Oi::ADDiu:
    case Oi::ANDi:
    case Oi::DADDi:
    case Oi::DADDiu:
    case Oi::DANDi:
    case Oi::ORi:
    case Oi::ORi64:
    case Oi::XORi:
    case Oi::XORi64: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: imm16
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::PRECR_SRA_PH_W:
    case Oi::PRECR_SRA_R_PH_W: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: sa
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::CMPGDU_EQ_QB:
    case Oi::CMPGDU_LE_QB:
    case Oi::CMPGDU_LT_QB:
    case Oi::CMPGU_EQ_QB:
    case Oi::CMPGU_LE_QB:
    case Oi::CMPGU_LT_QB:
    case Oi::PACKRL_PH:
    case Oi::PICK_PH:
    case Oi::PICK_QB:
    case Oi::PRECRQU_S_QB_PH:
    case Oi::PRECRQ_PH_W:
    case Oi::PRECRQ_QB_PH:
    case Oi::PRECRQ_RS_PH_W:
    case Oi::PRECR_QB_PH: {
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::EXTP:
    case Oi::EXTPDP:
    case Oi::EXTPDPV:
    case Oi::EXTPV:
    case Oi::EXTRV_RS_W:
    case Oi::EXTRV_R_W:
    case Oi::EXTRV_S_H:
    case Oi::EXTRV_W:
    case Oi::EXTR_RS_W:
    case Oi::EXTR_R_W:
    case Oi::EXTR_S_H:
    case Oi::EXTR_W: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: ac
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(3)) << 11;
      // op: shift_rs
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::LB:
    case Oi::LB64:
    case Oi::LB64_P8:
    case Oi::LB_P8:
    case Oi::LBu:
    case Oi::LBu64:
    case Oi::LBu64_P8:
    case Oi::LBu_P8:
    case Oi::LD:
    case Oi::LDC1:
    case Oi::LDC164:
    case Oi::LDC164_P8:
    case Oi::LDL:
    case Oi::LDL_P8:
    case Oi::LDR:
    case Oi::LDR_P8:
    case Oi::LD_P8:
    case Oi::LEA_ADDiu:
    case Oi::LEA_ADDiu64:
    case Oi::LH:
    case Oi::LH64:
    case Oi::LH64_P8:
    case Oi::LH_P8:
    case Oi::LHu:
    case Oi::LHu64:
    case Oi::LHu64_P8:
    case Oi::LHu_P8:
    case Oi::LL:
    case Oi::LLD:
    case Oi::LLD_P8:
    case Oi::LL_P8:
    case Oi::LW:
    case Oi::LW64:
    case Oi::LW64_P8:
    case Oi::LWC1:
    case Oi::LWC1_P8:
    case Oi::LWL:
    case Oi::LWL64:
    case Oi::LWL64_P8:
    case Oi::LWL_P8:
    case Oi::LWR:
    case Oi::LWR64:
    case Oi::LWR64_P8:
    case Oi::LWR_P8:
    case Oi::LW_P8:
    case Oi::LWu64:
    case Oi::LWu64_P8:
    case Oi::SB:
    case Oi::SB64:
    case Oi::SB64_P8:
    case Oi::SB_P8:
    case Oi::SD:
    case Oi::SDC1:
    case Oi::SDC164:
    case Oi::SDC164_P8:
    case Oi::SDL:
    case Oi::SDL_P8:
    case Oi::SDR:
    case Oi::SDR_P8:
    case Oi::SD_P8:
    case Oi::SH:
    case Oi::SH64:
    case Oi::SH64_P8:
    case Oi::SH_P8:
    case Oi::SW:
    case Oi::SW64:
    case Oi::SW64_P8:
    case Oi::SWC1:
    case Oi::SWC1_P8:
    case Oi::SWL:
    case Oi::SWL64:
    case Oi::SWL64_P8:
    case Oi::SWL_P8:
    case Oi::SWR:
    case Oi::SWR64:
    case Oi::SWR64_P8:
    case Oi::SWR_P8:
    case Oi::SW_P8: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: addr
      op = getMemEncoding(MI, 1);
      Value |= (op & UINT64_C(2031616)) << 5;
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::CFC1:
    case Oi::DMFC1:
    case Oi::MFC1: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::LUi:
    case Oi::LUi64: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: imm16
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::RDHWR:
    case Oi::RDHWR64: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::DMFC0_3OP64:
    case Oi::DMFC2_3OP64:
    case Oi::MFC0_3OP:
    case Oi::MFC2_3OP: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 11;
      // op: sel
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(7);
      break;
    }
    case Oi::SLTi:
    case Oi::SLTi64:
    case Oi::SLTiu:
    case Oi::SLTiu64: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: imm16
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::DEXT:
    case Oi::DEXTM:
    case Oi::DEXTU:
    case Oi::EXT: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: pos
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 6;
      // op: size
      op = getSizeExtEncoding(MI, 3);
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::DINS:
    case Oi::DINSM:
    case Oi::DINSU:
    case Oi::INS: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: pos
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 6;
      // op: size
      op = getSizeInsEncoding(MI, 3);
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::APPEND:
    case Oi::BALIGN:
    case Oi::PREPEND: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 21;
      // op: sa
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::INSV: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 21;
      break;
    }
    case Oi::SC:
    case Oi::SCD:
    case Oi::SCD_P8:
    case Oi::SC_P8: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      // op: addr
      op = getMemEncoding(MI, 2);
      Value |= (op & UINT64_C(2031616)) << 5;
      Value |= op & UINT64_C(65535);
      break;
    }
    case Oi::CTC1:
    case Oi::DMTC1:
    case Oi::MTC1: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 16;
      // op: fs
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      break;
    }
    case Oi::DMTC0_3OP64:
    case Oi::DMTC2_3OP64:
    case Oi::MTC0_3OP:
    case Oi::MTC2_3OP: {
      // op: rt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 16;
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 11;
      // op: sel
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(7);
      break;
    }
    case Oi::JrcRx16:
    case Oi::JumpLinkReg16: {
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 8;
      break;
    }
    case Oi::Mfhi16:
    case Oi::Mflo16: {
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 8;
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 5;
      break;
    }
    case Oi::DivRxRy16:
    case Oi::DivuRxRy16:
    case Oi::NegRxRy16:
    case Oi::NotRxRy16:
    case Oi::SltRxRy16: {
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 8;
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(7)) << 5;
      break;
    }
    case Oi::AndRxRxRy16:
    case Oi::OrRxRxRy16:
    case Oi::SllvRxRy16:
    case Oi::SltCCRxRy16:
    case Oi::SltuCCRxRy16:
    case Oi::SltuRxRyRz16:
    case Oi::SravRxRy16:
    case Oi::SrlvRxRy16:
    case Oi::XorRxRxRy16: {
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(7)) << 8;
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(7)) << 5;
      break;
    }
    case Oi::AdduRxRyRz16:
    case Oi::SubuRxRyRz16: {
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(7)) << 8;
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(7)) << 5;
      // op: rz
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 2;
      break;
    }
    case Oi::MoveR3216: {
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(15)) << 4;
      // op: r32
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(15);
      break;
    }
    case Oi::SllX16:
    case Oi::SraX16:
    case Oi::SrlX16: {
      // op: sa6
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 22;
      Value |= (op & UINT64_C(32)) << 16;
      // op: rx
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(7)) << 8;
      // op: ry
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(7)) << 5;
      break;
    }
    case Oi::SYNC: {
      // op: stype
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 6;
      break;
    }
    case Oi::J:
    case Oi::JAL:
    case Oi::TAILCALL: {
      // op: target
      op = getJumpTargetOpValue(MI, 0);
      Value |= op & UINT64_C(67108863);
      break;
    }
  default:
    std::string msg;
    raw_string_ostream Msg(msg);
    Msg << "Not supported instr: " << MI;
    report_fatal_error(Msg.str());
  }
  return Value;
}

