/*
https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
*/

#include <iostream>
#include <vector>

int divisibleSumPairs(int n, int k, std::vector<int> ar) {
    int res {0};
    int j {0};
    for (int i {0}; i < n; i++){
        j = i + 1;
        for (j; j < n; j++){
            if ((ar[i] + ar[j]) % k == 0)
                res++;
        }
    }
    return res;
}

int main(){
    std::vector<int> arr {1, 3, 2, 6, 1, 2};
    std::cout << divisibleSumPairs(6, 3, arr) << std::endl;
    return 0;
}