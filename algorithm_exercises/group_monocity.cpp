// https://edabit.com/challenge/kQ5RDqeTP3otjuKEt

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

using namespace std;

vector<int> groupMonotonic(vector<int> arr) {
    decltype(arr) result {};
    set<int> s {arr.begin(), arr.end()};
    if (s.size() <= 1){
        return result;
    }
    
    int i = 0;
    // finding starting direction - increasing or decreasing
    while (i != arr.size() - 1 && arr.at(i) == arr.at(i+1))
        ++i;
    ++i;
    bool flag_positive = (arr.at(i) > arr.at(0) ? true: false);

    // searching for peaks, both max & min
    while (i < arr.size() - 1){
        if (flag_positive && arr.at(i+1) < arr.at(i)){
            result.push_back(i);
            flag_positive = false;
        }
        else if (!flag_positive && arr.at(i+1) > arr.at(i)){
            result.push_back(i);
            flag_positive = true;
        }
        ++i;
    }
    return result;
}

int main(){
    vector<int> arr_1 {};
    vector<int> arr_2 {0};
    vector<int> arr_3 {0, 1};
    vector<int> arr_4 {0, 1, 0};
    groupMonotonic(arr_3);

    return 0;
}