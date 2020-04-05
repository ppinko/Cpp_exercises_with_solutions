#include <gtest/gtest.h>
#include "../fdiv.hpp"	

TEST(FdivTests, firstDiv){
    float x = 5.0;
    float y = 2.5;
    EXPECT_EQ(x/y, float_div(x, y));
}
