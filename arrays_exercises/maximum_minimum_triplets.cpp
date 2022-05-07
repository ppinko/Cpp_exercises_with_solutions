// https://edabit.com/challenge/5GXcpepqLahRxveWq

#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>

int maxProduct(std::vector<int> arr)
{
    std::sort(arr.begin(), arr.end());
    auto const len = arr.size();
    // only 3 numbers available, no choice
    if (len == 3)
    {
        return arr[0] * arr[1] * arr[2];
    }
    // all numbers are not greater than 0, result is negative
    else if (arr[len - 1] <= 0)
    {
        return arr[len - 3] * arr[len - 2] * arr[len - 1];
    }
    // only one positive number, in general result is positive
    else if (arr[len - 2] <= 0)
    {
        return arr[0] * arr[1] * arr[len - 1];
    }
    // only two positive number, result is negative
    else if (arr[len - 3] <= 0)
    {
        return arr[len - 3] * arr[len - 2] * arr[len - 1];
    }
    // only one negative number
    else if (arr[1] >= 0)
    {
        return arr[len - 3] * arr[len - 2] * arr[len - 1];
    }
    // better two take the lowest numbers than 2nd and 3rd the biggest
    else if (arr[0] * arr[1] > arr[len - 3] * arr[len - 2])
    {
        return arr[0] * arr[1] * arr[len - 1];
    }
    // simply take three highest numbers
    else
    {
        return arr[len - 3] * arr[len - 2] * arr[len - 1];
    }
}

int minProduct(std::vector<int> arr)
{
    std::sort(arr.begin(), arr.end());
    auto const len = arr.size();
    // only 3 numbers available, no choice
    if (len == 3)
    {
        return arr[0] * arr[1] * arr[2];
    }
    // all numbers are positive, take simple 3 lowest numbers
    else if (arr[0] >= 0)
    {
        return arr[0] * arr[1] * arr[2];
    }
    // only one negative number, in general result is negative
    else if (arr[1] >= 0)
    {
        return arr[0] * arr[len - 2] * arr[len - 1];
    }
    // only two negative number, result is negative
    else if (arr[2] >= 0)
    {
        return arr[0] * arr[len - 2] * arr[len - 1];
    }
    // only one positive number
    else if (arr[len - 2] <= 0)
    {
        return arr[0] * arr[1] * arr[2];
    }
    // better two take the highest numbers than 2nd and 3rd the lowest
    else if (arr[1] * arr[2] < arr[len - 2] * arr[len - 1])
    {
        return arr[0] * arr[len - 2] * arr[len - 1];
    }
    // simply take three lowest numbers
    else
    {
        return arr[0] * arr[1] * arr[2];
    }
}

int main()
{
    assert((maxProduct({1, -1, 1}) == -1));
    assert((maxProduct({1, -1, 1, 1}) == 1));
    assert((maxProduct({-8, -9, 1, 2, 7}) == 504));
    assert((maxProduct({-8, 1, 2, 7, 9}) == 126));
    assert((maxProduct({1, 1, 5, 1, 1, -10, -1}) == 50));
    assert((maxProduct({-8, -7, -6, -5}) == -210));
    assert((maxProduct({-8, -7, -6, -5, 1}) == 56));
    assert((maxProduct({1, 0, 1, 0, 0}) == 0));
    assert((maxProduct({-5, 1, 10, 0, 0}) == 0));
    assert((maxProduct({-5, -1, -1, 0, 0}) == 0));
    assert((maxProduct({-5, 1, -1, 0, 0}) == 5));
    assert((maxProduct({-5, -3, -1, 0, 4}) == 60));
    assert((maxProduct({5, 3, -1, 0, -4, 7, 7, 9}) == 441));
    assert((minProduct({1, -1, 1}) == -1));
    assert((minProduct({1, -1, 1, 1}) == -1));
    assert((minProduct({-8, -9, 1, 2, 7}) == -126));
    assert((minProduct({-8, 1, 2, 7, 9}) == -504));
    assert((minProduct({1, 1, 5, 1, 1, -10, -1}) == -50));
    assert((minProduct({-8, -7, -6, -5}) == -336));
    assert((minProduct({-8, -7, -6, -5, 1}) == -336));
    assert((minProduct({1, 0, 1, 0, 0}) == 0));
    assert((minProduct({-5, 1, 10, 0, 0}) == -50));
    assert((minProduct({-5, -1, -1, 0, 0}) == -5));
    assert((minProduct({-5, 1, -1, 0, 0}) == 0));
    assert((minProduct({-5, -3, -1, 0, 4}) == -15));
    assert((minProduct({5, 3, -1, 0, -4, 7, 7, 9}) == -252));

    std::cout << "Success" << std::endl;
    return 0;
}