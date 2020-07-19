// https://www.hackerrank.com/challenges/deque-stl/problem

#include <iostream>
#include <deque> 
#include <climits>
#include <algorithm>

void printKMax(int arr[], int n, int k){
    std::deque<int> d {};
    for (int i = 0; i < n; ++i)
    {   
        while (!d.empty() && d.front() <= i - k)
            d.pop_front();
        
        while (!d.empty() && arr[i] >= arr[d.back()])
            d.pop_back();
        
        d.push_back(i);
        if (i >= k - 1)
            std::cout << arr[d.front()] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    printKMax(arr, n, k); 
    return 0; 
}