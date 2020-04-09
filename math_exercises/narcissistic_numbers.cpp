/*
https://edabit.com/challenge/N9iMsJgiDTpqnrd5q
*/

#include <iostream>
#include <vector>
#include <cmath>

bool isNarcissistic(int n) {
    int comp = n;
    int res {0};
    int count {0};
    std::vector<int> v {};
    while (n != 0){
        v.push_back(n % 10);
        n /= 10;
        count++;
    }
    for (int i : v){
        res += std::pow(i, count);
    }
    if (res == comp)
        return true;
    return false;
}

int main(){
    std::cout << (isNarcissistic(8208) == true) << std::endl;
    std::cout << (isNarcissistic(22) == false) << std::endl;
    return 0;
}