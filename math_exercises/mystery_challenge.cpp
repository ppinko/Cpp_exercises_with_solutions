/*
https://edabit.com/challenge/RRX73DEm2BLp8z2TG
*/

#include <string>
#include <iostream>

std::string mysteryFunc(int n) {
	std::string temp = std::to_string(n);
	std::string new_str {};
	int count {1};
	for (int i {0}; i < temp.length(); i++){
		if (i == temp.length() - 1){
			new_str += std::to_string(count);
			new_str += temp[i];
		}
		else if (temp[i] == temp[i+1])
			count++;
		else {
			new_str += std::to_string(count);
			new_str += temp[i];
			count = 1;
		}
	}
	return new_str;
}

int main(){
    std::cout << mysteryFunc(5211255) << " = 1512211225" << "\n";
    return 0;
}