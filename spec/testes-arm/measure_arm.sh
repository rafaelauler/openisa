#!/bin/bash

REMOTEINSTALL=$(pwd)
REMOTEROOT=$(pwd)/bin
SPECWORKDIR=$(pwd)/input
MIBENCHWORKDIR=$(pwd)/bin
NUMTESTS=10

set -f noglob
mkdir -p output

function create_golden_files {
    if [ x"${1}" = x"susan" -a x"${4}" = x"-s" ]; then
        mv ${REMOTEINSTALL}/output/output_smoothing.pgm ${REMOTEINSTALL}/output/output_smoothing.pgm.golden &> /dev/null
    fi
    if [ x"${1}" = x"susan" -a x"${4}" = x"-e" ]; then
        mv ${REMOTEINSTALL}/output/output_edges.pgm ${REMOTEINSTALL}/output/output_edges.pgm.golden &> /dev/null
    fi
    if [ x"${1}" = x"susan" -a x"${4}" = x"-c" ]; then
        mv ${REMOTEINSTALL}/output/output_corners.pgm ${REMOTEINSTALL}/output/output_corners.pgm.golden &> /dev/null
    fi
    if [ x"${1}" = x"rijndael" -a x"${4}" = x"e" ]; then
        mv ${REMOTEINSTALL}/output/output_rijndael.enc ${REMOTEINSTALL}/output/output_rijndael.enc.golden &> /dev/null
    fi
    if [ x"${1}" = x"rijndael" -a x"${4}" = x"d" ]; then
        mv ${REMOTEINSTALL}/output/output_rijndael.asc ${REMOTEINSTALL}/output/output_rijndael.asc.golden &> /dev/null
    fi
    if [ x"${1}" = x"bf" -a x"${2}" = x"e" ]; then
        mv ${REMOTEINSTALL}/output/output_blowfish.enc ${REMOTEINSTALL}/output/output_blowfish.enc.golden &> /dev/null
    fi
    if [ x"${1}" = x"bf" -a x"${2}" = x"d" ]; then
        mv ${REMOTEINSTALL}/output/output_blowfish.asc ${REMOTEINSTALL}/output/output_blowfish.asc.golden &> /dev/null
    fi
    if [ x"${1}" = x"lame" ]; then
        mv ${REMOTEINSTALL}/output/large.mp3 ${REMOTEINSTALL}/output/output.mp3.golden &> /dev/null
    fi
}

function check_output_files {
    if [ x"${1}" = x"susan" -a x"${4}" = x"-s" ]; then
        diff ${REMOTEINSTALL}/output/output_smoothing.pgm ${REMOTEINSTALL}/output/output_smoothing.pgm.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! "
        else
            echo -ne " "
        fi
    fi
    if [ x"${1}" = x"susan" -a x"${4}" = x"-e" ]; then
        diff ${REMOTEINSTALL}/output/output_edges.pgm ${REMOTEINSTALL}/output/output_edges.pgm.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! "
        else
            echo -ne " "
        fi
    fi
    if [ x"${1}" = x"susan" -a x"${4}" = x"-c" ]; then
        diff ${REMOTEINSTALL}/output/output_corners.pgm ${REMOTEINSTALL}/output/output_corners.pgm.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! "
        else
            echo -ne " "
        fi
    fi
    if [ x"${1}" = x"rijndael" -a x"${4}" = x"e" ]; then
        diff ${REMOTEINSTALL}/output/output_rijndael.enc ${REMOTEINSTALL}/output/output_rijndael.enc.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! "
        else
            echo -ne " "
        fi
    fi
    if [ x"${1}" = x"rijndael" -a x"${4}" = x"d" ]; then
        diff ${REMOTEINSTALL}/output/output_rijndael.asc ${REMOTEINSTALL}/output/output_rijndael.asc.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! "
        else
            echo -ne " "
        fi
    fi
    if [ x"${1}" = x"bf" -a x"${2}" = x"e" ]; then
        diff ${REMOTEINSTALL}/output/output_blowfish.enc ${REMOTEINSTALL}/output/output_blowfish.enc.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! "
        else
            echo -ne " "
        fi
    fi
    if [ x"${1}" = x"bf" -a x"${2}" = x"d" ]; then
        diff ${REMOTEINSTALL}/output/output_blowfish.asc ${REMOTEINSTALL}/output/output_blowfish.asc.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "@@ "
        else
            echo -ne " "
        fi
    fi
    if [ x"${1}" = x"lame" ]; then
        diff ${REMOTEINSTALL}/output/large.mp3 ${REMOTEINSTALL}/output/output.mp3.golden &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "@@ "
        else
            echo -ne " "
        fi
    fi
}

