This is a hacked version of binutils-2.32.2 for mips to make a linker that
is able to correctly process OpenISA relocations.

Files changed:
bfd/elf32-mips.c, the howto table, whicch explains how each relocation
should be handled. The relocation R_MIPS_LO16 was changed.

bfd/elfxx-mipc.c, the special function used to handle the R_MIPS_LO16
relocation and similar ones, called bfd_mips_elf_lo16_reloc (). This
function was not changed, but can be useful in the future.



To build:
mkdir build
cd build
../binutils-2.23.2/configure --prefix=$(pwd)/../install --disable-nls --enable-shared --disable-multilib --with-sysroot=/cross-tools --target=mipsel-unknown-linux-gnu --disable-werror
make MAKEINFO=true
make install MAKEINFO=true
