#include "../gtest_guide.hpp"

#include <gtest/gtest.h>


bool f() {
    return true;
}

TEST(ExampleTests, DemonstrateGTestMacros){
    EXPECT_TRUE(true);
    const bool result = f();
    EXPECT_EQ(true, result) << "Hello world!";
}

TEST(ExampleTests, MAC) {
    int x = 42;
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + x * y;
    EXPECT_EQ(
        expectedNewSum,
        MAC(x, y, sum)
    );
    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}

TEST(ExampleTests, Square){
    int x = 5;
    int expectedSquare = x * x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}