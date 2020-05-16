/*
https://edabit.com/challenge/wvEELKb9nawzRSucg

Sort Numbers in Ascending Order

Create a function that takes an array of numbers and returns a new array, sorted in ascending order (smallest to biggest).

    Sort numbers array in ascending order.
    If the function's argument is null, an empty array, or undefined; return an empty array.
    Return a new array of sorted numbers.
*/


#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> sortNumsAscending(std::vector<int> arr) {
	std::sort(arr.begin(), arr.end());
    return arr;
}


int main(){
    return 0;
}


