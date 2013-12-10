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

all: random-oi-x86 random-nat

random-nat: random.c
	$(CLANG) -O3 random.c -o random-nat

random-oi-ia64: random-oi-ia64.s
	$(CLANG) random-oi-ia64.s -o random-oi-ia64

random-oi-ia64.s: random-oi.bc
	$(LLVMLLC) -march=x86-64 random-oi.bc -o random-oi-ia64.s

random-oi-x86: random-oi-x86.s
	$(CLANG) -g random-oi-x86.s -o random-oi-x86

random-oi-x86.s: random-oi.bc
	$(OPT) random-oi.bc -o random-oi.bc
	$(LLVMLLC) -march=x86 random-oi.bc -o random-oi-x86.s

random.oi: random-oi.o
	$(CROSS) random-oi.o -o random.oi

random-oi.o: random.s
	../../backend/oife -assemble -filetype=obj -o=random-oi.o random.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
random-oi.bc: random-oi.o
	../../backend/oisbt $(SBTOPT) -stacksize 4000 random-oi.o -o=random-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#random-oi.bc: random.s
#	../../backend/oife random.s -o=random-oi.bc

read: random.s
	../../backend/oife random.s

random.s: random.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi random.bc -o random.s

random.bc: random.c
	$(CLANG) $(EMITLLVM) -o random.bc random.c
	$(OPT) random.bc -o random.bc

clean:
	-rm -rf random.s random.bc random-oi.bc random-oi-ia64.s random-oi-ia64 random-oi-x86.s random-oi-x86 random-oi.o random.oi random-nat out-nat.txt out-oi.txt
