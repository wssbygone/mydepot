#!/usr/bin/env bash

echo "current path: `pwd`"
scriptpath=$(cd `dirname $0`; pwd)
echo -e "~~~$scriptpath~~~~~"

set -e
set -o pipefail

function foo() {
  echo "foo-000"
  return 9
}

echo "0000"
echo "hehe---000" | foo |ls *.notexist  | echo "hehe---999"
echo "9999"
