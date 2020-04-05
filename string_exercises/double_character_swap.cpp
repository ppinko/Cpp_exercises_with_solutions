/*
https://edabit.com/challenge/s695FkhRd3J65tmdQ
*/

#include <iostream>
#include <string>

std::string doubleSwap(std::string s, char c1, char c2) {
	for (int i {0}; i < s.length(); i++){
		if (s[i] == c1) s[i] = c2;
		else if (s[i] == c2) s[i] = c1;
	}
	return s;
}

int main(){
    std::cout << doubleSwap("aabbccc", 'a', 'b') << " = bbaaccc"  << "\n";
    return 0;
}