/*
https://edabit.com/challenge/M7Xzr3ez5xBPTu3bq
*/

#include <iostream>

int triangle(int n) {
	int sum = 0;
	while (n >= 1){
		sum += n;
		n--;
	}
	return sum;
}

int main(){
    std::cout << triangle(6) << " = 21" << "\n";
    return 0;
}
