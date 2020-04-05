/*
Write a function that reverses a string. Make your function recursive.

Examples:

reverse("hello") ➞ "olleh"

reverse("world") ➞ "dlrow"

reverse("a") ➞ "a"

reverse("") ➞ ""

Notes

    For non-base cases, your function must call itself at least once.
    Check the Resources tab for info on recursion.

*/

#include <iostream>
#include <string>

using namespace std;

std::string reverse(std::string str);

std::string reverse(std::string str) {
    if (str.length() == 1) {
        return str;
    }
    string temp {""}; 
    temp += str.back();
    str.pop_back();
    return temp + reverse(str);
}

int main() {
    cout << reverse("world") << "\n";
    return 0;
}
