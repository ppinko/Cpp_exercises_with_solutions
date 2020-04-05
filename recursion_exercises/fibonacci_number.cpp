/*
Create a function that, given a number, returns the corresponding Fibonacci number.

Examples:

fibonacci(3) ➞ 3

fibonacci(7) ➞ 21

fibonacci(12) ➞ 233

The first number in the sequence starts at 1 (not 0).

*/

#include <iostream>

int fibonacci(int num) {
	if (num == 1)
        return 1;
    else if (num == 2)
        return 2;
    else 
        return fibonacci(num-1) + fibonacci(num-2);
}

int main() {
    std::cout << fibonacci(3) << "\n";
    std::cout << fibonacci(7) << "\n";
    std::cout << fibonacci(21) << "\n";
    return 0;
}