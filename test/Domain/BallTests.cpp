//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/Ball.h"

TEST(Ball_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Ball ball;

    EXPECT_EQ(ball.x, 0);
    EXPECT_EQ(ball.y, 0);
    EXPECT_EQ(ball.speedX, 0);
    EXPECT_EQ(ball.speedY, 0);
}

TEST(Ball_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand();
    float y = rand();
    float speedX = rand();
    float speedY = rand();


    vss::Ball ball(x, y, speedX, speedY);

    EXPECT_EQ(ball.x, x);
    EXPECT_EQ(ball.y, y);
    EXPECT_EQ(ball.speedX, speedX);
    EXPECT_EQ(ball.speedY, speedY);
}

TEST(Ball_cout, WhenCoutShouldPrintRight){
    srand(static_cast<unsigned int>(time(NULL)));

    vss::Ball ball(rand(), rand(), rand(), rand());

    testing::internal::CaptureStdout();
    std::cout << ball;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << "Ball(" << ball.x << ", " << ball.y << ", " << ball.speedX << ", " << ball.speedY  << ")";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}