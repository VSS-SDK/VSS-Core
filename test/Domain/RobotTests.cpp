//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/Robot.h"

TEST(Robot_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Robot robot;

    EXPECT_EQ(robot.x, 0);
    EXPECT_EQ(robot.y, 0);
    EXPECT_EQ(robot.angle, 0);
    EXPECT_EQ(robot.speedX, 0);
    EXPECT_EQ(robot.speedY, 0);
    EXPECT_EQ(robot.speedAngle, 0);
}

TEST(Robot_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand();
    float y = rand();
    float angle = rand();
    float speedX = rand();
    float speedY = rand();
    float speedAngle = rand();


    vss::Robot robot(x, y, angle, speedX, speedY, speedAngle);

    EXPECT_EQ(robot.x, x);
    EXPECT_EQ(robot.y, y);
    EXPECT_EQ(robot.angle, angle);
    EXPECT_EQ(robot.speedX, speedX);
    EXPECT_EQ(robot.speedY, speedY);
    EXPECT_EQ(robot.speedAngle, speedAngle);
}