//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/ExecutionConfig.h>
#include <Domain/Constants.h>

TEST(ExecutionConfig_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::ExecutionConfig executionConfig;

    EXPECT_EQ(executionConfig.stateSendAddr.getIp(), vss::DEFAULT_STATE_SEND_ADDRESS);
    EXPECT_EQ(executionConfig.stateSendAddr.getPort(), vss::DEFAULT_STATE_PORT);
    EXPECT_EQ(executionConfig.stateRecvAddr.getIp(), vss::DEFAULT_STATE_RECEIVE_ADDRESS);
    EXPECT_EQ(executionConfig.stateRecvAddr.getPort(), vss::DEFAULT_STATE_PORT);

    EXPECT_EQ(executionConfig.cmdYellowRecvAddr.getIp(), vss::DEFAULT_COMMAND_RECEIVE_ADDRESS);
    EXPECT_EQ(executionConfig.cmdYellowRecvAddr.getPort(), vss::DEFAULT_COMMAND_YELLOW_PORT);
    EXPECT_EQ(executionConfig.cmdYellowSendAddr.getIp(), vss::DEFAULT_COMMAND_SEND_ADDRESS);
    EXPECT_EQ(executionConfig.cmdYellowSendAddr.getPort(), vss::DEFAULT_COMMAND_YELLOW_PORT);
    EXPECT_EQ(executionConfig.debugYellowRecvAddr.getIp(), vss::DEFAULT_DEBUG_RECEIVE_ADDRESS);
    EXPECT_EQ(executionConfig.debugYellowRecvAddr.getPort(), vss::DEFAULT_DEBUG_YELLOW_PORT);
    EXPECT_EQ(executionConfig.debugYellowSendAddr.getIp(), vss::DEFAULT_DEBUG_SEND_ADDRESS);
    EXPECT_EQ(executionConfig.debugYellowSendAddr.getPort(), vss::DEFAULT_DEBUG_YELLOW_PORT);

    EXPECT_EQ(executionConfig.cmdBlueRecvAddr.getIp(), vss::DEFAULT_COMMAND_RECEIVE_ADDRESS);
    EXPECT_EQ(executionConfig.cmdBlueRecvAddr.getPort(), vss::DEFAULT_COMMAND_BLUE_PORT);
    EXPECT_EQ(executionConfig.cmdBlueSendAddr.getIp(), vss::DEFAULT_COMMAND_SEND_ADDRESS);
    EXPECT_EQ(executionConfig.cmdBlueSendAddr.getPort(), vss::DEFAULT_COMMAND_BLUE_PORT);
    EXPECT_EQ(executionConfig.debugBlueRecvAddr.getIp(), vss::DEFAULT_DEBUG_RECEIVE_ADDRESS);
    EXPECT_EQ(executionConfig.debugBlueRecvAddr.getPort(), vss::DEFAULT_DEBUG_BLUE_PORT);
    EXPECT_EQ(executionConfig.debugBlueSendAddr.getIp(), vss::DEFAULT_DEBUG_SEND_ADDRESS);
    EXPECT_EQ(executionConfig.debugBlueSendAddr.getPort(), vss::DEFAULT_DEBUG_BLUE_PORT);

    EXPECT_EQ(executionConfig.ctrlSendAddr.getIp(), vss::DEFAULT_CONTROL_SEND_ADDRESS);
    EXPECT_EQ(executionConfig.ctrlSendAddr.getPort(), vss::DEFAULT_CONTROL_PORT);
    EXPECT_EQ(executionConfig.ctrlRecvAddr.getIp(), vss::DEFAULT_CONTROL_RECEIVE_ADDRESS);
    EXPECT_EQ(executionConfig.ctrlRecvAddr.getPort(), vss::DEFAULT_CONTROL_PORT);

    EXPECT_EQ(executionConfig.isValidConfiguration, false);
}

TEST(ExecutionConfig_cout, WhenCoutShouldPrintRight){
    vss::ExecutionConfig executionConfig;

    testing::internal::CaptureStdout();
    std::cout << executionConfig;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << "stateSendAddr: " << executionConfig.stateSendAddr.ip << ":" << executionConfig.stateSendAddr.port << std::endl;
    mock_output << "stateRecvAddr: " << executionConfig.stateRecvAddr.ip << ":" << executionConfig.stateRecvAddr.port << std::endl;

    mock_output << "cmdYellowSendAddr: " << executionConfig.cmdYellowSendAddr.ip << ":" << executionConfig.cmdYellowSendAddr.port << std::endl;
    mock_output << "cmdYellowRecvAddr: " << executionConfig.cmdYellowRecvAddr.ip << ":" << executionConfig.cmdYellowRecvAddr.port << std::endl;
    mock_output << "debugYellowSendAddr: " << executionConfig.debugYellowSendAddr.ip << ":" << executionConfig.debugYellowSendAddr.port << std::endl;
    mock_output << "debugYellowRecvAddr: " << executionConfig.debugYellowRecvAddr.ip << ":" << executionConfig.debugYellowRecvAddr.port << std::endl;

    mock_output << "cmdBlueSendAddr: " << executionConfig.cmdBlueSendAddr.ip << ":" << executionConfig.cmdBlueSendAddr.port << std::endl;
    mock_output << "cmdBlueRecvAddr: " << executionConfig.cmdBlueRecvAddr.ip << ":" << executionConfig.cmdBlueRecvAddr.port << std::endl;
    mock_output << "debugBlueSendAddr: " << executionConfig.debugBlueSendAddr.ip << ":" << executionConfig.debugBlueSendAddr.port << std::endl;
    mock_output << "debugBlueRecvAddr: " << executionConfig.debugBlueRecvAddr.ip << ":" << executionConfig.debugBlueRecvAddr.port << std::endl;

    mock_output << "ctrlSendAddr: " << executionConfig.ctrlSendAddr.ip << ":" << executionConfig.ctrlSendAddr.port << std::endl;
    mock_output << "ctrlRecvAddr: " << executionConfig.ctrlRecvAddr.ip << ":" << executionConfig.ctrlRecvAddr.port << std::endl;

    mock_output << "teamType: " << toDescription(executionConfig.teamType) << std::endl;
    mock_output << "sideAttackType: " << toDescription(executionConfig.sideAttackType) << std::endl;
    mock_output << "timeExecutionType: " << toDescription(executionConfig.timeExecutionType) << std::endl;
    mock_output << "environmentType: " << toDescription(executionConfig.environmentType) << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}