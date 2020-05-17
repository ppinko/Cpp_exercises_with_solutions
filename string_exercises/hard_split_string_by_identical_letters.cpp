/*
https://edabit.com/challenge/WxNaaCr5wRdebepwG

Split String by Identical Characters

Create a function that splits a string into an array of identical clusters.

Examples:

splitGroups("555") ➞ ["555"]

splitGroups("5556667788") ➞ ["555", "666", "77", "88"]

splitGroups("aaabbbaabbab") ➞ ["aaa", "bbb", "aa", "bb", "a", "b"]

splitGroups("abbbcc88999&&!!!_") ➞ ["a", "bbb", "cc", "88", "999", "&&", "!!!", "_"]

Notes

    Each cluster should only have one unique character.
    The resulting array should be in the same order as the input string.
    Should work with letters, numbers and other characters.

*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


std::vector<std::string> splitGroups(std::string s) {
	std::vector<std::string> ans {};
    std::string temp {};
    for (auto const& c : s){
        if (temp.empty() || temp.front() == c) temp += c;
        else {
            ans.push_back(temp);
            temp.clear();
            temp += c;
        }
    }
    ans.push_back(temp);
    return ans;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << "Success" << std::endl;
    return 0;
}