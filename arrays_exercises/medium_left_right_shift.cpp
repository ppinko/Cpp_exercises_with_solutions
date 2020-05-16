/*
https://edabit.com/challenge/zy9WuhejfNrQrgJti

Left, Right Shift

Create two functions: a left-shift function and a right-shift function. 
Each function will take in an array and a single parameter: the number of shifts.

[1, 2, 3, 4, 5]

[2, 3, 4, 5, 1]  // left shift of 1
[5, 1, 2, 3, 4]  // left shift of 4

[5, 1, 2, 3, 4]  // right shift of 1
[3, 4, 5, 1, 2]  // right shift of 3
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::vector<int> leftShift(std::vector<int> arr, int num) {
	if (num == 0 || num % arr.size() == 0)
        return arr;
    else {
        int k = static_cast<int>(num % arr.size());
        std::vector<int> ans {};
        for (int i = k; i < arr.size(); i++)
            ans.push_back(arr[i]);
        for (int i = 0; i < k; i++)
            ans.push_back(arr[i]);
        return ans;
    }
}

std::vector<int> rightShift(std::vector<int> arr, int num) {
	if (num == 0 || num % arr.size() == 0)
        return arr;	
    else {
        int k = static_cast<int>(num % arr.size());
        std::vector<int> ans {};
        for (int i = arr.size() - k; i < arr.size(); i++)
            ans.push_back(arr[i]);
        for (int i = 0; i < arr.size() - k; i++)
            ans.push_back(arr[i]);
        return ans;
    }
}

// Alernative solution

std::vector<int> leftShift2(std::vector<int> arr, int num) {
	int shift = num % arr.size();
	std::rotate(arr.begin(), arr.begin() + shift , arr.end());
    return arr;
}

std::vector<int> rightShift2(std::vector<int> arr, int num) {
	int shift = num % arr.size();
	std::rotate(arr.begin(), arr.begin() - shift , arr.end());
    return arr;
}

int main(){
    return 0;
}