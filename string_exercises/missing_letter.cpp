#include <iostream>
#include <string>

#include <iostream>
#include <string>

std::string missingLetter(std::string str) {
	for (int i {0}; i < str.length() - 1; i++){
		if (int(str[i+1]) - int(str[i]) != 1){
			int temp = int(str[i]) + 1;
			char c = (char)temp;
			std::string s {c};
			return s;
		}
	}
	return "No Missing Letter";
}

int main(){
    std::cout << missingLetter("mnopqs") << " should equal to r" << std::endl;
    std::cout << missingLetter("ghijklmno") << " should equal to No Missing Letter" << std::endl;
    return 0;
}