/*
https://edabit.com/challenge/E2oQvpnwuMMfYJ6gq
*/

#include <iostream> 
#include <cctype>
#include <string>

std::string split(std::string str) {
    std::string ans {};
    std::string no_vowels {};
    for (char c : str){
        if (c == 'e' || c =='i' || c == 'o' || c == 'a' || c == 'u')
            ans += c;
        else
            no_vowels += c;
    }
    ans += no_vowels;        
    return ans;
}

int main(){
    std::cout << split("abcde") << " : aebcd" << std::endl;
    std::cout << split("Hello!") << " : eoHll!"  << std::endl;
    std::cout << split("What's the time?") << " : aeieWht's th tm?"  << std::endl;
    return 0;
}