/*
https://edabit.com/challenge/nCrM3R5NsYkmpywSY
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int kaprekar(int num) {
    int counter {0};
    while (num != 6174 || counter > 10){
        counter++;
        int temp = 0;
        std::string s = std::to_string(num);
        std::sort(s.begin(), s.end());
        temp -= std::stoi(s);
        std::reverse(s.begin(), s.end());
        temp += std::stoi(s);
        num = temp;
    }
    return counter;
}


int main(){
    // int k = std::stoi(s2);
    // std::cout << k << std::endl;
    std::cout << kaprekar(3524) << std::endl;
    // std::cout << "Success" << std::endl;
    //     int temp = 0;
    //     std::string s = std::to_string(3524);
    //     std::sort(s.begin(), s.end());
    //     std::cout << "s = " << s << std::endl;
    //     temp -= std::stoi(s);
    //     std::cout << "temp = " << temp << std::endl;
    //     std::reverse(s.begin(), s.end());
    //     temp += std::stoi(s);
    //     std::cout << "temp = " << temp << std::endl;
    return 0;
}