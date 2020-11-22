//
// Created by badcw on 2020/11/21.
//
// check if "header.h" works correctly
// check if gtest works correctly

#include "header/header.h"
#include <gtest/gtest.h>

struct inter_tmp {
    int x;
    bool operator == (const inter_tmp& oth) const {
        return x == oth.x;
    }
};

TEST(IfGoogleTestRun, Correct) {
    // if google test run correctly
    EXPECT_EQ(1, 1);
    // basic int test
    EXPECT_EQ(f(1), 1);
    // double test
    EXPECT_DOUBLE_EQ(f(1.555398223293898932389222293), 1.555398223293898932389222292);
    // struct test
    inter_tmp x{44};
    EXPECT_EQ(f(x), x);
}
