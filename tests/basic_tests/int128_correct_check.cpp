//
// Created by mengqinyu on 2020/12/22.
//

#include "header/header.h"
#include <gtest/gtest.h>
#include <bits/stdc++.h>

stl::uint128 x, y;

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
    y = x;
    y += 100;
    x += 100;
    EXPECT_EQ(y, x);
    EXPECT_EQ(x, y);
}

TEST(IfInt128CalCorrect, Correct) {
    x = 1000;
    y = 1000;
    std::cerr << x * y << std::endl;
}