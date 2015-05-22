#!/bin/bash

REMOTEINSTALL=/data/oi/mibench
REMOTEROOT=/data/oi//mibench/bin
NUMTESTS=5

function run_test {
    echo "adb -d shell 'time ${REMOTEROOT}/"${@}"' > timeoutput.txt" > run_test.sh
    chmod u+x run_test.sh

    timelargenat="99999"
    for iter in $(seq 1 $NUMTESTS); do
        ./run_test.sh
        [ $? != 0 ] && {
            echo Cannot run run_test.sh
            exit
        }
        timecand=$(cat timeoutput.txt | gawk '{print $1}' | cut -c 3- | sed 's/.$//')
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
    run_test ${1}"-nat-arm "${2}" "${3}" "${4}" "${5}" &> /dev/null"
    echo -ne " "

    run_test ${1}"-nolocals "${2}" "${3}" "${4}" "${5}" &> /dev/null"
    echo -ne " "

    run_test ${1}"-locals "${2}" "${3}" "${4}" "${5}" &> /dev/null"
    echo -ne " "

    # Exceptions...
    if [ x"${1}" = x"cjpeg" ]; then
        return
    fi

    run_test ${1}"-oneregion "${2}" "${3}" "${4}" "${5}" &> /dev/null"
    echo -ne " "
}

#scp rafael@ubuntuvm:~/p/openisa/mibench/testes-arm/bundle-arm.tar.bz2 ./bundle-arm.tar.bz2
#if [ $? -ne 0 ]; then
#    echo Failed to scp
#    exit
#fi
#adb -d shell mkdir -p ${REMOTEINSTALL} &&
#adb -d shell mkdir -p ${REMOTEINSTALL}/output &&
#adb -d push ./bundle-arm.tar.bz2 ${REMOTEINSTALL}/bundle-arm.tar.bz2 &&
#adb -d shell 'cd /data/oi && ./setup.sh'
#adb -d shell 'cd '${REMOTEINSTALL}' && tar xjvf bundle-arm.tar.bz2 && rm bundle-arm.tar.bz2'
#if [ $? -ne 0 ]; then
#    echo Failed to upload bundle to device.
#    exit
#fi

echo Times include delay of ~0.02s for USB communication
echo -ne "Index Program Native Globals Locals Whole\n"

echo -ne "1 basicmath " && run_family "basicmath_large" && echo -ne "\n"
echo -ne "2 bitcount " && run_family "bitcnts" "1125000" && echo -ne "\n"
echo -ne "3 susan-smoothing " && run_family "susan" "${REMOTEINSTALL}/input/input_susan.pgm" "${REMOTEINSTALL}/output/output_smoothing.pgm" "-s" && echo -ne "\n"
echo -ne "4 susan-edges " && run_family "susan" "${REMOTEINSTALL}/input/input_susan.pgm" "${REMOTEINSTALL}/output/output_edges.pgm" "-e" && echo -ne "\n"
echo -ne "5 susan-corners " && run_family "susan" "${REMOTEINSTALL}/input/input_susan.pgm" "${REMOTEINSTALL}/output/output_corners.pgm" "-c" && echo -ne "\n"
echo -ne "6 patricia " && run_family "patricia" "${REMOTEINSTALL}/input/large.udp" && echo -ne "\n"
echo -ne "7 dijkstra " && run_family "dijkstra_large" "${REMOTEINSTALL}/input/dijkstra.dat" && echo -ne "\n"
echo -ne "8 rijndael-encode " && run_family "rijndael" "${REMOTEINSTALL}/input/input_rijndael.asc" "${REMOTEINSTALL}/output/output_rijndael.enc" "e" "1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321" && echo -ne "\n"
echo -ne "9 rijndael-decode " && run_family "rijndael" "${REMOTEINSTALL}/input/input_rijndael.enc" "${REMOTEINSTALL}/output/output_rijndael.asc" "d" "1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321" && echo -ne "\n"
echo -ne "10 blowfish-encode " && run_family "bf" "e" "${REMOTEINSTALL}/input/input_blowfish.asc" "${REMOTEINSTALL}/output/output_blowfish.enc" "1234567890abcdeffedcba0987654321" && echo -ne "\n"
echo -ne "11 blowfish-decode " && run_family "bf" "d" "${REMOTEINSTALL}/input/input_blowfish.enc" "${REMOTEINSTALL}/output/output_blowfish.asc" && echo -ne "\n"
echo -ne "12 sha " && run_family "sha" "${REMOTEINSTALL}/input/input_sha.asc" && echo -ne "\n"
echo -ne "13 adpcm-encode " && run_family "rawcaudio" "< ${REMOTEINSTALL}/input/large.pcm" && echo -ne "\n"
echo -ne "14 adpcm-decode " && run_family "rawdaudio" "< ${REMOTEINSTALL}/input/large.adpcm" && echo -ne "\n"
echo -ne "15 crc " && run_family "crc" "${REMOTEINSTALL}/input/input.crc" && echo -ne "\n"
echo -ne "16 fft " && run_family "fft" '8 32768' && echo -ne "\n"
echo -ne "17 fft-inv " && run_family "fft" "8 32768 -i" && echo -ne "\n"
echo -ne "18 stringsearch " && run_family "search_large" && echo -ne "\n"
echo -ne "19 lame " && run_family "lame" "${REMOTEINSTALL}/input/large.wav" "${REMOTEINSTALL}/output/large.mp3" && echo -ne "\n"
#echo -ne "20 cjpeg " && run_family "cjpeg" "${REMOTEINSTALL}/input/input_jpeg.ppm" && echo -ne "\n"
