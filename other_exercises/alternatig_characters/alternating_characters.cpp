#include <iostream>
#include <string>
#include <algorithm>

int alternatingCharacters(std::string s) {
    int counter {0};
    for(size_t i {0}; i < s.length() - 1; i++){
        if (s[i] == s[i+1])
            counter += 1;
    }
    return counter;
}

int main(){

    return 0;
}