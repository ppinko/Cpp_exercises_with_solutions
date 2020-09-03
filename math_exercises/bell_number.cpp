// https://edabit.com/challenge/RonK4TTo87c4qCpry

#include <vector>
#include <cassert>
#include <iostream>

int bell(int n) {
    // base case
	if (n == 1)
        return 1;
    std::vector<std::vector<int>> v (n, std::vector<int> (n, 0));
    
    // n = 1, result equals also 1
    v.at(0).at(0) = 1;

    // bottom-up approach
    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i <= j; ++i)
        {
            if (i == 0)
            {
                v.at(j).at(i) = v.at(j-1).at(j-1);
            } else {
                v.at(j).at(i) = v.at(j-1).at(i-1) + v.at(j).at(i-1);
            } 
        }
    }
    return v.at(n-1).at(n-1);
}

int main(){

    assert((bell(1) == 1));
    // std::cout << bell(3) << std::endl;
	assert((bell(2) == 2));
	assert((bell(3) == 5));
	assert((bell(4) == 15));
	assert((bell(5) == 52));
	assert((bell(6) == 203));

    return 0;
}