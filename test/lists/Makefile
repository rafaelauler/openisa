#LLVMCONFIG?=llvm-config
#LLVMLLC=$(shell $(LLVMCONFIG) --obj-root)/$(shell $(LLVMCONFIG) --build-mode)/bin/llc
LLVMLLC=llc -relocation-model=static -O3
#-view-dag-combine1-dags
#-view-sched-dags
#CLANG=clang -c -emit-llvm
#CLANGARM=clang -target armv7--eabi -mcpu=cortex-a9
CLANG=clang
OPT=opt -O3
#EMITLLVM=-ccc-host-triple mips-unknown-linux -ccc-clang-archs mips -emit-llvm -c
EMITLLVM=-target mips-unknown-linux -emit-llvm -c --sysroot=/tools
CROSS=mipsel-unknown-linux-gnu-gcc

all: lists-oi-x86 lists-nat

lists-nat: lists.c
	$(CLANG) -O3 lists.c -o lists-nat

lists-oi-ia64: lists-oi-ia64.s
	$(CLANG) lists-oi-ia64.s -o lists-oi-ia64

lists-oi-ia64.s: lists-oi.bc
	$(LLVMLLC) -march=x86-64 lists-oi.bc -o lists-oi-ia64.s

lists-oi-x86: lists-oi-x86.s
	$(CLANG) -g lists-oi-x86.s -o lists-oi-x86

lists-oi-x86.s: lists-oi.bc
	$(OPT) lists-oi.bc -o lists-oi.bc
	$(LLVMLLC) -march=x86 lists-oi.bc -o lists-oi-x86.s

lists.oi: lists-oi.o
	$(CROSS) lists-oi.o -o lists.oi

lists-oi.o: lists.s
	../../backend/oife -assemble -filetype=obj -o=lists-oi.o lists.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
lists-oi.bc: lists-oi.o
	../../backend/oisbt -stacksize 4000 -optimize lists-oi.o -o=lists-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#lists-oi.bc: lists.s
#	../../backend/oife lists.s -o=lists-oi.bc

read: lists.s
	../../backend/oife lists.s

lists.s: lists.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi lists.bc -o lists.s

lists.bc: lists.c
	$(CLANG) $(EMITLLVM) -o lists.bc lists.c
	$(OPT) lists.bc -o lists.bc

clean:
	-rm -rf lists.s lists.bc lists-oi.bc lists-oi-ia64.s lists-oi-ia64 lists-oi-x86.s lists-oi-x86 lists-oi.o lists.oi lists-nat
