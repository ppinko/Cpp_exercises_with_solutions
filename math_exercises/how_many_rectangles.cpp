/*
https://edabit.com/challenge/EePutMiQcitWdEA5s
https://www.youtube.com/watch?v=Uq9OXC0Gzgw
*/

#include <iostream>
#include <cmath>

int rectangles(int step) {
	return std::pow((step+1)*step / 2, 2);
}

int main(){
    std::cout << rectangles(3) << " = 36" << "\n";
    return 0;
}