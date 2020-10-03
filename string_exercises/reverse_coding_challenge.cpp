// https://edabit.com/challenge/gtdyy97TTDPWkei9d

#include <iostream>
#include <string>

using namespace std;

string mysteryFunc(const string &s) {
    string transformed {};
    for (int i = 0; i < s.size(); i += 2){
        string temp (static_cast<int>(s.at(i+1)) - 48, s.at(i));
        transformed.append(temp);
    }
    return transformed;
}

int main(int argc, char *argv[]){

    cout << (int)'1' << endl;
    cout << mysteryFunc("A4B5C2") << endl;

    return 0;
}