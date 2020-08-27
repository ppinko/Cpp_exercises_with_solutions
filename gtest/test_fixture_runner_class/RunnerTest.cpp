#include "Runner.h"
#include "Runner.cpp"
#include <gtest/gtest.h>

class RunnerTest : public testing::Test {
    public:
        Runner runner1 {"Pawel", 10000, 50};
        void SetUp() {}
        void TearDown() {}
};

TEST_F(RunnerTest, TempoTest) {
    double tempo = 5.0;
    ASSERT_DOUBLE_EQ(runner1.get_tempo(), tempo);
}

TEST_F(RunnerTest, NewDistance) {
    long value = 5000;
    runner1.setNewDistance(value);
    ASSERT_EQ(runner1.getDistance(), value);
}

TEST_F(RunnerTest, NewTempo) {
    long value = 5000;
    double tempo = 10.0;
    runner1.setNewDistance(value);
    ASSERT_DOUBLE_EQ(runner1.get_tempo(), tempo);
}


// TEST_F(RunnerTest, TestShouldFail) {
//     long value = 7000;
//     double tempo = 10.0;
//     runner1.setNewDistance(value);
//     ASSERT_DOUBLE_EQ(runner1.get_tempo(), tempo) << "This test should fail";
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}