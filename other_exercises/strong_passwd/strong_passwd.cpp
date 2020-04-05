#include <iostream>
#include <string>
#include <cctype>

int minimumNumber(int n, std::string password) {
    // Return the minimum number of characters to make the password strong
    int counter {0};
    std::string symbol {"!@#$%^&*()-+"};
    bool flag_lower {false};
    bool flag_upper {false};
    bool flag_number {false};
    bool flag_symbol {false};
    for (auto letter : password){
        if (std::islower(letter)){
            flag_lower = true;
        }
        else if (std::isupper(letter)){
            flag_upper = true;
        }
        else if (std::isdigit(letter))
            flag_number = true;
        else if (!flag_symbol){
            for (auto element : symbol){
                if (element == letter)
                    flag_symbol = true;
            }
        }
    }
    if (!flag_lower)
        counter += 1;
    if (!flag_upper)
        counter += 1;
    if (!flag_number)
        counter += 1;  
    if (!flag_symbol)
        counter += 1;
    n += counter;
    if (n <= 6){
        counter += 6-n;
    }
    return counter;
}

int main(){

    std::cout << minimumNumber(5, "^e!zA");
    return 0;
}