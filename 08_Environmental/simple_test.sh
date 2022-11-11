#!/bin/bash

res1=$(echo -n "tstnum1" | sha1sum | cut -f 1 -d " ")
res2=$(echo -n "SHA1 \"tstnum1" | ./rhasher)
if [ "echo $res1" != "echo $res2" ]; then
    echo "SHA1 TEST 1: NOT OK"
else
    echo "SHA1 TEST 1: OK"
fi

res1=$(echo -n "bbbbbbbbbbbbb" | sha1sum | cut -f 1 -d " ")
res2=$(echo -n "SHA1 \"bbbbbbbbbbbbb" | ./rhasher)
if [ "echo $res1" != "echo $res2" ]; then
    echo "SHA1 TEST 2: NOT OK"
else
    echo "SHA1 TEST 2: OK"
fi

res1=$(echo -n "tstnumtwo" | md5sum | cut -f 1 -d " ")
res2=$(echo -n "MD5 \"tstnumtwo" | ./rhasher)
if [ "echo $res1" != "echo $res2" ]; then
    echo "MD5 TEST 1: NOT OK"
else
    echo "MD5 TEST 1: OK"
fi

res1=$(echo -n "asdasdasd" | md5sum | cut -f 1 -d " ")
res2=$(echo -n "MD5 \"asdasdasd" | ./rhasher)
if [ "echo $res1" != "echo $res2" ]; then
    echo "MD5 TEST 2: NOT OK"
else
    echo "MD5 TEST 2: OK"
fi