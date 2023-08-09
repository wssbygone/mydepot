#!/bin/bash
echo "bash $0 program"
exe=$1
deplist=$(ldd $exe | awk '{if (match($3,"/")) { printf("%s "),$3 } }')
echo $deplist
if [ -d ball ]; then
  rm -rf ball/*
else
  mkdir ball
fi

for item in $deplist
do
  cp -rf $item ball/
  str=$(ls -l $item |grep -E "\->")
  echo $str
  if [ -n "$str" ]; then 
     str2=$(echo $str |awk -F"->" '{print $2}')
     str1=$(echo $str |awk -F"->" '{print $1}'|awk '{print $NF}')
     str1=$(dirname $str1)/
     str2=$(echo $str2|tr -d ' ')
     str=${str1}${str2}
     cp -rf ${str}* ball/
  fi
 
done
rm ball.zip
zip -ry ball.zip ball
rm -rf ball
