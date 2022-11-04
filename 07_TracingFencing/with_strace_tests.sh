#!/bin/bash

echo "1234567890" > 1.txt
strace -e openat -e fault=openat:error=ENOENT:when=3 ./move 1.txt 2.txt > /dev/null 2>> error.txt
if [ $? -eq 2 ] && [ -f 1.txt ] && [ ! -f 2.txt ]; then
    echo "1 test(strace): OK"
else
    echo "1 test(strace): NOT OK"
fi
		
strace -e openat -e fault=openat:error=ENOENT:when=4 ./move 1.txt 2.txt > /dev/null 2>> error.txt
if [ $? -eq 3 ] && [ -f 1.txt ] && [ ! -f 2.txt ]; then
    echo "2 test(strace): OK"
else
    echo "2 test(strace): NOT OK"
fi

echo "1234567890" > 1.txt && echo "abcdefgz" > 2.txt;
strace -e read -P "1.txt" -e fault=read:error=EIO ./move 1.txt 2.txt > /dev/null 2>> error.txt
if [ $? -eq 4 ] && [ -f 1.txt ] && [ ! -f 2.txt ]; then
    echo "3 test(strace): OK"
else
    echo "3 test(strace): NOT OK"
fi

echo "1234567890" > 1.txt && echo "abcdefgz" > 2.txt;
strace -e trace=write -e fault=write:error=EINTR:when=2 ./move 1.txt 2.txt > /dev/null 2>> error.txt
if [ $? -eq 4 ] && [ -f 1.txt ] && [ ! -f 2.txt ]; then
    echo "4 test(strace): OK"
else
    echo "4 test(strace): NOT OK"
fi
	
echo "1234567890" > 1PROTECT.txt && echo "abcdefgz" > 2PROTECT.txt;
echo "1234567890" > 1.txt && echo "abcdefgz" > 2.txt;
LD_PRELOAD=./injection_remove.so ./move 1PROTECT.txt 2.txt > /dev/null 2>> error.txt 
if [ $? -eq 5 ] && [ -f 1PROTECT.txt ] && [ -f 2PROTECT.txt ]; then
    echo "5 test(strace): OK"
else
    echo "5 test(strace): NOT OK"
fi