function run_test_measure_time {
    echo "/usr/bin/time -f'%e' -otimeoutput.txt "${REMOTEROOT}"/"${@} > run_test.sh
    chmod u+x run_test.sh
    progname=$(cut -d' ' -f1 <<< ${@})
    progsuffix=$(cut -d'-' -f2 <<< $progname)

    echo -ne "mydata <- c(" > rscript.r
    sep=""
    for iter in $(seq 1 $NUMTESTS); do
        ./run_test.sh
        resultcand=$(cat timeoutput.txt | tail -n1)
        echo -ne "$sep$resultcand" >> rscript.r
        sep=","
        rm timeoutput.txt
    done
    echo -ne ")\n" >> rscript.r
    echo -ne "mymean <- mean(mydata)\n" >> rscript.r
    echo -ne "mymean\n" >> rscript.r
    echo -ne "mysd <- sd(mydata)\n" >> rscript.r
    echo -ne "mysd\n" >> rscript.r
    result=$(R --no-save < rscript.r | tail -n 6)
    mean=$(cut -d' ' -f4 <<< $result)
    sd=$(cut -d' ' -f12 <<< $result)
    if [ x"$progsuffix" == x"nat" ]; then
        NATMEAN=$mean
        NATSD=$sd
        rm run_test.sh
        rm rscript.r
        return
    fi
    echo -ne "mymean <- $mean / $NATMEAN\n" > rscript.r
    echo -ne "mysd <- mymean * sqrt(($sd / $mean) ^ 2 + ($NATSD /$NATMEAN) ^ 2) \
             \nmymean\nmysd\n" >> rscript.r
    result=$(R --no-save < rscript.r | tail -n 6)
    mean=$(cut -d' ' -f19 <<< $result)
    sd=$(cut -d' ' -f23 <<< $result)
    echo -ne "$mean " | tee -a $OUTSCENARIO
    echo -ne "$sd" | tee -a $OUTSCENARIO
    rm run_test.sh
    rm rscript.r
}

function run_test_check_output {
    echo "/usr/bin/time -f'%e' -otimeoutput.txt "${REMOTEROOT}"/"${@} > run_test.sh
    chmod u+x run_test.sh

    ./run_test.sh
    timecand=$(cat timeoutput.txt | tail -n1)
    rm timeoutput.txt
    rm run_test.sh
    echo -ne "$timecand"
}

