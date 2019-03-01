#!/bin/bash

COMPILE_TYPE=$1

source scripts/base.sh

INSTALL () {
    ansible-playbook scripts/ansible/instala.yml

    INIT_SUBMODULES;

    if [[ $COMPILE_TYPE == "development" ]];
    then
        CMAKE;
    else
        CMAKE_INSTALL;
    fi
}

INSTALL;
