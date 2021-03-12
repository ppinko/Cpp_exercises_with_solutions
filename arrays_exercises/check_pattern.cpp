// https://edabit.com/challenge/dXjES9gNN3RXgokRq

#include <cassert>
#include <iostream>

#include <vector>

using namespace std;

bool checkPattern(vector<vector<int>> arr, string pattern)
{

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << i << endl;
	}
	do
	{

	} while (/* condition */);
}

int main()
{

	Describe(checkPattern_){
		It(test1){Assert::That(checkPattern({{1, 1}, {2, 2}, {1, 1}, {2, 2}}, "ABAB"), Equals(true));
}
It(test2) { Assert::That(checkPattern({{1, 2}, {1, 2}, {1, 2}, {1, 2}}, "AAAA"), Equals(true)); }
It(test3) { Assert::That(checkPattern({{1, 2}, {1, 3}, {1, 4}, {1, 2}}, "ABCA"), Equals(true)); }
It(test4) { Assert::That(checkPattern({{1, 2, 3}, {1, 2, 3}, {3, 2, 1}, {3, 2, 1}}, "AABB"), Equals(true)); }
It(test5) { Assert::That(checkPattern({{8, 8, 8, 8}, {7, 7, 7, 7}, {6, 6, 6, 6}, {5, 5, 5, 5}}, "ABCD"), Equals(true)); }
It(test6) { Assert::That(checkPattern({{8, 8, 8, 8}, {7, 7, 7, 7}, {6, 6, 6, 6}, {5, 5, 5, 5}}, "DCBA"), Equals(true)); }
It(test7) { Assert::That(checkPattern({{8}, {7}, {6}, {6}}, "ABCC"), Equals(true)); }
It(test8) { Assert::That(checkPattern({{8}, {9}, {9}, {9}}, "ABBB"), Equals(true)); }
It(test9) { Assert::That(checkPattern({{1, 1}, {2, 2}, {1, 1}, {1, 2}}, "ABAB"), Equals(false)); }
It(test10) { Assert::That(checkPattern({{1, 2}, {1, 2}, {2, 2}, {3, 2}}, "AAAA"), Equals(false)); }
It(test11) { Assert::That(checkPattern({{8}, {9}, {9}, {8}}, "ABBB"), Equals(false)); }
It(test12) { Assert::That(checkPattern({{8}, {7}, {6}, {5}}, "ABCC"), Equals(false)); }
It(test13) { Assert::That(checkPattern({{8, 8, 8, 8}, {7, 7, 7, 7}, {6, 6, 6, 6}, {5, 5, 5, 5}}, "DDBA"), Equals(false)); }
It(test14) { Assert::That(checkPattern({{1, 2}, {1, 2}, {1, 2}, {1, 2}}, "AABA"), Equals(false)); }
}
;

return 0;
}