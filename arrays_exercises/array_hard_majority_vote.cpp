// https://edabit.com/challenge/5kj4FDHnzaQETPuS3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

std::string majorityVote(std::vector<std::string> arr) {
	std::set <std::string> s {arr.begin(), arr.end()};
    std::string most_ofen {};
    int most_element = 0;
    for (std::string str: s){
        int k = std::count(arr.begin(), arr.end(), str);
        if (k > most_element){
            most_element = k;
            most_ofen = str;
        }
    }
    int middle = 1 + (arr.size() / 2);
    if (most_element >= middle) return most_ofen;
    else return "None";
}

int main(){
    std::cout << "Success" << std::endl;
    return 0;
}