// https://edabit.com/challenge/sf8SjYcqkwfdRYp3C

#include <cassert>
#include <iostream>

#include <cmath>
#include <string>

using namespace std;

int column(const string &str) {
    int value = 0;
	for (int i = 0, j = str.size() - 1; j >= 0; ++i, --j){
        int temp = static_cast<int>(str.at(j)) - 64;
        value += pow(26, i) * temp;
    }
    return value;
}

int main(){

    assert((column("A") == 1));
	assert((column("B") == 2));
	assert((column("Z") == 26));
	assert((column("AA") == 27));
	assert((column("BA") == 53));
	assert((column("BB") == 54));
	assert((column("CW") == 101));
	assert((column("DD") == 108));
	assert((column("PQ") == 433));
	assert((column("ZZ") == 702));
	assert((column("ABC") == 731));
	assert((column("ZZT") == 18272));
	assert((column("STVW") == 348059));

    cout << int('A') << endl; // 65

    cout << "Success" << endl;

    return 0;
};