function run_family {
    if [ $CHECKOUTPUT -eq 1 ]; then
        tailcmd="1> out-golden.txt"
    else
        tailcmd="1> /dev/null"
    fi

    $RUNSCENARIO ${1}"-nat-arm "${2}" "${3}" "${4}" "${5}" "$tailcmd
    echo -ne " "

    if [ $CHECKOUTPUT -eq 1 ]; then
        create_golden_files $@
        tailcmd="1> out.txt"
    else
        tailcmd="1> /dev/null"
    fi

    $RUNSCENARIO ${1}"-nolocals "${2}" "${3}" "${4}" "${5}" "$tailcmd
    if [ $CHECKOUTPUT -eq 1 ]; then
        diff out-golden.txt out.txt &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! " | tee -a $OUTSCENARIO
        else
            echo -ne " " | tee -a $OUTSCENARIO
        fi
        rm out.txt
    else
        echo -ne " " | tee -a $OUTSCENARIO
    fi

    $RUNSCENARIO ${1}"-locals "${2}" "${3}" "${4}" "${5}" "$tailcmd
    if [ $CHECKOUTPUT -eq 1 ]; then
        diff out-golden.txt out.txt &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! " | tee -a $OUTSCENARIO
        else
            echo -ne " " | tee -a $OUTSCENARIO
        fi
        rm out.txt
        check_output_files $@
    else
        echo -ne " " | tee -a $OUTSCENARIO
    fi

    $RUNSCENARIO ${1}"-oneregion "${2}" "${3}" "${4}" "${5}" "$tailcmd
    if [ $CHECKOUTPUT -eq 1 ]; then
        diff out-golden.txt out.txt &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! " | tee -a $OUTSCENARIO
        else
            echo -ne " " | tee -a $OUTSCENARIO
        fi
        rm out.txt
        check_output_files $@
    else
        echo -ne " " | tee -a $OUTSCENARIO
    fi

    $RUNSCENARIO ${1}"-abi-locals "${2}" "${3}" "${4}" "${5}" "$tailcmd
    if [ $CHECKOUTPUT -eq 1 ]; then
        diff out-golden.txt out.txt &> /dev/null
        if [ $? -ne 0 ]; then
            echo -ne "!! " | tee -a $OUTSCENARIO
        else
            echo -ne " " | tee -a $OUTSCENARIO
        fi
        rm out.txt
        rm out-golden.txt
        check_output_files $@
    else
        echo -ne " " | tee -a $OUTSCENARIO
    fi
}

function run_mibench {
    cd $MIBENCHWORKDIR
    echo -ne "1 basicmath " | tee -a $OUTSCENARIO && run_family "basicmath_large" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "2 bitcount " | tee -a $OUTSCENARIO && run_family "bitcnts" "1125000" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "3 susan-smoothing " | tee -a $OUTSCENARIO && run_family "susan" "${REMOTEINSTALL}/input/input_susan.pgm" "${REMOTEINSTALL}/output/output_smoothing.pgm" "-s" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "4 susan-edges " | tee -a $OUTSCENARIO && run_family "susan" "${REMOTEINSTALL}/input/input_susan.pgm" "${REMOTEINSTALL}/output/output_edges.pgm" "-e" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "5 susan-corners " | tee -a $OUTSCENARIO && run_family "susan" "${REMOTEINSTALL}/input/input_susan.pgm" "${REMOTEINSTALL}/output/output_corners.pgm" "-c" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "6 patricia " | tee -a $OUTSCENARIO && run_family "patricia" "${REMOTEINSTALL}/input/large.udp" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "7 dijkstra " | tee -a $OUTSCENARIO && run_family "dijkstra_large" "${REMOTEINSTALL}/input/dijkstra.dat" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "8 rijndael-encode " | tee -a $OUTSCENARIO && run_family "rijndael" "${REMOTEINSTALL}/input/input_rijndael.asc" "${REMOTEINSTALL}/output/output_rijndael.enc" "e" "1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "9 rijndael-decode " | tee -a $OUTSCENARIO && run_family "rijndael" "${REMOTEINSTALL}/input/input_rijndael.enc" "${REMOTEINSTALL}/output/output_rijndael.asc" "d" "1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "10 blowfish-encode " | tee -a $OUTSCENARIO && run_family "bf" "e" "${REMOTEINSTALL}/input/input_blowfish.asc" "${REMOTEINSTALL}/output/output_blowfish.enc" "1234567890abcdeffedcba0987654321" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "11 blowfish-decode " | tee -a $OUTSCENARIO && run_family "bf" "d" "${REMOTEINSTALL}/input/input_blowfish.enc" "${REMOTEINSTALL}/output/output_blowfish.asc" "1234567890abcdeffedcba0987654321" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "12 sha " | tee -a $OUTSCENARIO && run_family "sha" "${REMOTEINSTALL}/input/input_sha.asc" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "13 adpcm-encode " | tee -a $OUTSCENARIO && run_family "rawcaudio" "< ${REMOTEINSTALL}/input/large.pcm" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "14 adpcm-decode " | tee -a $OUTSCENARIO && run_family "rawdaudio" "< ${REMOTEINSTALL}/input/large.adpcm" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "15 crc " | tee -a $OUTSCENARIO && run_family "crc" "${REMOTEINSTALL}/input/input.crc" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "16 fft " | tee -a $OUTSCENARIO && run_family "fft" '8 32768' && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "17 fft-inv " | tee -a $OUTSCENARIO && run_family "fft" "8 32768 -i" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "18 stringsearch " | tee -a $OUTSCENARIO && run_family "search_large" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "19 lame " | tee -a $OUTSCENARIO && run_family "lame" "${REMOTEINSTALL}/input/large.wav" "${REMOTEINSTALL}/output/large.mp3" && echo -ne "\n" | tee -a $OUTSCENARIO
    #echo -ne "20 cjpeg " | tee -a $OUTSCENARIO && run_family "cjpeg" "${REMOTEINSTALL}/input/input_jpeg.ppm" && echo -ne "\n" | tee -a $OUTSCENARIO
}

