// https://edabit.com/challenge/uTrD4rPcfSdPerSGr

#include <vector>
#include <algorithm>

bool validateSubsets(std::vector<std::vector<int>> subsets, std::vector<int> set) {
	std::sort(set.begin(), set.end());
    std::for_each(subsets.begin(), subsets.end(), [](std::vector<int> &v)
        {std::sort(v.begin(), v.end());});
    return std::all_of(subsets.begin(), subsets.end(), [&set](std::vector<int> &v)
        {return std::includes(set.begin(), set.end(), v.begin(), v.end());});
}

int main(){
    return 0;
}