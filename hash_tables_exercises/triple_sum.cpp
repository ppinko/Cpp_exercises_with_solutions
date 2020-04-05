/*
Triple Sum
https://www.hackerrank.com/challenges/triple-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search

Idea:
Iterate over second vector and see how many smaller elements are on the left and right, multiply those values 
and add to main sum

Complexity n**2

*/

#include <vector>
#include <algorithm>
#include <iostream>

long triplets(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());
    long sum_pos {0};
    int temp1 {0}; 
    int temp2 {0};
    int j = 0;
    int k = 0;
    for (const auto &i : b){
        while (j < a.size() && a[j] <= i){
            temp1 += 1;
            j++;
        }
        while (k < c.size() && (c[k] <= i)){
            temp2 += 1;
            k++;
        }
        sum_pos += temp1 * temp2;
    }
    return sum_pos;
}

int main(){
    std::vector<int> vec1 {1, 4, 5};
    std::vector<int> vec2 {2, 3, 3};
    std::vector<int> vec3 {1, 2, 3};
    std::cout << triplets(vec1, vec2, vec3) << std::endl;
    return 0;
}