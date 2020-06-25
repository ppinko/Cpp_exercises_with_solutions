#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

int main() {
    std::ifstream in_file;
    std::ofstream out_file;
    
    in_file.open("to_replace.cpp");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    out_file.open("output_file.txt");
    
    std::vector<std::string> buffer {};
    std::string line{};
    bool flag {false}, transformation {false}; 
    int pos_first {0}, pos_second {0};
    
    while (std::getline(in_file, line)){
        pos_first = line.find("/*");
        pos_second = line.find("*/");

        if (!flag && pos_first == -1){
            out_file << line << std::endl;
            } 
        
        else if (!flag && pos_first != -1 && pos_second != -1 && pos_second > pos_first){
            if (pos_second + 1 == line.size() - 1){
                line.replace(pos_first, 2, "//");
                line.replace(pos_second, 2, "");
                out_file << line << std::endl;
                continue;
            }
            for (int i = pos_second + 2; i < line.size(); i++){
                if (std::isprint(line[i])) {
                    out_file << line << std::endl;
                    break;
                }
                transformation = true;
            }
            if (transformation) {
                line.replace(pos_first, 2, "//");
                line.replace(pos_second, 2, "");
                out_file << line << std::endl;
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
            buffer.push_back(line);
            if (pos_second + 1 == line.size() - 1){
                for (int j = 0; j < buffer.size(); j++){
                    if (j == 0){
                        pos_first = buffer[j].find("/*");
                        buffer[j].replace(pos_first, 2, "//");
                        out_file << buffer[j] << std::endl;
                        }
                    else if (j == buffer.size() - 1){
                        buffer[j].replace(pos_second, 2, "");
                        out_file << "// " << buffer[j] << std::endl;
                        }
                    else {
                        out_file << "// " << buffer[j] << std::endl;
                        }
                flag = false;
                continue;
                }
            }
            for (int i = pos_second + 2; i < line.size(); i++){
                if (std::isprint(line[i])) {
                    for (int j = 0; j < buffer.size(); j++){
                        out_file << buffer[j] << std::endl;
                    }
                    flag = false;
                    break;
                }
                transformation = true;
            }
            if (transformation) {
                for (int j = 0; j < buffer.size(); j++){
                    if (j == 0){
                        pos_first = buffer[j].find("/*");
                        buffer[j].replace(pos_first, 2, "//");
                        out_file << buffer[j] << std::endl;
                        }
                    else if (j == buffer.size() - 1){
                        buffer[j].replace(pos_second, 2, "");
                        out_file << "// " << buffer[j] << std::endl;
                        }
                    else {
                        out_file << "// " << buffer[j] << std::endl;
                        }
                transformation = false;
                flag = false;
                }
            }
        }
        else {
            out_file << line << std::endl;
        }
    }
    in_file.close();
    out_file.close();
    return 0;
}