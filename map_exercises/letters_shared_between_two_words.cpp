/*
https://edabit.com/challenge/qeCS48GXtK9NJLc9C
*/

#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

std::unordered_map<char, int> create_map (const std::string &str);
void display_map(const std::unordered_map<int, char> &mp);
int sharedLetters(const std::string str1, const std::string str2);
int compare_maps(const std::unordered_map<char, int> &mp1, const std::unordered_map<char, int> &mp2);

void display_map(const std::unordered_map<char, int> &mp){
    auto it = mp.begin();
    std::cout << "[ ";
    for (it; it != mp.end(); it++){
        std::cout << it->first << ":" << it->second << " ";
    }
    std::cout << "]\n"; 
}

int sharedLetters(const std::string str1, const std::string str2) {
    std::unordered_map<char, int> u_map_1 = create_map(str1);
    std::unordered_map<char, int> u_map_2 = create_map(str2);
    return compare_maps(u_map_1, u_map_2);
}

std::unordered_map<char, int> create_map(const std::string &str){
    std::unordered_map<char, int> u_map {};
    for (int i {0}; i < str.length(); i++){
        auto search = u_map.find(str[i]);
        if (search == u_map.end())
            u_map.emplace(str[i], 1);
        else
            u_map[str[i]] += 1;
    }
    return u_map;
}

int compare_maps(const std::unordered_map<char, int> &mp1, const std::unordered_map<char, int> &mp2){
    int counter {0};
    for (auto it = mp1.begin(); it != mp1.end(); it++){
        auto it2 = mp2.find(it->first);
        if (it2 != mp2.end())
            counter += std::min(it->second, it2->second);
    }
    return counter;
}

int main(){
    // std::string test_str = "apple";
    // std::unordered_map<char, int> u_map_test = create_map(test_str);
    // display_map(u_map_test);
    std::cout << sharedLetters("apple", "meaty") << " = 2" << std::endl;
    return 0;
}