// https://edabit.com/challenge/5Xo5fBrQui9opFWH5

#include <string>
#include <iostream>
#include <cmath>
#include <cassert>

int letterDistance(std::string str1, std::string str2) {
	int min_length = std::min(str1.size(), str2.size());
    int letter_distance = 0;
    for (int i = 0; i < min_length; ++i)
    {
        letter_distance += std::abs((int)str1[i] - (int)str2[i]);
    }
    letter_distance += std::abs((int)str1.size() - (int)str2.size());
    return letter_distance;
}

int main(){
	assert((letterDistance("house", "fly") == 11));
	assert((letterDistance("sharp", "sharq") == 1));
	assert((letterDistance("abcde", "bcdef") == 5));
	assert((letterDistance("abcde", "a") == 4));
	assert((letterDistance("abcde", "e") ==8 ));
	assert((letterDistance("very", "fragile") == 67));
	assert((letterDistance("abcde", "Abcde") == 32));
	assert((letterDistance("abcde", "A") == 36));
    std::cout << "Success" << std::endl;
    return 0;
}