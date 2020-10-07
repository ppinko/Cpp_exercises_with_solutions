// https://edabit.com/challenge/jXAutCihEANSFJdCj

#include <cassert>
#include <iostream>

#include <vector>

using namespace std;

int nDifferences(vector<int> arr) {
	decltype(arr) sub_array {};
    while (arr.size() != 1){
        for (int i = 0; i < arr.size() - 1; ++i)
            sub_array.push_back(arr.at(i+1) - arr.at(i));
        arr = sub_array;
        sub_array.clear();
    }
    return arr.at(0);
}

int main(){

    cout << "Success" << endl;

    return 0;
};