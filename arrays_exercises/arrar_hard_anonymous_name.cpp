/*
https://edabit.com/challenge/Q8ngJkLcgvS47WQ48
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isCorrectAliases(std::vector<std::string> names, std::vector<std::string> aliases) {
    for (int i {0}; i < names.size(); i++){
        if (std::count(aliases.at(i).begin(), aliases.at(i).end(), names.at(i).at(0)) != 2)
            return false;
    }
    return true;
}


int main(){

    std::cout << "Success" << std::endl;

    return 0;
}