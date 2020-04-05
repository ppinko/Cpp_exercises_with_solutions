/*
https://edabit.com/challenge/hjmadKkCtejKpvpc6
*/

#include <cmath>
#include <iostream>

int towerHanoi(int discs) {
    return std::pow(2, discs) - 1;
}

int main(){
    std::cout << towerHanoi(5) << " = 31" << std::endl;
    return 0;
}