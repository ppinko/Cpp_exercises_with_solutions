/*
https://www.hackerrank.com/challenges/migratory-birds/problem
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>

int migratoryBirds(std::vector<int> arr) {
    std::unordered_map<int, int> umap {};
    for (int &element : arr){
        auto it = umap.find(element);
        if (it == umap.end())
            umap[element] = 1;
        else
            umap[element] += 1;
    }
    int ans {-1};
    int pos {-1};
    for (auto it2 {umap.begin()}; it2 != umap.end(); it2++){
        if (it2->second == ans && it2->first < pos)
            pos = it2->first;
        else if (it2->second > ans){
            pos = it2->first;
            ans = it2->second;
        }
    }
    return pos;
}

int main(){
    std::vector<int> vec {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};
    std::cout << migratoryBirds(vec) << std::endl;
    return 0;
}