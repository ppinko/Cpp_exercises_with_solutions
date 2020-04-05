// Fibonacci

#include <iostream>
#include <algorithm>
#include <unordered_map>

int fibo_rec(int n){
    std::cout << "x";
    if ((n == 1) || (n == 2))
        return 1;
    else
        return fibo_rec(n-1) + fibo_rec(n-2);
}

int fibo_rec2(int n){
    static std::unordered_map<int, int> dict {{1, 1}, {2, 1}};
    std::cout << "x";
    int temp {};
    if ((dict[n]) != 0)
        return dict[n];
    else{
        temp = fibo_rec2(n-1) + fibo_rec2(n-2);       
        dict[n] = temp;
        return temp;
    }
}

int fibo_rec3(int n){
    if ((n == 1) || (n == 2))
        return 1;
    int p1 {1};
    int p2 {1};
    int p3 {};
    int i = 3;
    while( i <= n){
        std::cout << "x";
        p3 = p1 + p2;
        p1 = p2;
        p2 = p3;
        i++;
    }
    return p3;
}

int main(){

    std::cout << fibo_rec(10) << std::endl;
    std::cout << fibo_rec2(10) << std::endl;
    std::cout << fibo_rec3(10) << std::endl;
    return 0;
}