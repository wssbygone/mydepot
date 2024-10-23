mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=`pwd`/.. ..
make && make install
