#include "square_triangle.cpp"
#include <gtest/gtest.h>

TEST(SquareTriangleTest, RightTriangles)
{
    ASSERT_EQ(true, isSquareTriangle(3, 4, 5));
    ASSERT_EQ(true, isSquareTriangle(12, 13, 5));
}

TEST(SquareTriangleTest, NotRightTriangles)
{
    ASSERT_NE(true, isSquareTriangle(3, 6, 5));
    ASSERT_NE(true, isSquareTriangle(12, 13, 10));
}

TEST(SquareTriangleTest, CustomMsgs)
{
    ASSERT_EQ(true, isSquareTriangle(1, 1, 2)) << "That cannot be true!";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}