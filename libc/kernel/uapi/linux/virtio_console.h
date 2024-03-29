/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_VIRTIO_CONSOLE_H
#define _UAPI_LINUX_VIRTIO_CONSOLE_H
#include <linux/types.h>
#include <linux/virtio_types.h>
#include <linux/virtio_ids.h>
#include <linux/virtio_config.h>
#define VIRTIO_CONSOLE_F_SIZE 0
#define VIRTIO_CONSOLE_F_MULTIPORT 1
#define VIRTIO_CONSOLE_F_EMERG_WRITE 2
#define VIRTIO_CONSOLE_BAD_ID (~(__u32) 0)
struct virtio_console_config {
  __virtio16 cols;
  __virtio16 rows;
  __virtio32 max_nr_ports;
  __virtio32 emerg_wr;
} __attribute__((packed));
struct virtio_console_control {
  __virtio32 id;
  __virtio16 event;
  __virtio16 value;
};
#define VIRTIO_CONSOLE_DEVICE_READY 0
#define VIRTIO_CONSOLE_PORT_ADD 1
#define VIRTIO_CONSOLE_PORT_REMOVE 2
#define VIRTIO_CONSOLE_PORT_READY 3
#define VIRTIO_CONSOLE_CONSOLE_PORT 4
#define VIRTIO_CONSOLE_RESIZE 5
#define VIRTIO_CONSOLE_PORT_OPEN 6
#define VIRTIO_CONSOLE_PORT_NAME 7
#endif
