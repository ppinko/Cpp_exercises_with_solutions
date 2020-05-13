/*
https://edabit.com/challenge/WmCeqpu5miZAtLk2z
*/


#include <string>
#include <iostream>


std::string doubleChar(std::string str) {
	std::string ans {};
    for (int i {0}; i < str.size(); i++){
        ans.push_back(str[i]);
        ans.push_back(str[i]);
    }
    return ans;
}


int main(){
    return 0;
}