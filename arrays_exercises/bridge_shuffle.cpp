/*
https://edabit.com/challenge/CSf9zMBJBdc6YAHKo
*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

std::vector<std::string> bridgeShuffle(std::vector<std::string> arr1, 
		std::vector<std::string> arr2) {
	std::vector<std::string> res {};
	int i = 0;
	for (i; i < arr1.size(); i++){
		res.push_back(arr1[i]);
		if (i < arr2.size())
			res.push_back(arr2[i]);
	}
	while (i < arr2.size()){
		res.push_back(arr2[i]);
		i++;
	}
	return res;
}

int main(){
    std::vector<std::string> arr1 = {"C", "C", "C", "C"};
    std::vector<std::string> arr2 = {"D"};
    std::vector<std::string> shuffled = {"C", "D", "C", "C", "C"};
    std::cout << std::boolalpha;
    std::cout << (shuffled == bridgeShuffle(arr1, arr2)) << std::endl;
    return 0;
}