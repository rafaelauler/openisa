#!/bin/bash

ARMDIR=$(pwd)/testes-arm

DIRS=(401.bzip2
429.mcf
433.milc
456.hmmer
458.sjeng
462.libquantum
464.h264ref
470.lbm
482.sphinx3
998.specrand)
ACTIVATE=(yes #401.bzip
yes #429.mcf
yes #433.milc
yes #456.hmmer
yes #458.sjeng
yes #462.libquantum
yes #464.h264ref
yes #470.lbm
yes #482.sphinx3
yes) #998.specrand
NAMES=(401.bzip2
429.mcf
433.milc
456.hmmer
458.sjeng
462.libquantum
464.h264ref
470.lbm
482.sphinx
998.specrand)
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
    first=1
    for opts in "-oneregion" "-nolocals" "" "-abi-locals"; do
        if [ x"$name" = x"458.sjeng" ]; then
            myopts=$opts
        else
            myopts=$opts" -optimize"
        fi
	      ARCH="arm" make clean
	      ARCH="x86" make clean
        if [ $first == 1 ]; then
	          SBTOPT=${myopts} ARCH="arm" MATTR="-mattr=vfp3,d16,a8,-neon -mcpu=cortex-a9 -float-abi=hard" make
        else
	          SBTOPT=${myopts} ARCH="arm" MATTR="-mattr=vfp3,d16,a8,-neon -mcpu=cortex-a9 -float-abi=hard" make ${name}-oi-arm
        fi
	      if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	      fi
	      mkdir -p ${ARMDIR}/bin
        if [ $first == 1 ]; then
	          cp ${name}-nat-arm ${ARMDIR}/bin
	          if [ $? != 0 ]; then
                echo Stopping script at $dir
                exit
	          fi
            first=0
        fi
	      if [ x"$opts" == x"" ]; then
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
