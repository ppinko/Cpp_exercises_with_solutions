/*
https://edabit.com/challenge/df9LtdceySMvqQJtW
*/

#include <cctype>
#include <iostream>

std::string insertWhitespace(std::string str) {
	bool flag = false;
	std::string new_str {};
	for (char c : str){
		if (std::islower(c))
			flag = true;
		else if (flag && std::isupper(c)){
			new_str += ' ';
			flag = false;
		}
		new_str += c;
	}
	return new_str;
}

int main(){
    std::cout << insertWhitespace("MarvinTalksTooMuch") << " = Marvin Talks Too Much" << std::endl;
    return 0;
}