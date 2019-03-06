#!/usr/bin/env bash

CMAKE () {
    bash scripts/protos.sh
    rm -R build
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
}

CMAKE_INSTALL () {
    bash scripts/protos.sh
    rm -R build
    mkdir -p build
    cd build
    cmake -D RELEASE=ON ..
    make install
    cd ..
}

INIT_SUBMODULES() {
    git submodule init;
    git submodule update;
}