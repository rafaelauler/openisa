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

all: fib-oi-x86 fib-nat

fib-nat: fib.c
	gcc fib.c -o fib-nat

fib-oi-ia64: fib-oi-ia64.s
	$(CLANG) fib-oi-ia64.s -o fib-oi-ia64

fib-oi-ia64.s: fib-oi.bc
	$(LLVMLLC) -march=x86-64 fib-oi.bc -o fib-oi-ia64.s

fib-oi-x86: fib-oi-x86.s
	$(CLANG) fib-oi-x86.s -o fib-oi-x86

fib-oi-x86.s: fib-oi.bc
	$(LLVMLLC) -march=x86 fib-oi.bc -o fib-oi-x86.s

fib.oi: fib-oi.o
	$(CROSS) fib-oi.o -o fib.oi

fib-oi.o: fib.s
	../../backend/oife -assemble -filetype=obj -o=fib-oi.o fib.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
fib-oi.bc: fib-oi.o
	../../backend/oisbt -optimize fib-oi.o -o=fib-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#fib-oi.bc: fib.s
#	../../backend/oife fib.s -o=fib-oi.bc

read: fib.s
	../../backend/oife fib.s

fib.s: fib.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi fib.bc -o fib.s

fib.bc: fib.c
	$(CLANG) $(EMITLLVM) -o fib.bc fib.c
	$(OPT) fib.bc -o fib.bc

clean:
	-rm -rf fib.s fib.bc fib-oi.bc fib-oi-ia64.s fib-oi-ia64 fib-oi-x86.s fib-oi-x86 fib-oi.o fib.oi fib-nat
