/*
https://edabit.com/challenge/zYgqyHG4y2S8QHKTd
*/

#include <iostream>
#include <algorithm>
#include <vector>

int harry(int n, int m, std::vector<std::vector<int>> vv) {
	if (n == 0 && m == 0) return -1; 
	else if (n == 1 && m == 1) return vv.at(0).at(0); 
	std::vector<std::vector<int>> bottom_up (n, std::vector<int>(m));
	for (int i = n-1; i >= 0; i--){
		for (int j = m-1; j >= 0; j--){
			if (i == n-1 && j == m-1) bottom_up[i][j] = vv[i][j];
			else if (i == n-1) bottom_up[i][j] = vv[i][j] + bottom_up[i][j+1];
			else if (j == m-1) bottom_up[i][j] = vv[i][j] + bottom_up[i+1][j];
			else {
				bottom_up[i][j] = vv[i][j] + std::max(bottom_up[i+1][j], bottom_up[i][j+1]);
			}
		}		
	}
	return bottom_up[0][0];
}

int main(){
    std::cout << "Success" << std::endl;

    return 0;
}