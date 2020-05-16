/*
https://edabit.com/challenge/SS2T2QAsf5jWWZJ24

Count the Number of Duplicate Characters

Create a function that returns the amount of duplicate characters in a string. 
It will be case sensitive and spaces are included. If there are no duplicates, return 0.

Examples:

duplicates("Hello World!") ➞ 3

duplicates("foobar") ➞ 1

duplicates("helicopter") ➞ 1

duplicates("birthday") ➞ 0
// If there are no duplicates, return 0
*/


#include <iostream>
#include <string>
#include <map>
#include <cctype>


int duplicates(std::string str) {
	std::map<char, int> char_freq {};
    for (char& c : str){
        auto it = char_freq.find(c);
        if (isalpha(c) && it == char_freq.end())
            char_freq[c] = 1;
        else if (isalpha(c) && it != char_freq.end())
            char_freq[c] += 1;
    }
    int ans = 0;
    auto it = char_freq.begin();
    while (it != char_freq.end()){
        ans += it->second - 1;
        it++;
    }
    return ans;
}


int main(){
    std::cout << duplicates("Hello World!") << std::endl;
    return 0;
}