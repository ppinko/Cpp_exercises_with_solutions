// https://edabit.com/challenge/XszrQMmEbnWA6ve8b

#include <cassert>
#include <iostream>

#include <algorithm>
#include <string>
#include <set>

using namespace std;

int periodic(string n) {
	string base {n};
    int length = base.size();
    int iterations = 0;
    set<string> nums {base};
    while (true){
        ++iterations;
        int temp = 0;
        for (const auto &c : base){
            temp += static_cast<int>(c) - 48;
        }
        string str_temp = to_string(temp);
        base.append(str_temp);
        if (base.size() != length)
            base = base.substr(base.size() - length, length);
        std::set<string>::iterator it = nums.find(base);
        
        if (it != nums.end())
            return iterations;
        else
            nums.insert(base);
    }
}

int main(){

    assert((periodic("2") == 1));
	assert((periodic("22") == 13));
	assert((periodic("157") == 4));
	assert((periodic("1234567") == 943));
	assert((periodic("1818") == 1));
	assert((periodic("0000001") == 778));

    cout << static_cast<int>('0') << endl; // 48

    cout << "Success" << endl;

    return 0;
}