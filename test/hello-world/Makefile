#LLVMCONFIG?=llvm-config
#LLVMLLC=$(shell $(LLVMCONFIG) --obj-root)/$(shell $(LLVMCONFIG) --build-mode)/bin/llc
LLVMLLC=llc

all: hello.s


hello.s: hello.bc
	$(LLVMLLC) -load=../../backend/OIBackend.so -march=oi hello.bc -o hello.s

hello.bc: hello.c
	clang -c -emit-llvm -o hello.bc hello.c

clean:
	-rm -rf hello.s hello.bc
