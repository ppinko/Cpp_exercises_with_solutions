/*
https://edabit.com/challenge/G3vh6eg7xYutMJYCb
*/

#include <iostream>
#include <cctype>
#include <string>

bool overlap(std::string str1, std::string str2) {
	std::string s = str2.substr(str2.length() - str1.length(), 
															str1.length());
	int i {0};
	while (i < str1.length()){
		if (std::tolower(str1[i]) == std::tolower(s[i]) || str1[i] == '*' 
				|| s[i] == '*')
			i++;
		else 
			return false;
	}
	return true;
}

int main(){
    std::cout << overlap("abc", "Ican'tsingmyABC") << " should equal 1" << std::endl;
    std::cout << overlap("hello", "hello world") << " should equal 0" << std::endl;
    return 0;
}