#!/bin/bash

if [ "$(echo -n "tstnum1" | sha1sum | cut -f 1 -d " ")" != "$(echo -n "SHA1 \"tstnum1" | ./rhasher)" ]; then
    echo "SHA1 TEST 1: NOT OK"
else
    echo "SHA1 TEST 1: OK"
fi

if [ "$(echo -n "bbbbbbbbbbbbb" | sha1sum | cut -f 1 -d " ")" != "$(echo -n "SHA1 \"bbbbbbbbbbbbb" | ./rhasher)" ]; then
    echo "SHA1 TEST 2: NOT OK"
else
    echo "SHA1 TEST 2: OK"
fi

if [ "$(echo -n "tstnumtwo" | md5sum | cut -f 1 -d " ")" != "$(echo -n "MD5 \"tstnumtwo" | ./rhasher)" ]; then
    echo "MD5 TEST 1: NOT OK"
else
    echo "MD5 TEST 1: OK"
fi

if [ "$(echo -n "asdasdasd" | md5sum | cut -f 1 -d " ")" != "$(echo -n "MD5 \"asdasdasd" | ./rhasher)" ]; then
    echo "MD5 TEST 2: NOT OK"
else
    echo "MD5 TEST 2: OK"
fi
