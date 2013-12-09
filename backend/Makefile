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
TARGET?=Oi
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

#COMMON_FLAGS=-Wall -Wextra -fvisibility=hidden
#COMMON_FLAGS=-fvisibility=hidden
CFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cflags)
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags)

ifeq ($(shell uname),Darwin)
LOADABLE_MODULE_OPTIONS=-bundle -undefined dynamic_lookup
else
LOADABLE_MODULE_OPTIONS=-shared -Wl,-O1
endif

# Tablegen-generated necessary files
BUILT_SOURCES_raw := $(shell cat CMakeLists.txt | grep tablegen.LLVM | cut -d' ' -f2)
BUILT_SOURCES = $(BUILT_SOURCES_raw:%=$(ObjDir)/%)


PLUGIN=$(BIN_DIR)/OIBackend.so
FRONTEND=$(BIN_DIR)/oife
STATICBT=$(BIN_DIR)/oisbt

Sources := $(notdir $(wildcard $(SRC_DIR)/*.cpp \
           $(SRC_DIR)/TargetInfo/*.cpp \
	   $(SRC_DIR)/MCTargetDesc/*.cpp \
	   $(SRC_DIR)/InstPrinter/*.cpp \
	   $(SRC_DIR)/Disassembler/*.cpp \
	   $(SRC_DIR)/AsmParser/*.cpp))

FrontEndSources := $(notdir $(wildcard $(SRC_DIR)/FrontEnd/*.cpp))

StaticBTSources := $(notdir $(wildcard $(SRC_DIR)/StaticBT/*.cpp))

BaseNameSources := $(sort $(basename $(Sources)))

FrontEndBaseNameSources := $(sort $(basename $(FrontEndSources)))

StaticBTBaseNameSources := $(sort $(basename $(StaticBTSources)))

PLUGIN_OBJECTS := $(BaseNameSources:%=$(ObjDir)/%.o)

FRONTEND_OBJECTS := $(FrontEndBaseNameSources:%=$(ObjDir)/%.o)

STATICBT_OBJECTS := $(StaticBTBaseNameSources:%=$(ObjDir)/%.o) $(ObjDir)/MC2IRStreamer.o

ALL_OBJECTS=$(PLUGIN_OBJECTS) $(FRONTEND_OBJECTS) $(STATICBT_OBJECTS)
ALL_TARGETS=$(PLUGIN) $(FRONTEND) $(STATICBT)

CPP_OPTIONS+=$(CPPFLAGS) $(shell $(LLVM_CONFIG) --cppflags) \
	     -MD -MP -I$(SRC_DIR) -I$(ObjDir)

# options for static linking (not working in Linux) 
ifeq ($(shell uname),Darwin)
LD_STATIC_OPTIONS+=$(LDFLAGS) $(shell $(LLVM_CONFIG) --ldflags) $(shell $(LLVM_CONFIG) --libs)
else
LD_STATIC_OPTIONS+=$(LDFLAGS) -L$(shell $(LLVM_CONFIG) --libdir) -Wl,-Bdynamic -lz -lm -lpthread -Wl,-Bstatic $(shell $(LLVM_CONFIG) --libs) -Wl,-Bdynamic
endif
# enable dynamic linking
LD_OPTIONS+=$(LDFLAGS) $(shell $(LLVM_CONFIG) --ldflags) -lLLVM-$(shell $(LLVM_CONFIG) --version)

# Basic makefile initialization
VPATH=$(SRC_DIR):$(SRC_DIR)/TargetInfo:$(SRC_DIR)/MCTargetDesc:$(SRC_DIR)/InstPrinter:$(SRC_DIR)/Disassembler:$(SRC_DIR)/AsmParser:$(SRC_DIR)/FrontEnd:$(SRC_DIR)/StaticBT
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

$(FRONTEND): $(PLUGIN_OBJECS) $(FRONTEND_OBJECTS)
	@echo Linking $@
ifeq ($(shell uname),Darwin)
	$(QUIET)$(CXX) -o $@ $(LD_STATIC_OPTIONS) $(PLUGIN_OBJECTS) $(FRONTEND_OBJECTS)
else
	$(QUIET)$(CXX) -o $@ $(LD_OPTIONS) $(PLUGIN_OBJECTS) $(FRONTEND_OBJECTS)
endif

$(STATICBT): $(PLUGIN_OBJECS) $(STATICBT_OBJECTS)
	@echo Linking $@
ifeq ($(shell uname),Darwin)
	$(QUIET)$(CXX) -o $@ $(LD_STATIC_OPTIONS) $(PLUGIN_OBJECTS) $(STATICBT_OBJECTS)
else
	$(QUIET)$(CXX) -o $@ $(LD_OPTIONS) $(PLUGIN_OBJECTS) $(STATICBT_OBJECTS)
endif


include Makefile.tblgen

clean::
	$(QUIET)rm -f $(SRC_DIR)/*~ $(SRC_DIR)/TargetInfo/*~ \
        $(SRC_DIR)/MCTargetDesc/*~ $(BUILT_SOURCES) $(ALL_OBJECTS) *.d $(PLUGIN) $(FRONTEND) $(STATICBT)
	$(QUIET)rm -rf $(ObjDir)

-include $(ALL_OBJECTS:.o=.d)
