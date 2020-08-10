// https://edabit.com/challenge/oifX6z3a36urd2Z7p

#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

std::vector<int> validateSwaps(std::vector<std::string> arr, std::string s) {
	std::vector<int> answer {};
    for (const auto &str : arr)
    {
        int num_swaps = 0;
        if (str.size() == s.size())
        {
            for (int i = 0; i < s.size(); ++i)
            {
                if (str.at(i) != s.at(i))
                    ++num_swaps;
            }
            if (num_swaps == 0 || num_swaps == 2)
            {
                answer.push_back(1);
                continue;
            }
        }
        answer.push_back(0);
    }
    return answer;
}

int main()
{
	assert((validateSwaps({"BACDE", "EBCDA", "BCDEA", "ACBED"}, "ABCDE") == std::vector<int>({1, 1, 0, 0})));
	assert((validateSwaps({"32145", "12354", "15342", "12543"}, "12345") == std::vector<int>({1, 1, 1, 1})));
	assert((validateSwaps({"9786", "9788", "97865", "7689"}, "9768") == std::vector<int>({1, 0, 0, 0})));
	assert((validateSwaps({"123", "321", "132", "13", "12"}, "213") == std::vector<int>({1, 0, 0, 0, 0})));
	assert((validateSwaps({"123", "1234", "1235"}, "12") == std::vector<int>({0, 0, 0})));
	assert((validateSwaps({"123", "123", "123"}, "133") == std::vector<int>({0, 0, 0})));
	assert((validateSwaps({"132", "321", "213"}, "123") == std::vector<int>({1, 1, 1})));

    return 0;
}