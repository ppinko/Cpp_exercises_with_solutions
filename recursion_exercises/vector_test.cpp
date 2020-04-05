#include <vector>
#include <iostream>

int main(){
    std::vector<int> v1 {1, 2, 3};
    std::vector<int> v2 {3, 4, 5};
    auto v3 = v1;
    v3.insert(v3.end(), v2.begin(), v2.end());
    for (auto i : v3)
        std::cout << i << " ";
    return 0;
}