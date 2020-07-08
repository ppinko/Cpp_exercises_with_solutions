// file:///tmp/mozilla_devpyth0/0521-c-practice-exercises-with-solutions.pdf

/* Write a function which will be given as input an array, its size and 
an integer p. The function will then cyclically shift the array p positions 
to the right: each element is moved p positions to the right, while the last 
p elements are moved to the beginning of the array. For example: if we have 
the array   [ 1 2 3 4 5 6], shifting 2 positions to the right should give the 
array [ 5 6 1 2 3 4 ]. Your function should work correctly for negative values 
of p. */

#include <iostream>

void rotate_array(int* arr, const size_t length, int shift){
    if (shift < 0)
        shift = (shift % 5) + 5;
    else shift %= 5;
    int *arr_cp = new int[length];
    for (size_t i = 0; i < length; ++i)
        arr_cp[i] = arr[i];
    
    for (size_t i = 0; i < length; ++i){
        if (i + shift < length) arr[i] = arr_cp[i+shift];
        else arr[i] = arr_cp[i+shift - length];
    }
    delete [] arr_cp;
}

int* arr_rotation(const int *const arr, const size_t length, int shift){
    if (shift < 0)
        shift = (shift % 5) + 5;
    else shift %= 5;
    int *arr_cp {nullptr};
    arr_cp = new int[length];
    for (size_t i = 0; i < length; ++i){
        if (i + shift < length) arr_cp[i] = arr[i+shift];
        else arr_cp[i] = arr[i+shift - length];
    }
    return arr_cp;
}

int main(){
    int arr []{1, 2, 3, 4, 5};

    int* res = arr_rotation(arr, sizeof(arr) / sizeof(arr[0]), 2);
    for (int i = 0; i < 5; ++i)
        std::cout << res[i] << " ";
        
    std::cout << "\nSeperation line\n";

    rotate_array(arr, sizeof(arr) / sizeof(arr[0]), 2);
    for (int i = 0; i < 5; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}