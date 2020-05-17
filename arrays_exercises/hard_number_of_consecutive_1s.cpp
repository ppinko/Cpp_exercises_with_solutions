/*
https://edabit.com/challenge/yHWYC7qrCCHAqNpdM

Number of Two or More Consecutive Ones

Create a function that counts the number of blocks of two or more adjacent 1s in an array.

countOnes([1, 0, 0, 1, 1, 0, 1, 1, 1]) ➞ 2
// Two instances: [1, 1] (middle) and [1, 1, 1] (end)
countOnes([1, 0, 1, 0, 1, 0, 1, 0]) ➞ 0
countOnes([1, 1, 1, 1, 0, 0, 0, 0]) ➞ 1
countOnes([0, 0, 0]) ➞ 0
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>

int countOnes(std::vector<int> arr) {
    bool flag_one = true;
    bool flag_add = true;
    int n = 0;
    for (int i (0); i < arr.size(); i++){
        if (i == 0 and arr[i] == 1) flag_one = true;
        else if (i == 0 and arr[i] == 0) flag_one = false;
        else if ((flag_one) && arr[i] == 1){
            if (flag_add){
                flag_add = false;
                n += 1;
            }
        }
        else if (arr[i] == 1) flag_one = true;
        else {
            flag_one = false;
            flag_add = true;
        }
    }
    return n;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << countOnes({1, 0, 1, 0, 1, 0, 1, 0}) << std::endl;
    std::cout << countOnes({1, 0, 0, 1, 1, 0, 1, 1, 1}) << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}