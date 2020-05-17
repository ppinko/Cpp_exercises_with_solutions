/*
https://edabit.com/challenge/tLJdKYyLDkidPioAy

Words With Duplicate Letters

Given a common phrase, return false if any individual word in the
phrase contains duplicate letters. Return true otherwise.

Examples:
noDuplicateLetters("Fortune favours the bold.") ➞ true
noDuplicateLetters("Look before you leap.") ➞ false
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>

bool noDuplicateLetters(std::string phrase) {
    std::string word {};
    while ((phrase.find(" ")) != std::string::npos){
        word.clear();
        int pos = phrase.find(" ");
        for (int i = 0; i < pos; i++) word += std::tolower(phrase[i]);
        phrase.erase(0, pos + 1);
        std::set<char> s (word.begin(), word.end());
        if (s.size() != word.length()) return false;
    }
    word.clear();
    for (int i = 0; i < phrase.size(); i++) word += std::tolower(phrase[i]);
    std::set<char> s_final (phrase.begin(), phrase.end());
    if (s_final.size() != word.length()) return false;
    return true;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << noDuplicateLetters("Fortune favours the bold.") << std::endl;
    std::cout << noDuplicateLetters("So far, so good.") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}