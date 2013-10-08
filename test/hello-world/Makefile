#LLVMCONFIG?=llvm-config
#LLVMLLC=$(shell $(LLVMCONFIG) --obj-root)/$(shell $(LLVMCONFIG) --build-mode)/bin/llc
LLVMLLC=llc
#CLANG=clang -c -emit-llvm
CLANG=clang -ccc-host-triple mips-unknown-linux -ccc-clang-archs mips -emit-llvm -c


all: read

read: hello.s
	../../backend/oife hello.s

hello.s: hello.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi hello.bc -o hello.s

hello.bc: hello.c
	$(CLANG) -o hello.bc hello.c

clean:
	-rm -rf hello.s hello.bc
