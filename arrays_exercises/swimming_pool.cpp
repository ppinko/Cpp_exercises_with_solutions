// https://edabit.com/challenge/kWN7cQZ89qw5oHN3T

#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

bool isLegitimate(vector<vector<int>> arr) {
	for (int row = 0; row < arr.size(); ++row){
        if (row == 0 || row == arr.size() - 1){
            for (const auto &num : arr.at(row)){
                if (num == 1)
                    return false;
            }
        } else {
            if (arr.at(row).at(0) == 1 || arr.at(row).at(arr.at(0).size() - 1) == 1){
                return false;
            }
        }
    }
    return true;
}

int main(){

    assert((isLegitimate({
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}}) == true));

    cout << "success" << endl;

    return 0;
}