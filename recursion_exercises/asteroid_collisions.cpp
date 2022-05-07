#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

// https://edabit.com/challenge/z7ps9d2jmqY5ERCaT

bool collision(int a, int b)
{
    return (a > 0) && (b < 0) ? true : false;
}

int collisionOutput(int a, int b)
{
    if (a > std::abs(b))
    {
        return a;
    }
    else if (a < std::abs(b))
    {
        return b;
    }
    return 0;
}

std::vector<int> asteroidCollision(std::vector<int> asteroids)
{
    if (asteroids.size() < 2)
    {
        return asteroids;
    }
    std::vector<int> collisions{};

    bool finalRecursion{true};
    auto leftNum = asteroids.begin();
    auto rightNum = asteroids.begin() + 1;
    auto endIter = asteroids.end() - 1;
    while (leftNum != endIter)
    {
        if (collision(*leftNum, *rightNum))
        {
            finalRecursion = false;
            auto const collisionResult = collisionOutput(*leftNum, *rightNum);
            if (collisionResult != 0)
            {
                collisions.push_back(collisionResult);
            }

            leftNum += 2;
            rightNum += 2;
            if (leftNum == endIter)
            {
                collisions.push_back(*leftNum);
                break;
            }
            if (leftNum == asteroids.end())
            {
                break;
            }
        }
        else
        {
            collisions.push_back(*leftNum);
            leftNum++;
            rightNum++;
            if (leftNum == endIter)
            {
                collisions.push_back(*leftNum);
            }
        }
    }
    if (finalRecursion)
    {
        return collisions;
    }
    else
    {
        return asteroidCollision(collisions);
    }
}

int main()
{
    assert((asteroidCollision({5, 10, -5}) == std::vector<int>{5, 10}));
    assert((asteroidCollision({8, -8}) == std::vector<int>{}));
    assert((asteroidCollision({10, 2, -5}) == std::vector<int>{10}));
    assert((asteroidCollision({-2, -1, 1, 2}) == std::vector<int>{-2, -1, 1, 2}));
    assert((asteroidCollision({-2, 1, 1, -2}) == std::vector<int>{-2, -2}));
    assert((asteroidCollision({1, 1, -2, -2}) == std::vector<int>{-2, -2}));
    assert((asteroidCollision({-10, 66, -56, -9, -32, -41, 81, 10, 31, 65, -84, -73, -63, 94, -100, -56, -88, 41, 44, -45, -61, 12, 27, 85, -69, -26, -74, -18, -60, 90}) == std::vector<int>{-10, -84, -73, -63, -100, -56, -88, -45, -61, 12, 27, 85, 90}));
    assert((asteroidCollision({50, -36, 4, 35, 43, 72, -46, 68, 65, 94, -11, -78, -59, 15, -9, 1, 96, 42, 34, 60, -42, 5, 92, -55, 26, 39, -80, -18, -87, -51, 91, -21, -7, 80, -12, -61, -32, 6, -52, -67, 46, 24, -70, -64, -94}) == std::vector<int>{50, 4, 35, 43, 72, 68, 65, 94, 15, 1, 96}));
    assert((asteroidCollision({-24, 55, -68, 69, -35, 33, -75, -7, 9, -56, 71, 22, 59, -96, 1, -37, 61, -98, 30, -21, 57, -73, -3, -32, -93, -41, 63, 26, 41, 56, -60, 18, 67, 80, 100, -23, -53, 74, 49, 86, 48, 83, 40, 77, -57, 91, -8, 7, -33, 15, -92, 89, -48, 25, 66}) == std::vector<int>{-24, -68, -75, -7, -56, -96, -37, -98, -73, -3, -32, -93, -41, 63, 18, 67, 80, 100, 89, 25, 66}));
    assert((asteroidCollision({-25, -97, 57, -72, -85, 89, 81, -88, 24, -5, 75, 65, 12, 43, 25, 67, 34, 98, 10, 52, -42, -55, -87, -26, 31, -59, -47, 59, 72, -70, 30, -58, -62, 15, -71, 61, 69, -79, -34, 95, -28, -12, -40, -29, -100, 38, 36, -6, 94, 96, -76, -35, 18, 41, -80}) == std::vector<int>{-25, -97, -72, -85, -100, 38, 36, 94, 96}));
    std::cout << "success" << std::endl;

    return 0;
}