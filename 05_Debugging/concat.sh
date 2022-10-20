#!/bin/bash
i=0
line=""
flag=0
fin=$1
fout=$2
while read elem; 
do
    if [ "$i" == "0" ]; then
        line="$elem "
        i=1
        continue
    fi
    if [ "$i" == "1" ]; then
        line="$line$elem"
        i=0
        if [ "$flag" == "0" ]; then
            echo $line > $fout
            flag=1
            continue
        fi
        if [ "$flag" == "1" ]; then
            echo $line >> $fout
        fi
    fi
done < $fin