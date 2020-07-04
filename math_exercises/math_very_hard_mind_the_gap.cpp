// https://edabit.com/challenge/zFvCgwq5cJ5nrjHnH

#include <iostream>
#include <cassert>
#include <string>

bool is_gapful(int n){
    std::string val {std::to_string(n)};
    std::string temp {};
    temp.push_back(val.at(0));
    temp.push_back(val.at(val.size()-1));
    int transformed = std::stoi(temp);
    return n % transformed == 0;
}

int gapful(int n) {
	if (n <= 100) return 100;
    if (is_gapful(n)) return n;
    int i = 1;
    while (true){
        if (is_gapful(n-i)) return n-i;
        if (is_gapful(n+i)) return n+i;
        i++;
    }
}

int main(){
    assert((gapful(25) == 100));
	assert((gapful(100) == 100));
	assert((gapful(103) == 105));
	assert((gapful(1442) == 1441));
	assert((gapful(3345) == 3333));
    std::cout << "Success" << std::endl;
    return 0;
}