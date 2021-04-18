# CMakeLists.txt
# Copyright (C) orcaer@yeah.net. All rights reserved.
# Last modified: 2021-4-17

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(example)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O2 -fPIC")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -O2 -fPIC")

INCLUDE_DIRECTORIES(
	${PROJECT_SOURCE_DIR}/../include
	${PROJECT_SOURCE_DIR}/../third_party/libuv/include
	${PROJECT_SOURCE_DIR}/../third_party/uv-cpp/
)

SET(PUB_SRC ${PROJECT_SOURCE_DIR}/pub.cpp)
SET(SUB_SRC ${PROJECT_SOURCE_DIR}/sub.cpp)
SET(LOOKUP_SRC ${PROJECT_SOURCE_DIR}/main.cpp)



LINK_DIRECTORIES(
	${PROJECT_SOURCE_DIR}/../lib
)

ADD_EXECUTABLE(pub  ${PUB_SRC})
ADD_EXECUTABLE(sub  ${SUB_SRC})
ADD_EXECUTABLE(lookup  ${SUB_SRC})

TARGET_LINK_LIBRARIES(pub PRIVATE  libuvnsq.a libuvcpp.a libuv.a pthread dl)
TARGET_LINK_LIBRARIES(sub PRIVATE  libuvnsq.a libuvcpp.a libuv.a  pthread dl)
TARGET_LINK_LIBRARIES(lookup PRIVATE  libuvnsq.a libuvcpp.a libuv.a pthread dl)