// https://edabit.com/challenge/NhT8r8hw3tE83ntd2

#include <cassert>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool willFit(vector<string> holds, vector<int> cargo) {
	sort(cargo.begin(), cargo.end(), [](int a, int b){return a > b;});
    vector<int>capacity {};
    for (const auto &c : holds){
        if (c == "M")
            capacity.push_back(100);
        else if (c == "S")
            capacity.push_back(50);
        else
            capacity.push_back(200);
    }
    sort(capacity.begin(), capacity.end(), [](int a, int b){return a > b;});
    for (const auto &c : cargo){
        bool flag = false;
        for (int i = 0; i < capacity.size(); ++i){
            if (capacity.at(i) - c >= 0){
                flag = true;
                capacity.at(i) -= c;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}

int main(){

    cout << "Success" << endl;

    return 0;
};