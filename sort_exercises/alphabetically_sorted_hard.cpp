/*
https://edabit.com/challenge/tkQTD2TaXDE3eM4jp
*/

#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <string>

bool isAlphabeticallySorted(std::string s) {
	std::string temp {};
	int word_len {0};
	auto it = s.begin();
	auto it_prev = s.begin();
	while(it != s.end()){
		if (std::isalpha(*it)){
			it++;
			word_len++;
		}
		else {
			if (word_len > 2 && std::is_sorted(it_prev, it))
					return true;
			else {
				it++;
				it_prev = it;
				word_len = 0;
			}
		}
	}
	return false;
}

int main(){
    std::cout << isAlphabeticallySorted("The biopsy returned negative results.") << " = true" << std::endl;
    std::cout << isAlphabeticallySorted("She sells sea shells by the sea shore.") << " = false" << std::endl;
    return 0;
}