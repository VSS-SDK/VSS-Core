//
// Created by johnathan on 27/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/State.h"
#include "Domain/Robot.h"
#include "Domain/Ball.h"
#include "Helpers/CoordinateTransformer.h"

vss::Ball createRandomBall();
vss::Robot createRandomRobot();
vss::State createRandomState();
float getRightAngleTransformationInFlip(float angle);

TEST(CoordinateTransaformer_Spin180Degrees_Ball, WhenSpin_ShouldReturnTheRightTransformation){
    srand(static_cast<unsigned int>(time(NULL)));

    auto ball = createRandomBall();
    auto ballInFieldSpinned = vss::CoordinateTransformer::spin180Degrees(ball);

    EXPECT_EQ(ballInFieldSpinned.x, 170 - ball.x);
    EXPECT_EQ(ballInFieldSpinned.y, 130 - ball.y);
    EXPECT_GT(ballInFieldSpinned.x, -1);
    EXPECT_GT(ballInFieldSpinned.y, -1);
    EXPECT_LT(ballInFieldSpinned.x, 171);
    EXPECT_LT(ballInFieldSpinned.y, 131);
}

TEST(CoordinateTransaformer_Spin180Degrees_Robot, WhenSpin_ShouldReturnTheRightTransformation){
    srand(static_cast<unsigned int>(time(NULL)));

    auto robot = createRandomRobot();
    auto robotInFieldSpinned = vss::CoordinateTransformer::spin180Degrees(robot);
    auto rightAngle = getRightAngleTransformationInFlip(robot.angle);

    EXPECT_EQ(robotInFieldSpinned.x, 170 - robot.x);
    EXPECT_EQ(robotInFieldSpinned.y, 130 - robot.y);
    EXPECT_EQ(robotInFieldSpinned.angle, rightAngle);
    EXPECT_GT(robotInFieldSpinned.x, -1);
    EXPECT_GT(robotInFieldSpinned.y, -1);
    EXPECT_GT(robotInFieldSpinned.angle, -1);
    EXPECT_LT(robotInFieldSpinned.x, 171);
    EXPECT_LT(robotInFieldSpinned.y, 131);
    EXPECT_LT(robotInFieldSpinned.angle, 361);
}

TEST(CoordinateTransaformer_Spin180Degrees_State, WhenSpin_ShouldReturnTheRightTransformation){
    srand(static_cast<unsigned int>(time(NULL)));

    vss::State state = createRandomState();
    vss::State stateInFieldSpinned = vss::CoordinateTransformer::spinField180Degrees(state);

    EXPECT_EQ(stateInFieldSpinned.teamBlue.size(), (unsigned int)4);
    EXPECT_EQ(stateInFieldSpinned.teamYellow.size(), (unsigned int)3);

    EXPECT_EQ(stateInFieldSpinned.teamBlue.size(), state.teamBlue.size());
    EXPECT_EQ(stateInFieldSpinned.teamYellow.size(), state.teamYellow.size());

    EXPECT_EQ(stateInFieldSpinned.ball.x, 170 - state.ball.x);
    EXPECT_EQ(stateInFieldSpinned.ball.y, 130 - state.ball.y);
    EXPECT_GT(stateInFieldSpinned.ball.x, -1);
    EXPECT_GT(stateInFieldSpinned.ball.y, -1);
    EXPECT_LT(stateInFieldSpinned.ball.x, 171);
    EXPECT_LT(stateInFieldSpinned.ball.y, 131);

    for(unsigned int i = 0 ; i < stateInFieldSpinned.teamYellow.size() ; i++){
        auto rightAngle = getRightAngleTransformationInFlip(state.teamYellow[i].angle);

        EXPECT_EQ(stateInFieldSpinned.teamYellow[i].x, 170 - state.teamYellow[i].x);
        EXPECT_EQ(stateInFieldSpinned.teamYellow[i].y, 130 - state.teamYellow[i].y);
        EXPECT_EQ(stateInFieldSpinned.teamYellow[i].angle, rightAngle);
        EXPECT_GT(stateInFieldSpinned.teamYellow[i].x, -1);
        EXPECT_GT(stateInFieldSpinned.teamYellow[i].y, -1);
        EXPECT_GT(stateInFieldSpinned.teamYellow[i].angle, -1);
        EXPECT_LT(stateInFieldSpinned.teamYellow[i].x, 171);
        EXPECT_LT(stateInFieldSpinned.teamYellow[i].y, 131);
        EXPECT_LT(stateInFieldSpinned.teamYellow[i].angle, 361);
    }

    for(unsigned int i = 0 ; i < stateInFieldSpinned.teamBlue.size() ; i++){
        auto rightAngle = getRightAngleTransformationInFlip(state.teamBlue[i].angle);

        EXPECT_EQ(stateInFieldSpinned.teamBlue[i].x, 170 - state.teamBlue[i].x);
        EXPECT_EQ(stateInFieldSpinned.teamBlue[i].y, 130 - state.teamBlue[i].y);
        EXPECT_EQ(stateInFieldSpinned.teamBlue[i].angle, rightAngle);
        EXPECT_GT(stateInFieldSpinned.teamBlue[i].x, -1);
        EXPECT_GT(stateInFieldSpinned.teamBlue[i].y, -1);
        EXPECT_GT(stateInFieldSpinned.teamBlue[i].angle, -1);
        EXPECT_LT(stateInFieldSpinned.teamBlue[i].x, 171);
        EXPECT_LT(stateInFieldSpinned.teamBlue[i].y, 131);
        EXPECT_LT(stateInFieldSpinned.teamBlue[i].angle, 361);
    }
}

vss::Ball createRandomBall() {
    srand(static_cast<unsigned int>(time(NULL)));

    vss::Ball ball;
    ball.x = rand()%170;
    ball.y = rand()%130;

    return ball;
}

vss::Robot createRandomRobot() {
    srand(static_cast<unsigned int>(time(NULL)));

    vss::Robot robot;
    robot.x = rand()%170;
    robot.y = rand()%130;
    robot.angle = rand()%360;

    return robot;
}

vss::State createRandomState(){
    vss::State state;

    state.ball = createRandomBall();

    for(unsigned int i = 0 ; i < 3 ; i++){
        state.teamBlue[i] = createRandomRobot();
        state.teamYellow[i] = createRandomRobot();
    }

    return state;
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