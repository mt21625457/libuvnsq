# CMakeLists.txt
# Copyright (C) orcaer@yeah.net. All rights reserved.
# Last modified: 2019-9-3

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(uvnsq)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O2 -fPIC")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -O2 -fPIC")

INCLUDE_DIRECTORIES(
			${PROJECT_SOURCE_DIR}/include
			${PROJECT_SOURCE_DIR}/third_party/libuv/include
			${PROJECT_SOURCE_DIR}/third_party/uv-cpp/
			)


file(GLOB UVNSQ_SRC ${PROJECT_SOURCE_DIR}/uvnsq/*.cpp)


LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../lib)


ADD_LIBRARY (${PROJECT_NAME} STATIC ${UVNSQ_SRC} )


TARGET_LINK_LIBRARIES(${PROJECT_NAME} libuv.a libuvcpp.a -pthread)
