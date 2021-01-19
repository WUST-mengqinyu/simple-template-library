//
// Created by mengqinyu on 2020/12/22.
//

#include "header/header.h"
#include <gtest/gtest.h>
#include <bits/stdc++.h>

stl::uint128 x;

TEST(IfInt128RunCorrect, Correct) {
    // if int128 can be initialize correctly
    x = 1;
//    std::cout << x << std::endl;
    EXPECT_EQ(x, 1);
    x += 5;
    EXPECT_EQ(x, 6);
    x -= 10000000;
    EXPECT_EQ(x, 6 - 10000000);
    x = __LONG_LONG_MAX__;
    EXPECT_EQ(x, __LONG_LONG_MAX__);
    std::cerr << x << std::endl;
    x *= 2;
    std::cerr << x << std::endl;
    x /= 2;
    EXPECT_EQ(x, __LONG_LONG_MAX__);
}
