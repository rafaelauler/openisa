#!/bin/bash

for dir in $(find . -maxdepth 1 -mindepth 1 -type d | cut -c 3-); do
    if [ $dir == "calc" ]; then
        continue
    fi
    if [ $dir == "micro" ]; then
        continue
    fi
    if [ $dir == "hello-world" ]; then
        continue
    fi
    if [ $dir == "testes-arm" ]; then
        continue
    fi
    if [ $dir == "testes-x86" ]; then
        continue
    fi
    if [ $dir == "moments" ]; then
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir" "-abi-locals"; do
	make clean
	SBTOPT="-optimize "${opts} ARCH="arm" MATTR="-mattr=vfp3,d16,a8,-neon -mcpu=cortex-a9 -float-abi=hard" make
	if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	fi
	cp ${dir}-nat-arm ../testes-arm/binarios
	if [ $opts == "-debug-ir" ]; then
	    cp ${dir}-oi-arm ../testes-arm/binarios/${dir}-locals
	else
	    cp ${dir}-oi-arm ../testes-arm/binarios/${dir}${opts}
	fi	
	if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	fi	
	#arm-linux-musleabihf-gcc -O3 -static ${dir}.c -o ${dir}-nat-arm
    done
    cd ..
done
