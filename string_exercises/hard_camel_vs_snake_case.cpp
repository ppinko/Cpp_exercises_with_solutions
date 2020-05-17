/*
https://edabit.com/challenge/mEEsMKznTCq25PWvD

camelCase ⇄ snake_case

Create two functions toCamelCase() and toSnakeCase() that each take a single
string and convert it into either camelCase or snake_case. If you're not
sure what these terms mean, check the Resources tab above.

Examples:

toCamelCase("hello_edabit") ➞ "helloEdabit"
toSnakeCase("helloEdabit") ➞ "hello_edabit"
toCamelCase("is_modal_open") ➞ "isModalOpen"
toSnakeCase("getColor") ➞ "get_color"

Notes

Test input will always be appropriately formatted as either camelCase or
snake_case, depending on the function being called.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>


std::string toSnakeCase(std::string str) {
    std::string ans {};
    for (auto c : str){
        if (std::isupper(c)) 
            ans.push_back('_');
        ans.push_back(std::tolower(c));
    }
    return ans;
}

std::string toCamelCase(std::string str) {
    std::string ans {};
    for (int i = 0; i < str.length(); i++){
        if (i != 0 && str[i-1] == '_')
            ans.push_back(std::toupper(str[i]));
        else if (std::islower(str[i]))
            ans.push_back(str[i]);
    }
    return ans;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << toCamelCase("hello_edabit") << std::endl;
    std::cout << toSnakeCase("getColor") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}