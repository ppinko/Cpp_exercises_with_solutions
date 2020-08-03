// https://edabit.com/challenge/aQnur99HSdYbyypLd

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>

bool canPartition(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    if (std::count(arr.begin(), arr.end(), 0) > 1)
        return true;
    else if (std::accumulate(arr.begin() + 1, arr.end(), 1, std::multiplies<int>()) == arr.at(0))
        return true;
    else if (std::accumulate(arr.begin(), arr.end() - 1, 1, std::multiplies<int>()) == arr.at(arr.size()-1))
        return true;
	else
        return false;
}

int main()
{
    // // dot product test
    // std::vector<int> v {1, 2, 3, 4};
    // int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    // std::cout << product << std::endl;

	assert((canPartition({-1, -10, 1, -2, 20}) == false));
	assert((canPartition({-1, -20, 5, -1, -2, 2}) == true));
	assert((canPartition({2, 8, 4, 1}) == true));
	assert((canPartition({1, 1, -1, 1}) == false));
	assert((canPartition({-1, -1, 1, 1}) == true));
	assert((canPartition({0, 5, 1, -1}) == false));
	assert((canPartition({0, 1, 1, -1}) == false));
	assert((canPartition({0, 1, 1, 1}) == false));
	assert((canPartition({0, 0, 1, 1}) == true));
	assert((canPartition({0, 0, 1}) == true));
	assert((canPartition({0, 0, 0}) == true));
	assert((canPartition({5, 5, 25, 100}) == false));
	assert((canPartition({-1, 5, 20, 100}) == false));
	assert((canPartition({1, 1, 1, 1}) == true));
	assert((canPartition({-1, 1, -1}) == true));
	assert((canPartition({-1, 1, 1}) == false));

    return 0;
}