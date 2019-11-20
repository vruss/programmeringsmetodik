//
// Created by julia on 2019-11-20.
//

#include "gtest/gtest.h"


class Tests : public ::testing::Test
{

};

TEST(Tests, TestName)
{
    EXPECT_EQ("", "");
}
