// https://edabit.com/challenge/pc9bTjFFZ7BcShaDG

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

int findFulcrum(std::vector<int> arr) {
    int ans = -1;
    if (arr.size() >= 3)
        for (int i = 1; i < arr.size() - 1; ++i)
        {
            if (std::accumulate(arr.begin(), arr.begin() + i, 0) == std::accumulate(arr.begin() + i + 1, arr.end(), 0))
            {
                ans = arr.at(i);
                break;
            }
        }
    return ans;
}

int main()
{
	assert((findFulcrum({1, 2, 4, 9, 10, -10, -9, 3}) == 4));
    assert((findFulcrum({9, 1, 9}) == 1));
	assert((findFulcrum({7, -1, 0, -1, 1, 1, 2, 3}) == 0));
	assert((findFulcrum({8, 8, 8, 8}) == -1));
	assert((findFulcrum({9, 3, 4, 8, 1}) == -1));
	assert((findFulcrum({1, -1, 10, 5, -4, -1}) == 10));

    return 0;
}