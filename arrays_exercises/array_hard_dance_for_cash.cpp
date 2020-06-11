/*
https://edabit.com/challenge/ByqR9jKybjJy3ioZ4
*/

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <iterator>
#include <algorithm>

std::vector<std::string> danceConvert(std::string pin) {
	std::vector<std::string> moves = {"Shimmy", "Shake", "Pirouette", "Slide", 
        "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};
	std::vector<std::string> ans {};
    if (pin.size() != 4){
        ans.push_back("Invalid input.");
        return ans;
    }
    
    int current {-1};
    for (char& c: pin){
        if (std::isdigit(c)){
            int index = (int)c - int('0');
            current += 1;
            int pos = index + current;
            if (pos >= moves.size()) pos %= moves.size();
            ans.push_back(moves.at(pos));
        }
        else {
            ans.clear();
            ans.push_back("Invalid input.");
            break;
        }
    }
    return ans;
}


int main(){
    auto vec2 = danceConvert("5555");
    for (auto i: vec2){
        std::cout << i << " ";
    }
    // char c = '8';
    // std::cout << int(c) - int('0') << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}