#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <memory>

bool is_prime(const int& n);
void primes_to_n(const int& n);

bool is_prime(const int& n){
    if (n == 2 || n==3) return true;
    else if (n < 5 || n % 2 == 0) return false;
    for (int i = 5; i < n; i += 2){
        if (n % i == 0)
            return false;
    }
    return true;
}

void primes_to_n(const int& n){
    auto u_ptr = std::make_unique<std::vector<int>>();
    int i = 2;
    while (i <= n){
        if (is_prime(i))
            u_ptr->push_back(i);
        ++i;
    }
    std::copy(u_ptr->cbegin(), u_ptr->cend(), std::ostream_iterator<int>(std::cout, " "));
}

int main(){
    int a = 100;
    primes_to_n(a);
    std::cout << std::endl;
    return 0;
}