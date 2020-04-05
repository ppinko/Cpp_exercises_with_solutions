#include <cmath>
#include <iostream>
#include <iomanip>

bool rectangleInCircle(int w, int h, int radius) {
	double cross = std::sqrt(w*w + h*h); 
	if (double(2 * radius) >= cross)
		return true;
	else
		return false;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << rectangleInCircle(5, 9, 5) << " = false" << std::endl;
    return 0;
}