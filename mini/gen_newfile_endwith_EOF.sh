#!/bin/bash
set -x
ROOTDIR=$PWD  
cat<<EOF > $ROOTDIR/ShareMakefile.in
ROOTDIR = $ROOTDIR
EOF


cat<<EOF > $ROOTDIR/header.sh
#!/bin/bash
ROOTDIR=$ROOTDIR
EOF
