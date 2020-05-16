/*
https://edabit.com/challenge/8CAbaFuqDMeE4Ltgr

Number of Times a Character Appears

Create a function that returns the number of times a character appears in each word in a sentence.

Treat upper and lower case characters of the same letter as being identical (e.g. a exists in Anna
twice, not once; A exists in Anna twice, not once).

Examples:

charAppears("She sells sea shells by the seashore.", "s")
➞ [1, 2, 1, 2, 0, 0, 2]
// "s" shows up once in "She", twice in "sells", once in "sea", twice in "shells", etc.

charAppears("Peter Piper picked a peck of pickled peppers.", "P")
➞ [1, 2, 1, 0, 1, 0, 1, 3]
// "p" shows up once in "Peter", ... 3 times in "peppers".

charAppears("She hiked in the morning, then swam in the river.", "t")
➞ [0, 0, 0, 1, 0, 1, 0, 0, 1, 0]
*/


#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>


void print_vec(std::vector<int> v){
    for (auto const& i: v)
        std::cout << i << ' ';
    std::cout << std::endl;
}


std::vector<std::string> python_split(std::string str, std::string delimiter){
    size_t pos = 0;
    std::string token;
    std::vector<std::string> ans {};
    while ((pos = str.find(delimiter)) != std::string::npos){
        token = str.substr(0, pos);
        ans.push_back(token);
        str.erase(0, pos + delimiter.length());  
    }
    token = str.substr(0, pos);
    ans.push_back(token);
    return ans;
}


std::vector<int> charAppears(std::string s, char c) {
    std::string del {c};
    auto vec = python_split(s, " ");
    std::vector<int> ans {};
    for (auto const &word : vec){
        int n = std::count(word.begin(), word.end(), c);
        int k = std::count(word.begin(), word.end(), std::toupper(c));
        ans.push_back(n+k);
    }
    return ans;
}

int main(){
    std::string word {"She sells sea shells by the seashore."};
    std::string del {" "};
    print_vec(charAppears("She hiked in the morning, then swam in the river.", 't'));
    std::cout << "Success" << std::endl;
    return 0;
}