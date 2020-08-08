// https://edabit.com/challenge/dmTWccZAo2QSr3yFR

#include <cassert>
#include <iostream>

#include <vector>
#include <sstream>
#include <climits>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <string>
#include <set>

bool isPandigital(double num) {
	std::set<int> s {};
    int64_t n = static_cast<int64_t>(num);
    while (n != 0)
    {
        s.insert(n % 10);
        n /= 10;
    }
    return (s.size() == 10);
}

int main()
{
    assert((isPandigital(84847473937) == false));
	assert((isPandigital(546732965015) == false));
	assert((isPandigital(6781235184590) == true));
	assert((isPandigital(9432821089765) == true));
	assert((isPandigital(629764) == false));
	assert((isPandigital(90864523148909) == false));
	assert((isPandigital(7296012) == false));
	assert((isPandigital(647380265483206) == false));
	assert((isPandigital(38165975424790) == true));
	assert((isPandigital(8146327815320) == false));
	assert((isPandigital(768431605430) == false));
	assert((isPandigital(4920124852367763) == true));
	assert((isPandigital(60543981597247) == true));
	assert((isPandigital(10282343456789) == true));

    return 0;
}