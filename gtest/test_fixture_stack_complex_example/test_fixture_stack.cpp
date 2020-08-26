/*
to compile:
g++ -std=c++14 test_fixture_stack.cpp -lgtest -lgtest_main -pthread
*/

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Stack {
    private:
        vector<int> vstack = {};
    public:
        void push(int value) {vstack.push_back(value);}
        int pop() {
            if (vstack.size() > 0) {
                int value = vstack.back();
                vstack.pop_back();
                return value;
            } else {
                return -1;
            }
        }
        int size() {return vstack.size();}
};

class stackTest : public testing::Test {
    public:
        Stack s1;
        void SetUp() {
            int value[] = {1,2,3,4,5,6,7,8,9};
            for (auto &val : value) {
                s1.push(val);
            }
        }
        void TearDown(){}
};

TEST_F(stackTest, PopTest) {
    int lastPoppedValue = 9;
    while (lastPoppedValue != 1)
        ASSERT_EQ(s1.pop(), lastPoppedValue--);
}

TEST_F(stackTest, sizeValidityTest) {
    int val = s1.size();
    for (val; val > 0; val--)
        ASSERT_NE(s1.pop(), -1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}