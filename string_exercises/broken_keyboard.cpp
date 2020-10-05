// https://edabit.com/challenge/HBa85u8WfGSNfyWrf

#include <iostream>
#include <cassert>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> findBrokenKeys(const string &str1, const string &str2) {
	vector<string> solution {};
    for (auto it1 = begin(str1), it2 = begin(str2); it1 != end(str1); ++it1, ++it2){
        if (*it1 != * it2){
            char c = *it1;
            string temp {};
            temp += c;
            if (find(solution.begin(), solution.end(), temp) == solution.end()){
                solution.push_back(temp);
            }
        }
    }
    return solution;
}

int main(){

    cout << "success" << endl;

    return 0;
}