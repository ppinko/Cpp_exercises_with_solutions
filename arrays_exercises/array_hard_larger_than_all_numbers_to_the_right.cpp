/*
https://edabit.com/challenge/wzRGGpZfu2DuiBvbu
*/

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <typeinfo>

std::vector<int> largerThanRight(std::vector<int> arr) {
	std::vector<int> answer {};
    for (auto it = arr.begin(); it != arr.end(); it++){
        if (it == std::max_element(it, arr.end()) && std::find(it + 1, arr.end(), *it) == arr.end()) 
            answer.push_back(*it);
    }
    return answer;
}

int main(){
    std::vector<int> v {13, 11, 19, 5};
    std::cout << "Success" << std::endl;
    return 0;
}