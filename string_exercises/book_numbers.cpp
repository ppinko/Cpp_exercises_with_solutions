// https://edabit.com/challenge/3GBPFYoHEusMvWxdB

#include <string>
#include <iostream>
#include <cassert>

std::string isbn13(std::string str) {
	int letters_count = 0;
    if (str.size() == 10){
        for (int i = 10, j = 0; i >= 1; --i, ++j){
            int temp;
            if (str[j] == 'X')
                temp = 10;
            else 
                temp = (int)str[j] - (int)'0';
            letters_count += i * temp;
        }
        if (letters_count % 11 != 0)
            return "Invalid";
        else {
            str.insert(0, "978");
            letters_count = 0;
            for (int i = 0; i < str.size() - 1; ++i){
                int temp = (int)str[i] - (int)'0';
                if (i % 2 == 0){
                    letters_count += temp;
                }
                else {
                    letters_count += 3 * temp;
                }
            }
            int remainder = 10 - letters_count % 10;
            std::string rem = std::to_string(remainder);
            if (remainder == 10)
                str.replace(12, 1, "0");
            else {
                str.replace(12, 1, rem);
            }
            return str;
        }
    }
    else {
        for (int i = 0; i < str.size(); ++i){
            int temp = (int)str[i] - (int)'0';
            if (i % 2 == 0){
                letters_count += temp;
            }
            else {
                letters_count += 3 * temp;
            }
        }
        if (letters_count % 10 == 0)
            return "Valid";
        else {
            return "Invalid";
        }
    }
}

int main(){

    assert((isbn13("9780316066525") == "Valid"));
	assert((isbn13("9783866155237") == "Valid"));
	assert((isbn13("9780345453747") == "Valid"));
	assert((isbn13("031606652X") == "Invalid"));
	assert((isbn13("9783876155237") == "Invalid"));
	assert((isbn13("0345453747") == "Invalid"));
	assert((isbn13("0316066524") == "9780316066525"));
	assert((isbn13("3866155239") == "9783866155237"));
	assert((isbn13("817450494X") == "9788174504944"));

    std::cout << "Success" << std::endl;

    return 0;
}