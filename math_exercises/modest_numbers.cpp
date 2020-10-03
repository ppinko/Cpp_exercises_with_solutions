// https://edabit.com/challenge/Q7XYBfmgLHgyLCQfE

#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

bool isModest(int num) {
	if (num < 10)
        return false;
    int i = 1;
    int temp = pow(10, i);
    while (num / temp > 0){
        int left_side = num / temp;
        int right_side = num % temp;
        if (num % right_side == left_side){
            cout << left_side << endl;
            return true;
        }
        ++i;
        temp = pow(10, i);
    }
    return false;
}

int main(){
    cout << boolalpha;
    cout << isModest(3412) << endl;

    return 0;
}