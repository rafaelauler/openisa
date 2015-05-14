BENCHNAME=toast
BENCHNAME2=untoast


ROOT	= .
BIN	= $(ROOT)/bin
SRC	= $(ROOT)/src
INC	= $(ROOT)/inc

GSM_SOURCES =	$(SRC)/add.c		\
		$(SRC)/code.c		\
		$(SRC)/debug.c		\
		$(SRC)/decode.c		\
		$(SRC)/long_term.c	\
		$(SRC)/lpc.c		\
		$(SRC)/preprocess.c	\
		$(SRC)/rpe.c		\
		$(SRC)/gsm_destroy.c	\
		$(SRC)/gsm_decode.c	\
		$(SRC)/gsm_encode.c	\
		$(SRC)/gsm_explode.c	\
		$(SRC)/gsm_implode.c	\
		$(SRC)/gsm_create.c	\
		$(SRC)/gsm_print.c	\
		$(SRC)/gsm_option.c	\
		$(SRC)/short_term.c	\
		$(SRC)/table.c

TOAST_SOURCES = $(SRC)/toast.c 		\
		$(SRC)/toast_lin.c	\
		$(SRC)/toast_ulaw.c	\
		$(SRC)/toast_alaw.c	\
		$(SRC)/toast_audio.c


FILE1 = $(GSM_SOURCES) $(TOAST_SOURCES)
FILE2 = $(GSM_SOURCES) $(TOAST_SOURCES)

TARGETS=toast untoast

CPP_OPTS=-I$(INC)
SBTOPT?=-optimize -oneregion

STACKSIZE=400000

include ../../Makefile.common


