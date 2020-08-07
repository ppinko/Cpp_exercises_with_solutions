// https://edabit.com/challenge/AxyoBN9ZdMjEiyczm

#include <iostream>
#include <cassert>
#include <string>

bool isPalindrome(int n) {
    std::string str = std::to_string(n);
    if (str.size() <= 1)
        return true;
    
    int str_length = str.size();
    for (int i = 0; i < str_length; ++i)
    {
        if (str.at(i) != str.at(str_length - i - 1))
            return false;
    }
    return true;
}

int closestPalindrome(int n) {
    if (isPalindrome(n))
        return n;
    int i = 1;
    while (true)
    {
        if (isPalindrome(n-i))
            return n - i;
        else if (isPalindrome(n+i))
            return n + i;
        else
            ++i;
    }
}

int main()
{

	assert((closestPalindrome(887) == 888));
	assert((closestPalindrome(888) == 888));
	assert((closestPalindrome(27) == 22));
	assert((closestPalindrome(519) == 515));
	assert((closestPalindrome(4892) == 4884));
	assert((closestPalindrome(1) == 1));
	assert((closestPalindrome(100) == 99));
	assert((closestPalindrome(33344) == 33333));
	assert((closestPalindrome(123456) == 123321));
	assert((closestPalindrome(978215236) == 978212879)); 

}