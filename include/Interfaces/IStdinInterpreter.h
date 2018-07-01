//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_ISTDININTERPRETER_H
#define VSS_CORE_ISTDININTERPRETER_H

#include <Domain/ExecutionConfiguration.h>

namespace vss {

    class IStdinInterpreter {
    public:
        virtual ExecutionConfiguration extractExecutionConfiguration(int argc, char **argv) = 0;
    };

};

#endif //VSS_CORE_ISTDININTERPRETER_H
