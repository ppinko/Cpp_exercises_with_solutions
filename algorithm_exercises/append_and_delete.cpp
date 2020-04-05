/*
https://www.hackerrank.com/challenges/append-and-delete/problem
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

std::string appendAndDelete(std::string s, std::string t, int k) {
    int same {0};
    int size_s1 = s.length();
    int size_s2 = t.length();
    for (int i {0}; i < size_s1; i++){
        if (s[i] == t[i])
            same += 1;
        else
            break;
    }
    int min_changes = size_s1 + size_s2 - 2 * same;
    if (k < min_changes || ( ((k - min_changes) % 2 == 1) && k < min_changes + 2 * same ))
        return "No";
    return "Yes";
}

int main(){
    std::string s1 {"abcd"};
    std::string s2 {"abcdert"};
    std::cout << std::boolalpha;
    std::cout << appendAndDelete(s1, s2, 10) << std::endl;
    std::cout << (appendAndDelete(s1, s2, 10) == "Yes") << std::endl;
    return 0;
}