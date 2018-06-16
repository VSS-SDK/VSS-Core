//
// Created by johnathan on 16/06/18.
//

#ifndef VSS_CORE_VERSION_H
#define VSS_CORE_VERSION_H

#include <string>
#include <iostream>

#define vss_core_VERSION_MAJOR 1
#define vss_core_VERSION_MINOR 0
#define vss_core_VERSION_PATCH 0

namespace vss {

    std::string getCoreVersion(){
        std::stringstream ss;
        ss << "vss-core: " << vss_core_VERSION_MAJOR << "." << vss_core_VERSION_MINOR << "." << vss_core_VERSION_PATCH;
        return ss.str();
    }

    void printCoreVersion(){
        std::cout << getCoreVersion() << std::endl;
    }

}

#endif //VSS_CORE_VERSION_H
