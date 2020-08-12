// main script for checking if triangle is square

#include <vector>
#include <algorithm>
#include <cmath>

bool isSquareTriangle(int a, int b, int c)
{
    std::vector<int> v {a, b, c};
    std::sort(v.begin(), v.end());
    return (std::pow(v[0], 2) + std::pow(v[1], 2) == std::pow(v[2], 2));
}