#!/bin/bash

file=$1
effectfile=$2
mkdir -p "edited/$file"
i="0"
cd edited
cd "$file"
rm -f *.txt
rm -f *.wav
cd ..
cd ..
./mpg123 -s "$file.mp3" 2> "edited/$file/information.txt" | ./toascii -ss > "edited/$file/$file.txt"
time=$(sed -n -e '$p' "edited/$file/information.txt" | cut -c 2-5)
sed -i 1i$time "edited/$file/$file.txt"
python3 Parsing.py "$file" "$effectfile"
g++ -std=c++11 -o manipulate manipulate.cpp
./manipulate
i="0"
effects=( "pitch" "vol" "speed" )
while [ -f "edited/$file/$i.txt" ]
do
    fileeffects=""
    for effect in "${effects[@]}"
    do
	if [ -f "edited/$file/$effect-$i.txt" ]
	then
	    num=$(cat "edited/$file/$effect-$i.txt")
	    fileeffects="$fileeffects $effect $num"
	fi
    done
    ./toraw -ss < "edited/$file/$i.txt" | sox -t raw -r 44100 -e signed-integer -b 16 -c 2 - "edited/$file/$i.wav" $fileeffects 2> /dev/null
    i=$[$i+1]
done
