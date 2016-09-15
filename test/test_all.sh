#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log.txt
# Number of times each binary execution is measured
NUMTESTS=10
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
    for opts in "-oneregion" "-nolocals" ""; do
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
        timenat="99999"
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${dir}-nat-x86 | tee out-golden.txt
            cat timeoutput.txt | tee -a $LOGFILE
            curtime=$(cat timeoutput.txt)
            dotest=$(bc <<< "scale=4; $curtime < $timenat")
            if [ x"$dotest" == x"1" ]; then
                timenat=$curtime
            fi
            rm timeoutput.txt
        done
        if [ x"$iter" != x"1" ]; then
            echo -------- | tee -a $LOGFILE
            echo $timenat | tee -a $LOGFILE
        fi

        echo Running $dir OpenISA mode with opts $myopts - current time is $(date) | tee -a $LOGFILE
        smallesttime="99999"
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${dir}-oi-x86 | tee out-oi.txt
            curtime=$(cat timeoutput.txt)
            percentage=$(bc <<< "scale=4; $curtime / $timenat")
            echo $curtime "("${percentage}")" | tee -a $LOGFILE
            dotest=$(bc <<< "scale=4; $curtime < $smallesttime")
            if [ x"$dotest" == x"1" ]; then
                smallesttime=$curtime
            fi
            rm timeoutput.txt
        done
        if [ x"$iter" != x"1" ]; then
            echo -------- | tee -a $LOGFILE
            percentage=$(bc <<< "scale=4; $smallesttime / $timenat")
            echo $smallesttime "("${percentage}")" | tee -a $LOGFILE
        fi

        diff out-golden.txt out-oi.txt
        if [ $? -ne 0 ]; then
            echo "!! Output mismatch !!" | tee -a $LOGFILE
        fi
        rm out-golden.txt out-oi.txt
    done;
    cd ..
done
