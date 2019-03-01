#!/bin/bash
source scripts/base.sh

INSTALL () {
    INIT_SUBMODULES;

    ansible-playbook scripts/ansible/instala.yml

    if [[ $COMPILE_TYPE == "development" ]];
    then
        CMAKE;
    else
        CMAKE_INSTALL;
    fi
}

INSTALL;
