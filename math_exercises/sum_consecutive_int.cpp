// https://edabit.com/challenge/XHPgAgTbaLzdRNTec

#include <cassert>
#include <iostream>

#include <vector>
#include <sstream>
#include <climits>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <string>

std::vector<int> sumConsecutives(std::vector<int> arr) {
	std::vector<int> answer {};
    int temp = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        temp += arr.at(i);
        if (i == arr.size() - 1)
        {
            answer.push_back(temp);
        }
        else
        {
            if (arr.at(i) == arr.at(i+1))
                continue;
            else
            {
                answer.push_back(temp);
                temp = 0;
            }
        }
    }
    return answer;
}

int main()
{
	assert((sumConsecutives({0, 7, 7, 7, 5, 4, 9, 9, 0}) == std::vector<int>({0, 21, 5, 4, 18, 0})));
	assert((sumConsecutives({4, 4, 5, 6, 8, 8, 8}) == std::vector<int>({8, 5, 6, 24})));
	assert((sumConsecutives({-5, -5, 7, 7, 12, 0}) == std::vector<int>({-10, 14, 12, 0})));
	assert((sumConsecutives({2, 2, 2, 2, 2, 7}) == std::vector<int>({10, 7})));
	assert((sumConsecutives({2, 2, -4, 4, 5, 5, 6, 6, 6, 6, 6, 1}) == std::vector<int>({4, -4, 4, 10, 30, 1})));
	assert((sumConsecutives({3, 3, 3, 3, 1}) == std::vector<int>({12, 1})));
	assert((sumConsecutives({1, -1, -2, 2, 3, -3, 4, -4}) == std::vector<int>({1, -1, -2, 2, 3, -3, 4, -4})));

    return 0;
}