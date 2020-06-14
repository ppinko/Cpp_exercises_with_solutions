// https://edabit.com/challenge/7MB4iAGx53BMgHAC6

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string reverse(std::string str) {
	std::string letters {};
    for (const char& c: str){
        if (std::isalpha(c)) letters.push_back(c);
    }
    std::reverse(letters.begin(), letters.end());
    int index = 0;
    for (int i = 0; i < str.size(); i++){
        if (std::isalpha(str[i])){
            str[i] = letters[index];
            index++;
        }
    }
    return str;
}

int main(){
    std::cout << reverse("ab89c") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}