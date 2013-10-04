##===- oi/backend/Makefile --- -----------------------------*- Makefile -*-===##
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
##===----------------------------------------------------------------------===##
LLVM_CONFIG?=llvm-config
LLVMTableGen?=llvm-tblgen -I $(shell $(LLVM_CONFIG) --src-root)/include \
                          -I $(shell $(LLVM_CONFIG) --src-root)/lib/Target
TARGET?=OI
Echo=@echo

# Location of the source, useful if you want separate source and object
# directories.
SRC_DIR?=$(PWD)
BIN_DIR?=$(PWD)
ObjDir?=$(PWD)/obj

ifndef VERBOSE
	QUIET:=@
endif

Verb=$(QUIET)

# COMMON_FLAGS=-Wall -Wextra -fvisibility=hidden
COMMON_FLAGS=-fvisibility=hidden
CFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cflags)
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags)

ifeq ($(shell uname),Darwin)
LOADABLE_MODULE_OPTIONS=-bundle -undefined dynamic_lookup
else
LOADABLE_MODULE_OPTIONS=-shared -Wl,-O1
endif

# Tablegen-generated necessary files
BUILT_SOURCES_raw = OIGenRegisterInfo.inc OIGenInstrInfo.inc \
		OIGenAsmWriter.inc OIGenDAGISel.inc \
		OIGenSubtargetInfo.inc OIGenCallingConv.inc
BUILT_SOURCES = $(BUILT_SOURCES_raw:%=$(ObjDir)/%)


PLUGIN=$(BIN_DIR)/OIBackend.so

Sources := $(notdir $(wildcard $(SRC_DIR)/*.cpp \
           $(SRC_DIR)/TargetInfo/*.cpp \
	   $(SRC_DIR)/MCTargetDesc/*.cpp))
BaseNameSources := $(sort $(basename $(Sources)))

PLUGIN_OBJECTS := $(BaseNameSources:%=$(ObjDir)/%.o)

ALL_OBJECTS=$(PLUGIN_OBJECTS)
ALL_TARGETS=$(PLUGIN)

CPP_OPTIONS+=$(CPPFLAGS) $(shell $(LLVM_CONFIG) --cppflags) \
	     -MD -MP -I$(SRC_DIR) -I$(ObjDir)

LD_OPTIONS+=$(LDFLAGS) $(shell $(LLVM_CONFIG) --ldflags)

# Basic makefile initialization
VPATH=$(SRC_DIR):$(SRC_DIR)/TargetInfo:$(SRC_DIR)/MCTargetDesc
.PHONY: default clean
# .PRECIOUS: $(ObjDir) $(ALL_OBJECTS)

#------------------------------------------------------------------------
# Make sure the BUILT_SOURCES are built first
#------------------------------------------------------------------------
all default:: $(BUILT_SOURCES)


all default:: $(ALL_TARGETS)

#
# Rule used to create a separate folder to hold objects
#
$(ObjDir):
	$(QUIET) mkdir -p $(ObjDir)

#
# Wildcard rules
#
$(ObjDir)/%.o : %.c | $(ObjDir)
	@echo Compiling $*.c
	$(QUIET)$(CC) -c $(CPP_OPTIONS) $(CFLAGS) $< -o $@

$(ObjDir)/%.o : %.cpp | $(ObjDir)
	@echo Compiling $*.cpp
	$(QUIET)$(CXX) -c $(CPP_OPTIONS) $(CXXFLAGS) $< -o $@ 

#
# Creates the main dynamic library
#
$(PLUGIN): $(PLUGIN_OBJECTS)
	@echo Linking $@
	$(QUIET)$(CXX) -o $@ $(LOADABLE_MODULE_OPTIONS) $(CXXFLAGS) \
	$(LD_OPTIONS) $^ 

include Makefile.tblgen

clean::
	$(QUIET)rm -f $(SRC_DIR)/*~ $(SRC_DIR)/TargetInfo/*~ \
        $(SRC_DIR)/MCTargetDesc/*~ $(BUILT_SOURCES) $(ALL_OBJECTS) *.d $(PLUGIN)
	$(QUIET)rm -rf $(ObjDir)

-include $(ALL_OBJECTS:.o=.d)
