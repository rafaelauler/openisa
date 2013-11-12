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

all: hello-oi-x86

hello-oi-ia64: hello-oi-ia64.s
	$(CLANG) hello-oi-ia64.s -o hello-oi-ia64

hello-oi-ia64.s: hello-oi.bc
	$(LLVMLLC) -march=x86-64 hello-oi.bc -o hello-oi-ia64.s

hello-oi-x86: hello-oi-x86.s
	$(CLANG) hello-oi-x86.s -o hello-oi-x86

hello-oi-x86.s: hello-oi.bc
	$(LLVMLLC) -march=x86 hello-oi.bc -o hello-oi-x86.s

hello.oi: hello-oi.o
	$(CROSS) hello-oi.o -o hello.oi

hello-oi.o: hello.s
	../../backend/oife -assemble -filetype=obj -o=hello-oi.o hello.s

# Two methods to translate OpenISA code, one translates the .s assembly file,
# while other translates object files. Use object files as default.
hello-oi.bc: hello-oi.o
	../../backend/oisbt -optimize hello-oi.o -o=hello-oi.bc

# Method 2: Translate OpenISA directly from the assembly file (assembly
# translation layer).
#hello-oi.bc: hello.s
#	../../backend/oife hello.s -o=hello-oi.bc

read: hello.s
	../../backend/oife hello.s

hello.s: hello.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi hello.bc -o hello.s

hello.bc: hello.c
	$(CLANG) $(EMITLLVM) -o hello.bc hello.c
	$(OPT) hello.bc -o hello.bc

clean:
	-rm -rf hello.s hello.bc hello-oi.bc hello-oi-ia64.s hello-oi-ia64 hello-oi-x86.s hello-oi-x86 hello-oi.o hello.oi
