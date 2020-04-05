#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <set>

// using STL functions

// int main() 
// {
//     // remove duplicate elements
//     std::vector<int> v{1,2,3,1,2,3,3,4,5,4,5,6,7};
//     std::sort(v.begin(), v.end()); // 1 1 2 2 3 3 3 4 4 5 5 6 7 
//     auto last = std::unique(v.begin(), v.end());
//     // v now holds {1 2 3 4 5 6 7 x x x x x x}, where 'x' is indeterminate
//     // v.erase(last, v.end()); 
//     for (int i : v)
//       std::cout << i << " ";
//     std::cout << "\n";
// }

int main() 
{
    // remove duplicate elements
    std::vector<int> v{1,2,3,1,2,3,3,4,5,4,5,6,7};
    std::set<int> set_int {};
    std::vector<int> v2{};
    for (auto element : v){
        auto it = set_int.insert(element);
        if (it.second == true)
            v2.push_back(element);
    }
    for (int i : v2)
      std::cout << i << " ";
    std::cout << "\n";
}