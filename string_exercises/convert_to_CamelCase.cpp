/*
https://edabit.com/challenge/9PsMWfD9Zr66Lgoot
*/

#include <iostream>
#include <string>
#include <cctype>

std::string toCamelCase(std::string str) {
	std::string new_str {str.at(0)};
    if (str.empty())
        return "";
    for (int i {1}; i < str.length(); i++){
        if (str[i] != '-' && str[i] != '_'){
            if (str[i-1] != '-' && str[i-1] != '_')
                new_str.push_back(str[i]);
            else
                new_str.push_back(std::toupper(str[i]));
        }
    }
    return new_str;
}

int main(){
    std::cout << toCamelCase("the-stealth-warrior") << std::endl;
    std::cout << (toCamelCase("the-stealth-warrior") == "theStealthWarrior") << std::endl;
    return 0;
}