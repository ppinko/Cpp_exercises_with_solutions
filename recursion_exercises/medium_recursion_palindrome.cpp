/*


Recursion: String Palindromes

Write a function that recursively determines if a string is a palindrome.

Examples:

isPalindrome("ad") ➞ false

isPalindrome("abcba") ➞ true

isPalindrome("abbbbb") ➞ false

An empty string counts as a palindrome.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>

bool isPalindrome(std::string str) {
    if (str.size() == 0 || str.size() == 1) return true;
    else if (str.front() != str.back()) return false;
    else return isPalindrome(str.substr(1, str.size() - 2));
}

int main(){
    std::cout << std::boolalpha;
    std::cout << isPalindrome("abbbbb") << std::endl;
    std::cout << isPalindrome("abcba") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}