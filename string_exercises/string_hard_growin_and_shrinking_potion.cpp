// https://edabit.com/challenge/rtTzsz4o3bpomS37h

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

std::string afterPotion(std::string s) {
	std::vector<int> v {};
    for (char &c: s){
        if (std::isdigit(c))
            v.push_back(((int)c) - ((int)'0'));
        else if (c == 'A')
            v.at(v.size()-1) = v.at(v.size()-1) + 1;
        else if (c == 'B')
            v.at(v.size()-1) = v.at(v.size()-1) - 1;
    }
    std::string answer;
    for (auto i: v)
        answer.append(std::to_string(i));
    return answer;
}

int main(){
    std::cout << afterPotion("3A78B51") << " should equal to 47751." << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}