//
// Created by johnathan on 31/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include <Helpers/Math.h>

TEST(Math_distance, ShouldCalcDistanceBetweenPoints){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto point_2 = vss::Point(0, 0);

    auto distance = vss::Math::distance(point_1, point_2);

    EXPECT_EQ(distance, r);
}

TEST(Math_distance, ShouldCalcDistanceBetweenPointAndPose){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto pose_1 = vss::Pose(0, 0, 0);

    auto distance = vss::Math::distance(point_1, pose_1);

    EXPECT_EQ(distance, r);
}

TEST(Math_distance, ShouldCalcDistanceBetweenPointAndBall){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto ball_1 = vss::Ball(0, 0, 0, 0);

    auto distance = vss::Math::distance(point_1, ball_1);

    EXPECT_EQ(distance, r);
}

TEST(Math_distance, ShouldCalcDistanceBetweenPointAndRobot){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto robot_1 = vss::Robot(0, 0, 0, 0, 0, 0);

    auto distance = vss::Math::distance(point_1, robot_1);

    EXPECT_EQ(distance, r);
}