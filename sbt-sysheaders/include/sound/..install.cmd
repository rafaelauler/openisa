cmd_/tools/include/sound/.install := /bin/bash scripts/headers_install.sh /tools/include/sound   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/asequencer.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/asound.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/asound_fm.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/compress_offload.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/compress_params.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/emu10k1.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/hdsp.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/hdspm.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/sb16_csp.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/sound/sfnt_info.h ; for F in ; do echo "\#include <asm-generic/$$F>" > /tools/include/sound/$$F; done; touch /tools/include/sound/.install
