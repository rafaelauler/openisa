#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log.txt
# Number of times each binary execution is measured
NUMTESTS=1
VERBOSE=false

echo Tests started. Today is $(date). | tee -a $LOGFILE

DIRS=(automotive/basicmath
automotive/susan
automotive/susan
automotive/susan)
SMALL=(basicmath_small-VAR
"susan-VAR input_small.pgm output.smoothing-small-VAR.pgm -s"
"susan-VAR input_small.pgm output.edges-small-VAR.pgm -e"
"susan-VAR input_small.pgm output.corners-small-VAR.pgm -c")
LARGE=(basicmath_large-VAR
"susan-VAR input_large.pgm output.smoothing-large-VAR.pgm -s"
"susan-VAR input_large.pgm output.edges-large-VAR.pgm -e"
"susan-VAR input_large.pgm output.corners-large-VAR.pgm -c")
NAMES=(basicmath
susan-smoothing
susan-edges
susan-corners)
OUTPUTSMALL=(none
output.smoothing-small-VAR.pgm
output.edges-small-VAR.pgm
output.corners-small-VAR.pgm)
OUTPUTLARGE=(none
output.smoothing-large-VAR.pgm
output.edges-large-VAR.pgm
output.corners-large-VAR.pgm)

ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    smallnat=${SMALL[index]/VAR/nat}
    largenat=${LARGE[index]/VAR/nat}
    smalloi=${SMALL[index]/VAR/oi-x86}
    largeoi=${LARGE[index]/VAR/oi-x86}
    outputsmallnat=${OUTPUTSMALL[index]/VAR/nat}
    outputsmalloi=${OUTPUTSMALL[index]/VAR/oi-x86}
    outputlargenat=${OUTPUTLARGE[index]/VAR/nat}
    outputlargeoi=${OUTPUTLARGE[index]/VAR/oi-x86}
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
            cd $ROOT
            exit
        fi

        echo Running $name in native mode "(small)" - current time is $(date) | tee -a $LOGFILE
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smallnat} &> out-small-golden.txt
            cat timeoutput.txt | tee -a $LOGFILE
            rm timeoutput.txt
        done

        echo Running $name in native mode "(large)" - current time is $(date) | tee -a $LOGFILE
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${largenat} &> out-large-golden.txt
            cat timeoutput.txt | tee -a $LOGFILE
            rm timeoutput.txt
        done

        echo Running $name OpenISA mode "(small)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smalloi} &> out-small-oi.txt
            cat timeoutput.txt | tee -a $LOGFILE
            rm timeoutput.txt
        done

        diff out-small-golden.txt out-small-oi.txt &> /dev/null
        if [ $? -ne 0 ]; then
            echo Output mismatch "(small)" | tee -a $LOGFILE
        fi
        rm out-small-golden.txt out-small-oi.txt
        if [ x"$outputsmallnat" != x"none" ]; then
            diff $outputsmallnat $outputsmalloi &> /dev/null
            if [ $? -ne 0 ]; then
                echo Output mismatch "(small)" | tee -a $LOGFILE
            fi
            rm $outputsmallnat $outputsmalloi
        fi

        echo Running $name OpenISA mode "(large)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${largeoi} &> out-large-oi.txt
            cat timeoutput.txt | tee -a $LOGFILE
            rm timeoutput.txt
        done

        diff out-large-golden.txt out-large-oi.txt
        if [ $? -ne 0 ]; then
            echo Output mismatch "(large)" | tee -a $LOGFILE
        fi
        rm out-large-golden.txt out-large-oi.txt
        if [ x"$outputlargenat" != x"none" ]; then
            diff $outputlargenat $outputlargeoi &> /dev/null
            if [ $? -ne 0 ]; then
                echo Output mismatch "(large)" | tee -a $LOGFILE
            fi
            rm $outputlargenat $outputlargeoi
        fi


    done;
    cd $ROOT
done