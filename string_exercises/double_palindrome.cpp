// https://edabit.com/challenge/XqbL6onu8MNJPqyg9

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

bool rec_Palindrome(std::string str){
    std::string letters, digits;
    std::copy_if(str.begin(), str.end(), std::back_inserter(letters), 
        [](char c){return std::isalpha(c);});
    std::copy_if(str.begin(), str.end(), std::back_inserter(digits), 
        [](char c){return std::isdigit(c);});
    
    if (str.length() == 1 || str.length() == 0)
        return true;
    if (str[0] != str[str.length()-1])
        return false;
    else
        return rec_Palindrome(str.substr(1, str.length() - 2));   
}


std::vector<int> palindromeSet(std::vector<std::string> arr) {
	
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

    return 0;
}