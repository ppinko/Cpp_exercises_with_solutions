/*
https://edabit.com/challenge/qbpHHZYQrJnNYjtjn
*/


#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<int> > orderedMatrix(int a, int b) {
	std::vector<std::vector<int>> ans;
    int index = 1;
    for (int i {1}; i <= a; i++){
        std::vector<int> temp {};
        for (int j {1}; j <= b; j++){
            temp.push_back(index);
            index++;
        }
        ans.push_back(temp);
    }
    return ans;
}


// Alternative solution with constructor initialization

// std::vector<std::vector<int> > orderedMatrix(int a, int b) {
// 	std::vector<std::vector<int>> vect(a, std::vector<int>(b));
// 	int num = 1;
// 	for (int i = 0; i < a; i++) 
// 		for (int j = 0; j < b; j++)
// 			vect[i][j] = num++;
// 	return vect;
// }

int main(){
    std::cout << "Success" << std::endl;
    return 0;
}