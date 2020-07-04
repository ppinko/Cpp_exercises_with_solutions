// https://edabit.com/challenge/EkfpmCrKNoMbahwt3

#include <iostream>
#include <cassert>
#include <vector>

long long int bonacci(int N, int k) {
	if (N == 1) return 1;
    std::vector<long long int> fibo (N-1, 0);
    fibo.push_back(1);
    fibo.push_back(1);
    if (fibo.size() >= k) return fibo.at(k-1);
    for (unsigned long i {fibo.size()}; i <= k; i++){
        long long temp = 0;
        int current_size = fibo.size();
        for (int j = 1; j <= N; j++){
            temp += fibo.at(current_size-j);
        }
        fibo.push_back(temp);
    }
    return fibo.at(k-1);
}

int main(){
    assert((bonacci(2, 7) == 8));
	assert((bonacci(3, 13) == 274));
	assert((bonacci(5, 24) == 203513));
	assert((bonacci(8, 44) == 32440904961));
	assert((bonacci(1, 4) == 1));
    std::cout << "Success" << std::endl;
    return 0;
}

