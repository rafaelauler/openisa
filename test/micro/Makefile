#LLVMCONFIG?=llvm-config
#LLVMLLC=$(shell $(LLVMCONFIG) --obj-root)/$(shell $(LLVMCONFIG) --build-mode)/bin/llc
LLVMLLC=llc -relocation-model=static 
#-view-dag-combine1-dags
#-view-sched-dags
#CLANG=clang -c -emit-llvm
#CLANGARM=clang -target armv7--eabi -mcpu=cortex-a9
CLANG=clang
OPT=opt -O3
#EMITLLVM=-ccc-host-triple mips-unknown-linux -ccc-clang-archs mips -emit-llvm -c
EMITLLVM=-target mips-unknown-linux -emit-llvm -c --sysroot=/tools
CROSS=mipsel-unknown-linux-gnu-gcc

all: simple-oi-x86 simple-nat

simple-nat: simple.c
	$(CLANG) -O3 simple.c -o simple-nat

simple-oi-ia64: simple-oi-ia64.s
	$(CLANG) simple-oi-ia64.s -o simple-oi-ia64

simple-oi-ia64.s: simple-oi.bc
	$(LLVMLLC) -march=x86-64 simple-oi.bc -o simple-oi-ia64.s

simple-oi-x86: simple-oi-x86.s
	$(CLANG) -g simple-oi-x86.s -o simple-oi-x86

simple-oi-x86.s: simple-oi.bc
	$(LLVMLLC) -march=x86 simple-oi.bc -o simple-oi-x86.s

simple.oi: simple-oi.o
	$(CROSS) simple-oi.o -o simple.oi

simple-oi.o: simple.s
	../../backend/oife -assemble -filetype=obj -o=simple-oi.o simple.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
simple-oi.bc: simple-oi.o
	../../backend/oisbt -stacksize 4000 -optimize simple-oi.o -o=simple-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#simple-oi.bc: simple.s
#	../../backend/oife simple.s -o=simple-oi.bc

read: simple.s
	../../backend/oife simple.s

simple.s: simple.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi simple.bc -o simple.s

simple.bc: simple.c
	$(CLANG) $(EMITLLVM) -o simple.bc simple.c
	$(OPT) simple.bc -o simple.bc

clean:
	-rm -rf simple.s simple.bc simple-oi.bc simple-oi-ia64.s simple-oi-ia64 simple-oi-x86.s simple-oi-x86 simple-oi.o simple.oi simple-nat
