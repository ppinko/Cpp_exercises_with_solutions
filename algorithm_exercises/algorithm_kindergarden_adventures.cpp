// https://www.hackerrank.com/challenges/kindergarten-adventures/problem

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

int solve(std::vector<int> t) {
    int max_ready = 0;
    int optimal_pos = 0;
    int last = 0;
    int ready = 0;
    int vec_len = t.size();
    for (int i = 0; i < vec_len; ++i, ++last)
    {
        ready = 0;
        int start = vec_len - last - 1;
        for (int j = 0; j < vec_len; ++j, ++start)
        {
            if (start == vec_len)
            {
                start = 0;
            }
            if (t[j] - start <= 0)
            {
                ++ready;
            }
        }
        if (ready > max_ready)
        {   
            max_ready = ready;
            optimal_pos = last + 2;
        }
        if (i == vec_len - 1 && ready == max_ready)
        {
            optimal_pos = 1;
        }
        std::cout << "i = " << i << ", max_ready = " << max_ready <<
            ", optimal =" << optimal_pos << std::endl;
    }
    return optimal_pos;
}

// int solve(std::vector<int> t) {
//     int max_ready = 0;
//     int optimal_pos = 0;
//     int vec_len = t.size();
//     std::vector<int> timing (vec_len, 0);
//     std::iota(timing.begin(), timing.end(), 0);
//     for (int i = 0; i < vec_len; ++i)
//     {
//         int ready = 0;
//         for (int j = 0; j < vec_len; ++j)
//         {
//             if (t[j] - timing[j] <= 0)
//             {
//                 ++ready;
//             }
//         }
//         if (ready > max_ready)
//         {   
//             max_ready = ready;
//             if (i == 0)
//             {
//                 optimal_pos = 1;
//             }
//             else 
//             {
//                 optimal_pos = vec_len + 1 - i;
//             }
//         }
//         else if (ready == max_ready && optimal_pos > vec_len + 1 - i)
//         {
//             optimal_pos = vec_len + 1 - i;
//         }
//         std::rotate(timing.begin(), timing.begin() + 1, timing.end());
//     }
//     return optimal_pos;
// }

int main(){

    std::vector<int> v {1, 2, 3, 0};
    std::cout << solve(v) << std::endl;

    return 0;
}