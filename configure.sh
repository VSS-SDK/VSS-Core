#!/bin/bash
#
# This file is part of the VSS-SDK project.
#
# This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
# v. 3.0. If a copy of the GPL was not distributed with this
# file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
#

DISTRO=`lsb_release -si`
RELEASE=`lsb_release -sr`
ARCHITECTURE=`uname -m`

INSTALLED=0

CMAKE_UBUNTU () {
  ./protos.sh
  sudo rm -R build
  mkdir build
  cd build
  cmake ..
  sudo make install
  cd ..
}

CMAKE_MINT () {
  ./protos.sh
  sudo rm -R build
  mkdir build
  cd build
  cmake ..
  sudo make install
  cd ..
}

CMAKE_DEBIAN () {
  ./protos.sh
  rm -R build
  mkdir build
  cd build
  cmake ..
  make install
  cd ..
}

INSTALL_UBUNTU_14_04 () {
  sudo apt-get update && apt-get upgrade
  sudo apt-get install pkg-config
  sudo apt-get install g++ cmake libzmqpp3 libzmqpp-dev protobuf-compiler libprotobuf-dev
  INSTALLED=1
}

INSTALL_UBUNTU_16_04 () {
  sudo apt-get update && apt-get upgrade
  sudo apt-get install pkg-config
  sudo apt-get install g++ cmake libzmqpp3 libzmqpp-dev protobuf-compiler libprotobuf-dev
  INSTALLED=1
}

INSTALL_UBUNTU_16_10 () {
  sudo apt-get update && apt-get upgrade
  sudo apt-get install pkgconf
  sudo apt-get install g++ cmake libzmq5 libzmq3-dev protobuf-compiler libprotobuf-dev
  INSTALLED=1
}

INSTALL_MINT_18_2 () {
  sudo apt-get update && apt-get upgrade
  sudo apt-get install pkg-config
  sudo apt-get install g++ cmake libzmqpp3 libzmqpp-dev protobuf-compiler libprotobuf-dev
  INSTALLED=1
}

INSTALL_DEBIAN () {
  sudo apt-get update && apt-get upgrade
  sudo apt-get install pkgconf
  sudo apt-get install g++ cmake libzmq5 libzmq3-dev protobuf-compiler libprotobuf-dev
  INSTALLED=1
}

INSTALL () {
  # Ubuntu
  if [[ "$DISTRO" == "Ubuntu" ]] && [[ "$RELEASE" == "16.04" ]]; then
    INSTALL_UBUNTU_16_04;
    if [ $INSTALLED == 1 ]; then
      CMAKE_UBUNTU;
    fi
  fi

  if [[ "$DISTRO" == "Ubuntu" ]] && [[ "$RELEASE" == "16.10" ]]; then
    INSTALL_UBUNTU_16_10;
    if [ $INSTALLED == 1 ]; then
      CMAKE_UBUNTU;
    fi
  fi

  if [[ "$DISTRO" == "Ubuntu" ]] && [[ "$RELEASE" == "14.04" ]]; then
      INSTALL_UBUNTU_14_04;
      if [ $INSTALLED == 1 ]; then
        CMAKE_UBUNTU;
      fi
    fi

  # Debian
  if [[ "$DISTRO" == "Debian" ]]; then
    INSTALL_DEBIAN;
    if [ $INSTALLED == 1 ]; then
      CMAKE_DEBIAN;
    fi
  fi

  # LinuxMint
  if [[ "$DISTRO" == "LinuxMint" ]] && [[ "$RELEASE" == "18.2" ]]; then
    INSTALL_MINT_18_2;
    if [ $INSTALLED == 1 ]; then
      CMAKE_MINT;
    fi
  fi

  if [[ $INSTALLED == 0 ]]; then
    echo "Sistema Operacional Incompatível";
  fi
}

INSTALL;
