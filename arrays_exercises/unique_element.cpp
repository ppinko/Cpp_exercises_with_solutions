/*
https://edabit.com/challenge/ou6E9eStZ2SiR8bTD
*/

#include <vector>
#include <iostream>

double unique(std::vector<double> arr) {
	for (int i {1}; i < arr.size() - 1; i++){
		if (arr[i] != arr[i-1] || arr[i] != arr[i+1]){
			if (arr[i] != arr[i-1] && arr[i] != arr[i+1])
				return arr[i];
			else if (arr[i] == arr[i-1])
				return arr[i+1];
			else
				return arr[i-1];
		}
	}
    return 0;
}

int main(){
    std::cout << unique({0, 0, 0.77, 0, 0}) << " = 0.77"<< "\n";
    return 0;
}