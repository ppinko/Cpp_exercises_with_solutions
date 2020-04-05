/*
https://edabit.com/challenge/KAkXmQFM4vPxnKo7P
*/

#include <iostream>
#include <cmath>
#include <string>
#include <set>

int sum_square(int num){
	int res {0};
	while (num > 0){
		res += std::pow(num % 10, 2);
		num /= 10;
	}
	return res;
}

std::string happyAlgorithm(int num) {
	if (num == 1) 
		return "HAPPY 1";
	std::set<int> s;
	s.insert(num);
	int counter = 0;
	while (true){
		counter++;
		num = sum_square(num);
		if (num == 1)
			return "HAPPY " + std::to_string(counter);
		auto it = s.insert(num);
		if (it.second == false){
			return "SAD " + std::to_string(counter);
		}
	}
}

int main(){
    
    std::cout << happyAlgorithm(139) << " equals to = HAPPY 5 " << std::endl;

    return 0;
}