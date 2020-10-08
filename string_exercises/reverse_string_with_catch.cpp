// https://edabit.com/challenge/8P9NvjJRtnuiSBhJz

#include <iostream>
#include <cassert>

#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

string specialReverseString(string str) {
	string first {str};
    first.erase(std::remove(first.begin(), first.end(), ' '), first.end()); 
    reverse(first.begin(), first.end());
    for (int i = 0; i < str.size(); ++i){
        if (isspace(str.at(i))){
            first.insert(first.begin() + i, str.at(i));
        }
        else if (islower(str.at(i)) || !isalpha(str.at(i))){
            first.at(i) = tolower(first.at(i));
        }
        else {
            first.at(i) = toupper(first.at(i));
        }
    }
    return first;
}

int main()
{

    assert((specialReverseString("Edabit") == "Tibade"));
	assert((specialReverseString("UPPER lower") == "REWOL reppu"));
	assert((specialReverseString("1 23 456") == "6 54 321"));
	assert((specialReverseString("Hello World!") == "!dlro Wolleh"));
	assert((specialReverseString("Where's your dog Daisy?") == "?ysiadg odru oys 'erehw"));
	assert((specialReverseString("It's known that CSS means Cascading Style Sheets") == "Stee hsely tsgn IDA csacs Naemsscta Htnwo Nks'ti"));

    cout << "Success" << endl;

    return 0;
}