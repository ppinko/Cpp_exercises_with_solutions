/*
https://edabit.com/challenge/fzgiGqP8Mz49Yy4QM
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

std::string reverse(std::string str) {
    std::string new_str {};
    std::string temp {};
    for (int i {0}; i < str.length(); i++){
        if (str[i] != ' ')
            temp += str[i];
        else if (temp.length() <= 4){
            new_str += temp + ' ';
            temp.clear();
        }
        else {
            std::reverse(temp.begin(), temp.end());
            new_str += temp + ' ';
            temp.clear();            
        }
        if (i == str.length() - 1){
            if (temp.length() != 0){
                if (temp.length() <= 4){
                    new_str += temp;
                }
                else {
                    std::reverse(temp.begin(), temp.end());
                    new_str += temp;         
                }
            }
                 
        }

    }
    return new_str;
}

int main(){
    std::cout << reverse("Reverse") << " = esreveR" << std::endl;
    std::cout << reverse("This is a typical sentence.") << " = This is a lacipyt .ecnetnes" << std::endl;
    std::cout << reverse("The dog is big.") << " = The dog is big." << std::endl;
    return 0;
}