#include <string>
#include <algorithm>

bool isNew(int n) {
	std::string n_str = std::to_string(n);
    std::next_permutation(n_str.begin(), n_str.end(), [](char a, char b){return a > b;});
    int n_next_permutation = std::stoi(n_str);
    return n_next_permutation >= n || n_str.at(0) == '0';
}