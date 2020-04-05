/*
https://edabit.com/challenge/Wv9ZeXyC32EMfRWGB
*/

#include <string>
#include <iostream>

std::string uncensor(std::string str, std::string vowels) {
	int vow_index {0};
	for (int i {0}; i < str.length(); i++){
		if (str[i] == '*'){
			str[i] = vowels[vow_index];
			vow_index++;
		}
	}
	return str;
}

int main(){
    std::cout << uncensor("*PP*RC*S*", "UEAE") << " = UPPERCASE" << "\n";
    return 0;
}
