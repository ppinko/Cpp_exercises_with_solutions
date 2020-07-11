#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>

int num(int a = 10);

int num(int a){
    return a * a;
}

int main(){

    std::string s1 = "developer";
    std::string s2 = "lop";
    std::cout << std::boolalpha;
    std::cout << std::includes(s1.cbegin(), s1.cend(), s2.cbegin(), s2.cend()) << std::endl;

    std::string s3 = "abcdef";
    std::string s4 = "cde";
    std::cout << std::includes(s3.cbegin(), s3.cend(), s4.cbegin(), s4.cend()) << std::endl;

    std::string str ("developer");
	std::rotate(str.begin(), str.begin() + 3, str.end());
    std::cout << str << std::endl;

    std::cout << ('a' > 'A') << std::endl;  // out: true
    std::cout << (int)'a' << " " << (int)'A' << std::endl;

    std::cout << num() << std::endl;    // out: 100
    std::cout << num(5) << std::endl;   // out: 25

    return 0;
}