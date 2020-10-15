// https://edabit.com/challenge/CEsNg38svzLP4iG8E

#include <iostream>
#include <cassert>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

string isValid(string str) {
    map<char, int> m {};
    for (auto &c : str){
        if (isalpha(c)){
            c = tolower(c);
            m[c] += 1;
        }
    }

    vector<int> nums {};
    for (auto it = m.begin(); it != m.end(); ++it){
        nums.push_back(it->second);
    }    

    map<int, int> f {};
    for (auto &c : nums)
            f[c] += 1;

    if (f.size() > 2)
        return "NO";
    else if (f.size() == 1){
        return "YES";
    }
    else {
        auto it = f.begin();
        auto it2 = next(it);
        if (it->second > 1 && it2->second > 1)
            return "NO";
        if (it->second == 1){
            if (it->first == 1 || it->first - it2->first == 1){
                return "YES";
            }
        }
        if (it2->second == 1){
            if (it2->first == 1 || it2->first - it->first == 1){
                return "YES";  
            }      
        }
    }
    return "NO";
}

int main(int argc, char** argv){

	assert((isValid("aabbccddeefghi") == "NO"));
	assert((isValid("aabbcd") == "NO"));
	assert((isValid("abcdefghhgfedecba") == "YES"));
	assert((isValid("abc") == "YES"));
	assert((isValid("abcc") == "YES"));
	assert((isValid("abccc") == "NO"));

    cout << "success" << endl;
    return 0;
}