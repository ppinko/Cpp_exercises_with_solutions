/*
https://edabit.com/challenge/JLfEg4J8xSKCNKdEp
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

bool anaStrStr(std::string needle, std::string haystack) {
	std::sort(needle.begin(), needle.end());
	std::string sorted_haystack {haystack};
	std::sort(sorted_haystack.begin(), sorted_haystack.end());
	std::string test {};
	std::set_intersection(needle.begin(), needle.end(),
											 sorted_haystack.begin(), sorted_haystack.end(),
											 std::back_inserter(test));
	if (test.length() != needle.length())
		return false;
	for (int i {0}; i < needle.length() + 1; i++){
		std::string temp = haystack.substr(i, needle.length());
		std::sort(temp.begin(), temp.end());
		if (needle == temp)
			return true;
	}
	return false;
}

int main(){
    std::cout << (anaStrStr("car", "race") == true) << std::endl;
    std::cout << (anaStrStr("bag", "grab") == false) << std::endl;
    return 0;
}