// https://edabit.com/challenge/u5ScK7AcPwtpPdizy

#include <string>
#include <iostream>
#include <cassert>
#include <iomanip>

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else if (n == 2 || n == 3) 
    {
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0)
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

std::string truncatable(int num) {
    std::string str = std::to_string(num);
    bool left = true, right = true;
    if (str.find('0') != std::string::npos)
        return "none";
    std::string temp_left, temp_right;
    for (int i = 0, j = 1; i < str.size(); ++i, ++j){
        temp_left = str.substr(0, j);
        temp_right = str.substr(str.size()-j, j);
        int lefty = std::stoi(temp_left);
        int righty = std::stoi(temp_right);
        if (right && !isPrime(lefty)){
            right = false;
        }
        if (left && !isPrime(righty)){
            left = false;
        }
    }
    if (left && right)
        return "both";
    else if (left)
        return "left";
    else if (right)
        return "right";
    else
        return "none";
}

int main(){

    std::cout << std::boolalpha;
    std::cout << truncatable(62383) << std::endl;
    assert((truncatable(47) == "left"));
	assert((truncatable(347) == "left"));
	assert((truncatable(62383) == "left"));
	assert((truncatable(79) == "right"));
	assert((truncatable(7331) == "right"));
	assert((truncatable(233993) == "right"));
	assert((truncatable(3797) == "both"));
	assert((truncatable(739397) == "both"));

    return 0;
}