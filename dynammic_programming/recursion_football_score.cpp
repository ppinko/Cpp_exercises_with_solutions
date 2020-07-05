// https://edabit.com/challenge/Bt4fbnZZ7sbpvk3pN

#include <string>
#include <cassert>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <vector>

int football(int score) {
    if (score == 1) return 0;
    else if (score == 0 || score == 2 || score == 3) return 1;

    std::vector<std::vector <int> > dp (6, std::vector<int>(score+1, 0));
    std::vector<int> scoring {0, 2, 3, 6, 7, 8};
    
    dp[0][0] = 1;
    for (int i = 1; i < 6; i++){
        for (int j = 0; j <= score; j++){
            if (j - scoring[i] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j - scoring[i]];
        }
    }
    return dp[5][score];
}

int main(){
    assert((football(0) == 1));
	assert((football(1) == 0));
	assert((football(8) == 4));
	assert((football(19) == 18));
	assert((football(35) == 103));
	assert((football(66) == 804));
    std::cout << "Success" << std::endl;
    return 0;
}