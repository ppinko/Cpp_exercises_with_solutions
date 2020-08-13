#include "double_palindrome.cpp"
#include <gtest/gtest.h>

TEST(DoublePalindromeBase, ShortWords)
{
	ASSERT_EQ(palindromeSet({"7a", "5f", "6c"}), std::vector<int>({2, 2, 2}));
	ASSERT_EQ(palindromeSet({"7ab", "5fc", "6cd"}), std::vector<int>({1, 1, 1}));
}

TEST(DoublePalindromeSpecialCases, EmptyVector)
{
    ASSERT_EQ(palindromeSet({""}), std::vector<int>({0}));
}

TEST(DoublePalindromeBase, NoPalindromes)
{
    ASSERT_EQ(palindromeSet({"87ab", "15fc", "26cd"}), std::vector<int>({0, 0, 0}));
}

TEST(DoublePalindromeSpecialCases, FailingExamples)
{
    EXPECT_EQ(palindromeSet({"1234ab", "144a441"}), std::vector<int>({1, 1})) << "This should be wrong!!!";
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}