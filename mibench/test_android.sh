#!/bin/bash

REMOTEINSTALL=/data/oi/mibench
REMOTEROOT=/data/oi//mibench/bin
NUMTESTS=3

function run_test {
    echo "gtime -f'%e' -otimeoutput.txt adb -d shell ${REMOTEROOT}/"${@} > run_test.sh
    chmod u+x run_test.sh

    timelargenat="99999"
    for iter in $(seq 1 $NUMTESTS); do
        ./run_test.sh
        [ $? != 0 ] && {
            echo Cannot run run_test.sh
            exit
        }
        timecand=$(cat timeoutput.txt)
        dotest=$(bc <<< "scale=4; $timecand < $timelargenat")
        if [ x"$dotest" == x"1" ]; then
            timelargenat=$timecand
        fi
        rm timeoutput.txt
    done
    rm run_test.sh
    echo -ne "$timelargenat"
}

function run_family {
    run_test ${1}"-nat-arm "${2}" "${3}" "${4}" &> out-golden.txt"
    echo -ne " "

    run_test ${1}"-nolocals "${2}" "${3}" "${4}" &> out.txt"

    diff out-golden.txt out.txt &> /dev/null
    if [ $? -ne 0 ]; then
        echo -ne "!! "
    else
        echo -ne " "
    fi
    rm out.txt

    run_test ${1}"-locals "${2}" "${3}" "${4}" &> out.txt"

    diff out-golden.txt out.txt &> /dev/null
    if [ $? -ne 0 ]; then
        echo -ne "!! "
    else
        echo -ne " "
    fi
    rm out.txt

    run_test ${1}"-oneregion "${2}" "${3}" "${4}" &> out.txt"

    diff out-golden.txt out.txt &> /dev/null
    if [ $? -ne 0 ]; then
        echo -ne "!! "
    else
        echo -ne " "
    fi
    rm out.txt
    rm out-golden.txt
}

scp rafael@172.16.169.130:~/p/openisa/mibench/testes-arm/bundle-arm.tar.bz2 ./bundle-arm.tar.bz2
if [ $? -ne 0 ]; then
    echo Failed to scp
    exit
fi
adb -d shell mkdir -p ${REMOTEINSTALL} &&
adb -d push ./bundle-arm.tar.bz2 ${REMOTEINSTALL}/bundle-arm.tar.bz2 &&
adb -d shell 'cd '${REMOTEINSTALL}' && tar xjvf bundle-arm.tar.bz2 && rm bundle-arm.tar.bz2'
if [ $? -ne 0 ]; then
    echo Failed to upload bundle to device.
    exit
fi

echo Times include delay of ~0.02s for USB communication
echo -ne "Index Program Native Globals Locals Whole\n"

echo -ne "1 basicmath " && run_family "basicmath_large" && echo -ne "\n"
echo -ne "2 susan-smoothing " && run_family "../susan" "-s" && echo -ne "\n"
echo -ne "3 susan-edges " && run_family "../susan" "-e" && echo -ne "\n"
echo -ne "4 susan-corners " && run_family "../susan" "-c" && echo -ne "\n"
echo -ne "5 patricia " && run_family "patricia" "${REMOTEINSTALL}/input/large.udp" && echo -ne "\n"
echo -ne "6 dijkstra " && run_family "dijkstra_large" "${REMOTEINSTALL}/input/dijkstra.dat" && echo -ne "\n"
echo -ne "7 rijndael-encode " && run_family "../rijndael" "e" && echo -ne "\n"
echo -ne "8 rijndael-decode " && run_family "../rijndael" "d" && echo -ne "\n"
echo -ne "9 fft " && run_family "fft" '8 32768' && echo -ne "\n"
echo -ne "0 fft-inv " && run_family "fft" "8 32768 -i" && echo -ne "\n"
