// https://edabit.com/challenge/Wzk69GjCT7vX3rtGf

#include <string>
#include <iostream>
#include <algorithm>

bool canComplete(std::string initial, std::string word) {
	std::string initial_sorted {initial};
    std::string word_sorted {word};
    std::sort(initial_sorted.begin(), initial_sorted.end());
    std::sort(word_sorted.begin(), word_sorted.end());

    if (!std::includes(word_sorted.cbegin(), word_sorted.cend(), 
        initial_sorted.cbegin(), initial_sorted.cend())){
            return false;
        }
    int last_index = 0;
    for (const auto &c : initial)
    {
        if (word.find(c) == std::string::npos)
        {
            return false;
        }
        int temp = word.find(c, last_index);
        if (temp == -1)
            return false;
        last_index = temp + 1;
    }
    return true;
}

int main(){

    canComplete("tulb", "beautiful");
    canComplete("sing", "something");
    return 0;
}