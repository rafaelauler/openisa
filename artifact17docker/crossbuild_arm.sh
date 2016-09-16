#!/bin/bash

ROOT=$(pwd)/oitools

function check_error {
    [ $? -ne 0 ] && {
        echo "Command failed :-("
        exit
    }
}

. env.sh

cd ${ROOT}/openisa/mibench || check_error
./build_all_arm.sh || check_error
mkdir -p ${ROOT}/openisa/spec/testes-arm/bin
cp -v testes-arm/bin/* ${ROOT}/openisa/spec/testes-arm/bin || check_error
cd ${ROOT}/openisa/spec || check_error
./build_all_arm.sh || check_error
cd ${ROOT}/openisa/spec/testes-arm || check_error
cp -v ${ROOT}/openisa/spec/testes-x86/*.gnuplot ${ROOT}/openisa/spec/testes-arm || check_error
tar cjvf bundle-arm.tar.bz2 bin input measure-arm.sh *.gnuplot || check_error
cp -v bundle-arm.tar.bz2 ${ROOT}/.. || check_error

echo "Finished. Please deploy bundle-arm.tar.bz2 to an ARM Linux platform and run measure-arm.sh"
