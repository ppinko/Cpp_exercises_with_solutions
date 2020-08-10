// https://edabit.com/challenge/DT2aPWpeZxy82GZon

#include <cassert>
#include <iostream>
#include <string>

bool firstBeforeSecond(std::string str, char first, char second) {
	int sec = str.find_first_of(second);
    if (sec == -1)
        return true;
    int fst = str.find_last_of(first);
    return (fst < sec);
}

int main()
{
    assert((firstBeforeSecond("a rabbit jumps joyfully", 'a', 'j') == true));
	assert((firstBeforeSecond("knaves knew about waterfalls", 'k', 'w') == true));
	assert((firstBeforeSecond("maria makes money", 'm', 'o') == true));
	assert((firstBeforeSecond("the hostess made pecan pie", 'h', 'p') == true));
	assert((firstBeforeSecond("barry the butterfly flew away", 'b', 'f') == true));
	assert((firstBeforeSecond("moody muggles", 'm', 'g') == true));
	assert((firstBeforeSecond("happy birthday", 'a', 'y') == false));
	assert((firstBeforeSecond("precarious kangaroos", 'k', 'a') == false));
	assert((firstBeforeSecond("maria makes money", 'm', 'i') == false));
	assert((firstBeforeSecond("taken by the beautiful sunrise", 'u', 's') == false));
	assert((firstBeforeSecond("sharp cheddar biscuit", 't', 's') == false));
	assert((firstBeforeSecond("moody muggles", 'm', 'o') == false));

    std::cout << "Success" << std::endl;

    return 0;
}