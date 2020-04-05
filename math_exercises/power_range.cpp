/*
https://edabit.com/challenge/6Gh9SSD6ZCZS89HMc
*/

#include <cmath>
#include <iostream>

int powerRanger(int power, int min, int max) {
	double boundary_low = std::pow(double(min), 1.0 / power);
	double boundary_high = std::pow(double(max), 1.0 / power);
	int bl = std::ceil(boundary_low);
	int bh = std::floor(boundary_high);
	if (bh < bl) return 0;
	else return bh - bl + 1;
}

int main(){   
    std::cout << powerRanger(4, 250, 1300) << " equals to = 3 " << std::endl;
    return 0;
}