/*
Create a function that outputs the result of a math expression in words.
Examples

wordedMath("One plus one") ➞ "Two"

wordedMath("zero Plus one") ➞ "One"

wordedMath("one minus one") ➞ "Zero"

Notes

    Expect only the operations plus and minus.
    Expect to only get numbers and answers from 0 to 2.
    The first letter of the answer must be capitalised.
*/
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <locale>

std::string wordedMath(std::string s){
    std::string res {};
    std::vector<std::string> v {};
    std::transform(s.begin(), s.end(), s.begin(), std::tolower);
    std::cout << s;
    return res;
}

int main(){
    std::cout << wordedMath("zero Plus one") << std::endl;
    return 0;
}