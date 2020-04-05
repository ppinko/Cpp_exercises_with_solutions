#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

std::string sharedLetters(std::string str1, std::string str2) {
	std::string shared {};
	std::for_each(str1.begin(), str1.end(), [](char& c)
								{c = std::tolower(c);});
	std::sort(str1.begin(), str1.end());
    // std::cout << str1 << "\n";
	std::for_each(str2.begin(), str2.end(),[](char& c)
								{c = std::tolower(c);});
	std::sort(str2.begin(), str2.end());
    // std::cout << str2 << "\n";
	std::set_intersection(str1.begin(), str1.end(),
											 str2.begin(), str2.end(), 
												std::back_inserter(shared));
    auto last = std::unique(shared.begin(), shared.end());
	shared.erase(last, shared.end());
    return shared;
}

int main(){
    
    std::cout << sharedLetters("house", "home") << " = eho" << std::endl;
    std::cout << sharedLetters("Micky", "mouse") << " = m" << std::endl;
    return 0;
}