_update() {
  swu=${@: -1}         // 表示获取参数列表的最后一个参数即arg4 
  _args="${@:1:$#-1}"  // 表示从第一个参数到倒数第二个参数为止的所有参数即arg1 arg2 arg3
  echo $swu
  echo $_args
}

_update arg1 arg2 arg3

