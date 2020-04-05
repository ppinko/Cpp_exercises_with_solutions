#include <list>
#include <cmath>
#include <algorithm>
#include <iostream>

std::list<int> divisors(int n);
int phi(int n);
std::list<int> all_divisors(int n);

int phi(int n) {
    if (n == 1)
        return 1;
    std::list<int> ls = divisors(n);
    int counter = 0;
    std::list<int> ls2 {};
    std::list<int> com {};
    for (int j {1}; j < n; j++){
        ls2 = all_divisors(j);
        std::set_intersection(ls.begin(), ls.end(), ls2.begin(), ls2.end(), std::back_inserter(com));
        if (com.size() < 2)
            counter++;
        com.clear();
    }
    return counter;
}

std::list<int> divisors(int n){
    std::list<int> ls {1};
    int bound = std::floor(std::sqrt(n));
    if (n % 2 == 0)
        ls.push_back(2);
    int i = 3;
    while (i <= bound){
        if (n % i == 0)
            ls.push_back(i);
        i += 2;
    }
    return ls;
}

std::list<int> all_divisors(int n){
    std::list<int> ls {1};
    if (n % 2 == 0)
        ls.push_back(2);
    int i = 3;
    while (i <= n){
        if (n % i == 0)
            ls.push_back(i);
        i += 2;
    }
    return ls;
}

int main(){
    std::cout << phi(51) << " = 32" << std::endl;
    std::cout << phi(54) << " = 18" << std::endl;
    std::cout << phi(144) << " = 48" << std::endl;
    std::cout << phi(1000) << " = 400" << std::endl;
    return 0;
}