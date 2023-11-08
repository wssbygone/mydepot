#!/bin/bash
PATH1=$(dirname $0)
PATH2=$(cd `dirname $0`;pwd)
PATH3=$(readlink -f $PATH1/..)
echo $PATH1
echo $PATH2
echo $PATH3
