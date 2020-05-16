/*
https://edabit.com/challenge/JGLzdgXRcwBRGAcF3

You will be implementing a basic case of the map-reduce pattern in programming.
Use the built in C++ array functions std::transform for map and std::accumulate
for reduce to solve the following problem.

Examples:

magnitude([3, 4]) ➞ 5

magnitude([0, 0, -10]) ➞ 10

magnitude([]) ➞ 0

magnitude([2, 3, 6, 1, 8] ) ➞ 10.677078252031311
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>


float magnitude(std::vector<float> nums) {
	std::transform(nums.begin(), nums.end(), nums.begin(),
        [](float i) -> float { return i * i; });
    float ans = std::accumulate(nums.begin(), nums.end(), 0);
    return std::pow(ans, 0.5);
}


int main(){
    return 0;
}