// https://edabit.com/challenge/6H6dch4q68BXQbFcM

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cctype>
#include <algorithm>

std::string addStrNums(std::string num1, std::string num2) {
	if (num1.empty() && num2.empty()) return "0";

    // checking if there are only letters
    std::vector<std::string> pair {num1, num2};
    for (const auto &i : pair){
        if (!i.empty()){
            for (const auto &c : i){
                if (!std::isdigit(c)) return "-1";
            }
        }
    }
    
    int min_length = std::fmin(num1.size(), num2.size());
    if (min_length == 0){
        if (num1.size() == 0) return num2;
        else return num1;
    }

    std::string answer {};
    bool buffer = false;
    auto it_1 = num1.rbegin();
    auto it_2 = num2.rbegin();
    std::string c {};
    for (int i = 0; i < min_length; i++){
        int temp = 0;
        temp = int(*it_1) - 2 * int('0') + int(*it_2);
        if (buffer) temp++;
        if (temp >= 10) {
            buffer = true;
        } else {
            buffer = false;
        }
        c = std::to_string(temp % 10);
        // std::cout << "temp = " << temp << std::endl;
        // std::cout << "c = " << c << std::endl;
        answer.append(c);
        it_1++;
        it_2++;
    }

    // std::cout << "Intermediate value = " << answer << std::endl;

    if (num1.size() > num2.size()){
        while(it_1 != num1.rend()){
            int temp = 0;
            temp = int(*it_1) - int('0');
            if (buffer) temp++;
            if (temp >= 10) {
                buffer = true;
            } else {
                buffer = false;
            }
            c = std::to_string(temp % 10);
            answer.append(c);
            it_1++;
        }
    }
    else if (num1.size() < num2.size()){
        while(it_2 != num2.rend()){
            int temp = 0;
            temp = int(*it_2) - int('0');
            if (buffer) temp++;
            if (temp >= 10) {
                buffer = true;
            } else {
                buffer = false;
            }
            c = std::to_string(temp % 10);
            answer.append(c);
            it_2++;
        }
    }
    if (buffer) answer.push_back('1');
    std::reverse(answer.begin(), answer.end());
    bool flag = true;
    std::string without_zeros {};
    for (const auto &c : answer){
        if (flag && c == '0') continue;
        else {
            flag = false;
            without_zeros.push_back(c);
        }
    }
    return without_zeros;
}

int main(){
    std::cout << std::boolalpha;
    std::string s1 {"125"};
    std::string s2 {"1345"};
    std::cout << addStrNums(s1, s2) << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}