BENCHNAME=pgp

RSASRCS = rsaglue1.c

ZIPSRCS= zbits.c zdeflate.c zfile_io.c zglobals.c \
	zinflate.c zip.c zipup.c ztrees.c zunzip.c 

SRC1 =  pgp.c crypto.c keymgmt.c fileio.c \
	mdfile.c more.c armor.c mpilib.c mpiio.c \
	genprime.c rsagen.c random.c idea.c passwd.c \
	md5.c system.c language.c getopt.c keyadd.c \
	config.c keymaint.c charset.c \
	randpool.c noise.c

FILE1 = $(RSASRCS) $(ZIPSRCS) $(SRC1)

TARGETS=pgp

SBTOPT?=-optimize -oneregion
CPP_OPTS=-std=gnu89 -DUNIX -DLINUX -DIDEA32 -DPORTABLE
STACKSIZE=400000

include ../../../Makefile.common


