/*
https://edabit.com/challenge/rgZmbyYh2MSHTX3K6
*/


#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <iterator>
#include <algorithm>


std::vector<int> replaceNextLargest(std::vector<int> arr) {
    std::vector<int> sortedArr {};
    std::copy(arr.begin(), arr.end(), std::back_inserter(sortedArr));
    std::sort(sortedArr.begin(), sortedArr.end());
    std::vector<int> answer {};
    for (auto i: arr){
        auto it = std::find(sortedArr.begin(), sortedArr.end(), i);
        if (it == sortedArr.end() - 1) {
            answer.push_back(-1);
            std::cout << "YEAP" << std::endl;
        }
        else {
            it++;
            answer.push_back(*it);
        }
    }
    return answer;
}


int main(){
    std::vector<int> vec1 {5, 7, 3, 2, 8};
    auto vec2 = replaceNextLargest(vec1);
    for (auto i: vec2){
        std::cout << i << " ";
    }
    std::cout << "Success" << std::endl;
    return 0;
}