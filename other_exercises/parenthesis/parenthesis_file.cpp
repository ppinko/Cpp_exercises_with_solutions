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
#include <fstream>

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
    
    std::ifstream in_file;
    in_file.open("test_file3.txt");
    if (!in_file){
        std::cerr << "File cannot be opened\n";
        return 2;
    }
    std::string line {};
    bool flag = true;
    while(std::getline(in_file, line)){
        if (!par_test(line)){
            std::cout << "Not proper parenthesis\n";
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Proper usage\n";

    // std::string test {};
    // std::cout << test << std::endl;
    // std::cout << (par_test(test)) << std::endl;

    in_file.close();
    return 0;
}
