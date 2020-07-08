/* 
Write a function that decides if a given char array is a palindrome. 
A palindrome is a word/phrasethat can be read the same from left to
right as from right to left. Example: EVE, MADAMIMADAM, ABBA are
palindromes.
*/

#include <iostream>
#include <iomanip>

bool isPalindrome(const char* word, int size){
    if (size <= 1) return true;
    else if (word[0] == word[size-1]){
        size -= 2;
        ++word;
        return isPalindrome(word, size);
    }
    else return false;
}

int main(){
    char name [] = "aorka";
    std::cout << std::boolalpha;
    
    // checking position of an array
    int shift = 5 % 2;
    std::cout << name[1] << std::endl;


    std::cout << isPalindrome(name, 5) << std::endl;
    return 0;
}