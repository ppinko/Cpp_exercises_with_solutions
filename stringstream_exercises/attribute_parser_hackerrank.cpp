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
    std::string opening_tag {};
    std::string tag_key;

    std::map<std::string, std::string> m {};
    for (int i = 0; i <= row; ++i)
    {   
        std::getline(std::cin, temp);
        if (temp.find("<tag") != std::string::npos)
        {
            int start_tag_pos = temp.find("<tag");
            int end_tag_pos = temp.find(" ", start_tag_pos);
            tag_name = temp.substr(start_tag_pos +1, end_tag_pos - start_tag_pos - 1);
            std::cout << tag_name << std::endl;
            int tag_attr_end = temp.find(" ", end_tag_pos + 1);
            tag_attr = temp.substr(end_tag_pos+1, tag_attr_end-end_tag_pos-1);
            if (opening_tag.size() == 0){
                tag_key = tag_name + "~" + tag_attr;
            }
            std::cout << tag_key << std::endl;
        }
        
    }


    return 0;
}