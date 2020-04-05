/*
Hole Number Sequence

What do the digits 0, 4, 6, 8, and 9 have in common? Well, they are whole numbers... and they are also hole numbers (not actually a thing until now). Hole numbers are numbers with holes in their shapes (8 is special in that it contains two holes).

14 is a hole number with one hole. 88 is a hole number with four holes.

Your task is to create a function with argument N that returns the sum of the holes for the integers n in the range of range 0 < n <= N.

To illustrate, sumOfHoles(14) returns 7, because there are 7 holes in 4, 6, 8, 9, 10 and 14.

Examples:

sumOfHoles(4) ➞ 1

sumOfHoles(6) ➞ 2

sumOfHoles(8) ➞ 4

sumOfHoles(6259) ➞ 12345

Notes

    All test cases are positive real integers.
    Don't forget that 8 has two holes.
*/

#include <iostream>
#include <string>

using namespace std;

    int sumOfHoles(int N) {
        if (N == 1)
            return 0;
        std::string temp = std::to_string(N);
        int counter {0};
        for (auto letter: temp) {
            if (letter == '0' || letter == '4' || letter == '6' || letter == '9')
                counter++;
            else if (letter == '8')
                counter += 2;
        }
        return counter + sumOfHoles(N-1);
    }

int main() {
    cout << sumOfHoles(8) << "\n";
    return 0;
}