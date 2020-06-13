// https://edabit.com/challenge/EGFHjxnJMh3xuiLFa

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string spoonerise(std::string phrase) {
    std::string vowels {"aeiou"};
    std::string first_word {};
    std::string second_word {};
    std::string::iterator iter = phrase.begin();
    while (std::find(vowels.begin(), vowels.end(), (*iter)) == vowels.end()){
        first_word.push_back(*iter);
        iter++;
    }
    std::string::iterator iter2 = phrase.begin() + phrase.find_first_of(' ') + 1;
    while (std::find(vowels.begin(), vowels.end(), (*iter2)) == vowels.end()){
        second_word.push_back(*iter2);
        iter2++;
    }
    phrase.replace(0, first_word.size(), second_word);
    int pos_second_word = phrase.find(' ') + 1;
    phrase.replace(pos_second_word, second_word.size(), first_word);
    return phrase;
}


int main(){
    std::cout << spoonerise("crushing failure") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}