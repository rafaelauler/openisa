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

all: sieve-oi-x86 sieve-nat

sieve-nat: sieve.c
	$(CLANG) -O3 sieve.c -o sieve-nat

sieve-oi-ia64: sieve-oi-ia64.s
	$(CLANG) sieve-oi-ia64.s -o sieve-oi-ia64

sieve-oi-ia64.s: sieve-oi.bc
	$(LLVMLLC) -march=x86-64 sieve-oi.bc -o sieve-oi-ia64.s

sieve-oi-x86: sieve-oi-x86.s
	$(CLANG) -g sieve-oi-x86.s -o sieve-oi-x86

sieve-oi-x86.s: sieve-oi.bc
	$(OPT) sieve-oi.bc -o sieve-oi.bc
	$(LLVMLLC) -march=x86 sieve-oi.bc -o sieve-oi-x86.s

sieve.oi: sieve-oi.o
	$(CROSS) sieve-oi.o -o sieve.oi

sieve-oi.o: sieve.s
	../../backend/oife -assemble -filetype=obj -o=sieve-oi.o sieve.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
sieve-oi.bc: sieve-oi.o
	../../backend/oisbt $(SBTOPT) -stacksize 20000 sieve-oi.o -o=sieve-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#sieve-oi.bc: sieve.s
#	../../backend/oife sieve.s -o=sieve-oi.bc

read: sieve.s
	../../backend/oife sieve.s

sieve.s: sieve.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi sieve.bc -o sieve.s

sieve.bc: sieve.c
	$(CLANG) $(EMITLLVM) -o sieve.bc sieve.c
	$(OPT) sieve.bc -o sieve.bc

clean:
	-rm -rf sieve.s sieve.bc sieve-oi.bc sieve-oi-ia64.s sieve-oi-ia64 sieve-oi-x86.s sieve-oi-x86 sieve-oi.o sieve.oi sieve-nat out-nat.txt out-oi.txt
