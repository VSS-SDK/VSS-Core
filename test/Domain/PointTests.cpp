//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/Point.h"

TEST(Point_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Point point;

    EXPECT_EQ(point.x, 0);
    EXPECT_EQ(point.y, 0);
}

TEST(Point_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand();
    float y = rand();

    vss::Point point(x, y);

    EXPECT_EQ(point.x, x);
    EXPECT_EQ(point.y, y);
}