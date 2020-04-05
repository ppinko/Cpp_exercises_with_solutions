/*
Write a function that returns the number of ways a person can climb n stairs, where the person may only climb 1 or 2 steps at a time.

To illustrate, if n = 4 there are 5 ways to climb:

[1, 1, 1, 1]
[2, 1, 1]
[1, 2, 1]
[1, 1, 2]
[2, 2]

Examples

waysToClimb(1) ➞ 1

waysToClimb(2) ➞ 2

waysToClimb(5) ➞ 8

Notes

A staircase of height 0 should return 1.

*/

#include <iostream>
#include <string>

int waysToClimb(int n) {
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else
        return waysToClimb(n-1) + waysToClimb(n-2);
}

int main() {
    std::cout << waysToClimb(1) << "\n";
    std::cout << waysToClimb(2) << "\n";
    std::cout << waysToClimb(5) << "\n";
    return 0;
}