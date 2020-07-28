// https://edabit.com/challenge/J5uja7eL2LzktEzKo

#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int josephus(int n, int i) {
    std::vector<int> soldiers (n, 0);
    std::iota(soldiers.begin(), soldiers.end(), 1);
    int index = -1;
    while (soldiers.size() != 1)
    {
        index += i;
        auto it = soldiers.begin();
        while (index >= soldiers.size())
        {
            index -= soldiers.size();    
        }
        soldiers.erase(it + index);
        index -= 1;
    }
    return soldiers.at(0);
}

int main()
{
    assert((josephus(41, 3) == 31));
	assert((josephus(14, 2) == 13));
	assert((josephus(35, 11) == 18));
	assert((josephus(20, 1) == 20));
	assert((josephus(15, 15) == 4));

    std::cout << "Success" << std::endl;
    return 0;
};