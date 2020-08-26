#include "multiplicity_numbers.cpp"
#include <gtest/gtest.h>

TEST(MultiplicityNumbersTests, InitialTests) {
    ASSERT_EQ(multiplicity({1, 1, 1, 1, 1}), std::vector<std::vector<int>>({{1, 5}}));
}

TEST(MultiplicityNumbersTests, EdabitTests) {
	ASSERT_EQ(multiplicity({1, 1, 1, 2, 2, 3}), std::vector<std::vector<int>>({{1, 3}, {2, 2}, {3, 1}}));
	ASSERT_EQ(multiplicity({1, 1, 1, 1, 1}), std::vector<std::vector<int>>({{1, 5}}));
	ASSERT_EQ(multiplicity({1, 5, 4, 3, 2}), std::vector<std::vector<int>>({{1, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}}));
	ASSERT_EQ(multiplicity({5, 5, 5, 5, 8}), std::vector<std::vector<int>>({{5, 4}, {8, 1}}));
	ASSERT_EQ(multiplicity({3, 3, 3, 0}), std::vector<std::vector<int>>({{3, 3}, {0, 1}}));
	ASSERT_EQ(multiplicity({1, 1, 2, 2, 3, 3, 4, 4}), std::vector<std::vector<int>>({{1, 2}, {2, 2}, {3, 2}, {4, 2}}));
	ASSERT_EQ(multiplicity({4, 4, 3, 3, 2, 2, 1, 1}), std::vector<std::vector<int>>({{4, 2}, {3, 2}, {2, 2}, {1, 2}}));
};

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}