
main() {
  local arg
  for arg; do     # equal to  for arg in "$@"; do
    echo $arg
  done
}


main "$@"


i=10
while ((i > 0))
do 
   ((i-=1))
   echo $i
#   sleep 1
done   
