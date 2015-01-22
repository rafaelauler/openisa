#!/bin/bash

ARMDIR=$(pwd)/testes-arm

DIRS=(automotive/basicmath
automotive/susan
network/patricia
network/dijkstra
security/rijndael
telecomm/FFT)
ACTIVATE=(yes #basicmath
yes #susan-smoothing
yes #patricia
yes #dijkstra
yes #rijndael-encode
yes) #fft-inv
NAMES=(basicmath_large
susan
patricia
dijkstra_large
rijndael
fft)
ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi

    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir"; do
	ARCH="arm" make clean
	ARCH="x86" make clean
	SBTOPT="-optimize "${opts} ARCH="arm" MATTR="-mattr=vfp3,d16,a8,-neon -mcpu=cortex-a9 -float-abi=hard" make
	if [ $? != 0 ]; then
           echo Stopping script at $dir
            exit
	fi
	mkdir -p ${ARMDIR}/bin
	cp ${name}-nat-arm ${ARMDIR}/bin
	if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	fi
	if [ $opts == "-debug-ir" ]; then
	    cp ${name}-oi-arm ${ARMDIR}/bin/${name}-locals
	else
	    cp ${name}-oi-arm ${ARMDIR}/bin/${name}${opts}
	fi
	if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	fi
	#arm-linux-musleabihf-gcc -O3 -static ${dir}.c -o ${dir}-nat-arm
    done
    cd ${ROOT}
done
