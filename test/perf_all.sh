#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log_perf.txt
# Number of times each binary execution is measured
NUMTESTS=10
VERBOSE=false

echo Tests started. Today is $(date). | tee -a $LOGFILE

DIRS=(ackermann
array
fib
heapsort
lists
matrix
random
sieve)
ACTIVATE=(yes #ackermann
yes #array
yes #fib
yes #heapsort
yes #lists
yes #matrix
yes #random
yes) #sieve
LARGE=(ackermann-VAR
array-VAR
fib-VAR
heapsort-VAR
lists-VAR
matrix-VAR
random-VAR
sieve-VAR)
NAMES=(ackermann
array
fib
heapsort
lists
matrix
random
sieve)

ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    largenat=${LARGE[index]//VAR/nat-x86}
    largeoi=${LARGE[index]//VAR/oi-x86}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir" "-abi-locals"; do
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
                make clean &> /dev/null
                SBTOPT="$myopts" make
            fi
            cd $ROOT
            exit
        fi

        echo Running $name in native mode "(large)" - current time is $(date) | tee -a $LOGFILE
        sudo schedtool -F -p 99 -a 0x4 -e perf stat -r $NUMTESTS ./${largenat} 1> /dev/null 2>> $LOGFILE

        echo Running $name OpenISA mode "(large)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        sudo schedtool -F -p 99 -a 0x4 -e perf stat -r $NUMTESTS ./${largeoi} 1> /dev/null 2>> $LOGFILE

        SBTOPT="$myopts" make clean &> /dev/null

    done;
    cd $ROOT
done
