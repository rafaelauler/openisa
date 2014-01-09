#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log.txt
# Number of times each binary execution is measured
NUMTESTS=1
VERBOSE=false

echo Tests started. Today is $(date). | tee -a $LOGFILE

for dir in $(find . -maxdepth 1 -mindepth 1 -type d | cut -c 3-); do
    if [ $dir == "calc" ]; then
        echo Skipping calc folder
        continue
    fi
    if [ $dir == "testes-arm" ]; then
        echo Skipping testes-arm folder
        continue
    fi
    if [ $dir == "micro" ]; then
        echo Skipping micro folder
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
    for opts in "-oneregion" "-nolocals" "-debug-ir"; do
        myopts=$opts" -optimize"
        make clean &> /dev/null
        echo Building $dir with mode $myopts ...
        if [ x"$VERBOSE" == x"false" ]; then
            SBTOPT="$myopts" make &> /dev/null
            OUT=$?
        else
            SBTOPT="$myopts" make
            OUT=$?
        fi
        if [ $OUT -ne 0 ]; then
            echo Build failed. Program: $dir Options: $myopts | tee -a $LOGFILE
            if [ x"$VERBOSE" == x"false" ]; then
                echo Running make verbose:
                SBTOPT="$myopts" make       
            fi
            cd ..
            exit
        fi
        echo Running $dir native mode - current time is $(date) | tee -a $LOGFILE
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${dir}-nat | tee out-golden.txt
            cat timeoutput.txt | tee -a $LOGFILE
            rm timeoutput.txt
        done

        echo Running $dir OpenISA mode with opts $myopts - current time is $(date) | tee -a $LOGFILE
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${dir}-oi-x86 | tee out-oi.txt
            cat timeoutput.txt | tee -a $LOGFILE
            rm timeoutput.txt
        done

        diff out-golden.txt out-oi.txt
        if [ $? -ne 0 ]; then
            echo Output mismatch | tee -a $LOGFILE
        fi
        rm out-golden.txt out-oi.txt
    done;
    cd ..
done