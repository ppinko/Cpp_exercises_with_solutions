/*
https://edabit.com/challenge/WDQmm8tmLp5zQY4Hq
*/

#include <iostream>

int pentagonal(int num) {
    if (num == 1) // base case
        return 1;
    return pentagonal(num-1) + 5 * (num-1);
}

int pentagonal2(int num) {
    int ans {0};
    while (num >= 1){
        if (num == 1)
            ans += 1;
        else
            ans += 5 * (num-1);
        num--;
    }
    return ans;
}

int main(){
    std::cout << pentagonal(3) << " = 16" << std::endl;
    std::cout << pentagonal2(8) << " = 141" << std::endl;
    return 0;
}