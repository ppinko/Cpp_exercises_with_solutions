#include <iostream>
#include <string>
#include <cctype>

std::string accum(std::string str){
    std::string new_str;
    for (int i {0}; i < str.length(); i++){
        std::string temp (i, std::tolower(str[i]));
        new_str += std::toupper(str[i]);
        new_str += temp;
				if (i != str.length() - 1)
					new_str += '-';
    }
    return new_str;
}

int main(){
    std::cout << accum("RqaEzty") << " = R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy" << "\n";
    return 0;
}