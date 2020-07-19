// https://www.hackerrank.com/challenges/attribute-parser/problem

/*
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <algorithm>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int row, queries;
    std::cin >> row >> queries;
    std::string temp, tag_name, tag_attr, tag_val, tag_key;
    std::string opening_tag {};
    std::map<std::string, std::string> m {};

    for (int i = 0; i <= row; ++i)
    {   
        std::getline(std::cin, temp);
        if (temp.find("</") != std::string::npos)
        {
            if (opening_tag.rfind(".") == std::string::npos)
                opening_tag.clear();
            else {
                int last_tag_pos = opening_tag.rfind(".");
                opening_tag = opening_tag.substr(0, last_tag_pos);
            }
        }
        else if (temp.find("<") != std::string::npos)
        {   
            int start_position = 0;
            int num_args = std::count(temp.begin(), temp.end(), '=');
            if (num_args == 0)
                ++num_args;
            for (int j = 0; j < num_args; ++j)
            {
                int start_tag_pos, end_tag_pos;
                if (j == 0){
                    start_tag_pos = temp.find("<");
                    if (temp.find(" ", start_tag_pos) != std::string::npos)
                    {   
                        end_tag_pos = temp.find(" ", start_tag_pos);
                        tag_name = temp.substr(start_tag_pos +1, end_tag_pos - start_tag_pos - 1);
                        start_position = end_tag_pos;
                    }
                    else 
                    {
                        end_tag_pos = temp.find(">", start_tag_pos);
                        tag_name = temp.substr(start_tag_pos +1, end_tag_pos - start_tag_pos - 1);
                        start_position = end_tag_pos;
                        break;
                    }
                }
                int tag_attr_end = temp.find(" ", start_position + 1);
                tag_attr = temp.substr(start_position+1, tag_attr_end-start_position-1);
                if (opening_tag.size() == 0){
                    tag_key = tag_name + "~" + tag_attr;
                }
                else {
                    tag_key = opening_tag + "." + tag_name + "~" + tag_attr;
                }
                int tag_val_start = temp.find('"', tag_attr_end) + 1;
                int tag_val_end = temp.find('"', tag_val_start) - 1;
                start_position = tag_val_end + 2;
                tag_val = temp.substr(tag_val_start, tag_val_end-tag_val_start+1);
                m[tag_key] = tag_val;
            }
            if (opening_tag.size() == 0){
                opening_tag = tag_name;
            }
            else {
                opening_tag += "." + tag_name;
            }
        }
    }

    for (int i = 0; i < queries; ++i){
        std::string q_key;
        std::cin >> q_key;
        auto it = m.find(q_key);
        if (it != m.end())
            std::cout << m[q_key] << std::endl;
        else {
            std::cout << "Not Found!" << std::endl;
        }
    }

    return 0;
}