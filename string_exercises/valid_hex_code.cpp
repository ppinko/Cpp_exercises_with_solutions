// https://edabit.com/challenge/ZhEBoaEfMcK6vT7Kx

#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <cctype>

bool isValidHexCode(std::string str) {
    if (str.size() != 7 || str.at(0) != '#')
        return false;
    for (int i = 1; i < str.size(); ++i)
    {
        if (std::isdigit(str.at(i)))
            continue;
        else if (std::islower(str.at(i)) && str.at(i) >= 'a' && str.at(i) <= 'f')
            continue;
        else if (std::isupper(str.at(i)) && str.at(i) >= 'A' && str.at(i) <= 'F')
            continue;
        else
            return false;
    }
    return true;
}

int main()
{

	// Valid HEX codes
	assert((isValidHexCode("#CD5C5C") == true));
	assert((isValidHexCode("#EAECEE") == true));
	assert((isValidHexCode("#eaecee") == true));
	assert((isValidHexCode("#123456") == true));
	assert((isValidHexCode("#987654") == true));
	assert((isValidHexCode("#CCCCCC") == true));
	// Length cannot exceed 6
	assert((isValidHexCode("#CD5C58C") == false));
	assert((isValidHexCode("#123CCCD") == false));
	assert((isValidHexCode("#9876543") == false));
	// Cannot have letters outside A F
	assert((isValidHexCode("#ZCCZCC") == false));
	assert((isValidHexCode("#Z88Z99") == false)); 
	assert((isValidHexCode("#CD5C5Z") == false));
	// Cannot have other unacceptable chars
	assert((isValidHexCode("#Z88!99") == false));
	assert((isValidHexCode("#CD5C&C") == false));
	assert((isValidHexCode("CD5CD#C") == false));
	// Should hav a hash as first character
	assert((isValidHexCode("CD5C5C") == false));

    return 0;
}