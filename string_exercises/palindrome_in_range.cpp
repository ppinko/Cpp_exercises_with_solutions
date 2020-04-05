/*
https://edabit.com/challenge/xGmJtnrwv54jtZvqP
*/

#include <iostream> 
#include <cctype>
#include <string>

bool isPalindrome(std::string str);
bool rec_Palindrome(std::string low);
std::string sentence_to_lower(std::string str);
int countPalindromes(int num1, int num2);

bool isPalindrome(std::string str){
    std::string lower = sentence_to_lower(str);
    return rec_Palindrome(lower);
}

bool rec_Palindrome(std::string low){
    if (low.length() == 1 || low.length() == 0)
        return true;
    if (low[0] != low[low.length()-1])
        return false;
    else
        return rec_Palindrome(low.substr(1, low.length() - 2));
    
}

std::string sentence_to_lower(std::string str){
    std::string lower {};
    for (char c : str){
        if (std::isdigit(c))
            lower += std::tolower(c);
    }  
    return lower;  
}

int countPalindromes(int num1, int num2) {
	int counter {0};
    std::string temp {};
    for (num1; num1 <= num2; num1++){
        temp = std::to_string(num1);
        if (isPalindrome(temp))
            counter++;
    }
    return counter;
}

int main(){
    std::cout << countPalindromes(1, 10) << std::endl;
    std::cout << countPalindromes(555, 556) << std::endl;
    std::cout << countPalindromes(878, 898) << std::endl;
    return 0;
}