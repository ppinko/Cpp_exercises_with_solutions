// file:///tmp/mozilla_devpyth0/0521-c-practice-exercises-with-solutions.pdf

/* Write a function that is given two positive integers r,c and allocates 
a 2-dimensional array with r rows and c columns. The function then returns 
a pointer to the allocated array. */

#include <iostream>

int **twoDarray(const int r, const int c){
    int** arr {nullptr};
    arr = new int* [r];
    for (int i = 0; i < r; ++i)
        arr[i] = new int[c];
    return arr;
}

int main(){

    return 0;
}