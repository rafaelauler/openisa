#LLVMCONFIG?=llvm-config
#LLVMLLC=$(shell $(LLVMCONFIG) --obj-root)/$(shell $(LLVMCONFIG) --build-mode)/bin/llc
LLVMLLC=llc -relocation-model=static -view-dag-combine1-dags
#-view-sched-dags
#CLANG=clang -c -emit-llvm
#CLANGARM=clang -target armv7--eabi -mcpu=cortex-a9
CLANG=clang
OPT=opt -O3
#EMITLLVM=-ccc-host-triple mips-unknown-linux -ccc-clang-archs mips -emit-llvm -c
EMITLLVM=-target mips-unknown-linux -emit-llvm -c --sysroot=/tools

all: calc-oi-x86

calc-oi-ia64: calc-oi-ia64.s
	$(CLANG) calc-oi-ia64.s -o calc-oi-ia64

calc-oi-ia64.s: calc-oi.bc
	$(LLVMLLC) -march=x86-64 calc-oi.bc -o calc-oi-ia64.s

calc-oi-x86: calc-oi-x86.s
	$(CLANG) calc-oi-x86.s -o calc-oi-x86

calc-oi-x86.s: calc-oi.bc
	$(LLVMLLC) -march=x86 calc-oi.bc -o calc-oi-x86.s

calc-oi.bc: calc.s
	../../backend/oife calc.s -o=calc-oi.bc

read: calc.s
	../../backend/oife calc.s

calc.s: calc.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi calc.bc -o calc.s

calc.bc: calc.c
	$(CLANG) $(EMITLLVM) -o calc.bc calc.c
	$(OPT) calc.bc -o calc.bc

clean:
	-rm -rf calc.s calc.bc calc-oi.bc calc-oi-ia64.s calc-oi-ia64
