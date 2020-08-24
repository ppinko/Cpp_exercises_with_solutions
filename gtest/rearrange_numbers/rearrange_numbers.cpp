#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>

int rearranged_difference(int n) {
	std::string s_max = std::to_string(n);
    std::string s_min = std::to_string(n);
    std::sort(s_min.begin(), s_min.end());
    std::sort(s_max.begin(), s_max.end(), [](char a, char b){return a > b;});
    int n_max = std::stoi(s_max);
    int n_min = std::stoi(s_min);
    return n_max - n_min;
}