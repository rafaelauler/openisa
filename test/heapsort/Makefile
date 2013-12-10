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

all: heapsort-oi-x86 heapsort-nat

heapsort-nat: heapsort.c
	$(CLANG) -O3 heapsort.c -o heapsort-nat

heapsort-oi-ia64: heapsort-oi-ia64.s
	$(CLANG) heapsort-oi-ia64.s -o heapsort-oi-ia64

heapsort-oi-ia64.s: heapsort-oi.bc
	$(LLVMLLC) -march=x86-64 heapsort-oi.bc -o heapsort-oi-ia64.s

heapsort-oi-x86: heapsort-oi-x86.s
	$(CLANG) -g heapsort-oi-x86.s -o heapsort-oi-x86

heapsort-oi-x86.s: heapsort-oi.bc
	$(OPT) heapsort-oi.bc -o heapsort-oi.bc
	$(LLVMLLC) -march=x86 heapsort-oi.bc -o heapsort-oi-x86.s

heapsort.oi: heapsort-oi.o
	$(CROSS) heapsort-oi.o -o heapsort.oi

heapsort-oi.o: heapsort.s
	../../backend/oife -assemble -filetype=obj -o=heapsort-oi.o heapsort.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
heapsort-oi.bc: heapsort-oi.o
	../../backend/oisbt $(SBTOPT) -stacksize 4000 heapsort-oi.o -o=heapsort-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#heapsort-oi.bc: heapsort.s
#	../../backend/oife heapsort.s -o=heapsort-oi.bc

read: heapsort.s
	../../backend/oife heapsort.s

heapsort.s: heapsort.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi heapsort.bc -o heapsort.s

heapsort.bc: heapsort.c
	$(CLANG) $(EMITLLVM) -o heapsort.bc heapsort.c
	$(OPT) heapsort.bc -o heapsort.bc

clean:
	-rm -rf heapsort.s heapsort.bc heapsort-oi.bc heapsort-oi-ia64.s heapsort-oi-ia64 heapsort-oi-x86.s heapsort-oi-x86 heapsort-oi.o heapsort.oi heapsort-nat out-nat.txt out-oi.txt
