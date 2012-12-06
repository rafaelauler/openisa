##===- oi/backend/TargetInfo/Makefile --- ------------------*- Makefile -*-===##
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
##===----------------------------------------------------------------------===##
LLVM_CONFIG?=llvm-config

# Location of the source, useful if you want separate source and object
# directories.
SRC_DIR?=$(PWD)/TargetInfo

ifndef VERBOSE
	QUIET:=@
endif

COMMON_FLAGS=-Wall -Wextra -fvisibility=hidden
CFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cflags)
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags)

ifeq ($(shell uname),Darwin)
LOADABLE_MODULE_OPTIONS=-bundle -undefined dynamic_lookup
else
LOADABLE_MODULE_OPTIONS=-shared -Wl,-O1
endif

TARGETINFO=OIBackendCodeGen.o
TARGETINFO_OBJECTS=OIBackendTargetInfo.o
ALL_OBJECTS=$(TARGETINFO_OBJECTS)
ALL_TARGETS=$(TARGETINFO)

CPP_OPTIONS+=$(CPPFLAGS) $(shell $(LLVM_CONFIG) --cppflags) \
	     -MD -MP -I$(SRC_DIR)

LD_OPTIONS+=$(LDFLAGS) $(shell $(LLVM_CONFIG) --ldflags)

default: $(ALL_TARGETS)

%.o : $(SRC_DIR)/%.c
	@echo Compiling $*.c
	$(QUIET)$(CC) -c $(CPP_OPTIONS) $(CFLAGS) $<

%.o : $(SRC_DIR)/%.cpp
	@echo Compiling $*.cpp
	$(QUIET)$(CXX) -c $(CPP_OPTIONS) $(CXXFLAGS) $<

$(TARGETINFO): $(TARGETINFO_OBJECTS)
	@echo Linking $@
	$(QUIET)ld -o $@ -r $(TARGETINFO_OBJECTS)

clean::
	$(QUIET)rm -f $(ALL_OBJECTS) *.d

-include $(ALL_OBJECTS:.o=.d)
