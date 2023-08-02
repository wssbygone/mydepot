cat /dev/null > xx.log
for line in $(seq 10 246) 
do
  echo "$line"
#  if [[ -z `grep Unreachable  $(ping -c 1 192.168.66.${line})` ]];then
  ping -c 1 192.168.66.${line}  &>>xx.log  
done


echo "~~~~~~~~~~~~~~~~~~"

grep "64 bytes from" xx.log|grep -v  Unreachable |awk '{print $4}' |tr -d ":"|sort -t . -n -k 4 |uniq 
rm -rf xx.log

