// https://edabit.com/challenge/aZBfsFhLZmE384E5m

#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool validName(const string &name) {
	vector<string> names {};
    string temp_word;
    istringstream iss {name};
    while (iss >> temp_word){
        names.push_back(temp_word);
    }

    // checking right number of names
    if (names.size() <= 1 || names.size() > 3)
        return false;

    vector<bool> initials {};
    for (const auto &_name: names){
        // name must start with capital letter
        if (!isupper(_name[0]) || _name.size() == 1)
            return false;

        // checking if it's initial and filling in initials vector
        if (_name.find('.') != string::npos){
            if (_name.size() == 2 && isupper(_name[0])){
                initials.push_back(true);
            }
            else {
                return false;
            }
        }
        else {
            initials.push_back(false);
        }
    }

    // family name must be fully written
    if (initials.back())
        return false;
    
    // if first name is written with initials the second one must be too
    if (initials.size() == 3 && (initials[0] && !initials[1]))
        return false;

    return true;
}

int main(){

    assert((validName("H. Wells") == true));
    assert((validName("H. G. Wells") == true));
    assert((validName("Herbert G. Wells") == true));
    assert((validName("Herbert George Wells") == true));

    assert((validName("Herbert") == false));
    assert((validName("Herbert W. G. Wells") == false));
    assert((validName("h. Wells") == false));
    assert((validName("herbert G. Wells") == false));
    assert((validName("H Wells") == false));
    assert((validName("Herb. Wells") == false));
    assert((validName("H. George Wells") == false));
    assert((validName("Herbert George W.") == false));

    cout << "success" << endl;
    cout << 100 << endl;

    return 0;
}