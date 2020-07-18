// https://edabit.com/challenge/jbPEN7JCfySFKBxxY

#include <string>
#include <iostream>
#include <cassert>

bool isPrime(int n);
int sum_numbers(int n);
std::string moran(int n);

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else if (n == 2 && n == 3) 
    {
        return true;
    }
    else if (n % 2 == 0 && n % 3 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 5; i < n; i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int sum_numbers(int n)
{   
    int ans = 0;
    while (n != 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

std::string moran(int n) 
{
    auto sumNumbers = sum_numbers(n);
    int temp = n / sumNumbers;
    if (n % sumNumbers != 0)
    {
        return "Neither";
    }
    else if (isPrime(temp))
    {
        return "M";
    }
    else 
    {
        return "H";
    }
}


int main(){
    assert((moran(132) == "H"));
	assert((moran(133) == "M"));
	assert((moran(134) == "Neither"));
	assert((moran(3033) == "M"));
	assert((moran(3030) == "H"));
	assert((moran(491423) == "Neither"));
	assert((moran(20937) == "M"));
    std::cout << "Success" << std::endl;
    return 0;
}