// https://edabit.com/challenge/WtfjhA6dydKSERz6G

#include <iostream>
#include <cassert>
#include <algorithm>
#include <deque>
#include <cmath>

long long nextNumber(long long num) {
    if (num <= 11) return num;
    long long copy_num {num};
    std::deque<int> d {};
    while (num > 0){
        d.push_front(num % 10);
        num /= 10;
    }
    std::next_permutation(d.begin(), d.end());
    long long result = 0;
    int j = 0;
    for (auto it = d.rbegin(); it != d.rend(); it++, j++){
        result += *it * std::pow(10, j);
    }
    if (result < copy_num) return copy_num;
    return result;
}


int main(){
    assert((nextNumber(7) == 7));
	assert((nextNumber(19) == 91));
	assert((nextNumber(217) == 271));
	assert((nextNumber(899) == 989));

    std::cout << "Success" << std::endl;
    return 0;
}