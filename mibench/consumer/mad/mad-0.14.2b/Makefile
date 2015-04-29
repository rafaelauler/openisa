default_audio =  	audio.c	audio_cdda.c audio_aiff.c audio_wave.c audio_snd.c audio_raw.c  	audio_null.c


extra_audio =  	audio_oss.c audio_empeg.c audio_sun.c audio_win32.c  	audio_hex.c audio_esd.c


common_sources =  	version.c


madplay_SOURCES =  	$(common_sources) $(default_audio) madplay.c  	resample.c filter.c equalizer.c xing.c player.c getopt.c getopt1.c getopt.h


EXTRA_madplay_SOURCES =  	$(extra_audio)


madtime_SOURCES = $(common_sources) madtime.c


BENCHNAME=mad
FILE1 = $(madtime_SOURCES)

TARGETS=mad

SBTOPT?=-optimize
OPTFLAGS?=-printf-break
STACKSIZE=400000

include ../../../Makefile.common
