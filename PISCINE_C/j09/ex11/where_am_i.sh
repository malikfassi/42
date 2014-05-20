RET=$(ifconfig | grep '\<inet\>' | cut -d ' ' -f2 | grep -v 127)
a=${?}
if [ ${a} -ne 0 ]; then echo "Je suis perdu!"; else echo $RET; fi
