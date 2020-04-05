#include <iostream>
#include <string>
#include <algorithm>

/*
https://edabit.com/challenge/BnQxapsGjBg64JqCc

*/

std::string replaceThe(std::string& str){
    std::string vowels = "aeio";
    auto n = str.find("the");
    while (n != std::string::npos){
        char k = str[n+4];
        bool flag {true};
        for (char i : vowels){
            if (i == k){
                str.replace(n, 3, "an");
                flag = false;
                break;
            }
        }
        if (flag)
            str.replace(n, 3, "a");
        n = str.find("the");
    }
    return str;
}

int main(){
    std::string test = "the egg, the spoon and the espionage";
    std::cout << replaceThe(test) << std::endl;
    std::cout << test << std::endl;
    return 0;
}