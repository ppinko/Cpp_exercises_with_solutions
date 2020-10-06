// https://edabit.com/challenge/g8doAJBg4dKKzzBZT

#include <cassert>
#include <iostream>

#include <vector>

using namespace std;

bool canSeeStage(vector<vector<int>> seats) {
	int rows = seats.size();
    int columns =seats.at(0).size();
    for (int i = 0; i < rows - 1; ++i){
        for (int j = 0; j < columns; ++j){
            if (seats.at(i).at(j) >= seats.at(i+1).at(j)){
                return false;
            }
        }
    }
    return true;
}

int main(){

    cout << "Success" << endl;

    return 0;
};