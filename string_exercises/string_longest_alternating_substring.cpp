// https://edabit.com/challenge/R95FfS8PGtsCLxnKH

#include <string>
#include <cassert>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

std::string longestSubstring(std::string digits) {
	int alternate = -1;
    std::string temp {};
    std::string longest {};
    for (char c : digits){
        int val = (int)c - (int)'0';
        val %= 2;
        if (val == alternate) temp.clear();
        temp.push_back(c);
        alternate = val;
        if (temp.size() > longest.size()) longest = temp;
    }
    return longest;
}

int main(){
    assert((longestSubstring("345724969853525333273796592356") == "496985"));
	assert((longestSubstring("548915548581127334254139969136") == "8581"));
	assert((longestSubstring("417922164857852157775176959188") == "78521"));
	assert((longestSubstring("251346385699223913113161144327") == "638569"));
    std::cout << "Success" << std::endl;
    return 0;
}