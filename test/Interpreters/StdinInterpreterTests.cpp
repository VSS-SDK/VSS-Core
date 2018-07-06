//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Interpreters/StdinInterpreter.h>
#include <Domain/Constants.h>

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

TEST(StdinInterpreter_extractExecutionConfig, WhenAllConfigsAreFalseAnHelp_ShouldPrintOnlyHelp){
    vss::StdinInterpreter stdinInterpreter;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnStateRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStateRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --state_recv_addr arg (=" << vss::DEFAULT_STATE_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnStateSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStateSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --state_send_addr arg (=" << vss::DEFAULT_STATE_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowCmdRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_cmd_recv_addr arg (=" << vss::DEFAULT_CMD_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowCmdSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_cmd_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowDebugRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_debug_recv_addr arg (=" << vss::DEFAULT_CMD_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowDebugSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_debug_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}


TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueCmdRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_cmd_recv_addr arg (=" << vss::DEFAULT_CMD_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueCmdSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_cmd_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueDebugRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_debug_recv_addr arg (=" << vss::DEFAULT_CMD_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueDebugSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_debug_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnCtrlRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --ctrl_recv_addr arg (=" << vss::DEFAULT_CTRL_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnCtrlSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --ctrl_send_addr arg (=" << vss::DEFAULT_CTRL_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnStatePortIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStatePort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --state_port arg (=" << vss::DEFAULT_STATE_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowCmdPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_cmd_port arg (=" << vss::DEFAULT_CMD_YELLOW_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowDebugPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_debug_port arg (=" << vss::DEFAULT_DEBUG_YELLOW_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueCmdPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_cmd_port arg (=" << vss::DEFAULT_CMD_BLUE_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueDebugPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_debug_port arg (=" << vss::DEFAULT_DEBUG_BLUE_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnCtrlPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --ctrl_port arg (=" << vss::DEFAULT_CTRL_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnTeamTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --team_type arg (=" << vss::toDescription(vss::DEFAULT_TEAM_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnSideAttackTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onSideAttackType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --side_attack_type arg (=" << vss::toDescription(vss::DEFAULT_SIDE_ATTACK_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnTimeExecutionTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTimeExecutionType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --time_execution_type arg (=" << vss::toDescription(vss::DEFAULT_TIME_EXECUTION_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnEnvironmentTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onEnvironmentType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --environment_type arg (=" << vss::toDescription(vss::DEFAULT_ENVIRONMENT_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnStateSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStateSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--state_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnStateRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStateRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--state_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowCmdSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_cmd_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowCmdRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_cmd_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowDebugSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_debug_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowDebugRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_debug_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueCmdSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_cmd_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueCmdRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_cmd_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueDebugSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_debug_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueDebugRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_debug_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnCtrlSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--ctrl_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnCtrlRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--ctrl_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnStatePortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStatePort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--state_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowCmdPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_cmd_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueCmdPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_cmd_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowDebugPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_debug_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueDebugPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_debug_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnCtrlPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--ctrl_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTeamTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--team_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnSideAttackTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onSideAttackType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--side_attack_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTimeExecutionTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTimeExecutionType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--time_execution_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnEnvironmentTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onEnvironmentType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--environment_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}