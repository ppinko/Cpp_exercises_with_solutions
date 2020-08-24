#include "rearrange_numbers.cpp"
#include <gtest/gtest.h>

TEST(RearrangeNumbersTests, FirstTests) {
    ASSERT_EQ(rearranged_difference(100), 99);
}

TEST(RearrangeNumbersTests, EdabitTests) {
	ASSERT_EQ(rearranged_difference(9092564), 9719721);
	ASSERT_EQ(rearranged_difference(1308821), 8719722);
	ASSERT_EQ(rearranged_difference(8386568), 5319765);
	ASSERT_EQ(rearranged_difference(7794084), 9429651);
	ASSERT_EQ(rearranged_difference(6366093), 9329661);
	ASSERT_EQ(rearranged_difference(7863060), 8729622);
	ASSERT_EQ(rearranged_difference(3368327), 6429654);
	ASSERT_EQ(rearranged_difference(7218787), 7599933);
	ASSERT_EQ(rearranged_difference(7723188), 7639533);
	ASSERT_EQ(rearranged_difference(8816317), 7739523);
	ASSERT_EQ(rearranged_difference(8824349), 7539543);
	ASSERT_EQ(rearranged_difference(3320707), 7709823);
	ASSERT_EQ(rearranged_difference(1695488), 8429652);
	ASSERT_EQ(rearranged_difference(2120034), 4309866);
	ASSERT_EQ(rearranged_difference(5300586), 8619732);
	ASSERT_EQ(rearranged_difference(3538814), 7519743);
	ASSERT_EQ(rearranged_difference(1336939), 8629632);
	ASSERT_EQ(rearranged_difference(6290200), 9619731);
	ASSERT_EQ(rearranged_difference(5268866), 6299964);
	ASSERT_EQ(rearranged_difference(5155458), 7099983);
};

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}