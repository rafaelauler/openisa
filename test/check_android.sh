#!/bin/bash

REMOTEINSTALL=/data/oi
REMOTEROOT=/data/oi/binarios
NUMTESTS=3

function run_test {
    echo "gtime -f'%e' -otimeoutput.txt adb -d shell ${REMOTEROOT}/"${1} > run_test.sh
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
    run_test ${1}"-nat-arm &> out-golden.txt"
    echo -ne " "

    run_test ${1}"-nolocals &> out.txt"

    diff out-golden.txt out.txt &> /dev/null
    if [ $? -ne 0 ]; then
        echo -ne "!! "
    else
        echo -ne " "
    fi
    rm out.txt

    run_test ${1}"-locals &> out.txt"

    diff out-golden.txt out.txt &> /dev/null
    if [ $? -ne 0 ]; then
        echo -ne "!! "
    else
        echo -ne " "
    fi
    rm out.txt

    run_test ${1}"-oneregion &> out.txt"

    diff out-golden.txt out.txt &> /dev/null
    if [ $? -ne 0 ]; then
        echo -ne "!! "
    else
        echo -ne " "
    fi
    rm out.txt
    rm out-golden.txt
}

scp rafael@172.16.169.130:~/p/openisa/test/testes-arm/bundle-arm.tar.bz2 ./bundle-arm.tar.bz2
if [ $? -ne 0 ]; then
    echo Failed to scp
    exit
fi
adb -d shell mkdir -p ${REMOTEINSTALL} &&
adb -d push ./bundle-arm.tar.bz2 ${REMOTEINSTALL}/bundle-arm.tar.bz2 &&
adb -d shell 'cd /data/oi && ./setup.sh'
adb -d shell 'cd '${REMOTEINSTALL}' && tar xjvf bundle-arm.tar.bz2 && rm bundle-arm.tar.bz2'
if [ $? -ne 0 ]; then
    echo Failed to upload bundle to device.
    exit
fi

echo Times include delay of ~0.02s for USB communication
echo -ne "Index Program Native Globals Locals Whole\n"

#echo -ne "1 fib " && run_family "fib" && echo -ne "\n"
echo -ne "1 matrix " && run_family "matrix" && echo -ne "\n"
echo -ne "1 heapsort " && run_family "heapsort" && echo -ne "\n"
#echo -ne "1 ackermann " && run_family "ackermann" && echo -ne "\n"
echo -ne "1 sieve " && run_family "sieve" && echo -ne "\n"
echo -ne "1 array " && run_family "array" && echo -ne "\n"
echo -ne "1 lists " && run_family "lists" && echo -ne "\n"
echo -ne "1 random " && run_family "random" && echo -ne "\n"
