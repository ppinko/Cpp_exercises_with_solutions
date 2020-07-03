// https://edabit.com/challenge/DqaLizN7DtKDRRrxv

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

bool canMove(std::string piece, std::string current, std::string target) {
	if (piece == "Pawn"){
        if (current.at(0) == target.at(0) && ((int(target.at(1)) - int(current.at(1)) == 1 
            || target.at(1) == '4' && current.at(1) == '2')))
            return true;
        else return false;
    }
    else if (piece == "Knight"){
        int a = std::abs(int(target.at(0)) - int(current.at(0)));
        int b = std::abs(int(target.at(1)) - int(current.at(1)));
        if (std::fmin(a, b) == 1 && std::fmax(a, b) == 2)
            return true;
        else return false;
    }
    return false;
}


int main(){
    std::cout << std::boolalpha;
    std::cout << canMove("Pawn", "A5", "A6") << std::endl;
    std::cout << canMove("Pawn", "G2", "G4") << std::endl;
	std::cout << canMove("Pawn", "C6", "D7") << std::endl;
    std::cout << canMove("Knight", "F5", "E3") << std::endl;
	std::cout << canMove("Knight", "F6", "E5") << std::endl;
    return 0;
}