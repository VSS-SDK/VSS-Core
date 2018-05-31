//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/Pose.h"

TEST(Pose_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Pose pose;

    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 0);
    EXPECT_EQ(pose.angle, 0);
}

TEST(Pose_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand();
    float y = rand();
    float angle = rand();

    vss::Pose pose(x, y, angle);

    EXPECT_EQ(pose.x, x);
    EXPECT_EQ(pose.y, y);
    EXPECT_EQ(pose.angle, angle);
}