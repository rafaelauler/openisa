#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log.txt
# Number of times each binary execution is measured
NUMTESTS=3
VERBOSE=false

echo Tests started. Today is $(date). | tee -a $LOGFILE

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
no  #456.hmmer
yes #458.sjeng
yes #462.libquantum
yes #464.h264ref
yes #470.lbm
yes #482.sphinx3
yes) #998.specrand
SMALL=("../bzip2-VAR input.source 280"
"../429.mcf-VAR inp.in"
"../433.milc-VAR"
"../456.hmmer-VAR nph3.hmm swiss41"
"../458.sjeng-VAR ref.txt"
"../462.libquantum-VAR 1397 8"
"../464.h264ref-VAR -d foreman_ref_encoder_baseline.cfg"
"../470.lbm-VAR 3000 reference.dat 0 0 100_100_130_ldc.of"
"../482.sphinx-VAR ctlfile . args.an4"
"../998.specrand-VAR 1255432124 234923")
NAMES=(401.bzip2
429.mcf
433.milc
456.hmmer
458.sjeng
462.libquantum
464.h264ref
470.lbm
482.sphinx3
998.specrand)
INPUTSMALL=(none
none
su3imp.in
none
none
none
none
none
none
none)
OUTPUTSMALL=(none
none
none
none
none
none
none
none
none
none)

ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    smallnat=${SMALL[index]//VAR/nat-x86}
    smalloi=${SMALL[index]//VAR/oi-x86}
    inputsmall=${INPUTSMALL[index]}
    outputsmallnat=${OUTPUTSMALL[index]//VAR/nat-x86}
    outputsmalloi=${OUTPUTSMALL[index]//VAR/oi-x86}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" ""; do
        if [ x"$name" = x"458.sjeng" ]; then
            myopts=$opts
        else
            myopts=$opts" -optimize"
        fi
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

        echo Running $name in native mode "(small)" - current time is $(date) | tee -a $LOGFILE
        cd run
        timesmallnat="99999"
        for iter in $(seq 1 $NUMTESTS); do
            if [ x"$inputsmall" != x"none" ]; then
                $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smallnat} < $inputsmall &> /dev/null
            else
                $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smallnat} &> /dev/null
            fi
            cat timeoutput.txt | tee -a $LOGFILE
            timecand=$(cat timeoutput.txt)
            dotest=$(bc <<< "scale=4; $timecand < $timesmallnat")
            if [ x"$dotest" == x"1" ]; then
                timesmallnat=$timecand
            fi
            rm timeoutput.txt
        done
        if [ x"$iter" != x"1" ]; then
            echo -------- | tee -a $LOGFILE
            echo $timesmallnat | tee -a $LOGFILE
        fi

        echo Running $name OpenISA mode "(small)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        smallesttime="99999"
        for iter in $(seq 1 $NUMTESTS); do
            if [ x"$inputsmall" != x"none" ]; then
                $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smalloi} < $inputsmall &> /dev/null
            else
                $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smalloi} &> /dev/null
            fi
            curtime=$(cat timeoutput.txt)
            percentage=$(bc <<< "scale=4; $curtime / $timesmallnat")
            echo $curtime "("${percentage}")" | tee -a $LOGFILE
            dotest=$(bc <<< "scale=4; $curtime < $smallesttime")
            if [ x"$dotest" == x"1" ]; then
                smallesttime=$curtime
            fi
            rm timeoutput.txt
        done
        if [ x"$iter" != x"1" ]; then
            echo -------- | tee -a $LOGFILE
            percentage=$(bc <<< "scale=4; $smallesttime / $timesmallnat")
            echo $smallesttime "("${percentage}")" | tee -a $LOGFILE
        fi

        cd ..
        SBTOPT="$myopts" make clean &> /dev/null

    done;
    cd $ROOT
done
