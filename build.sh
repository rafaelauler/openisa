#!/bin/bash

ROOT=$(pwd)/oitools


function check_error {
    [ $? -ne 0 ] && {
        echo "Command failed :-("
        exit
    }
}

mkdir -p $ROOT || check_error
cd $ROOT || check_error
[ ! -f ${ROOT}/oi-toolchain/bin/mipsel-unknown-linux-gnu-ld ] && {
    git clone git-marvin:openisa.git --depth 1 || check_error
    cd openisa/linker-oi || check_error
    wget http://ftp.gnu.org/gnu/binutils/binutils-2.23.2.tar.bz2 || check_error
    tar xjvf binutils-2.23.2.tar.bz2 || check_error
    git reset --hard || check_error
    mkdir -p build || check_error
    cd build || check_error
    ../binutils-2.23.2/configure --prefix=${ROOT}/oi-toolchain \
                                 --disable-nls --enable-shared --disable-multilib \
                                 --target=mipsel-unknown-linux-gnu --disable-werror || check_error
    make MAKEINFO=true -j20 || check_error
    make install MAKEINFO=true || check_error
}
[ ! -d ${ROOT}/llvm-openisa ] && {
    cd ${ROOT} || check_error
    git clone --recursive git-marvin:llvm-openisa.git -b openisa --depth 1 || check_error
}
[ ! -f ${ROOT}/obj/bin/clang ] && {
    cd ${ROOT} || check_error
    mkdir obj || check_error
    cd obj || check_error
    cmake ../llvm-openisa -DLLVM_TARGETS_TO_BUILD="Mips;X86;ARM" \
          -DCMAKE_INSTALL_PREFIX=${ROOT}/oi-toolchain \
          -DLLVM_DEFAULT_TARGET_TRIPLE="mipsel-unknown-linux-gnu" \
          -DCLANG_VENDOR="OpenISA Tools" -GNinja || check_error
    ninja || check_error
}
[ ! -f ${ROOT}/oi-toolchain/bin/clang ] && {
    cd ${ROOT}/obj || check_error
    ninja install || check_error
}
[ ! -f ${ROOT}/oi-toolchain/oi-elf/lib/libc.a ] && {
    cd ${ROOT}/oi-toolchain/bin || check_error
    export PATH=$(pwd):$PATH
    cd ${ROOT}/openisa/newlib || check_error
    mkdir build || check_error
    cd build
    CC_FOR_TARGET="clang"\
                 CXX_FOR_TARGET="clang++"\
                 AR_FOR_TARGET="mipsel-unknown-linux-gnu-ar"\
                 AS_FOR_TARGET="mipsel-unknown-linux-gnu-as"\
                 LD_FOR_TARGET="mipsel-unknown-linux-gnu-ld"\
                 NM_FOR_TARGET="mipsel-unknown-linux-gnu-nm"\
                 OBJDUMP_FOR_TARGET="mipsel-unknown-linux-gnu-objdump"\
                 RANLIB_FOR_TARGET="mipsel-unknown-linux-gnu-ranlib"\
                 READELF_FOR_TARGET="mipsel-unknown-linux-gnu-readelf"\
                 STRIP_FOR_TARGET="mipsel-unknown-linux-gnu-strip"\
                 ../newlib-2.1.0/configure --prefix=${ROOT}/oi-toolchain -target=oi-elf || check_error
    make || check_error
    make install || check_error
    cp  -v ../newlib-2.1.0/libgloss/libnosys/ac_link.ld ${ROOT}/oi-toolchain/oi-elf/lib || check_error
    cd ${ROOT}/oi-toolchain/oi-elf/lib || check_error
    clang -c ${ROOT}/openisa/newlib/newlib-2.1.0/libgloss/libnosys/ac_start.S \
          -o ac_start.o || check_error
}
echo "Finished :-) Tools installed in ${ROOT}/oi-toolchain and binaries in ${ROOT}/oi-toolchain/bin"


