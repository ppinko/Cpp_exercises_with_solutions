/*
https://edabit.com/challenge/kPp8WKYcaEAsJonhe

Longest Common Ending

Write a function that returns the longest common ending between two strings.

Examples:

longestCommonEnding("multiplication", "ration") ➞ "ation"
longestCommonEnding("potent", "tent") ➞ "tent"
longestCommonEnding("skyscraper", "carnivore") ➞ ""
*/


#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>

std::string longestCommonEnding(std::string s1, std::string s2) {
	std::string common_ending {};
    int l = ((s1.size() > s2.size() ) ? s1.size() : s2.size());
    auto it1 = s1.rbegin();
    auto it2 = s2.rbegin();
    for (int i (0); i < l; i++){
        if (*it1 == *it2) {
            common_ending.insert(common_ending.begin(), *it1);
            it1++;
            it2++;
        }
        else return common_ending;
    }
}


int main(){
    std::cout << std::boolalpha;
    std::cout << longestCommonEnding("multiplication", "ration") << std::endl;
    std::cout << longestCommonEnding("potent", "tent") << std::endl;
    std::cout << longestCommonEnding("skyscraper", "carnivore") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}
