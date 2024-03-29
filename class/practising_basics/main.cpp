#include "Dog.h"
#include <iostream>
#include <string>

int main(){
    {
        Dog ziuta {"Ziuta", 5};
        ziuta.get_age();
        ziuta.introduce();
        std::cout << ziuta.after_n_year() << std::endl;
        std::cout << ziuta.after_n_year(10) << std::endl;

        Dog homeless;
        homeless.get_age();
        homeless.introduce();

        ziuta++;
        Dog hybrid = ziuta + homeless;
        std::cout << "My hybrid dog\n";
        hybrid.get_age();
        hybrid.introduce();

        std::cout << ziuta;

        Dog rysio {"rysio", 10};
        ziuta = rysio;
        ziuta.introduce();
    }
    return 0;
}