// https://www.hackerrank.com/challenges/largest-rectangle/problem

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Complete the largestRectangle function below.
long largestRectangle(std::vector<int> h) {
    int limit = h.size() - 1;
    long max_rect = 0;
    for (int i = 0; i <= limit; ++i)
    {
        long temp = h[i];
        int n = 1, j = 1, k = 1;
        while (i - j >= 0)
        {
            if (temp <= h[i-j])
            {
                ++n;
                ++j;
            }
            else 
            {
                break;
            }
        }
        while (i + k <= limit)
        {
            if (temp <= h[i+k])
            {
                ++n;
                ++k;
            }
            else 
            {
                break;
            }
        }
        if (temp * n > max_rect)
        {
            max_rect = temp * n;
        }
        // std::cout << "I = " << i << ", rect = " << max_rect << std::endl;
    }
    return max_rect;
}

int main(){

    std::vector<int> v {11, 11, 10, 10, 10};
    std::cout << largestRectangle(v) << std::endl;

    return 0;
}