#!/bin/bash

GSED=sed
GNUTIME=/usr/bin/time
LOGFILE=log.txt
# Number of times each binary execution is measured
NUMTESTS=3

echo Tests started. Today is $(date). | tee -a $LOGFILE

for arq in $(find bin -maxdepth 1 -mindepth 1 -type f); do
    name=$($GSED 's/.*\/\(.*\)-.*/\1/g' <<< $arq)
    name=$($GSED 's/-nat//g' <<< $name)
    echo Started testing $arq - current time is $(date) | tee -a $LOGFILE
    for iter in $(seq 1 $NUMTESTS); do
        $GNUTIME -f "%e" -otimeoutput.txt --quiet $arq | tee out.txt
        cat timeoutput.txt | tee -a $LOGFILE
    done
    if [ -f out-$name.txt ]; then
        diff out-$name.txt out.txt
        if [ $? -ne 0 ]; then
            echo Output mismatch
            echo Output mismatch >> $LOGFILE
        fi
    else
        mv out.txt out-$name.txt
    fi
done

rm out.txt
echo --
echo Done. Time results written in log.txt.
