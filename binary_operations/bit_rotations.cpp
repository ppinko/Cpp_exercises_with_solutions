// https://edabit.com/challenge/NgtAmTiF3sg4X2D38

#include <cassert>
#include <cmath>
#include <iostream>

int bitRotate(int n, int m, bool d)
{
    // transformation does not effect '0'
    if (n == 0)
    {
        return n;
    }

    // num of important bits
    int len = std::floor(std::log2(n)) + 1;

    // eliminate unnecessary rotations
    m = m % len;

    // right rotation
    if (d)
    {
        int a = ((static_cast<int>(std::pow(2, m)) - 1) & n) << (len - m);
        int b = n >> m;
        return a | b;
    }
    // left rotation
    else
    {
        int a = (n << m) & (static_cast<int>(std::pow(2, len)) - 1);
        int b = n >> (len - m);
        return a | b;
    }
}

int main()
{
    assert((bitRotate(8, 1, true) == 4));
    assert((bitRotate(16, 2, true) == 4));
    assert((bitRotate(283, 7, true) == 110));
    assert((bitRotate(16, 1, false) == 1));
    assert((bitRotate(17, 2, false) == 6));
    assert((bitRotate(122, 7, false) == 122));
    assert((bitRotate(125, 10, true) == 95));
    assert((bitRotate(1022, 8, false) == 767));
    assert((bitRotate(33, 6, true) == 33));

    std::cout << "Success" << std::endl;
    return 0;
}