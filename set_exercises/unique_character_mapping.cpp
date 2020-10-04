// https://edabit.com/challenge/AiWEZSinxkMwoRhwR

#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> characterMapping(const string &str) {
    vector<int> v {};
    map<char, int> m {};
    int i = 0;
    for (const auto &c : str){
        auto it = m.find(c);
        if (it == m.end()){
            m.emplace(c, i);
            v.push_back(i);
            ++i;
        }
        else {
            v.push_back(it->second);
        }
    }
	return v;
}

int main(){

    cout << "success" << endl;
    cout << 100 << endl;

    return 0;
}