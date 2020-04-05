/*
https://edabit.com/challenge/K7Qq7HXhJWh3tgwKD
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

bool possiblyPerfect(std::vector<char> key, std::vector<char> answers) {
	if (key.size() == 1)
        return true;
    int sure_ans = std::count_if(key.begin(), key.end(), [](char c){return c != '_';});
    int same = {0};
    for (int i {0}; i < key.size(); i++){
        if (key[i] == '_')
            continue;
        else if (key[i] == answers[i])
            same++;
        else 
            same--;
    }
    if (sure_ans == std::abs(same))
        return true;
    else 
        return false;
}

int main(){
    std::cout << std::boolalpha;
    std::vector<char> vec1 {'A', 'B', 'A', '_'};
    std::vector<char> vec2 {'B', 'A', 'C', 'C'};
    std::cout << possiblyPerfect(vec1, vec2) << " = true " << std::endl;
    return 0;
}