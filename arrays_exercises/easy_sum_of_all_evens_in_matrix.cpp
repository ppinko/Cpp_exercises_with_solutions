/*
https://edabit.com/challenge/xe43hz5DJuTewb5nA
*/

#include <iostream>
#include <vector>


int sumOfEvens(std::vector<std::vector<int>> arr) {
    int n {0};
    for (auto i: arr){
        for (int j: i){
            if (j % 2 == 0)
                n += j;
        }
    }
	return n;
}

int main(){

    return 0;
}