/*
https://edabit.com/challenge/n3uivD8qXEq2D3ZMh
*/


#include <iostream>
#include <string>
#include <vector>
#include <set>

void print_vec(std::vector<std::string>& v){
    for (auto i: v)
        std::cout << i << ' ';
    std::cout << std::endl;
}

std::vector<std::string> filterUnique(std::vector<std::string> arr) {
    std::set<char> s;
    std::vector<std::string> new_arr;
  
    for (const auto &str : arr){
        for (const char &c : str)
            s.insert(c);
        if (s.size() == str.length())
            new_arr.push_back(str);
        s.clear();
    }
    return new_arr;
}


int main(){
    auto a = filterUnique({"abb", "abc"});
    print_vec(a);
    return 0;
}