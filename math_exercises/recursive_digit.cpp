// https://edabit.com/challenge/cPu9k4bBimoKHc9zD

#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long super(long long n){
    long long total = 0;
    while (n != 0){
        total += n % 10;
        n /= 10;
    }
    return total;
}

int superDigit(string n, unsigned int k) {
    long long initial = 0;
    for (const auto &num :n){
        initial += int(num) - int('0');    
    }
    long long first = super(initial);
    first *= k;
    while (first >= 10){
        first = super(first);    
    }
    return first;
}

int main()
{
    cout << "END" << endl;
}