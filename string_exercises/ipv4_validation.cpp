// https://edabit.com/challenge/vk3NibPRqsR2RquTM

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isValidIP(const string &str) {
	if (count(str.cbegin(), str.cend(), '.') != 3)
        return false;
    
    string temp {};
    for (const auto &c: str){
        if (isdigit(c))
            temp.push_back(c);
        else if (c == '.'){
            if (temp.size() > 1 && temp.at(0) == '0')
                return false;
            if (stoi(temp) < 0 || stoi(temp) > 255)
                return false;
            temp.clear();
        }
        else
            return false;
    }
    if (stoi(temp) < 0 || stoi(temp) > 255)
        return false;
    else
        return true;
}

int main(int argc, char *argv[]){

    cout << boolalpha;
    cout << isValidIP("0.232.47.227") << endl;

    return 0;
}