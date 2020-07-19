// https://www.hackerrank.com/challenges/attribute-parser/problem

/*
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int row, queries;
    std::cin >> row >> queries;
    std::string nested_tag = "";
    std::string temp;
    std::string tag_name;
    std::string tag_attr;
    std::string tag_val;
    std::string opening_tag {};
    std::string tag_key;

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
            int start_tag_pos = temp.find("<");
            int end_tag_pos = temp.find(" ", start_tag_pos);
            tag_name = temp.substr(start_tag_pos +1, end_tag_pos - start_tag_pos - 1);
            int tag_attr_end = temp.find(" ", end_tag_pos + 1);
            tag_attr = temp.substr(end_tag_pos+1, tag_attr_end-end_tag_pos-1);
            if (opening_tag.size() == 0){
                tag_key = tag_name + "~" + tag_attr;
                opening_tag = tag_name;
            }
            else {
                tag_key = opening_tag + "." + tag_name + "~" + tag_attr;
                opening_tag += "." + tag_name;
            }
            int tag_val_start = temp.find('"', tag_attr_end) + 1;
            int tag_val_end = temp.find('"', tag_val_start) - 1;
            tag_val = temp.substr(tag_val_start, tag_val_end-tag_val_start+1);
            m[tag_key] = tag_val;
        }
    }

    auto it_all = m.begin();
    while (it_all != m.end()){
        std::cout << it_all->first << " = " << it_all->second << std::endl;
        ++it_all;
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