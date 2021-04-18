#!/bin/bash





CURR_PATH=`pwd`
LIB_PATH=${CURR_PATH}/lib/

#编译 libuv
cd ./third_party/libuv
./build.sh
cd ${CURR_PATH}

#编译 libuvcpp
cd ./third_party/uv-cpp
./build.sh
cd ${CURR_PATH}

#编译 libuvnsq
if [ ! -d ./build ]; then
    mkdir ./build
else 
    rm   ./build  -rf
    mkdir ./build
fi

cd ./build 

cmake .. -DCMAKE_BUILD_TYPE=Release

make -j4

cp libuvnsq.a ${LIB_PATH}

cd ${CURR_PATH}

rm build -rf