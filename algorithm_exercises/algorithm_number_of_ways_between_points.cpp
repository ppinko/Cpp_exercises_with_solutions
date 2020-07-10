// https://edabit.com/challenge/mGnmpYKnozcjP8Yja

#include <iostream>
#include <cassert>
#include <vector>

int paths(int x, int y) {
	if (x == 0 || y == 0) 
        return 1;
    else
        return paths(x-1, y) + paths(x, y-1);  
}

int main(){
    assert((paths(0, 0) == 1));
	assert((paths(2, 1) == 3));
	assert((paths(2, 2) == 6));
	assert((paths(6, 9) == 5005));
	assert((paths(0, 8) == 1));
	assert((paths(7, 0) == 1));
	assert((paths(1, 99) == 100));

    std::cout << "Success" << std::endl;
    return 0;
}