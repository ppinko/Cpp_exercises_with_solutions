// https://edabit.com/challenge/kR9oYxEws69ArjwKM

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iterator>

bool isParselTongue(std::string s);

bool isParselTongue(std::string s) {
    std::string s_lower {};
    std::transform(s.begin(), s.end(), std::back_inserter(s_lower),
        [](char c) -> char {return std::tolower(c);});
    std::cout << "s_lower = " << s_lower << std::endl;
	int index = s_lower.find_first_of('s', 0);
    while (index != -1){
        if (index == s_lower.size() - 1 || s_lower.at(index+1) != 's') return false;
        int span = s_lower.find_first_not_of('s', index);
        index = s_lower.find_first_of('s', span);
    }
    return true;
}


int main(){
    std::cout << std::boolalpha;
    std::cout << isParselTongue("Sshe ssselectss to eat that apple.") << " should equal to true." << std::endl;
    std::cout << isParselTongue("She ssselects to eat that apple.") << " should equal to false." << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}