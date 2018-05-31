//
// Created by johnathan on 31/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/Debug.h>
#include <Helpers/DomainRandomizer.h>

TEST(Debug_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Debug debug;

    EXPECT_EQ(debug.stepPoints.size(), (unsigned int)0);
    EXPECT_EQ(debug.finalPoses.size(), (unsigned int)0);
    EXPECT_EQ(debug.paths.size(), (unsigned int)0);
}

TEST(Debug_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    unsigned int robotsAmount = rand()%10;

    std::vector<vss::Point> stepPoints;
    std::vector<vss::Pose> finalPoses;
    std::vector<vss::Path> paths;

    for(unsigned int i = 0 ; i < robotsAmount ; i++){
        stepPoints.push_back(vss::DomainRandomizer::createRandomPoint());
        finalPoses.push_back(vss::DomainRandomizer::createRandomPose());
        paths.push_back(vss::DomainRandomizer::createRandomPath());
    }

    vss::Debug debug(stepPoints, finalPoses, paths);

    EXPECT_EQ(debug.stepPoints.size(), stepPoints.size());
    EXPECT_EQ(debug.finalPoses.size(), finalPoses.size());
    EXPECT_EQ(debug.paths.size(), paths.size());

    for(unsigned int i = 0 ; i < robotsAmount ; i++){
        EXPECT_EQ(debug.stepPoints[i].x, stepPoints[i].x);
        EXPECT_EQ(debug.stepPoints[i].y, stepPoints[i].y);

        EXPECT_EQ(debug.finalPoses[i].x, finalPoses[i].x);
        EXPECT_EQ(debug.finalPoses[i].y, finalPoses[i].y);
        EXPECT_EQ(debug.finalPoses[i].angle, finalPoses[i].angle);

        EXPECT_EQ(debug.paths[i].points.size(), paths[i].points.size());

        for(unsigned int j = 0 ; j < debug.paths[i].points.size() ; j++){
            EXPECT_EQ(debug.paths[i].points[j].x, paths[i].points[j].x);
            EXPECT_EQ(debug.paths[i].points[j].y, paths[i].points[j].y);
        }
    }
}