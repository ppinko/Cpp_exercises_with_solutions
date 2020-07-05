// https://edabit.com/challenge/Ne2HsL4ENEhnMiFJR

#include <string>
#include <cassert>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

std::string sorting(std::string str) {
    
    std::string letters {}, digits {};
    for (char& c: str){
        if (std::isalpha(c)) letters.push_back(c);
        else digits.push_back(c);
    }

    struct {
        bool operator()(char a, char b) const
        {
            if (std::tolower(a) == std::tolower(b))
                return a > b;
            else
                return std::tolower(a) < std::tolower(b);
        }
    } lettersLess;

	std::sort(letters.begin(), letters.end(), lettersLess);
    std::sort(digits.begin(), digits.end());
    letters.append(digits);
    return letters;
}

int main(){
    // std::cout << sorting("eA2a1E") << std::endl;
    assert((sorting("eA2a1E") == "aAeE12"));
	assert((sorting("Re4r") == "erR4"));
	assert((sorting("6jnM31Q") == "jMnQ136"));
	assert((sorting("f5Eex") == "eEfx5"));
	assert((sorting("846ZIbo") == "bIoZ468"));
	assert((sorting("2lZduOg1jB8SPXf5rakC37wIE094Qvm6Tnyh") == "aBCdEfghIjklmnOPQrSTuvwXyZ0123456789"));
    std::cout << "Success" << std::endl;
    return 0;
}