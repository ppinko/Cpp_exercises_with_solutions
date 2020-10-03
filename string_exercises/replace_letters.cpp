// https://edabit.com/challenge/rZbXfisPPKbR6yNXn

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

string alphabetIndex(const string &str) {
    string converted {};
    for (const auto &c: str){
        if (isalpha(c)){
            converted.append(to_string((static_cast<int>(tolower(c))) - 96));
            converted.push_back(' ');
        }
    }
    converted.pop_back();
    return converted;
}


int main(int argc, char *argv[]){
    cout << alphabetIndex("Wow, does that work?") << endl;

    cout << int('a') << endl;

    return 0;
}