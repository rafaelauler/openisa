#!/bin/bash

LOG_TEMP=log_temp.txt
LOG_T2=log_temp2.txt
[ x"$1" == x ] && {
    echo "Usage: $0 <log date>"
    exit
}

sed -n "/Tests started. Today is $1/,/Tests started/p" log.txt &> $LOG_TEMP
lines=$(wc -l ${LOG_TEMP}  | cut -d' ' -f 1)
[ x"$lines" == x0 ] && {
    echo "Date failed to select any log data."
    rm $LOG_TEMP
    exit
}
echo Extracted $lines lines of log data.

NAMES=(fib
matrix
heapsort
ackermann
sieve
array
lists
random)

ACTIVATE=(yes #fib
yes #matrix
yes #heapsort
yes #ackermann
yes #sieve
yes #array
yes #lists
yes) #random

echo -ne "Index Program Native Globals Locals Whole\n"
for index in ${!NAMES[*]}; do
    name=${NAMES[index]}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        continue
    fi
    echo -ne "$(bc <<< "$index + 1") ${name} "
    sed -n "/Running ${name} native mode/,/Running/p" $LOG_TEMP &> $LOG_T2
    echo -ne "$(tail -n2 $LOG_T2 | head -n1 | cut -d' ' -f 1) "

    sed -n "/Running ${name} OpenISA mode with opts -nolocals/,/Running/p" $LOG_TEMP &> $LOG_T2
    echo -ne "$(tail -n2 $LOG_T2 | head -n1 | cut -d' ' -f 1) "

    sed -n "/Running ${name} OpenISA mode with opts -debug-ir -optimize/,/Running/p" $LOG_TEMP &> $LOG_T2
    echo -ne "$(tail -n2 $LOG_T2 | head -n1 | cut -d' ' -f 1) "

    sed -n "/Running ${name} OpenISA mode with opts -oneregion/,/Running/p" $LOG_TEMP &> $LOG_T2
    echo -ne "$(tail -n2 $LOG_T2 | head -n1 | cut -d' ' -f 1)\n"
done

rm $LOG_TEMP
rm $LOG_T2
