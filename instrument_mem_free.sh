PID=$(./mem_free.o > /dev/null &)
echo 'pid='$PID
top -pid $PID -stats pid,command,cpu,mem
kill -9 $PID
