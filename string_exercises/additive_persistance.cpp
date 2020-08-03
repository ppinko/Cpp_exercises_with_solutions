// https://edabit.com/challenge/tCxDzrFbNS7om2RQi

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

int additivePersistence(int n) {
	int counter = 0;
    while (n > 9)
    {
        ++counter;
        int temp = 0;
        while (n != 0)
        {
            temp += n % 10;
            n /= 10;
        }
        n = temp;
    }
    return counter;
}

int multiplicativePersistence(unsigned long long int n) {
	int counter = 0;
    while (n > 9)
    {
        ++counter;
        unsigned long long int temp = 1;
        while (n != 0)
        {
            temp *= n % 10;
            n /= 10;
        }
        n = temp;
    }
    return counter;	
}

int main()
{

    assert((additivePersistence(5) == 0));
	assert((additivePersistence(27) == 1));
	assert((additivePersistence(58) == 2));
	assert((additivePersistence(5789) == 3));

    assert((multiplicativePersistence(7) == 0));
	assert((multiplicativePersistence(1234567890) == 1));
	assert((multiplicativePersistence(39) == 3));
	assert((multiplicativePersistence(6788) == 6));
	assert((multiplicativePersistence(277777788888899) == 11));

    return 0;
}