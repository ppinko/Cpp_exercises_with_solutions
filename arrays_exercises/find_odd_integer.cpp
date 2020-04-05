/*
Create a function that takes an array and finds the integer which appears an odd number of times.

Examples

findOdd([1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5]) ➞ -1

findOdd([20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5]) ➞ 5

findOdd([10]) ➞ 10

Notes

There will always only be one integer that appears an odd number of times.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findOdd(vector<int> arr) {
    for (int element : arr) {
            int num = count(arr.begin(), arr.end(), element);
            if (num % 2 == 1)
                return element;
    }
}

int main(){
    cout << findOdd({20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5});
    return 0;
}
