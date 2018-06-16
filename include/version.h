//
// Created by johnathan on 16/06/18.
//

#ifndef VSS_CORE_VERSION_H
#define VSS_CORE_VERSION_H

#include <string>
#include <iostream>
#include "sstream"

#define VSS_CORE_MAJOR_VERSION 1
#define VSS_CORE_MINOR_VERSION 0
#define VSS_CORE_PATCH_VERSION 0

namespace vss {

    std::string getCoreVersion(){
        std::stringstream ss;
        ss << "vss-core: " << VSS_CORE_MAJOR_VERSION << "." << VSS_CORE_MINOR_VERSION << "." << VSS_CORE_PATCH_VERSION;
        return ss.str();
    }

    void printCoreVersion(){
        std::cout << getCoreVersion() << std::endl;
    }

}

#endif //VSS_CORE_VERSION_H
