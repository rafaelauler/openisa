cmd_/tools/include/linux/netfilter_bridge/.install := /bin/bash scripts/headers_install.sh /tools/include/linux/netfilter_bridge   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_802_3.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_among.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_arp.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_arpreply.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_ip.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_ip6.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_limit.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_log.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_mark_m.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_mark_t.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_nat.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_nflog.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_pkttype.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_redirect.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_stp.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_ulog.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebt_vlan.h   /l/home/rafael/disco2/rafael/archc/openisa/cross/linux-3.10.14/include/uapi/linux/netfilter_bridge/ebtables.h ; for F in ; do echo "\#include <asm-generic/$$F>" > /tools/include/linux/netfilter_bridge/$$F; done; touch /tools/include/linux/netfilter_bridge/.install
