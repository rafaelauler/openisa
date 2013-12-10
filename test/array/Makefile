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
SBTOPT?=-optimize

all: array-oi-x86 array-nat

array-nat: array.c
	$(CLANG) -O3 array.c -o array-nat

array-oi-ia64: array-oi-ia64.s
	$(CLANG) array-oi-ia64.s -o array-oi-ia64

array-oi-ia64.s: array-oi.bc
	$(LLVMLLC) -march=x86-64 array-oi.bc -o array-oi-ia64.s

array-oi-x86: array-oi-x86.s
	$(CLANG) -g array-oi-x86.s -o array-oi-x86

array-oi-x86.s: array-oi.bc
	$(OPT) array-oi.bc -o array-oi.bc
	$(LLVMLLC) -march=x86 array-oi.bc -o array-oi-x86.s

array.oi: array-oi.o
	$(CROSS) array-oi.o -o array.oi

array-oi.o: array.s
	../../backend/oife -assemble -filetype=obj -o=array-oi.o array.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
array-oi.bc: array-oi.o
	../../backend/oisbt $SBTOPT -stacksize 4000 array-oi.o -o=array-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#array-oi.bc: array.s
#	../../backend/oife array.s -o=array-oi.bc

read: array.s
	../../backend/oife array.s

array.s: array.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi array.bc -o array.s

array.bc: array.c
	$(CLANG) $(EMITLLVM) -o array.bc array.c
	$(OPT) array.bc -o array.bc

clean:
	-rm -rf array.s array.bc array-oi.bc array-oi-ia64.s array-oi-ia64 array-oi-x86.s array-oi-x86 array-oi.o array.oi array-nat out-nat.txt out-oi.txt
