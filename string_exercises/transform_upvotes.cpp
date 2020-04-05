/*
https://edabit.com/challenge/qfnWPjmJWFaZuitFz
*/

#include <iostream>
#include <vector>
#include <cctype>
#include <string>

std::vector<int> transformUpvotes(std::string s) {
	std::vector<std::string> temp {};
	int start = 0;
	auto pos = s.find(' ', start);
	do {
		pos = s.find(' ', start); 
		temp.push_back(s.substr(start, pos - start));
		start = pos;
		start++;
	} while (pos != std::string::npos);
	std::vector<int> v;
	for (std::string str : temp){
		if (str[str.length() -1 ] == 'k'){
			float x = std::stof(str.substr(0, str.length() - 1));
			x *= 1000;
			v.push_back((int)x);
		}
		else{
			int y = std::stoi(str);
			v.push_back(y);
		}
	}
	return v;
}

int main(){
    return 0;
}