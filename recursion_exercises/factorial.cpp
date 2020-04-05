/*
Write a function that calculates the factorial of a number recursively.

Examples

factorial(5) ➞ 120

factorial(3) ➞ 6

factorial(1) ➞ 1

factorial(0) ➞ 1

*/

#include <iostream>

int factorial(int n) {
    if (n ==0 || n == 1)
        return 1;
    else 
        return n * factorial(n-1);
}

int main() {
    std::cout << factorial(6) << "\n";
    return 0;
}