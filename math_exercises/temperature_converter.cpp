/*
https://edabit.com/challenge/N4h5rzEYxNnmmqhSB
*/

#include <string>
#include <cmath>
#include <iostream>

std::string convert(std::string deg) {
	if (deg.find("°C") == std::string::npos && 
			deg.find("°F") == std::string::npos)
		return "Error";
	else if (deg.find("°C") != std::string::npos){
		int pos = deg.find("°C");
		long long fahrenheit = std::stoll(deg.substr(0, pos));
		fahrenheit = std::round(fahrenheit * 1.8 + 32);
		std::string ans_1 = std::to_string(fahrenheit) + "°F";
        return ans_1;
	}
	else {
		int pos = deg.find("°F");
		long long celcius = std::stoll(deg.substr(0, pos));
		celcius = std::round((celcius - 32) / 1.8);
		std::string ans_2 = std::to_string(celcius) + "°C";
        return ans_2;
	}
    return "End";
}

int main(){
    std::cout << convert("35°C") << " should equal to 95°F" << std::endl;
    std::cout << convert("19°F") << " should equal to -7°C" << std::endl;
    std::cout << convert("33") << " should equal to Error" << std::endl;
    return 0;
}