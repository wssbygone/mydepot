#!/bin/bash

check_exception() {
    ret=$1
    if [ $ret = "DEPS_RELATION_HAS_LOOP" ];then
        echo "DEPS RELATION HAS LOOP"
        return 111
    elif [ $ret = "UNKOWN_MODULE" ];then
        echo "UNKOWN MODULE"
        return 222
    else
        echo "$ret"
    fi
    return 100
}

a=$(check_exception "DEPS_RELATION_HAS_LOOP")
echo "$?"
echo "($a)"
