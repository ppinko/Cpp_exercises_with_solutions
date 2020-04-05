/*
https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search
*/

#include <vector>
#include <unordered_map>
#include <iostream>

void whatFlavors(std::vector<int> cost, int money) {
    int x1, x2;
    std::unordered_map<int, int> umap {};
    for (int i {0}; i < cost.size(); i++){
        auto it = umap.find(money - cost[i]); 
        if (it != umap.end()){
            x1 = it->second + 1;
            x2 = i+1;
            break;
        }
        else
            umap.emplace(cost[i], i);
    }
    std::cout << x1 << " " << x2 << "\n";
}

int main(){
    std::vector<int> vec {1, 4, 5, 3, 2};
    int money {4};
    std::vector<int> vec2 {2, 2, 4, 3};
    int money2 {4};   
    whatFlavors(vec, money);
    whatFlavors(vec2, money2);
    return 0;
}