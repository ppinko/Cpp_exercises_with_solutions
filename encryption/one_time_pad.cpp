// https://edabit.com/challenge/6WkQfbASjhzWwgj5K

#include <iostream>
#include <cassert>

#include <string>

using namespace std;

string encrypt(const string &plncode, const string &pad) {
	
    auto it_pad = begin(pad);
    string encrypted {it_pad, it_pad + 5}; // first 5 numbers equal KEYID
    it_pad += 5;
    
    for (const auto &c : plncode){
        int temp = stoi(to_string(c)) - stoi(to_string(*it_pad));
        if (temp < 0){
            temp += 10;
        }
        encrypted.append(to_string(temp));
        ++it_pad;
    }
    return encrypted;
}


string decrypt(const string &cypcode, const string &pad) {
	if (cypcode.substr(0, 5) != pad.substr(0, 5))
        return "Error: Key IDs don't match.";

    auto it_cypcode = begin(cypcode);
    it_cypcode += 5;
    auto it_pad = begin(pad);
    it_pad += 5;

    string decrypted {};
    for (; it_cypcode != end(cypcode); ++it_cypcode, ++it_pad){
        char c1 = *it_cypcode, c2 = *it_pad;
        string s1 {c1}, s2 {c2};
        int i1 = stoi(s1), i2 = stoi(s2);
        int temp = i1 + i2;
        if (temp >= 10){
            temp -= 10;
        }
        decrypted.append(to_string(temp));
    }
    return decrypted;    
}

int main(){

    assert((encrypt("24955184247696969", "637197877682780836504704874690100607768768") == "6371956289367449331922"));
	assert((decrypt("6371956289367449331922", "442878365779404250678127528855846163827272") == "Error: Key IDs don't match."));
	assert((decrypt("6371956289367449331922", "637197877682780836504704874690100607768768") == "24955184247696969"));

    cout << "success" << endl;
    cout << decrypt("6371956289367449331922", "637197877682780836504704874690100607768768") << endl;

    return 0;
}