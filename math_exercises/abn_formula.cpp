// https://edabit.com/challenge/Fe9X2DxpSCMun6t5D


#include <string>
#include <iterator>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

std::vector<int> binomialCoeff(int n);
std::string Formula(int n);

// Returns value of Binomial Coefficient C(n, k) 
std::vector<int> binomialCoeff(int n) 
{ 
    std::vector<std::vector<int>> v (n+1, std::vector<int> (n+1, 0));
    int i, j; 
  
    // Caculate value of Binomial Coefficient 
    // in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= i; j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                v[i][j] = 1; 
  
            // Calculate value using previously 
            // stored values 
            else
                v[i][j] = v[i - 1][j - 1] + 
                          v[i - 1][j]; 
        } 
    } 
  
    return v[n]; 
} 

std::string Formula(int n) {
    return "yes";
}

int main(){

    auto vec = binomialCoeff(1);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}