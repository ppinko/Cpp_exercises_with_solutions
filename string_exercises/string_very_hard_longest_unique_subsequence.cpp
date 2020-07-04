// https://edabit.com/challenge/WFQvbjeXRZeontieP

#include <iostream>
#include <string>

std::string longestNRS(std::string str) {
    std::string max_str {};
    std::string temp {};
    for (int i {0}; i < str.size(); i++){
        char c = str.at(i);
        int pos = temp.find(c);
        temp.push_back(c);
        if (pos != -1)
            temp = temp.substr(pos + 1, temp.size() - pos - 1);
        if (temp.size() > max_str.size()) max_str = temp;
    }
    return max_str;
}

int main(){
    std::cout << longestNRS("abcabcbb") << std::endl;
	std::cout << longestNRS("aaaaaa") << std::endl;
	std::cout << longestNRS("abcde") << std::endl;
	std::cout << longestNRS("abcda") << std::endl;
    return 0;
}