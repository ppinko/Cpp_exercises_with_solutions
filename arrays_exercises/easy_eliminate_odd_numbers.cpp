/*
https://edabit.com/challenge/7iT6DbY3GsHnLBPq4
*/


#include <vector>
#include <iostream>


std::vector<int> noOdds(std::vector<int> arr) {
    std::vector<int> res {};
    int i {0};
    for (i; i < arr.size(); i++){
        if (arr[i] % 2 == 0)
            res.push_back(arr[i]);
    }
    return res;
}

int main(){
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    // std::cout << noOdds(arr) << std::endl;
    return 0;
}