#include <cmath>
#include <string>
#include <iostream>

std::string isApocalyptic(int number) {
	std::string str = std::to_string(std::pow(2, number));
	int counter {0};
	int sub_counter {0};
	for (char c : str){
		if (c == '6'){
			sub_counter += 1;
			if (sub_counter == 3){
				counter += 1;
				sub_counter = 0;
			}
		}
		else
			sub_counter = 0;
	}
	switch (counter){
		case 0 : return "Safe"; break;
		case 1 : return "Single"; break;
		case 2 : return "Double"; break;
		case 3 : return "Triple"; break;
		default : return "More";
	}
}

int main(){
    std::cout << isApocalyptic(157) << " = Single" << std::endl;
    return 0;
}