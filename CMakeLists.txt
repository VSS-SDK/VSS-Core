cmake_minimum_required(VERSION 2.8.9)
project(vss-interface)
set(CMAKE_BUILD_TYPE Release)

ADD_SUBDIRECTORY(protos)

#Bring the headers, such as Student.h into the project
include_directories(includes)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB PROTOS "protos/*.cc")

#Generate the shared library from the sources
add_library(vss-interface SHARED ${SOURCES})

TARGET_LINK_LIBRARIES(vss-interface protos ${PROTOBUF_LIBRARY})

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS vss-interface DESTINATION /usr/lib)
