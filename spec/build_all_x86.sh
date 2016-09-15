#!/bin/bash

X86DIR=$(pwd)/testes-x86

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
no) #998.specrand
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
    for opts in "-oneregion" "-nolocals" "-debug-ir" "-abi-locals"; do
        if [ x"$name" = x"458.sjeng" ]; then
            myopts=$opts
        else
            myopts=$opts" -optimize"
        fi
	      ARCH="arm" make clean
	      ARCH="x86" make clean
        if [ $first == 1 ]; then
	          SBTOPT=${myopts} make
        else
	          SBTOPT=${myopts} make ${name}-oi-x86
        fi
	      if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	      fi
	      mkdir -p ${X86DIR}/bin
        if [ $first == 1 ]; then
	          cp ${name}-nat-x86 ${X86DIR}/bin
	          if [ $? != 0 ]; then
                echo Stopping script at $dir
                exit
	          fi
            first=0
        fi
	      if [ $opts == "-debug-ir" ]; then
	          cp ${name}-oi-x86 ${X86DIR}/bin/${name}-locals
	      else
	          cp ${name}-oi-x86 ${X86DIR}/bin/${name}${opts}
	      fi
	      if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	      fi
    done
    cd ${ROOT}
done
