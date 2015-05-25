#!/bin/bash

LOG_TEMP=log_temp.txt
LOG_T2=log_temp2.txt
FIELD_SEP=","
[ x"$1" == x ] && {
    echo "Usage: $0 <log date>"
    exit
}

sed -n "/Tests started. Today is $1/,/Tests started/p" log_perf.txt &> $LOG_TEMP
lines=$(wc -l ${LOG_TEMP}  | cut -d' ' -f 1)
[ x"$lines" == x0 ] && {
    echo "Date failed to select any log data."
    rm $LOG_TEMP
    exit
}

NAMES=(ackermann
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

function format_perf_output() {
    # Printing task clock (msec)
    echo -ne "$(head -n1 ${LOG_T2} | sed 's/,//g' | gawk '{print $1}')${FIELD_SEP}"
    # Printing Clock std dev
    echo -ne "$(head -n1 ${LOG_T2} | sed 's/,//g' | gawk '{print $10}' | sed 's/.$//')${FIELD_SEP}"
    # Printing CPU utilization
    echo -ne "$(head -n1 ${LOG_T2} | sed 's/,//g' | gawk '{print $5}')${FIELD_SEP}"
    # Printing page faults
    echo -ne "$(head -n4 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $1}')${FIELD_SEP}"
    # Printing cycles
    echo -ne "$(head -n5 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $1}')${FIELD_SEP}"
    # Printing cycles std dev
    echo -ne "$(head -n5 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $8}' | sed 's/.$//')${FIELD_SEP}"
    # Printing stalled cycles frontend
    echo -ne "$(head -n6 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $1}')${FIELD_SEP}"
    # Printing percentage stalled
    echo -ne "$(head -n6 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $4}' | sed 's/.$//')${FIELD_SEP}"
    # Printing instructions
    echo -ne "$(head -n8 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $1}')${FIELD_SEP}"
    # Printing IPC
    echo -ne "$(head -n8 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $4}')${FIELD_SEP}"
    # Printing stalled cycles per ins
    echo -ne "$(head -n9 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $2}')${FIELD_SEP}"
    # Printing Branches
    echo -ne "$(head -n10 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $1}')${FIELD_SEP}"
    # Printing Branches misses
    echo -ne "$(head -n11 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $1}')${FIELD_SEP}"
    # Printing Percentage branches misses
    echo -ne "$(head -n11 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $4}' | sed 's/.$//')${FIELD_SEP}"
    # Printing Std dev branches misses
    echo -ne "$(head -n11 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $10}' | sed 's/.$//')${FIELD_SEP}"
    # Printing Time (seconds)
    echo -ne "$(head -n13 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $1}')${FIELD_SEP}"
    # Printing Std dev time
    echo -ne "$(head -n13 ${LOG_T2} | sed 's/,//g' | tail -n1 | gawk '{print $7}' | sed 's/.$//')\n"
    return
}

echo -ne "Program${FIELD_SEP}Task clock (msec)${FIELD_SEP}Clock std dev"
echo -ne "${FIELD_SEP}CPU utilization${FIELD_SEP}Page faults${FIELD_SEP}Cycles"
echo -ne "${FIELD_SEP}Cycles std dev${FIELD_SEP}Stalled cycles frontend"
echo -ne "${FIELD_SEP}Percentage stalled${FIELD_SEP}Instructions${FIELD_SEP}IPC"
echo -ne "${FIELD_SEP}Stalled cycles per ins${FIELD_SEP}Branches"
echo -ne "${FIELD_SEP}Branches misses${FIELD_SEP}Percentage branches missed"
echo -ne "${FIELD_SEP}Std dev branches misses${FIELD_SEP}Time (seconds)"
echo -ne "${FIELD_SEP}Std dev time\n"

for index in ${!NAMES[*]}; do
    name=${NAMES[index]}
    active=${ACTIVATE[index]}
    if [ $active == "no" ]; then
        continue
    fi
    echo -ne "${name}-native${FIELD_SEP}"
    sed -n "/Running ${name} in native mode (large)/,/Running/p" $LOG_TEMP | sed -n "/task-clock/,/blblbl/p" > $LOG_T2
    format_perf_output

    echo -ne "${name}-globals${FIELD_SEP}"
    sed -n "/Running ${name} OpenISA mode (large) with opts -nolocals/,/Running/p" $LOG_TEMP | sed -n "/task-clock/,/blblbl/p" > $LOG_T2
    format_perf_output

    echo -ne "${name}-locals${FIELD_SEP}"
    sed -n "/Running ${name} OpenISA mode (large) with opts -debug-ir -optimize/,/Running/p" $LOG_TEMP | sed -n "/task-clock/,/blblbl/p" > $LOG_T2
    format_perf_output

    echo -ne "${name}-oneregion${FIELD_SEP}"
    sed -n "/Running ${name} OpenISA mode (large) with opts -oneregion/,/Running/p" $LOG_TEMP | sed -n "/task-clock/,/blblbl/p" > $LOG_T2
    format_perf_output
done

rm $LOG_TEMP
rm $LOG_T2
