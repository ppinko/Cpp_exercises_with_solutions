/*
Write a function that takes an integer and returns a string with the given number of "a"s in Edabit.

Examples:

howManyTimes(5) ➞ "Edaaaaabit"

howManyTimes(0) ➞ "Edbit"

howManyTimes(12) ➞ "Edaaaaaaaaaaaabit"

Notes

    The string must start with "Ed" and end with "bit".
    You'll only be given integers as test input.

*/

#include <iostream>
#include <string>

using namespace std;

string howManyTimes(int num);
string help_func(int num, std::string temp);

string howManyTimes(int num) {
	string start {"Ed"};
    return help_func(num, start);
}

string help_func(int num, std::string start) {
    if (num == 0){
        return start += "bit";
    }
    else {
        start += "a";
        --num;
        return help_func(num, start);
    }
}

int main() {
    cout << howManyTimes(23) << endl;
    return 0;
}

// std::string howManyTimes(int num) {
// 	static string start {"Ed"};
//     if (num == 0){
//         return start += "bit";
//     }
//     else {
//         start += "a";
//         --num;
//         return howManyTimes(num);
//     }
// }

// int main() {
//     cout << howManyTimes(23) << endl;
//     return 0;
// }