// https://edabit.com/challenge/k9ZMQ9yY2tGSFEG9G

#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

int postfix(string expr) {
    vector<int> v {};
    istringstream iss {expr};
    string temp {};
    while (iss >> temp){
        int num {};
        if (temp != "+" && temp != "-" && temp != "/" && temp != "*"){
            num = stoi(temp);
            v.push_back(num);
            continue;
        }
        else if (temp == "+"){
            num = *(v.end() - 2) + v.back();
        }
        else if (temp == "-"){
            num = *(v.end() - 2) - v.back();
        }
        else if (temp == "*"){
            num = *(v.end() - 2) * v.back();
        }
        else if (temp == "/"){
            num = *(v.end() - 2) / v.back();
        }
        v.pop_back();
        v.back() = num;
    }
    return v.front();
}

int main(){

{
    assert((postfix("2 2 +") == 4));
	assert((postfix("2 3 * 1 - 5 /") == 1));
	assert((postfix("5") == 5));
	assert((postfix("10 10 * 10 /") == 10));
	assert((postfix("5 6 * 2 1 + /") == 10));
	assert((postfix("1 1 + 2 2 + -") == -2));
	assert((postfix("8 4 / 9 * 3 1 * /") == 6));
};

    cout << postfix("2 2 +") << endl;

    cout << "Success" << endl;

    return 0;
}