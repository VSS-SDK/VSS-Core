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

        bool looksForStateReceiverAddress;
        bool looksForStateSenderAddress;
        bool looksForYellowCommandReceiverAddress;
        bool looksForYellowCommandSenderAddress;
        bool looksForYellowDebugReceiverAddress;
        bool looksForYellowDebugSenderAddress;
        bool looksForBlueCommandReceiverAddress;
        bool looksForBlueCommandSenderAddress;
        bool looksForBlueDebugReceiverAddress;
        bool looksForBlueDebugSenderAddress;
        bool looksForControlReceiverAddress;
        bool looksForControlSenderAddress;

        bool looksForStateCommunicationPort;
        bool looksForYellowCommandCommunicationPort;
        bool looksForYellowDebugCommunicationPort;
        bool looksForBlueCommandCommunicationPort;
        bool looksForBlueDebugCommunicationPort;
        bool looksForControlCommunicationPort;

        bool looksForTeamType;
        bool looksForSideAttackType;
        bool looksForTimeExecutionType;
        bool looksForEnvironmentType;
    };

};

#endif //VSS_CORE_ISTDININTERPRETER_H
