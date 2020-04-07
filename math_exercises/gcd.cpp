/*
https://edabit.com/challenge/BzEQsTSmPATbsZJCR
*/

#include <iostream>

int gcd(int a, int b) {
	if (a == b)
		return a;
	if (a == 0 || b == 0){
		if (a > b){
			return b;
		}
		else
			return a;
	}
	while (a != 0 && b != 0){
		if ( a == b)
			return a;
		else if ( a > b){
			a = a % b;
			if (a == 0)
				return b;
		}
		else {
			b = b % a;
			if (b == 0)
				return a;
		}
	}
    return 0;
}

int main(){
    std::cout << gcd(14, 28) << " should equal to 14" << std::endl;
    std::cout << gcd(4, 18) << " should equal to 2" << std::endl;
    return 0;
}