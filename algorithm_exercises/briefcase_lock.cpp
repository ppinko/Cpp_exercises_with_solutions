// https://edabit.com/challenge/oKwYyH4Xk4cktFodW

#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

int minTurns(string current, string target) {
	int total = 0;
    for (auto it_current = begin(current), it_target = begin(target);
        it_current != end(current); ++it_current, ++it_target){
            int a = static_cast<int>(*it_current) - static_cast<int>(0);
            int b = static_cast<int>(*it_target) - static_cast<int>(0);
            int temp = abs(a-b);
            if (temp > 5)
                temp = 10 - temp;
            total += temp;
        }
    return total;
}

int main(){


    assert((minTurns("4089", "5672") == 9));
    assert((minTurns("1732", "4444") == 9));
    assert((minTurns("7109", "2332") == 13));
    assert((minTurns("2391", "4984") == 10));
    assert((minTurns("1234", "3456") == 8));
    assert((minTurns("1111", "1100") == 2));
    assert((minTurns("1111", "0000") == 4));
    assert((minTurns("0000", "9999") == 4));

    cout << "success" << endl;
    cout << minTurns("4089", "5672") << endl;

    return 0;
}