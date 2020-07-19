// https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    
    int vec_length, num_queries, query, temp;
    std::vector<int> v {};

    std::cin >> vec_length;
    for (int i = 0; i < vec_length; ++i)
    {
        std::cin >> temp;
        v.push_back(temp);
    }

    std::cin >> num_queries;
    for (int i = 0; i < num_queries; ++i)
    {
        std::cin >> temp;
        auto it = std::lower_bound(v.begin(), v.end(), temp);
        int index = it - v.begin() + 1;
        if (*it == temp)
            std::cout << "Yes " << index << std::endl;
        else
            std::cout << "No " << index << std::endl;
    }
    return 0;
}