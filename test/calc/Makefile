

all: calc.s


calc.s: calc.bc
	llc -load=../../backend/OIBackend.so -march=oi calc.bc -o calc.s

calc.bc: calc.c
	clang -c -emit-llvm -o calc.bc calc.c

clean:
	-rm -rf calc.s calc.bc
