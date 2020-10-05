// https://edabit.com/challenge/38irrYhBL8BbfBGnw

#include <cassert>
#include <iostream>

#include <string>
#include <cctype>
#include <set>

using namespace std;

bool vowelLinks(const string &str) {
	set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    for (int i = 1; i < str.size() - 1; ++i){
        if (isspace(str.at(i))){
            char last_letter = tolower(str.at(i-1));
            char first_letter = tolower(str.at(i+1));
            if (vowels.find(last_letter) != vowels.end() 
                && vowels.find(first_letter) != vowels.end()){
                    return true;
                }
        }
    }
    return false;
}

int main(){

	assert((vowelLinks("an open fire") == false));
	assert((vowelLinks("the sudden applause") == false));
	assert((vowelLinks("the large appliances") == true));
	assert((vowelLinks("creative environment") == true));
	assert((vowelLinks("Creative Environment") == true));
	assert((vowelLinks("beneficial luggage") == false));
	assert((vowelLinks("the eagle swooped down low") == true));
	assert((vowelLinks("this is not a drill") == false));
	assert((vowelLinks("Patrice Evra") == true));
	assert((vowelLinks("please log on to edabit") == true));
	assert((vowelLinks("the quick brown fox was sad") == false));

    cout << "Success" << endl;

    return 0;
};