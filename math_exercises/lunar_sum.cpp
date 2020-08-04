// https://edabit.com/challenge/GBmwGCwP3GfDKfqY2

#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <cmath>

int lunarSum(int number1, int number2) {
    int answer = 0, index = 0;
    int min_num = std::min(number1, number2);
    int max_num = std::max(number1, number2);
    while (max_num != 0)
    {
        answer += std::pow(10, index) * std::max(min_num % 10, max_num % 10);
        ++index;
        min_num /= 10;
        max_num /= 10;
    }
    return answer;
}

int main()
{
    assert((lunarSum(246, 317) == 347));
	assert((lunarSum(134, 54) == 154));
	assert((lunarSum(20, 140) == 140));
	assert((lunarSum(1, 1) == 1));
	assert((lunarSum(198, 44) == 198));
	assert((lunarSum(36602, 696) == 36696));
	assert((lunarSum(91, 8823) == 8893));
	assert((lunarSum(123, 8) == 128));
	assert((lunarSum(2289, 98211285) == 98212289));
	assert((lunarSum(9, 11) == 19));
	assert((lunarSum(11, 22) == 22));

    return 0;
}