#!/bin/bash

COMPILE_TYPE=$1

COMPILE_PROTOs() {
    protoc -I=. --cpp_out=. protos/state.proto
    protoc -I=. --cpp_out=. protos/command.proto
    protoc -I=. --cpp_out=. protos/debug.proto
    protoc -I=. --cpp_out=. protos/control.proto

    mkdir -p src/protos
    mkdir -p include/protos

    mv protos/*.pb.cc src/protos
    mv protos/*.pb.h include/protos
}

CMAKE () {
    cmake ..
    make
    cd ..
}

CMAKE_INSTALL () {
    cmake -D RELEASE=ON ..
    make install
    cd ..
}

CREATE_BUILD_FOLDER() {
    rm -R build
    mkdir -p build
    cd build
}

INIT_SUBMODULES() {
    git submodule init;
    git submodule update;
}

INSTALL_ANSIBLE() {
    {
        apt-get update
        apt-get install -y python-pip python-dev
    } || {
        dnf update -y
        dnf install -y python-pip python-dev
    } || {
        yum update
        yum install -y python-pip python-dev
    }

    {
        sudo -H pip3 install ansible==2.7.8.0
    } || {
        pip3 install ansible==2.7.8.0
    } || {
        sudo -H pip install ansible==2.7.8.0
    } || {
        pip install ansible==2.7.8.0
    }
}

INSTALL () {
    INSTALL_ANSIBLE;

    ansible-playbook scripts/ansible/instala.yml

    INIT_SUBMODULES;
    COMPILE_PROTOs;
    CREATE_BUILD_FOLDER;

    if [[ $COMPILE_TYPE == "development" ]];
    then
        CMAKE;
    else
        CMAKE_INSTALL;
    fi
}

INSTALL;
