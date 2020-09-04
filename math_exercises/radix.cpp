// Non-Repeating Integers
// https://edabit.com/challenge/SJLZ6thTfCsFWgvYv

#include <cassert>
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    std::vector<int> v (n, 0);
    std::iota(v.begin(), v.end(), 1);
    int v_product = std::accumulate(v.cbegin(), v.cend(), 
        1, std::multiplies<int>());
    return v_product;
}

int number_permutations(int n, int r)
{
    return factorial(n) / factorial(r);
}

int nonRepeats(int radix) {
	if (radix < 2)
        return -1;
    int total = 0;
    for (int i = 1; i <= radix; ++i)
    {
        if (i == 1){
            total += radix - i;
        } 
        else if (i == radix){
            total += (radix - 1) * factorial(radix - 1);
        } else {
            total += (radix - 1) * number_permutations(radix - 1, i-1);             
        }
    }
    return total;
    
}

int main(){

    assert((nonRepeats(2) == 2));
	assert((nonRepeats(8) == 95900));
	assert((nonRepeats(10) == 8877690));
	assert((nonRepeats(3) == 10));

    return 0;
}