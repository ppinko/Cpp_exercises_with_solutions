// https://edabit.com/challenge/Aphy89fubdP3oPrJB

#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

std::string incrementString(std::string str) {
    auto it = std::find_if(str.rbegin(), str.rend(), [](char c){return (!std::isdigit(c));});
    if (it == str.rbegin())
    {
        str.push_back('1');
        return str;
    }
    else 
    {
        int num_digits = it - str.rbegin();
        int digits = std::stoi(str.substr(str.size() - num_digits, num_digits)) + 1;
        std::string new_digits = std::to_string(digits);
        std::string answer = str.substr(0, str.size() - num_digits);
        if (new_digits.size() < num_digits)
            {
                std::string temp (num_digits - new_digits.size(), '0');
                answer.append(temp);
            }
        answer.append(new_digits);
        return answer;
    }
}

int main()
{

    // std::string str1 = "abcdef123";
    // // std::string str1 = "abcdef";
    // incrementString(str1);

    assert((incrementString("foo") == "foo1"));
	assert((incrementString("foobar01002") == "foobar01003"));
	assert((incrementString("foobar00599") == "foobar00600"));
	assert((incrementString("foo099") == "foo100"));
	assert((incrementString("foo09999") == "foo10000"));

    return 0;
}