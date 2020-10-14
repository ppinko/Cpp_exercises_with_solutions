// https://edabit.com/challenge/E4MGaMxB9zGdSDdne



#include <cassert>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

bool coinsDiv(const vector<int> &arr) {
    // commonly used variable
    int s = arr.size();

    // quick elimination of impossible variations
	int sum = accumulate(arr.cbegin(), arr.cend(), 0);
    if (s < 3 || sum % 3 != 0 || any_of(arr.cbegin(), arr.cend(), 
            [sum](int a){return a > sum/3;}))
        return false;

    // factorial algorithm
    vector<int> cp {arr};
    vector<int> start {cp};
    sort(cp.begin(), cp.end(), [](int a, int b){return a > b;});
    do {
        int total = 0;
        bool success = true;
        for (const auto c : cp){
            total += c;
            if (total == sum/3){
                total = 0;
                continue;
            }
            else if (total > sum/3){
                total = 0;
                next_permutation(cp.begin(), cp.end());
                success = false;
                break;
            }
        }
        if (total != 0){
            next_permutation(cp.begin(), cp.end());
            success = false;
        }
        if (success)
            return true;
    } while (cp != start);
    return false;    
}

int main(){

{
	assert((coinsDiv({1, 1, 1}) == true));
	assert((coinsDiv({80, 78, 79, 65, 61}) == false));
	assert((coinsDiv({1, 1, 1}) == true));
	assert((coinsDiv({80, 78, 79, 65, 61}) == false));
	assert((coinsDiv({1, 2, 3, 2, 2, 2, 3}) == true));
	assert((coinsDiv({5, 3, 10, 1, 2}) == false));
	assert((coinsDiv({2, 4, 3, 2, 4, 9, 7, 8, 6, 9}) == true));
	assert((coinsDiv({4, 7, 6, 8, 2, 1, 2}) == true));
	assert((coinsDiv({3, 6, 2, 2, 2, 2, 1, 3, 2, 1, 3}) == true));
	assert((coinsDiv({11, 9, 3, 22, 6, 2, 4, 10, 1}) == false));
	assert((coinsDiv({13, 6, 12, 23, 2, 8, 15, 31, 16}) == false));
	assert((coinsDiv({4, 14, 12, 21, 3, 1, 18, 5}) == true));
	assert((coinsDiv({10, 5, 20, 27, 17, 4, 3, 15, 0, 25}) == true));
	assert((coinsDiv({7, 3, 3, 4, 5, 4, 1, 1, 1, 1, 1, 8, 7, 3, 3, 4, 5, 4, 1, 1, 1, 1, 1, 8}) == true));
	assert((coinsDiv({1, 13, 10, 6, 24, 16, 22, 4}) == false));
	assert((coinsDiv({9}) == false));
	assert((coinsDiv({246, 96, 129, 220, 203, 75, 200, 77, 114, 91}) == false));
	assert((coinsDiv({3, 2, 2, 5, 9, 3, 3}) == true));
};

    cout << "Success" << endl;

    return 0;
};