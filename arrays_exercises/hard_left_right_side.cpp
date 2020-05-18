/*
https://edabit.com/challenge/bW5PnsDyuLBz9QeyW

Left Side, Right Side

Create two functions:

    Leftside function: Returns count of numbers strictly smaller than n on the left.
    Rightside function: Returns count of numbers strictly smaller than n on the right.

Examples:

leftSide([5, 2, 1, 4, 8, 7]) ➞ [0, 0, 0, 2, 4, 4]
rightSide([5, 2, 1, 4, 8, 7]) ➞ [3, 1, 0, 0, 1, 0]
leftSide([1, 2, 3, -1]) ➞ [0, 1, 2, 0]
rightSide([1, 2, 3, -1]) ➞ [1, 1, 1, 0]
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <algorithm>

std::vector<int> rightSide(std::vector<int> arr) {
    std::vector<int> ans {};
    int tot = 0;
    for (int i {0}; i < arr.size(); i++){
        if (i == arr.size() - 1) {
            ans.push_back(0);
            continue;
        }
        tot = 0;
        for (int j {i + 1}; j < arr.size(); j++){
            if (arr[i] > arr[j]) tot += 1;
        }
        ans.push_back(tot);
    }
    return ans;
}

std::vector<int> leftSide(std::vector<int> arr) {
    std::reverse(arr.begin(), arr.end());
    std::vector<int> ans = rightSide(arr);
    std::reverse(ans.begin(), arr.end());
    return ans;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << "Success" << std::endl;
    return 0;
}