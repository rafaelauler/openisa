cmd_/tools/include/linux/spi/.install := /bin/bash scripts/headers_install.sh /tools/include/linux/spi   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/spi/spidev.h ; for F in ; do echo "\#include <asm-generic/$$F>" > /tools/include/linux/spi/$$F; done; touch /tools/include/linux/spi/.install
