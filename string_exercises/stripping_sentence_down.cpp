/*
https://edabit.com/challenge/m3qQgMbLhMpbEySBP
*/

#include <set>
#include <iostream>

std::string stripSentence(std::string str, std::string chars) {
	std::set<char> s;
	s.insert(chars.begin(), chars.end());
	std::string new_str;
	for (char c : str){
		if (s.find(c) == s.end())
			new_str += c;
	}
	return new_str;
}

int main(){
    std::cout << stripSentence("the quick brown fox jumps over the lazy dog", "aeiou") <<
        " = th qck brwn fx jmps vr th lzy dg" << "\n";
    return 0;
}