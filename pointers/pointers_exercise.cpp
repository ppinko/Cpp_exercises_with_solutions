/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes
  
  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.
  
  The function should return a pointer to the newly allocated array.
  
  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.
    
  For example,
  
  Below is the output from the following code which would be in main:
  
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,5);
    
    cout << "Array 2: " ;
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
   
   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/

#include <iostream>

int* apply_all(const int *const arr1, size_t s1, const int *const arr2, size_t s2){
    int* result = new int[s1 * s2];
    int k = 0;
    for (size_t i = 0; i < s1; ++i){
        for (size_t j = 0; j < s2; ++j){
            result[k] = arr1[i] * arr2[j];
            ++k;
        }
    }
    return result;
}

void print(const int *const arr, size_t s){
    std::cout << "[ ";
    for (size_t i {0}; i < s; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

#include <iostream>

int main(){
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    print(array1, sizeof(array1) / sizeof(array1[0]));
    print(array2, sizeof(array2) / sizeof(array1[0]));

    int* res = apply_all(array1, 5, array2, 3);
    print(res, 15);
    delete [] res;
    
    return 0;
}