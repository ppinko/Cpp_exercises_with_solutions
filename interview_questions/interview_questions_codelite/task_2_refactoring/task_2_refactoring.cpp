#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// function prototype
int convert_comments(std::string file_name);
std::vector<int> counting_comments(std::string line);

// function checking number of starting and closing comment symbol in one line
std::vector<int> counting_comments(std::string line){
    std::vector<int> counter {0, 0};
    std::string start_comment {"/*"}, end_comment {"*/"};
    int i {0};
    while (i < line.size() - 1){
        std::string temp = line.substr(i, 2);
        if (temp == start_comment || temp == end_comment){
            if (temp == start_comment) counter[0]++;
            else counter[1]++;
            i += 2;
        } else i++;
    }
    return counter;
}

int convert_comments(std::string file_name){
    std::ifstream in_file;
    in_file.open(file_name);
    
    // checking if file exists and was opened properly
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    // setting variables
    std::vector<std::string> out_file {};
    std::vector<std::string> buffer {};
    std::string line{};
    bool flag {false};
    int pos_start {0}, pos_end {0};
    int line_no = -1;
    
    while (std::getline(in_file, line)){
        line_no++;
        pos_start = line.find("/*");
        pos_end = line.find("*/");
    
        // lack of starting c-style comment symbol /* and flag equals false, copy original line
        if (!flag && pos_start == -1) 
            out_file.push_back(line);
        
        // checking one-line comments
        else if (!flag && pos_start != -1 && pos_end != -1){
            std::vector<int> counter = counting_comments(line);
            std::cout << counter[0] << " & " << counter[1] << std::endl;
            // if closing comment symbol */ at the end of line, then convert line
            if (pos_end + 1 == line.size() - 1){
                line.replace(pos_start, 2, "//");
                line.replace(pos_end, 2, "");
                out_file.push_back(line);
            } else {
                // if closing comment symbol */ not at the end of line and printable
                // objects behind closing comment symbol, then no conversion
                flag = true;
                for (int i = pos_end + 2; i < line.size(); i++){
                    if (std::isprint(line[i])) {
                        out_file.push_back(line);
                        flag = false;
                        break;
                    }
                }
                // if closing comment symbol */ not at the end of line, but no more
                // printable objects behind closing comment symbol, then convert
                if (flag){
                    line.replace(pos_start, 2, "//");
                    line.replace(pos_end, 2, "");
                    flag = false;
                    out_file.push_back(line);
                }
            }
        }
        
        // checking multi-line comments
        else {
            buffer.push_back(line);
            // if only starting c-style comment symbol /*, append line to buffer and activate
            // flag marking start of c-style comment
            if (!flag && pos_start != -1){
                std::cout << "First: " << line_no << std::endl;
                flag = true;
            }
            // adding next comment line to buffer
            else if (flag && pos_end == -1){
                std::cout << "Second: " << line_no << std::endl;
                continue;
            }
            // checking closing line with */
            else {
                if (pos_end + 1 != line.size() - 1){
                    for (int i = pos_end + 2; i < line.size(); i++){
                        if (!std::isspace(line[i])) {
                            std::cout << "Wrong line: " << line << " -> wrong element, i = " << i << " = " << line[i] << std::endl;
                            for (int j = 0; j < buffer.size(); j++){
                                out_file.push_back(buffer[j]);
                            }
                            buffer.clear();
                            flag = false;
                            std::cout << "Third: " << line_no << std::endl;
                            break;
                        }                
                    }
                }
                if (flag){
                    std::cout << "Fourth: " << line_no << std::endl;
                    for (int j = 0; j < buffer.size(); j++){
                        if (j == 0){
                            pos_start = buffer[j].find("/*");
                            buffer[j].replace(pos_start, 2, "//");
                        } else if (j == buffer.size() - 1){
                            buffer[j].replace(pos_end, 2, "");
                            buffer[j].insert(0, "// ");
                        } else {
                            buffer[j].insert(0, "// ");
                        }
                        out_file.push_back(buffer[j]);
                    }
                    buffer.clear();
                }
                flag = false;                
            }
        }
    }
    in_file.close();
    
    // copying converted data from vector to initial cpp script
    std::ofstream output_file;
    output_file.open(file_name);
    for (auto i: out_file) 
        output_file << i << std::endl;
    output_file.close();
    return 0;
}

int main() {
    convert_comments("to_replace.cpp");
    return 0;
}