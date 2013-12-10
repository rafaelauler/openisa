#!/bin/bash

for dir in $(find . -maxdepth 1 -mindepth 1 -type d | cut -c 3-); do
    if [ $dir == "calc" ]; then
        continue
    fi
    if [ $dir == "micro" ]; then
        continue
    fi
    if [ $dir == "hello-world" ]; then
        continue
    fi
    if [ $dir == "moments" ]; then
        continue
    fi
    cd $dir
    for opts in "-oneregion" "-nolocals" "-debug-ir"; do
        myopts=$opts" -optimize"
        make clean
        SBTOPT="$myopts" make
        echo Running $dir native mode with opts $myopts
        time ./${dir}-nat | tee out-nat.txt
        echo Running $dir OpenISA mode with opts $myopts
        time ./${dir}-oi-x86 | tee out-oi.txt
        diff out-nat.txt out-oi.txt
        if [ $? -ne 0 ]; then
            echo Different outputs
        fi
        sleep 4
    done;
    cd ..
done