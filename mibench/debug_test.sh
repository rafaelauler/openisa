#!/bin/bash

REMOTEINSTALL=/data/oi/mibench
REMOTEROOT=/data/oi//mibench/bin
NUMTESTS=2

function run_test {
    echo "adb -d shell ${REMOTEROOT}/"${1} > run_test.sh
    chmod u+x run_test.sh

    ./run_test.sh
    [ $? != 0 ] && {
        echo Cannot run run_test.sh
        exit
    }
    rm run_test.sh
}

function run_family {
    run_test ${1}"-nat-arm &> out-golden.txt"
    echo -ne " "

    run_test ${1}"-nolocals &> out.txt"

    diff out-golden.txt out.txt
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

run_family "basicmath_large"
