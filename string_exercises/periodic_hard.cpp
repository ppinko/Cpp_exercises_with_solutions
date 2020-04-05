/*
https://edabit.com/challenge/XszrQMmEbnWA6ve8b
*/

#include <iostream>
#include <cmath>
#include <set>

int periodic(int n);
int int_length(int n);
int sum_digits(int n);

int periodic(int n) {
    if (n < 10)
        return 1;
	std::set<int> s1 {};
    int cycle {0};
    auto it = s1.find(n);
    int k, l, m;
    k = int_length(n);

    while (true){
        if (it != s1.end())
            return cycle;
        else {
            // std::cout << "n = " << n << std::endl;
            s1.insert(n);
            l = sum_digits(n);
            m = int_length(l);
            n = n * (std::pow(10, m)) + l;
            // std::cout << "n2 = " << n << std::endl;
            int div = std::pow(10, k);
            n = n % div;
            // std::cout << "n3 = " << n << std::endl;
            it = s1.find(n);
            cycle++;
        }
    }
}

int int_length(int n) {
    if (n < 10 && n >= 0)
        return 1;
    int k {2};
    int s = n / std::pow(10, k);
    while (s != 0){
        k++;
        s = n / std::pow(10, k);
    }
    return k;
}

int sum_digits(int n){
    int k = int_length(n);
    int i {1};
    int sum_dig {0};
    int remainder {};
    float temp {};
    int temp2 {};
    while (k > 0){
        if (k == 1){
            remainder += n;
            break;
        }
        temp = n / 10.0;
        // std::cout << "Initial temp = " << temp << std::endl;
        n /= 10;
        temp = 10 * (temp - int(temp));
        // std::cout << "temp to add = " << temp << std::endl;
        remainder += int(std::round(temp));
        // std::cout << "remainder = " << remainder << std::endl;
        k--;
    }
    return remainder;
}

int main(){

    // std::cout << int_length(1) << " : 1 " << std::endl;
    // std::cout << int_length(3061) << " : 4 " << std::endl;
    // std::cout << int_length(102468) << " : 6 " << std::endl;

    // std::cout << sum_digits(1) << " : 1 " << std::endl;
    // std::cout << sum_digits(3061) << " : 10 " << std::endl;
    // std::cout << sum_digits(102468) << " : 21 " << std::endl;

    // std::cout << periodic(1) << " : 1 " << std::endl;
    // std::cout << periodic(3061) << " : 7 " << std::endl;
    // std::cout << periodic("02468") << " : 178 " << std::endl;
    std::cout << periodic(314159265) << " : 12210 " << std::endl;
    return 0;
}