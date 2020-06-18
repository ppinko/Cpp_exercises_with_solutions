#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ifstream in_file;
    
    in_file.open("test_2.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    std::string buffer{};
    std::string line{};
    bool flag {false}, transformation {false}; 
    int pos_first {0}, pos_second {0};
    int line_no = 0;
    while (std::getline(in_file, line)){
        line_no++;
        pos_first = line.find("/*");
        pos_second = line.find("*/");
        std::cout << "line_no, pos_first, pos_second = " << line_no << ", " << pos_first << ", " 
            << pos_second << std::endl;
        if (!flag && pos_first == -1){
            std::cout << line << std::endl;
            } 
        else if (pos_first != -1 && pos_second != -1 && pos_second > pos_first){
            std::cout << "We are inside" << std::endl;
            if (pos_second + 1 == line.size() - 1){
                std::cout << "This line MUST be changed" << std::endl;
                continue;
            }
            std::cout << "Before for loop" << std::endl;
            for (int i = pos_second + 2; i < line.size(); i++){
                std::cout << "Checking" << std::endl;
                if (std::isprint(line[i])) {
                    std::cout << "This line shouldn't be changed" << std::endl;
                    break;
                }
                transformation = true;
            }
            if (transformation) {
                std::cout << "THIS LINE MUST BE CHANGED" << std::endl;
            }
        }
        else {
            std::cout << line << std::endl;
        }
    }
    in_file.close();
    return 0;
}