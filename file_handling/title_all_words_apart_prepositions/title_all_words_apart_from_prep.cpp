/*
Title all words apart prepositions like 'a', 'an', 'the'
*/

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <iostream>

int title_file(const std::string& in_file, const std::string& out_file);
void title_word(std::string& word);

void title_word(std::string& word)
{
    word[0] = std::toupper(word[0]);
}

int title_file(const std::string& input_file, const std::string& output_file)
{
    std::ifstream in_file;
    in_file.open(input_file);
    if (in_file)
        std::cout << "Input file is opened" << std::endl;
    else
        std::cout << "Input file not opened" << std::endl;

    std::ofstream out_file;
    out_file.open(output_file);
    if (out_file)
        std::cout << "Output file is opened" << std::endl;
    else
        std::cout << "Output file not opened" << std::endl;
    
    std::string line;
    while(std::getline(in_file, line))
    {
        std::istringstream iss {line};
        std::string new_line;
        std::string word;
        while (iss >> word)
        {
            if (word == "a" || word == "an" || word == "the")
                new_line.append(word);
            else {
                word[0] = std::toupper(word[0]);
                new_line.append(word);
            }
            new_line.push_back(' ');
        }
        new_line.pop_back();
        out_file << new_line << std::endl;
    }
    return 0;
}

int main(){
    std::string f {"/home/devpyth/all/c++/Cpp_exercises_with_solutions/file_handling/title_all_words_apart_prepositions/original.txt"};
    std::string o {"/home/devpyth/all/c++/Cpp_exercises_with_solutions/file_handling/title_all_words_apart_prepositions/output.txt"};
    title_file(f, o);

    return 0;
}