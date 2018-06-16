//
// Created by johnathan on 16/06/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <version.h>

TEST(getCoreVersion, ShouldReturnValidVersion){
    auto version = vss::getCoreVersion();
    std::stringstream mock_version;
    mock_version << "vss-core: " << VSS_CORE_MAJOR_VERSION << "." << VSS_CORE_MINOR_VERSION << "." << VSS_CORE_PATCH_VERSION;

    EXPECT_EQ(version, mock_version.str());
}

TEST(printCoreVersion, ShouldPrintAValidVersion){
    testing::internal::CaptureStdout();
    vss::printCoreVersion();
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_version;
    mock_version << "vss-core: "  << VSS_CORE_MAJOR_VERSION << "." << VSS_CORE_MINOR_VERSION << "." << VSS_CORE_PATCH_VERSION << std::endl;
    EXPECT_STREQ(output.c_str(), mock_version.str().c_str());
}