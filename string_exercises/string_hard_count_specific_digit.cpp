// https://edabit.com/challenge/FsG7JrxTyPyoeWT4Q

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int digitOccurrences(int min, int max, int digit) {
	int total = 0;
    std::string digit_c = std::to_string(digit);
    std::cout << digit_c << " digit " << digit << std::endl;
    for (int i = min; i <= max; i++){
        std::string str = std::to_string(i);
        total += std::count(str.begin(), str.end(), digit_c[0]);
    }
    return total;
}

int main(){
    std::cout << digitOccurrences(51, 55, 5) << " should equal to 6." << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}