function run_spec {
    cd $SPECWORKDIR
    echo -ne "1 401.bzip2 " | tee -a $OUTSCENARIO && run_family "401.bzip2" "input.program" "10" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "2 429.mcf " | tee -a $OUTSCENARIO && run_family "429.mcf" "inp.in" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "3 433.milc " | tee -a $OUTSCENARIO && run_family "433.milc" "< su3imp.in" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "4 456.hmmer " | tee -a $OUTSCENARIO && run_family "456.hmmer" "nph3.hmm swiss41" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "4 458.sjeng " | tee -a $OUTSCENARIO && run_family "458.sjeng" "train.txt" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "5 462.libquantum " | tee -a $OUTSCENARIO && run_family "462.libquantum" "143" "25" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "6 464.h264ref " | tee -a $OUTSCENARIO && run_family "464.h264ref" "-d foreman_train_encoder_baseline.cfg" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "7 470.lbm " | tee -a $OUTSCENARIO && run_family "470.lbm" "300" "reference.dat" "0" "1" "100_100_130_cf_b.of" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "8 482.sphinx3 " | tee -a $OUTSCENARIO && run_family "482.sphinx" "ctlfile" "." "args.an4" && echo -ne "\n" | tee -a $OUTSCENARIO
    echo -ne "9 998.specrand " | tee -a $OUTSCENARIO && run_family "998.specrand" "1255432124" "234923" && echo -ne "\n" | tee -a $OUTSCENARIO
}

function main_check_output {
    RUNSCENARIO="run_test_check_output"
    OUTSCENARIO="$REMOTEINSTALL/spec_check_output.csv"
    CHECKOUTPUT=1
    echo -ne "Index Program Native Globals Locals Whole Abi\n" | tee $OUTSCENARIO
    run_spec

    OUTSCENARIO="$REMOTEINSTALL/mibench_check_output.csv"
    echo -ne "Index Program Native Globals Locals Whole Abi\n" | tee $OUTSCENARIO
    run_mibench
}

function main_measure_runtime {
    RUNSCENARIO="run_test_measure_time"
    OUTSCENARIO="$REMOTEINSTALL/spec_runtime.csv"
    CHECKOUTPUT=0
    echo -ne "Index Program Globals GError Locals LError Whole WError Abi AError\n" | tee $OUTSCENARIO
    run_spec

    OUTSCENARIO="$REMOTEINSTALL/mibench_runtime.csv"
    echo -ne "Index Program Globals GError Locals LError Whole WError Abi AError\n" | tee $OUTSCENARIO
    run_mibench
}


main_check_output
main_measure_runtime
cd $REMOTEINSTALL
gnuplot < mibench.gnuplot
gnuplot < spec.gnuplot
