//
// Created by johnathan on 01/07/18.
//

#include <Builders/FluentStdinInterpreterBuilder.h>
#include <Interpreters/StdinInterpreter.h>

namespace vss {

    FluentStdinInterpreterBuilder::FluentStdinInterpreterBuilder() {
        stdinInterpreter = new StdinInterpreter();
    }

    IStdinInterpreter* FluentStdinInterpreterBuilder::buildInterpreter() {
        return stdinInterpreter;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableStateReceiverAddress() {
        stdinInterpreter->looksForStateReceiverAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableStateSenderAddress() {
        stdinInterpreter->looksForStateSenderAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableYellowCommandReceiverAddress() {
        stdinInterpreter->looksForYellowCommandReceiverAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableYellowCommandSenderAddress() {
        stdinInterpreter->looksForYellowCommandSenderAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableYellowDebugReceiverAddress() {
        stdinInterpreter->looksForYellowDebugReceiverAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableYellowDebugSenderAddress() {
        stdinInterpreter->looksForYellowDebugSenderAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableBlueCommandReceiverAddress() {
        stdinInterpreter->looksForBlueCommandReceiverAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableBlueCommandSenderAddress() {
        stdinInterpreter->looksForBlueCommandSenderAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableBlueDebugReceiverAddress() {
        stdinInterpreter->looksForBlueDebugReceiverAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableBlueDebugSenderAddress() {
        stdinInterpreter->looksForBlueDebugSenderAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableControlReceiverAddress() {
        stdinInterpreter->looksForControlReceiverAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableControlSenderAddress() {
        stdinInterpreter->looksForControlSenderAddress = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableTeamType() {
        stdinInterpreter->looksForTeamType = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableYellowCommandCommunicationPort() {
        stdinInterpreter->looksForYellowCommandCommunicationPort = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableYellowDebugCommunicationPort() {
        stdinInterpreter->looksForYellowDebugCommunicationPort = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableBlueCommandCommunicationPort() {
        stdinInterpreter->looksForBlueCommandCommunicationPort = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableBlueDebugCommunicationPort() {
        stdinInterpreter->looksForBlueDebugCommunicationPort = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableControlCommunicationPort() {
        stdinInterpreter->looksForControlCommunicationPort = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableSideAttackType() {
        stdinInterpreter->looksForSideAttackType = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableTimeExecutionType() {
        stdinInterpreter->looksForTimeExecutionType = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableStateCommunicationPort() {
        stdinInterpreter->looksForStateCommunicationPort = true;
        return this;
    }

    IFluentStdinInterpreterBuilder *FluentStdinInterpreterBuilder::enableEnvironmentType() {
        stdinInterpreter->looksForEnvironmentType = true;
        return this;
    }

};