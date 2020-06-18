#include <fstream>
#include <iostream>

int main() {
    std::ifstream in_file;
    std::string line{};			

    // in_file.open("task_1_test_1.cpp");
    in_file.open("test.txt");		
    if (!in_file) { 				
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    while (std::getline(in_file, line)) {		
        std::cout << line << std::endl;
    }
    in_file.close();				
    return 0;
}

