// https://edabit.com/challenge/XHem2LWCF7LRu2ksu

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> leftRotations(std::string str) {
	std::vector<std::string> v {};
    v.push_back(str);
    for (int i = 0; i < str.size() - 1; ++i)
    {
        std::rotate(str.begin(), str.begin() + 1, str.end());
        v.push_back(str);
    }
    return v;
}

std::vector<std::string> rightRotations(std::string str) {
	std::vector<std::string> v {};
    v.push_back(str);
    for (int i = 0; i < str.size() - 1; ++i)
    {
        std::rotate(str.rbegin(), str.rbegin() + 1, str.rend());
        v.push_back(str);
    }
    return v;
}

int main()
{

    std::string str = "Pawel";
    std::vector<std::string> v = rightRotations(str);
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));

    return 0;
}