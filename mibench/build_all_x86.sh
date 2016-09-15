#!/bin/bash

X86DIR=$(pwd)/testes-x86

DIRS=(automotive/basicmath
automotive/bitcount
automotive/susan
network/patricia
network/dijkstra
security/rijndael
security/blowfish
security/sha
telecomm/adpcm
telecomm/adpcm
telecomm/CRC32
telecomm/FFT
office/stringsearch
consumer/lame/lame3.70
consumer/jpeg/jpeg-6a)
ACTIVATE=(yes #basicmath
yes #bitcount
yes #susan
yes #patricia
yes #dijkstra
yes #rijndael
yes #blowfish
yes #sha
yes #adpcm-coder
yes #adpcm-decoder
yes #crc32
yes #fft
yes #stringsearch
yes #lame
yes) #jpeg-6a
NAMES=(basicmath_large
bitcnts
susan
patricia
dijkstra_large
rijndael
bf
sha
rawcaudio
rawdaudio
crc
fft
search_large
lame
cjpeg)
ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi

    cd $dir
    for opts in "-oneregion" "-nolocals" "" "-abi-locals"; do
        # Exceptions...
        if [ x"$opts" = x"-oneregion" -a x"$name" = x"cjpeg" ]; then
            continue
        fi
        if [ x"$opts" = x"-oneregion" -a x"$name" = x"djpeg" ]; then
            continue
        fi
	      ARCH="arm" make clean
	      ARCH="x86" make clean
	      SBTOPT="-optimize "${opts} make
	      if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	      fi
	      mkdir -p ${X86DIR}/bin
	      cp ${name}-nat-x86 ${X86DIR}/bin
	      if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	      fi
	      if [ x"$opts" == x"" ]; then
	          cp ${name}-oi-x86 ${X86DIR}/bin/${name}-locals
	      else
	          cp ${name}-oi-x86 ${X86DIR}/bin/${name}${opts}
	      fi
	      if [ $? != 0 ]; then
            echo Stopping script at $dir
            exit
	      fi
    done
    cd ${ROOT}
done
