/*
https://edabit.com/challenge/TK4AF6bohj9pSkNPk
*/

#include <iostream>
#include <cmath>

int smallest(int digits, int value) {
	if (value < 10 && digits == 1)
		return value;
	int temp = std::pow(10, digits - 1);
	while (true){
		if (temp % value == 0)
			return temp;
		temp++;
	}
}

int main(){
    std::cout << smallest(5, 12) << " should equal to 10008" << std::endl;
    return 0;
}