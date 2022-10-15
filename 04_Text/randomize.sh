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
text=""
while IFS= read -r line; do
    line=$(echo "$line" | tr -d '\n' | cat -v -T)
    for ((i=0;i<${#line};i++)); do
        if [ "${line:i:1}" != " " ]; then
            text="$text${line:i:1}|$row_number|$i\new_line"
        fi
    done
    row_number=$((row_number+1))
done

text=$(echo "$text" | sed 's/\\new_line/ /g')

tput clear

for element in $(shuf -e $text); do
    IFS="|" read symbol row column <<< $element
    tput cup $row $column
    echo "$symbol"
    sleep $sleep_delay
done

tput cup $row_number 0