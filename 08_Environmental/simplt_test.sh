#!/bin/bash

if [ "$(echo -n "tstnum1" | sha1sum | cut -f 1 -d " ")" != "$(echo -n "SHA1 \"tstnum1" | ./rhasher)" ]; then
    echo "SHA1 test failed"
else
    echo "TEST 1: OK"
fi

if [ "$(echo -n "tstnumtwo" | md5sum | cut -f 1 -d " ")" != "$(echo -n "MD5 \"tstnumtwo" | ./rhasher)" ]; then
    echo "MD5 test failed"
else
    echo "TEST 2: OK"
fi
