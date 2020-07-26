// https://edabit.com/challenge/nCrM3R5NsYkmpywSY

#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

int kaprekar(int num) {
	int num_operations = 0, temp = num;
    const int kap = 6174;
    while (temp != kap)
    {
        ++num_operations;
        std::string init_num = std::to_string(temp);
        while (init_num.size() < 4)
            init_num.push_back('0');
        std::sort(init_num.begin(), init_num.end());
        int min_val = std::stoi(init_num);
        std::sort(init_num.begin(), init_num.end(), [](char a, char b){return a > b;});
        int max_val = std::stoi(init_num);
        temp = max_val - min_val;
    }
    return num_operations;
}

int main(){

    assert((kaprekar(1112) == 5));
	assert((kaprekar(1342) == 3));
	assert((kaprekar(2636) == 3));
	assert((kaprekar(3219) == 3));
	assert((kaprekar(3305) == 6));
	assert((kaprekar(4132) == 3));

    std::cout << "Success" << std::endl;

    return 0; 
}