/*
https://edabit.com/challenge/hTwBnjQXvgpkmGATF


Star Shorthand

Write a function that converts a string into star shorthand. If a character is repeated n times, convert it into character*n.

Examples:
toStarShorthand("abbccc") ➞ "ab*2c*3"
toStarShorthand("77777geff") ➞ "7*5gef*2"
toStarShorthand("abc") ➞ "abc"
toStarShorthand("") ➞ ""

Notes
    Leave lone occurrences of a character as is.
    Return an empty string if given an empty string input.
*/


#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>

std::string toStarShorthand(std::string str) {
    std::string ans {};
    int seq = 0;
    char c {};
    for (int i (0); i < str.length(); i++){
        if (i == 0) {
            ans.push_back(str[i]);
            seq = 1;
        }
        else if (ans.back() == str[i]){
            seq += 1;
        }
        else if (seq > 1){
            ans.push_back('*');
            ans += std::to_string(seq);
            ans.push_back(str[i]);
            seq = 1;
        }
        else {
            ans.push_back(str[i]);
            seq = 1;            
        }
    }
    if (seq > 1){
        ans.push_back('*');
        ans += std::to_string(seq);
    }
    return ans;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << toStarShorthand("abbccc") << std::endl;
    std::cout << toStarShorthand("77777geff") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}