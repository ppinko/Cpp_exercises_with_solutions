/*
https://edabit.com/challenge/eLH7c93ujbacHTwmy
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

std::vector<std::string> removeDups(std::vector<std::string> arr) {
    std::set<std::string> s;
    std::vector<std::string> new_arr;
  
    for (const std::string& str : arr){
        if (s.insert(str).second)
    	    new_arr.push_back(str);
    }
    return new_arr;
}

int main(){
    return 0;
}