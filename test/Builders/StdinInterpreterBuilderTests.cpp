//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Builders/StdinInterpreterBuilder.h>

TEST(StdinInterpreterBuilder_buildInterpreter, ShouldReturnAllFalse){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto stdinInterpreter = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(stdinInterpreter->onStateRecvAddr, false);
    EXPECT_EQ(stdinInterpreter->onStateSendAddr, false);

    EXPECT_EQ(stdinInterpreter->onYellowCmdRecvAddr, false);
    EXPECT_EQ(stdinInterpreter->onYellowCmdSendAddr, false);
    EXPECT_EQ(stdinInterpreter->onYellowDebugRecvAddr, false);
    EXPECT_EQ(stdinInterpreter->onYellowDebugSendAddr, false);

    EXPECT_EQ(stdinInterpreter->onBlueCmdRecvAddr, false);
    EXPECT_EQ(stdinInterpreter->onBlueCmdSendAddr, false);
    EXPECT_EQ(stdinInterpreter->onBlueDebugRecvAddr, false);
    EXPECT_EQ(stdinInterpreter->onBlueDebugSendAddr, false);

    EXPECT_EQ(stdinInterpreter->onCtrlRecvAddr, false);
    EXPECT_EQ(stdinInterpreter->onCtrlSendAddr, false);

    EXPECT_EQ(stdinInterpreter->onStatePort, false);
    EXPECT_EQ(stdinInterpreter->onYellowCmdPort, false);
    EXPECT_EQ(stdinInterpreter->onYellowDebugPort, false);
    EXPECT_EQ(stdinInterpreter->onBlueCmdPort, false);
    EXPECT_EQ(stdinInterpreter->onBlueDebugPort, false);
    EXPECT_EQ(stdinInterpreter->onCtrlPort, false);

    EXPECT_EQ(stdinInterpreter->onTeamType, false);
    EXPECT_EQ(stdinInterpreter->onSideAttackType, false);
    EXPECT_EQ(stdinInterpreter->onTimeExecutionType, false);
    EXPECT_EQ(stdinInterpreter->onEnvironmentType, false);
}

TEST(StdinInterpreterBuilder_onStateRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onStateRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onStateRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onStateRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onStateSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onStateSendAddr, false);

    auto configured = stdinInterpreterBuilder.onStateSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onStateSendAddr, true);
}

TEST(StdinInterpreterBuilder_onYellowCmdRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowCmdRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onYellowCmdRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onYellowCmdRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onYellowCmdSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowCmdSendAddr, false);

    auto configured = stdinInterpreterBuilder.onYellowCmdSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onYellowCmdSendAddr, true);
}

TEST(StdinInterpreterBuilder_onYellowDebugRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowDebugRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onYellowDebugRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onYellowDebugRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onYellowDebugSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowDebugSendAddr, false);

    auto configured = stdinInterpreterBuilder.onYellowDebugSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onYellowDebugSendAddr, true);
}

TEST(StdinInterpreterBuilder_onBlueCmdRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueCmdRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onBlueCmdRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onBlueCmdRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onBlueCmdSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueCmdSendAddr, false);

    auto configured = stdinInterpreterBuilder.onBlueCmdSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onBlueCmdSendAddr, true);
}

TEST(StdinInterpreterBuilder_onBlueDebugRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueDebugRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onBlueDebugRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onBlueDebugRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onBlueDebugSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueDebugSendAddr, false);

    auto configured = stdinInterpreterBuilder.onBlueDebugSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onBlueDebugSendAddr, true);
}

TEST(StdinInterpreterBuilder_onCtrlRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onCtrlRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onCtrlRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onCtrlRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onCtrlSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onCtrlSendAddr, false);

    auto configured = stdinInterpreterBuilder.onCtrlSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onCtrlSendAddr, true);
}

TEST(StdinInterpreterBuilder_onTeamType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onTeamType, false);

    auto configured = stdinInterpreterBuilder.onTeamType()->buildInterpreter();
    EXPECT_EQ(configured->onTeamType, true);
}

TEST(StdinInterpreterBuilder_onYellowCmdPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowCmdPort, false);

    auto configured = stdinInterpreterBuilder.onYellowCmdPort()->buildInterpreter();
    EXPECT_EQ(configured->onYellowCmdPort, true);
}

TEST(StdinInterpreterBuilder_onYellowDebugPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowDebugPort, false);

    auto configured = stdinInterpreterBuilder.onYellowDebugPort()->buildInterpreter();
    EXPECT_EQ(configured->onYellowDebugPort, true);
}

TEST(StdinInterpreterBuilder_onBlueCmdPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueCmdPort, false);

    auto configured = stdinInterpreterBuilder.onBlueCmdPort()->buildInterpreter();
    EXPECT_EQ(configured->onBlueCmdPort, true);
}

TEST(StdinInterpreterBuilder_onBlueDebugPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueDebugPort, false);

    auto configured = stdinInterpreterBuilder.onBlueDebugPort()->buildInterpreter();
    EXPECT_EQ(configured->onBlueDebugPort, true);
}

TEST(StdinInterpreterBuilder_onCtrlPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onCtrlPort, false);

    auto configured = stdinInterpreterBuilder.onCtrlPort()->buildInterpreter();
    EXPECT_EQ(configured->onCtrlPort, true);
}

TEST(StdinInterpreterBuilder_onSideAttackType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onSideAttackType, false);

    auto configured = stdinInterpreterBuilder.onSideAttackType()->buildInterpreter();
    EXPECT_EQ(configured->onSideAttackType, true);
}

TEST(StdinInterpreterBuilder_onTimeExecutionType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onTimeExecutionType, false);

    auto configured = stdinInterpreterBuilder.onTimeExecutionType()->buildInterpreter();
    EXPECT_EQ(configured->onTimeExecutionType, true);
}

TEST(StdinInterpreterBuilder_onStatePort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onStatePort, false);

    auto configured = stdinInterpreterBuilder.onStatePort()->buildInterpreter();
    EXPECT_EQ(configured->onStatePort, true);
}

TEST(StdinInterpreterBuilder_onEnvironmentType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onEnvironmentType, false);

    auto configured = stdinInterpreterBuilder.onEnvironmentType()->buildInterpreter();
    EXPECT_EQ(configured->onEnvironmentType, true);
}

TEST(StdinInterpreterBuilder_TwoFluents, ShouldReturnThisAndSetValues){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onEnvironmentType, false);
    EXPECT_EQ(raw->onStatePort, false);

    auto configured = stdinInterpreterBuilder.onStatePort()->onEnvironmentType()->buildInterpreter();
    EXPECT_EQ(configured->onEnvironmentType, true);
    EXPECT_EQ(configured->onStatePort, true);
}