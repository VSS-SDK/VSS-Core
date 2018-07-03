//
// Created by johnathan on 01/07/18.
//

#include <Builders/StdinInterpreterBuilder.h>
#include <Interpreters/StdinInterpreter.h>

namespace vss {

    StdinInterpreterBuilder::StdinInterpreterBuilder() {
        stdinInterpreter = new StdinInterpreter();
    }

    IStdinInterpreter* StdinInterpreterBuilder::buildInterpreter() {
        return stdinInterpreter;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onStateRecvAddr() {
        stdinInterpreter->looksForStateReceiverAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onStateSendAddr() {
        stdinInterpreter->looksForStateSenderAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowCmdRecvAddr() {
        stdinInterpreter->looksForYellowCommandReceiverAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowCmdSendAddr() {
        stdinInterpreter->looksForYellowCommandSenderAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowDebugRecvAddr() {
        stdinInterpreter->looksForYellowDebugReceiverAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowDebugSendAddr() {
        stdinInterpreter->looksForYellowDebugSenderAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueCmdRecvAddr() {
        stdinInterpreter->looksForBlueCommandReceiverAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueCmdSendAddr() {
        stdinInterpreter->looksForBlueCommandSenderAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueDebugRecvAddr() {
        stdinInterpreter->looksForBlueDebugReceiverAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueDebugSendAddr() {
        stdinInterpreter->looksForBlueDebugSenderAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onCtrlRecvAddr() {
        stdinInterpreter->looksForControlReceiverAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onCtrlSendAddr() {
        stdinInterpreter->looksForControlSenderAddress = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onTeamType() {
        stdinInterpreter->looksForTeamType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowCmdPort() {
        stdinInterpreter->looksForYellowCommandCommunicationPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowDebugPort() {
        stdinInterpreter->looksForYellowDebugCommunicationPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueCmdPort() {
        stdinInterpreter->looksForBlueCommandCommunicationPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueDebugPort() {
        stdinInterpreter->looksForBlueDebugCommunicationPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onCtrlPort() {
        stdinInterpreter->looksForControlCommunicationPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onSideAttackType() {
        stdinInterpreter->looksForSideAttackType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onTimeExecutionType() {
        stdinInterpreter->looksForTimeExecutionType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onStatePort() {
        stdinInterpreter->looksForStateCommunicationPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onEnvironmentType() {
        stdinInterpreter->looksForEnvironmentType = true;
        return this;
    }

};