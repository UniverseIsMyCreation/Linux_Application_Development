#!/bin/bash

echo "1234567890" > 1.txt && echo "abcdefgz" > 2.txt;
./move 1.txt 2.txt > /dev/null 2>> error.txt
if [ $? -eq 0 ] && [ ! -f 1.txt ] && [ -f 2.txt ]; then
		echo "1 test: OK"
else
		echo "1 test: NOT OK"
fi

echo "1234567890" > 1.txt && echo "abcdefgz" > 2.txt;
./move 1.txt > /dev/null 2>> error.txt
if [ $? -eq 1 ] && [ -f 1.txt ] && [ -f 2.txt ]; then
        echo "2 test: OK"
else
        echo "2 test: NOT OK"
fi

rm 1.txt
rm 2.txt
./move 1.txt 2.txt > /dev/null 2>> error.txt
if [ $? -eq 2 ] && [ ! -f 1.txt ] && [ ! -f 2.txt ]; then
        echo "3 test: OK"
else
        echo "3 test: NOT OK"
fi 

echo "1234567890" > 1.txt
./move 1.txt 1.txt > /dev/null 2>> error.txt
if [ $? -eq 0 ] && [ -f 1.txt ] && [ ! -f 2.txt ]; then
        echo "4 test: OK"
else
        echo "4 test: NOT OK"
fi 