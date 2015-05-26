#!/bin/bash

LOG_TEMP=log_temp.txt
LOG_T2=log_temp2.txt
FIELD_SEP=","
[ x"$1" == x ] && {
    echo "Usage: $0 <log date>"
    exit
}

sed -n "/Tests started. Today is $1/,/Tests started/p" log_perf_record.txt &> $LOG_TEMP
lines=$(wc -l ${LOG_TEMP}  | cut -d' ' -f 1)
[ x"$lines" == x0 ] && {
    echo "Date failed to select any log data."
    rm $LOG_TEMP
    exit
}

DIRS=(ackermann
array
fib
heapsort
lists
matrix
random
sieve)
ACTIVATE=(yes #ackermann
yes #array
yes #fib
yes #heapsort
yes #lists
yes #matrix
yes #random
yes) #sieve
EXECNAMES=(ackermann
array
fib
heapsort
lists
matrix
random
sieve)
NAMES=(ackermann
array
fib
heapsort
lists
matrix
random
sieve)


function extract_info() {
    namedso=$(head -n10 ${LOG_T2} | tail -n1 | gawk '{ print $2 }')
    if [ x"$namedso" ==  x"${execname}-${1}" ]; then
        echo -ne "$(head -n10 ${LOG_T2} | tail -n1 | gawk '{ print $1 }' | sed 's/.$//')\n"
        return
    fi
    namedso=$(head -n11 ${LOG_T2} | tail -n1 | gawk '{ print $2 }')
    if [ x"$namedso" ==  x"${execname}-${1}" ]; then
        echo -ne "$(head -n11 ${LOG_T2} | tail -n1 | gawk '{ print $1 }' | sed 's/.$//')\n"
        return
    fi
    namedso=$(head -n12 ${LOG_T2} | tail -n1 | gawk '{ print $2 }')
    if [ x"$namedso" ==  x"${execname}-${1}" ]; then
        echo -ne "$(head -n12 ${LOG_T2} | tail -n1 | gawk '{ print $1 }' | sed 's/.$//')\n"
        return
    fi
    namedso=$(head -n13 ${LOG_T2} | tail -n1 | gawk '{ print $2 }')
    if [ x"$namedso" ==  x"${execname}-${1}" ]; then
        echo -ne "$(head -n13 ${LOG_T2} | tail -n1 | gawk '{ print $1 }' | sed 's/.$//')\n"
        return
    fi
    echo ! COULD NOT FIND PROGRAM INFORMATION, QUITTING...
    exit
}

echo -ne "Program${FIELD_SEP}Percentage\n"

for index in ${!NAMES[*]}; do
    name=${NAMES[index]}
    active=${ACTIVATE[index]}
    execname=${EXECNAMES[index]}
    if [ $active == "no" ]; then
        continue
    fi
    echo -ne "${name}-native${FIELD_SEP}"
    sed -n "/Running ${name} in native mode (large)/,/Running/p" $LOG_TEMP > $LOG_T2
    extract_info "nat-x86"

    echo -ne "${name}-globals${FIELD_SEP}"
    sed -n "/Running ${name} OpenISA mode (large) with opts -nolocals/,/Running/p" $LOG_TEMP > $LOG_T2
    extract_info "oi-x86"

    echo -ne "${name}-locals${FIELD_SEP}"
    sed -n "/Running ${name} OpenISA mode (large) with opts -debug-ir -optimize/,/Running/p" $LOG_TEMP > $LOG_T2
    extract_info "oi-x86"

    echo -ne "${name}-oneregion${FIELD_SEP}"
    sed -n "/Running ${name} OpenISA mode (large) with opts -oneregion/,/Running/p" $LOG_TEMP > $LOG_T2
    extract_info "oi-x86"
done

rm $LOG_TEMP
rm $LOG_T2
