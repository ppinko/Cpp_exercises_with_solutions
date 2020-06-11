/*
https://edabit.com/challenge/LDNzJS27GY7aWNcBv
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct compare_length {
    bool operator()(const std::string &l, const std::string &r) const {
        return l.size() < r.size();
    }
};


std::vector<std::string> sortByLength(std::vector<std::string> arr) {
	std::sort(arr.begin(), arr.end(), compare_length());
    return arr;
}


// Alternative solution

// bool myFunc(std::string a, std::string b)	{
// 	return a.length() < b.length();
// }

// std::vector<std::string> sortByLength(std::vector<std::string> arr) {
// 	std::sort(arr.begin(), arr.end(), myFunc);
	
// 	return arr;
// }

int main(){
    std::cout << "Success" << std::endl;
    return 0;
}