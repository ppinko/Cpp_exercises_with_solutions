/*
Napisz funkcję sprawdzającą  poprawność rozmieszczonych nawiasów w stringu:

Poprawne rozmieszczenie:

    ( )
    ( ) ( )
    (( ))
    ( ) (( )) ( ) ((( )))

Niepoprawne rozmieszczenie:

    )
    (
    ) (
    ( ) )
    ( ) ((( )) ( )
    ( ) (( )) ( ) ) (
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>

bool par_test(const std::string &sentence);

bool par_test(const std::string &sentence){
    int counter {0};
    for (auto &letter : sentence){
        if (letter == '(')
            counter++;
        else if (letter == ')'){
            counter--;
            if (counter < 0)
                return false;
        }
    }
    if (counter != 0)
        return false;
    else
        return true;
}

int main(){
    std::cout << std::boolalpha;
    std::string test {"( ) (( )) ( ) ) ("};

    std::cout << test << std::endl;
    std::cout << (par_test(test)) << std::endl;
    return 0;
}
