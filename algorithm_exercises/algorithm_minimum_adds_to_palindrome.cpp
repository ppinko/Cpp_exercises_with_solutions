// https://edabit.com/challenge/SRnJJw3pEuHjeMaHS

#include <iostream>
#include <string>
#include <cassert>

int minPalindromeSteps(const std::string str);
bool isPalindrom(const std::string& str);

bool isPalindrom(const std::string& str)
{
    int length = str.size();
    for (int i = 0; i < str.size() / 2; ++i)
    {
        if (str[i] != str[length - i - 1])
            return false;
    }
    return true;
}

int minPalindromeSteps(const std::string str) 
{   
    if (str.size() <= 1)
        return 0;
    for (int i = 0; i < str.size() - 1; ++i)
    {
        std::string temp = str.substr(i);
        std::cout << temp << std::endl;
        if (isPalindrom(temp))
            return i;
    }
    return str.size() - 1;
}


int main(){

    std::cout << minPalindromeSteps("maa") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}