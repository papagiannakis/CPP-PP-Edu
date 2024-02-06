
//
// This is unit tests file 
// for the example code from Chapter 5.6.1 "Bad arguments" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// Copyright 2021, University of Crete, Course HY150




// you need to do: "git clone git@github.com:google/googletest.git"
// so that you get the googletest project in this folder
// which is build also via cmake
#include <gtest/gtest.h>
#include "chapter5.6.1.h"

TEST(chapter5, area)
{
    GTEST_ASSERT_EQ(area(5,5), 25);
}

TEST(chapter5two, area)
{
    GTEST_ASSERT_EQ(area(10,20), 200);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}