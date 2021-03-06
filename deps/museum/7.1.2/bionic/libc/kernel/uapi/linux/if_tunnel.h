/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_IF_TUNNEL_H_
#define _UAPI_IF_TUNNEL_H_
#define UAPI_IF_TUNNEL_H_
#define UAPI_IF_TUNNEL_H
#define _IF_TUNNEL_H_
#define _IF_TUNNEL_H
#define _UAPI_IF_TUNNEL_H
#include <museum/7.1.2/bionic/libc/linux/types.h>
#include <museum/7.1.2/bionic/libc/asm/byteorder.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SIOCGETTUNNEL (SIOCDEVPRIVATE + 0)
#define SIOCADDTUNNEL (SIOCDEVPRIVATE + 1)
#define SIOCDELTUNNEL (SIOCDEVPRIVATE + 2)
#define SIOCCHGTUNNEL (SIOCDEVPRIVATE + 3)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SIOCGETPRL (SIOCDEVPRIVATE + 4)
#define SIOCADDPRL (SIOCDEVPRIVATE + 5)
#define SIOCDELPRL (SIOCDEVPRIVATE + 6)
#define SIOCCHGPRL (SIOCDEVPRIVATE + 7)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SIOCGET6RD (SIOCDEVPRIVATE + 8)
#define SIOCADD6RD (SIOCDEVPRIVATE + 9)
#define SIOCDEL6RD (SIOCDEVPRIVATE + 10)
#define SIOCCHG6RD (SIOCDEVPRIVATE + 11)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define GRE_CSUM __cpu_to_be16(0x8000)
#define GRE_ROUTING __cpu_to_be16(0x4000)
#define GRE_KEY __cpu_to_be16(0x2000)
#define GRE_SEQ __cpu_to_be16(0x1000)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define GRE_STRICT __cpu_to_be16(0x0800)
#define GRE_REC __cpu_to_be16(0x0700)
#define GRE_FLAGS __cpu_to_be16(0x00F8)
#define GRE_VERSION __cpu_to_be16(0x0007)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ip_tunnel_parm {
  char name[IFNAMSIZ];
  int link;
  __be16 i_flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __be16 o_flags;
  __be32 i_key;
  __be32 o_key;
  struct iphdr iph;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  IFLA_IPTUN_UNSPEC,
  IFLA_IPTUN_LINK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IPTUN_LOCAL,
  IFLA_IPTUN_REMOTE,
  IFLA_IPTUN_TTL,
  IFLA_IPTUN_TOS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IPTUN_ENCAP_LIMIT,
  IFLA_IPTUN_FLOWINFO,
  IFLA_IPTUN_FLAGS,
  IFLA_IPTUN_PROTO,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IPTUN_PMTUDISC,
  IFLA_IPTUN_6RD_PREFIX,
  IFLA_IPTUN_6RD_RELAY_PREFIX,
  IFLA_IPTUN_6RD_PREFIXLEN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IPTUN_6RD_RELAY_PREFIXLEN,
  IFLA_IPTUN_ENCAP_TYPE,
  IFLA_IPTUN_ENCAP_FLAGS,
  IFLA_IPTUN_ENCAP_SPORT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IPTUN_ENCAP_DPORT,
  __IFLA_IPTUN_MAX,
};
#define IFLA_IPTUN_MAX (__IFLA_IPTUN_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum tunnel_encap_types {
  TUNNEL_ENCAP_NONE,
  TUNNEL_ENCAP_FOU,
  TUNNEL_ENCAP_GUE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define TUNNEL_ENCAP_FLAG_CSUM (1 << 0)
#define TUNNEL_ENCAP_FLAG_CSUM6 (1 << 1)
#define TUNNEL_ENCAP_FLAG_REMCSUM (1 << 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SIT_ISATAP 0x0001
struct ip_tunnel_prl {
  __be32 addr;
  __u16 flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 __reserved;
  __u32 datalen;
  __u32 __reserved2;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PRL_DEFAULT 0x0001
struct ip_tunnel_6rd {
  struct in6_addr prefix;
  __be32 relay_prefix;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 prefixlen;
  __u16 relay_prefixlen;
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GRE_UNSPEC,
  IFLA_GRE_LINK,
  IFLA_GRE_IFLAGS,
  IFLA_GRE_OFLAGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GRE_IKEY,
  IFLA_GRE_OKEY,
  IFLA_GRE_LOCAL,
  IFLA_GRE_REMOTE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GRE_TTL,
  IFLA_GRE_TOS,
  IFLA_GRE_PMTUDISC,
  IFLA_GRE_ENCAP_LIMIT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GRE_FLOWINFO,
  IFLA_GRE_FLAGS,
  IFLA_GRE_ENCAP_TYPE,
  IFLA_GRE_ENCAP_FLAGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GRE_ENCAP_SPORT,
  IFLA_GRE_ENCAP_DPORT,
  IFLA_GRE_COLLECT_METADATA,
  __IFLA_GRE_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_GRE_MAX (__IFLA_GRE_MAX - 1)
#define VTI_ISVTI ((__force __be16) 0x0001)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VTI_UNSPEC,
  IFLA_VTI_LINK,
  IFLA_VTI_IKEY,
  IFLA_VTI_OKEY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VTI_LOCAL,
  IFLA_VTI_REMOTE,
  __IFLA_VTI_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_VTI_MAX (__IFLA_VTI_MAX - 1)
#endif
