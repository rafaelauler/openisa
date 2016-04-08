#!/bin/bash

GSED=sed
LOGFILE=$(pwd)/log-check.txt
ROOTDIR=$(pwd)
VERBOSE=false

# Choose the simulator to run OpenISA code
SIMULATOR="openisa.x --load="
#SIMULATOR="oii "

echo Checking started. Today is $(date). | tee -a $LOGFILE

for dir in $(find . -maxdepth 2 -mindepth 1 -type d | cut -c 3-); do
    if [ $dir == "calc" ]; then
        echo Skipping calc folder
        continue
    fi
    if [[ $dir == testes-arm* ]]; then
        echo Skipping testes-arm folder
        continue
    fi
    if [ $dir == "hello-world" ]; then
        echo Skipping hello-world folder
        continue
    fi
    if [ $dir == "ackermann" ] ||
           [ $dir == "array" ] ||
           [ $dir == "fib" ] ||
           [ $dir == "heapsort" ] ||
           [ $dir == "lists" ] ||
           [ $dir == "matrix" ] ||
           [ $dir == "random" ] ||
           [ $dir == "sieve" ]; then
        echo Skipping large benchmarks folder
        continue
    fi
    if [ $dir == "moments" ]; then
        echo Skipping moments folder
        continue
    fi
    cd ${ROOTDIR}
    cd $dir
    make clean &> /dev/null
    echo -ne "$dir : \t\t" | tee -a $LOGFILE
    if [ x"$VERBOSE" == x"false" ]; then
        make &> /dev/null
        OUT=$?
    else
        make
        OUT=$?
    fi
    if [ $OUT -ne 0 ]; then
        echo "BUILD FAIL!\n" | tee -a $LOGFILE
	      continue
    fi
	  file=${dir}
    if [[ $dir == micro* ]]; then
        file=simple
	  fi
	  if [ -e testcase.txt ]; then
	      ./${file}-nat-x86 > out-golden.txt < testcase.txt
	      ${SIMULATOR}${file}-oi > out-oi.txt < testcase.txt 2> /dev/null
	  else
		    ./${file}-nat-x86 > out-golden.txt
        ${SIMULATOR}${file}-oi > out-oi.txt 2> /dev/null
	  fi
    diff out-golden.txt out-oi.txt &> /dev/null
    if [ $? -ne 0 ]; then
        echo "FAIL!" | tee -a $LOGFILE
	  else
        echo "PASS!" | tee -a $LOGFILE
    fi
    rm out-golden.txt out-oi.txt
done
cd ${ROOTDIR}
