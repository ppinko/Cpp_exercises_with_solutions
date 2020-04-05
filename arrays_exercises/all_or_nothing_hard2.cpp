/*
https://edabit.com/challenge/K7Qq7HXhJWh3tgwKD
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

bool possiblyPerfect(std::vector<char> key, std::vector<char> answers) {
	int key_size = key.size();
    if (key_size == 1)
        return true;
    int same {0};
    int not_sure {0};
    for (int i {0}; i < key_size; i++){
        if (key[i] == '_')
            not_sure++;
        else if (key[i] == answers[i])
            same++;
        else 
            same--;
    }
    if (key_size - not_sure == std::abs(same))
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