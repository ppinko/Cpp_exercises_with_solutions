// https,//edabit.com/challenge/EwJeurw9P2hksr7E4

#include <iostream>
#include <cassert>

#include <map>
#include <sstream>
#include <string>

using namespace std;

string numToEng(const int n) {
	
    ostringstream oss {};
    map<int, string> basic_numbers {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {30, "thirty"},
        {40, "fourty"},
        {50, "fifty"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"},
        {100, "hundred"}
    };
    if (basic_numbers.find(n) != basic_numbers.end()){
        auto it = basic_numbers.find(n);
        return it->second;
    }

    if (n > 100){
        auto it = basic_numbers.find(n / 100);
        oss << it->second << " hundred";
        if (n % 100 == 0)
            return oss.str();
        else 
            oss << " ";
    }
    
    if (basic_numbers.find(n % 100) != basic_numbers.end()){
        auto it = basic_numbers.find(n % 100);
        oss << it->second;
        return oss.str();
    }
    else {
        int num_tens = n % 100 - n % 10;
        if (num_tens != 0){
            auto it = basic_numbers.find(num_tens);
            oss << it->second;
            if (n % 10 != 0)
                oss << " ";
        }
    }

    auto it = basic_numbers.find(n % 10);
    oss << it->second;

    return oss.str();
}

int main(){

    assert((numToEng(0) == "zero"));
	assert((numToEng(26) == "twenty six"));
	assert((numToEng(519) == "five hundred nineteen"));
	assert((numToEng(106) == "one hundred six"));
	assert((numToEng(999) == "nine hundred ninety nine"));

    // cout << numToEng(999) << endl;
    cout << "success" << endl;

    return 0;
}