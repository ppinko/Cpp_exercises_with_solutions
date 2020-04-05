#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

int main(){
    std::string sentence {"Ala ma kota."};
    std::vector<std::string> vec {};
    std::string val {};
    for (size_t i {0}; i < sentence.length(); i++){
        if (std::isalpha(sentence[i]))
            val += sentence[i];
        else if (std::isspace(sentence[i])){
            vec.push_back(val);
            val.clear();
        }
        if (i == sentence.length() - 1){
            vec.push_back(val);
            val.clear();
        }
    }
    for (auto k: vec){
        std::cout << k << std::endl;
    }
    std::vector<std::string> vec_ans {};
    vec_ans.push_back(vec[2]);
    vec_ans.push_back(vec[1]);
    vec_ans.push_back(vec[0]);
    std::string result_str {};
    for (auto k: vec_ans){
        result_str += k;
        result_str += " ";
    }
    result_str.at(result_str.size() - 1) = '.';
    std::cout << result_str;
    return 0;
}