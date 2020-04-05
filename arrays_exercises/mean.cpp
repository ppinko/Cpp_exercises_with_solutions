/*
Create a function that takes an array of numbers and returns the mean value.

Examples:

mean([1, 0, 4, 5, 2, 4, 1, 2, 3, 3, 3]) ➞ 2.55

mean([2, 3, 2, 3]) ➞ 2.50

mean([3, 3, 3, 3, 3]) ➞ 3.00

Notes

    Round to two decimal places.
    You can expect a number ranging from 0 to 10,000.

*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

float mean(std::vector<int> arr) {
	int sum_val {0};
	for (size_t i {0}; i < arr.size(); i++){
		sum_val += arr[i];
	}
	float mean_val = static_cast<float>(sum_val) / arr.size();
	mean_val = round(mean_val * 100) / 100;
	return mean_val;
}

int main(){
    cout << mean({1, 0, 4, 5, 2, 4, 1, 2, 3, 3, 3}) << " should equals 2.55" << endl;
    cout << mean({324, 543, 654, 9876}) << " should equals 2849.25" << endl;
    cout << mean({0, 0, 0, 0}) << " should equals 0.00" << endl;
    return 0;
}