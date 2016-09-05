#!/bin/bash

GSED=sed
LOGFILE=$(pwd)/log-check.txt
ROOTDIR=$(pwd)
VERBOSE=false

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
    if [ $dir == "moments" ]; then
        echo Skipping moments folder
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir" "-abi-locals"; do
        myopts=$opts" -optimize"
        make clean &> /dev/null
        echo -ne "$dir [ $myopts ] : \t\t" | tee -a $LOGFILE
        if [ x"$VERBOSE" == x"false" ]; then
            SBTOPT="$myopts" make &> /dev/null
            OUT=$?
        else
            SBTOPT="$myopts" make
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
	        ./${file}-oi-x86 > out-oi.txt < testcase.txt
	else
		./${file}-nat-x86 > out-golden.txt
        	./${file}-oi-x86 > out-oi.txt
	fi
        diff out-golden.txt out-oi.txt &> /dev/null
        if [ $? -ne 0 ]; then
            echo "FAIL!" | tee -a $LOGFILE
	else
            echo "PASS!" | tee -a $LOGFILE
        fi
        rm out-golden.txt out-oi.txt
    done;
    cd ${ROOTDIR}
done
