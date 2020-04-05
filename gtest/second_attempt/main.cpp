#include "fdiv.hpp"
#include <iostream>

int Mal(int a, int b){
    return a*b;
}

int main(){
    float a = 2.0;
    float b = 5.0;
    std::cout << float_div(b, a) << std::endl;
    return 0;
}