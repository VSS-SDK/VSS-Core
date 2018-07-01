//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_ISTDININTERPRETER_H
#define VSS_CORE_ISTDININTERPRETER_H

#include <Domain/ExecutionConfig.h>

namespace vss {

    class IStdinInterpreter {
    public:
        virtual ExecutionConfig extractExecutionConfig(int argc, char **argv) = 0;
    };

};

#endif //VSS_CORE_ISTDININTERPRETER_H
