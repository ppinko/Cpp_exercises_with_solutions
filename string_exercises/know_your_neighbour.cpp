/*
https://edabit.com/challenge/CqQn9z9dS3u957Bg7
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

bool plusSign(std::string str) {
	for (int i {0}; i < str.length(); i++){
		if (i == 0 || i == str.length() - 1){
			if (std::isalpha(str[i]))
				return false;
		}
		else if (std::isalpha(str[i])){
			if (str[i-1] != '+' || str[i+1] != '+')
				return false;
		}
	}
	return true;
}

int main(){
    std::cout << std::boolalpha;
    std::cout <<  plusSign("+f+d+c+#+f+") <<" -> should equal to true" << std::endl;
    std::cout <<  plusSign("+s+7+fg+r+8+") <<" -> should equal to false" << std::endl;
    return 0;
}