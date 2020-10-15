// https://edabit.com/challenge/Kekh6Jf8gKzD4abWk

#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
    vector<vector<char>> phone_letters {{'a', 'b', 'c'}, {'d', 'e', 'f'},
        {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    vector<string> actual, answer;
    actual.push_back("");
    for (int i = 0; i < digits.size(); ++i){
    int button = static_cast<int>(digits.at(i)) - (int)'0';
    button -= 2;
    for (auto str : actual){
        for (auto c : phone_letters.at(button)){
            string tempy {str};
            tempy.push_back(c);
            answer.push_back(tempy);    
        }
    }
    actual = answer;
    answer.clear();
    }
    return actual;
}

int main(int argc, char** argv){

    cout << "success" << endl;
    return 0;
}