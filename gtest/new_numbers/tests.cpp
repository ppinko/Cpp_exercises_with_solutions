#include "new_numbers.cpp"
#include <gtest/gtest.h>

TEST(NewNumberTests, InitialTests) {
    ASSERT_TRUE(isNew(12));
}

TEST(NewNumberTests, EdabitTests) {
    ASSERT_TRUE(isNew(0));
	ASSERT_TRUE(isNew(90));
	ASSERT_FALSE(isNew(601));
	ASSERT_TRUE(isNew(123));
	ASSERT_FALSE(isNew(321));
	ASSERT_TRUE(isNew(40567));
	ASSERT_FALSE(isNew(10783));
	ASSERT_TRUE(isNew(4444));
	ASSERT_TRUE(isNew(102));
	ASSERT_TRUE(isNew(30004));
	ASSERT_FALSE(isNew(40003));
	ASSERT_FALSE(isNew(125609));
	ASSERT_FALSE(isNew(23401));
};

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}