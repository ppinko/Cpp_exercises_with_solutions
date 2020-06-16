// https://edabit.com/challenge/v44GSB8CpBxnnQWNW

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


int rySeq(int n, std::string s);


int rySeq(int n, std::string s) {
    if (n == 0) return 0;
    int red = 2*(n-1) + 1;
    int all = 2*n*n - 2*n + 1;
    int yellow = all - red;
    if (s == "red")
        return red;
    else if (s == "all")
        return all;
    else if (s == "yellow")
        return yellow;
    else return -1;
}


int main(){
    std::cout << rySeq(28, "red") << " should equal to 55." << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}