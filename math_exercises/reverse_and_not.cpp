// https://edabit.com/challenge/Q6BxBmvpXFo4rRgNn

#include <cassert>
#include <iostream>

#include <algorithm>
#include <string>

using namespace std;

string ReverseAndNot(int i) {
	string basic = to_string(i);
    string reversed {basic};
    reverse(reversed.begin(), reversed.end());
    reversed.append(basic);
    return reversed;
}

int main(){

	assert((ReverseAndNot(123) == "321123"));
	assert((ReverseAndNot(123456789) == "987654321123456789"));
	assert((ReverseAndNot(111) == "111111"));
	assert((ReverseAndNot(152) == "251152"));

    cout << "Success" << endl;

    return 0;
};