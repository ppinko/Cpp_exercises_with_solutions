/*
https://edabit.com/challenge/s68GjL3c5qugzHF4f
*/

#include <iostream>
#include <string>
#include <iterator>
#include <cctype>

bool doesRhyme(std::string str1, std::string str2) {
	std::string end1 {};
	std::string end2 {};
	for (int i = str1.rfind(' '); i < str1.length(); i++){
		char c = std::tolower(str1[i]);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			end1 += c;
	}
	for (int i = str2.rfind(' '); i < str2.length(); i++){
		char c = std::tolower(str2[i]);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			end2 += c;
	}
	return (end1 == end2);
}

int main(){
    std::cout << doesRhyme("Sam I am!", "Green eggs and ham.") << " = true" << std::endl;
    return 0;
}