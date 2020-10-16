// https://edabit.com/challenge/neXwYQ5y7RSxkNfTe
#include <iostream>

#include <string>
#include <vector>
#include <cctype>
#include <set>
#include <climits>
#include <cmath>

using namespace std;

bool isVowel(char c){
    set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    return (vowels.find(c) != vowels.end());
}

int rightVowel(string str){
    int counter = 0;
    for (const auto &c : str){
        ++counter;
        if (isVowel(c))
            return counter;
    }
    return INT_MAX;
}  

vector<int> distanceToNearestVowel(string str){
    vector<int> answer {};
    int len = str.size();
    for (int i = 0; i < len; ++i){
        if (isVowel(str.at(i)))
            answer.push_back(0);
        else if (i == 0)
            answer.push_back(rightVowel(str.substr(i+1, len-i-1)));
        else if (i == len - 1)
            answer.push_back(answer.at(i-1) + 1);
        else {
            int lower = min(answer.at(i-1) + 1, rightVowel(str.substr(i+1, len-i-1)));
            answer.push_back(lower);
        }
    }
}

int main(){
    cout << "END" << endl;
}