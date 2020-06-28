#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// function prototype
int convert_comments(std::string file_name);
std::vector<int> counting_comments(std::string line);
std::string one_line_comments(std::string line, int pos_start, int pos_end);

// function checking number of starting and closing comment symbol in one line
std::vector<int> counting_comments(std::string line){
    std::vector<int> counter {0, 0};
    std::string start_comment {"/*"}, end_comment {"*/"};
    int i {0};
    if (line.empty()) return counter;
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

std::string one_line_comments(std::string line, int pos_start, int pos_end){
            // if closing comment symbol */ at the end of line, then convert line
            if (pos_end + 1 == line.size() - 1){
                line.replace(pos_start, 2, "//");
                line.replace(pos_end, 2, "");
            } else {
                // if closing comment symbol */ not at the end of line and printable
                // objects behind closing comment symbol, then no conversion
                for (int i = pos_end + 2; i < line.size(); i++){
                    if (!std::isspace(line[i])) {
                        return line;
                    }
                }
                // if closing comment symbol */ not at the end of line, but no more
                // printable objects behind closing comment symbol, then convert
                line.replace(pos_start, 2, "//");
                line.replace(pos_end, 2, "");
            }
            return line;
}

int convert_comments(std::string file_name){
    std::ifstream in_file;
    in_file.open(file_name);
    
    // checking if file exists and was opened properly
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    // setting variabless
    std::vector<std::string> out_file {};
    std::vector<std::string> buffer {};
    std::string line{};
    bool flag {false};
    int pos_start {0}, pos_end {0};
    int line_no = -1;
    
    while (std::getline(in_file, line)){
        line_no++;
        pos_start = line.rfind("/*");
        pos_end = line.rfind("*/");
//        std::cout << line << std::endl;
//        std::cout << line_no << "=" << pos_start << "=" << pos_end << std::endl;
        std::vector<int> counter = counting_comments(line);
//        std::cout << counter[0] << " & " << counter[1] << std::endl;
    
        // lack of starting c-style comment symbol /* and flag equals false, copy original line
        if (!flag && pos_start == -1) 
            out_file.push_back(line);
        
        // checking one-line comments
        else if (!flag && pos_start != -1 && pos_end != -1 && pos_end > pos_start){
            std::string one_line = one_line_comments(line, pos_start, pos_end);
            std::cout << "ONE-LINER = " << one_line << std::endl;
            out_file.push_back(one_line);
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
            else if (flag && pos_start != -1){
                for (int j = 0; j < buffer.size() - 1; j++){
                    out_file.push_back(buffer[j]);
                }
                buffer.clear();
                if (pos_end > pos_start){
                    std::string complex_line = one_line_comments(line, pos_start, pos_end);
                    out_file.push_back(complex_line);
                } else buffer.push_back(line);
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
                            pos_start = buffer[j].rfind("/*");
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
    for (auto i: out_file){
        output_file << i << std::endl;
        std::cout << i << std::endl;
    }
    output_file.close();
    return 0;
}

int main() {
    convert_comments("to_replace.cpp");
    return 0;
}