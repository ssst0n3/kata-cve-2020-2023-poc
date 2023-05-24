#!/bin/bash

get_block_address() {
    address=$(mountpoint -d /)
    lsblk | grep $address >/dev/null
    if [ $? != 0 ]; then
        address=$(lsblk | grep part | head -n 1 | grep -oP '\d+:\d+')
    fi
    echo $address | awk -F: '{print $1," "$2}'
}