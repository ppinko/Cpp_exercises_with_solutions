// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem

#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    std::vector<int> v {};
    std::istringstream oss {str};
    int N = std::count(str.begin(), str.end(), ',');
    for (int i = 0; i <= N; ++i){
        int a; char c;
        if (i != N){
            oss >> a >> c;
        }
        else {
            oss >> a;
        }
        v.push_back(a);
    }
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}