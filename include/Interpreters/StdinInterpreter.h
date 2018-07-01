//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_STDININTERPRETER_H
#define VSS_CORE_STDININTERPRETER_H

#include <Interfaces/IStdinInterpreter.h>

namespace vss {

    class StdinInterpreter : public IStdinInterpreter {
    public:
        StdinInterpreter();

        StdinConfiguration extractConfiguration(int argc, char** argv) override;

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

    private:
        boost::program_options::options_description buildOptions();
    };

};

#endif //VSS_CORE_STDININTERPRETER_H
