#include <iostream>
#include <gsl/gsl>

void doubleValue(gsl::not_null<int16_t*> ptr)
{
    *ptr *= 2;
}

void doubleVal(int16_t* ptr)
{
    *ptr *= 2;
}

int main(){
    int16_t* ptr = new int16_t(10);
    std::cout << "Pointer value ptr = " << *ptr << std::endl;

    doubleValue(ptr);
    std::cout << "Pointer value ptr = " << *ptr << std::endl;
    
    int16_t* ptr2 = new int16_t;
    ptr2 = nullptr;
    // doubleValue(ptr2); // terminate called without an active exception
    // doubleVal(ptr2); // Exception has occurred. Segmentation fault.

    return 0;
}