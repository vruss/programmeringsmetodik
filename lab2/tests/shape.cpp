//
// Created by julia on 2019-11-20.
//

#include "gtest/gtest.h"
#include "../circle.h"

class Tests : public ::testing::Test
{
public:


     void SetUp()
    {
//        c = circle(text);
    }

     void TearDown()
    {

    }

    char text[4] = "Red";
    circle c = circle(text, 3);
};

TEST_F(Tests, get_colour)
{
    EXPECT_EQ(c.get_colour(), text);
}
