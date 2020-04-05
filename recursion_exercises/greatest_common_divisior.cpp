/*

Write a function that calculates the GCD (Greatest Common Divisor) of two numbers recursively.

Examples:

gcd(10, 20) ➞ 10

gcd(1, 3) ➞ 1

gcd(5, 7) ➞ 1

gcd(2, 6) ➞ 2

*/

#include <iostream>

int gcd(int a, int b);

int gcd(int a, int b) {
	if ( a == b)
        return a;

    int max_num {0};
    int min_num {0};
    if (a > b) {
        max_num = a;
        min_num = b;
    }
    else {
        max_num = b;
        min_num = a;
    }
    while (min_num >= 1) {
        if (min_num == 1)
            return min_num;
        else if ( a % min_num == 0 && b % min_num == 0)
            return min_num;
        --min_num;
    }
    return 1;
}

int main() {
    std::cout << gcd(10, 20) << "\n";
    std::cout << gcd(100, 8) << "\n";
    return 0;
}
