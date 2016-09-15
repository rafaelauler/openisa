#!/bin/bash

ROOT=$(pwd)/oitools

function check_error {
    [ $? -ne 0 ] && {
        echo "Command failed :-("
        exit
    }
}

. env.sh

cd $ROOT/openisa/spec/testes-x86
./measure_x86.sh

echo "Finished. Check the results in ${ROOT}/openisa/spec/mibench.pdf and spec.pdf."
