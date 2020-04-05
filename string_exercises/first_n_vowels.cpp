/*
https://edabit.com/challenge/mtwkcXjQe75fDYjPx
*/

#include <iostream> 
#include <cctype>
#include <string>

std::string firstNVowels(std::string str, int n) {
	std::string not_enough {"invalid"};
    std::string result {};
    int counter {0};
    for (char c: str){
        if (c == 'e' || c =='i' || c == 'o' || c == 'a' || c == 'u'){
            result += c;
            counter++;
            if (counter == n)
                return result;
        }
    }
    return not_enough;
}

int main(){
    std::cout << firstNVowels("sharpening skills", 3) << std::endl;
    std::cout << firstNVowels("major league", 5)  << std::endl;
    std::cout << firstNVowels("hostess", 5)  << std::endl;
    return 0;
}