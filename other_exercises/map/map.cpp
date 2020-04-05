#include <map>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <iostream>

void display_map(std::map<int, char> mp){
    auto it = mp.begin();
    std::cout << "[ ";
    for (it; it != mp.end(); it++){
        std::cout << it->first << ":" << it->second << " ";
    }
    std::cout << "]\n"; 
}

int main(){

    // STANDARD FUNCTIONS: m.at(key), m.size(), m.empty(), m.clear(), m.erase(key / iterator), 

    std::map<int,char> example = {{1,'a'},{2,'b'}, {3, 'c'}};
    example.erase(3);
    display_map(example);

    // FIND -> return std::pair{first, second} !!!!!!!
    auto search = example.find(2);
    if (search != example.end()) {
    std::cout << "Found " << search->first << " " << search->second << '\n';
    } else {
    std::cout << "Not found\n";
    }
    
    // EMPLACE      -> m.emplace(val1, val2)
    // uses pair's converting move constructor
    example.emplace(std::make_pair(5, 'x'));
    example.emplace(std::make_pair(7, 'c'));
    display_map(example);

    return 0;
}