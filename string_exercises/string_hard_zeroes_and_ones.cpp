// https://edabit.com/challenge/K283AfNkBRXaDZRQa

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>

bool sameLength(std::string str) {
    char first = str[0];
    int second_pos = str.find_first_not_of(first);
    if (second_pos == -1) // it means that string with only 1's or 0's
        return false;
    char second = str[second_pos];
    bool check = false;
    int first_count = 0;
    int second_count = 0;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == second){
            check = true;
            second_count++;
        } else if (check){
            if (first_count != second_count) return false;
            else {
                first_count++;
                check = false;
            }
        } else {
            first_count++;
            check = false;
        }
    }
    return (first_count == second_count);
}


int main(){
    std::cout << std::boolalpha;
    std::cout << sameLength("10101110001100") << " should equal to true" << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}