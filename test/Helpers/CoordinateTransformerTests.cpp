//
// Created by johnathan on 27/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include <Constants.h>
#include "Helpers/CoordinateTransformer.h"

float getRightAngleTransformationInFlip(float angle);

TEST(CoordinateTransaformer_Spin180Degrees_Ball, WhenSpin_ShouldReturnTheRightTransformation){
    srand(static_cast<unsigned int>(time(NULL)));

    auto ball = vss::DomainRandomizer::createRandomBall();
    auto ballInFieldSpinned = vss::CoordinateTransformer::spin180Degrees(ball);

    EXPECT_EQ(ballInFieldSpinned.x, vss::MAX_COORDINATE_X - ball.x);
    EXPECT_EQ(ballInFieldSpinned.y, vss::MAX_COORDINATE_Y - ball.y);
    EXPECT_GT(ballInFieldSpinned.x, vss::MIN_COORDINATE_X - 1);
    EXPECT_GT(ballInFieldSpinned.y, vss::MIN_COORDINATE_Y - 1);
    EXPECT_LT(ballInFieldSpinned.x, vss::MAX_COORDINATE_X + 1);
    EXPECT_LT(ballInFieldSpinned.y, vss::MAX_COORDINATE_Y + 1);
}

TEST(CoordinateTransaformer_Spin180Degrees_Robot, WhenSpin_ShouldReturnTheRightTransformation){
    srand(static_cast<unsigned int>(time(NULL)));

    auto robot = vss::DomainRandomizer::createRandomRobot();
    auto robotInFieldSpinned = vss::CoordinateTransformer::spin180Degrees(robot);
    auto rightAngle = getRightAngleTransformationInFlip(robot.angle);

    EXPECT_EQ(robotInFieldSpinned.x, vss::MAX_COORDINATE_X - robot.x);
    EXPECT_EQ(robotInFieldSpinned.y, vss::MAX_COORDINATE_Y - robot.y);
    EXPECT_EQ(robotInFieldSpinned.angle, rightAngle);
    EXPECT_GT(robotInFieldSpinned.x, vss::MIN_COORDINATE_X - 1);
    EXPECT_GT(robotInFieldSpinned.y, vss::MIN_COORDINATE_Y - 1);
    EXPECT_GT(robotInFieldSpinned.angle, vss::MIN_ANGLE_VALUE - 1);
    EXPECT_LT(robotInFieldSpinned.x, vss::MAX_COORDINATE_X + 1);
    EXPECT_LT(robotInFieldSpinned.y, vss::MAX_COORDINATE_Y + 1);
    EXPECT_LT(robotInFieldSpinned.angle, vss::MAX_ANGLE_VALUE + 1);
}

TEST(CoordinateTransaformer_Spin180Degrees_State, WhenSpin_ShouldReturnTheRightTransformation){
    srand(static_cast<unsigned int>(time(NULL)));

    vss::State state = vss::DomainRandomizer::createRandomState();
    vss::State stateInFieldSpinned = vss::CoordinateTransformer::spinField180Degrees(state);

    EXPECT_EQ(stateInFieldSpinned.teamBlue.size(), state.teamBlue.size());
    EXPECT_EQ(stateInFieldSpinned.teamYellow.size(), state.teamYellow.size());

    EXPECT_EQ(stateInFieldSpinned.ball.x, vss::MAX_COORDINATE_X - state.ball.x);
    EXPECT_EQ(stateInFieldSpinned.ball.y, vss::MAX_COORDINATE_Y - state.ball.y);
    EXPECT_GT(stateInFieldSpinned.ball.x, vss::MIN_COORDINATE_X - 1);
    EXPECT_GT(stateInFieldSpinned.ball.y, vss::MIN_COORDINATE_Y - 1);
    EXPECT_LT(stateInFieldSpinned.ball.x, vss::MAX_COORDINATE_X + 1);
    EXPECT_LT(stateInFieldSpinned.ball.y, vss::MAX_COORDINATE_Y + 1);

    for(unsigned int i = 0 ; i < stateInFieldSpinned.teamYellow.size() ; i++){
        auto rightAngle = getRightAngleTransformationInFlip(state.teamYellow[i].angle);

        EXPECT_EQ(stateInFieldSpinned.teamYellow[i].x, vss::MAX_COORDINATE_X - state.teamYellow[i].x);
        EXPECT_EQ(stateInFieldSpinned.teamYellow[i].y, vss::MAX_COORDINATE_Y - state.teamYellow[i].y);
        EXPECT_EQ(stateInFieldSpinned.teamYellow[i].angle, rightAngle);
        EXPECT_GT(stateInFieldSpinned.teamYellow[i].x, vss::MIN_COORDINATE_X - 1);
        EXPECT_GT(stateInFieldSpinned.teamYellow[i].y, vss::MIN_COORDINATE_Y - 1);
        EXPECT_GT(stateInFieldSpinned.teamYellow[i].angle, vss::MIN_ANGLE_VALUE - 1);
        EXPECT_LT(stateInFieldSpinned.teamYellow[i].x, vss::MAX_COORDINATE_X + 1);
        EXPECT_LT(stateInFieldSpinned.teamYellow[i].y, vss::MAX_COORDINATE_Y + 1);
        EXPECT_LT(stateInFieldSpinned.teamYellow[i].angle, vss::MAX_ANGLE_VALUE + 1);
    }

    for(unsigned int i = 0 ; i < stateInFieldSpinned.teamBlue.size() ; i++){
        auto rightAngle = getRightAngleTransformationInFlip(state.teamBlue[i].angle);

        EXPECT_EQ(stateInFieldSpinned.teamBlue[i].x, vss::MAX_COORDINATE_X - state.teamBlue[i].x);
        EXPECT_EQ(stateInFieldSpinned.teamBlue[i].y, vss::MAX_COORDINATE_Y - state.teamBlue[i].y);
        EXPECT_EQ(stateInFieldSpinned.teamBlue[i].angle, rightAngle);
        EXPECT_GT(stateInFieldSpinned.teamBlue[i].x, vss::MIN_COORDINATE_X - 1);
        EXPECT_GT(stateInFieldSpinned.teamBlue[i].y, vss::MIN_COORDINATE_Y - 1);
        EXPECT_GT(stateInFieldSpinned.teamBlue[i].angle, vss::MIN_ANGLE_VALUE - 1);
        EXPECT_LT(stateInFieldSpinned.teamBlue[i].x, vss::MAX_COORDINATE_X + 1);
        EXPECT_LT(stateInFieldSpinned.teamBlue[i].y, vss::MAX_COORDINATE_Y + 1);
        EXPECT_LT(stateInFieldSpinned.teamBlue[i].angle, vss::MAX_ANGLE_VALUE + 1);
    }
}

float getRightAngleTransformationInFlip(float angle){
    float rightAngle;

    if (angle + 180 > 360){
        rightAngle = angle - 180;
    } else {
        rightAngle = angle + 180;
    }

    return rightAngle;
}