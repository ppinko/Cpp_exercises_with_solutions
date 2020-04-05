/*
https://edabit.com/challenge/egHYkzJZaoiJoGsgd
*/

#include <iostream>
#include <string>
#include <cctype>

std::string removeSpecialCharacters(std::string str) {
	std::string s {};
	for (char &c : str){
		if (std::isalnum(c) || std::isspace(c) || c == '-' || c == '_') 
			s.push_back(c);
	}
	return s;
}

int main(){
    std::cout << removeSpecialCharacters("%fd76$fd(-)6GvKlO.") << " shoud equal to fd76fd-6GvKlO" << std::endl;
    return 0;
}