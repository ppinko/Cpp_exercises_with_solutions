#include <vector>
#include <set>
#include <algorithm>

std::vector<std::vector<int>> multiplicity(std::vector<int> arr) {
	std::vector<std::vector<int>> result {};
    std::set<int> unique_numbers {};
    for (int i = 0; i < arr.size(); ++i)
    {
        auto set_test = unique_numbers.insert(arr.at(i));
        if (set_test.second == true)
        {
            std::vector<int> temp {};
            temp.push_back(arr.at(i));
            temp.push_back(std::count(arr.begin(), arr.end(), arr.at(i)));
            result.push_back(temp);
        }
    }
    return result;
}