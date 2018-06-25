#!/bin/bash

file=$1
i="0"
while [ -f "edited/$file/$i.txt" ]
do
    files="$files $i.wav"
    i=$[$i+1]
done
cd edited
cd "$file"
play $files 2> /dev/null
cd ..
cd ..
