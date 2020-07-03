// https://edabit.com/challenge/DqaLizN7DtKDRRrxv

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

bool canMove(std::string piece, std::string current, std::string target) {
    int a = std::abs(int(target.at(0)) - int(current.at(0)));
    int b = std::abs(int(target.at(1)) - int(current.at(1)));

	if (piece == "Pawn"){
        if (current.at(0) == target.at(0) && ((int(target.at(1)) - int(current.at(1)) == 1 
            || target.at(1) == '4' && current.at(1) == '2')))
            return true;
    }
    else if (piece == "Knight"){
        if (std::fmin(a, b) == 1 && std::fmax(a, b) == 2)
            return true;
    }
    else if (piece == "Bishop"){
        if (a == b)
            return true;
    }
    else if (piece == "Rook"){
        if (current.at(0) == target.at(0) || current.at(1) == target.at(1))
            return true;
    }
    else if (piece == "Queen"){
        if (a == b || current.at(0) == target.at(0) || current.at(1) == target.at(1))
            return true;
    }
    else if (piece == "King"){
        if (a <= 1 && b <= 1)
            return true;
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
    std::cout << canMove("Bishop", "B4", "E7") << std::endl;
	std::cout << canMove("Bishop", "B6", "F5") << std::endl;
    std::cout << canMove("Rook", "A8", "H8") << std::endl;
	std::cout << canMove("Rook", "A8", "H7") << std::endl;
    std::cout << canMove("Queen", "A8", "H1") << std::endl;
	std::cout << canMove("Queen", "A6", "H4") << std::endl;
	std::cout << canMove("King", "C4", "D5") << std::endl;
	std::cout << canMove("King", "B7", "B5") << std::endl;
    return 0;
}