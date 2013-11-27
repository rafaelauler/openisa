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

all: matrix-oi-x86 matrix-nat

matrix-nat: matrix.c
	$(CLANG) -O3 matrix.c -o matrix-nat

matrix-oi-ia64: matrix-oi-ia64.s
	$(CLANG) matrix-oi-ia64.s -o matrix-oi-ia64

matrix-oi-ia64.s: matrix-oi.bc
	$(OPT) matrix-oi.bc -o matrix-oi.bc
	$(LLVMLLC) -march=x86-64 matrix-oi.bc -o matrix-oi-ia64.s

matrix-oi-x86: matrix-oi-x86.s
	$(OPT) matrix-oi.bc -o matrix-oi.bc
	$(CLANG) -g matrix-oi-x86.s -o matrix-oi-x86

matrix-oi-x86.s: matrix-oi.bc
	$(LLVMLLC) -march=x86 matrix-oi.bc -o matrix-oi-x86.s

matrix.oi: matrix-oi.o
	$(CROSS) matrix-oi.o -o matrix.oi

matrix-oi.o: matrix.s
	../../backend/oife -assemble -filetype=obj -o=matrix-oi.o matrix.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
matrix-oi.bc: matrix-oi.o
	../../backend/oisbt -stacksize 4000 -optimize matrix-oi.o -o=matrix-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#matrix-oi.bc: matrix.s
#	../../backend/oife matrix.s -o=matrix-oi.bc

read: matrix.s
	../../backend/oife matrix.s

matrix.s: matrix.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi matrix.bc -o matrix.s

matrix.bc: matrix.c
	$(CLANG) $(EMITLLVM) -o matrix.bc matrix.c
	$(OPT) matrix.bc -o matrix.bc

clean:
	-rm -rf matrix.s matrix.bc matrix-oi.bc matrix-oi-ia64.s matrix-oi-ia64 matrix-oi-x86.s matrix-oi-x86 matrix-oi.o matrix.oi matrix-nat
