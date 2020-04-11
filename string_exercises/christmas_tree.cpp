/*
https://edabit.com/challenge/27NTFdWjxtTyKyyaA
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tree(int h) {
    int bottom = 2 * h + 1;
    std::string temp = {};
    std::vector<std::string> v {};
    if (h == 0)
        return v;
    for (int i {0}; i < h; i++){
        std::string left {};
        left.assign((bottom - (2 * i + 1))/2, ' ');
        std::string middle {}; 
        middle.assign(2*i +1, '#');
        temp = left + middle + left;
        v.push_back(temp);
        temp.clear();
    }
    return v;
}

int main(){
    std::vector<std::string> vec = tree(2);
    for (auto row : vec){
        std::cout << row << std::endl;
    }
    return 0;
}

