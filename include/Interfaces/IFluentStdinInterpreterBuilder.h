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
        virtual IFluentStdinInterpreterBuilder* enableYellowCommandReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableYellowCommandSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableYellowDebugReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableYellowDebugSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableBlueCommandReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableBlueCommandSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableBlueDebugReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableBlueDebugSenderAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableControlReceiverAddress() = 0;
        virtual IFluentStdinInterpreterBuilder* enableControlSenderAddress() = 0;

        virtual IFluentStdinInterpreterBuilder* enableStateCommunicationPort() = 0;
        virtual IFluentStdinInterpreterBuilder* enableYellowCommandCommunicationPort() = 0;
        virtual IFluentStdinInterpreterBuilder* enableYellowDebugCommunicationPort() = 0;
        virtual IFluentStdinInterpreterBuilder* enableBlueCommandCommunicationPort() = 0;
        virtual IFluentStdinInterpreterBuilder* enableBlueDebugCommunicationPort() = 0;
        virtual IFluentStdinInterpreterBuilder* enableControlCommunicationPort() = 0;

        virtual IFluentStdinInterpreterBuilder* enableTeamType() = 0;
        virtual IFluentStdinInterpreterBuilder* enableSideAttackType() = 0;
        virtual IFluentStdinInterpreterBuilder* enableTimeExecutionType() = 0;
        virtual IFluentStdinInterpreterBuilder* enableEnvironmentType() = 0;
    };

};

#endif //VSS_CORE_ISTDININTERPRETERBUILDER_H
