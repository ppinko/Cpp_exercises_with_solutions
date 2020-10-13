#include <iostream>
#include <cassert>

#include <vector>
#include <algorithm>

using namespace std;

int cycleLength(vector<int> arr, int n) {
	int counter = 0;
    decltype(arr) sorted_arr {arr};
    sort(sorted_arr.begin(), sorted_arr.end());
    auto it_sorted = find(sorted_arr.begin(), sorted_arr.end(), n);
    int pos_sorted = it_sorted - sorted_arr.begin();
    auto it_original = find(arr.begin(), arr.end(), n);
    int pos_original = it_original - arr.begin();
    
    if (pos_original == pos_sorted){
        return counter;
    }

    int i = pos_sorted;
    while (true){
        ++counter;
        auto it = find(arr.begin(), arr.end(), sorted_arr.at(i));
        iter_swap(it, arr.begin() + i);
        int a = it - arr.begin();
        if (arr.at(a) == sorted_arr.at(a))
            return counter;
        else {
            i = a;
        }
    }
    return counter;
}

int main() {

	assert((cycleLength({1, 5, 4, 3, 2, 6}, 4) ==  1));
	assert((cycleLength({1, 5, 4, 3, 2, 6}, 6) ==  0));
	assert((cycleLength({1, 5, 4, 3, 2, 6}, 5) ==  1));
	assert((cycleLength({1, 4, 2, 3, 5}, 4) ==  2));
	assert((cycleLength({11, 44, 22, 31, 50}, 44) ==  2));
	assert((cycleLength({1, 6, 7, 2, 4, 3, 8, 9, 5}, 7) ==  7));
	assert((cycleLength({43, 81, 88, 93, 17, 32, 19, 11}, 93) ==  5));
	assert((cycleLength({1, 6, 7, 2, 4, 3, 8, 9, 5}, 1) ==  0));
	assert((cycleLength({1, 6, 7, 2, 4, 3, 9, 8, 5}, 6) ==  6));
	assert((cycleLength({1, 6, 7, 2, 4, 3, 9, 8, 5}, 5) ==  6));
	assert((cycleLength({1, 6, 7, 2, 4, 3, 9, 8, 5}, 2) ==  6));
	assert((cycleLength({1, 6, 7, 2, 4, 3, 9, 8, 5}, 3) ==  6));

    cout << "success" << endl;

    return 0;
}