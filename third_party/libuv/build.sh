#!/bin/bash

CURR_PATH=`pwd`
LIB_PATH=${CURR_PATH}/../../lib/

if [ ! -d ./build ]; then
    mkdir ./build
else 
    rm   ./build  -rf
    mkdir ./build
fi

cd ./build 

cmake .. -DCMAKE_BUILD_TYPE=Release

make -j4

cp libuv_a.a ${LIB_PATH}/libuv.a

cd ${CURR_PATH}
rm build -rf