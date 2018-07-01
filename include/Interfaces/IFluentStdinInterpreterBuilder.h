//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_ISTDININTERPRETERBUILDER_H
#define VSS_CORE_ISTDININTERPRETERBUILDER_H

#include "Interfaces/IStdinInterpreter.h"

namespace vss {

    class IFluentStdinInterpreterBuilder {
    public:
        virtual IStdinInterpreter* buildInterpreter() = 0;
        virtual IFluentStdinInterpreterBuilder* enableStateReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableStateSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder enableCommandReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder enableCommandSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder enableDebugReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder enableDebugSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder enableControlReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder enableControlSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder enableTeamType() = 0;
        virtual IFluentStdinInterpreterBuilder enableSideAttackType() = 0;
        virtual IFluentStdinInterpreterBuilder enableTimeExecutionType() = 0;
    };

};

#endif //VSS_CORE_ISTDININTERPRETERBUILDER_H
