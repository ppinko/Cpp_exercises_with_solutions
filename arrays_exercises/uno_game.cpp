/*
https://edabit.com/challenge/KWu64CmjkD8g7icEM
*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cctype>

bool canPlay(const std::vector<std::string> hand, const std::string face);
std::vector<std::string> split (const std::string &str);

bool canPlay(const std::vector<std::string> hand, const std::string face) {
    auto face_val = split(face);
    for (int i {0}; i < hand.size(); i++){
        auto temp = split(hand[i]);
        if (temp[0] == face_val[0] || temp[1] == face_val[1])
            return true;
    }
	return false;
}

std::vector<std::string> split (const std::string &str){
    std::vector<std::string> vec {};
    std::string temp {};
    for (int i {0}; i < str.length(); i++){
        if (std::isspace(str[i])){
            vec.push_back(temp);
            temp.clear();
        }
        else 
            temp += str[i];
        if (i == str.length() - 1)
            vec.push_back(temp);
    }
    return vec; 
}

int main(){
    std::cout << std::boolalpha;
    std::vector<std::string> vec1 {"yellow 3", "yellow 7", "blue 8", "red 9", "red 2"};
    std::string face {"red 1"};
    auto vec2 = split(face);
    // std::cout << vec2.size() << std::endl;
    // std::cout << vec2.at(0) << " " << vec2[1] << std::endl;
    std::cout << canPlay(vec1, face) << std::endl;
    return 0;
}