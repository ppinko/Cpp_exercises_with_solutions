// https://edabit.com/challenge/w6M2vGaTm2bb2NFmh

#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int mysteryFunc(const int &num) {
	int first {}, second {};
    first = floor(log2(num));
    int temp = pow(2, first);
    second = num - temp;
    string combined (first, '2');
    combined.append(to_string(second));
    int answer = stoi(combined); 
    return answer;
}

int main(){

    cout << mysteryFunc(15) << endl;

    return 0;
}