/*
https://edabit.com/challenge/qeCS48GXtK9NJLc9C
*/

#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

// USING set_intersection to find repeating elements

int sharedLetters(std::string str1, std::string str2) {
	std::sort(str1.begin(),str1.end());
	std::sort(str2.begin(),str2.end());
	std::string intersectStr;
	std::set_intersection(str1.begin(),str1.end(),str2.begin(),str2.end(),
												std::back_inserter(intersectStr));
	return intersectStr.size();
}

int main(){
    std::cout << sharedLetters("apple", "moeapty") << " = 4" << std::endl;
    return 0;
}