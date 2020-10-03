// https://edabit.com/challenge/sAkNHEKK8wu4fnyYL

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int firstIndex(const string &str_hex, const string &needle) {
    istringstream oss {str_hex};
    string temp {}, translated {};
    while (oss >> temp){
        stringstream ss;
        int x;
        ss << std::hex << temp;
        ss >> x;
        translated += (char)x;
    }
    return translated.find(needle);
}


int main(int argc, char *argv[]){

    cout << firstIndex("68 65 6c 6c 6f 20 77 6f 72 6c 64", "world") << endl;
    cout << std::stoi("1A", nullptr, 16); 

    return 0;
}