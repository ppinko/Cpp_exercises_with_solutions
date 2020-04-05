/*
https://edabit.com/challenge/D2SRFgCh6koCnPgEi
*/

#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>

std::string censor(std::string str) {
	auto it = str.begin();
	auto it_found = std::find(it, str.end(), ' ');
	while (it_found != str.end()){
		if (it_found - it <= 4){
			it = it_found + 1;
			it_found = std::find(it, str.end(), ' ');
		}
		else {
			std::string replaced (it_found - it, '*');
			str.replace(it, it_found, replaced.begin(), replaced.end());
			it = it_found + 1;
			it_found = std::find(it, str.end(), ' ');
		}
	}
	if (str.end() - it > 4){
			std::string replaced (str.end() - it, '*');
			str.replace(it, str.end(), replaced.begin(), replaced.end());
	}
	return str;
}

int main(){
    std::cout << censor("The code is fourty") << " = The code is ******" << "\n";
    return 0;
}