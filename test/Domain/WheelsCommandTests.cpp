//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/WheelsCommand.h"

TEST(WheelsCommand_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::WheelsCommand wheelsCommand;

    EXPECT_EQ(wheelsCommand.id, 0);
    EXPECT_EQ(wheelsCommand.leftVel, 0);
    EXPECT_EQ(wheelsCommand.rightVel, 0);
}

TEST(WheelsCommand_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    int id = rand();
    float leftVel = rand();
    float rightVel = rand();

    vss::WheelsCommand wheelsCommand(id, leftVel, rightVel);

    EXPECT_EQ(wheelsCommand.id, id);
    EXPECT_EQ(wheelsCommand.leftVel, leftVel);
    EXPECT_EQ(wheelsCommand.rightVel, rightVel);
}