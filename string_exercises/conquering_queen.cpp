#include <string>
#include <iostream> 
#include <vector>
#include <cmath>
#include <iomanip>

bool canCapture(std::vector<std::string> queens) {
	char a1 = queens.at(0).at(0);
    int a2 = std::stoi(std::to_string(queens.at(0).at(1)));
    char b1 = queens.at(1).at(0);
    int b2 = std::stoi(std::to_string(queens.at(1).at(1)));
    if (a1 == b1 || a2 == b2)
        return true;
    else if (std::abs(a1 - b1) == std::abs(a2 - b2))
        return true;
    else
        return false;
}

int main(){
    std::cout << std::boolalpha;
    std::vector<std::string> vec1 {"A1", "A8"};
    std::vector<std::string> vec2 {"A1", "H1"};
    std::vector<std::string> vec3 {"B2", "D4"};
    std::vector<std::string> vec4 {"A1", "C4"};

    std::cout << canCapture(vec1) << std::endl;
    std::cout << canCapture(vec2) << std::endl;
    std::cout << canCapture(vec3) << std::endl;
    std::cout << canCapture(vec4) << std::endl;

    return 0;
}