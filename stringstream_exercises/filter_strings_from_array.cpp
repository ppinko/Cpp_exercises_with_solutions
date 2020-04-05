/*
https://edabit.com/challenge/WMWtKrTpCDGzEcNKi
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> filterArray(std::vector<std::string> arr) {
	auto it = arr.begin();
	int x;
	while(it != arr.end()){
		std::istringstream iss {*it};
		if ( iss >> x) it++;
		else it = arr.erase(it);
	}
	return arr;
}

int main(){
    return 0;
}
