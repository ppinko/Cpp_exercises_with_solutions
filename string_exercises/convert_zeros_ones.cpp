// https://edabit.com/challenge/JFGHZjb7KNJdhfkDC

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <sstream>

std::string textToNumberBinary(std::string s) {
	std::string answer = "";
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return std::tolower(c);});
    int words = std::count(s.begin(), s.end(), ' ');
    if (words < 7)
        return answer;
    std::istringstream iss {s};
    std::string temp;
    while (iss >> temp)
    {
        if (temp == "zero")
            answer.push_back('0');
        else if (temp == "one")
            answer.push_back('1');
    }
    if (answer.size() < 8)
        answer.clear();
    else
    {   
        answer = answer.substr(0, 8 * (answer.size() / 8));
    }

    return answer;
}

int main(){
    
    // std::cout << textToNumberBinary("One zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero") << std::endl;

    assert((textToNumberBinary("one one one one zero zero zero zero") == "11110000"));
    assert((textToNumberBinary("One zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero") == "1001011101100001011101100001011101100001011101100001011101100001"));
    assert((textToNumberBinary("one Zero zero one zero zero one one one one one zero oNe one one zero one zerO") == "1001001111101110"));
    assert((textToNumberBinary("one zero one") == ""));
    assert((textToNumberBinary("TWO one zero one one zero one zero") == ""));
    assert((textToNumberBinary("one zero zero one zero ten one one one one two") == "10010111"));
    assert((textToNumberBinary("TWO one zero one one zero one zero one") == "10110101"));

    return 0;
}