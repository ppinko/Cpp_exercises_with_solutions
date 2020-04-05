/*
https://edabit.com/challenge/NGD8wv2rKoFDKzmEu
*/

#include <string>
#include <iostream>
#include <algorithm>

std::string highLow(std::string str) {
	long max_val (0); 
    long min_val (0);
    bool flag {false};
    std::string temp;
    long t;
    for (int i {0}; i < str.length(); i++) {
        if (str[i] != ' '){
            temp += str[i];
        }
        else {
            // std::cout << temp << " ";
            t = std::stoul(temp);
            if (!flag){
                min_val = t;
                max_val = t;
                flag = true;
            }
            else if (t > max_val){
                max_val = t;
            }
            else if (t < min_val){
                min_val = t;
            }
            temp.clear();
        }
        if (i == str.length() - 1){
            t = std::stoul(temp);
            if (!flag){
                min_val = t;
                max_val = t;
                flag = true;
            }
            else if (t > max_val){
                max_val = t;
            }
            else if (t < min_val){
                min_val = t;
            }
        }
    }
    std::string ans;
    ans = std::to_string(max_val) + " " + std::to_string(min_val);
    return ans;
}

int main(){
    std::cout << highLow("1 2 3 4 5") << " = 5 1" << std::endl;
    std::cout << highLow("1 2 -3 4 5") << " = 5 -3" << std::endl;
    std::cout << highLow("1 9 3 4 -5") << " = 9 -5" << std::endl;
    std::cout << highLow("13") << " = 13 13" << std::endl;
    return 0;
}