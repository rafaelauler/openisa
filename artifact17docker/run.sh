#!/bin/bash

ROOT=$(pwd)/oitools

function check_error {
    [ $? -ne 0 ] && {
        echo "Command failed :-("
        exit
    }
}

. env.sh

cd $ROOT/openisa/spec
./measure_x86.sh

echo "Finished. Check the results in mibench.pdf and spec.pdf."
