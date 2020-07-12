// https://edabit.com/challenge/daj2nHY4Zs2X6FZx5


#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cmath>

std::vector<int> split_vec(std::vector<int> v)
{
    std::vector<int> res {};
    int len = v.size();
    int num_size = len / 2;
    int a = 0, b = 0;
    if (len % 2 == 0)
    {
        for (int i = 0, j = 0; i < num_size; ++i, ++j)
        {
            a += v[len - i - 1] * std::pow(10, j);
            b += v[num_size - i - 1] * std::pow(10, j);
        }
    }
    else
    {   
        int j = 0;
        for (int i = 0; i < num_size; ++i, ++j)
        {
            a += v[len - i - 1] * std::pow(10, j);
            b += v[num_size - i] * std::pow(10, j);
        }
        b += v[0] * std::pow(10, j);           
    }
    res.push_back(a);
    res.push_back(b);
    return res;
}

std::string isVampire(int n) {
    int copy_n = n;
	if (n < 100)
    {
        return "Normal Number";
    }
    std::vector<int> v {};
    while (n != 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    int len = v.size();
    std::vector<int> first = v;
    std::vector<int> temp;
    do 
    {
        temp = split_vec(v);
        if (temp[0] * temp[1] == copy_n)
        {
            if (len % 2 == 0)
            {
                return "True Vampire";
            }
            else 
            {
                return "Pseudovampire";
            }
        }
        else
        {
            std::next_permutation(v.begin(), v.end());
        }
    }
    while (v != first);
    return "Normal Number";
}

int main(){

    // std::vector<int> vec {1, 2, 6, 0};
    // std::vector<int> test = split_vec(vec);
    // std::cout << test[0] << " % " << test[1] << std::endl;

    // std::cout << isVampire(1260) << std::endl;

    assert((isVampire(1260) == "True Vampire"));
	assert((isVampire(126) == "Pseudovampire"));
	assert((isVampire(67) == "Normal Number"));
	assert((isVampire(1) == "Normal Number"));

    std::cout << "Success" << std::endl;
    return 0;
}