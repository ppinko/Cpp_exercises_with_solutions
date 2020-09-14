// https://edabit.com/challenge/keLCuThwQRFZb9D94

#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int maxPossible(int n1, int n2) {
	string s1 = to_string(n1), s2 = to_string(n2);
    sort(s2.begin(), s2.end(), [](char a, char b){return a > b;});
    for (int i = 0, j = 0; i < s1.size(); ++i){
        if (j < s2.size() && s1.at(i) < s2.at(j)){
            s1.at(i) = s2.at(j);
            ++j;
        }
    }
    n1 = stoi(s1);
    return n1;
}

int main(){

    assert((maxPossible(9328, 456) == 9658));
	assert((maxPossible(523, 76) == 763));
	assert((maxPossible(9132, 5564) == 9655));
	assert((maxPossible(8732, 91255) == 9755));
	assert((maxPossible(589, 777) == 789));
	assert((maxPossible(1, 0) == 1));
	assert((maxPossible(8, 9) == 9));
	assert((maxPossible(28, 19) == 98));
	assert((maxPossible(12345, 4) == 42345));

    return 0;
}