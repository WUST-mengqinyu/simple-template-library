//
// Created by mengqinyu on 2020/12/22.
//

#include "header/header.h"
#include <gtest/gtest.h>

stl::int128 x;

TEST(IfInt128RunCorrect, Correct) {
    // if int128 can be initialize correctly
    x = 1;
    EXPECT_EQ(x, 1);
}
