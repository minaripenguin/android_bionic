/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __LINUX_TC_EM_NBYTE_H
#define __LINUX_TC_EM_NBYTE_H
#include <linux/types.h>
#include <linux/pkt_cls.h>
struct tcf_em_nbyte {
  __u16 off;
  __u16 len : 12;
  __u8 layer : 4;
};
#endif
