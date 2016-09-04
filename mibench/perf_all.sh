#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log_perf.txt
# Number of times each binary execution is measured
NUMTESTS=10
VERBOSE=false

echo Tests started. Today is $(date). | tee -a $LOGFILE

DIRS=(automotive/basicmath
automotive/bitcount
automotive/susan
automotive/susan
automotive/susan
network/patricia
network/dijkstra
security/rijndael
security/rijndael
security/blowfish
security/blowfish
security/sha
telecomm/adpcm
telecomm/adpcm
telecomm/CRC32
telecomm/FFT
telecomm/FFT
office/stringsearch
consumer/lame/lame3.70
consumer/jpeg/jpeg-6a
consumer/jpeg/jpeg-6a)
ACTIVATE=(yes #basicmath
yes #bitcount
yes #susan-smoothing
yes #susan-edges
yes #susan-corners
yes #patricia
yes #dijkstra
yes #rijndael-encode
yes #rijndael-decode
yes #blowfish-encode
yes #blowfish-decode
yes #sha
yes #adpcm coder
yes #adpcm decoder
yes #crc32
yes #fft
yes #fft-inv
yes #stringsearch
yes #lame
yes #cjpeg
yes) #djpeg
#ACTIVATE=(yes #basicmath
#yes #bitcount
#yes #susan-smoothing
#yes #susan-edges
#yes #susan-corners
#yes #patricia
#yes #dijkstra
#yes #rijndael-encode
#yes #rijndael-decode
#yes #fft
#yes) #fft-inv
SMALL=(basicmath_small-VAR
"bitcnts-VAR 1000000"
"susan-VAR input_small.pgm output.smoothing-small-VAR.pgm -s"
"susan-VAR input_small.pgm output.edges-small-VAR.pgm -e"
"susan-VAR input_small.pgm output.corners-small-VAR.pgm -c"
"patricia-VAR small.udp"
"dijkstra_small-VAR input.dat"
"rijndael-VAR input_small.asc output_small-VAR.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"rijndael-VAR input_small.enc output_small-VAR.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"bf-VAR e input_small.asc output_small-VAR.enc 1234567890abcdeffedcba0987654321"
"bf-VAR d input_small.enc output_small-VAR.dec 1234567890abcdeffedcba0987654321"
"sha-VAR input_small.asc"
"rawcaudio-VAR"
"rawdaudio-VAR"
"crc-VAR ../../network/patricia/large.udp"
"fft-VAR 4 4096"
"fft-VAR 4 8192 -i"
"search_small-VAR"
"lame-VAR ../small.wav output-sm-VAR.mp3"
"cjpeg-VAR ../input_small.ppm"
"djpeg-VAR ../input_small.jpg")
LARGE=(basicmath_large-VAR
"bitcnts-VAR 10000000"
"susan-VAR input_large.pgm output.smoothing-large-VAR.pgm -s"
"susan-VAR input_large.pgm output.edges-large-VAR.pgm -e"
"susan-VAR input_large.pgm output.corners-large-VAR.pgm -c"
"patricia-VAR large.udp"
"dijkstra_large-VAR input.dat"
"rijndael-VAR input_large.asc output_large-VAR.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"rijndael-VAR input_large.enc output_large-VAR.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"bf-VAR e input_large.asc output_large-VAR.enc 1234567890abcdeffedcba0987654321"
"bf-VAR d input_large.enc output_large-VAR.dec 1234567890abcdeffedcba0987654321"
"sha-VAR input_large.asc"
"rawcaudio-VAR"
"rawdaudio-VAR"
"crc-VAR ../adpcm/data/large.pcm"
"fft-VAR 8 32768"
"fft-VAR 8 32768 -i"
"search_large-VAR"
"lame-VAR ../large.wav output-VAR.mp3"
"cjpeg-VAR ../input_large.ppm"
"djpeg-VAR ../input_large.jpg")
NAMES=(basicmath
bitcount
susan-smoothing
susan-edges
susan-corners
patricia
dijkstra
rijndael-encode
rijndael-decode
blowfish-encode
blowfish-decode
sha
adpcm-coder
adpcm-decoder
crc
fft
fft-inv
stringsearch
lame
cjpeg
djpeg)
INPUTSMALL=(none
none
none
none
none
none
none
none
none
none
none
none
data/small.pcm
data/small.adpcm
none
none
none
none
none
none
none)
INPUTLARGE=(none
none
none
none
none
none
none
none
none
none
none
none
data/large.pcm
data/large.adpcm
none
none
none
none
none
none
none)
OUTPUTSMALL=(none
none
output.smoothing-small-VAR.pgm
output.edges-small-VAR.pgm
output.corners-small-VAR.pgm
none
none
output_small-VAR.enc
output_small-VAR.dec
output_small-VAR.enc
output_small-VAR.dec
none
none
none
none
none
none
none
output-sm-VAR.mp3
none
none)
OUTPUTLARGE=(none
none
output.smoothing-large-VAR.pgm
output.edges-large-VAR.pgm
output.corners-large-VAR.pgm
none
none
output_large-VAR.enc
output_large-VAR.dec
output_large-VAR.enc
output_large-VAR.dec
none
none
none
none
none
none
none
output-VAR.mp3
none
none)

ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    smallnat=${SMALL[index]//VAR/nat-x86}
    largenat=${LARGE[index]//VAR/nat-x86}
    smalloi=${SMALL[index]//VAR/oi-x86}
    largeoi=${LARGE[index]//VAR/oi-x86}
    inputsmall=${INPUTSMALL[index]}
    inputlarge=${INPUTLARGE[index]}
    outputsmallnat=${OUTPUTSMALL[index]//VAR/nat-x86}
    outputsmalloi=${OUTPUTSMALL[index]//VAR/oi-x86}
    outputlargenat=${OUTPUTLARGE[index]//VAR/nat-x86}
    outputlargeoi=${OUTPUTLARGE[index]//VAR/oi-x86}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir" "-abi-locals"; do
        # Exceptions...
        if [ x"$opts" = x"-oneregion" -a x"$name" = x"cjpeg" ]; then
            myopts=$opts
        elif [ x"$opts" = x"-oneregion" -a x"$name" = x"djpeg" ]; then
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

        echo Running $name in native mode "(large)" - current time is $(date) | tee -a $LOGFILE
        if [ x"$inputlarge" != x"none" ]; then
            sudo schedtool -F -p 99 -a 0x4 -e perf stat ./${largenat} < $inputlarge 1> /dev/null 2>> $LOGFILE
        else
            sudo schedtool -F -p 99 -a 0x4 -e perf stat -r $NUMTESTS ./${largenat} 1> /dev/null 2>> $LOGFILE
        fi

        echo Running $name OpenISA mode "(large)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        if [ x"$inputlarge" != x"none" ]; then
            sudo schedtool -F -p 99 -a 0x4 -e perf stat ./${largeoi} < $inputlarge 1> /dev/null 2>> $LOGFILE
        else
            sudo schedtool -F -p 99 -a 0x4 -e perf stat -r $NUMTESTS ./${largeoi} 1> /dev/null 2>> $LOGFILE
        fi
        SBTOPT="$myopts" make clean &> /dev/null

    done;
    cd $ROOT
done
