// https://edabit.com/challenge/Fe9X2DxpSCMun6t5D


#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> binomialCoeff(int n);
std::string formula(int n);

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

std::string formula(int n) {
    int n_pos = std::abs(n);
    std::vector<int> binomial_coefficients = binomialCoeff(n_pos);
    std::string ans {};
    if (n == 0)
        return "1";
    
    int a_pow, b_pow, temp;
    for (int i = 0; i < binomial_coefficients.size(); ++i)
    {
        a_pow = n_pos - i;
        b_pow = i;
        temp = binomial_coefficients[i];
        if (temp != 1)
        {
        ans.append(std::to_string(temp));
        }
        if (a_pow == 1)
        {
            ans.push_back('a');
        }
        else if (a_pow > 1)
        {
            ans.append("a^");
            ans.append(std::to_string(a_pow));
        }

        if (b_pow == 1)
        {
            ans.push_back('b');
        }
        else if (b_pow > 1)
        {
            ans.append("b^");
            ans.append(std::to_string(b_pow));
        }
        ans.push_back('+');
    }
    ans.erase(ans.size() - 1);
    
    if (n < 0)
    {   
        ans = "1/(" + ans + ")";
    }

    return ans;
}

int main(){

    // auto vec = binomialCoeff(4);
    // std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    std::string test_1 = formula(-2);
    std::cout << test_1 << std::endl;

    return 0;
}