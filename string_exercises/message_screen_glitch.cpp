// https://edabit.com/challenge/deLhcDjNRE2RRFzoz

#include <cassert>
#include <iostream>

#include <cctype>
#include <string>

using namespace std;

string messageGlitch(const string &txt) {
	string solution {}, temp {};
    for (const auto &c : txt){
        if (!isdigit(c) && !temp.empty()){
            int number = 96 + stoi(temp);
            solution.push_back(static_cast<char>(number));
            solution.push_back(c);
            temp.clear();
        }
        else if (!isdigit(c)){
            solution.push_back(c);
        }
        else {
            temp.push_back(c);
        }
    }
    if (!temp.empty()){
        int number = 96 + stoi(temp);
        solution.push_back(static_cast<char>(number));
    }
    return solution;
}

int main(){

    char c = 'a';
    cout << static_cast<int>(c) << endl;

    cout << "Success" << endl;

    return 0;
};