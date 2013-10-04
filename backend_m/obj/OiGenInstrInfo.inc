/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Instruction Enum Values                                              *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_INSTRINFO_ENUM
#undef GET_INSTRINFO_ENUM
namespace llvm {

namespace Oi {
  enum {
    PHI	= 0,
    INLINEASM	= 1,
    PROLOG_LABEL	= 2,
    EH_LABEL	= 3,
    GC_LABEL	= 4,
    KILL	= 5,
    EXTRACT_SUBREG	= 6,
    INSERT_SUBREG	= 7,
    IMPLICIT_DEF	= 8,
    SUBREG_TO_REG	= 9,
    COPY_TO_REGCLASS	= 10,
    DBG_VALUE	= 11,
    REG_SEQUENCE	= 12,
    COPY	= 13,
    BUNDLE	= 14,
    LIFETIME_START	= 15,
    LIFETIME_END	= 16,
    ABSQ_S_PH	= 17,
    ABSQ_S_QB	= 18,
    ABSQ_S_W	= 19,
    ADD	= 20,
    ADDQH_PH	= 21,
    ADDQH_R_PH	= 22,
    ADDQH_R_W	= 23,
    ADDQH_W	= 24,
    ADDQ_PH	= 25,
    ADDQ_S_PH	= 26,
    ADDQ_S_W	= 27,
    ADDSC	= 28,
    ADDUH_QB	= 29,
    ADDUH_R_QB	= 30,
    ADDU_PH	= 31,
    ADDU_QB	= 32,
    ADDU_S_PH	= 33,
    ADDU_S_QB	= 34,
    ADDWC	= 35,
    ADDi	= 36,
    ADDiu	= 37,
    ADDu	= 38,
    ADJCALLSTACKDOWN	= 39,
    ADJCALLSTACKUP	= 40,
    AND	= 41,
    AND64	= 42,
    ANDi	= 43,
    APPEND	= 44,
    ATOMIC_CMP_SWAP_I16	= 45,
    ATOMIC_CMP_SWAP_I16_P8	= 46,
    ATOMIC_CMP_SWAP_I32	= 47,
    ATOMIC_CMP_SWAP_I32_P8	= 48,
    ATOMIC_CMP_SWAP_I64	= 49,
    ATOMIC_CMP_SWAP_I64_P8	= 50,
    ATOMIC_CMP_SWAP_I8	= 51,
    ATOMIC_CMP_SWAP_I8_P8	= 52,
    ATOMIC_LOAD_ADD_I16	= 53,
    ATOMIC_LOAD_ADD_I16_P8	= 54,
    ATOMIC_LOAD_ADD_I32	= 55,
    ATOMIC_LOAD_ADD_I32_P8	= 56,
    ATOMIC_LOAD_ADD_I64	= 57,
    ATOMIC_LOAD_ADD_I64_P8	= 58,
    ATOMIC_LOAD_ADD_I8	= 59,
    ATOMIC_LOAD_ADD_I8_P8	= 60,
    ATOMIC_LOAD_AND_I16	= 61,
    ATOMIC_LOAD_AND_I16_P8	= 62,
    ATOMIC_LOAD_AND_I32	= 63,
    ATOMIC_LOAD_AND_I32_P8	= 64,
    ATOMIC_LOAD_AND_I64	= 65,
    ATOMIC_LOAD_AND_I64_P8	= 66,
    ATOMIC_LOAD_AND_I8	= 67,
    ATOMIC_LOAD_AND_I8_P8	= 68,
    ATOMIC_LOAD_NAND_I16	= 69,
    ATOMIC_LOAD_NAND_I16_P8	= 70,
    ATOMIC_LOAD_NAND_I32	= 71,
    ATOMIC_LOAD_NAND_I32_P8	= 72,
    ATOMIC_LOAD_NAND_I64	= 73,
    ATOMIC_LOAD_NAND_I64_P8	= 74,
    ATOMIC_LOAD_NAND_I8	= 75,
    ATOMIC_LOAD_NAND_I8_P8	= 76,
    ATOMIC_LOAD_OR_I16	= 77,
    ATOMIC_LOAD_OR_I16_P8	= 78,
    ATOMIC_LOAD_OR_I32	= 79,
    ATOMIC_LOAD_OR_I32_P8	= 80,
    ATOMIC_LOAD_OR_I64	= 81,
    ATOMIC_LOAD_OR_I64_P8	= 82,
    ATOMIC_LOAD_OR_I8	= 83,
    ATOMIC_LOAD_OR_I8_P8	= 84,
    ATOMIC_LOAD_SUB_I16	= 85,
    ATOMIC_LOAD_SUB_I16_P8	= 86,
    ATOMIC_LOAD_SUB_I32	= 87,
    ATOMIC_LOAD_SUB_I32_P8	= 88,
    ATOMIC_LOAD_SUB_I64	= 89,
    ATOMIC_LOAD_SUB_I64_P8	= 90,
    ATOMIC_LOAD_SUB_I8	= 91,
    ATOMIC_LOAD_SUB_I8_P8	= 92,
    ATOMIC_LOAD_XOR_I16	= 93,
    ATOMIC_LOAD_XOR_I16_P8	= 94,
    ATOMIC_LOAD_XOR_I32	= 95,
    ATOMIC_LOAD_XOR_I32_P8	= 96,
    ATOMIC_LOAD_XOR_I64	= 97,
    ATOMIC_LOAD_XOR_I64_P8	= 98,
    ATOMIC_LOAD_XOR_I8	= 99,
    ATOMIC_LOAD_XOR_I8_P8	= 100,
    ATOMIC_SWAP_I16	= 101,
    ATOMIC_SWAP_I16_P8	= 102,
    ATOMIC_SWAP_I32	= 103,
    ATOMIC_SWAP_I32_P8	= 104,
    ATOMIC_SWAP_I64	= 105,
    ATOMIC_SWAP_I64_P8	= 106,
    ATOMIC_SWAP_I8	= 107,
    ATOMIC_SWAP_I8_P8	= 108,
    AddiuRxImmX16	= 109,
    AddiuRxPcImmX16	= 110,
    AddiuRxRxImmX16	= 111,
    AddiuRxRyOffMemX16	= 112,
    AddiuSpImmX16	= 113,
    AdduRxRyRz16	= 114,
    AndRxRxRy16	= 115,
    B	= 116,
    BALIGN	= 117,
    BAL_BR	= 118,
    BC1F	= 119,
    BC1T	= 120,
    BEQ	= 121,
    BEQ64	= 122,
    BGEZ	= 123,
    BGEZ64	= 124,
    BGEZAL	= 125,
    BGTZ	= 126,
    BGTZ64	= 127,
    BITREV	= 128,
    BLEZ	= 129,
    BLEZ64	= 130,
    BLTZ	= 131,
    BLTZ64	= 132,
    BLTZAL	= 133,
    BNE	= 134,
    BNE64	= 135,
    BPOSGE32	= 136,
    BPOSGE32_PSEUDO	= 137,
    BeqzRxImmX16	= 138,
    BimmX16	= 139,
    BnezRxImmX16	= 140,
    BteqzT8CmpX16	= 141,
    BteqzT8CmpiX16	= 142,
    BteqzT8SltX16	= 143,
    BteqzT8SltiX16	= 144,
    BteqzT8SltiuX16	= 145,
    BteqzT8SltuX16	= 146,
    BteqzX16	= 147,
    BtnezT8CmpX16	= 148,
    BtnezT8CmpiX16	= 149,
    BtnezT8SltX16	= 150,
    BtnezT8SltiX16	= 151,
    BtnezT8SltiuX16	= 152,
    BtnezT8SltuX16	= 153,
    BtnezX16	= 154,
    BuildPairF64	= 155,
    CEIL_L_D64	= 156,
    CEIL_L_S	= 157,
    CEIL_W_D32	= 158,
    CEIL_W_D64	= 159,
    CEIL_W_S	= 160,
    CFC1	= 161,
    CLO	= 162,
    CLZ	= 163,
    CMPGDU_EQ_QB	= 164,
    CMPGDU_LE_QB	= 165,
    CMPGDU_LT_QB	= 166,
    CMPGU_EQ_QB	= 167,
    CMPGU_LE_QB	= 168,
    CMPGU_LT_QB	= 169,
    CMPU_EQ_QB	= 170,
    CMPU_LE_QB	= 171,
    CMPU_LT_QB	= 172,
    CMP_EQ_PH	= 173,
    CMP_LE_PH	= 174,
    CMP_LT_PH	= 175,
    CTC1	= 176,
    CVT_D32_S	= 177,
    CVT_D32_W	= 178,
    CVT_D64_L	= 179,
    CVT_D64_S	= 180,
    CVT_D64_W	= 181,
    CVT_L_D64	= 182,
    CVT_L_S	= 183,
    CVT_S_D32	= 184,
    CVT_S_D64	= 185,
    CVT_S_L	= 186,
    CVT_S_W	= 187,
    CVT_W_D32	= 188,
    CVT_W_D64	= 189,
    CVT_W_S	= 190,
    Constant32	= 191,
    DADD	= 192,
    DADDi	= 193,
    DADDiu	= 194,
    DADDu	= 195,
    DANDi	= 196,
    DCLO	= 197,
    DCLZ	= 198,
    DEXT	= 199,
    DEXTM	= 200,
    DEXTU	= 201,
    DINS	= 202,
    DINSM	= 203,
    DINSU	= 204,
    DMFC0_3OP64	= 205,
    DMFC1	= 206,
    DMFC2_3OP64	= 207,
    DMTC0_3OP64	= 208,
    DMTC1	= 209,
    DMTC2_3OP64	= 210,
    DMULT	= 211,
    DMULTu	= 212,
    DPAQX_SA_W_PH	= 213,
    DPAQX_SA_W_PH_PSEUDO	= 214,
    DPAQX_S_W_PH	= 215,
    DPAQX_S_W_PH_PSEUDO	= 216,
    DPAQ_SA_L_W	= 217,
    DPAQ_SA_L_W_PSEUDO	= 218,
    DPAQ_S_W_PH	= 219,
    DPAQ_S_W_PH_PSEUDO	= 220,
    DPAU_H_QBL	= 221,
    DPAU_H_QBL_PSEUDO	= 222,
    DPAU_H_QBR	= 223,
    DPAU_H_QBR_PSEUDO	= 224,
    DPAX_W_PH	= 225,
    DPAX_W_PH_PSEUDO	= 226,
    DPA_W_PH	= 227,
    DPA_W_PH_PSEUDO	= 228,
    DPSQX_SA_W_PH	= 229,
    DPSQX_SA_W_PH_PSEUDO	= 230,
    DPSQX_S_W_PH	= 231,
    DPSQX_S_W_PH_PSEUDO	= 232,
    DPSQ_SA_L_W	= 233,
    DPSQ_SA_L_W_PSEUDO	= 234,
    DPSQ_S_W_PH	= 235,
    DPSQ_S_W_PH_PSEUDO	= 236,
    DPSU_H_QBL	= 237,
    DPSU_H_QBL_PSEUDO	= 238,
    DPSU_H_QBR	= 239,
    DPSU_H_QBR_PSEUDO	= 240,
    DPSX_W_PH	= 241,
    DPSX_W_PH_PSEUDO	= 242,
    DPS_W_PH	= 243,
    DPS_W_PH_PSEUDO	= 244,
    DROTR	= 245,
    DROTRV	= 246,
    DSBH	= 247,
    DSDIV	= 248,
    DSHD	= 249,
    DSLL	= 250,
    DSLL32	= 251,
    DSLL64_32	= 252,
    DSLLV	= 253,
    DSRA	= 254,
    DSRA32	= 255,
    DSRAV	= 256,
    DSRL	= 257,
    DSRL32	= 258,
    DSRLV	= 259,
    DSUBu	= 260,
    DUDIV	= 261,
    DivRxRy16	= 262,
    DivuRxRy16	= 263,
    EXT	= 264,
    EXTP	= 265,
    EXTPDP	= 266,
    EXTPDPV	= 267,
    EXTPV	= 268,
    EXTRV_RS_W	= 269,
    EXTRV_R_W	= 270,
    EXTRV_S_H	= 271,
    EXTRV_W	= 272,
    EXTR_RS_W	= 273,
    EXTR_R_W	= 274,
    EXTR_S_H	= 275,
    EXTR_W	= 276,
    ExtractElementF64	= 277,
    FABS_D32	= 278,
    FABS_D64	= 279,
    FABS_S	= 280,
    FADD_D32	= 281,
    FADD_D64	= 282,
    FADD_S	= 283,
    FCMP_D32	= 284,
    FCMP_D64	= 285,
    FCMP_S32	= 286,
    FDIV_D32	= 287,
    FDIV_D64	= 288,
    FDIV_S	= 289,
    FLOOR_L_D64	= 290,
    FLOOR_L_S	= 291,
    FLOOR_W_D32	= 292,
    FLOOR_W_D64	= 293,
    FLOOR_W_S	= 294,
    FMOV_D32	= 295,
    FMOV_D64	= 296,
    FMOV_S	= 297,
    FMUL_D32	= 298,
    FMUL_D64	= 299,
    FMUL_S	= 300,
    FNEG_D32	= 301,
    FNEG_D64	= 302,
    FNEG_S	= 303,
    FSQRT_D32	= 304,
    FSQRT_D64	= 305,
    FSQRT_S	= 306,
    FSUB_D32	= 307,
    FSUB_D64	= 308,
    FSUB_S	= 309,
    INS	= 310,
    INSV	= 311,
    J	= 312,
    JAL	= 313,
    JALR	= 314,
    JALR64	= 315,
    JR	= 316,
    JR64	= 317,
    JrRa16	= 318,
    JrcRa16	= 319,
    JrcRx16	= 320,
    JumpLinkReg16	= 321,
    LB	= 322,
    LB64	= 323,
    LB64_P8	= 324,
    LBUX	= 325,
    LB_P8	= 326,
    LBu	= 327,
    LBu64	= 328,
    LBu64_P8	= 329,
    LBu_P8	= 330,
    LD	= 331,
    LDC1	= 332,
    LDC164	= 333,
    LDC164_P8	= 334,
    LDL	= 335,
    LDL_P8	= 336,
    LDR	= 337,
    LDR_P8	= 338,
    LDXC1	= 339,
    LDXC164	= 340,
    LDXC164_P8	= 341,
    LD_P8	= 342,
    LEA_ADDiu	= 343,
    LEA_ADDiu64	= 344,
    LH	= 345,
    LH64	= 346,
    LH64_P8	= 347,
    LHX	= 348,
    LH_P8	= 349,
    LHu	= 350,
    LHu64	= 351,
    LHu64_P8	= 352,
    LHu_P8	= 353,
    LL	= 354,
    LLD	= 355,
    LLD_P8	= 356,
    LL_P8	= 357,
    LUXC1	= 358,
    LUXC164	= 359,
    LUi	= 360,
    LUi64	= 361,
    LW	= 362,
    LW64	= 363,
    LW64_P8	= 364,
    LWC1	= 365,
    LWC1_P8	= 366,
    LWL	= 367,
    LWL64	= 368,
    LWL64_P8	= 369,
    LWL_P8	= 370,
    LWR	= 371,
    LWR64	= 372,
    LWR64_P8	= 373,
    LWR_P8	= 374,
    LWX	= 375,
    LWXC1	= 376,
    LWXC1_P8	= 377,
    LW_P8	= 378,
    LWu64	= 379,
    LWu64_P8	= 380,
    LbRxRyOffMemX16	= 381,
    LbuRxRyOffMemX16	= 382,
    LhRxRyOffMemX16	= 383,
    LhuRxRyOffMemX16	= 384,
    LiRxImmX16	= 385,
    LoadAddr32Imm	= 386,
    LoadAddr32Reg	= 387,
    LoadImm32Reg	= 388,
    LwConstant32	= 389,
    LwRxRyOffMemX16	= 390,
    LwRxSpImmX16	= 391,
    MADD	= 392,
    MADDU	= 393,
    MADDU_DSP	= 394,
    MADDU_DSP_PSEUDO	= 395,
    MADD_D32	= 396,
    MADD_D64	= 397,
    MADD_DSP	= 398,
    MADD_DSP_PSEUDO	= 399,
    MADD_S	= 400,
    MAQ_SA_W_PHL	= 401,
    MAQ_SA_W_PHL_PSEUDO	= 402,
    MAQ_SA_W_PHR	= 403,
    MAQ_SA_W_PHR_PSEUDO	= 404,
    MAQ_S_W_PHL	= 405,
    MAQ_S_W_PHL_PSEUDO	= 406,
    MAQ_S_W_PHR	= 407,
    MAQ_S_W_PHR_PSEUDO	= 408,
    MFC0_3OP	= 409,
    MFC1	= 410,
    MFC2_3OP	= 411,
    MFHI	= 412,
    MFHI64	= 413,
    MFLO	= 414,
    MFLO64	= 415,
    MODSUB	= 416,
    MOVCCRToCCR	= 417,
    MOVF_D32	= 418,
    MOVF_D64	= 419,
    MOVF_I	= 420,
    MOVF_I64	= 421,
    MOVF_S	= 422,
    MOVN_I64_D64	= 423,
    MOVN_I64_I	= 424,
    MOVN_I64_I64	= 425,
    MOVN_I64_S	= 426,
    MOVN_I_D32	= 427,
    MOVN_I_D64	= 428,
    MOVN_I_I	= 429,
    MOVN_I_I64	= 430,
    MOVN_I_S	= 431,
    MOVT_D32	= 432,
    MOVT_D64	= 433,
    MOVT_I	= 434,
    MOVT_I64	= 435,
    MOVT_S	= 436,
    MOVZ_I64_D64	= 437,
    MOVZ_I64_I	= 438,
    MOVZ_I64_I64	= 439,
    MOVZ_I64_S	= 440,
    MOVZ_I_D32	= 441,
    MOVZ_I_D64	= 442,
    MOVZ_I_I	= 443,
    MOVZ_I_I64	= 444,
    MOVZ_I_S	= 445,
    MSUB	= 446,
    MSUBU	= 447,
    MSUBU_DSP	= 448,
    MSUBU_DSP_PSEUDO	= 449,
    MSUB_D32	= 450,
    MSUB_D64	= 451,
    MSUB_DSP	= 452,
    MSUB_DSP_PSEUDO	= 453,
    MSUB_S	= 454,
    MTC0_3OP	= 455,
    MTC1	= 456,
    MTC2_3OP	= 457,
    MTHI	= 458,
    MTHI64	= 459,
    MTHLIP	= 460,
    MTHLIP_PSEUDO	= 461,
    MTLO	= 462,
    MTLO64	= 463,
    MUL	= 464,
    MULEQ_S_W_PHL	= 465,
    MULEQ_S_W_PHR	= 466,
    MULEU_S_PH_QBL	= 467,
    MULEU_S_PH_QBR	= 468,
    MULQ_RS_PH	= 469,
    MULQ_RS_W	= 470,
    MULQ_S_PH	= 471,
    MULQ_S_W	= 472,
    MULSAQ_S_W_PH	= 473,
    MULSAQ_S_W_PH_PSEUDO	= 474,
    MULSA_W_PH	= 475,
    MULSA_W_PH_PSEUDO	= 476,
    MULT	= 477,
    MULTU_DSP	= 478,
    MULTU_DSP_PSEUDO	= 479,
    MULT_DSP	= 480,
    MULT_DSP_PSEUDO	= 481,
    MULTu	= 482,
    MUL_PH	= 483,
    MUL_S_PH	= 484,
    Mfhi16	= 485,
    Mflo16	= 486,
    Move32R16	= 487,
    MoveR3216	= 488,
    MultRxRy16	= 489,
    MultRxRyRz16	= 490,
    MultuRxRy16	= 491,
    MultuRxRyRz16	= 492,
    NMADD_D32	= 493,
    NMADD_D64	= 494,
    NMADD_S	= 495,
    NMSUB_D32	= 496,
    NMSUB_D64	= 497,
    NMSUB_S	= 498,
    NOP	= 499,
    NOR	= 500,
    NOR64	= 501,
    NegRxRy16	= 502,
    NotRxRy16	= 503,
    OR	= 504,
    OR64	= 505,
    ORi	= 506,
    ORi64	= 507,
    OrRxRxRy16	= 508,
    PACKRL_PH	= 509,
    PICK_PH	= 510,
    PICK_QB	= 511,
    PRECEQU_PH_QBL	= 512,
    PRECEQU_PH_QBLA	= 513,
    PRECEQU_PH_QBR	= 514,
    PRECEQU_PH_QBRA	= 515,
    PRECEQ_W_PHL	= 516,
    PRECEQ_W_PHR	= 517,
    PRECEU_PH_QBL	= 518,
    PRECEU_PH_QBLA	= 519,
    PRECEU_PH_QBR	= 520,
    PRECEU_PH_QBRA	= 521,
    PRECRQU_S_QB_PH	= 522,
    PRECRQ_PH_W	= 523,
    PRECRQ_QB_PH	= 524,
    PRECRQ_RS_PH_W	= 525,
    PRECR_QB_PH	= 526,
    PRECR_SRA_PH_W	= 527,
    PRECR_SRA_R_PH_W	= 528,
    PREPEND	= 529,
    RADDU_W_QB	= 530,
    RDDSP	= 531,
    RDHWR	= 532,
    RDHWR64	= 533,
    REPLV_PH	= 534,
    REPLV_QB	= 535,
    REPL_PH	= 536,
    REPL_QB	= 537,
    RET	= 538,
    ROTR	= 539,
    ROTRV	= 540,
    ROUND_L_D64	= 541,
    ROUND_L_S	= 542,
    ROUND_W_D32	= 543,
    ROUND_W_D64	= 544,
    ROUND_W_S	= 545,
    RestoreIncSpF16	= 546,
    RestoreRaF16	= 547,
    RetRA	= 548,
    RetRA16	= 549,
    SB	= 550,
    SB64	= 551,
    SB64_P8	= 552,
    SB_P8	= 553,
    SC	= 554,
    SCD	= 555,
    SCD_P8	= 556,
    SC_P8	= 557,
    SD	= 558,
    SDC1	= 559,
    SDC164	= 560,
    SDC164_P8	= 561,
    SDIV	= 562,
    SDL	= 563,
    SDL_P8	= 564,
    SDR	= 565,
    SDR_P8	= 566,
    SDXC1	= 567,
    SDXC164	= 568,
    SDXC164_P8	= 569,
    SD_P8	= 570,
    SEB	= 571,
    SEB64	= 572,
    SEH	= 573,
    SEH64	= 574,
    SH	= 575,
    SH64	= 576,
    SH64_P8	= 577,
    SHILO	= 578,
    SHILOV	= 579,
    SHILOV_PSEUDO	= 580,
    SHILO_PSEUDO	= 581,
    SHLLV_PH	= 582,
    SHLLV_QB	= 583,
    SHLLV_S_PH	= 584,
    SHLLV_S_W	= 585,
    SHLL_PH	= 586,
    SHLL_QB	= 587,
    SHLL_S_PH	= 588,
    SHLL_S_W	= 589,
    SHRAV_PH	= 590,
    SHRAV_QB	= 591,
    SHRAV_R_PH	= 592,
    SHRAV_R_QB	= 593,
    SHRAV_R_W	= 594,
    SHRA_PH	= 595,
    SHRA_QB	= 596,
    SHRA_R_PH	= 597,
    SHRA_R_QB	= 598,
    SHRA_R_W	= 599,
    SHRLV_PH	= 600,
    SHRLV_QB	= 601,
    SHRL_PH	= 602,
    SHRL_QB	= 603,
    SH_P8	= 604,
    SLL	= 605,
    SLL64_32	= 606,
    SLL64_64	= 607,
    SLLV	= 608,
    SLT	= 609,
    SLT64	= 610,
    SLTi	= 611,
    SLTi64	= 612,
    SLTiu	= 613,
    SLTiu64	= 614,
    SLTu	= 615,
    SLTu64	= 616,
    SRA	= 617,
    SRAV	= 618,
    SRL	= 619,
    SRLV	= 620,
    SUB	= 621,
    SUBQH_PH	= 622,
    SUBQH_R_PH	= 623,
    SUBQH_R_W	= 624,
    SUBQH_W	= 625,
    SUBQ_PH	= 626,
    SUBQ_S_PH	= 627,
    SUBQ_S_W	= 628,
    SUBUH_QB	= 629,
    SUBUH_R_QB	= 630,
    SUBU_PH	= 631,
    SUBU_QB	= 632,
    SUBU_S_PH	= 633,
    SUBU_S_QB	= 634,
    SUBu	= 635,
    SUXC1	= 636,
    SUXC164	= 637,
    SW	= 638,
    SW64	= 639,
    SW64_P8	= 640,
    SWC1	= 641,
    SWC1_P8	= 642,
    SWL	= 643,
    SWL64	= 644,
    SWL64_P8	= 645,
    SWL_P8	= 646,
    SWR	= 647,
    SWR64	= 648,
    SWR64_P8	= 649,
    SWR_P8	= 650,
    SWXC1	= 651,
    SWXC1_P8	= 652,
    SW_P8	= 653,
    SYNC	= 654,
    SaveDecSpF16	= 655,
    SaveRaF16	= 656,
    SbRxRyOffMemX16	= 657,
    SelBeqZ	= 658,
    SelBneZ	= 659,
    SelTBteqZCmp	= 660,
    SelTBteqZCmpi	= 661,
    SelTBteqZSlt	= 662,
    SelTBteqZSlti	= 663,
    SelTBteqZSltiu	= 664,
    SelTBteqZSltu	= 665,
    SelTBtneZCmp	= 666,
    SelTBtneZCmpi	= 667,
    SelTBtneZSlt	= 668,
    SelTBtneZSlti	= 669,
    SelTBtneZSltiu	= 670,
    SelTBtneZSltu	= 671,
    ShRxRyOffMemX16	= 672,
    SllX16	= 673,
    SllvRxRy16	= 674,
    SltCCRxRy16	= 675,
    SltRxRy16	= 676,
    SltiCCRxImmX16	= 677,
    SltiuCCRxImmX16	= 678,
    SltuCCRxRy16	= 679,
    SltuRxRyRz16	= 680,
    SraX16	= 681,
    SravRxRy16	= 682,
    SrlX16	= 683,
    SrlvRxRy16	= 684,
    SubuRxRyRz16	= 685,
    SwRxRyOffMemX16	= 686,
    SwRxSpImmX16	= 687,
    TAILCALL	= 688,
    TAILCALL64_R	= 689,
    TAILCALL_R	= 690,
    TRUNC_L_D64	= 691,
    TRUNC_L_S	= 692,
    TRUNC_W_D32	= 693,
    TRUNC_W_D64	= 694,
    TRUNC_W_S	= 695,
    UDIV	= 696,
    WRDSP	= 697,
    WSBH	= 698,
    XOR	= 699,
    XOR64	= 700,
    XORi	= 701,
    XORi64	= 702,
    XorRxRxRy16	= 703,
    INSTRUCTION_LIST_END = 704
  };
}
} // End llvm namespace 
#endif // GET_INSTRINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Instruction Descriptors                                              *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_INSTRINFO_MC_DESC
#undef GET_INSTRINFO_MC_DESC
namespace llvm {

static const uint16_t ImplicitList1[] = { Oi::DSPCtrl, 0 };
static const uint16_t ImplicitList2[] = { Oi::SP, 0 };
static const uint16_t ImplicitList3[] = { Oi::AT, 0 };
static const uint16_t ImplicitList4[] = { Oi::RA, 0 };
static const uint16_t ImplicitList5[] = { Oi::FCR31, 0 };
static const uint16_t ImplicitList6[] = { Oi::HI64, Oi::LO64, 0 };
static const uint16_t ImplicitList7[] = { Oi::AC0, 0 };
static const uint16_t ImplicitList8[] = { Oi::DSPCtrl, Oi::AC0, 0 };
static const uint16_t ImplicitList9[] = { Oi::HI, Oi::LO, 0 };
static const uint16_t ImplicitList10[] = { Oi::HI, 0 };
static const uint16_t ImplicitList11[] = { Oi::HI64, 0 };
static const uint16_t ImplicitList12[] = { Oi::LO, 0 };
static const uint16_t ImplicitList13[] = { Oi::LO64, 0 };
static const uint16_t ImplicitList14[] = { Oi::S0, Oi::S1, Oi::RA, Oi::SP, 0 };
static const uint16_t ImplicitList15[] = { Oi::RA, Oi::SP, Oi::S0, Oi::S1, 0 };

static const MCOperandInfo OperandInfo2[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo3[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo4[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo5[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo6[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo7[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo8[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo9[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo10[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo11[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo12[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo13[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo14[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo15[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo16[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo17[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo18[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo19[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo20[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo21[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo22[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo23[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo24[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo25[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo26[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo27[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo28[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo29[] = { { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo30[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo31[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo32[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo33[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo34[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo35[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo36[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo37[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo38[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_PCREL, 0 }, };
static const MCOperandInfo OperandInfo39[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo40[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo41[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo42[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo43[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo44[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo45[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CCRRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo46[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo47[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo48[] = { { Oi::CCRRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo49[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo50[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo51[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo52[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo53[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo54[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo55[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo56[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo57[] = { { Oi::ACRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo58[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo59[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo60[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo61[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo62[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::ACRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo63[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::ACRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo64[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo65[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo66[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo67[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo68[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo69[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo70[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo71[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo72[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo73[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo74[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo75[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo76[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo77[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo78[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo79[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo80[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo81[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo82[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo83[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo84[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo85[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo86[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo87[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo88[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo89[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo90[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo91[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo92[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo93[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo94[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo95[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo96[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo97[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo98[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo99[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPUSPRegRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo100[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo101[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo102[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo103[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo104[] = { { Oi::CCRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CCRRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo105[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo106[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo107[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo108[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo109[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo110[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo111[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo112[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo113[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo114[] = { { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::AFGR64RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo115[] = { { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR64RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo116[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo117[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo118[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo119[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo120[] = { { Oi::FGR32RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo121[] = { { Oi::ACRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo122[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo123[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo124[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo125[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo126[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo127[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::HWRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo128[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::HWRegs64RegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo129[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo130[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo131[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo132[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo133[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo134[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo135[] = { { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo136[] = { { Oi::ACRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo137[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo138[] = { { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::DSPRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo139[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo140[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo141[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo142[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo143[] = { { Oi::CPURegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Oi::CPU64RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo144[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo145[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo146[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo147[] = { { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Oi::CPU16RegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };

extern const MCInstrDesc OiInsts[] = {
  { 0,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0 },  // Inst #0 = PHI
  { 1,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic), 0x0ULL, NULL, NULL, 0 },  // Inst #1 = INLINEASM
  { 2,	1,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::NotDuplicable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2 },  // Inst #2 = PROLOG_LABEL
  { 3,	1,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::NotDuplicable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2 },  // Inst #3 = EH_LABEL
  { 4,	1,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::NotDuplicable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2 },  // Inst #4 = GC_LABEL
  { 5,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic), 0x0ULL, NULL, NULL, 0 },  // Inst #5 = KILL
  { 6,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo3 },  // Inst #6 = EXTRACT_SUBREG
  { 7,	4,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo4 },  // Inst #7 = INSERT_SUBREG
  { 8,	1,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo5 },  // Inst #8 = IMPLICIT_DEF
  { 9,	4,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo6 },  // Inst #9 = SUBREG_TO_REG
  { 10,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo3 },  // Inst #10 = COPY_TO_REGCLASS
  { 11,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic), 0x0ULL, NULL, NULL, 0 },  // Inst #11 = DBG_VALUE
  { 12,	1,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo5 },  // Inst #12 = REG_SEQUENCE
  { 13,	2,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo7 },  // Inst #13 = COPY
  { 14,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0 },  // Inst #14 = BUNDLE
  { 15,	1,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo2 },  // Inst #15 = LIFETIME_START
  { 16,	1,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo2 },  // Inst #16 = LIFETIME_END
  { 17,	2,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #17 = ABSQ_S_PH
  { 18,	2,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #18 = ABSQ_S_QB
  { 19,	2,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo9 },  // Inst #19 = ABSQ_S_W
  { 20,	3,	1,	0,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #20 = ADD
  { 21,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #21 = ADDQH_PH
  { 22,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #22 = ADDQH_R_PH
  { 23,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #23 = ADDQH_R_W
  { 24,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #24 = ADDQH_W
  { 25,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #25 = ADDQ_PH
  { 26,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #26 = ADDQ_S_PH
  { 27,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo12 },  // Inst #27 = ADDQ_S_W
  { 28,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo12 },  // Inst #28 = ADDSC
  { 29,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #29 = ADDUH_QB
  { 30,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #30 = ADDUH_R_QB
  { 31,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #31 = ADDU_PH
  { 32,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #32 = ADDU_QB
  { 33,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #33 = ADDU_S_PH
  { 34,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #34 = ADDU_S_QB
  { 35,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, ImplicitList1, ImplicitList1, OperandInfo12 },  // Inst #35 = ADDWC
  { 36,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo13 },  // Inst #36 = ADDi
  { 37,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x2ULL, NULL, NULL, OperandInfo13 },  // Inst #37 = ADDiu
  { 38,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #38 = ADDu
  { 39,	1,	0,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList2, ImplicitList2, OperandInfo2 },  // Inst #39 = ADJCALLSTACKDOWN
  { 40,	2,	0,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList2, ImplicitList2, OperandInfo14 },  // Inst #40 = ADJCALLSTACKUP
  { 41,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #41 = AND
  { 42,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo15 },  // Inst #42 = AND64
  { 43,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x2ULL, NULL, NULL, OperandInfo13 },  // Inst #43 = ANDi
  { 44,	4,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo16 },  // Inst #44 = APPEND
  { 45,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo17 },  // Inst #45 = ATOMIC_CMP_SWAP_I16
  { 46,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo18 },  // Inst #46 = ATOMIC_CMP_SWAP_I16_P8
  { 47,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo17 },  // Inst #47 = ATOMIC_CMP_SWAP_I32
  { 48,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo18 },  // Inst #48 = ATOMIC_CMP_SWAP_I32_P8
  { 49,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo19 },  // Inst #49 = ATOMIC_CMP_SWAP_I64
  { 50,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo20 },  // Inst #50 = ATOMIC_CMP_SWAP_I64_P8
  { 51,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo17 },  // Inst #51 = ATOMIC_CMP_SWAP_I8
  { 52,	4,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo18 },  // Inst #52 = ATOMIC_CMP_SWAP_I8_P8
  { 53,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #53 = ATOMIC_LOAD_ADD_I16
  { 54,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #54 = ATOMIC_LOAD_ADD_I16_P8
  { 55,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #55 = ATOMIC_LOAD_ADD_I32
  { 56,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #56 = ATOMIC_LOAD_ADD_I32_P8
  { 57,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo22 },  // Inst #57 = ATOMIC_LOAD_ADD_I64
  { 58,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo23 },  // Inst #58 = ATOMIC_LOAD_ADD_I64_P8
  { 59,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #59 = ATOMIC_LOAD_ADD_I8
  { 60,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #60 = ATOMIC_LOAD_ADD_I8_P8
  { 61,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #61 = ATOMIC_LOAD_AND_I16
  { 62,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #62 = ATOMIC_LOAD_AND_I16_P8
  { 63,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #63 = ATOMIC_LOAD_AND_I32
  { 64,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #64 = ATOMIC_LOAD_AND_I32_P8
  { 65,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo22 },  // Inst #65 = ATOMIC_LOAD_AND_I64
  { 66,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo23 },  // Inst #66 = ATOMIC_LOAD_AND_I64_P8
  { 67,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #67 = ATOMIC_LOAD_AND_I8
  { 68,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #68 = ATOMIC_LOAD_AND_I8_P8
  { 69,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #69 = ATOMIC_LOAD_NAND_I16
  { 70,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #70 = ATOMIC_LOAD_NAND_I16_P8
  { 71,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #71 = ATOMIC_LOAD_NAND_I32
  { 72,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #72 = ATOMIC_LOAD_NAND_I32_P8
  { 73,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo22 },  // Inst #73 = ATOMIC_LOAD_NAND_I64
  { 74,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo23 },  // Inst #74 = ATOMIC_LOAD_NAND_I64_P8
  { 75,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #75 = ATOMIC_LOAD_NAND_I8
  { 76,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #76 = ATOMIC_LOAD_NAND_I8_P8
  { 77,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #77 = ATOMIC_LOAD_OR_I16
  { 78,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #78 = ATOMIC_LOAD_OR_I16_P8
  { 79,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #79 = ATOMIC_LOAD_OR_I32
  { 80,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #80 = ATOMIC_LOAD_OR_I32_P8
  { 81,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo22 },  // Inst #81 = ATOMIC_LOAD_OR_I64
  { 82,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo23 },  // Inst #82 = ATOMIC_LOAD_OR_I64_P8
  { 83,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #83 = ATOMIC_LOAD_OR_I8
  { 84,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #84 = ATOMIC_LOAD_OR_I8_P8
  { 85,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #85 = ATOMIC_LOAD_SUB_I16
  { 86,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #86 = ATOMIC_LOAD_SUB_I16_P8
  { 87,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #87 = ATOMIC_LOAD_SUB_I32
  { 88,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #88 = ATOMIC_LOAD_SUB_I32_P8
  { 89,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo22 },  // Inst #89 = ATOMIC_LOAD_SUB_I64
  { 90,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo23 },  // Inst #90 = ATOMIC_LOAD_SUB_I64_P8
  { 91,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #91 = ATOMIC_LOAD_SUB_I8
  { 92,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #92 = ATOMIC_LOAD_SUB_I8_P8
  { 93,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #93 = ATOMIC_LOAD_XOR_I16
  { 94,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #94 = ATOMIC_LOAD_XOR_I16_P8
  { 95,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #95 = ATOMIC_LOAD_XOR_I32
  { 96,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #96 = ATOMIC_LOAD_XOR_I32_P8
  { 97,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo22 },  // Inst #97 = ATOMIC_LOAD_XOR_I64
  { 98,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo23 },  // Inst #98 = ATOMIC_LOAD_XOR_I64_P8
  { 99,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #99 = ATOMIC_LOAD_XOR_I8
  { 100,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #100 = ATOMIC_LOAD_XOR_I8_P8
  { 101,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #101 = ATOMIC_SWAP_I16
  { 102,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #102 = ATOMIC_SWAP_I16_P8
  { 103,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #103 = ATOMIC_SWAP_I32
  { 104,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #104 = ATOMIC_SWAP_I32_P8
  { 105,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo22 },  // Inst #105 = ATOMIC_SWAP_I64
  { 106,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo23 },  // Inst #106 = ATOMIC_SWAP_I64_P8
  { 107,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo12 },  // Inst #107 = ATOMIC_SWAP_I8
  { 108,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo21 },  // Inst #108 = ATOMIC_SWAP_I8_P8
  { 109,	2,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x10ULL, NULL, NULL, OperandInfo24 },  // Inst #109 = AddiuRxImmX16
  { 110,	2,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x10ULL, NULL, NULL, OperandInfo24 },  // Inst #110 = AddiuRxPcImmX16
  { 111,	3,	1,	1,	0,	0|(1<<MCID::Rematerializable), 0x10ULL, NULL, NULL, OperandInfo25 },  // Inst #111 = AddiuRxRxImmX16
  { 112,	3,	1,	1,	0,	0, 0x12ULL, NULL, NULL, OperandInfo26 },  // Inst #112 = AddiuRxRyOffMemX16
  { 113,	1,	0,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x14ULL, ImplicitList2, ImplicitList2, OperandInfo5 },  // Inst #113 = AddiuSpImmX16
  { 114,	3,	1,	1,	0,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x5ULL, NULL, NULL, OperandInfo27 },  // Inst #114 = AdduRxRyRz16
  { 115,	3,	1,	1,	0,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x3ULL, NULL, NULL, OperandInfo28 },  // Inst #115 = AndRxRxRy16
  { 116,	1,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo29 },  // Inst #116 = B
  { 117,	4,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo16 },  // Inst #117 = BALIGN
  { 118,	1,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, ImplicitList4, OperandInfo29 },  // Inst #118 = BAL_BR
  { 119,	1,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x5ULL, ImplicitList5, ImplicitList3, OperandInfo29 },  // Inst #119 = BC1F
  { 120,	1,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x5ULL, ImplicitList5, ImplicitList3, OperandInfo29 },  // Inst #120 = BC1T
  { 121,	3,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo30 },  // Inst #121 = BEQ
  { 122,	3,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo31 },  // Inst #122 = BEQ64
  { 123,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo32 },  // Inst #123 = BGEZ
  { 124,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo33 },  // Inst #124 = BGEZ64
  { 125,	2,	0,	2,	4,	0|(1<<MCID::DelaySlot)|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, ImplicitList4, OperandInfo34 },  // Inst #125 = BGEZAL
  { 126,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo32 },  // Inst #126 = BGTZ
  { 127,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo33 },  // Inst #127 = BGTZ64
  { 128,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo9 },  // Inst #128 = BITREV
  { 129,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo32 },  // Inst #129 = BLEZ
  { 130,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo33 },  // Inst #130 = BLEZ64
  { 131,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo32 },  // Inst #131 = BLTZ
  { 132,	2,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo33 },  // Inst #132 = BLTZ64
  { 133,	2,	0,	2,	4,	0|(1<<MCID::DelaySlot)|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, ImplicitList4, OperandInfo34 },  // Inst #133 = BLTZAL
  { 134,	3,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo30 },  // Inst #134 = BNE
  { 135,	3,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x2ULL, NULL, ImplicitList3, OperandInfo31 },  // Inst #135 = BNE64
  { 136,	1,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, ImplicitList1, NULL, OperandInfo29 },  // Inst #136 = BPOSGE32
  { 137,	1,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, NULL, OperandInfo35 },  // Inst #137 = BPOSGE32_PSEUDO
  { 138,	2,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x10ULL, NULL, NULL, OperandInfo36 },  // Inst #138 = BeqzRxImmX16
  { 139,	1,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0xeULL, NULL, NULL, OperandInfo29 },  // Inst #139 = BimmX16
  { 140,	2,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x10ULL, NULL, NULL, OperandInfo36 },  // Inst #140 = BnezRxImmX16
  { 141,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo37 },  // Inst #141 = BteqzT8CmpX16
  { 142,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo38 },  // Inst #142 = BteqzT8CmpiX16
  { 143,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo37 },  // Inst #143 = BteqzT8SltX16
  { 144,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo38 },  // Inst #144 = BteqzT8SltiX16
  { 145,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x14ULL, NULL, NULL, OperandInfo38 },  // Inst #145 = BteqzT8SltiuX16
  { 146,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x14ULL, NULL, NULL, OperandInfo37 },  // Inst #146 = BteqzT8SltuX16
  { 147,	1,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x14ULL, NULL, NULL, OperandInfo5 },  // Inst #147 = BteqzX16
  { 148,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo37 },  // Inst #148 = BtnezT8CmpX16
  { 149,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo38 },  // Inst #149 = BtnezT8CmpiX16
  { 150,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo37 },  // Inst #150 = BtnezT8SltX16
  { 151,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x14ULL, NULL, NULL, OperandInfo38 },  // Inst #151 = BtnezT8SltiX16
  { 152,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x14ULL, NULL, NULL, OperandInfo38 },  // Inst #152 = BtnezT8SltiuX16
  { 153,	3,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x14ULL, NULL, NULL, OperandInfo37 },  // Inst #153 = BtnezT8SltuX16
  { 154,	1,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x14ULL, NULL, NULL, OperandInfo5 },  // Inst #154 = BtnezX16
  { 155,	3,	1,	17,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo39 },  // Inst #155 = BuildPairF64
  { 156,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #156 = CEIL_L_D64
  { 157,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo41 },  // Inst #157 = CEIL_L_S
  { 158,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo42 },  // Inst #158 = CEIL_W_D32
  { 159,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo43 },  // Inst #159 = CEIL_W_D64
  { 160,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #160 = CEIL_W_S
  { 161,	2,	1,	8,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo45 },  // Inst #161 = CFC1
  { 162,	2,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo46 },  // Inst #162 = CLO
  { 163,	2,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo46 },  // Inst #163 = CLZ
  { 164,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #164 = CMPGDU_EQ_QB
  { 165,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #165 = CMPGDU_LE_QB
  { 166,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #166 = CMPGDU_LT_QB
  { 167,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #167 = CMPGU_EQ_QB
  { 168,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #168 = CMPGU_LE_QB
  { 169,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #169 = CMPGU_LT_QB
  { 170,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #170 = CMPU_EQ_QB
  { 171,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #171 = CMPU_LE_QB
  { 172,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #172 = CMPU_LT_QB
  { 173,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #173 = CMP_EQ_PH
  { 174,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #174 = CMP_LE_PH
  { 175,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo8 },  // Inst #175 = CMP_LT_PH
  { 176,	2,	1,	8,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo48 },  // Inst #176 = CTC1
  { 177,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo49 },  // Inst #177 = CVT_D32_S
  { 178,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo49 },  // Inst #178 = CVT_D32_W
  { 179,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #179 = CVT_D64_L
  { 180,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo41 },  // Inst #180 = CVT_D64_S
  { 181,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo41 },  // Inst #181 = CVT_D64_W
  { 182,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #182 = CVT_L_D64
  { 183,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo41 },  // Inst #183 = CVT_L_S
  { 184,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo42 },  // Inst #184 = CVT_S_D32
  { 185,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo43 },  // Inst #185 = CVT_S_D64
  { 186,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo43 },  // Inst #186 = CVT_S_L
  { 187,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #187 = CVT_S_W
  { 188,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo42 },  // Inst #188 = CVT_W_D32
  { 189,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo43 },  // Inst #189 = CVT_W_D64
  { 190,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #190 = CVT_W_S
  { 191,	1,	0,	17,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5 },  // Inst #191 = Constant32
  { 192,	3,	1,	0,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo15 },  // Inst #192 = DADD
  { 193,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo50 },  // Inst #193 = DADDi
  { 194,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x2ULL, NULL, NULL, OperandInfo50 },  // Inst #194 = DADDiu
  { 195,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo15 },  // Inst #195 = DADDu
  { 196,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x2ULL, NULL, NULL, OperandInfo50 },  // Inst #196 = DANDi
  { 197,	2,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo51 },  // Inst #197 = DCLO
  { 198,	2,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo51 },  // Inst #198 = DCLZ
  { 199,	4,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo52 },  // Inst #199 = DEXT
  { 200,	4,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo52 },  // Inst #200 = DEXTM
  { 201,	4,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo52 },  // Inst #201 = DEXTU
  { 202,	5,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo53 },  // Inst #202 = DINS
  { 203,	5,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo53 },  // Inst #203 = DINSM
  { 204,	5,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo53 },  // Inst #204 = DINSU
  { 205,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo50 },  // Inst #205 = DMFC0_3OP64
  { 206,	2,	1,	8,	4,	0|(1<<MCID::Bitcast), 0x4ULL, NULL, NULL, OperandInfo54 },  // Inst #206 = DMFC1
  { 207,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo50 },  // Inst #207 = DMFC2_3OP64
  { 208,	3,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo55 },  // Inst #208 = DMTC0_3OP64
  { 209,	2,	1,	8,	4,	0|(1<<MCID::Bitcast), 0x4ULL, NULL, NULL, OperandInfo56 },  // Inst #209 = DMTC1
  { 210,	3,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo55 },  // Inst #210 = DMTC2_3OP64
  { 211,	2,	0,	15,	4,	0|(1<<MCID::Commutable), 0x1ULL, NULL, ImplicitList6, OperandInfo51 },  // Inst #211 = DMULT
  { 212,	2,	0,	15,	4,	0|(1<<MCID::Commutable), 0x1ULL, NULL, ImplicitList6, OperandInfo51 },  // Inst #212 = DMULTu
  { 213,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #213 = DPAQX_SA_W_PH
  { 214,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #214 = DPAQX_SA_W_PH_PSEUDO
  { 215,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #215 = DPAQX_S_W_PH
  { 216,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #216 = DPAQX_S_W_PH_PSEUDO
  { 217,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #217 = DPAQ_SA_L_W
  { 218,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #218 = DPAQ_SA_L_W_PSEUDO
  { 219,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #219 = DPAQ_S_W_PH
  { 220,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #220 = DPAQ_S_W_PH_PSEUDO
  { 221,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #221 = DPAU_H_QBL
  { 222,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #222 = DPAU_H_QBL_PSEUDO
  { 223,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #223 = DPAU_H_QBR
  { 224,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #224 = DPAU_H_QBR_PSEUDO
  { 225,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #225 = DPAX_W_PH
  { 226,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #226 = DPAX_W_PH_PSEUDO
  { 227,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #227 = DPA_W_PH
  { 228,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #228 = DPA_W_PH_PSEUDO
  { 229,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #229 = DPSQX_SA_W_PH
  { 230,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #230 = DPSQX_SA_W_PH_PSEUDO
  { 231,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #231 = DPSQX_S_W_PH
  { 232,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #232 = DPSQX_S_W_PH_PSEUDO
  { 233,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #233 = DPSQ_SA_L_W
  { 234,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #234 = DPSQ_SA_L_W_PSEUDO
  { 235,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #235 = DPSQ_S_W_PH
  { 236,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #236 = DPSQ_S_W_PH_PSEUDO
  { 237,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #237 = DPSU_H_QBL
  { 238,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #238 = DPSU_H_QBL_PSEUDO
  { 239,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #239 = DPSU_H_QBR
  { 240,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #240 = DPSU_H_QBR_PSEUDO
  { 241,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #241 = DPSX_W_PH
  { 242,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #242 = DPSX_W_PH_PSEUDO
  { 243,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #243 = DPS_W_PH
  { 244,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #244 = DPS_W_PH_PSEUDO
  { 245,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo50 },  // Inst #245 = DROTR
  { 246,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo58 },  // Inst #246 = DROTRV
  { 247,	2,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo51 },  // Inst #247 = DSBH
  { 248,	2,	0,	14,	4,	0, 0x1ULL, NULL, ImplicitList6, OperandInfo51 },  // Inst #248 = DSDIV
  { 249,	2,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo51 },  // Inst #249 = DSHD
  { 250,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo50 },  // Inst #250 = DSLL
  { 251,	3,	1,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo50 },  // Inst #251 = DSLL32
  { 252,	2,	1,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo59 },  // Inst #252 = DSLL64_32
  { 253,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo58 },  // Inst #253 = DSLLV
  { 254,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo50 },  // Inst #254 = DSRA
  { 255,	3,	1,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo50 },  // Inst #255 = DSRA32
  { 256,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo58 },  // Inst #256 = DSRAV
  { 257,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo50 },  // Inst #257 = DSRL
  { 258,	3,	1,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo50 },  // Inst #258 = DSRL32
  { 259,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo58 },  // Inst #259 = DSRLV
  { 260,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo15 },  // Inst #260 = DSUBu
  { 261,	2,	0,	14,	4,	0, 0x1ULL, NULL, ImplicitList6, OperandInfo51 },  // Inst #261 = DUDIV
  { 262,	2,	0,	1,	0,	0, 0x3ULL, NULL, ImplicitList9, OperandInfo60 },  // Inst #262 = DivRxRy16
  { 263,	2,	0,	1,	0,	0, 0x3ULL, NULL, ImplicitList9, OperandInfo60 },  // Inst #263 = DivuRxRy16
  { 264,	4,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo61 },  // Inst #264 = EXT
  { 265,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo62 },  // Inst #265 = EXTP
  { 266,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo62 },  // Inst #266 = EXTPDP
  { 267,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo63 },  // Inst #267 = EXTPDPV
  { 268,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo63 },  // Inst #268 = EXTPV
  { 269,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo63 },  // Inst #269 = EXTRV_RS_W
  { 270,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo63 },  // Inst #270 = EXTRV_R_W
  { 271,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo63 },  // Inst #271 = EXTRV_S_H
  { 272,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo63 },  // Inst #272 = EXTRV_W
  { 273,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo62 },  // Inst #273 = EXTR_RS_W
  { 274,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo62 },  // Inst #274 = EXTR_R_W
  { 275,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo62 },  // Inst #275 = EXTR_S_H
  { 276,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo62 },  // Inst #276 = EXTR_W
  { 277,	3,	1,	17,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo64 },  // Inst #277 = ExtractElementF64
  { 278,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo65 },  // Inst #278 = FABS_D32
  { 279,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #279 = FABS_D64
  { 280,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #280 = FABS_S
  { 281,	3,	1,	3,	4,	0|(1<<MCID::Commutable), 0x4ULL, NULL, NULL, OperandInfo66 },  // Inst #281 = FADD_D32
  { 282,	3,	1,	3,	4,	0|(1<<MCID::Commutable), 0x4ULL, NULL, NULL, OperandInfo67 },  // Inst #282 = FADD_D64
  { 283,	3,	1,	3,	4,	0|(1<<MCID::Commutable), 0x4ULL, NULL, NULL, OperandInfo68 },  // Inst #283 = FADD_S
  { 284,	3,	0,	4,	4,	0, 0x4ULL, NULL, ImplicitList5, OperandInfo69 },  // Inst #284 = FCMP_D32
  { 285,	3,	0,	4,	4,	0, 0x4ULL, NULL, ImplicitList5, OperandInfo70 },  // Inst #285 = FCMP_D64
  { 286,	3,	0,	4,	4,	0, 0x4ULL, NULL, ImplicitList5, OperandInfo71 },  // Inst #286 = FCMP_S32
  { 287,	3,	1,	6,	4,	0, 0x4ULL, NULL, NULL, OperandInfo66 },  // Inst #287 = FDIV_D32
  { 288,	3,	1,	6,	4,	0, 0x4ULL, NULL, NULL, OperandInfo67 },  // Inst #288 = FDIV_D64
  { 289,	3,	1,	7,	4,	0, 0x4ULL, NULL, NULL, OperandInfo68 },  // Inst #289 = FDIV_S
  { 290,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #290 = FLOOR_L_D64
  { 291,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo41 },  // Inst #291 = FLOOR_L_S
  { 292,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo42 },  // Inst #292 = FLOOR_W_D32
  { 293,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo43 },  // Inst #293 = FLOOR_W_D64
  { 294,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #294 = FLOOR_W_S
  { 295,	2,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo65 },  // Inst #295 = FMOV_D32
  { 296,	2,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #296 = FMOV_D64
  { 297,	2,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #297 = FMOV_S
  { 298,	3,	1,	9,	4,	0|(1<<MCID::Commutable), 0x4ULL, NULL, NULL, OperandInfo66 },  // Inst #298 = FMUL_D32
  { 299,	3,	1,	9,	4,	0|(1<<MCID::Commutable), 0x4ULL, NULL, NULL, OperandInfo67 },  // Inst #299 = FMUL_D64
  { 300,	3,	1,	10,	4,	0|(1<<MCID::Commutable), 0x4ULL, NULL, NULL, OperandInfo68 },  // Inst #300 = FMUL_S
  { 301,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo65 },  // Inst #301 = FNEG_D32
  { 302,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #302 = FNEG_D64
  { 303,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #303 = FNEG_S
  { 304,	2,	1,	11,	4,	0, 0x4ULL, NULL, NULL, OperandInfo65 },  // Inst #304 = FSQRT_D32
  { 305,	2,	1,	11,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #305 = FSQRT_D64
  { 306,	2,	1,	12,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #306 = FSQRT_S
  { 307,	3,	1,	3,	4,	0, 0x4ULL, NULL, NULL, OperandInfo66 },  // Inst #307 = FSUB_D32
  { 308,	3,	1,	3,	4,	0, 0x4ULL, NULL, NULL, OperandInfo67 },  // Inst #308 = FSUB_D64
  { 309,	3,	1,	3,	4,	0, 0x4ULL, NULL, NULL, OperandInfo68 },  // Inst #309 = FSUB_S
  { 310,	5,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo72 },  // Inst #310 = INS
  { 311,	3,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x6ULL, ImplicitList1, NULL, OperandInfo73 },  // Inst #311 = INSV
  { 312,	1,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x3ULL, NULL, ImplicitList3, OperandInfo5 },  // Inst #312 = J
  { 313,	1,	0,	2,	4,	0|(1<<MCID::DelaySlot)|(1<<MCID::Call), 0x3ULL, NULL, ImplicitList4, OperandInfo5 },  // Inst #313 = JAL
  { 314,	1,	0,	2,	4,	0|(1<<MCID::DelaySlot)|(1<<MCID::Call), 0x1ULL, NULL, ImplicitList4, OperandInfo35 },  // Inst #314 = JALR
  { 315,	1,	0,	2,	4,	0|(1<<MCID::DelaySlot)|(1<<MCID::Call), 0x1ULL, NULL, ImplicitList4, OperandInfo74 },  // Inst #315 = JALR64
  { 316,	1,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x1ULL, NULL, NULL, OperandInfo35 },  // Inst #316 = JR
  { 317,	1,	0,	2,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x1ULL, NULL, NULL, OperandInfo74 },  // Inst #317 = JR64
  { 318,	0,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x3ULL, NULL, NULL, 0 },  // Inst #318 = JrRa16
  { 319,	0,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x3ULL, NULL, NULL, 0 },  // Inst #319 = JrcRa16
  { 320,	1,	0,	1,	0,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x3ULL, NULL, NULL, OperandInfo75 },  // Inst #320 = JrcRx16
  { 321,	1,	0,	2,	0,	0|(1<<MCID::Call), 0x3ULL, NULL, NULL, OperandInfo75 },  // Inst #321 = JumpLinkReg16
  { 322,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #322 = LB
  { 323,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #323 = LB64
  { 324,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #324 = LB64_P8
  { 325,	3,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #325 = LBUX
  { 326,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #326 = LB_P8
  { 327,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #327 = LBu
  { 328,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #328 = LBu64
  { 329,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #329 = LBu64_P8
  { 330,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #330 = LBu_P8
  { 331,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #331 = LD
  { 332,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo80 },  // Inst #332 = LDC1
  { 333,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo81 },  // Inst #333 = LDC164
  { 334,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo82 },  // Inst #334 = LDC164_P8
  { 335,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo83 },  // Inst #335 = LDL
  { 336,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo84 },  // Inst #336 = LDL_P8
  { 337,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo83 },  // Inst #337 = LDR
  { 338,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo84 },  // Inst #338 = LDR_P8
  { 339,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo39 },  // Inst #339 = LDXC1
  { 340,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo85 },  // Inst #340 = LDXC164
  { 341,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo86 },  // Inst #341 = LDXC164_P8
  { 342,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #342 = LD_P8
  { 343,	3,	1,	0,	4,	0, 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #343 = LEA_ADDiu
  { 344,	3,	1,	0,	4,	0, 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #344 = LEA_ADDiu64
  { 345,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #345 = LH
  { 346,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #346 = LH64
  { 347,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #347 = LH64_P8
  { 348,	3,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #348 = LHX
  { 349,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #349 = LH_P8
  { 350,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #350 = LHu
  { 351,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #351 = LHu64
  { 352,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #352 = LHu64_P8
  { 353,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #353 = LHu_P8
  { 354,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo13 },  // Inst #354 = LL
  { 355,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo87 },  // Inst #355 = LLD
  { 356,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo50 },  // Inst #356 = LLD_P8
  { 357,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo88 },  // Inst #357 = LL_P8
  { 358,	3,	1,	16,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x5ULL, NULL, NULL, OperandInfo39 },  // Inst #358 = LUXC1
  { 359,	3,	1,	16,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x5ULL, NULL, NULL, OperandInfo85 },  // Inst #359 = LUXC164
  { 360,	2,	1,	1,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x2ULL, NULL, NULL, OperandInfo89 },  // Inst #360 = LUi
  { 361,	2,	1,	1,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x2ULL, NULL, NULL, OperandInfo90 },  // Inst #361 = LUi64
  { 362,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #362 = LW
  { 363,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #363 = LW64
  { 364,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #364 = LW64_P8
  { 365,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo91 },  // Inst #365 = LWC1
  { 366,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo92 },  // Inst #366 = LWC1_P8
  { 367,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo93 },  // Inst #367 = LWL
  { 368,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo83 },  // Inst #368 = LWL64
  { 369,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo84 },  // Inst #369 = LWL64_P8
  { 370,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo94 },  // Inst #370 = LWL_P8
  { 371,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo93 },  // Inst #371 = LWR
  { 372,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo83 },  // Inst #372 = LWR64
  { 373,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo84 },  // Inst #373 = LWR64_P8
  { 374,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo94 },  // Inst #374 = LWR_P8
  { 375,	3,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #375 = LWX
  { 376,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo95 },  // Inst #376 = LWXC1
  { 377,	3,	1,	16,	4,	0|(1<<MCID::MayLoad), 0x5ULL, NULL, NULL, OperandInfo96 },  // Inst #377 = LWXC1_P8
  { 378,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #378 = LW_P8
  { 379,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #379 = LWu64
  { 380,	3,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #380 = LWu64_P8
  { 381,	4,	1,	16,	0,	0|(1<<MCID::MayLoad), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #381 = LbRxRyOffMemX16
  { 382,	4,	1,	16,	0,	0|(1<<MCID::MayLoad), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #382 = LbuRxRyOffMemX16
  { 383,	4,	1,	16,	0,	0|(1<<MCID::MayLoad), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #383 = LhRxRyOffMemX16
  { 384,	4,	1,	16,	0,	0|(1<<MCID::MayLoad), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #384 = LhuRxRyOffMemX16
  { 385,	2,	1,	1,	0,	0, 0x10ULL, NULL, NULL, OperandInfo24 },  // Inst #385 = LiRxImmX16
  { 386,	2,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo98 },  // Inst #386 = LoadAddr32Imm
  { 387,	3,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13 },  // Inst #387 = LoadAddr32Reg
  { 388,	2,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo98 },  // Inst #388 = LoadImm32Reg
  { 389,	2,	0,	17,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo24 },  // Inst #389 = LwConstant32
  { 390,	4,	1,	16,	0,	0|(1<<MCID::MayLoad), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #390 = LwRxRyOffMemX16
  { 391,	3,	1,	16,	0,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x10ULL, ImplicitList2, NULL, OperandInfo99 },  // Inst #391 = LwRxSpImmX16
  { 392,	2,	0,	15,	4,	0|(1<<MCID::Commutable), 0x1ULL, ImplicitList9, ImplicitList9, OperandInfo46 },  // Inst #392 = MADD
  { 393,	2,	0,	15,	4,	0|(1<<MCID::Commutable), 0x1ULL, ImplicitList9, ImplicitList9, OperandInfo46 },  // Inst #393 = MADDU
  { 394,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #394 = MADDU_DSP
  { 395,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #395 = MADDU_DSP_PSEUDO
  { 396,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo100 },  // Inst #396 = MADD_D32
  { 397,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo101 },  // Inst #397 = MADD_D64
  { 398,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #398 = MADD_DSP
  { 399,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #399 = MADD_DSP_PSEUDO
  { 400,	4,	1,	10,	4,	0, 0x4ULL, NULL, NULL, OperandInfo102 },  // Inst #400 = MADD_S
  { 401,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #401 = MAQ_SA_W_PHL
  { 402,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #402 = MAQ_SA_W_PHL_PSEUDO
  { 403,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #403 = MAQ_SA_W_PHR
  { 404,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #404 = MAQ_SA_W_PHR_PSEUDO
  { 405,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #405 = MAQ_S_W_PHL
  { 406,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #406 = MAQ_S_W_PHL_PSEUDO
  { 407,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #407 = MAQ_S_W_PHR
  { 408,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #408 = MAQ_S_W_PHR_PSEUDO
  { 409,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo13 },  // Inst #409 = MFC0_3OP
  { 410,	2,	1,	8,	4,	0|(1<<MCID::Bitcast), 0x4ULL, NULL, NULL, OperandInfo103 },  // Inst #410 = MFC1
  { 411,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo13 },  // Inst #411 = MFC2_3OP
  { 412,	1,	1,	13,	4,	0, 0x1ULL, ImplicitList10, NULL, OperandInfo35 },  // Inst #412 = MFHI
  { 413,	1,	1,	13,	4,	0, 0x1ULL, ImplicitList11, NULL, OperandInfo74 },  // Inst #413 = MFHI64
  { 414,	1,	1,	13,	4,	0, 0x1ULL, ImplicitList12, NULL, OperandInfo35 },  // Inst #414 = MFLO
  { 415,	1,	1,	13,	4,	0, 0x1ULL, ImplicitList13, NULL, OperandInfo74 },  // Inst #415 = MFLO64
  { 416,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #416 = MODSUB
  { 417,	2,	1,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo104 },  // Inst #417 = MOVCCRToCCR
  { 418,	3,	1,	8,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo105 },  // Inst #418 = MOVF_D32
  { 419,	3,	1,	8,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo106 },  // Inst #419 = MOVF_D64
  { 420,	3,	1,	1,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo107 },  // Inst #420 = MOVF_I
  { 421,	3,	1,	1,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo108 },  // Inst #421 = MOVF_I64
  { 422,	3,	1,	8,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo109 },  // Inst #422 = MOVF_S
  { 423,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo110 },  // Inst #423 = MOVN_I64_D64
  { 424,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo111 },  // Inst #424 = MOVN_I64_I
  { 425,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo112 },  // Inst #425 = MOVN_I64_I64
  { 426,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo113 },  // Inst #426 = MOVN_I64_S
  { 427,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo114 },  // Inst #427 = MOVN_I_D32
  { 428,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo115 },  // Inst #428 = MOVN_I_D64
  { 429,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo116 },  // Inst #429 = MOVN_I_I
  { 430,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo117 },  // Inst #430 = MOVN_I_I64
  { 431,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo118 },  // Inst #431 = MOVN_I_S
  { 432,	3,	1,	8,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo105 },  // Inst #432 = MOVT_D32
  { 433,	3,	1,	8,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo106 },  // Inst #433 = MOVT_D64
  { 434,	3,	1,	1,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo107 },  // Inst #434 = MOVT_I
  { 435,	3,	1,	1,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo108 },  // Inst #435 = MOVT_I64
  { 436,	3,	1,	8,	4,	0, 0x4ULL, ImplicitList5, NULL, OperandInfo109 },  // Inst #436 = MOVT_S
  { 437,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo110 },  // Inst #437 = MOVZ_I64_D64
  { 438,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo111 },  // Inst #438 = MOVZ_I64_I
  { 439,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo112 },  // Inst #439 = MOVZ_I64_I64
  { 440,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo113 },  // Inst #440 = MOVZ_I64_S
  { 441,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo114 },  // Inst #441 = MOVZ_I_D32
  { 442,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo115 },  // Inst #442 = MOVZ_I_D64
  { 443,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo116 },  // Inst #443 = MOVZ_I_I
  { 444,	4,	1,	0,	4,	0, 0x4ULL, NULL, NULL, OperandInfo117 },  // Inst #444 = MOVZ_I_I64
  { 445,	4,	1,	8,	4,	0, 0x4ULL, NULL, NULL, OperandInfo118 },  // Inst #445 = MOVZ_I_S
  { 446,	2,	0,	15,	4,	0, 0x1ULL, ImplicitList9, ImplicitList9, OperandInfo46 },  // Inst #446 = MSUB
  { 447,	2,	0,	15,	4,	0, 0x1ULL, ImplicitList9, ImplicitList9, OperandInfo46 },  // Inst #447 = MSUBU
  { 448,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #448 = MSUBU_DSP
  { 449,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #449 = MSUBU_DSP_PSEUDO
  { 450,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo100 },  // Inst #450 = MSUB_D32
  { 451,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo101 },  // Inst #451 = MSUB_D64
  { 452,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #452 = MSUB_DSP
  { 453,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #453 = MSUB_DSP_PSEUDO
  { 454,	4,	1,	10,	4,	0, 0x4ULL, NULL, NULL, OperandInfo102 },  // Inst #454 = MSUB_S
  { 455,	3,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo119 },  // Inst #455 = MTC0_3OP
  { 456,	2,	1,	8,	4,	0|(1<<MCID::Bitcast), 0x4ULL, NULL, NULL, OperandInfo120 },  // Inst #456 = MTC1
  { 457,	3,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo119 },  // Inst #457 = MTC2_3OP
  { 458,	1,	0,	13,	4,	0, 0x1ULL, NULL, ImplicitList10, OperandInfo35 },  // Inst #458 = MTHI
  { 459,	1,	0,	13,	4,	0, 0x1ULL, NULL, ImplicitList11, OperandInfo74 },  // Inst #459 = MTHI64
  { 460,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo121 },  // Inst #460 = MTHLIP
  { 461,	1,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo35 },  // Inst #461 = MTHLIP_PSEUDO
  { 462,	1,	0,	13,	4,	0, 0x1ULL, NULL, ImplicitList12, OperandInfo35 },  // Inst #462 = MTLO
  { 463,	1,	0,	13,	4,	0, 0x1ULL, NULL, ImplicitList13, OperandInfo74 },  // Inst #463 = MTLO64
  { 464,	3,	1,	15,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #464 = MUL
  { 465,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #465 = MULEQ_S_W_PHL
  { 466,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo47 },  // Inst #466 = MULEQ_S_W_PHR
  { 467,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #467 = MULEU_S_PH_QBL
  { 468,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #468 = MULEU_S_PH_QBR
  { 469,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #469 = MULQ_RS_PH
  { 470,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo12 },  // Inst #470 = MULQ_RS_W
  { 471,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #471 = MULQ_S_PH
  { 472,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo12 },  // Inst #472 = MULQ_S_W
  { 473,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #473 = MULSAQ_S_W_PH
  { 474,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #474 = MULSAQ_S_W_PH_PSEUDO
  { 475,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #475 = MULSA_W_PH
  { 476,	2,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo9 },  // Inst #476 = MULSA_W_PH_PSEUDO
  { 477,	2,	0,	15,	4,	0|(1<<MCID::Commutable), 0x1ULL, NULL, ImplicitList9, OperandInfo46 },  // Inst #477 = MULT
  { 478,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #478 = MULTU_DSP
  { 479,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList8, OperandInfo9 },  // Inst #479 = MULTU_DSP_PSEUDO
  { 480,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo57 },  // Inst #480 = MULT_DSP
  { 481,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList8, OperandInfo9 },  // Inst #481 = MULT_DSP_PSEUDO
  { 482,	2,	0,	15,	4,	0|(1<<MCID::Commutable), 0x1ULL, NULL, ImplicitList9, OperandInfo46 },  // Inst #482 = MULTu
  { 483,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #483 = MUL_PH
  { 484,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #484 = MUL_S_PH
  { 485,	1,	1,	1,	0,	0, 0x3ULL, ImplicitList10, NULL, OperandInfo75 },  // Inst #485 = Mfhi16
  { 486,	1,	1,	1,	0,	0, 0x3ULL, ImplicitList12, NULL, OperandInfo75 },  // Inst #486 = Mflo16
  { 487,	2,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0xaULL, NULL, NULL, OperandInfo122 },  // Inst #487 = Move32R16
  { 488,	2,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x9ULL, NULL, NULL, OperandInfo123 },  // Inst #488 = MoveR3216
  { 489,	2,	0,	17,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList9, OperandInfo60 },  // Inst #489 = MultRxRy16
  { 490,	3,	1,	17,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList9, OperandInfo27 },  // Inst #490 = MultRxRyRz16
  { 491,	2,	0,	17,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList9, OperandInfo60 },  // Inst #491 = MultuRxRy16
  { 492,	3,	1,	17,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList9, OperandInfo27 },  // Inst #492 = MultuRxRyRz16
  { 493,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo100 },  // Inst #493 = NMADD_D32
  { 494,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo101 },  // Inst #494 = NMADD_D64
  { 495,	4,	1,	10,	4,	0, 0x4ULL, NULL, NULL, OperandInfo102 },  // Inst #495 = NMADD_S
  { 496,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo100 },  // Inst #496 = NMSUB_D32
  { 497,	4,	1,	9,	4,	0, 0x4ULL, NULL, NULL, OperandInfo101 },  // Inst #497 = NMSUB_D64
  { 498,	4,	1,	10,	4,	0, 0x4ULL, NULL, NULL, OperandInfo102 },  // Inst #498 = NMSUB_S
  { 499,	0,	0,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x3ULL, NULL, NULL, 0 },  // Inst #499 = NOP
  { 500,	3,	1,	1,	4,	0|(1<<MCID::Commutable), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #500 = NOR
  { 501,	3,	1,	1,	4,	0|(1<<MCID::Commutable), 0x1ULL, NULL, NULL, OperandInfo15 },  // Inst #501 = NOR64
  { 502,	2,	1,	1,	0,	0, 0x3ULL, NULL, NULL, OperandInfo60 },  // Inst #502 = NegRxRy16
  { 503,	2,	1,	1,	0,	0, 0x3ULL, NULL, NULL, OperandInfo60 },  // Inst #503 = NotRxRy16
  { 504,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #504 = OR
  { 505,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo15 },  // Inst #505 = OR64
  { 506,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x2ULL, NULL, NULL, OperandInfo13 },  // Inst #506 = ORi
  { 507,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x2ULL, NULL, NULL, OperandInfo50 },  // Inst #507 = ORi64
  { 508,	3,	1,	1,	0,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x3ULL, NULL, NULL, OperandInfo28 },  // Inst #508 = OrRxRxRy16
  { 509,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #509 = PACKRL_PH
  { 510,	3,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x6ULL, ImplicitList1, NULL, OperandInfo11 },  // Inst #510 = PICK_PH
  { 511,	3,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x6ULL, ImplicitList1, NULL, OperandInfo11 },  // Inst #511 = PICK_QB
  { 512,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #512 = PRECEQU_PH_QBL
  { 513,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #513 = PRECEQU_PH_QBLA
  { 514,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #514 = PRECEQU_PH_QBR
  { 515,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #515 = PRECEQU_PH_QBRA
  { 516,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo124 },  // Inst #516 = PRECEQ_W_PHL
  { 517,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo124 },  // Inst #517 = PRECEQ_W_PHR
  { 518,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #518 = PRECEU_PH_QBL
  { 519,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #519 = PRECEU_PH_QBLA
  { 520,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #520 = PRECEU_PH_QBR
  { 521,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo8 },  // Inst #521 = PRECEU_PH_QBRA
  { 522,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #522 = PRECRQU_S_QB_PH
  { 523,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo125 },  // Inst #523 = PRECRQ_PH_W
  { 524,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #524 = PRECRQ_QB_PH
  { 525,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo125 },  // Inst #525 = PRECRQ_RS_PH_W
  { 526,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #526 = PRECR_QB_PH
  { 527,	4,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo126 },  // Inst #527 = PRECR_SRA_PH_W
  { 528,	4,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo126 },  // Inst #528 = PRECR_SRA_R_PH_W
  { 529,	4,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo16 },  // Inst #529 = PREPEND
  { 530,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo124 },  // Inst #530 = RADDU_W_QB
  { 531,	2,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x6ULL, ImplicitList1, NULL, OperandInfo89 },  // Inst #531 = RDDSP
  { 532,	2,	1,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo127 },  // Inst #532 = RDHWR
  { 533,	2,	1,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo128 },  // Inst #533 = RDHWR64
  { 534,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo129 },  // Inst #534 = REPLV_PH
  { 535,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo129 },  // Inst #535 = REPLV_QB
  { 536,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo130 },  // Inst #536 = REPL_PH
  { 537,	2,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo130 },  // Inst #537 = REPL_QB
  { 538,	1,	0,	2,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects)|(1<<MCID::ExtraSrcRegAllocReq), 0x1ULL, NULL, NULL, OperandInfo35 },  // Inst #538 = RET
  { 539,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo13 },  // Inst #539 = ROTR
  { 540,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #540 = ROTRV
  { 541,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #541 = ROUND_L_D64
  { 542,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo41 },  // Inst #542 = ROUND_L_S
  { 543,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo42 },  // Inst #543 = ROUND_W_D32
  { 544,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo43 },  // Inst #544 = ROUND_W_D64
  { 545,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #545 = ROUND_W_S
  { 546,	1,	0,	16,	0,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0xbULL, ImplicitList2, ImplicitList2, OperandInfo5 },  // Inst #546 = RestoreIncSpF16
  { 547,	1,	0,	16,	0,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0xbULL, ImplicitList2, ImplicitList14, OperandInfo5 },  // Inst #547 = RestoreRaF16
  { 548,	0,	0,	17,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, 0 },  // Inst #548 = RetRA
  { 549,	0,	0,	17,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Terminator)|(1<<MCID::ExtraSrcRegAllocReq), 0x0ULL, NULL, NULL, 0 },  // Inst #549 = RetRA16
  { 550,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #550 = SB
  { 551,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #551 = SB64
  { 552,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #552 = SB64_P8
  { 553,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #553 = SB_P8
  { 554,	4,	1,	0,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo131 },  // Inst #554 = SC
  { 555,	4,	1,	0,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo132 },  // Inst #555 = SCD
  { 556,	4,	1,	0,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo133 },  // Inst #556 = SCD_P8
  { 557,	4,	1,	0,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x2ULL, NULL, NULL, OperandInfo134 },  // Inst #557 = SC_P8
  { 558,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #558 = SD
  { 559,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo80 },  // Inst #559 = SDC1
  { 560,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo81 },  // Inst #560 = SDC164
  { 561,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo82 },  // Inst #561 = SDC164_P8
  { 562,	2,	0,	14,	4,	0, 0x1ULL, NULL, ImplicitList9, OperandInfo46 },  // Inst #562 = SDIV
  { 563,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #563 = SDL
  { 564,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #564 = SDL_P8
  { 565,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #565 = SDR
  { 566,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #566 = SDR_P8
  { 567,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo39 },  // Inst #567 = SDXC1
  { 568,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo85 },  // Inst #568 = SDXC164
  { 569,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo86 },  // Inst #569 = SDXC164_P8
  { 570,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #570 = SD_P8
  { 571,	2,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo9 },  // Inst #571 = SEB
  { 572,	2,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo135 },  // Inst #572 = SEB64
  { 573,	2,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo9 },  // Inst #573 = SEH
  { 574,	2,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo135 },  // Inst #574 = SEH64
  { 575,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #575 = SH
  { 576,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #576 = SH64
  { 577,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #577 = SH64_P8
  { 578,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo136 },  // Inst #578 = SHILO
  { 579,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo121 },  // Inst #579 = SHILOV
  { 580,	1,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo35 },  // Inst #580 = SHILOV_PSEUDO
  { 581,	1,	0,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList7, ImplicitList8, OperandInfo5 },  // Inst #581 = SHILO_PSEUDO
  { 582,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo137 },  // Inst #582 = SHLLV_PH
  { 583,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo137 },  // Inst #583 = SHLLV_QB
  { 584,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo137 },  // Inst #584 = SHLLV_S_PH
  { 585,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo12 },  // Inst #585 = SHLLV_S_W
  { 586,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo138 },  // Inst #586 = SHLL_PH
  { 587,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo138 },  // Inst #587 = SHLL_QB
  { 588,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo138 },  // Inst #588 = SHLL_S_PH
  { 589,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo139 },  // Inst #589 = SHLL_S_W
  { 590,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo137 },  // Inst #590 = SHRAV_PH
  { 591,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo137 },  // Inst #591 = SHRAV_QB
  { 592,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo137 },  // Inst #592 = SHRAV_R_PH
  { 593,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo137 },  // Inst #593 = SHRAV_R_QB
  { 594,	3,	1,	0,	4,	0, 0x6ULL, NULL, ImplicitList1, OperandInfo12 },  // Inst #594 = SHRAV_R_W
  { 595,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo138 },  // Inst #595 = SHRA_PH
  { 596,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo138 },  // Inst #596 = SHRA_QB
  { 597,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo138 },  // Inst #597 = SHRA_R_PH
  { 598,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo138 },  // Inst #598 = SHRA_R_QB
  { 599,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo139 },  // Inst #599 = SHRA_R_W
  { 600,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo137 },  // Inst #600 = SHRLV_PH
  { 601,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo137 },  // Inst #601 = SHRLV_QB
  { 602,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo138 },  // Inst #602 = SHRL_PH
  { 603,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo138 },  // Inst #603 = SHRL_QB
  { 604,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #604 = SH_P8
  { 605,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo13 },  // Inst #605 = SLL
  { 606,	2,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo59 },  // Inst #606 = SLL64_32
  { 607,	2,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo135 },  // Inst #607 = SLL64_64
  { 608,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #608 = SLLV
  { 609,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo140 },  // Inst #609 = SLT
  { 610,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo141 },  // Inst #610 = SLT64
  { 611,	3,	1,	1,	4,	0, 0x2ULL, NULL, NULL, OperandInfo142 },  // Inst #611 = SLTi
  { 612,	3,	1,	1,	4,	0, 0x2ULL, NULL, NULL, OperandInfo143 },  // Inst #612 = SLTi64
  { 613,	3,	1,	1,	4,	0, 0x2ULL, NULL, NULL, OperandInfo142 },  // Inst #613 = SLTiu
  { 614,	3,	1,	1,	4,	0, 0x2ULL, NULL, NULL, OperandInfo143 },  // Inst #614 = SLTiu64
  { 615,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo140 },  // Inst #615 = SLTu
  { 616,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo141 },  // Inst #616 = SLTu64
  { 617,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo13 },  // Inst #617 = SRA
  { 618,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #618 = SRAV
  { 619,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo13 },  // Inst #619 = SRL
  { 620,	3,	1,	1,	4,	0, 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #620 = SRLV
  { 621,	3,	1,	0,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::UnmodeledSideEffects), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #621 = SUB
  { 622,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #622 = SUBQH_PH
  { 623,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #623 = SUBQH_R_PH
  { 624,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #624 = SUBQH_R_W
  { 625,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo12 },  // Inst #625 = SUBQH_W
  { 626,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #626 = SUBQ_PH
  { 627,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #627 = SUBQ_S_PH
  { 628,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo12 },  // Inst #628 = SUBQ_S_W
  { 629,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #629 = SUBUH_QB
  { 630,	3,	1,	0,	4,	0, 0x6ULL, NULL, NULL, OperandInfo11 },  // Inst #630 = SUBUH_R_QB
  { 631,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #631 = SUBU_PH
  { 632,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #632 = SUBU_QB
  { 633,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #633 = SUBU_S_PH
  { 634,	3,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo11 },  // Inst #634 = SUBU_S_QB
  { 635,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #635 = SUBu
  { 636,	3,	0,	18,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x5ULL, NULL, NULL, OperandInfo39 },  // Inst #636 = SUXC1
  { 637,	3,	0,	18,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x5ULL, NULL, NULL, OperandInfo85 },  // Inst #637 = SUXC164
  { 638,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #638 = SW
  { 639,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #639 = SW64
  { 640,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #640 = SW64_P8
  { 641,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo91 },  // Inst #641 = SWC1
  { 642,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo92 },  // Inst #642 = SWC1_P8
  { 643,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #643 = SWL
  { 644,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #644 = SWL64
  { 645,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #645 = SWL64_P8
  { 646,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #646 = SWL_P8
  { 647,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo76 },  // Inst #647 = SWR
  { 648,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo77 },  // Inst #648 = SWR64
  { 649,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo78 },  // Inst #649 = SWR64_P8
  { 650,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #650 = SWR_P8
  { 651,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo95 },  // Inst #651 = SWXC1
  { 652,	3,	0,	18,	4,	0|(1<<MCID::MayStore), 0x5ULL, NULL, NULL, OperandInfo96 },  // Inst #652 = SWXC1_P8
  { 653,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x2ULL, NULL, NULL, OperandInfo79 },  // Inst #653 = SW_P8
  { 654,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, NULL, OperandInfo2 },  // Inst #654 = SYNC
  { 655,	1,	0,	18,	0,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0xbULL, ImplicitList2, ImplicitList2, OperandInfo5 },  // Inst #655 = SaveDecSpF16
  { 656,	1,	0,	18,	0,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0xbULL, ImplicitList15, ImplicitList2, OperandInfo5 },  // Inst #656 = SaveRaF16
  { 657,	4,	0,	18,	0,	0|(1<<MCID::MayStore), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #657 = SbRxRyOffMemX16
  { 658,	4,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo144 },  // Inst #658 = SelBeqZ
  { 659,	4,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo144 },  // Inst #659 = SelBneZ
  { 660,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo145 },  // Inst #660 = SelTBteqZCmp
  { 661,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo146 },  // Inst #661 = SelTBteqZCmpi
  { 662,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo145 },  // Inst #662 = SelTBteqZSlt
  { 663,	5,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo146 },  // Inst #663 = SelTBteqZSlti
  { 664,	5,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo146 },  // Inst #664 = SelTBteqZSltiu
  { 665,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo145 },  // Inst #665 = SelTBteqZSltu
  { 666,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo145 },  // Inst #666 = SelTBtneZCmp
  { 667,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo146 },  // Inst #667 = SelTBtneZCmpi
  { 668,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo145 },  // Inst #668 = SelTBtneZSlt
  { 669,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo146 },  // Inst #669 = SelTBtneZSlti
  { 670,	5,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo146 },  // Inst #670 = SelTBtneZSltiu
  { 671,	5,	1,	1,	0,	0, 0x0ULL, NULL, NULL, OperandInfo145 },  // Inst #671 = SelTBtneZSltu
  { 672,	4,	0,	18,	0,	0|(1<<MCID::MayStore), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #672 = ShRxRyOffMemX16
  { 673,	3,	1,	1,	0,	0, 0x13ULL, NULL, NULL, OperandInfo147 },  // Inst #673 = SllX16
  { 674,	3,	1,	1,	0,	0, 0x3ULL, NULL, NULL, OperandInfo28 },  // Inst #674 = SllvRxRy16
  { 675,	3,	1,	1,	0,	0, 0x3ULL, NULL, NULL, OperandInfo27 },  // Inst #675 = SltCCRxRy16
  { 676,	2,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x3ULL, NULL, NULL, OperandInfo60 },  // Inst #676 = SltRxRy16
  { 677,	3,	1,	1,	0,	0, 0x10ULL, NULL, NULL, OperandInfo147 },  // Inst #677 = SltiCCRxImmX16
  { 678,	3,	1,	1,	0,	0, 0x10ULL, NULL, NULL, OperandInfo147 },  // Inst #678 = SltiuCCRxImmX16
  { 679,	3,	1,	1,	0,	0, 0x3ULL, NULL, NULL, OperandInfo27 },  // Inst #679 = SltuCCRxRy16
  { 680,	3,	1,	1,	0,	0|(1<<MCID::UnmodeledSideEffects), 0x3ULL, NULL, NULL, OperandInfo27 },  // Inst #680 = SltuRxRyRz16
  { 681,	3,	1,	1,	0,	0, 0x13ULL, NULL, NULL, OperandInfo147 },  // Inst #681 = SraX16
  { 682,	3,	1,	1,	0,	0, 0x3ULL, NULL, NULL, OperandInfo28 },  // Inst #682 = SravRxRy16
  { 683,	3,	1,	1,	0,	0, 0x13ULL, NULL, NULL, OperandInfo147 },  // Inst #683 = SrlX16
  { 684,	3,	1,	1,	0,	0, 0x3ULL, NULL, NULL, OperandInfo28 },  // Inst #684 = SrlvRxRy16
  { 685,	3,	1,	1,	0,	0|(1<<MCID::Rematerializable), 0x5ULL, NULL, NULL, OperandInfo27 },  // Inst #685 = SubuRxRyRz16
  { 686,	4,	0,	18,	0,	0|(1<<MCID::MayStore), 0x11ULL, NULL, NULL, OperandInfo97 },  // Inst #686 = SwRxRyOffMemX16
  { 687,	3,	1,	18,	0,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x10ULL, NULL, NULL, OperandInfo99 },  // Inst #687 = SwRxSpImmX16
  { 688,	1,	0,	2,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Call)|(1<<MCID::Terminator)|(1<<MCID::ExtraSrcRegAllocReq), 0x3ULL, NULL, ImplicitList3, OperandInfo5 },  // Inst #688 = TAILCALL
  { 689,	1,	0,	2,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Call)|(1<<MCID::Terminator)|(1<<MCID::ExtraSrcRegAllocReq), 0x1ULL, NULL, NULL, OperandInfo74 },  // Inst #689 = TAILCALL64_R
  { 690,	1,	0,	2,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::DelaySlot)|(1<<MCID::Call)|(1<<MCID::Terminator)|(1<<MCID::ExtraSrcRegAllocReq), 0x1ULL, NULL, NULL, OperandInfo35 },  // Inst #690 = TAILCALL_R
  { 691,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo40 },  // Inst #691 = TRUNC_L_D64
  { 692,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo41 },  // Inst #692 = TRUNC_L_S
  { 693,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo42 },  // Inst #693 = TRUNC_W_D32
  { 694,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo43 },  // Inst #694 = TRUNC_W_D64
  { 695,	2,	1,	5,	4,	0, 0x4ULL, NULL, NULL, OperandInfo44 },  // Inst #695 = TRUNC_W_S
  { 696,	2,	0,	14,	4,	0, 0x1ULL, NULL, ImplicitList9, OperandInfo46 },  // Inst #696 = UDIV
  { 697,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x6ULL, NULL, ImplicitList1, OperandInfo89 },  // Inst #697 = WRDSP
  { 698,	2,	1,	0,	4,	0, 0x1ULL, NULL, NULL, OperandInfo46 },  // Inst #698 = WSBH
  { 699,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo10 },  // Inst #699 = XOR
  { 700,	3,	1,	1,	4,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x1ULL, NULL, NULL, OperandInfo15 },  // Inst #700 = XOR64
  { 701,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x2ULL, NULL, NULL, OperandInfo13 },  // Inst #701 = XORi
  { 702,	3,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x2ULL, NULL, NULL, OperandInfo50 },  // Inst #702 = XORi64
  { 703,	3,	1,	1,	0,	0|(1<<MCID::Commutable)|(1<<MCID::Rematerializable), 0x3ULL, NULL, NULL, OperandInfo28 },  // Inst #703 = XorRxRxRy16
};

extern const char OiInstrNameData[] = {
  /* 0 */ 'L', 'D', 'C', '1', 0,
  /* 5 */ 'S', 'D', 'C', '1', 0,
  /* 10 */ 'C', 'F', 'C', '1', 0,
  /* 15 */ 'D', 'M', 'F', 'C', '1', 0,
  /* 21 */ 'C', 'T', 'C', '1', 0,
  /* 26 */ 'D', 'M', 'T', 'C', '1', 0,
  /* 32 */ 'L', 'W', 'C', '1', 0,
  /* 37 */ 'S', 'W', 'C', '1', 0,
  /* 42 */ 'L', 'D', 'X', 'C', '1', 0,
  /* 48 */ 'S', 'D', 'X', 'C', '1', 0,
  /* 54 */ 'L', 'U', 'X', 'C', '1', 0,
  /* 60 */ 'S', 'U', 'X', 'C', '1', 0,
  /* 66 */ 'L', 'W', 'X', 'C', '1', 0,
  /* 72 */ 'S', 'W', 'X', 'C', '1', 0,
  /* 78 */ 'D', 'S', 'R', 'A', '3', '2', 0,
  /* 85 */ 'F', 'S', 'U', 'B', '_', 'D', '3', '2', 0,
  /* 94 */ 'N', 'M', 'S', 'U', 'B', '_', 'D', '3', '2', 0,
  /* 104 */ 'F', 'A', 'D', 'D', '_', 'D', '3', '2', 0,
  /* 113 */ 'N', 'M', 'A', 'D', 'D', '_', 'D', '3', '2', 0,
  /* 123 */ 'M', 'O', 'V', 'F', '_', 'D', '3', '2', 0,
  /* 132 */ 'F', 'N', 'E', 'G', '_', 'D', '3', '2', 0,
  /* 141 */ 'M', 'O', 'V', 'N', '_', 'I', '_', 'D', '3', '2', 0,
  /* 152 */ 'M', 'O', 'V', 'Z', '_', 'I', '_', 'D', '3', '2', 0,
  /* 163 */ 'F', 'M', 'U', 'L', '_', 'D', '3', '2', 0,
  /* 172 */ 'F', 'C', 'M', 'P', '_', 'D', '3', '2', 0,
  /* 181 */ 'F', 'A', 'B', 'S', '_', 'D', '3', '2', 0,
  /* 190 */ 'C', 'V', 'T', '_', 'S', '_', 'D', '3', '2', 0,
  /* 200 */ 'F', 'S', 'Q', 'R', 'T', '_', 'D', '3', '2', 0,
  /* 210 */ 'M', 'O', 'V', 'T', '_', 'D', '3', '2', 0,
  /* 219 */ 'F', 'D', 'I', 'V', '_', 'D', '3', '2', 0,
  /* 228 */ 'F', 'M', 'O', 'V', '_', 'D', '3', '2', 0,
  /* 237 */ 'T', 'R', 'U', 'N', 'C', '_', 'W', '_', 'D', '3', '2', 0,
  /* 249 */ 'R', 'O', 'U', 'N', 'D', '_', 'W', '_', 'D', '3', '2', 0,
  /* 261 */ 'C', 'E', 'I', 'L', '_', 'W', '_', 'D', '3', '2', 0,
  /* 272 */ 'F', 'L', 'O', 'O', 'R', '_', 'W', '_', 'D', '3', '2', 0,
  /* 284 */ 'C', 'V', 'T', '_', 'W', '_', 'D', '3', '2', 0,
  /* 294 */ 'B', 'P', 'O', 'S', 'G', 'E', '3', '2', 0,
  /* 303 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '3', '2', 0,
  /* 323 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '3', '2', 0,
  /* 343 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '3', '2', 0,
  /* 364 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '3', '2', 0,
  /* 384 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '3', '2', 0,
  /* 400 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '3', '2', 0,
  /* 420 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '3', '2', 0,
  /* 440 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '3', '2', 0,
  /* 459 */ 'D', 'S', 'L', 'L', '3', '2', 0,
  /* 466 */ 'D', 'S', 'R', 'L', '3', '2', 0,
  /* 473 */ 'F', 'C', 'M', 'P', '_', 'S', '3', '2', 0,
  /* 482 */ 'D', 'S', 'L', 'L', '6', '4', '_', '3', '2', 0,
  /* 492 */ 'L', 'w', 'C', 'o', 'n', 's', 't', 'a', 'n', 't', '3', '2', 0,
  /* 505 */ 'L', 'D', 'C', '1', '6', '4', 0,
  /* 512 */ 'S', 'D', 'C', '1', '6', '4', 0,
  /* 519 */ 'L', 'D', 'X', 'C', '1', '6', '4', 0,
  /* 527 */ 'S', 'D', 'X', 'C', '1', '6', '4', 0,
  /* 535 */ 'L', 'U', 'X', 'C', '1', '6', '4', 0,
  /* 543 */ 'S', 'U', 'X', 'C', '1', '6', '4', 0,
  /* 551 */ 'S', 'E', 'B', '6', '4', 0,
  /* 557 */ 'L', 'B', '6', '4', 0,
  /* 562 */ 'S', 'B', '6', '4', 0,
  /* 567 */ 'A', 'N', 'D', '6', '4', 0,
  /* 573 */ 'M', 'O', 'V', 'N', '_', 'I', '6', '4', '_', 'D', '6', '4', 0,
  /* 586 */ 'M', 'O', 'V', 'Z', '_', 'I', '6', '4', '_', 'D', '6', '4', 0,
  /* 599 */ 'F', 'S', 'U', 'B', '_', 'D', '6', '4', 0,
  /* 608 */ 'N', 'M', 'S', 'U', 'B', '_', 'D', '6', '4', 0,
  /* 618 */ 'F', 'A', 'D', 'D', '_', 'D', '6', '4', 0,
  /* 627 */ 'N', 'M', 'A', 'D', 'D', '_', 'D', '6', '4', 0,
  /* 637 */ 'M', 'O', 'V', 'F', '_', 'D', '6', '4', 0,
  /* 646 */ 'F', 'N', 'E', 'G', '_', 'D', '6', '4', 0,
  /* 655 */ 'M', 'O', 'V', 'N', '_', 'I', '_', 'D', '6', '4', 0,
  /* 666 */ 'M', 'O', 'V', 'Z', '_', 'I', '_', 'D', '6', '4', 0,
  /* 677 */ 'F', 'M', 'U', 'L', '_', 'D', '6', '4', 0,
  /* 686 */ 'T', 'R', 'U', 'N', 'C', '_', 'L', '_', 'D', '6', '4', 0,
  /* 698 */ 'R', 'O', 'U', 'N', 'D', '_', 'L', '_', 'D', '6', '4', 0,
  /* 710 */ 'C', 'E', 'I', 'L', '_', 'L', '_', 'D', '6', '4', 0,
  /* 721 */ 'F', 'L', 'O', 'O', 'R', '_', 'L', '_', 'D', '6', '4', 0,
  /* 733 */ 'C', 'V', 'T', '_', 'L', '_', 'D', '6', '4', 0,
  /* 743 */ 'F', 'C', 'M', 'P', '_', 'D', '6', '4', 0,
  /* 752 */ 'F', 'A', 'B', 'S', '_', 'D', '6', '4', 0,
  /* 761 */ 'C', 'V', 'T', '_', 'S', '_', 'D', '6', '4', 0,
  /* 771 */ 'F', 'S', 'Q', 'R', 'T', '_', 'D', '6', '4', 0,
  /* 781 */ 'M', 'O', 'V', 'T', '_', 'D', '6', '4', 0,
  /* 790 */ 'F', 'D', 'I', 'V', '_', 'D', '6', '4', 0,
  /* 799 */ 'F', 'M', 'O', 'V', '_', 'D', '6', '4', 0,
  /* 808 */ 'T', 'R', 'U', 'N', 'C', '_', 'W', '_', 'D', '6', '4', 0,
  /* 820 */ 'R', 'O', 'U', 'N', 'D', '_', 'W', '_', 'D', '6', '4', 0,
  /* 832 */ 'C', 'E', 'I', 'L', '_', 'W', '_', 'D', '6', '4', 0,
  /* 843 */ 'F', 'L', 'O', 'O', 'R', '_', 'W', '_', 'D', '6', '4', 0,
  /* 855 */ 'C', 'V', 'T', '_', 'W', '_', 'D', '6', '4', 0,
  /* 865 */ 'B', 'N', 'E', '6', '4', 0,
  /* 871 */ 'B', 'u', 'i', 'l', 'd', 'P', 'a', 'i', 'r', 'F', '6', '4', 0,
  /* 884 */ 'E', 'x', 't', 'r', 'a', 'c', 't', 'E', 'l', 'e', 'm', 'e', 'n', 't', 'F', '6', '4', 0,
  /* 902 */ 'S', 'E', 'H', '6', '4', 0,
  /* 908 */ 'L', 'H', '6', '4', 0,
  /* 913 */ 'S', 'H', '6', '4', 0,
  /* 918 */ 'M', 'F', 'H', 'I', '6', '4', 0,
  /* 925 */ 'M', 'T', 'H', 'I', '6', '4', 0,
  /* 932 */ 'M', 'O', 'V', 'N', '_', 'I', '6', '4', '_', 'I', '6', '4', 0,
  /* 945 */ 'M', 'O', 'V', 'Z', '_', 'I', '6', '4', '_', 'I', '6', '4', 0,
  /* 958 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '6', '4', 0,
  /* 978 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '6', '4', 0,
  /* 998 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '6', '4', 0,
  /* 1019 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '6', '4', 0,
  /* 1039 */ 'M', 'O', 'V', 'F', '_', 'I', '6', '4', 0,
  /* 1048 */ 'M', 'O', 'V', 'N', '_', 'I', '_', 'I', '6', '4', 0,
  /* 1059 */ 'M', 'O', 'V', 'Z', '_', 'I', '_', 'I', '6', '4', 0,
  /* 1070 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '6', '4', 0,
  /* 1086 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '6', '4', 0,
  /* 1106 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '6', '4', 0,
  /* 1126 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '6', '4', 0,
  /* 1145 */ 'M', 'O', 'V', 'T', '_', 'I', '6', '4', 0,
  /* 1154 */ 'L', 'W', 'L', '6', '4', 0,
  /* 1160 */ 'S', 'W', 'L', '6', '4', 0,
  /* 1166 */ 'M', 'F', 'L', 'O', '6', '4', 0,
  /* 1173 */ 'M', 'T', 'L', 'O', '6', '4', 0,
  /* 1180 */ 'D', 'M', 'F', 'C', '0', '_', '3', 'O', 'P', '6', '4', 0,
  /* 1192 */ 'D', 'M', 'T', 'C', '0', '_', '3', 'O', 'P', '6', '4', 0,
  /* 1204 */ 'D', 'M', 'F', 'C', '2', '_', '3', 'O', 'P', '6', '4', 0,
  /* 1216 */ 'D', 'M', 'T', 'C', '2', '_', '3', 'O', 'P', '6', '4', 0,
  /* 1228 */ 'B', 'E', 'Q', '6', '4', 0,
  /* 1234 */ 'J', 'R', '6', '4', 0,
  /* 1239 */ 'J', 'A', 'L', 'R', '6', '4', 0,
  /* 1246 */ 'N', 'O', 'R', '6', '4', 0,
  /* 1252 */ 'X', 'O', 'R', '6', '4', 0,
  /* 1258 */ 'R', 'D', 'H', 'W', 'R', '6', '4', 0,
  /* 1266 */ 'L', 'W', 'R', '6', '4', 0,
  /* 1272 */ 'S', 'W', 'R', '6', '4', 0,
  /* 1278 */ 'S', 'L', 'T', '6', '4', 0,
  /* 1284 */ 'L', 'W', '6', '4', 0,
  /* 1289 */ 'S', 'W', '6', '4', 0,
  /* 1294 */ 'B', 'G', 'E', 'Z', '6', '4', 0,
  /* 1301 */ 'B', 'L', 'E', 'Z', '6', '4', 0,
  /* 1308 */ 'B', 'G', 'T', 'Z', '6', '4', 0,
  /* 1315 */ 'B', 'L', 'T', 'Z', '6', '4', 0,
  /* 1322 */ 'S', 'L', 'L', '6', '4', '_', '6', '4', 0,
  /* 1331 */ 'X', 'O', 'R', 'i', '6', '4', 0,
  /* 1338 */ 'S', 'L', 'T', 'i', '6', '4', 0,
  /* 1345 */ 'L', 'U', 'i', '6', '4', 0,
  /* 1351 */ 'L', 'B', 'u', '6', '4', 0,
  /* 1357 */ 'L', 'H', 'u', '6', '4', 0,
  /* 1363 */ 'S', 'L', 'T', 'u', '6', '4', 0,
  /* 1370 */ 'L', 'W', 'u', '6', '4', 0,
  /* 1376 */ 'L', 'E', 'A', '_', 'A', 'D', 'D', 'i', 'u', '6', '4', 0,
  /* 1388 */ 'S', 'L', 'T', 'i', 'u', '6', '4', 0,
  /* 1396 */ 'M', 'o', 'v', 'e', 'R', '3', '2', '1', '6', 0,
  /* 1406 */ 'R', 'e', 't', 'R', 'A', '1', '6', 0,
  /* 1414 */ 'R', 'e', 's', 't', 'o', 'r', 'e', 'R', 'a', 'F', '1', '6', 0,
  /* 1427 */ 'S', 'a', 'v', 'e', 'R', 'a', 'F', '1', '6', 0,
  /* 1437 */ 'S', 'a', 'v', 'e', 'D', 'e', 'c', 'S', 'p', 'F', '1', '6', 0,
  /* 1450 */ 'R', 'e', 's', 't', 'o', 'r', 'e', 'I', 'n', 'c', 'S', 'p', 'F', '1', '6', 0,
  /* 1466 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '1', '6', 0,
  /* 1486 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '1', '6', 0,
  /* 1506 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '1', '6', 0,
  /* 1527 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '1', '6', 0,
  /* 1547 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '1', '6', 0,
  /* 1563 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '1', '6', 0,
  /* 1583 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '1', '6', 0,
  /* 1603 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '1', '6', 0,
  /* 1622 */ 'M', 'o', 'v', 'e', '3', '2', 'R', '1', '6', 0,
  /* 1632 */ 'S', 'r', 'a', 'X', '1', '6', 0,
  /* 1639 */ 'B', 't', 'n', 'e', 'z', 'T', '8', 'C', 'm', 'p', 'i', 'X', '1', '6', 0,
  /* 1654 */ 'B', 't', 'e', 'q', 'z', 'T', '8', 'C', 'm', 'p', 'i', 'X', '1', '6', 0,
  /* 1669 */ 'B', 't', 'n', 'e', 'z', 'T', '8', 'S', 'l', 't', 'i', 'X', '1', '6', 0,
  /* 1684 */ 'B', 't', 'e', 'q', 'z', 'T', '8', 'S', 'l', 't', 'i', 'X', '1', '6', 0,
  /* 1699 */ 'S', 'l', 'l', 'X', '1', '6', 0,
  /* 1706 */ 'S', 'r', 'l', 'X', '1', '6', 0,
  /* 1713 */ 'L', 'b', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1729 */ 'S', 'b', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1745 */ 'L', 'h', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1761 */ 'S', 'h', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1777 */ 'L', 'b', 'u', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1794 */ 'L', 'h', 'u', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1811 */ 'A', 'd', 'd', 'i', 'u', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1830 */ 'L', 'w', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1846 */ 'S', 'w', 'R', 'x', 'R', 'y', 'O', 'f', 'f', 'M', 'e', 'm', 'X', '1', '6', 0,
  /* 1862 */ 'A', 'd', 'd', 'i', 'u', 'R', 'x', 'P', 'c', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1878 */ 'A', 'd', 'd', 'i', 'u', 'S', 'p', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1892 */ 'L', 'w', 'R', 'x', 'S', 'p', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1905 */ 'S', 'w', 'R', 'x', 'S', 'p', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1918 */ 'S', 'l', 't', 'i', 'C', 'C', 'R', 'x', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1933 */ 'S', 'l', 't', 'i', 'u', 'C', 'C', 'R', 'x', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1949 */ 'L', 'i', 'R', 'x', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1960 */ 'A', 'd', 'd', 'i', 'u', 'R', 'x', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1974 */ 'A', 'd', 'd', 'i', 'u', 'R', 'x', 'R', 'x', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 1990 */ 'B', 'n', 'e', 'z', 'R', 'x', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 2003 */ 'B', 'e', 'q', 'z', 'R', 'x', 'I', 'm', 'm', 'X', '1', '6', 0,
  /* 2016 */ 'B', 'i', 'm', 'm', 'X', '1', '6', 0,
  /* 2024 */ 'B', 't', 'n', 'e', 'z', 'T', '8', 'C', 'm', 'p', 'X', '1', '6', 0,
  /* 2038 */ 'B', 't', 'e', 'q', 'z', 'T', '8', 'C', 'm', 'p', 'X', '1', '6', 0,
  /* 2052 */ 'B', 't', 'n', 'e', 'z', 'T', '8', 'S', 'l', 't', 'X', '1', '6', 0,
  /* 2066 */ 'B', 't', 'e', 'q', 'z', 'T', '8', 'S', 'l', 't', 'X', '1', '6', 0,
  /* 2080 */ 'B', 't', 'n', 'e', 'z', 'T', '8', 'S', 'l', 't', 'i', 'u', 'X', '1', '6', 0,
  /* 2096 */ 'B', 't', 'e', 'q', 'z', 'T', '8', 'S', 'l', 't', 'i', 'u', 'X', '1', '6', 0,
  /* 2112 */ 'B', 't', 'n', 'e', 'z', 'T', '8', 'S', 'l', 't', 'u', 'X', '1', '6', 0,
  /* 2127 */ 'B', 't', 'e', 'q', 'z', 'T', '8', 'S', 'l', 't', 'u', 'X', '1', '6', 0,
  /* 2142 */ 'B', 't', 'n', 'e', 'z', 'X', '1', '6', 0,
  /* 2151 */ 'B', 't', 'e', 'q', 'z', 'X', '1', '6', 0,
  /* 2160 */ 'J', 'r', 'c', 'R', 'a', '1', '6', 0,
  /* 2168 */ 'J', 'r', 'R', 'a', '1', '6', 0,
  /* 2175 */ 'J', 'u', 'm', 'p', 'L', 'i', 'n', 'k', 'R', 'e', 'g', '1', '6', 0,
  /* 2189 */ 'M', 'f', 'h', 'i', '1', '6', 0,
  /* 2196 */ 'M', 'f', 'l', 'o', '1', '6', 0,
  /* 2203 */ 'J', 'r', 'c', 'R', 'x', '1', '6', 0,
  /* 2211 */ 'S', 'l', 't', 'C', 'C', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2223 */ 'S', 'l', 't', 'u', 'C', 'C', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2236 */ 'N', 'e', 'g', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2246 */ 'S', 'l', 't', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2256 */ 'M', 'u', 'l', 't', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2267 */ 'N', 'o', 't', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2277 */ 'M', 'u', 'l', 't', 'u', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2289 */ 'D', 'i', 'v', 'u', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2300 */ 'S', 'r', 'a', 'v', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2311 */ 'D', 'i', 'v', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2321 */ 'S', 'l', 'l', 'v', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2332 */ 'S', 'r', 'l', 'v', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2343 */ 'A', 'n', 'd', 'R', 'x', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2355 */ 'O', 'r', 'R', 'x', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2366 */ 'X', 'o', 'r', 'R', 'x', 'R', 'x', 'R', 'y', '1', '6', 0,
  /* 2378 */ 'M', 'u', 'l', 't', 'R', 'x', 'R', 'y', 'R', 'z', '1', '6', 0,
  /* 2391 */ 'S', 'u', 'b', 'u', 'R', 'x', 'R', 'y', 'R', 'z', '1', '6', 0,
  /* 2404 */ 'A', 'd', 'd', 'u', 'R', 'x', 'R', 'y', 'R', 'z', '1', '6', 0,
  /* 2417 */ 'S', 'l', 't', 'u', 'R', 'x', 'R', 'y', 'R', 'z', '1', '6', 0,
  /* 2430 */ 'M', 'u', 'l', 't', 'u', 'R', 'x', 'R', 'y', 'R', 'z', '1', '6', 0,
  /* 2444 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '8', 0,
  /* 2463 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '8', 0,
  /* 2482 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '8', 0,
  /* 2502 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '8', 0,
  /* 2521 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '8', 0,
  /* 2536 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '8', 0,
  /* 2555 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '8', 0,
  /* 2574 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '8', 0,
  /* 2592 */ 'L', 'W', 'C', '1', '_', 'P', '8', 0,
  /* 2600 */ 'S', 'W', 'C', '1', '_', 'P', '8', 0,
  /* 2608 */ 'L', 'W', 'X', 'C', '1', '_', 'P', '8', 0,
  /* 2617 */ 'S', 'W', 'X', 'C', '1', '_', 'P', '8', 0,
  /* 2626 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2649 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2672 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2696 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2719 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2738 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2761 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2784 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '3', '2', '_', 'P', '8', 0,
  /* 2806 */ 'L', 'D', 'C', '1', '6', '4', '_', 'P', '8', 0,
  /* 2816 */ 'S', 'D', 'C', '1', '6', '4', '_', 'P', '8', 0,
  /* 2826 */ 'L', 'D', 'X', 'C', '1', '6', '4', '_', 'P', '8', 0,
  /* 2837 */ 'S', 'D', 'X', 'C', '1', '6', '4', '_', 'P', '8', 0,
  /* 2848 */ 'L', 'B', '6', '4', '_', 'P', '8', 0,
  /* 2856 */ 'S', 'B', '6', '4', '_', 'P', '8', 0,
  /* 2864 */ 'L', 'H', '6', '4', '_', 'P', '8', 0,
  /* 2872 */ 'S', 'H', '6', '4', '_', 'P', '8', 0,
  /* 2880 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 2903 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 2926 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 2950 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 2973 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 2992 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 3015 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 3038 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '6', '4', '_', 'P', '8', 0,
  /* 3060 */ 'L', 'W', 'L', '6', '4', '_', 'P', '8', 0,
  /* 3069 */ 'S', 'W', 'L', '6', '4', '_', 'P', '8', 0,
  /* 3078 */ 'L', 'W', 'R', '6', '4', '_', 'P', '8', 0,
  /* 3087 */ 'S', 'W', 'R', '6', '4', '_', 'P', '8', 0,
  /* 3096 */ 'L', 'W', '6', '4', '_', 'P', '8', 0,
  /* 3104 */ 'S', 'W', '6', '4', '_', 'P', '8', 0,
  /* 3112 */ 'L', 'B', 'u', '6', '4', '_', 'P', '8', 0,
  /* 3121 */ 'L', 'H', 'u', '6', '4', '_', 'P', '8', 0,
  /* 3130 */ 'L', 'W', 'u', '6', '4', '_', 'P', '8', 0,
  /* 3139 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3162 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3185 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3209 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3232 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3251 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3274 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3297 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '1', '6', '_', 'P', '8', 0,
  /* 3319 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3341 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3363 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3386 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3408 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3426 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3448 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3470 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '8', '_', 'P', '8', 0,
  /* 3491 */ 'L', 'B', '_', 'P', '8', 0,
  /* 3497 */ 'S', 'B', '_', 'P', '8', 0,
  /* 3503 */ 'S', 'C', '_', 'P', '8', 0,
  /* 3509 */ 'S', 'C', 'D', '_', 'P', '8', 0,
  /* 3516 */ 'L', 'L', 'D', '_', 'P', '8', 0,
  /* 3523 */ 'S', 'D', '_', 'P', '8', 0,
  /* 3529 */ 'L', 'H', '_', 'P', '8', 0,
  /* 3535 */ 'S', 'H', '_', 'P', '8', 0,
  /* 3541 */ 'L', 'D', 'L', '_', 'P', '8', 0,
  /* 3548 */ 'S', 'D', 'L', '_', 'P', '8', 0,
  /* 3555 */ 'L', 'L', '_', 'P', '8', 0,
  /* 3561 */ 'L', 'W', 'L', '_', 'P', '8', 0,
  /* 3568 */ 'S', 'W', 'L', '_', 'P', '8', 0,
  /* 3575 */ 'L', 'D', 'R', '_', 'P', '8', 0,
  /* 3582 */ 'S', 'D', 'R', '_', 'P', '8', 0,
  /* 3589 */ 'L', 'W', 'R', '_', 'P', '8', 0,
  /* 3596 */ 'S', 'W', 'R', '_', 'P', '8', 0,
  /* 3603 */ 'L', 'W', '_', 'P', '8', 0,
  /* 3609 */ 'S', 'W', '_', 'P', '8', 0,
  /* 3615 */ 'L', 'B', 'u', '_', 'P', '8', 0,
  /* 3622 */ 'L', 'H', 'u', '_', 'P', '8', 0,
  /* 3629 */ 'P', 'R', 'E', 'C', 'E', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'L', 'A', 0,
  /* 3644 */ 'P', 'R', 'E', 'C', 'E', 'Q', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'L', 'A', 0,
  /* 3660 */ 'P', 'R', 'E', 'C', 'E', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'R', 'A', 0,
  /* 3675 */ 'P', 'R', 'E', 'C', 'E', 'Q', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'R', 'A', 0,
  /* 3691 */ 'D', 'S', 'R', 'A', 0,
  /* 3696 */ 'R', 'e', 't', 'R', 'A', 0,
  /* 3702 */ 'S', 'E', 'B', 0,
  /* 3706 */ 'L', 'B', 0,
  /* 3709 */ 'S', 'H', 'R', 'A', '_', 'Q', 'B', 0,
  /* 3717 */ 'C', 'M', 'P', 'G', 'D', 'U', '_', 'L', 'E', '_', 'Q', 'B', 0,
  /* 3730 */ 'C', 'M', 'P', 'G', 'U', '_', 'L', 'E', '_', 'Q', 'B', 0,
  /* 3742 */ 'C', 'M', 'P', 'U', '_', 'L', 'E', '_', 'Q', 'B', 0,
  /* 3753 */ 'S', 'U', 'B', 'U', 'H', '_', 'Q', 'B', 0,
  /* 3762 */ 'A', 'D', 'D', 'U', 'H', '_', 'Q', 'B', 0,
  /* 3771 */ 'P', 'I', 'C', 'K', '_', 'Q', 'B', 0,
  /* 3779 */ 'S', 'H', 'L', 'L', '_', 'Q', 'B', 0,
  /* 3787 */ 'R', 'E', 'P', 'L', '_', 'Q', 'B', 0,
  /* 3795 */ 'S', 'H', 'R', 'L', '_', 'Q', 'B', 0,
  /* 3803 */ 'C', 'M', 'P', 'G', 'D', 'U', '_', 'E', 'Q', '_', 'Q', 'B', 0,
  /* 3816 */ 'C', 'M', 'P', 'G', 'U', '_', 'E', 'Q', '_', 'Q', 'B', 0,
  /* 3828 */ 'C', 'M', 'P', 'U', '_', 'E', 'Q', '_', 'Q', 'B', 0,
  /* 3839 */ 'S', 'H', 'R', 'A', '_', 'R', '_', 'Q', 'B', 0,
  /* 3849 */ 'S', 'U', 'B', 'U', 'H', '_', 'R', '_', 'Q', 'B', 0,
  /* 3860 */ 'A', 'D', 'D', 'U', 'H', '_', 'R', '_', 'Q', 'B', 0,
  /* 3871 */ 'S', 'H', 'R', 'A', 'V', '_', 'R', '_', 'Q', 'B', 0,
  /* 3882 */ 'A', 'B', 'S', 'Q', '_', 'S', '_', 'Q', 'B', 0,
  /* 3892 */ 'S', 'U', 'B', 'U', '_', 'S', '_', 'Q', 'B', 0,
  /* 3902 */ 'A', 'D', 'D', 'U', '_', 'S', '_', 'Q', 'B', 0,
  /* 3912 */ 'C', 'M', 'P', 'G', 'D', 'U', '_', 'L', 'T', '_', 'Q', 'B', 0,
  /* 3925 */ 'C', 'M', 'P', 'G', 'U', '_', 'L', 'T', '_', 'Q', 'B', 0,
  /* 3937 */ 'C', 'M', 'P', 'U', '_', 'L', 'T', '_', 'Q', 'B', 0,
  /* 3948 */ 'S', 'U', 'B', 'U', '_', 'Q', 'B', 0,
  /* 3956 */ 'A', 'D', 'D', 'U', '_', 'Q', 'B', 0,
  /* 3964 */ 'S', 'H', 'R', 'A', 'V', '_', 'Q', 'B', 0,
  /* 3973 */ 'S', 'H', 'L', 'L', 'V', '_', 'Q', 'B', 0,
  /* 3982 */ 'R', 'E', 'P', 'L', 'V', '_', 'Q', 'B', 0,
  /* 3991 */ 'S', 'H', 'R', 'L', 'V', '_', 'Q', 'B', 0,
  /* 4000 */ 'R', 'A', 'D', 'D', 'U', '_', 'W', '_', 'Q', 'B', 0,
  /* 4011 */ 'S', 'B', 0,
  /* 4014 */ 'M', 'O', 'D', 'S', 'U', 'B', 0,
  /* 4021 */ 'M', 'S', 'U', 'B', 0,
  /* 4026 */ 'S', 'Y', 'N', 'C', 0,
  /* 4031 */ 'A', 'D', 'D', 'S', 'C', 0,
  /* 4037 */ 'A', 'D', 'D', 'W', 'C', 0,
  /* 4043 */ 'S', 'C', 'D', 0,
  /* 4047 */ 'D', 'A', 'D', 'D', 0,
  /* 4052 */ 'M', 'A', 'D', 'D', 0,
  /* 4057 */ 'D', 'S', 'H', 'D', 0,
  /* 4062 */ 'L', 'L', 'D', 0,
  /* 4066 */ 'A', 'N', 'D', 0,
  /* 4070 */ 'P', 'R', 'E', 'P', 'E', 'N', 'D', 0,
  /* 4078 */ 'A', 'P', 'P', 'E', 'N', 'D', 0,
  /* 4085 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'E', 'N', 'D', 0,
  /* 4098 */ 'S', 'D', 0,
  /* 4101 */ 'R', 'E', 'G', '_', 'S', 'E', 'Q', 'U', 'E', 'N', 'C', 'E', 0,
  /* 4114 */ 'B', 'U', 'N', 'D', 'L', 'E', 0,
  /* 4121 */ 'B', 'N', 'E', 0,
  /* 4125 */ 'D', 'B', 'G', '_', 'V', 'A', 'L', 'U', 'E', 0,
  /* 4135 */ 'B', 'C', '1', 'F', 0,
  /* 4140 */ 'I', 'M', 'P', 'L', 'I', 'C', 'I', 'T', '_', 'D', 'E', 'F', 0,
  /* 4153 */ 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 4168 */ 'I', 'N', 'S', 'E', 'R', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 4182 */ 'S', 'U', 'B', 'R', 'E', 'G', '_', 'T', 'O', '_', 'R', 'E', 'G', 0,
  /* 4196 */ 'D', 'S', 'B', 'H', 0,
  /* 4201 */ 'W', 'S', 'B', 'H', 0,
  /* 4206 */ 'S', 'E', 'H', 0,
  /* 4210 */ 'L', 'H', 0,
  /* 4213 */ 'S', 'H', 'R', 'A', '_', 'P', 'H', 0,
  /* 4221 */ 'P', 'R', 'E', 'C', 'R', 'Q', '_', 'Q', 'B', '_', 'P', 'H', 0,
  /* 4234 */ 'P', 'R', 'E', 'C', 'R', '_', 'Q', 'B', '_', 'P', 'H', 0,
  /* 4246 */ 'P', 'R', 'E', 'C', 'R', 'Q', 'U', '_', 'S', '_', 'Q', 'B', '_', 'P', 'H', 0,
  /* 4262 */ 'C', 'M', 'P', '_', 'L', 'E', '_', 'P', 'H', 0,
  /* 4272 */ 'S', 'U', 'B', 'Q', 'H', '_', 'P', 'H', 0,
  /* 4281 */ 'A', 'D', 'D', 'Q', 'H', '_', 'P', 'H', 0,
  /* 4290 */ 'P', 'I', 'C', 'K', '_', 'P', 'H', 0,
  /* 4298 */ 'S', 'H', 'L', 'L', '_', 'P', 'H', 0,
  /* 4306 */ 'R', 'E', 'P', 'L', '_', 'P', 'H', 0,
  /* 4314 */ 'S', 'H', 'R', 'L', '_', 'P', 'H', 0,
  /* 4322 */ 'P', 'A', 'C', 'K', 'R', 'L', '_', 'P', 'H', 0,
  /* 4332 */ 'M', 'U', 'L', '_', 'P', 'H', 0,
  /* 4339 */ 'S', 'U', 'B', 'Q', '_', 'P', 'H', 0,
  /* 4347 */ 'A', 'D', 'D', 'Q', '_', 'P', 'H', 0,
  /* 4355 */ 'C', 'M', 'P', '_', 'E', 'Q', '_', 'P', 'H', 0,
  /* 4365 */ 'S', 'H', 'R', 'A', '_', 'R', '_', 'P', 'H', 0,
  /* 4375 */ 'S', 'U', 'B', 'Q', 'H', '_', 'R', '_', 'P', 'H', 0,
  /* 4386 */ 'A', 'D', 'D', 'Q', 'H', '_', 'R', '_', 'P', 'H', 0,
  /* 4397 */ 'S', 'H', 'R', 'A', 'V', '_', 'R', '_', 'P', 'H', 0,
  /* 4408 */ 'M', 'U', 'L', 'Q', '_', 'R', 'S', '_', 'P', 'H', 0,
  /* 4419 */ 'S', 'H', 'L', 'L', '_', 'S', '_', 'P', 'H', 0,
  /* 4429 */ 'M', 'U', 'L', '_', 'S', '_', 'P', 'H', 0,
  /* 4438 */ 'S', 'U', 'B', 'Q', '_', 'S', '_', 'P', 'H', 0,
  /* 4448 */ 'A', 'D', 'D', 'Q', '_', 'S', '_', 'P', 'H', 0,
  /* 4458 */ 'M', 'U', 'L', 'Q', '_', 'S', '_', 'P', 'H', 0,
  /* 4468 */ 'A', 'B', 'S', 'Q', '_', 'S', '_', 'P', 'H', 0,
  /* 4478 */ 'S', 'U', 'B', 'U', '_', 'S', '_', 'P', 'H', 0,
  /* 4488 */ 'A', 'D', 'D', 'U', '_', 'S', '_', 'P', 'H', 0,
  /* 4498 */ 'S', 'H', 'L', 'L', 'V', '_', 'S', '_', 'P', 'H', 0,
  /* 4509 */ 'C', 'M', 'P', '_', 'L', 'T', '_', 'P', 'H', 0,
  /* 4519 */ 'S', 'U', 'B', 'U', '_', 'P', 'H', 0,
  /* 4527 */ 'A', 'D', 'D', 'U', '_', 'P', 'H', 0,
  /* 4535 */ 'S', 'H', 'R', 'A', 'V', '_', 'P', 'H', 0,
  /* 4544 */ 'S', 'H', 'L', 'L', 'V', '_', 'P', 'H', 0,
  /* 4553 */ 'R', 'E', 'P', 'L', 'V', '_', 'P', 'H', 0,
  /* 4562 */ 'S', 'H', 'R', 'L', 'V', '_', 'P', 'H', 0,
  /* 4571 */ 'D', 'P', 'A', '_', 'W', '_', 'P', 'H', 0,
  /* 4580 */ 'M', 'U', 'L', 'S', 'A', '_', 'W', '_', 'P', 'H', 0,
  /* 4591 */ 'D', 'P', 'A', 'Q', 'X', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', 0,
  /* 4605 */ 'D', 'P', 'S', 'Q', 'X', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', 0,
  /* 4619 */ 'D', 'P', 'S', '_', 'W', '_', 'P', 'H', 0,
  /* 4628 */ 'D', 'P', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 0,
  /* 4640 */ 'M', 'U', 'L', 'S', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 0,
  /* 4654 */ 'D', 'P', 'S', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 0,
  /* 4666 */ 'D', 'P', 'A', 'Q', 'X', '_', 'S', '_', 'W', '_', 'P', 'H', 0,
  /* 4679 */ 'D', 'P', 'S', 'Q', 'X', '_', 'S', '_', 'W', '_', 'P', 'H', 0,
  /* 4692 */ 'D', 'P', 'A', 'X', '_', 'W', '_', 'P', 'H', 0,
  /* 4702 */ 'D', 'P', 'S', 'X', '_', 'W', '_', 'P', 'H', 0,
  /* 4712 */ 'S', 'H', 0,
  /* 4715 */ 'E', 'X', 'T', 'R', '_', 'S', '_', 'H', 0,
  /* 4724 */ 'E', 'X', 'T', 'R', 'V', '_', 'S', '_', 'H', 0,
  /* 4734 */ 'M', 'F', 'H', 'I', 0,
  /* 4739 */ 'P', 'H', 'I', 0,
  /* 4743 */ 'M', 'T', 'H', 'I', 0,
  /* 4748 */ 'M', 'O', 'V', 'N', '_', 'I', '6', '4', '_', 'I', 0,
  /* 4759 */ 'M', 'O', 'V', 'Z', '_', 'I', '6', '4', '_', 'I', 0,
  /* 4770 */ 'M', 'O', 'V', 'F', '_', 'I', 0,
  /* 4777 */ 'M', 'O', 'V', 'N', '_', 'I', '_', 'I', 0,
  /* 4786 */ 'M', 'O', 'V', 'Z', '_', 'I', '_', 'I', 0,
  /* 4795 */ 'M', 'O', 'V', 'T', '_', 'I', 0,
  /* 4802 */ 'J', 0,
  /* 4804 */ 'J', 'A', 'L', 0,
  /* 4808 */ 'B', 'G', 'E', 'Z', 'A', 'L', 0,
  /* 4815 */ 'B', 'L', 'T', 'Z', 'A', 'L', 0,
  /* 4822 */ 'M', 'U', 'L', 'E', 'U', '_', 'S', '_', 'P', 'H', '_', 'Q', 'B', 'L', 0,
  /* 4837 */ 'P', 'R', 'E', 'C', 'E', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'L', 0,
  /* 4851 */ 'P', 'R', 'E', 'C', 'E', 'Q', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'L', 0,
  /* 4866 */ 'D', 'P', 'A', 'U', '_', 'H', '_', 'Q', 'B', 'L', 0,
  /* 4877 */ 'D', 'P', 'S', 'U', '_', 'H', '_', 'Q', 'B', 'L', 0,
  /* 4888 */ 'L', 'D', 'L', 0,
  /* 4892 */ 'S', 'D', 'L', 0,
  /* 4896 */ 'G', 'C', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 4905 */ 'P', 'R', 'O', 'L', 'O', 'G', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 4918 */ 'E', 'H', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 4927 */ 'M', 'A', 'Q', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', 'L', 0,
  /* 4940 */ 'P', 'R', 'E', 'C', 'E', 'Q', '_', 'W', '_', 'P', 'H', 'L', 0,
  /* 4953 */ 'M', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 'L', 0,
  /* 4965 */ 'M', 'U', 'L', 'E', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 'L', 0,
  /* 4979 */ 'T', 'A', 'I', 'L', 'C', 'A', 'L', 'L', 0,
  /* 4988 */ 'K', 'I', 'L', 'L', 0,
  /* 4993 */ 'D', 'S', 'L', 'L', 0,
  /* 4998 */ 'D', 'S', 'R', 'L', 0,
  /* 5003 */ 'M', 'U', 'L', 0,
  /* 5007 */ 'L', 'W', 'L', 0,
  /* 5011 */ 'S', 'W', 'L', 0,
  /* 5015 */ 'C', 'V', 'T', '_', 'D', '6', '4', '_', 'L', 0,
  /* 5025 */ 'C', 'V', 'T', '_', 'S', '_', 'L', 0,
  /* 5033 */ 'I', 'N', 'L', 'I', 'N', 'E', 'A', 'S', 'M', 0,
  /* 5043 */ 'D', 'I', 'N', 'S', 'M', 0,
  /* 5049 */ 'D', 'E', 'X', 'T', 'M', 0,
  /* 5055 */ 'B', 'A', 'L', 'I', 'G', 'N', 0,
  /* 5062 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'D', 'O', 'W', 'N', 0,
  /* 5079 */ 'B', 'P', 'O', 'S', 'G', 'E', '3', '2', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5095 */ 'D', 'P', 'A', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5111 */ 'M', 'U', 'L', 'S', 'A', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5129 */ 'D', 'P', 'A', 'Q', 'X', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5150 */ 'D', 'P', 'S', 'Q', 'X', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5171 */ 'D', 'P', 'S', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5187 */ 'D', 'P', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5206 */ 'M', 'U', 'L', 'S', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5227 */ 'D', 'P', 'S', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5246 */ 'D', 'P', 'A', 'Q', 'X', '_', 'S', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5266 */ 'D', 'P', 'S', 'Q', 'X', '_', 'S', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5286 */ 'D', 'P', 'A', 'X', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5303 */ 'D', 'P', 'S', 'X', '_', 'W', '_', 'P', 'H', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5320 */ 'D', 'P', 'A', 'U', '_', 'H', '_', 'Q', 'B', 'L', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5338 */ 'D', 'P', 'S', 'U', '_', 'H', '_', 'Q', 'B', 'L', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5356 */ 'M', 'A', 'Q', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', 'L', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5376 */ 'M', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 'L', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5395 */ 'S', 'H', 'I', 'L', 'O', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5408 */ 'M', 'T', 'H', 'L', 'I', 'P', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5422 */ 'M', 'S', 'U', 'B', '_', 'D', 'S', 'P', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5438 */ 'M', 'A', 'D', 'D', '_', 'D', 'S', 'P', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5454 */ 'M', 'U', 'L', 'T', '_', 'D', 'S', 'P', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5470 */ 'M', 'S', 'U', 'B', 'U', '_', 'D', 'S', 'P', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5487 */ 'M', 'A', 'D', 'D', 'U', '_', 'D', 'S', 'P', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5504 */ 'M', 'U', 'L', 'T', 'U', '_', 'D', 'S', 'P', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5521 */ 'D', 'P', 'A', 'U', '_', 'H', '_', 'Q', 'B', 'R', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5539 */ 'D', 'P', 'S', 'U', '_', 'H', '_', 'Q', 'B', 'R', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5557 */ 'M', 'A', 'Q', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', 'R', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5577 */ 'M', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 'R', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5596 */ 'S', 'H', 'I', 'L', 'O', 'V', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5610 */ 'D', 'P', 'A', 'Q', '_', 'S', 'A', '_', 'L', '_', 'W', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5629 */ 'D', 'P', 'S', 'Q', '_', 'S', 'A', '_', 'L', '_', 'W', '_', 'P', 'S', 'E', 'U', 'D', 'O', 0,
  /* 5648 */ 'D', 'C', 'L', 'O', 0,
  /* 5653 */ 'M', 'F', 'L', 'O', 0,
  /* 5658 */ 'S', 'H', 'I', 'L', 'O', 0,
  /* 5664 */ 'M', 'T', 'L', 'O', 0,
  /* 5669 */ 'E', 'X', 'T', 'P', 'D', 'P', 0,
  /* 5676 */ 'M', 'T', 'H', 'L', 'I', 'P', 0,
  /* 5683 */ 'M', 'F', 'C', '0', '_', '3', 'O', 'P', 0,
  /* 5692 */ 'M', 'T', 'C', '0', '_', '3', 'O', 'P', 0,
  /* 5701 */ 'M', 'F', 'C', '2', '_', '3', 'O', 'P', 0,
  /* 5710 */ 'M', 'T', 'C', '2', '_', '3', 'O', 'P', 0,
  /* 5719 */ 'N', 'O', 'P', 0,
  /* 5723 */ 'R', 'D', 'D', 'S', 'P', 0,
  /* 5729 */ 'W', 'R', 'D', 'S', 'P', 0,
  /* 5735 */ 'M', 'S', 'U', 'B', '_', 'D', 'S', 'P', 0,
  /* 5744 */ 'M', 'A', 'D', 'D', '_', 'D', 'S', 'P', 0,
  /* 5753 */ 'M', 'U', 'L', 'T', '_', 'D', 'S', 'P', 0,
  /* 5762 */ 'M', 'S', 'U', 'B', 'U', '_', 'D', 'S', 'P', 0,
  /* 5772 */ 'M', 'A', 'D', 'D', 'U', '_', 'D', 'S', 'P', 0,
  /* 5782 */ 'M', 'U', 'L', 'T', 'U', '_', 'D', 'S', 'P', 0,
  /* 5792 */ 'E', 'X', 'T', 'P', 0,
  /* 5797 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'U', 'P', 0,
  /* 5812 */ 'B', 'E', 'Q', 0,
  /* 5816 */ 'M', 'U', 'L', 'E', 'U', '_', 'S', '_', 'P', 'H', '_', 'Q', 'B', 'R', 0,
  /* 5831 */ 'P', 'R', 'E', 'C', 'E', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'R', 0,
  /* 5845 */ 'P', 'R', 'E', 'C', 'E', 'Q', 'U', '_', 'P', 'H', '_', 'Q', 'B', 'R', 0,
  /* 5860 */ 'D', 'P', 'A', 'U', '_', 'H', '_', 'Q', 'B', 'R', 0,
  /* 5871 */ 'D', 'P', 'S', 'U', '_', 'H', '_', 'Q', 'B', 'R', 0,
  /* 5882 */ 'B', 'A', 'L', '_', 'B', 'R', 0,
  /* 5889 */ 'M', 'O', 'V', 'C', 'C', 'R', 'T', 'o', 'C', 'C', 'R', 0,
  /* 5901 */ 'L', 'D', 'R', 0,
  /* 5905 */ 'S', 'D', 'R', 0,
  /* 5909 */ 'M', 'A', 'Q', '_', 'S', 'A', '_', 'W', '_', 'P', 'H', 'R', 0,
  /* 5922 */ 'P', 'R', 'E', 'C', 'E', 'Q', '_', 'W', '_', 'P', 'H', 'R', 0,
  /* 5935 */ 'M', 'A', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 'R', 0,
  /* 5947 */ 'M', 'U', 'L', 'E', 'Q', '_', 'S', '_', 'W', '_', 'P', 'H', 'R', 0,
  /* 5961 */ 'J', 'R', 0,
  /* 5964 */ 'J', 'A', 'L', 'R', 0,
  /* 5969 */ 'N', 'O', 'R', 0,
  /* 5973 */ 'X', 'O', 'R', 0,
  /* 5977 */ 'D', 'R', 'O', 'T', 'R', 0,
  /* 5983 */ 'R', 'D', 'H', 'W', 'R', 0,
  /* 5989 */ 'L', 'W', 'R', 0,
  /* 5993 */ 'S', 'W', 'R', 0,
  /* 5997 */ 'T', 'A', 'I', 'L', 'C', 'A', 'L', 'L', '6', '4', '_', 'R', 0,
  /* 6010 */ 'T', 'A', 'I', 'L', 'C', 'A', 'L', 'L', '_', 'R', 0,
  /* 6021 */ 'D', 'I', 'N', 'S', 0,
  /* 6026 */ 'C', 'O', 'P', 'Y', '_', 'T', 'O', '_', 'R', 'E', 'G', 'C', 'L', 'A', 'S', 'S', 0,
  /* 6043 */ 'C', 'V', 'T', '_', 'D', '3', '2', '_', 'S', 0,
  /* 6053 */ 'C', 'V', 'T', '_', 'D', '6', '4', '_', 'S', 0,
  /* 6063 */ 'M', 'O', 'V', 'N', '_', 'I', '6', '4', '_', 'S', 0,
  /* 6074 */ 'M', 'O', 'V', 'Z', '_', 'I', '6', '4', '_', 'S', 0,
  /* 6085 */ 'F', 'S', 'U', 'B', '_', 'S', 0,
  /* 6092 */ 'N', 'M', 'S', 'U', 'B', '_', 'S', 0,
  /* 6100 */ 'F', 'A', 'D', 'D', '_', 'S', 0,
  /* 6107 */ 'N', 'M', 'A', 'D', 'D', '_', 'S', 0,
  /* 6115 */ 'M', 'O', 'V', 'F', '_', 'S', 0,
  /* 6122 */ 'F', 'N', 'E', 'G', '_', 'S', 0,
  /* 6129 */ 'M', 'O', 'V', 'N', '_', 'I', '_', 'S', 0,
  /* 6138 */ 'M', 'O', 'V', 'Z', '_', 'I', '_', 'S', 0,
  /* 6147 */ 'F', 'M', 'U', 'L', '_', 'S', 0,
  /* 6154 */ 'T', 'R', 'U', 'N', 'C', '_', 'L', '_', 'S', 0,
  /* 6164 */ 'R', 'O', 'U', 'N', 'D', '_', 'L', '_', 'S', 0,
  /* 6174 */ 'C', 'E', 'I', 'L', '_', 'L', '_', 'S', 0,
  /* 6183 */ 'F', 'L', 'O', 'O', 'R', '_', 'L', '_', 'S', 0,
  /* 6193 */ 'C', 'V', 'T', '_', 'L', '_', 'S', 0,
  /* 6201 */ 'F', 'A', 'B', 'S', '_', 'S', 0,
  /* 6208 */ 'F', 'S', 'Q', 'R', 'T', '_', 'S', 0,
  /* 6216 */ 'M', 'O', 'V', 'T', '_', 'S', 0,
  /* 6223 */ 'F', 'D', 'I', 'V', '_', 'S', 0,
  /* 6230 */ 'F', 'M', 'O', 'V', '_', 'S', 0,
  /* 6237 */ 'T', 'R', 'U', 'N', 'C', '_', 'W', '_', 'S', 0,
  /* 6247 */ 'R', 'O', 'U', 'N', 'D', '_', 'W', '_', 'S', 0,
  /* 6257 */ 'C', 'E', 'I', 'L', '_', 'W', '_', 'S', 0,
  /* 6266 */ 'F', 'L', 'O', 'O', 'R', '_', 'W', '_', 'S', 0,
  /* 6276 */ 'C', 'V', 'T', '_', 'W', '_', 'S', 0,
  /* 6284 */ 'B', 'C', '1', 'T', 0,
  /* 6289 */ 'R', 'E', 'T', 0,
  /* 6293 */ 'S', 'L', 'T', 0,
  /* 6297 */ 'D', 'M', 'U', 'L', 'T', 0,
  /* 6303 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'S', 'T', 'A', 'R', 'T', 0,
  /* 6318 */ 'D', 'E', 'X', 'T', 0,
  /* 6323 */ 'M', 'S', 'U', 'B', 'U', 0,
  /* 6329 */ 'M', 'A', 'D', 'D', 'U', 0,
  /* 6335 */ 'D', 'I', 'N', 'S', 'U', 0,
  /* 6341 */ 'D', 'E', 'X', 'T', 'U', 0,
  /* 6347 */ 'D', 'S', 'R', 'A', 'V', 0,
  /* 6353 */ 'B', 'I', 'T', 'R', 'E', 'V', 0,
  /* 6360 */ 'D', 'S', 'D', 'I', 'V', 0,
  /* 6366 */ 'D', 'U', 'D', 'I', 'V', 0,
  /* 6372 */ 'D', 'S', 'L', 'L', 'V', 0,
  /* 6378 */ 'D', 'S', 'R', 'L', 'V', 0,
  /* 6384 */ 'S', 'H', 'I', 'L', 'O', 'V', 0,
  /* 6391 */ 'E', 'X', 'T', 'P', 'D', 'P', 'V', 0,
  /* 6399 */ 'E', 'X', 'T', 'P', 'V', 0,
  /* 6405 */ 'D', 'R', 'O', 'T', 'R', 'V', 0,
  /* 6412 */ 'I', 'N', 'S', 'V', 0,
  /* 6417 */ 'L', 'W', 0,
  /* 6420 */ 'S', 'W', 0,
  /* 6423 */ 'C', 'V', 'T', '_', 'D', '3', '2', '_', 'W', 0,
  /* 6433 */ 'C', 'V', 'T', '_', 'D', '6', '4', '_', 'W', 0,
  /* 6443 */ 'P', 'R', 'E', 'C', 'R', '_', 'S', 'R', 'A', '_', 'P', 'H', '_', 'W', 0,
  /* 6458 */ 'P', 'R', 'E', 'C', 'R', 'Q', '_', 'P', 'H', '_', 'W', 0,
  /* 6470 */ 'P', 'R', 'E', 'C', 'R', '_', 'S', 'R', 'A', '_', 'R', '_', 'P', 'H', '_', 'W', 0,
  /* 6487 */ 'P', 'R', 'E', 'C', 'R', 'Q', '_', 'R', 'S', '_', 'P', 'H', '_', 'W', 0,
  /* 6502 */ 'S', 'U', 'B', 'Q', 'H', '_', 'W', 0,
  /* 6510 */ 'A', 'D', 'D', 'Q', 'H', '_', 'W', 0,
  /* 6518 */ 'D', 'P', 'A', 'Q', '_', 'S', 'A', '_', 'L', '_', 'W', 0,
  /* 6530 */ 'D', 'P', 'S', 'Q', '_', 'S', 'A', '_', 'L', '_', 'W', 0,
  /* 6542 */ 'E', 'X', 'T', 'R', '_', 'W', 0,
  /* 6549 */ 'S', 'H', 'R', 'A', '_', 'R', '_', 'W', 0,
  /* 6558 */ 'S', 'U', 'B', 'Q', 'H', '_', 'R', '_', 'W', 0,
  /* 6568 */ 'A', 'D', 'D', 'Q', 'H', '_', 'R', '_', 'W', 0,
  /* 6578 */ 'E', 'X', 'T', 'R', '_', 'R', '_', 'W', 0,
  /* 6587 */ 'S', 'H', 'R', 'A', 'V', '_', 'R', '_', 'W', 0,
  /* 6597 */ 'E', 'X', 'T', 'R', 'V', '_', 'R', '_', 'W', 0,
  /* 6607 */ 'M', 'U', 'L', 'Q', '_', 'R', 'S', '_', 'W', 0,
  /* 6617 */ 'E', 'X', 'T', 'R', '_', 'R', 'S', '_', 'W', 0,
  /* 6627 */ 'E', 'X', 'T', 'R', 'V', '_', 'R', 'S', '_', 'W', 0,
  /* 6638 */ 'S', 'H', 'L', 'L', '_', 'S', '_', 'W', 0,
  /* 6647 */ 'S', 'U', 'B', 'Q', '_', 'S', '_', 'W', 0,
  /* 6656 */ 'A', 'D', 'D', 'Q', '_', 'S', '_', 'W', 0,
  /* 6665 */ 'M', 'U', 'L', 'Q', '_', 'S', '_', 'W', 0,
  /* 6674 */ 'A', 'B', 'S', 'Q', '_', 'S', '_', 'W', 0,
  /* 6683 */ 'C', 'V', 'T', '_', 'S', '_', 'W', 0,
  /* 6691 */ 'S', 'H', 'L', 'L', 'V', '_', 'S', '_', 'W', 0,
  /* 6701 */ 'E', 'X', 'T', 'R', 'V', '_', 'W', 0,
  /* 6709 */ 'L', 'H', 'X', 0,
  /* 6713 */ 'L', 'B', 'U', 'X', 0,
  /* 6718 */ 'L', 'W', 'X', 0,
  /* 6722 */ 'C', 'O', 'P', 'Y', 0,
  /* 6727 */ 'B', 'G', 'E', 'Z', 0,
  /* 6732 */ 'B', 'L', 'E', 'Z', 0,
  /* 6737 */ 'D', 'C', 'L', 'Z', 0,
  /* 6742 */ 'B', 'G', 'T', 'Z', 0,
  /* 6747 */ 'B', 'L', 'T', 'Z', 0,
  /* 6752 */ 'S', 'e', 'l', 'B', 'n', 'e', 'Z', 0,
  /* 6760 */ 'S', 'e', 'l', 'B', 'e', 'q', 'Z', 0,
  /* 6768 */ 'L', 'o', 'a', 'd', 'I', 'm', 'm', '3', '2', 'R', 'e', 'g', 0,
  /* 6781 */ 'L', 'o', 'a', 'd', 'A', 'd', 'd', 'r', '3', '2', 'R', 'e', 'g', 0,
  /* 6795 */ 'D', 'A', 'D', 'D', 'i', 0,
  /* 6801 */ 'D', 'A', 'N', 'D', 'i', 0,
  /* 6807 */ 'X', 'O', 'R', 'i', 0,
  /* 6812 */ 'S', 'L', 'T', 'i', 0,
  /* 6817 */ 'L', 'U', 'i', 0,
  /* 6821 */ 'S', 'e', 'l', 'T', 'B', 't', 'n', 'e', 'Z', 'C', 'm', 'p', 'i', 0,
  /* 6835 */ 'S', 'e', 'l', 'T', 'B', 't', 'e', 'q', 'Z', 'C', 'm', 'p', 'i', 0,
  /* 6849 */ 'S', 'e', 'l', 'T', 'B', 't', 'n', 'e', 'Z', 'S', 'l', 't', 'i', 0,
  /* 6863 */ 'S', 'e', 'l', 'T', 'B', 't', 'e', 'q', 'Z', 'S', 'l', 't', 'i', 0,
  /* 6877 */ 'L', 'o', 'a', 'd', 'A', 'd', 'd', 'r', '3', '2', 'I', 'm', 'm', 0,
  /* 6891 */ 'S', 'e', 'l', 'T', 'B', 't', 'n', 'e', 'Z', 'C', 'm', 'p', 0,
  /* 6904 */ 'S', 'e', 'l', 'T', 'B', 't', 'e', 'q', 'Z', 'C', 'm', 'p', 0,
  /* 6917 */ 'S', 'e', 'l', 'T', 'B', 't', 'n', 'e', 'Z', 'S', 'l', 't', 0,
  /* 6930 */ 'S', 'e', 'l', 'T', 'B', 't', 'e', 'q', 'Z', 'S', 'l', 't', 0,
  /* 6943 */ 'L', 'B', 'u', 0,
  /* 6947 */ 'D', 'S', 'U', 'B', 'u', 0,
  /* 6953 */ 'D', 'A', 'D', 'D', 'u', 0,
  /* 6959 */ 'L', 'H', 'u', 0,
  /* 6963 */ 'S', 'L', 'T', 'u', 0,
  /* 6968 */ 'D', 'M', 'U', 'L', 'T', 'u', 0,
  /* 6975 */ 'D', 'A', 'D', 'D', 'i', 'u', 0,
  /* 6982 */ 'L', 'E', 'A', '_', 'A', 'D', 'D', 'i', 'u', 0,
  /* 6992 */ 'S', 'L', 'T', 'i', 'u', 0,
  /* 6998 */ 'S', 'e', 'l', 'T', 'B', 't', 'n', 'e', 'Z', 'S', 'l', 't', 'i', 'u', 0,
  /* 7013 */ 'S', 'e', 'l', 'T', 'B', 't', 'e', 'q', 'Z', 'S', 'l', 't', 'i', 'u', 0,
  /* 7028 */ 'S', 'e', 'l', 'T', 'B', 't', 'n', 'e', 'Z', 'S', 'l', 't', 'u', 0,
  /* 7042 */ 'S', 'e', 'l', 'T', 'B', 't', 'e', 'q', 'Z', 'S', 'l', 't', 'u', 0,
};

extern const unsigned OiInstrNameIndices[] = {
    4739U, 5033U, 4905U, 4918U, 4896U, 4988U, 4153U, 4168U, 
    4140U, 4182U, 6026U, 4125U, 4101U, 6722U, 4114U, 6303U, 
    4085U, 4468U, 3882U, 6674U, 4048U, 4281U, 4386U, 6568U, 
    6510U, 4347U, 4448U, 6656U, 4031U, 3762U, 3860U, 4527U, 
    3956U, 4488U, 3902U, 4037U, 6796U, 6976U, 6954U, 5062U, 
    5797U, 4066U, 567U, 6802U, 4078U, 1563U, 3251U, 400U, 
    2738U, 1086U, 2992U, 2536U, 3426U, 1486U, 3162U, 323U, 
    2649U, 978U, 2903U, 2463U, 3341U, 1527U, 3209U, 364U, 
    2696U, 1019U, 2950U, 2502U, 3386U, 1506U, 3185U, 343U, 
    2672U, 998U, 2926U, 2482U, 3363U, 1603U, 3297U, 440U, 
    2784U, 1126U, 3038U, 2574U, 3470U, 1466U, 3139U, 303U, 
    2626U, 958U, 2880U, 2444U, 3319U, 1583U, 3274U, 420U, 
    2761U, 1106U, 3015U, 2555U, 3448U, 1547U, 3232U, 384U, 
    2719U, 1070U, 2973U, 2521U, 3408U, 1960U, 1862U, 1974U, 
    1811U, 1878U, 2404U, 2343U, 3704U, 5055U, 5882U, 4135U, 
    6284U, 5812U, 1228U, 6727U, 1294U, 4808U, 6742U, 1308U, 
    6353U, 6732U, 1301U, 6747U, 1315U, 4815U, 4121U, 865U, 
    294U, 5079U, 2003U, 2016U, 1990U, 2038U, 1654U, 2066U, 
    1684U, 2096U, 2127U, 2151U, 2024U, 1639U, 2052U, 1669U, 
    2080U, 2112U, 2142U, 871U, 710U, 6174U, 261U, 832U, 
    6257U, 10U, 5649U, 6738U, 3803U, 3717U, 3912U, 3816U, 
    3730U, 3925U, 3828U, 3742U, 3937U, 4355U, 4262U, 4509U, 
    21U, 6043U, 6423U, 5015U, 6053U, 6433U, 733U, 6193U, 
    190U, 761U, 5025U, 6683U, 284U, 855U, 6276U, 494U, 
    4047U, 6795U, 6975U, 6953U, 6801U, 5648U, 6737U, 6318U, 
    5049U, 6341U, 6021U, 5043U, 6335U, 1180U, 15U, 1204U, 
    1192U, 26U, 1216U, 6297U, 6968U, 4591U, 5129U, 4666U, 
    5246U, 6518U, 5610U, 4628U, 5187U, 4866U, 5320U, 5860U, 
    5521U, 4692U, 5286U, 4571U, 5095U, 4605U, 5150U, 4679U, 
    5266U, 6530U, 5629U, 4654U, 5227U, 4877U, 5338U, 5871U, 
    5539U, 4702U, 5303U, 4619U, 5171U, 5977U, 6405U, 4196U, 
    6360U, 4057U, 4993U, 459U, 482U, 6372U, 3691U, 78U, 
    6347U, 4998U, 466U, 6378U, 6947U, 6366U, 2311U, 2289U, 
    6319U, 5792U, 5669U, 6391U, 6399U, 6627U, 6597U, 4724U, 
    6701U, 6617U, 6578U, 4715U, 6542U, 884U, 181U, 752U, 
    6201U, 104U, 618U, 6100U, 172U, 743U, 473U, 219U, 
    790U, 6223U, 721U, 6183U, 272U, 843U, 6266U, 228U, 
    799U, 6230U, 163U, 677U, 6147U, 132U, 646U, 6122U, 
    200U, 771U, 6208U, 85U, 599U, 6085U, 6022U, 6412U, 
    4802U, 4804U, 5964U, 1239U, 5961U, 1234U, 2168U, 2160U, 
    2203U, 2175U, 3706U, 557U, 2848U, 6713U, 3491U, 6943U, 
    1351U, 3112U, 3615U, 4063U, 0U, 505U, 2806U, 4888U, 
    3541U, 5901U, 3575U, 42U, 519U, 2826U, 3517U, 6982U, 
    1376U, 4210U, 908U, 2864U, 6709U, 3529U, 6959U, 1357U, 
    3121U, 3622U, 4985U, 4062U, 3516U, 3555U, 54U, 535U, 
    6817U, 1345U, 6417U, 1284U, 3096U, 32U, 2592U, 5007U, 
    1154U, 3060U, 3561U, 5989U, 1266U, 3078U, 3589U, 6718U, 
    66U, 2608U, 3603U, 1370U, 3130U, 1713U, 1777U, 1745U, 
    1794U, 1949U, 6877U, 6781U, 6768U, 492U, 1830U, 1892U, 
    4052U, 6329U, 5772U, 5487U, 114U, 628U, 5744U, 5438U, 
    6108U, 4927U, 5356U, 5909U, 5557U, 4953U, 5376U, 5935U, 
    5577U, 5683U, 16U, 5701U, 4734U, 918U, 5653U, 1166U, 
    4014U, 5889U, 123U, 637U, 4770U, 1039U, 6115U, 573U, 
    4748U, 932U, 6063U, 141U, 655U, 4777U, 1048U, 6129U, 
    210U, 781U, 4795U, 1145U, 6216U, 586U, 4759U, 945U, 
    6074U, 152U, 666U, 4786U, 1059U, 6138U, 4021U, 6323U, 
    5762U, 5470U, 95U, 609U, 5735U, 5422U, 6093U, 5692U, 
    27U, 5710U, 4743U, 925U, 5676U, 5408U, 5664U, 1173U, 
    5003U, 4965U, 5947U, 4822U, 5816U, 4408U, 6607U, 4458U, 
    6665U, 4640U, 5206U, 4580U, 5111U, 6298U, 5782U, 5504U, 
    5753U, 5454U, 6969U, 4332U, 4429U, 2189U, 2196U, 1622U, 
    1396U, 2256U, 2378U, 2277U, 2430U, 113U, 627U, 6107U, 
    94U, 608U, 6092U, 5719U, 5969U, 1246U, 2236U, 2267U, 
    5970U, 1247U, 6808U, 1332U, 2355U, 4322U, 4290U, 3771U, 
    4851U, 3644U, 5845U, 3675U, 4940U, 5922U, 4837U, 3629U, 
    5831U, 3660U, 4246U, 6458U, 4221U, 6487U, 4234U, 6443U, 
    6470U, 4070U, 4000U, 5723U, 5983U, 1258U, 4553U, 3982U, 
    4306U, 3787U, 6289U, 5978U, 6406U, 698U, 6164U, 249U, 
    820U, 6247U, 1450U, 1414U, 3696U, 1406U, 4011U, 562U, 
    2856U, 3497U, 4034U, 4043U, 3509U, 3503U, 4098U, 5U, 
    512U, 2816U, 6361U, 4892U, 3548U, 5905U, 3582U, 48U, 
    527U, 2837U, 3523U, 3702U, 551U, 4206U, 902U, 4712U, 
    913U, 2872U, 5658U, 6384U, 5596U, 5395U, 4544U, 3973U, 
    4498U, 6691U, 4298U, 3779U, 4419U, 6638U, 4535U, 3964U, 
    4397U, 3871U, 6587U, 4213U, 3709U, 4365U, 3839U, 6549U, 
    4562U, 3991U, 4314U, 3795U, 3535U, 4994U, 483U, 1322U, 
    6373U, 6293U, 1278U, 6812U, 1338U, 6992U, 1388U, 6963U, 
    1363U, 3692U, 6348U, 4999U, 6379U, 4017U, 4272U, 4375U, 
    6558U, 6502U, 4339U, 4438U, 6647U, 3753U, 3849U, 4519U, 
    3948U, 4478U, 3892U, 6948U, 60U, 543U, 6420U, 1289U, 
    3104U, 37U, 2600U, 5011U, 1160U, 3069U, 3568U, 5993U, 
    1272U, 3087U, 3596U, 72U, 2617U, 3609U, 4026U, 1437U, 
    1427U, 1729U, 6760U, 6752U, 6904U, 6835U, 6930U, 6863U, 
    7013U, 7042U, 6891U, 6821U, 6917U, 6849U, 6998U, 7028U, 
    1761U, 1699U, 2321U, 2211U, 2246U, 1918U, 1933U, 2223U, 
    2417U, 1632U, 2300U, 1706U, 2332U, 2391U, 1846U, 1905U, 
    4979U, 5997U, 6010U, 686U, 6154U, 237U, 808U, 6237U, 
    6367U, 5729U, 4201U, 5973U, 1252U, 6807U, 1331U, 2366U, 
};

static inline void InitOiMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(OiInsts, OiInstrNameIndices, OiInstrNameData, 704);
}

} // End llvm namespace 
#endif // GET_INSTRINFO_MC_DESC


#ifdef GET_INSTRINFO_HEADER
#undef GET_INSTRINFO_HEADER
namespace llvm {
struct OiGenInstrInfo : public TargetInstrInfo {
  explicit OiGenInstrInfo(int SO = -1, int DO = -1);
};
} // End llvm namespace 
#endif // GET_INSTRINFO_HEADER


#ifdef GET_INSTRINFO_CTOR
#undef GET_INSTRINFO_CTOR
namespace llvm {
extern const MCInstrDesc OiInsts[];
extern const unsigned OiInstrNameIndices[];
extern const char OiInstrNameData[];
OiGenInstrInfo::OiGenInstrInfo(int SO, int DO)
  : TargetInstrInfo(SO, DO) {
  InitMCInstrInfo(OiInsts, OiInstrNameIndices, OiInstrNameData, 704);
}
} // End llvm namespace 
#endif // GET_INSTRINFO_CTOR

