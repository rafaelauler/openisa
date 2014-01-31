#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=$(pwd)/log.txt
# Number of times each binary execution is measured
NUMTESTS=10
VERBOSE=false

echo Tests started. Today is $(date). | tee -a $LOGFILE

DIRS=(automotive/basicmath
automotive/susan
automotive/susan
automotive/susan
network/patricia
network/dijkstra
security/rijndael
security/rijndael
telecomm/FFT
telecomm/FFT)
ACTIVATE=(yes #basicmath
yes #susan-smoothing
yes #susan-edges
yes #susan-corners
yes #patricia
yes #dijkstra
yes #rijndael-encode
yes #rijndael-decode
yes #fft
yes) #fft-inv
SMALL=(basicmath_small-VAR
"susan-VAR input_small.pgm output.smoothing-small-VAR.pgm -s"
"susan-VAR input_small.pgm output.edges-small-VAR.pgm -e"
"susan-VAR input_small.pgm output.corners-small-VAR.pgm -c"
"patricia-VAR small.udp"
"dijkstra_small-VAR input.dat"
"rijndael-VAR input_small.asc output_small.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"rijndael-VAR input_small.enc output_small.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"fft-VAR 4 4096"
"fft-VAR 4 8192 -i")
LARGE=(basicmath_large-VAR
"susan-VAR input_large.pgm output.smoothing-large-VAR.pgm -s"
"susan-VAR input_large.pgm output.edges-large-VAR.pgm -e"
"susan-VAR input_large.pgm output.corners-large-VAR.pgm -c"
"patricia-VAR large.udp"
"dijkstra_large-VAR input.dat"
"rijndael-VAR input_large.asc output_large.enc e 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"rijndael-VAR input_large.enc output_large.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321"
"fft-VAR 8 32768"
"fft-VAR 8 32768 -i")
NAMES=(basicmath
susan-smoothing
susan-edges
susan-corners
patricia
dijkstra
rijndael-encode
rijndael-decode
fft
fft-inv)
OUTPUTSMALL=(none
output.smoothing-small-VAR.pgm
output.edges-small-VAR.pgm
output.corners-small-VAR.pgm
none
none
output_small.enc
output_small.dec
none
none)
OUTPUTLARGE=(none
output.smoothing-large-VAR.pgm
output.edges-large-VAR.pgm
output.corners-large-VAR.pgm
none
none
output_large-VAR.enc
output_large-VAR.dec
none
none)

ROOT=$(pwd)

for index in ${!DIRS[*]}; do
    dir=${DIRS[index]}
    name=${NAMES[index]}
    smallnat=${SMALL[index]//VAR/nat}
    largenat=${LARGE[index]//VAR/nat}
    smalloi=${SMALL[index]//VAR/oi-x86}
    largeoi=${LARGE[index]//VAR/oi-x86}
    outputsmallnat=${OUTPUTSMALL[index]//VAR/nat}
    outputsmalloi=${OUTPUTSMALL[index]//VAR/oi-x86}
    outputlargenat=${OUTPUTLARGE[index]//VAR/nat}
    outputlargeoi=${OUTPUTLARGE[index]//VAR/oi-x86}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        echo "Skipping $name"
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir"; do
        if [ "$opts" == "-debug-ir" ]; then
            if [ $dir == "automotive/susan" ] ||
                [ $dir == "security/rijndael" ] ||
                [ $dir == "automotive/basicmath" ]; then
                echo Skipping $opts for $dir
                continue
            fi
        fi
#        if [ "$opts" == "-optstack" ]; then
#            if [ $dir == "automotive/susan" ] ||
#                [ $dir == "automotive/basicmath" ]; then
#                echo Skipping $opts for $dir
#                continue
#            fi            
#        fi
        myopts=$opts" -optimize"
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
        timesmallnat="99999"
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smallnat} &> out-small-golden.txt
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

        echo Running $name in native mode "(large)" - current time is $(date) | tee -a $LOGFILE
        timelargenat="99999"
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${largenat} &> out-large-golden.txt
            cat timeoutput.txt | tee -a $LOGFILE
            timecand=$(cat timeoutput.txt)
            dotest=$(bc <<< "scale=4; $timecand < $timelargenat")
            if [ x"$dotest" == x"1" ]; then
                timelargenat=$timecand
            fi
            rm timeoutput.txt
        done
        if [ x"$iter" != x"1" ]; then
            echo -------- | tee -a $LOGFILE
            echo $timelargenat | tee -a $LOGFILE
        fi

        echo Running $name OpenISA mode "(small)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        smallesttime="99999"
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${smalloi} &> out-small-oi.txt
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

        diff out-small-golden.txt out-small-oi.txt &> /dev/null
        if [ $? -ne 0 ]; then
            echo "!! Output mismatch (small) !!" | tee -a $LOGFILE
        fi
        rm out-small-golden.txt out-small-oi.txt
        if [ x"$outputsmallnat" != x"none" ]; then
            diff $outputsmallnat $outputsmalloi &> /dev/null
            if [ $? -ne 0 ]; then
                echo "!! Output mismatch (small) !!" | tee -a $LOGFILE
            fi
            rm $outputsmallnat $outputsmalloi
        fi

        echo Running $name OpenISA mode "(large)" with opts $myopts - current time is $(date) | tee -a $LOGFILE
        smallesttime="99999"
        for iter in $(seq 1 $NUMTESTS); do
            $GNUTIME -f "%e" -otimeoutput.txt --quiet ./${largeoi} &> out-large-oi.txt
            curtime=$(cat timeoutput.txt)
            percentage=$(bc <<< "scale=4; $curtime / $timelargenat")
            echo $curtime "("${percentage}")" | tee -a $LOGFILE
            dotest=$(bc <<< "scale=4; $curtime < $smallesttime")
            if [ x"$dotest" == x"1" ]; then
                smallesttime=$curtime
            fi
            rm timeoutput.txt
        done
        if [ x"$iter" != x"1" ]; then
            echo -------- | tee -a $LOGFILE
            percentage=$(bc <<< "scale=4; $smallesttime / $timelargenat")
            echo $smallesttime "("${percentage}")" | tee -a $LOGFILE
        fi

        diff out-large-golden.txt out-large-oi.txt
        if [ $? -ne 0 ]; then
            echo "!! Output mismatch (large) !!" | tee -a $LOGFILE
        fi
        rm out-large-golden.txt out-large-oi.txt
        if [ x"$outputlargenat" != x"none" ]; then
            diff $outputlargenat $outputlargeoi &> /dev/null
            if [ $? -ne 0 ]; then
                echo "!! Output mismatch (large) !!" | tee -a $LOGFILE
            fi
            rm $outputlargenat $outputlargeoi
        fi
        SBTOPT="$myopts" make clean &> /dev/null


    done;
    cd $ROOT
done