/*
https://edabit.com/challenge/hgPeuTNMWXB3eBBTf
*/

#include <iostream>
#include <string>

std::string noYelling(std::string phrase) {
		while (phrase.back() == '?' || phrase.back() == '!'){
			if (phrase.at(phrase.length() - 2) == phrase.back())
				phrase.pop_back();
            else
                break;
        }
	return phrase;
}

int main(){
    std::cout << (noYelling("Oh my goodness!!!") == "Oh my goodness!") << std::endl;
    return 0;
}