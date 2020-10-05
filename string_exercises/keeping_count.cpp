// https://edabit.com/challenge/6xJMo3NerTFXXWSz2

#include <iostream>
#include <cassert>

#include <string>
#include <algorithm>

using namespace std;

long digitCount(long num) {
	string s_num = to_string(num);
    string numbers {};
    for (const auto &n : s_num){
        int counter = count(s_num.begin(), s_num.end(), n);
        numbers.append(to_string(counter));
    }
    return stol(numbers);
}

int main(){

	assert((digitCount(221333) == 221333));
	assert((digitCount(136116) == 312332));
	assert((digitCount(2) == 1));
	assert((digitCount(3410515780) == 1122222112));
	assert((digitCount(24677734541) == 13133313131));
	assert((digitCount(79825929634) == 13121323111));
	assert((digitCount(36123594675) == 22112211212));
	assert((digitCount(62849835970) == 11212211211));
	assert((digitCount(29081455325) == 21111133123));
	assert((digitCount(94717270184) == 12323131212));
	assert((digitCount(72017589759) == 31113212322));
	assert((digitCount(53569357419) == 32312231112));
	assert((digitCount(33879999825) == 22214444211));
	assert((digitCount(33600360627) == 33333333311));
	assert((digitCount(12594580129) == 22221211222));
	assert((digitCount(36852564216) == 13122231213));
	assert((digitCount(34415793631) == 32221113132));
	assert((digitCount(76384607724) == 32112213312));
	assert((digitCount(8604519582) == 2111211221));
	assert((digitCount(70209476552) == 22221121222));
	assert((digitCount(20036302062) == 34422243423));
	assert((digitCount(77674727011) == 55151515122));
	assert((digitCount(17597066090) == 12122322323));
	assert((digitCount(79082080537) == 21321323112));
	assert((digitCount(30187177000) == 14213233444));
	assert((digitCount(72916170033) == 21121222222));
	assert((digitCount(11314637247) == 33232122122));
	assert((digitCount(69095956141) == 23132322212));
	assert((digitCount(66117263379) == 33222132221));
	assert((digitCount(30491133624) == 31212233112));

    cout << "success" << endl;

    return 0;
}