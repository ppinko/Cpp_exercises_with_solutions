// https://edabit.com/challenge/CMFyi8tgCucNSoRo7

#include <cassert>
#include <iostream>
#include <cmath>
#include <iomanip>

bool is_prime(long long n){
    if (n <= 1) return false;
    long long i = 2;
    while (i < n){
        if (n % i == 0) return false;
        i++;
    }
    return true;
}

bool isExactlyThree(long long n) {
	float m = std::pow(n, 0.5);
    if (std::ceil(m) != std::floor(m)) return false;
    long long k = (long long)m;
    return is_prime(k);
}

int main(){
    std::cout << std::boolalpha << std::endl;
    // std::cout << isExactlyThree(5) << std::endl;
    assert((isExactlyThree(4) == true));
    assert((isExactlyThree(12) == false));
    assert((isExactlyThree(25) == true));
    std::cout << "Success" << std::endl;
    return 0;
}