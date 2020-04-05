/*
https://edabit.com/challenge/M3ET2Pa3oHH6KWXyw
*/

#include <cmath>
#include <iostream>

int convert(int slope) {
	if (slope == 0) return 90;
	double pi = 3.14159265358979323846;
	double result = std::round(std::atan(slope) * 180 / pi);
	int res = 90 - (int)result;
	return res;
}

int main(){
    
    std::cout << convert(1) << " equals to = 45 " << std::endl;
    std::cout << convert(0) << " equals to = 90 " << std::endl;
    std::cout << convert(-1) << " equals to = 135 " << std::endl;

    return 0;
}