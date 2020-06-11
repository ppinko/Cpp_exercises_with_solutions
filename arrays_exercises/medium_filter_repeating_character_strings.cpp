/*
https://edabit.com/challenge/wB8iDapNTTa2wpiJN

Create a function that keeps only strings with repeating identical characters (in other words, it has a set size of 1).

identicalFilter(["aaaaaa", "bc", "d", "eeee", "xyz"]) 
➞ ["aaaaaa", "d", "eeee"]

identicalFilter(["88", "999", "22", "545", "133"]) 
➞ ["88", "999", "22"]

identicalFilter(["xxxxo", "oxo", "xox", "ooxxoo", "oxo"]) 
➞ []
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


std::vector<std::string> identicalFilter(std::vector<std::string> arr) {
    std::vector<std::string> ans {};
    for (auto i: arr){
        if (i.length() == 1)
            ans.push_back(i);
        else {
            bool flag = true;
            for (int j = 0; j < i.length() - 1; j++){
                if (i[j] == i[j + 1])
                    continue;
                else {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(i);
        }
    }
    return ans;
}


// Alternative solution 1

std::vector<std::string> identicalFilter2(std::vector<std::string> arr) {
	std::vector<std::string> output {};
	for (auto str: arr) {
		std::sort(str.begin(), str.end());
		if (str.front() == str.back())
			output.push_back(str);
	}
	return output;
}

int main(){
    return 0;
}