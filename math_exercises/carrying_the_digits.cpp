/*
https://edabit.com/challenge/2QphS7wwuTgRGaxBJ
*/

#include <iostream> 
#include <cmath>
#include <algorithm>

int carryDigits(int n1, int n2) {
	int max_n = std::max(n1, n2);
    int min_n = std::min(n1, n2);
    int counter {0};
    int temp1 {};
    int temp2 {};
    int temp3 {0};
    while (max_n != 0){
        temp1 = max_n % 10;
        temp2 = min_n % 10;
        max_n /= 10;
        min_n /= 10;
        if (temp1 + temp2 + temp3 >= 10){
            counter++;
            temp3 = 1;
        }
        else 
            temp3 = 0;
    }
    return counter;
}


int main(){
    std::cout << carryDigits(36, 135) << " = 1 " << std::endl;
    std::cout << carryDigits(1111, 3333) << " = 0" << std::endl;
    std::cout << carryDigits(53214, 56905) << " = 3" << std::endl;
    return 0;
}