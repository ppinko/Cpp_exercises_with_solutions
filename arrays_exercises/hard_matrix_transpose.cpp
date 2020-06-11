/*
https://edabit.com/challenge/4KaoDvxaFSmf38bPQ
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> transposeMatrix(std::vector<std::vector<int>> arr) {
	std::vector<std::vector<int>> transposed (arr.at(0).size(), std::vector<int> (arr.size()));
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.at(0).size(); j++){
            transposed[j][i] = arr[i][j];
        }
    }
    return transposed;
}


int main(){
    std::vector<std::vector<int>> m {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    transposeMatrix(m);
    std::cout << "Success" << std::endl;
    return 0;
}