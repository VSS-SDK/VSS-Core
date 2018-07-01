//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_ISTDININTERPRETER_H
#define VSS_CORE_ISTDININTERPRETER_H

#include <Domain/StdinConfiguration.h>

namespace vss {

    class IStdinInterpreter {
    public:
        virtual StdinConfiguration extractConfiguration(int argc, char** argv) = 0;
    };

};

#endif //VSS_CORE_ISTDININTERPRETER_H
