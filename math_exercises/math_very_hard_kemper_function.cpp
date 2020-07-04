// https://edabit.com/challenge/h4ru5X2MqBRWT7XJL

#include <iostream>
#include <cassert>

long long factorial(int n);
int kempner(int n);
bool is_prime(int n);

bool is_prime(int n){
    if (n <= 1) return false;
    else if (n == 2 || n == 3) return true;
    int i = 2;
    while (i < n){
        if (n % i == 0) return false;
        i++;
    }
    return true;
}

long long factorial(int n){
    long long ans = 1;
    while (n > 1){
        ans *= n;
        n--;
    }
    return ans;
}

int kempner(int n) {
    if (n > 0 && n <= 2) return n;
    else if (is_prime(n)) return n;
    int i = 3;
    while (i < n){
        if (factorial(i) % n == 0)
            return i;
        i++;
    }
    return n;
}

int main(){
    assert((kempner(6) == 3));
	assert((kempner(10) == 5));
	assert((kempner(2) == 2));
	assert((kempner(21) == 7));
	assert((kempner(1) == 1));
	assert((kempner(4) == 4));
    assert((kempner(13) == 13));
    std::cout << "Success" << std::endl;
    return 0;
}