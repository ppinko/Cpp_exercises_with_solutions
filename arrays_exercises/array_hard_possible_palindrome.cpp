/*
https://edabit.com/challenge/gJKr6RmNYCP2E4daP
*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <iterator>
#include <algorithm>
#include <set>

bool possiblePalindrome(std::string s) {
	std::set<char> set;
    for (const char& c: s)
        set.insert(c);
    int even = 0;
    int odd = 0;
    for (const char& c: set){
        int k = std::count(s.begin(), s.end(), c);
        ((k % 2 == 0) ? even++ : odd++);
    }
    return (odd <= 1);
}


int main(){
    // std::vector<int> vec1 {5, 7, 3, 2, 8};
    // auto vec2 = replaceNextLargest(vec1);
    // for (auto i: vec2){
    //     std::cout << i << " ";
    // }
    std::cout << "Success" << std::endl;
    return 0;
}