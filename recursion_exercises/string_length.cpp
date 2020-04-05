/*
Write a function that returns the length of a string. Make your function recursive.

Examples:

length("apple") ➞ 5

length("make") ➞ 4

length("a") ➞ 1

length("") ➞ 0

*/

#include <iostream>
#include <string>

using namespace std;

using namespace std;

int length(std::string str) {
    if ( str.length() == 0) {
        return 0;
    }
    else {
        str.pop_back();
        return 1 + length(str);
    }
}

int main() {
    string word {"pawel"};
    cout << length(word) << endl;
    return 0;
}