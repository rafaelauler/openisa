#!/bin/bash

GSED=sed
VERBOSE=false

echo Check started. Today is $(date).

DIRS=(automotive/basicmath
automotive/bitcount
automotive/susan
automotive/susan
automotive/susan
network/patricia
network/dijkstra
security/rijndael
security/rijndael
telecomm/FFT
telecomm/FFT
consumer/lame/lame3.70)
ACTIVATE=(yes #basicmath
yes #bitcount
yes #susan-smoothing
yes #susan-edges
yes #susan-corners
yes #patricia
yes #dijkstra
yes #rijndael-encode
yes #rijndael-decode
yes #fft
yes #fft-inv
yes) #lame
CHECKSTDOUT=(yes #basicmath
yes #bitcount
yes #susan-smoothing
yes #susan-edges
yes #susan-corners
yes #patricia
yes #dijkstra
yes #rijndael-encode
yes #rijndael-decode
yes #fft
yes #fft-inv
no) #lame
SMALL=(basicmath_small-VAR
"bitcnts-VAR 1000000"
"susan-VAR input_small.pgm output.smoothing-small-VAR.pgm -s"
"susan-VAR input_small.pgm output.edges-small-VAR.pgm -e"
"susan-VAR input_small.pgm output.corners-small-VAR.pgm -c"
"patricia-VAR small.udp"
"dijkstra_small-VAR input.dat"
"rijndael-VAR input_small.asc output_small-VAR.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"rijndael-VAR input_small.enc output_small-VAR.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"fft-VAR 4 4096"
"fft-VAR 4 8192 -i"
"lame-VAR ../small.wav output-sm-VAR.mp3")
LARGE=(basicmath_large-VAR
"bitcnts-VAR 10000000"
"susan-VAR input_large.pgm output.smoothing-large-VAR.pgm -s"
"susan-VAR input_large.pgm output.edges-large-VAR.pgm -e"
"susan-VAR input_large.pgm output.corners-large-VAR.pgm -c"
"patricia-VAR large.udp"
"dijkstra_large-VAR input.dat"
"rijndael-VAR input_large.asc output_large-VAR.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"rijndael-VAR input_large.enc output_large-VAR.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"fft-VAR 8 32768"
"fft-VAR 8 32768 -i"
"lame-VAR ../large.wav output-VAR.mp3")
NAMES=(basicmath
bitcount
susan-smoothing
susan-edges
susan-corners
patricia
dijkstra
rijndael-encode
rijndael-decode
fft
fft-inv
lame)
OUTPUTSMALL=(none
none
output.smoothing-small-VAR.pgm
output.edges-small-VAR.pgm
output.corners-small-VAR.pgm
none
none
output_small-VAR.enc
output_small-VAR.dec
none
none
output-sm-VAR.mp3)
OUTPUTLARGE=(none
none
output.smoothing-large-VAR.pgm
output.edges-large-VAR.pgm
output.corners-large-VAR.pgm
none
none
output_large-VAR.enc
output_large-VAR.dec
none
none
output-VAR.mp3)

ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    smallnat=${SMALL[index]//VAR/nat-x86}
    largenat=${LARGE[index]//VAR/nat-x86}
    smalloi=${SMALL[index]//VAR/oi-x86}
    largeoi=${LARGE[index]//VAR/oi-x86}
    outputsmallnat=${OUTPUTSMALL[index]//VAR/nat-x86}
    outputsmalloi=${OUTPUTSMALL[index]//VAR/oi-x86}
    outputlargenat=${OUTPUTLARGE[index]//VAR/nat-x86}
    outputlargeoi=${OUTPUTLARGE[index]//VAR/oi-x86}
    checkstdoutput=${CHECKSTDOUT[index]}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir"; do
        myopts=$opts" -optimize"
        make clean &> /dev/null
        echo -ne "$dir [ $myopts ] : \t\t"
        if [ x"$VERBOSE" == x"false" ]; then
            SBTOPT="$myopts" make &> /dev/null
            OUT=$?
        else
            SBTOPT="$myopts" make
            OUT=$?
        fi
        if [ $OUT -ne 0 ]; then
            echo Build failed. Program: $dir Options: $myopts
            if [ x"$VERBOSE" == x"false" ]; then
                echo Running make verbose:
                make clean &> /dev/null
                SBTOPT="$myopts" make       
            fi
            cd $ROOT
            exit
        fi

        ./${smallnat} &> out-small-golden.txt
        ./${largenat} &> out-large-golden.txt
        ./${smalloi} &> out-small-oi.txt
	if [ x"$checkstdoutput" != x"no" ]; then
	        diff out-small-golden.txt out-small-oi.txt &> /dev/null
        	if [ $? -ne 0 ]; then
        	    echo "FAIL! (small input)"
        	fi
	fi
        rm out-small-golden.txt out-small-oi.txt
        if [ x"$outputsmallnat" != x"none" ]; then
            diff $outputsmallnat $outputsmalloi &> /dev/null
            if [ $? -ne 0 ]; then
                echo "FAIL! (small input)"
            fi
            rm $outputsmallnat $outputsmalloi
        fi

        ./${largeoi} &> out-large-oi.txt
	if [ x"$checkstdoutput" != x"no" ]; then
	        diff out-large-golden.txt out-large-oi.txt &> /dev/null
        	if [ $? -ne 0 ]; then
        	    echo "FAIL! (large input)"
        	fi
	fi
        rm out-large-golden.txt out-large-oi.txt
        if [ x"$outputlargenat" != x"none" ]; then
            diff $outputlargenat $outputlargeoi &> /dev/null
            if [ $? -ne 0 ]; then
                echo "FAIL! (large input)"
            fi
            rm $outputlargenat $outputlargeoi
        fi
        SBTOPT="$myopts" make clean &> /dev/null
	echo "PASS!"

    done;
    cd $ROOT
done
