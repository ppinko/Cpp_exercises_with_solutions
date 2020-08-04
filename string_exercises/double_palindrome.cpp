// https://edabit.com/challenge/XqbL6onu8MNJPqyg9

#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

std::vector<std::string> seperate_words (const std::string &str){
    std::string letters, digits;
    std::copy_if(str.begin(), str.end(), std::back_inserter(letters), 
        [](char c){return std::isalpha(c);});
    std::copy_if(str.begin(), str.end(), std::back_inserter(digits), 
        [](char c){return std::isdigit(c);});
    std::vector<std::string> v {letters, digits};
    return v;  
}

int assess_words(std::vector<std::string> &words)
{
    int counter = 0;
    for (auto &word : words)
    {
        if (word.size() == 0)
            continue;
        while (word.size() > 1)
        {
            if (word.at(0) == word.at(word.size() - 1))
            {
                word.pop_back();
                word.erase(word.begin());
            }
            else 
            {
                break;
            }
        }
        if (word.size() <= 1)
            ++counter;
    }
    return counter;
}

std::vector<int> palindromeSet(std::vector<std::string> arr) {
	std::vector<int> answer {};
    for (auto &str : arr)
    {
        std::vector<std::string> temp = seperate_words(str);
        answer.push_back(assess_words(temp));
    }
    return answer;
}

int main()
{   

	assert((palindromeSet({"cb77c", "ccc888", "ccc789", "abc89"}) == std::vector<int>({2, 2, 1, 0})));
	assert((palindromeSet({"18a99b89cc881ba", "p7o8p987", "p7o", "p7o8"}) == std::vector<int>({1, 2, 1, 0})));
	assert((palindromeSet({"7a", "5f", "6c"}) == std::vector<int>({2, 2, 2})));
	assert((palindromeSet({"7ab", "5fc", "6cd"}) == std::vector<int>({1, 1, 1})));
	assert((palindromeSet({"87ab", "15fc", "26cd"}) == std::vector<int>({0, 0, 0})));
	assert((palindromeSet({"1234ab", "144a441"}) == std::vector<int>({0, 2})));
	assert((palindromeSet({"789", "555", "ccc", "abba"}) == std::vector<int>({0, 1, 1, 1})));
	assert((palindromeSet({"ab9a", "abba", "aa78bb8bbaa7", "a88a"}) == std::vector<int>({2, 1, 2, 2})));
	assert((palindromeSet({""}) == std::vector<int>({0})));

    std::cout << "Success\n" << std::flush;

    return 0;
}