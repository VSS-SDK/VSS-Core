cmake_minimum_required(VERSION 2.8.9)
project(vss-interface)
set(CMAKE_BUILD_TYPE Release)

find_package(PkgConfig)
INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)

find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )

find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )

#Bring the headers, such as Student.h into the project
include_directories(include)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB CPP "src/*.cpp")
file(GLOB CC "src/*.cc")

#Generate the shared library from the sources
add_library(vss-interface SHARED ${CPP} ${CC})

target_include_directories(vss-interface PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(vss-interface PUBLIC ${ZeroMQ_LIBRARY})
target_link_libraries(vss-interface ${PROTOBUF_LIBRARIES})

SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

install(TARGETS vss-interface DESTINATION /usr/lib)
install(DIRECTORY include/ DESTINATION include/ FILES_MATCHING PATTERN "*.h")
