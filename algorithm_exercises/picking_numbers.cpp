/*
https://www.hackerrank.com/challenges/picking-numbers/problem
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

void display_map(std::map<int, int> mp){
    auto it = mp.begin();
    std::cout << "[ ";
    for (it; it != mp.end(); it++){
        std::cout << it->first << ":" << it->second << " ";
    }
    std::cout << "]\n"; 
}

int pickingNumbers(std::vector<int> a) {
    int res {0};
    int temp {};
    std::map<int, int> mp {};
    for (int &element : a){
        auto it = mp.find(element);
        if (it != mp.end())
            mp[element] += 1;
        else
            mp[element] = 1;
    }
    // display_map(mp);
    auto it2 = mp.begin();
    while (it2 != mp.end()){
        // std::cout << it2->first << " ~ " << it2->second << " - " << mp.count(it2->first + 1) << std::endl;
        temp += it2->second;
        if(mp.count(it2->first + 1) == 1)
            temp += mp[it2->first +1 ];
        if (temp > res){
            res = temp;
        }
        temp = 0;
        it2++;
    }
    return res;
}

int main(){
    std::vector<int> arr {1, 2, 2, 3, 1, 2};
    std::cout << std::boolalpha;
    std::cout << pickingNumbers(arr) << std::endl;
    std::cout << (pickingNumbers(arr) == 5) << std::endl;
    return 0;
}