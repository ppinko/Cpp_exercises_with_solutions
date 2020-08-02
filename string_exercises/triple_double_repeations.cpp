// https://edabit.com/challenge/f5oRvRPnkwMesG977

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <string>
#include <set>

bool trouble(long num1, long num2) {
    std::string str1 = std::to_string(num1);
    std::string str2 = std::to_string(num2);
    if (str1.size() < 3 || str2.size() < 2)
        return false;
    std::set<char> triples {}, doubles {};
    for (int i = 0; i < str1.size() - 2; ++i)
    {
        if (str1.at(i) == str1.at(i+1) && str1.at(i) == str1.at(i+2))
            triples.insert(str1.at(i));
    }
    for (int i = 0; i < str2.size() - 1; ++i)
    {
        if (str2.at(i) == str2.at(i+1))
            doubles.insert(str2.at(i));
    }
    for (auto const &c : triples)
    {
        auto it = doubles.find(c);
        if (it != doubles.end())
            return true;
    }
    return false;
}

int main()
{

    assert((trouble(451999277, 41177722899) == true));
	assert((trouble(444, 44) == true));
	assert((trouble(1222345, 12345) == false));
	assert((trouble(12345, 12345) == false));
	assert((trouble(888, 888) == true));
	assert((trouble(666789, 12345667) == true));
	assert((trouble(10560002, 100) == true));
	assert((trouble(1, 1) == false));
	assert((trouble(9111922229333339, 9559669779) == false));

    return 0;
}