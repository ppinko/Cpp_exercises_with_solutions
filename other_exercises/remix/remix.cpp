#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

std::string remix(std::string str, std::vector<int> arr) {
    std::string ans(str.length(), '-');
    for (int i {0}; i < str.length(); i++)
        ans[arr[i]] = str[i];
    return ans;
}

int main(){
    std::vector<int> v {0, 2, 1, 5, 3, 6, 7, 4};
    std::cout << " " << std::endl;
    std::cout << remix("computer", v) << std::endl;
    return 0;
}