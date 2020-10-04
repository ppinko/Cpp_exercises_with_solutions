// https://edabit.com/challenge/R3jHbeLbJ2tMaSFoq

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

string edabitInString(const string &str) {
	const string edabit {"edabit"};
    auto it_edabit = begin(edabit);
    auto it_str = begin(str);
    while(it_edabit != end(edabit) && it_str != end(str)){
        if (*it_edabit == *it_str){
            ++it_edabit;       
        }
        ++it_str;
    }
    if (it_edabit == end(edabit))
        return "YES";
    else 
        return "NO";
}


int main(){

    assert((edabitInString("eddaaabt") == "NO"));
	assert((edabitInString("edwardisabletodoittoo") == "YES"));
	assert((edabitInString("abecdfghijklmnopqrstuvwxyz") == "NO"));
	assert((edabitInString("edisthebestatthis") == "NO"));
	assert((edabitInString("teachandlearnbitbybit") == "YES"));
	assert((edabitInString("fjkdlkskkkkkdkkdkdedaaakkjkkdkkdklqiieuirooeizooziiciibiiiiifooiioiiuuyeyttgguoosooodiifiufiiodikkjkls") == "YES"));

    cout << "success" << endl;

    return 0;
}