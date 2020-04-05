/*
https://edabit.com/challenge/3LbBqGsNdeMPLECXS
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <iterator>

bool palindromicDate(std::string date) {
	std::string year = date.substr(6, 4);
	std::reverse(year.begin(), year.end());
	std::string day = date.substr(0, 2);
	std::string month = date.substr(3, 2);
	if (day != month)
		return false;
	else if (day + month != year)
		return false;
	else
		return true;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << palindromicDate("02/02/2020") << " = true" << "\n";
    std::cout << palindromicDate("11/02/2011") << " = false" << "\n";
    return 0;
}