#!/bin/bash

LOGFILE=$(pwd)/log_perf_record.txt
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
    smallnat=${SMALL[index]//VAR/nat-x86}
    largenat=${LARGE[index]//VAR/nat-x86}
    smalloi=${SMALL[index]//VAR/oi-x86}
    largeoi=${LARGE[index]//VAR/oi-x86}
    inputsmall=${INPUTSMALL[index]}
    inputlarge=${INPUTLARGE[index]}
    outputsmallnat=${OUTPUTSMALL[index]//VAR/nat-x86}
    outputsmalloi=${OUTPUTSMALL[index]//VAR/oi-x86}
    outputlargenat=${OUTPUTLARGE[index]//VAR/nat-x86}
    outputlargeoi=${OUTPUTLARGE[index]//VAR/oi-x86}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi
    cd $dir
    runnative=true
    for opts in "-oneregion" "-nolocals" "-debug-ir" "-abi-locals"; do
        # Exceptions...
        if [ x"$opts" = x"-oneregion" -a x"$name" = x"cjpeg" ]; then
            continue
        fi
        if [ x"$opts" = x"-oneregion" -a x"$name" = x"djpeg" ]; then
            continue
        fi
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

        if [ x"$runnative" != x"false" ]; then
            echo Running $name in native mode "(large)" - current time is $(date) | tee -a $LOGFILE
            sudo schedtool -F -p 99 -a 0x4 -e perf record -q ./${largenat} > /dev/null
            sudo perf report --sort=dso >> $LOGFILE
            runnative=false
        fi

        echo Running $name OpenISA mode "(large)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        sudo schedtool -F -p 99 -a 0x4 -e perf record -q ./${largeoi} > /dev/null
        sudo perf report --sort=dso >> $LOGFILE
        SBTOPT="$myopts" make clean &> /dev/null

    done;
    cd $ROOT
done
