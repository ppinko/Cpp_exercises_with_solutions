// https://edabit.com/challenge/pv39bCFoACLiuKMAo

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

bool ascending(std::string str) 
{
	int limit = str.size() / 2;
    int length_check = 1;
    bool flag = true;
    while (length_check <= limit)
    {   
        flag = true;
        int start = std::stoi(str.substr(0, length_check));
        int j = length_check;  
        while (j < str.size())
        {
            int next = std::stoi(str.substr(j, length_check));
            if (next - start != 1)
            {   
                flag = false;
                break;
            }
            start = next;
            j += length_check;
        }
        if (flag)
        {
            return true;
        }
        ++length_check;
    }
    return false; 
}

int main(){

    std::cout << std::boolalpha;
    std::cout << ascending("232425") << std::endl;

    return 0;
}