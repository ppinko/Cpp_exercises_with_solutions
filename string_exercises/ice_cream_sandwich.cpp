// https://edabit.com/challenge/GHaTpruxeoNc77Lto

#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <iterator>
#include <set>

using namespace std;

bool isIcecreamSandwich(string str) {
    set<char> letters {};
    for (const auto &c : str)
        letters.insert(c);

    if (letters.size() != 2)
        return false;
    
    int str_length = str.size();
    for (int i = 0; i < str_length; ++i)
    {
        if (str.at(i) != str.at(str_length - i - 1))
            return false;
    }
    return true;
}

int main()
{

    assert((isIcecreamSandwich("AABBBAA") == true));
    assert((isIcecreamSandwich("3&&3") == true));
    assert((isIcecreamSandwich("yyyyymmmmmmmmyyyyy") == true));
    assert((isIcecreamSandwich("hhhhhhhhmhhhhhhhh") == true));
    assert((isIcecreamSandwich("CDC") == true));

    assert((isIcecreamSandwich("BBBBB") == false));

    assert((isIcecreamSandwich("AAACCCAA") == false));

    assert((isIcecreamSandwich("AACDCAA") == false));

    assert((isIcecreamSandwich("AAABB") == false));
    assert((isIcecreamSandwich("AA") == false));
    assert((isIcecreamSandwich("A") == false));
    assert((isIcecreamSandwich("") == false));

    return 0;
}