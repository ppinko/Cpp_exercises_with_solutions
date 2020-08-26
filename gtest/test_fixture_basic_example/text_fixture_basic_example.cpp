/*
How to run a gtest without CMakeLists.txt from a command line when gtest and 
tested element are in the same script:

g++ -std=c++14 text_fixture_basic_example.cpp -lgtest -lgtest_main -pthread

where:
	→ g++ // compiler
	→ -std=c++14 // cpp standard
	→ text_fixture_basic_example.cpp // script to compile
	→ -lgtest // link to gtest library
	→ -lgtest_main // link to main gtest library
	→ -pthread // link to pthread library
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

// creating exemplary class “MyClass” as a factory for objects
class MyClass {
    private:
        int baseValue;
    public:
        MyClass(int _bv) : baseValue(_bv) {}
        void Increment(int byValue){
            baseValue += byValue;
        }
        int getValue() {return baseValue;}
};

/*
Creating Test Fixture: 
- as a test fixture we create a class which derives from testing::Test.
- we need to instantiate an object of tested class (in this case “MyClass”)
- function SetUp() - to set up an environment for tests
- function TearDown() - clean-up function
*/

class MyClassTest : public testing::Test {
    public:
        MyClass *mc;
        void SetUp() {cout<<"Alive"<<endl; mc = new MyClass(100);}
        void TearDown() {cout<<"Dead"<<endl; delete mc;}
};

/*
TEST_F(FixtureClassName, SubtestName) – in case of test fixture we use TEST_F(), not TEST(). 
FixtureClassName must be the same as Fixture Object (in this example – “MyClassTest”).
For every test, new object of tested class is constructed and later on destructed.
*/

TEST_F(MyClassTest, Increment_by_5){
    // Act
    mc->Increment(5);
    // Assert
    ASSERT_EQ(mc->getValue(), 105);
}

TEST_F(MyClassTest, Increment_by_10){
    // Act
    mc->Increment(10);
    // Assert
    ASSERT_EQ(mc->getValue(), 110);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}