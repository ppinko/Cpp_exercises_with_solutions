/*
https://edabit.com/challenge/D2SRFgCh6koCnPgEi
*/

#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>

std::string censor(std::string str)
{
	auto first = str.begin(), last = str.end();
	first = std::find_if_not(first, last, ::isspace);
	
	while (first != last) {
		auto next = first;
		next = std::find_if(++next, last, ::isspace);
		
		if (std::distance(first, next) > 4)
			std::fill(first, next, '*');
		if (next == last)
			break;
		
		first = std::find_if_not(++next, last, ::isspace);
	}

	return str;
}

int main(){
    std::cout << censor("The code is fourty") << " = The code is ******" << "\n";
    return 0;
}