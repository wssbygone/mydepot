echo $(seq 1 9) | awk '{ print $5,$6,$7}' | while read a b c
do
   echo -n "Loop times: "
   echo $a $b $c
   rep=$(ls -l $0 |column -t)
#   echo "$rep" | sed -n 's/\([^ ]*\)  \([^ ]*\)  \([^ ]*\)  \(.*\)/\1'"[${a}]"'\2'"[${b}]"'\3'"[${c}]"'\4/p'
   echo $rep
done
echo "========"
echo $a $b $c
