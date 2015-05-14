BENCHNAME=lout

SRCS	= z01.c z02.c z03.c z04.c z05.c z06.c z07.c z08.c	\
	  z09.c z10.c z11.c z12.c z13.c z14.c z15.c z16.c	\
	  z17.c z18.c z19.c z20.c z21.c z22.c z23.c z24.c	\
	  z25.c z26.c z27.c z28.c z29.c z30.c z31.c z32.c	\
	  z33.c z34.c z35.c z36.c z37.c z38.c z39.c z40.c	\
	  z41.c z42.c z43.c z44.c z45.c z46.c z47.c z48.c	\
	  z49.c z50.c z51.c

CPP_OPTS	= -DOS_UNIX=1					\
	  -DOS_DOS=0					\
	  -DOS_MAC=0					\
	  -DDB_FIX=0					\
	  -DUSE_STAT=1					\
	  -DSAFE_DFT=0					\
	  -DCOLLATE=0					\
	  -DLIB_DIR=\"\"				\
	  -DFONT_DIR=\"\"				\
	  -DMAPS_DIR=\"\"				\
	  -DINCL_DIR=\"\"				\
	  -DDATA_DIR=\"\"				\
	  -DHYPH_DIR=\"\"				\
	  -DCHAR_IN=1				\
	  -DCHAR_OUT=0					\
	  -DASSERT_ON=1 -ansi -pedantic -Wall -O3				\
	  -DDEBUG_ON=0				\
	  $(TRACING)					\
	  -DPDF_COMPRESSION=0			\
	  $(ZLIBPATH)


FILE1 = $(SRCS)

TARGETS=lout

SBTOPT?=-optimize -oneregion
OPTFLAGS?=-printf-break

STACKSIZE=400000

include ../../../Makefile.common


