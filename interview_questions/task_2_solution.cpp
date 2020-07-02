// Problem-solving task
//
// C++ supports two kinds of comments, C-style comments (/* comment */)
// and C++ comments (// comment). C-style comments can span multiple 
// lines, while C++ comments end at the end of the line.
//
// Write a small word processor that reads a C++ source file and replaces 
// C-style comments with C++ comments, if possible. If a C-style comment 
// does not end at the end of a line (ignoring whitespaces), it needs to 
// be kept. For simplicity’s sake, C++ syntax rules are not to be 
// considered, including nested comments.

/*
 * ASSUMPTIONS:
 * a) for simplicity the cpp script modifying comments is located in the 
 * same folder as script to modify
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// function prototypes
std::string one_line_comments(std::string &line, const int pos_start, const int pos_end);
int convert_comments(std::string file_name);

std::string one_line_comments(std::string &line, const int pos_start, const int pos_end){
    // if closing comment symbol */ not at the end of line and printable
    // objects behind closing comment symbol, then no conversion, keep 
    // original line        
    if (pos_end + 1 != line.size() - 1){
        for (int i = pos_end + 2; i < line.size(); i++){
            if (!std::isspace(line[i])) {
                return line;
            }
        }
    }
    // else convert comments
    line.replace(pos_start, 2, "//");
    line.replace(pos_end, 2, "");
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
    
    // setting variables
    std::vector<std::string> *out_file = new std::vector<std::string> {};
    std::vector<std::string> buffer {};
    std::string line {};
    bool flag {false}; // flag marking start of c-style multi-line comments
    int pos_start {0}, pos_end {0};
    
    while (std::getline(in_file, line)){
        pos_start = line.rfind("/*");
        pos_end = line.rfind("*/");
    
        // lack of starting c-style comment symbol /* and flag equals false, copy original line
        if (!flag && pos_start == -1) 
            out_file->push_back(line);
        // checking one-line comments
        else if (!flag && pos_start != -1 && pos_end != -1 && pos_end > pos_start){
            std::string one_line = one_line_comments(line, pos_start, pos_end);
            out_file->push_back(one_line);
        }
        // checking multi-line comments
        else {
            buffer.push_back(line);
            // if only starting c-style comment symbol /*, append line to buffer and activate
            // flag marking start of c-style multi-line comment
            if (!flag && pos_start != -1){
                flag = true;
            }
            // adding next comment line to buffer
            else if (flag && pos_end == -1){
                continue;
            }
            // handle situation when another comment starts at the line where
            // first comment ends
            else if (flag && pos_start != -1){
                for (int j = 0; j < buffer.size() - 1; j++){
                    out_file->push_back(buffer[j]);
                }
                buffer.clear();
                if (pos_end > pos_start){
                    std::string complex_line = one_line_comments(line, pos_start, pos_end);
                    out_file->push_back(complex_line);
                } else buffer.push_back(line);
            }
            // checking closing line with */
            else {
                if (pos_end + 1 != line.size() - 1){
                    for (int i = pos_end + 2; i < line.size(); i++){
                        if (!std::isspace(line[i])) {
                            for (int j = 0; j < buffer.size(); j++){
                                out_file->push_back(buffer[j]);
                            }
                            buffer.clear();
                            flag = false;
                            break;
                        }                
                    }
                }
                if (flag){
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
                        out_file->push_back(buffer[j]);
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
    for (auto i: *out_file){
        output_file << i << std::endl;
    }
    output_file.close();
    delete out_file;
    return 0;
}

int main() {
    convert_comments("task_2_testing_file_extended.cpp");
    return 0;
}