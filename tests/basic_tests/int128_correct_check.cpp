//
// Created by mengqinyu on 2020/12/22.
//

#include "header/header.h"
#include <gtest/gtest.h>
#include <bits/stdc++.h>

stl::int128 zero_x;
stl::uint128 zero_ux;

TEST(Int128Construct, Correct) {
    // empty heap
    EXPECT_EQ(zero_x, 0);
    // empty stack
    stl::int128 x;
    EXPECT_NE(x, 0);
    // easy
    stl::int128 xx = 1;
    EXPECT_EQ(xx, 1);
    // list
    stl::int128 xxx = {1};
    EXPECT_EQ(xxx, 1);
    // copy
    stl::int128 xxxx = xx;
    EXPECT_EQ(xxxx, 1);
    // - int
    stl::int128 xxxxx = -100;
    EXPECT_EQ(xxxxx, -100);
}

TEST(Uint128Construct, Correct) {
    // empty heap
    EXPECT_EQ(zero_ux, 0);
    // empty stack
    stl::uint128 x;
    EXPECT_NE(x, 0);
    // easy
    stl::uint128 xx = 1;
    EXPECT_EQ(xx, 1);
    // list
    stl::uint128 xxx = {1};
    EXPECT_EQ(xxx, 1);
    // copy
    stl::uint128 xxxx = xx;
    EXPECT_EQ(xxxx, 1);
}

TEST(Int128Calculator, Correct) {
    stl::int128 x = 1, y = 1, z;
    z = x + y;
    EXPECT_EQ(z, 2);
    z += x;
    EXPECT_EQ(z, 3);
    x = z;
    EXPECT_EQ(x, 3);
    z = x * z;
    EXPECT_EQ(z, 9);
    y = z; // 9
    z = y * x;
    EXPECT_EQ(z, 27);
    z = stl::int128(100) % stl::int128(7);
    EXPECT_EQ(z, 100 % 7);
    z = y / x;
    EXPECT_EQ(z, 3);
    z = stl::int128(100) / stl::int128 (7);
    EXPECT_EQ(z, 100 / 7);
    z = stl::int128(8) % 2;
    EXPECT_EQ(z, 0);
    z = stl::int128(1487781455) % stl::int128(5);
    EXPECT_EQ(z, 0);
    z = stl::int128(-100) % stl::int128(3);
    EXPECT_EQ(z, -1);
}

TEST(Int128BitCalculator, Correct) {
    stl::int128 x, y;
    x = 0x7; // 111
    y = 0x7;
    EXPECT_EQ(x ^ y, 0);
    x = 0x7; // 111
    y = 0x6; // 110
    EXPECT_EQ(x ^ y, 1);
}