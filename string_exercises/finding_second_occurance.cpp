/*
https://edabit.com/challenge/ZA7D6GqyAgkzcnGad
*/

#include <iostream>
#include <string>

int findZip(std::string str) {
	size_t start = 0;
	for (int i {0}; i <= 1; i++){
		start = str.find("zip", start);
		if (start == std::string::npos) return -1;
		else if (i == 0) start++;
		else return start;
	}
    return 0;
}

int main(){
    std::cout << findZip("all zip files are zipped") << " shoud equal to 18" << std::endl;
    return 0;
}
