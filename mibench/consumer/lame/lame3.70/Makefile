BENCHNAME=lame

FILE1 = brhist.c \
	formatBitstream.c \
	fft.c \
	get_audio.c \
	l3bitstream.c \
        id3tag.c \
	ieeefloat.c \
        lame.c \
        newmdct.c \
        parse.c \
	portableio.c \
	psymodel.c \
	quantize.c \
	quantize-pvt.c \
	vbrquantize.c \
	reservoir.c \
	tables.c \
	takehiro.c \
	timestatus.c \
	util.c \
        VbrTag.c \
        version.c \
        gtkanal.c \
        gpkplotting.c \
        mpglib/common.c \
        mpglib/dct64_i386.c \
        mpglib/decode_i386.c \
        mpglib/layer3.c \
        mpglib/tabinit.c \
        mpglib/interface.c \
        mpglib/main.c \
   main.c

CPP_OPTS= -DHAVEMPGLIB -DLAMEPARSE -DNDEBUG -DLAMESNDFILE
OPTFLAGS?=-printf-break

TARGETS=lame

SBTOPT?=-optimize -oneregion

STACKSIZE=400000

include ../../../Makefile.common


