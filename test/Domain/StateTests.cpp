//
// Created by johnathan on 31/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/State.h>

TEST(State_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::State state;

    EXPECT_EQ(state.ball.x, 0);
    EXPECT_EQ(state.ball.y, 0);
    EXPECT_EQ(state.ball.speedX, 0);
    EXPECT_EQ(state.ball.speedY, 0);
    EXPECT_EQ(state.teamYellow.size(), (unsigned int)0);
    EXPECT_EQ(state.teamBlue.size(), (unsigned int)0);
}

