// https://edabit.com/challenge/6eKE83afJNGfQjtTF

#include <iostream>
#include <string>
#include <algorithm>

int minSwaps(std::string str) {
	int start_one = 0;
    int start_zero = 0;
    int index = 0;
    for (char& c: str){
        if ((index % 2 == 0 && c == '1') || (index % 2 == 1 && c == '0')) start_zero++;
        else start_one++;
        index++;
    }
    return std::min(start_one, start_zero);
}

int main(){
    minSwaps("010010111");
    minSwaps("010101010");
    std::cout << "Success" << std::endl;
    return 0;
}