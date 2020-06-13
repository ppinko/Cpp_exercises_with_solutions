/*
https://edabit.com/challenge/4zsrEYCxG8yA86E2C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::vector<int>> chunkify(std::vector<int> arr, int size) {
    std::vector<std::vector<int>> answer {};
    if (arr.size() < size){
        answer.push_back(arr);
        return answer;
    }
    for (std::vector<int>::iterator iter = arr.begin(); iter < arr.end(); iter += size){
        std::vector<int> temp {};
        if ((iter + size) < arr.end()) {
            std::copy(iter, iter + size, std::back_inserter(temp));
        }
        else {
            std::copy(iter, arr.end(), std::back_inserter(temp));
        }
        answer.push_back(temp);
    }
    return answer;
}

int main(){
    // std::vector<int> vec {2, 3, 4, 5, 6, 7};
    std::vector<int> vec {2, 3, 4, 5, 6, 7, 8};
    auto v = chunkify(vec, 3);
    for (auto i: v){
        for (auto j: i){
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Success" << std::endl;
    return 0;
}