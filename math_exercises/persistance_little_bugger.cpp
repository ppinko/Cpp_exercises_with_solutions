// https://edabit.com/challenge/j6zxMhNChzi5uKLvx

#include <cassert>

int bugger(int num) {
	int counter = 0;
    while (num > 9)
    {
        ++counter;
        int temp = 1;
        while (num != 0)
        {
            temp *= num % 10;
            num /= 10;
        }
        num = temp;
    }
    return counter;
}

int main()
{

	assert((bugger(39) == 3));
	assert((bugger(4) == 0));
	assert((bugger(25) == 2));
	assert((bugger(999) == 4));

    return 0;
}