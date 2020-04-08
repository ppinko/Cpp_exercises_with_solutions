/*
https://edabit.com/challenge/rAYegxMqQuHeqSHSz
*/

#include <cmath>
#include <iostream>

int halveCount(int a, int b) {
	return std::ceil(std::log2(a) - std::log2(b) -1);
}

int main(){
    std::cout << halveCount(1324, 98) << " should equal 3" << std::endl;
    return 0;
}