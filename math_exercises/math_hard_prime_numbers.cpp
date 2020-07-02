// https://edabit.com/challenge/Ba4vZuzC7b2Zr6SPs

#include <iostream>
#include <cassert>
#include <vector>

int primeNumbers(int num) {
	if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num == 3) return 2;
    std::vector<int> primes {2, 3};
    int i {5};
    while (i <= num){
        bool flag = true;
        for (int j: primes){
            if (i % j == 0){
                flag = false;
                break;
            }
        }
        if (flag) primes.push_back(i);
        i++;
    }
    return primes.size();
}

int main(){
    assert((primeNumbers(10) == 4));
    assert((primeNumbers(20) == 8));
    assert((primeNumbers(30) == 10));
    std::cout << "Success" << std::endl;
    return 0;
}