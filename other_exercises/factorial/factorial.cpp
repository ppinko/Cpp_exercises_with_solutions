/*
Napisz silnię dwoma sposobami
*/

#include <iostream>

int factorial_rec(int n){
    if (n == 1)
        return 1;
    return n * factorial_rec(n-1);
}

int factorial_linear(int n){
    int ans {1};
    if (n == 1)
        return 1;
    while(n > 1){
        ans *= n;
        n--;
    }
    return ans;
}

int main(){
    std::cout << factorial_rec(5) << std::endl;
    std::cout << factorial_linear(5) << std::endl;
    return 0;
}