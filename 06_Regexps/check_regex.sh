#!/bin/bash

if [ "$(echo '123456' | sed -E 's/[1-2][1-2]/a\\b/')" != "$(./esub '[1-2][1-2]' 'a\\b' '123456')" ]; then
    echo "Test 1 failed"
else
    echo "Test 1 completed succesfully"
fi

if [ "$(echo '123a456abc' | sed -E 's/([a-z])+/here/')" != "$(./esub '([a-z])+' 'here' '123a456abc')" ]; then
    echo "Test 2 failed"
else
    echo "Test 2 completed succesfully"
fi

echo "Test 3 result (with error):"
./esub '[1-2][1-2]' 'a\\\v' '123456'

echo "Test 4 result (with error):"
./esub '[1-2][1-2]' 'a\3\t' '123456'

echo "Test 5 result (with error):"
./esub '[1-2][1-2]' 'a\\\' '123456'

if [ "$(echo 'aaabbb' | sed -E 's/(a*(b*))/\2\1/')" != "$(./esub '(a*(b*))' '\2\1' 'aaabbb')" ]; then
    echo "Test 6 failed"
else
    echo "Test 6 completed succesfully"
fi

if [ "$(echo '123a456b789' | sed -E 's/([0-9]*.[0-9]*)([0-9]*.[0-9]*)/\2<->\1/')" != "$(./esub '([0-9]*.[0-9]*)([0-9]*.[0-9]*)' '\2<->\1' '123a456b789')" ]; then
    echo "Test 7 failed"
else
    echo "Test 7 completed succesfully"
fi

if [ "$(echo 'abc123abc' | sed -E 's/^([a-z]{3})/.../')" != "$(./esub '^([a-z]{3})' '...' 'abc123abc')" ]; then
    echo "Test 8 failed"
else
    echo "Test 8 completed succesfully"
fi