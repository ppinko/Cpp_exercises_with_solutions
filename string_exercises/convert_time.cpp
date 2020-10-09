// https://edabit.com/challenge/r2cxzqjmQPXMbbW53

#include <iostream>
#include <cassert>

#include <string>

using namespace std;

string convertTime(string str) {
	// firtly converting morning time (AM)
    if (*(str.end() - 2) == 'A'){
        if (str.substr(0, 2) == "12"){
            return "00" + str.substr(2, 6);
        }
        else {
            return str.substr(0, 8);
        }
    }
    // secondly converting evening time (PM)
    else {
        if (str.substr(0, 2) == "12"){
            return str.substr(0, 8);
        }
        else {
            int temp = stoi(str.substr(0, 2));
            temp += 12;
            return to_string(temp) + str.substr(2, 6);
        }
    }
}


int main(){

{
    assert((convertTime("07:05:45PM") == "19:05:45"));
	assert((convertTime("12:40:22AM") == "00:40:22"));
	assert((convertTime("12:45:54PM") == "12:45:54"));
	assert((convertTime("05:32:33PM") == "17:32:33"));
	assert((convertTime("11:59:59PM") == "23:59:59"));
	assert((convertTime("11:59:59AM") == "11:59:59"));
	assert((convertTime("06:00:19AM") == "06:00:19"));
};

    cout << "Success" << endl;

    return 0;
}