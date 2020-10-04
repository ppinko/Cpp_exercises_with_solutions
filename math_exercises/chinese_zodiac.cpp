// https://edabit.com/challenge/EE8zy9SQoTQ2kxzry

#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

string sexagenary(int year) {
	vector<string> stem { "Metal", "Water", "Wood", "Fire", "Earth"};
    vector<string> branch {"Monkey", "Rooster", "Dog", "Pig", "Rat", "Ox", 
                        "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep"};
    ostringstream oss {};
    int stem_pos = (year % 10) / 2;
    oss << stem.at(stem_pos) << " " << branch.at(year % 12);
    return oss.str();
}

int main(){

    assert((sexagenary(1971) == "Metal Pig"));
	assert((sexagenary(1927) == "Fire Rabbit"));
	assert((sexagenary(2017) == "Fire Rooster"));
	assert((sexagenary(2000) == "Metal Dragon"));
	assert((sexagenary(1958) == "Earth Dog"));
	assert((sexagenary(1942) == "Water Horse"));
	assert((sexagenary(1974) == "Wood Tiger"));

    cout << "success" << endl;
    cout << sexagenary(1971) << endl;

    return 0;
}