/*
https://edabit.com/challenge/LaJsPMBqXMBECWGCN
*/

#include <iostream>

int persistence(unsigned long int num) {
	unsigned long int temp = 1;
	int count = 0;
	if (num < 10)
		return 0;	
	while (num > 9){
		count++;
		while (num > 0){
			temp *= num % 10;
			num /= 10;
		}
		num = temp;
		temp = 1;
	}
	return count;
}	

int main(){
    std::cout << persistence(9) << std::endl;
    std::cout << persistence(11)<< std::endl;
    std::cout << (persistence(6788) == 6) << std::endl;
    return 0;
}