/*
Count all names containing vowel {'a', 'e', 'i', 'o', 'u'}
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

struct {
    bool operator()(std::string str) const
    {
        return str.find('a') != -1 || str.find('e') != -1 || str.find('i') != -1 ||
                str.find('o') != -1 || str.find('u') != -1;
    }
} vowel_words;

int main(){

    std::vector<std::string> v {"banan", "ups", "object", "c++"};
    std::cout << std::count_if(v.cbegin(), v.cend(), vowel_words) << std::endl;

    return 0;
}