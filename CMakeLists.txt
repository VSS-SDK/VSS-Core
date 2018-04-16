cmake_minimum_required(VERSION 2.8.9)
project(vss-core)
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
file(GLOB H "src/*.h")

set(CLION SOURCE ${CC} ${CPP} ${H})

#Generate the shared library from the sources
add_library(vss-core SHARED ${CPP} ${CC})

target_include_directories(vss-core PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(vss-core PUBLIC ${ZeroMQ_LIBRARY})
target_link_libraries(vss-core ${PROTOBUF_LIBRARIES})

SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

install(TARGETS vss-core DESTINATION /usr/lib)
install(DIRECTORY include/ DESTINATION include/ FILES_MATCHING PATTERN "*.h")
