/*
https://edabit.com/challenge/3HEY2ZfqMXyZsA87i
*/


#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> isFourLetters(std::vector<std::string> arr) {
    std::vector<std::string> ans {};
    for (auto i: arr){
        if (i.size() == 4)
            ans.push_back(i);
    }
    return ans;
}


int main(){
    return 0;
}