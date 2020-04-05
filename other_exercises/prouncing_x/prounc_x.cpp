#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/*
Replace all x's with "cks" UNLESS:

    The word begins with "x", therefore replace it with "z".
    The word is just the letter "x", therefore replace it with "ecks".
*/

std::string xPronounce(std::string str) {
    int x = std::count(str.begin(), str.end(), 'x');
    while (x > 0){
        int y = str.find('x');
        if (y == 0){
            if (str[y+1] == ' '){
                str.replace(y, 1, "ecks");
            }
            else 
                str.replace(y, 1, "z");
            }
        else if (y == str.length() - 1){
            if (str[y-1] == ' '){
                str.replace(y, 1, "ecks");
            }
            else 
                str.replace(y, 1, "cks");
            }            
        else {
            if (str[y-1] == ' ' && str[y+1] == ' '){
                str.replace(y, 1, "ecks");
            }
            else if (str[y-1] == ' '){
                str.replace(y, 1, "z");
            }
            else 
                str.replace(y, 1, "cks");
            }  
        x--;
    }
    return str;
}


int main(){
    std::cout << xPronounce("Inside the box was a xylophone") << std::endl;
    std::cout << xPronounce("The x ray is excellent") << std::endl;
    return 0;
}