// https://edabit.com/challenge/cMMYEBAx2kMSDvX86

#include <string>
#include <cassert>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

int strongPassword(std::string password) {
    int conditions = 0;
    if (std::any_of(password.begin(), password.end(), [](char c){return std::islower(c);}))
        conditions++;
    if (std::any_of(password.begin(), password.end(), [](char c){return std::isupper(c);}))
        conditions++;
    if (std::any_of(password.begin(), password.end(), [](char c){return std::isdigit(c);}))
        conditions++;
    if (std::any_of(password.begin(), password.end(), 
            [](char c){std::string special {"!@#$%^&*()-+"};
                    return special.find(c) != std::string::npos;}))
        conditions++;
    
    int passwd_length = 6 - password.length();
    int answer = std::fmax(4 - conditions, passwd_length);
    return answer;
}

int main(){
    assert((strongPassword("#Edabit") == 1));
	assert((strongPassword("Cr3ateAStr0ng1") == 1));
	assert((strongPassword("willthispass") == 3));
	assert((strongPassword("W1llth!spass?") == 0));
    std::cout << "Success" << std::endl;
    return 0;
}