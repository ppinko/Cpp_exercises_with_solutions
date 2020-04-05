/*
https://edabit.com/challenge/7NgGjgQvaRzYkmZJ3
*/

#include <iostream>

int digitDistance(int num1, int num2) {
	int ans {0};
	int n = 10;
	do {
		ans += num2 % n - num1 % n;
		num2 /= 10;
		num1 /= 10;
	} while (num2 != 0);
	return ans;
}

int main(){
    std::cout << digitDistance(121, 599) << " = 19" << std::endl;
    return 0;
}