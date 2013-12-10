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
SBTOPT?=-debug-ir -oneregion -optimize

all: ackermann-oi-x86 ackermann-nat

ackermann-nat: ackermann.c
	$(CLANG) -O3 ackermann.c -o ackermann-nat

ackermann-oi-ia64: ackermann-oi-ia64.s
	$(CLANG) ackermann-oi-ia64.s -o ackermann-oi-ia64

ackermann-oi-ia64.s: ackermann-oi.bc
	$(LLVMLLC) -march=x86-64 ackermann-oi.bc -o ackermann-oi-ia64.s

ackermann-oi-x86: ackermann-oi-x86.s
	$(CLANG) -g ackermann-oi-x86.s -o ackermann-oi-x86

ackermann-oi-x86.s: ackermann-oi.bc
	$(OPT) ackermann-oi.bc -o ackermann-oi.bc
	$(LLVMLLC) -march=x86 ackermann-oi.bc -o ackermann-oi-x86.s

ackermann.oi: ackermann-oi.o
	$(CROSS) ackermann-oi.o -o ackermann.oi

ackermann-oi.o: ackermann.s
	../../backend/oife -assemble -filetype=obj -o=ackermann-oi.o ackermann.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
ackermann-oi.bc: ackermann-oi.o
	../../backend/oisbt $(SBTOPT) -stacksize 4000000 ackermann-oi.o -o=ackermann-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#ackermann-oi.bc: ackermann.s
#	../../backend/oife ackermann.s -o=ackermann-oi.bc

read: ackermann.s
	../../backend/oife ackermann.s

ackermann.s: ackermann.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi ackermann.bc -o ackermann.s

ackermann.bc: ackermann.c
	$(CLANG) $(EMITLLVM) -o ackermann.bc ackermann.c
	$(OPT) ackermann.bc -o ackermann.bc

clean:
	-rm -rf ackermann.s ackermann.bc ackermann-oi.bc ackermann-oi-ia64.s ackermann-oi-ia64 ackermann-oi-x86.s ackermann-oi-x86 ackermann-oi.o ackermann.oi ackermann-nat out-nat.txt out-oi.txt
