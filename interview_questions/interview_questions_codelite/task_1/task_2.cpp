#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

int main() {
    std::ifstream in_file;
    std::ofstream out_file;

    in_file.open("test_2.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    out_file.open("output_file.txt");
    
    std::vector<std::string> buffer {};
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
            std::cout << "SAVING" << std::endl;
            out_file << line << std::endl;
            std::cout << line << std::endl;
            } 
        
        else if (!flag && pos_first != -1 && pos_second != -1 && pos_second > pos_first){
            if (pos_second + 1 == line.size() - 1){
                out_file << "This line MUST be changed" << std::endl;
                std::cout << "This line MUST be changed" << std::endl;
                continue;
            }
            for (int i = pos_second + 2; i < line.size(); i++){
                if (std::isprint(line[i])) {
                    out_file << "This line shouldn't be changed" << std::endl;
                    std::cout << "This line shouldn't be changed" << std::endl;
                    break;
                }
                transformation = true;
            }
            if (transformation) {
                out_file << "THIS LINE MUST BE CHANGED" << std::endl;
                std::cout << "THIS LINE MUST BE CHANGED" << std::endl;
                transformation = false;
            }
        }
        else if (!flag && pos_first != -1){
            buffer.push_back(line);
            flag = true;
        }
        else if (flag && pos_second == -1){
            buffer.push_back(line);
            }
        else if (flag && pos_second != -1){
            if (pos_second + 1 == line.size() - 1){
                out_file << "This line MUST be changed" << std::endl;
                std::cout << "This line MUST be changed" << std::endl;
                flag = false;
                continue;
            }
            for (int i = pos_second + 2; i < line.size(); i++){
                if (std::isprint(line[i])) {
                    out_file << "This line shouldn't be changed" << std::endl;
                    std::cout << "This line shouldn't be changed" << std::endl;
                    flag = false;
                    break;
                }
                transformation = true;
            }
            if (transformation) {
                out_file << "THIS LINE MUST BE CHANGED" << std::endl;
                std::cout << "THIS LINE MUST BE CHANGED" << std::endl;
                transformation = false;
                flag = false;
            }
            }
        else {
            out_file << line << std::endl;
            std::cout << line << std::endl;
        }
    }
    in_file.close();
    out_file.close();
    return 0;
}