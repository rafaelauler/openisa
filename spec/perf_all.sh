#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log_perf.txt
# Number of times each binary execution is measured
NUMTESTS=10
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
yes #456.hmmer
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
    for opts in "-oneregion" "-nolocals" "-debug-ir"; do
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

        cd run
        echo Running $name in native mode "(small)" - current time is $(date) | tee -a $LOGFILE
        if [ x"$inputsmall" != x"none" ]; then
            sudo schedtool -F -p 99 -a 0x4 -e perf stat ./${smallnat} < $inputsmall 1> /dev/null 2>> $LOGFILE
        else
            sudo schedtool -F -p 99 -a 0x4 -e perf stat -r $NUMTESTS ./${smallnat} 1> /dev/null 2>> $LOGFILE
        fi

        echo Running $name OpenISA mode "(small)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        if [ x"$inputsmall" != x"none" ]; then
            sudo schedtool -F -p 99 -a 0x4 -e perf stat ./${smalloi} < $inputsmall 1> /dev/null 2>> $LOGFILE
        else
            sudo schedtool -F -p 99 -a 0x4 -e perf stat -r $NUMTESTS ./${smalloi} 1> /dev/null 2>> $LOGFILE
        fi

        cd ..
        SBTOPT="$myopts" make clean &> /dev/null

    done;
    cd $ROOT
done
