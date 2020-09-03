// https://edabit.com/challenge/hTsL3mY96fpeTxqwD

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>

std::vector<std::vector<int>> allPairs(std::vector<int> arr, int target) {
    std::vector<std::vector<int>> result {};
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr.at(i) + arr.at(j) == target)
            {
                result.push_back({arr.at(i), arr.at(j)});
            }
        }
    }
    for (auto &v : result)
        std::sort(v.begin(), v.end());

    std::sort(result.begin(), result.end(),
        [](std::vector<int> v, std::vector<int> y){return v.at(0) < y.at(0);});
    
    return result;
}

int main(){
    std::vector<std::vector<int>> result = allPairs({2, 4, 5, 3}, 7);
    for (const auto &v : result)
    {
        std::cout << v.at(0) << " " << v.at(1) << std::endl;
    }
    // std::vector<std::vector<int>> result {{2, 5}, {3, 4}};
    // assert((allPairs({2, 4, 5, 3}, 7) == result));

    return 0;
}