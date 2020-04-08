/*
https://edabit.com/challenge/fiKqrYibtEuykW7PF
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

bool canBuild(std::string str1, std::string str2) {
	str1.erase(std::remove(str1.begin(), str1.end(), ' '), str1.end());
	str2.erase(std::remove(str2.begin(), str2.end(), ' '), str2.end());
	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());
	std::string str3 {};
	std::set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(), std::back_inserter(str3));
	if (str3.length() == str1.length())
		return true;
	return false;
}

int main(){
    std::cout << canBuild("got 2 go", "gogogo 2 today") << " should equal 1" << std::endl;
    std::cout << canBuild("long high add or", "highway road go long") << " should equal 0" << std::endl;
    return 0;
}
