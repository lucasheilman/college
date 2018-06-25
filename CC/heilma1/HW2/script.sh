#!/bin/bash

#set off the chatbot servers
python3 a-iChatbot.py 10000 & 
python3 j-rChatbot.py 10001 &
python3 s-zChatbot.py 10002 &

#get pids of servers to kill at the end
sleep 1
atoipid=$(cat "a-ipid.txt")
jtorpid=$(cat "j-rpid.txt")
stozpid=$(cat "s-zpid.txt")

#get questions
echo "Enter a question or 'done':"
while read line
do
    if [ "$line" == "done" ]
    then
        break
    elif [[ "${line:0:1}" == *[ABCDEFGHIabcdefghi]* ]]
    then
        python3 chatbot.py 127.0.0.1 10000 << EOF
$line

EOF
    elif [[ "${line:0:1}" == *[JKLMNOPQRjklmnopqr]* ]]
    then
        python3 chatbot.py 127.0.0.1 10001 << EOF
$line

EOF
    elif [[ "${line:0:1}" == *[STUVWXYZstuvwxyz]* ]]
    then
        python3 chatbot.py 127.0.0.1 10002 << EOF
$line

EOF
    fi  
    echo "Enter a question or 'done':"
done 

#kill servers
kill $atoipid
kill $jtorpid
kill $stozpid
     
