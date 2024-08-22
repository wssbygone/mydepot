#!/bin/bash

mdl=("module1" "asan" "teacher" "jin")
accumulate_str=""

fun_1() {
for it in "${mdl[@]}"
do 
  formatted_string="$(printf "%-15s %s" "$it" "$(git rev-parse --short HEAD)\n")"
  echo -e "$formatted_string"
  echo "-----------"
  accumulate_str+="$formatted_string"
  echo -e "$accumulate_str"
done
}

fun_2() {
for it in "${mdl[@]}"
do
   length=${#mdl[@]}
   echo ${!mdl[@]}
#   unset mdl[length-1]   #虽然不报错，但是下行写法更严谨
   unset mdl[$((length-1))]  
#   echo ${#mdl[@]}
done
}


fun_2

