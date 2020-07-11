#include <iostream>
#include <typeinfo>

int main(){
    
    const int i = 10;
    auto j = i;
    decltype(i) k = i;
    
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;

    return 0;
}