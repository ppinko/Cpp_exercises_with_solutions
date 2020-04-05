/*
https://edabit.com/challenge/eLH7c93ujbacHTwmy
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> removeDups(std::vector<std::string> arr) {
	std::vector<std::string> new_arr {};
	std::map<std::string, int> m {};
	for (std::string str : arr) {
		if (m.find(str) == m.end()){
			new_arr.push_back(str);
			m.emplace(str, 1);
		}
	}
	return new_arr;
}

int main(){
    return 0;
}