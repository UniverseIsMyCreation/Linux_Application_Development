#!/bin/bash

if [ "$#" -eq "0" ]; then
    sleep_delay=0.0
else
    if [ "$#" -gt "1" ]; then
        echo "Get too many parameters, write less than 2"
        exit 1
    else
        sleep_delay=$1
    fi
fi

row_number=0
flag=1
text=""
while IFS= read -r line; do
    line=$(echo "$line" | tr -d '\n' | cat -v -T)
    for ((i=0;i<${#line};i++)); do
        if [ $flag -eq 0 ]; then
            if ! [ -z ${line:i:1} ]; then
                text="$text ${line:i:1}\\$row_number\\$i"
            fi
        else
            if ! [ -z ${line:i:1} ]; then
                text="$text${line:i:1}\\$row_number\\$i"
            fi
            flag=0
        fi
    done
    row_number=$((row_number+1))
done

tput clear

for element in $(shuf -e $text); do
    element=$(echo $element | tr '\\' ' ')
    IFS=" " read symbol row column <<< $element
    tput cup $row $column
    echo "$symbol"
    sleep $sleep_delay
done

tput cup $row_number 0