/*
https://edabit.com/challenge/AhkWvhrAGfGsDyWvb
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool rightTriangle(int x, int y, int z) {
	std::vector<int> v {x, y, z};
	if (std::count_if(v.begin(), v.end(), [](int i){return i <= 0;}) != 0)
		return false;
	std::sort(v.begin(), v.end());
	if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
		return true;
	return false;
}

int main(){
    std::cout << rightTriangle(3, 4, 5) << " should equal to 1" << std::endl;
    std::cout << rightTriangle(70, 130, 110) << " should equal to 0" << std::endl;
    return 0;
}