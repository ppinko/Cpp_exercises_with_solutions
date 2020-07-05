// https://edabit.com/challenge/WxcHKJAuCDDmGbDWN

#include <string>
#include <cassert>
#include <iostream>
#include <map>
#include <set>

bool sameLetterPattern(std::string str1, std::string str2) {
	if (str1.size() != str2.size()) return false;
    std::map<char, char> letters_pattern {};
    std::set<char> pattern {};
    for (int i {0}; i < str1.size(); i++){
        char c = str1.at(i);
        char c2 = str2.at(i);
        if (letters_pattern.find(c) == letters_pattern.end()){
            letters_pattern.emplace(c, c2);
            auto result = pattern.insert(c2);
            if (result.second == false) return false;
        }
        else {
            if (letters_pattern[c] != c2) return false;
        }
    }
    return true;
}

int main(){
    assert((sameLetterPattern("AAAA", "BBBB") == true));
    assert((sameLetterPattern("ABCBA", "BCDCB") == true));
    assert((sameLetterPattern("FFGG", "FFG") == false));
	assert((sameLetterPattern("FFGG", "CDCD") == false));
    std::cout << "Success" << std::endl;
    return 0;
}

