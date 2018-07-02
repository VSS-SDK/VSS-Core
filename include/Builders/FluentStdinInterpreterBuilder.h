//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_FLUENTSTDININTERPRETERBUILDER_H
#define VSS_CORE_FLUENTSTDININTERPRETERBUILDER_H

#include <Interfaces/IFluentStdinInterpreterBuilder.h>

namespace vss {

    class FluentStdinInterpreterBuilder : public IFluentStdinInterpreterBuilder {
    public:
        FluentStdinInterpreterBuilder();

        IStdinInterpreter* buildInterpreter() override;

        IFluentStdinInterpreterBuilder* enableStateReceiverAddress() override;
        IFluentStdinInterpreterBuilder* enableStateSenderAddress() override;
        IFluentStdinInterpreterBuilder* enableYellowCommandReceiverAddress() override;
        IFluentStdinInterpreterBuilder* enableYellowCommandSenderAddress() override;
        IFluentStdinInterpreterBuilder* enableYellowDebugReceiverAddress() override;
        IFluentStdinInterpreterBuilder* enableYellowDebugSenderAddress() override;
        IFluentStdinInterpreterBuilder* enableBlueCommandReceiverAddress() override;
        IFluentStdinInterpreterBuilder* enableBlueCommandSenderAddress() override;
        IFluentStdinInterpreterBuilder* enableBlueDebugReceiverAddress() override;
        IFluentStdinInterpreterBuilder* enableBlueDebugSenderAddress() override;
        IFluentStdinInterpreterBuilder* enableControlReceiverAddress() override;
        IFluentStdinInterpreterBuilder* enableControlSenderAddress() override;

        IFluentStdinInterpreterBuilder* enableStateCommunicationPort() override;
        IFluentStdinInterpreterBuilder* enableYellowCommandCommunicationPort() override;
        IFluentStdinInterpreterBuilder* enableYellowDebugCommunicationPort() override;
        IFluentStdinInterpreterBuilder* enableBlueCommandCommunicationPort() override;
        IFluentStdinInterpreterBuilder* enableBlueDebugCommunicationPort() override;
        IFluentStdinInterpreterBuilder* enableControlCommunicationPort() override;

        IFluentStdinInterpreterBuilder* enableTeamType() override;
        IFluentStdinInterpreterBuilder* enableSideAttackType() override;
        IFluentStdinInterpreterBuilder* enableTimeExecutionType() override;
        IFluentStdinInterpreterBuilder* enableEnvironmentType() override;

    private:
        IStdinInterpreter *stdinInterpreter;
    };

};

#endif //VSS_CORE_FLUENTSTDININTERPRETERBUILDER_H
