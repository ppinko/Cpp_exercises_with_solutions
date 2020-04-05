#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>



std::string firstNonRepeatedCharacter(std::string str) {
    std::unordered_map<char, int> map_letters {};
    for (auto letter : str){
        auto search = map_letters.find(letter);
        if (search == map_letters.end())
            map_letters[letter] = 1;
        else
            map_letters[letter] += 1;
    }
    for (auto letter : str){
        if (map_letters[letter] == 1){
            std::string ans {letter};
            return ans; 
        }
    }
    return "Invalid";
}

int main(){
    std::cout << firstNonRepeatedCharacter("hheelloo") << std::endl;
    std::cout << firstNonRepeatedCharacter("it was then the frothy word met the round night") << std::endl;
    return 0;
}