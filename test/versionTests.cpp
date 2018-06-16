//
// Created by johnathan on 16/06/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <version.h>

TEST(getCoreVersion, ShouldReturnValidVersion){
    auto version = vss::getCoreVersion();
    std::stringstream mock_version;
    mock_version << "vss-core: " << vss_core_VERSION_MAJOR << "." << vss_core_VERSION_MINOR << "." << vss_core_VERSION_PATCH;

    EXPECT_EQ(version, mock_version.str());
}

TEST(printCoreVersion, ShouldPrintAValidVersion){
    testing::internal::CaptureStdout();
    vss::printCoreVersion();
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_version;
    mock_version << "vss-core: "  << vss_core_VERSION_MAJOR << "." << vss_core_VERSION_MINOR << "." << vss_core_VERSION_PATCH << std::endl;
    EXPECT_STREQ(output.c_str(), mock_version.str().c_str());
}