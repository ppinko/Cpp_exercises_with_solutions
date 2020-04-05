/*
https://edabit.com/challenge/rtWB9o6vghtkPDMFX
*/

#include <iostream>
#include <string>
#include <cctype>

std::string inatorInator(std::string inv) {
	std::string str {inv};
	char c = std::tolower(inv[inv.length()-1]); 
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		str.append("-inator ");
	else str.append("inator ");
	str.append(std::to_string(inv.length()));
	str.append("000");
	return str;
}

int main(){
    std::cout << inatorInator("EvilClone") << " = EvilClone-inator 9000" << std::endl;
    return 0;
}