#!/bin/bash

#a=$(cd $(dirname $0) && pwd) ; echo $a
scriptdir=`dirname ${0}`
scriptdir=`(cd ${scriptdir}; pwd)`
scriptname=`basename ${0}`

set -e

function errorexit()
{
  errorcode=${1}
  shift
  echo $@
  exit ${errorcode}
}

function usage()
{
  echo "USAGE ${scriptname} <tostrip>"
}

tostripdir=`dirname "$1"`
tostripfile=`basename "$1"`

echo "$tostripdir +  $tostripfile" 


if [ -z ${tostripfile} ] ; then
  usage
  errorexit 0 "tostrip must be specified"
fi

cd "${tostripdir}"

pwd
debugdir=.debug
debugfile="${tostripfile}.debug"

if [ ! -d "${debugdir}" ] ; then
  echo "creating dir ${tostripdir}/${debugdir}"
  mkdir -p "${debugdir}"
fi

echo "stripping ${tostripfile}, putting debug info into ${debugfile}"
objcopy --only-keep-debug "${tostripfile}" "${debugdir}/${debugfile}"
strip --strip-debug --strip-unneeded "${tostripfile}"

objcopy --add-gnu-debuglink="${debugdir}/${debugfile}" "${tostripfile}"
chmod -x "${debugdir}/${debugfile}"
