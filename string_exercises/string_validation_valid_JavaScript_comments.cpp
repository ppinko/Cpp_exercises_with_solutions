// https://edabit.com/challenge/jF9Hr2YCEZAbXrCvH

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iterator>

bool commentsCorrect(std::string str) {
	std::string single_line = "//";
    std::string open_multiline = "/*";
    std::string closed_multiline = "*/";
    bool flag = false;
    if (str.size() % 2 == 1) return false;
    for (int i = 0; i < str.size() / 2; i++){
        std::string two = str.substr(2 * i, 2);
        if (flag){
            if (two == closed_multiline) {
                flag = false;
                continue;
            } else return false;
        }
        else if (two == single_line) continue;
        else if (two == open_multiline) flag = true;
        if (i == str.size() - 1) return false; 
    }
    return true;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << commentsCorrect("/**//**////**/") << " should equal to true." << std::endl;
    std::cout << commentsCorrect("///*/**/") << " should equal to false." << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}