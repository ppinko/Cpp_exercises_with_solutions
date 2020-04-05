/*
Mini Sudoku

A Sudoku is a 9x9 grid that is completed when every 3x3 square, row and column consist of the numbers 1-9.

For this task, you will be given a completed 3x3 square, in the form of a two-dimensional array. Create
a function that checks to make sure this 3x3 square contains each number from 1-9 exactly once. Make sure
there are no duplicates, and no numbers outside this range.

Examples

isMiniSudoku([[1, 3, 2], [9, 7, 8], [4, 5, 6]]) ➞ true

isMiniSudoku([[1, 1, 3], [6, 5, 4], [8, 7, 9]]) ➞ false
// The 1 is repeated twice

isMiniSudoku([[0, 1, 2], [6, 4, 5], [9, 8, 7]]) ➞ false
// The 0 is included (outside range)

isMiniSudoku([[8, 9, 2], [5, 6, 1], [3, 7, 4]]) ➞ true

*/

#include <iostream>
#include <vector>

using namespace std;

bool isMiniSudoku(std::vector<std::vector<int>> square) {
	int compared_array [9] {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int temp_array [9] {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i {0}; i <= 2; i++) {
            for (int k {0}; k <= 2; k++) {
                if (square[i][k] < 1 || square[i][k] > 9) {
                    return false;
                }
                else {
                    for (int j {0}; j < 9; j++){
                        if (square[i][k] == compared_array[j]){
                            temp_array[j] -= square[i][k];
                                if (temp_array[j] != 0) {
                                    return false;
                                }
                        }
                    }
                }
            }
    }
    return true;
}

int main(){
    cout << boolalpha << endl;
    cout << isMiniSudoku({{1, 3, 2}, {9, 7, 8}, {4, 5, 6}}) << endl;
    cout << isMiniSudoku({{1, 1, 2}, {9, 7, 8}, {4, 5, 6}}) << endl;
    return 0;
}
