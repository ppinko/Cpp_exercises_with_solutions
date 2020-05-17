/*
https://edabit.com/challenge/KNMDxnbSFiw9QuKwj

Mangle the String

Create a function that takes a string and replaces every letter with
the letter following it in the alphabet ("c" becomes "d", "z" becomes
"a", "b" becomes "c", etc). Then capitalize every vowel (a, e, i, o, u)
and return the new modified string.

Examples:

mangle("Fun times!") ➞ "GvO Ujnft!"
mangle("The quick brown fox.") ➞ "UIf rvjdl cspxO gpy."
mangle("Omega") ➞ "Pnfhb"
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>
#include <algorithm>

std::string mangle(std::string str) {
    std::vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
    std::string ans {};
    for (int i (0); i < str.length(); i++){
        char k = str[i] + 1;
        if (std::isalpha(str[i])){
            if (str[i] == 'Z' || str[i] == 'z') ans.push_back('A');
            else {
                if (std::count(vowels.begin(), vowels.end(), k) == 1)
                    ans.push_back(std::toupper(k));
                else ans.push_back(k);
            }
        }
        else ans.push_back(str[i]);
    }
	return ans;
}


int main(){
    std::cout << std::boolalpha;
    std::cout << mangle("Fun times!") << std::endl;
    std::cout << mangle("The quick brown fox.") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}