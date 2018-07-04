//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Interpreters/StdinInterpreter.h>

TEST(StdinInterpreter_Constructor, WhenDefaultBuilded_ShouldBeFalse){
    vss::StdinInterpreter stdinInterpreter;

    EXPECT_EQ(stdinInterpreter.onStateRecvAddr, false);
    EXPECT_EQ(stdinInterpreter.onStateSendAddr, false);

    EXPECT_EQ(stdinInterpreter.onYellowCmdRecvAddr, false);
    EXPECT_EQ(stdinInterpreter.onYellowCmdSendAddr, false);
    EXPECT_EQ(stdinInterpreter.onYellowDebugRecvAddr, false);
    EXPECT_EQ(stdinInterpreter.onYellowDebugSendAddr, false);

    EXPECT_EQ(stdinInterpreter.onBlueCmdRecvAddr, false);
    EXPECT_EQ(stdinInterpreter.onBlueCmdSendAddr, false);
    EXPECT_EQ(stdinInterpreter.onBlueDebugRecvAddr, false);
    EXPECT_EQ(stdinInterpreter.onBlueDebugSendAddr, false);

    EXPECT_EQ(stdinInterpreter.onCtrlRecvAddr, false);
    EXPECT_EQ(stdinInterpreter.onCtrlSendAddr, false);

    EXPECT_EQ(stdinInterpreter.onStatePort, false);
    EXPECT_EQ(stdinInterpreter.onYellowCmdPort, false);
    EXPECT_EQ(stdinInterpreter.onYellowDebugPort, false);
    EXPECT_EQ(stdinInterpreter.onBlueCmdPort, false);
    EXPECT_EQ(stdinInterpreter.onBlueDebugPort, false);
    EXPECT_EQ(stdinInterpreter.onCtrlPort, false);

    EXPECT_EQ(stdinInterpreter.onTeamType, false);
    EXPECT_EQ(stdinInterpreter.onSideAttackType, false);
    EXPECT_EQ(stdinInterpreter.onTimeExecutionType, false);
    EXPECT_EQ(stdinInterpreter.onEnvironmentType, false);
}
